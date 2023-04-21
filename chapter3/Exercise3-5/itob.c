/*
    Write the function itob(n, s, b) that
    converts the integer n into a base b character 
    representation in the string s.

    In particular itob(n, s, 16) formats n as a hexadecimal
    integer in s
*/

#include <stdio.h>
#include <string.h>

void itob(int n, char s[], int base);
void reverse(char s[]);

int main(void)
{
    char str[100];
    int n = 987;

    itob(n, str, 16);
    printf("%s\n", str);

    return 0;
}

void itob(int n, char s[], int base)
{
    int i, j, c, tmp, sign;
    
    if ((sign = n) < 0)
        n = -n;

    i = 0;
    do {
        c = n % base;
        if (c >= 10)
            s[i++] = c + '0' + 7;
        else
            s[i++] = c + '0';
    } while ((n /= base) > 0);
    
    if (sign < 0)
        s[i++] = '-';
    
    s[i] = '\0';

    reverse(s);
}

void reverse(char s[])
{
    int i, j, tmp;
    i = 0;
    j = strlen(s) - 1;

    while (i < j)
    {
        tmp = s[i];
        s[i] = s[j];
        s[j] = tmp;

        ++i;
        --j;
    }
}