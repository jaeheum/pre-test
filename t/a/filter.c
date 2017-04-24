/* filter.c */
typedef enum {FALSE = 0, TRUE = 1} BOOLEAN;
BOOLEAN INIT;
float P, X;

void filter () {
  static float E[2], S[2];
  if (INIT) {
    S[0] = X;
    P = X;
    E[0] = X;
  } else {
    P = (((((0.5*X)-(E[0]*0.7))+(E[1]*0.4))+(S[0]*1.5))-(S[1]*0.7));
  }
  E[1] = E[0];
  E[0] = X;
  S[1] = S[0];
  S[0] = P;
}

void main () {
  X = 0.2 * X + 5;
  INIT = TRUE;
  while (1) {
    X = 0.9 * X + 35;
    filter ();
    INIT = FALSE;
  }
}
/*
The absence of overflow (and more precisely that P is in [-1327.05,
1327.05] as found by Astrée) is not obvious, in particular because
of 32-bit floating-point computations. The situa­tion becomes even
more inextricable in the presence of boolean control or cascades of
filters. Astrée knows enough about control theory to analyze filters
precisely.
*/
// https://www.absint.com/astree/examples.htm

