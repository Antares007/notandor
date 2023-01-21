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

int main(int argc, char *argv[]) {
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
