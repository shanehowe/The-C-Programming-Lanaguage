/*
    This program reads in lines from its input
    and prints the longest line + the length of the line

    if len of line > buffer to hold text
        string[i] for 0.. buffer_size is printed.
    
    example:
        string_buffer[3]
        line entered = hel\n
        printed = he (only 2 chars printed because of \0) 
                  longested_len = 3

    This program does not count \n as a char.
*/
#include <stdio.h>

#define MAXLINE 100

int getline(char line[], int maxline);
void copy(char to[], char from[]);

int main(void)
{
    int len;
    int max;
    char line[MAXLINE];
    char longest[MAXLINE];

    max = 0;
    while((len = getline(line, MAXLINE)) > 0)
        if (len > max)
        {
            max = len;
            copy(longest, line);
        }
    
    if (max > 0)
        printf("Longest line: %s\nLength: %d\n", longest, max);
    
    return 0;
}


/* Read a line into char line[] and return the length */
int getline(char line[], int maxline)
{
    int c, i;

    for (i = 0; (c = getchar()) != EOF && c != '\n'; ++i)
    {
        if (i == maxline - 1)
            line[i] = '\0';
        else if (i > maxline - 1)
            continue;
        else
            line[i] = c;
    }
        
    if (c == '\n')
    {
        line[i] = c;
        ++i;
        line[i] = '\0';
    }

    return i - 1;
}

void copy(char to[], char from[])
{
    int i;

    i = 0;
    while((to[i] = from[i]) != '\0')
        ++i;
}