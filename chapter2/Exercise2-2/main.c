/*
    for (i = 0; i < lim - 1 && (c = getchar()) != '\n' && c != EOF)

    Write a loop equivalent to the for loop
    shown above without using && or ||
*/

#include <stdio.h>

int main(void)
{
    int i, c, lim;

    lim = 100;
    i = 0;
    while(i < lim - 1)
    {
        if ((c = getchar()) == '\n')
            break;
        
        if (c == EOF)
            break;
        
        printf("%c", c);
        ++i;
    }
    printf("\n");

    return 0;
}