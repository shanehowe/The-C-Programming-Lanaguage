/*
    Write the function any(s1, s2), which returns
    the first location in the string s1 where any char
    from s2 occurs, or -1 if s1 contains no chars from s2
*/
#include <stdio.h>

#define MAX_LINE 50

void get_string(char line[], int max_line);
int any(char s1[], char s2[]);

int main(void)
{
    char string_one[MAX_LINE];
    char string_two[MAX_LINE];

    printf("Enter string one: ");
    get_string(string_one, MAX_LINE);

    printf("Enter string two: ");
    get_string(string_two, MAX_LINE);

    printf("%d\n", any(string_one, string_two));

    return 0;
}

int any(char s1[], char s2[])
{
    int i, j;

    for (i = 0; s1[i] != '\0'; ++i)
    {
        for (j = 0; s2[j] != '\0'; ++j)
            if (s1[i] == s2[j])
                return i;
    }

    return -1;
}

void get_string(char line[], int max_line)
{
    int i, c;

    for (i = 0; i < max_line - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    {
        line[i] = c;
    }

    line[i] = '\0';
}