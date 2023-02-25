/*
    Write a program to remove all comments from a C program
    Dont forget to handle quoted strings and character constants properly
*/

#include <stdio.h>

#define MAX_LINE 1000
#define TRUE 1
#define FALSE 0
#define NONE -1
/* 
    BLOCK_COMMENT & INLINE_COMMENT can be defined as anything
    they just provide a way of telling the program what kind of
    comment we are in.
 */
#define BLOCK_COMMENT 'b'
#define INLINE_COMMENT 'i'

int mygetline(char line[], int maxline);
void remove_comments(char oldline[], char newline[]);

int in_comment;
int in_str;
int comment_type;

int main(void)
{
    char line[MAX_LINE];
    char newline[MAX_LINE];
    extern int in_comment;
    extern int in_str;
    extern int comment_type;
    
    comment_type = NONE;
    in_comment = in_str = FALSE;

    while (mygetline(line, MAX_LINE) > 0)
    {
        remove_comments(line, newline);
        printf("%s", newline);
    }
    printf("\n");

    return 0;
}

int mygetline(char line[], int maxline)
{
    int i, c;

    for (i = 0; i < maxline - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
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

void remove_comments(char oldline[], char newline[])
{
    int i, j;

    extern int in_comment;
    extern int in_str;
    extern int comment_type;

    for (i = j = 0; oldline[i] != '\0'; ++i)
    {
        // Change state for when in a string
        if (oldline[i] == '"' && in_str == FALSE)
        {
            in_str = TRUE;
        }
        else if (oldline[i] == '"' && in_str == TRUE)
        {
            in_str = FALSE;
        }

        // Change state for when we are in a block comment
        if (in_str == FALSE && oldline[i] == '/' && oldline[i+1] == '*')
        {
            in_comment = TRUE;
            comment_type = BLOCK_COMMENT;
        }
        // Change state for when we are in an inline comment
        else if (in_str == FALSE && oldline[i] == '/' && oldline[i+1] == '/')
        {
            in_comment = TRUE;
            comment_type = INLINE_COMMENT; 
        }

        // Change state for reaching the end of a BLOCK_COMMENT
        if (in_comment == TRUE && comment_type == BLOCK_COMMENT && oldline[i] == '*' && oldline[i+1] == '/')
        {
            in_comment = FALSE;
            comment_type = NONE;
            // Increment i because next char will be part of the comment
            i += 2;
        }
        // Change state for reaching the end of an INLINE_COMMENT
        else if (in_comment == TRUE && comment_type == INLINE_COMMENT && oldline[i] == '\n')
        {
            in_comment = FALSE;
            comment_type = NONE;
        }

        if (in_comment == FALSE)
            newline[j++] = oldline[i];
        else
            newline[j++] = ' ';
        
        newline[j] = '\0';
    }
}