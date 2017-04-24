/* double-error.c */
int main () {
  double x; float y, z, r;
  /* x = ldexp(1.,50)+ldexp(1.,26); */
  x = 1125899973951488.0;
  y = x + 1;
  z = x - 1;
  r = y - z;
  printf("%f\n", r);
}
/*
% gcc double-error.c
% ./a.out
134217728.000000
*/
// https://www.absint.com/astree/examples.htm
