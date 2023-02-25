#include <stdio.h>

#define BUFF_SIZE 1000

void reverse(char s[]);
int get_line(char line[], int buffsize);

int main(void)
{
    char line[BUFF_SIZE];

    while (get_line(line, BUFF_SIZE) > 0)
    {
        reverse(line);
        printf("%s", line);
    }

    return 0;
}

void reverse(char s[])
{
    int len, i, j;
    char tmp;

    for (len = 0; s[len] != '\0'; len++)
        ;

    i = 0;
    j = len - 1;
    while(i < j)
    {
        if (s[j] == '\n')
        {
            --j;
            continue;   
        }
        
        tmp = s[i];
        s[i] = s[j];
        s[j] = tmp;

        --j;
        ++i;
    }
}

int get_line(char line[], int buffsize)
{
    int c, i;

    for (i = 0; i < buffsize - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        line[i] = c;

    if (c == '\n')
    {
        line[i] = '\n';
        ++i;
    }

    line[i] = '\0';
    return i;
}