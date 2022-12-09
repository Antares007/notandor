#include <errno.h>
#include <fcntl.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/epoll.h>
#include <sys/socket.h>
#include <unistd.h>

#define MAX_EVENTS 10
int setnonblocking(long fd) {
  // F_GETFL  Value of file status flags and access modes.
  //          The return value is not negative.
  int flags = fcntl(fd, F_GETFL, 0);
  if (flags < 0)
    return flags;
  flags |= O_NONBLOCK;
  // F_SETFL  Value other than -1.
  return fcntl(fd, F_SETFL, flags);
}

int main() {
  int epollfd;
  if ((epollfd = epoll_create1(0)) == -1)
    perror("epoll_create1"), exit(EXIT_FAILURE);

  struct epoll_event ev = {.events = EPOLLIN, .data.fd = STDIN_FILENO};
  if (setnonblocking(ev.data.fd) == -1)
    perror("cant set O_NONBLOCK"), exit(EXIT_FAILURE);

  if (epoll_ctl(epollfd, EPOLL_CTL_ADD, ev.data.fd, &ev) == -1)
    perror("epoll_ctl: listen_sock"), exit(EXIT_FAILURE);

  unsigned char buffer[65536];
  struct epoll_event events[MAX_EVENTS];
  for (int nfds;;)
    if ((nfds = epoll_wait(epollfd, events, MAX_EVENTS, 0)) == -1)
      perror("epoll_wait"), exit(EXIT_FAILURE);
    else
      for (long n = 0; n < nfds; ++n)
        for (long buflen;;)
          if ((buflen = read(events[n].data.fd, buffer, sizeof(buffer))) < 0)
            if (errno == EAGAIN || errno == EWOULDBLOCK)
              break;
            else
              perror("read"), exit(EXIT_FAILURE);
          else
            printf("%ld\n", buflen);
}
/*
 Where we will put epoll_wait call?
 How we read data in loop until EAGAIN or in
 pull call from consumer steam?


 epoll_wait will check if there is data to read
 and will return answer. if we dont read all data
 until EAGIN epoll wait will never tell us that
 there is still data to read.
 we can think about epoll_wait call like so.
 imagine we have some device like keyboard,
 and for that device we have intterupt handler.
 so in intterupt handler we need to read all data
 from device and store some other place for consumer.
 and if data flows much fuster then we can consume it, then we need to
 somehow backpressure device so it may slow down sending data.
 if not than we can store data in memory or throw it away when 
 there is no more free space to store data.
 for keyboard we can signall user with sound as backpressure.
 saying "hey bro stop typing so fast."

 but wait, lets analize out thinking. wtf is backpressure?

 in normal adamkind to adamkind communication we can identify moment
 when person who listening may say in return to stop takling too fast.
 or in some intervals he may aknowleging with some reaction
 to request more data.

 Today we need to do something some thing that we can meassure and
 be proud as obrant so we did some mesurable thing.
 we need to have plan. we need to have todos.
 please take yout time and write down some todos and arrange them
 and do first one but do it today plz. we love you.
 * Write program to calculate mathematical expressions.
    programm must consume stdin, parse expressions and calculate
    them incrementally.
 * Write program which can listen to stdin and parse text.
   and do things acordingly.
   in other words execute incomming text.
   we need to do it as efficient as it can be done.
   example:    
    1+2*3<CR>
    7
    *7<CR>
    49
    -1<CR>
    48
   example:
    open window by 800x600. draw line from 0, 0 to 100, 100.
 */ 
