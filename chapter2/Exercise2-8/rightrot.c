#include <stdio.h>

unsigned rightrot(unsigned x, int n);

int main(void)
{
    printf("%d\n", rightrot(8, 2));
}

unsigned rightrot(unsigned x, int n)
{
    // get the n bits to rotate
    unsigned rotated_bits = x & (1 << n) - 1 << (sizeof(unsigned) * 8 - n);

    // shift x to right to acomadate bits
    x >>= n;

    // or x with the rotated bits
    x |= rotated_bits;

    return x;
}