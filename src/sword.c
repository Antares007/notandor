#define O(...) 0
#define T(...) 0
#define oars                                                                   \
  void (***o)(), void (***a)(), void (***r)(), void (***s)(), void (**t)()

void if_match_dot(oars) {
  char *m = (char*)*--t;
}
void aterm(oars) {
  o = O(T("a", if_match_dot), T(1),T(2),T(3), o, a, r, s); 
  a = O(T(aa),                T(1),T(2),T(3), o, a, r, s);
  t[-1](o, a, r, s, t - 1);
}
void sword(     oars) {}
void proppeller(oars) {
  for (long i = 0; i < 4; i++) {
    o[i][-1](o[4], o[5], o[6], o[7], o[i] - 1);
    a[i][-1](a[4], a[5], a[6], a[7], a[i] - 1);
    r[i][-1](r[4], r[5], r[6], r[7], r[i] - 1);
    s[i][-1](s[4], s[5], s[6], s[7], s[i] - 1);
  }
}
void ond(oars) {

}
int main() {
  void*o = O(T(ond), T(ond), T(ond), T(ond), 0, 0, 0, 0);
  void*a = O(T(and), T(and), T(and), T(and), 0, 0, 0, 0);
  void*r = O(T(rnd), T(rnd), T(rnd), T(rnd), 0, 0, 0, 0);
  void*s = O(T(snd), T(snd), T(snd), T(snd), 0, 0, 0, 0);

  proppeller(o, a, r, s, 0);
}

//    XXXXX
//     XXX
//      #
//     XXX
//    XXXXX
//
//      X
//     XXX
//    XXXXX
//     ###
//      #
