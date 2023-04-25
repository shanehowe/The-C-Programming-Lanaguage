/*
    Write the function strindex(s, t), which returns the position
    of the right most occurence of t in s, or -1 if there is none
*/

#include <stdio.h>
#include <string.h>

int strindex(char s[], char t[]);

int main(void)
{
    char s[] = "The quick brown fox jumped over the lazy dog. Yes he jumped over him.";
    char t[] = "jumped";

    int index = strindex(s, t);

    if (index == -1)
        printf("Found no occurences of %s in %s\n", t, s);
    else
        printf("The right most occurence of '%s' in %s is at index %d\n", t, s, index);

    return 0;
}

int strindex(char s[], char t[])
{
    int i, j, k, t_length;

    t_length = strlen(t);
    k = t_length - 1;

    for (i = strlen(s) - 1; i >= 0; --i)
    {
        for (j = i, k = t_length - 1; j > 0 && k > 0 && s[j] == t[k]; --k, --j)
            ;
        
        if (k == 0)
            return j;
    }

    return -1;
}