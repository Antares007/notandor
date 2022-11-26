#define Λ(array) ((long)((void **)(array))[-1]) // count elements of an array
void c(void **t, long i, void **n, long a, void **o) {
  if (a)
    if (t[a] == c) {
      long ii = t[a - 1];
      if (o[ii]) {
        c(o[ii], ii, n, Λ(o[ii]), o[Λ(o) - 1]);
        if (1 < a) c(t, i, n, a - 2, o);
      } else {
        c(t, i, n, a, o[Λ(o) - 1]);
      }
    } else {
      ((void (*)())t[a - 1])(t, i, n, a - 1, o);
    }
  else {
    if (o[i]) {
      c(o[i], i, n, Λ(o[i]), o[Λ(o) - 1]);
    } else {
      c(t, i, n, a, o[Λ(o) - 1]);
    }
  }
}
