#include <stdio.h>

unsigned setbits(int x, int p, int n, int y);

int main(void)
{
    printf(%un, setbits(67, 8, 3, 35));
}

unsigned setbits(int x, int p, int n, int y) 
{
    return (x & ~(~(~0 << n) << p+1-n)) | ((y & ~(~0 << n)) << p+1-n);
}
