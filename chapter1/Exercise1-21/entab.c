/*
    This program reads in lines of input
    and replaces white spaces by the optimal
    number of tabs and white space to achieve 
    the same spacing.
    

    Example: 
        . = white space
        _ = tab
        input : 'Hello.....World!'
        output: 'Hello_World!'
*/

#include <stdio.h>

#define TAB_WITDH 5
#define BUFFER_SIZE 1000

int mygetline(char buffer[], int buffersize);
int countwhitespace(char line[], int idx);
void entab(char newbuffer[], char oldbuffer[]);

int main(void)
{
    char line[BUFFER_SIZE];
    char entab_line[BUFFER_SIZE];

    while (mygetline(line, BUFFER_SIZE) > 0)
    {
        entab(entab_line, line);
        printf("%s", entab_line);
    }   

    return 0;
}

/* Reads line into buffer and returns the length */
int mygetline(char buffer[], int buffersize)
{
    int i, c;

    for (i = 0; i < buffersize - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    {
        buffer[i] = c;
    }

    if (c == '\n')
    {
        buffer[i] = '\n';
        ++i;
    }

    buffer[i] = '\0';
    
    return i;
}

/* Replaces white space with minimum amount of tabs to achieve same spacing */
void entab(char newbuffer[], char oldbuffer[])
{
    int i, j, nwhite_space, ntabs, spaces_to_fill;

    for (i = j = 0; oldbuffer[i] != '\0'; i++)
    {
        if (oldbuffer[i] == ' ')
        {
            nwhite_space = countwhitespace(oldbuffer, i);
        
            if (nwhite_space >= TAB_WITDH)
            {
                ntabs = nwhite_space / TAB_WITDH;
                spaces_to_fill = nwhite_space % TAB_WITDH;

                while(ntabs-- > 0)
                    newbuffer[j++] = '_';
                
                while(spaces_to_fill-- > 0)
                    newbuffer[j++] = '.';
                
                i += nwhite_space - 1;
            } 
            else
                newbuffer[j++] = oldbuffer[i];

        }
        else 
        {
            newbuffer[j++] = oldbuffer[i];
        }
    }

    newbuffer[j] = '\0';
}

int countwhitespace(char line[], int idx)
{
    int count, i;
    count = 0;
    for (i = idx; line[i] == ' ' && line[i] != '\0'; i++)
        count++;
    
    return count;
}