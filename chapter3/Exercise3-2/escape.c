/*
    Write a function escape(t, s) that converts 
    characters like newline and tab into visible escape sequences
    like \n \t as it copies the string t to s.

    Write the function for the other direction as well, 
    converting escape sequences into real characters.
*/

#include <stdio.h>

void escape(char t[], char s[]);
void unescape(char t[], char s[]);

int main(void)
{
    char t[] = "The quick brown fox\n\tjumped over the cat\n";
    char s[90];

    escape(t, s);

    printf("Original string: %s\n\n", t);
    printf("Escaped string: %s\n", s);

    return 0;
}

void escape(char t[], char s[])
{
    int i, c, j;

    j = 0;
    for (i = 0; (c = t[i]) != '\0'; ++i)
    {
        switch (c)
        {
            case '\n':
                s[j++] = '\\';
                s[j++] = 'n';
                break;
            case '\t':
                s[j++] = '\\';
                s[j++] = 't';
                break;
            default:
                s[j++] = t[i];
                break;
        }
    }

    s[j] = '\0';
}

void unescape(char t[], char s[])
{
    int i, c, j;

    for (i = 0; (c = t[i]) != '\0'; ++i)
    {

    }
}