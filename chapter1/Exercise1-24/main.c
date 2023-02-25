#include <stdio.h>

#define MAXLINE 1000
#define TRUE 1
#define FALSE 0
#define COMMENT_START '/'
#define BLOCK_COMMENT 'b'
#define INLINE_COMMENT 'i'
#define SINGLE_STR 's'
#define DOUBLE_STR 'd'

int mygetline(char line[], int maxline);
void print_results(int parencount, int curlycount, int singleqcount, int doubleqcount);

int main(void)
{
    int in_comment, in_str, len, i, c, comment_type, str_type,
        paren_count, curly_count, singleq_count, doubleq_count;
    char line[MAXLINE];

    paren_count = curly_count = singleq_count = doubleq_count = 0;
    in_comment = in_str = FALSE;
    while ((len = mygetline(line, MAXLINE)) > 0)
    {
        for (i = 0; line[i] != '\0'; ++i)
        {
            // logic for changing state of program to in comment
            if (in_comment == FALSE && in_str == FALSE && line[i] == '/')
            {
                if (line[i + 1] == '*')
                {
                    in_comment = TRUE;
                    comment_type = BLOCK_COMMENT;
                    
                }
                else if (line[i + 1] == '/')
                {
                    in_comment = TRUE;
                    comment_type = INLINE_COMMENT;
                
                }
            }
            // changing state to out of comment
            if (in_comment == TRUE && in_str == FALSE && (line[i] == '\n' || line[i] == '*'))
            {
                if (comment_type == INLINE_COMMENT && line[i] == '\n')
                {
                    in_comment = FALSE;
                    comment_type = -1;
                }
                else if (comment_type == BLOCK_COMMENT && line[i + 1] == '/')
                {
                    in_comment = FALSE;
                    comment_type = -1;
                }
            }

            // changing state to in string
            if (in_comment == FALSE && in_str == FALSE && (line[i] == '\'' || line[i] == '"'))
            {
                if (line[i] == '"')
                {
                    in_str = TRUE;
                    str_type = DOUBLE_STR;
                    ++i;
                }
                else if (line[i] == '\'')
                {
                    in_str = TRUE;
                    str_type = SINGLE_STR;
                    ++i;
                }
            }
            // changing state to out of string
            if (line[i] != '\\' && line[i + 1] != '\'') // Handles when encountering -> '\''
            {
                if (in_comment == FALSE && in_str == TRUE && (line[i] == '\'' || line[i] == '"'))
                {
                    if (line[i] == '"' && str_type == DOUBLE_STR)
                    {
                        in_str = FALSE;
                        str_type = -1;
                        ++i;
                    }
                    if (line[i] == '\'' && str_type == SINGLE_STR)
                    {
                        in_str = FALSE;
                        str_type = -1;
                        ++i;
                    }
                }
            }

            // Only if we arent in comment and arent in a string
            if (in_comment == FALSE && in_str == FALSE)
            {
                if (line[i] == '(' || line[i] == ')')
                {
                    paren_count++;
                }
                if (line[i] == '{' || line[i] == '}')
                {
                    curly_count++;
                }
                if (line[i] == '\'')
                {
                    singleq_count++;
                }
                if (line[i] == '"')
                {
                    doubleq_count++;
                }
            }
        }
    }

    /* 
        if state is still in string at the end of the program
        that means a string wasnt finished.
    */
    if (in_str == TRUE && str_type == SINGLE_STR)
    {
        printf("Found unbalanced single quotes\n");
    }
    else if (in_str == TRUE && str_type == DOUBLE_STR)
    {
        printf("Found unbalanced double quotes\n");
    }

    print_results(paren_count, curly_count, singleq_count, doubleq_count);

    return 0;
}

int mygetline(char line[], int maxline)
{
    int i, c;

    for (i = 0; i < maxline - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        line[i] = c;
    
    if (c == '\n')
    {
        line[i] = c;
        ++i;
    }

    line[i] = '\0';
    return i;
}

void print_results(int parencount, int curlycount, int singleqcount, int doubleqcount)
{
    int mistakes;

    mistakes = 0;
    if (parencount % 2 != 0)
    {
        printf("Found unbalanced parenthesis\n");
        mistakes++;
    }

    if (curlycount % 2 != 0)
    {
        printf("Found unbalanced curly braces\n");
        mistakes++;
    }

    if (singleqcount % 2 != 0)
    {
        printf("Found unbalanced single quotes\n");
        mistakes++;
    }

    if (doubleqcount % 2 != 0)
    {
        printf("Found unbalanced double quotes\n");
        mistakes++;
    }

    if (mistakes == 0)
    {
        printf("Program found no mismatches!\n");
    }
}