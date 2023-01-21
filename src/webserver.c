/*
This code is a basic implementation of an HTTP server. It uses the C standard

library for socket programming to create and bind a socket, listen for incoming
connections, and accept connections.

The first group of includes are the headers that the program needs to use socket
programming, in addition to the standard input/output library and the string
library.

The error() function is a simple function that prints an error message to the
console and exits the program.

The send_response() function takes in a socket descriptor, a status code, and a
body, and sends an HTTP response with that status code and body over the socket.

The handle_get_request() function takes in a socket descriptor and a resource
(the requested file path), opens the file at that path, reads it into a buffer,
and sends the contents of the file as the body of an HTTP response with a status
code of 200 OK. If the file is not found, it sends a response with a status code
of 404 Not Found.

The handle_post_request() function takes in a socket descriptor and a resource
(which is not used in this example), reads incoming data from the socket, and
sends an HTTP response with a status code of 200 OK and the message "Data
received" as the body.

The main() function sets up the socket, binds it to a port, and enters a loop
that waits for incoming connections. When a connection is accepted, it reads the
incoming HTTP request, parses the method and resource from it, and calls the
appropriate handling function (handle_get_request() or handle_post_request())
based on the method.

Overall, the code is a basic implementation of an HTTP server which can handle
GET and POST request. It's missing some important feature like request
validation, thread handling, and security, but it demonstrates the core
functionality of an HTTP server.
*/
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

void error(const char *msg) {
  perror(msg);
  exit(1);
}

void send_response(int sock, char *status, char *body) {
  char response[0x10000];
  sprintf(response,
          "HTTP/1.1 %s\nContent-Type: text/html\nContent-Length: %lu\n\n%s",
          status, strlen(body), body);
  write(sock, response, strlen(response));
}

void handle_get_request(int sock, char *resource) {
  char path[255];
  sprintf(path, "public%s", resource);
  printf("%s\n", path);
  FILE *fp = fopen(path, "r");
  if (fp == NULL) {
    send_response(sock, "404 Not Found", "File not found");
    return;
  }

  // Read the file into a buffer
  fseek(fp, 0, SEEK_END);
  int size = ftell(fp);
  rewind(fp);
  char *buffer = (char *)malloc(size + 1);
  fread(buffer, 1, size, fp);
  buffer[size] = '\0';
  fclose(fp);

  // Send the response
  send_response(sock, "200 OK", buffer);
  free(buffer);
}

void handle_post_request(int sock, char *resource) {
  char buffer[256];
  bzero(buffer, 256);
  int n = read(sock, buffer, 255);
  if (n < 0) {
    error("ERROR reading from socket");
  }

  // Handle the posted data
  // ...

  send_response(sock, "200 OK", "Data received");
}

int main_without_threading(int argc, char *argv[]) {
  int sockfd, newsockfd, portno;
  socklen_t clilen;
  char buffer[256];
  struct sockaddr_in serv_addr, cli_addr;
  int n;
  if (argc < 2) {
    fprintf(stderr, "ERROR, no port provided\n");
    exit(1);
  }
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0)
    error("ERROR opening socket");
  bzero((char *)&serv_addr, sizeof(serv_addr));
  portno = atoi(argv[1]);
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_addr.s_addr = INADDR_ANY;
  serv_addr.sin_port = htons(portno);
  if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    error("ERROR on binding");
  listen(sockfd, 5);
  clilen = sizeof(cli_addr);
  while (1) {
    newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &clilen);
    if (newsockfd < 0) {
      error("ERROR on accept");
    }

    bzero(buffer, 256);
    n = read(newsockfd, buffer, 255);
    if (n < 0) {
      error("ERROR reading from socket");
    }

    // Parse the incoming HTTP request
    char method[8], resource[255];
    sscanf(buffer, "%s %s", method, resource);

    // Handle the request based on the HTTP method
    if (strcmp(method, "GET") == 0) {
      handle_get_request(newsockfd, resource);
    } else if (strcmp(method, "POST") == 0) {
      handle_post_request(newsockfd, resource);
    } else {
      // Invalid method, return an error
      send_response(newsockfd, "405 Method Not Allowed", "Invalid method");
    }

    close(newsockfd);
  }
  close(sockfd);
  return 0;
}

// Here's an example of how you could modify the code to handle multiple
// connections using threads:
#include <pthread.h>
void *connection_handler(void *socket_desc) {
  // Get the socket descriptor
  int sock = *(int *)socket_desc;

  // Read the incoming HTTP request
  char buffer[256];
  bzero(buffer, 256);
  int n = read(sock, buffer, 255);
  if (n < 0) {
    error("ERROR reading from socket");
  }

  // Parse the incoming HTTP request
  char method[8], resource[255];
  sscanf(buffer, "%s %s", method, resource);

  // Handle the request based on the HTTP method
  if (strcmp(method, "GET") == 0) {
    handle_get_request(sock, resource);
  } else if (strcmp(method, "POST") == 0) {
    handle_post_request(sock, resource);
  } else {
    // Invalid method, return an error
    send_response(sock, "405 Method Not Allowed", "Invalid method");
  }

  // Close the socket and exit the thread
  close(sock);
  pthread_exit(NULL);
}
int main_with_threading(int argc, char *argv[]) {
  int sockfd, newsockfd, portno;
  socklen_t clilen;
  struct sockaddr_in serv_addr, cli_addr;

  if (argc < 2) {
    fprintf(stderr, "ERROR, no port provided\n");
    exit(1);
  }
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0)
    error("ERROR opening socket");
  bzero((char *)&serv_addr, sizeof(serv_addr));
  portno = atoi(argv[1]);
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_addr.s_addr = INADDR_ANY;
  serv_addr.sin_port = htons(portno);
  if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    error("ERROR on binding");
  listen(sockfd, 5);
  clilen = sizeof(cli_addr);
  while (1) {
    newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &clilen);
    if (newsockfd < 0) {
      error("ERROR on accept");
    }
    // Create a new thread to handle the connection
    pthread_t thread_id;
    int *new_sock = malloc(1);
    *new_sock = newsockfd;
    if (pthread_create(&thread_id, NULL, connection_handler, (void *)new_sock) <
        0) {
      error("could not create thread");
    }
  }
}

int main(int argc, char *argv[]) { main_with_threading(argc, argv); }
