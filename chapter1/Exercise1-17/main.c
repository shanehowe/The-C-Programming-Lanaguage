/*
    This program reads input 
    from a file by redirecting 
    the file into the executable
    and prints lines > 80 chars

    usage: ./a.out < filename
                  OR
           echo "string" | ./a.out
      
*/

#include <stdio.h>

#define BUFF_SIZE 1000

int getline(char line[], int buffsize);

int main(void)
{
    int len, above80;
    char line[BUFF_SIZE];

    above80 = 0;
    while((len = getline(line, BUFF_SIZE)) > 0)
    {
        if (len > 80)
        {
            ++above80;
            printf("%s\n", line);
        }
    }

    printf("--------------------------------------\n");
    printf("*              SUMMARY               *\n");
    printf("--------------------------------------\n");
    printf("*         Found %2d lines > 80        *\n", above80);
    printf("--------------------------------------\n");

    return 0;   
}

/* reads line into char line[] and returns the length */
int getline(char line[], int buffsize)
{
    int i, c;

    for (i = 0; i < buffsize -1 && (c = getchar()) != EOF && c != '\n'; ++i)
        line[i] = c;
    
    if (c == '\n')
    {
        line[i] = '\0';
        ++i;
    }
    return i;
}