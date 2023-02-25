/*
    This program reads input and splits the line
    into multiple lines if line length > FOLD_POINT
    after the last non-blank character
    if line > FOLD_POINT and no non-blanks
    the line is split in 2
*/

#include <stdio.h>

#define MAX_LINE_LEN 1000
#define FOLD_POINT 50

int isblankspace(char c);
int mygetline(char line[], int maxlen);
int fold(char oldline[], char foldline[]);

int main(void)
{
    int len;
    char line[MAX_LINE_LEN];
    char foldline[MAX_LINE_LEN];

    while((len = mygetline(line, MAX_LINE_LEN)) > 0)
    {
        if (len > FOLD_POINT)
        {
            while (len > FOLD_POINT)
            {
                len = fold(line, foldline);
                printf("%s\n", foldline);
            }
            printf("%s", line);
        }
        else
        {
            printf("%s", line);
        }
    }

    return 0;
}

int mygetline(char line[], int maxlen)
{
    int i, c;
    for (i = 0; i < maxlen - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    {
        line[i] = c;
    }

    if (c == '\n')
    {
        line[i] = c;
        ++i;
    }

    line[i] = '\0';
    return i;
}

/* 
    Folds input lines greater than 30 into 2 lines
    Assumes only lines > 30 will be passed
 */
int fold(char oldline[], char foldline[])
{
    int i, j, closest_foldpoint;

    closest_foldpoint = -1;
    for (i = 0; oldline[i] != '\0' && i <= FOLD_POINT; ++i)
    {
        // find nearest white space to fold point
        if (isblankspace(oldline[i]) == 1 && isblankspace(oldline[i-1]) == 0)
        {
            closest_foldpoint = i;
        }
    }

    // Handle input lines > fold point and have no spaces or tabs
    if (closest_foldpoint == -1)
    {
        closest_foldpoint = (FOLD_POINT / 2);
    }

    j = 0;
    // Copy chars until closest fold point into fold line
    for (i = 0; i < closest_foldpoint; ++i)
    {
        foldline[j++] = oldline[i];
    }

    foldline[j++] = '\0';

    // Strip white space from left of line
    while(oldline[closest_foldpoint] == ' ')
        closest_foldpoint++;

    // Go from closest fold point till the end of the string
    // copy chars into oldline and terminate the string
    j = 0;
    for (i = closest_foldpoint; oldline[i] != '\0'; ++i)
        oldline[j++] = oldline[i];
    
    oldline[j] = '\0';

    return j;
}

int isblankspace(char c)
{
    if (c == ' ')
        return 1;
    else if (c == '\t')
        return 1;

    return 0;
}