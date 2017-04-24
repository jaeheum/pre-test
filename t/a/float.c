/* float.c */
void main () {
    float x,y,z;
    /* ... code to initialize x,y,z ... */
    if ( (((*((unsigned*)&x) & 0x7f800000) >> 23) != 255 ) /* not NaN */
       && (x >= -1.0e38) && (x <= 1.0e38) ) {
        while (1) {
            y = x+1.0e21;
            z = x-1.0e21;
            x = y-z;
        }}
    else
        return;
}
/*
Astrée proves that the above program is free of runtime errors when
running on a machine with floats on 32 bits.

Likewise, Astrée handles possible positive and negative infinity as well
NaN values for variables, and can track their effects through arithmetic
calculations and comparisons. This is used to precisely analyze source
code with special handling of these values.
*/
// https://www.absint.com/astree/examples.htm
