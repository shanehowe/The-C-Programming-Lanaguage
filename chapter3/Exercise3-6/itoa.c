/*
    Write a version of itoa that accepts three
    arguments instead of two. The third argument
    is a minimum field width; the converted
    number must be padded with blanks on the left
    if necessary to make it wide enough
*/

#include <stdio.h>
#include <string.h>

void modified_itoa(int n, char s[], int field_width);
void reverse(char s[]);

int main(void)
{
    int n, field_width;
    char s[1000];

    n = 10;
    field_width = 5;

    modified_itoa(n, s, field_width);
    printf("%s\n", s);

    return 0;
}

void modified_itoa(int n, char s[], int field_width)
{
    int i, sign;

    if ((sign = n) < 0)
        n = -n;
    
    i = 0;
    do {
        s[i++] = n % 10 + '0';
    } while ((n /= 10) > 0);

    if (sign < 0)
        s[i++] = '-';
    
    s[i] = '\0';
    if (i < field_width)
    {
        while (i < field_width)
        {
            s[i++] = ' ';
        }
        s[i] = '\0';
    }

    reverse(s);
}

void reverse(char s[])
{
    int i, j, tmp;
    for (i = 0, j = strlen(s) - 1; i < j; ++i, --j)
    {
        tmp = s[i];
        s[i] = s[j];
        s[j] = tmp;
    }
}