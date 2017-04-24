/* boolean.c */
typedef enum {FALSE = 0, TRUE = 1} BOOLEAN;
BOOLEAN B;
void main () {
  unsigned int X, Y;
  while (1) {
    /* ... */
    B = (X == 0);
    /* ... */
    if (!B) {
      Y = 1 / X;
    };
    /* ... */
  };
}
/*
The analysis of the above code by Astrée yields no warnings, thanks
to the automatically de­termined relationship between B and X. Integer
divide-by-zero can never happen when executing this program.
*/
// https://www.absint.com/astree/examples.htm

