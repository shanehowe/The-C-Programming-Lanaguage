/*
* This program prints its input one word per line
* Example:
* Input > hello world 
* Out   > hello
*       > world
* Handles trailing white space at the end of input too
*/


#include <stdio.h>

#define WORD_FOUND 1
#define NOT_WORD_FOUND 0

int main()
{
    int c, state, prev_c;

    prev_c = '\0';
    state = NOT_WORD_FOUND;
    while((c = getchar()) != EOF)
    {
        if (c == ' ' || c == '\t' || c == '\n')
        {
            state = WORD_FOUND;

            if (prev_c != ' ' && prev_c != '\t')
                putchar('\n');
        }

        if (state == NOT_WORD_FOUND)
            putchar(c);
        else if (state = WORD_FOUND)
            state = NOT_WORD_FOUND;
    
        prev_c = c;
    }
}

