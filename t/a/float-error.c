/* float-error.c */
int main () {
    float x, y, z, r;

    x = 1.000000019e+38;
    y = x + 1.0e21;
    z = x - 1.0e21;
    r = y - z;
    printf("%f\n", r);
}
/*
% gcc float-error.c
% ./a.out
0.000000
*/
// https://www.absint.com/astree/examples.htm

