#include <stdio.h>

unsigned invert(int x, int p, int n);

int main(void)
{
    printf("%d\n", invert(5000, 3, 3));
    return 0;
}

unsigned invert(int x, int p, int n)
{
    int mask = (~(~0) << (1 << n) - 1) << (p - n + 1);

    // exclusive or x with the mask
    return x ^ mask;
}