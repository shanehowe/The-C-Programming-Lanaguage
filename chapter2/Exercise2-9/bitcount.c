/*
    In a twos compliment system, x &= (x - 1)
    deletes the right most 1 bit in x. Explain why.
    Use this information to write a faster version of bit count

    Why? Say x = 0b101101.
    x - 1 = 0b101100

      0b101101
    & 0b101100
    ----------
      0b101100

    Next iteration:

      0b101100
    & 0b101000
    ----------
      0b101000

    We keep iterating until all 1 bits in x are deleted increment a variable and then return it.
    
    Bit manipulation is a total new way of thinking for me and I found it extremely hard to finish
    these topics and had to do a lot of research and have the answers explained to me but I do have 
    a much better grasp on it then I had before attempting these topics
*/

#include <stdio.h>

int bitcount(unsigned x);

int main(void)
{
    unsigned num = 3;

    printf("Number of 1 bits in %d: %d\n", num, bitcount(num));
    return 0;
}

int bitcount(unsigned x)
{
    int b;

    for (b = 0; x != 0; x &= (x - 1))
        b++;
    
    return b;
}