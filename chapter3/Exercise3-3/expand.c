#include <stdio.h>
#include <ctype.h>
#include <string.h>

void expand(char s1[], char s2[]);

int main(void)
{
    char s1[] = "a-f0-9b-fA-Z-";
    char s2[1000];

    expand(s1, s2);
    printf("%s\n", s2);
    return 0;
}

void expand(char s1[], char s2[])
{
    int j, c, k, start_point, end_point;
    size_t i;

    i = k = 0;
    while (s1[i] != '\0' && i < strlen(s1))
    {
        for (j = i; !isalnum(s1[j]) && s1[j] != '\0'; ++j)
        ;

        if (s1[j] == '\0')
            break;
        
        start_point = s1[j++];

        for (; !isalnum(s1[j]) && s1[j] != '\0'; ++j)
        ;

        if (s1[j] == '\0')
            break;

        end_point = s1[j];
        
        for ((c = start_point); c <= end_point; c++)
            s2[k++] = c;
        
        // move i and j passed previous end point
        i = ++j;
    }

    s2[k] = '\0';
}
