#define Λ(array) ((long)((void **)(array))[-1]) // count elements of an array
void c(void **o, void **t, long i, void **n, long a) {
  if (a)
    if (t[a] == c) {
      long ii = t[a - 1];
      if (o[ii]) {
        c(o[Λ(o) - 1], o[ii], ii, n, Λ(o[ii]));
        if (1 < a) c(o, t, i, n, a - 2);
      } else {
        c(o[Λ(o) - 1], t, i, n, a);
      }
    } else {
      ((void (*)())t[a - 1])(o, t, i, n, a - 1);
    }
  else {
    if (o[i]) {
      c(o[Λ(o) - 1], o[i], i, n, Λ(o[i]));
    } else {
      c(o[Λ(o) - 1], t, i, n, a);
    }
  }
}
