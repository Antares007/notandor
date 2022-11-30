#include "obrt.h"
#include <stdio.h>
#include <assert.h>
#include <unistd.h>

void logger_ray(obrt, rest) {
  long d = 0;
  void **p = (void **)o;
  while (p)
    d++, p = p[8];
  printf("%ld %ld %s\n", r, d, (char *)*--t);
  usleep(100000);
  C(o, b, r, frwd);
}
void logger(obrt, rest) {
  void *Tlogger_ray = T(*--t, logger_ray);
  D(O(Tlogger_ray, Tlogger_ray, Tlogger_ray, Tlogger_ray, Tlogger_ray,
      Tlogger_ray, Tlogger_ray, Tlogger_ray, o), t, frwd);
}
void continues(obrt, rest) {
  t = (void *)*t[-1];
  D(o, t, frwd);
}
void wrap_logger(obrt, rest) {
  char *str = (void *)*--t;
  void *word_to_wrap = (void *)*--t;
  t = T(t, continues, str, logger, word_to_wrap, str, logger);
  D(o, t, frwd);
}

