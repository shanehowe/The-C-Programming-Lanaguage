#include <stdio.h>

/*
*   This program counts, blanks, tabs and new lines
*   from input and displays the result
*/

int main()
{
    int n, c;

    n = 0;
    while((c = getchar()) != EOF)
        if (c == ' ' || c == '\n' || c == '\t')
            ++n;

    printf("%d\n", n);
    
    return 0;
}