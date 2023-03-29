/*
    Write an alternate version of squeeze(s1, s2)
    that deletes each character in s1 that matches any character in s2
*/

#include <stdio.h>

#define MAX_LINE 50

void squeeze(char s1[], char s2[]);
void get_string(char line[], int max_line);

int main(void)
{
    char string_one[MAX_LINE];
    char string_two[MAX_LINE];

    printf("Enter string one: ");
    get_string(string_one, MAX_LINE);

    printf("Enter string two: ");
    get_string(string_two, MAX_LINE);

    squeeze(string_one, string_two);

    printf("\nResult after squeezing all the characters from string two out of string one: %s\n", string_one);

    return 0;
}

void squeeze(char s1[], char s2[])
{
    int i, j, k, match_found;

    k = 0;
    for (i = 0; s1[i] != '\0'; ++i)
    {
        match_found = 0;
        for (j = 0; s2[j] != '\0'; ++j)
        {
            if (s1[i] == s2[j])
            {
                match_found = 1;
                break;
            }
        }

        if (!match_found)
            s1[k++] = s1[i];
    }

    s1[k] = '\0';
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
