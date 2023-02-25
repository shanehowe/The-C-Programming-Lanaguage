/*
* This program prints the frequency of
* the letters of the alphabet and number digits from an input file
* -- Case Insensitive --
*/

#include <stdio.h>
#include <ctype.h>

#define ALPHA_RANGE 26
#define NUM_RANGE 10
#define VALID_CHAR 1
#define NOT_VALID_CHAR 0

int main()
{
    int char_freq[ALPHA_RANGE];
    int num_freq[NUM_RANGE];
    int c, i, j, state, max_freq;

    for (i = 0; i < ALPHA_RANGE; i++)
        char_freq[i] = 0;
    
    for (i = 0; i < NUM_RANGE; i++)
        num_freq[i] = 0;

    state = VALID_CHAR;
    while((c = getchar()) != EOF)
    {
        if (c == ' ' || c == '\t' | c == '\n')
        {
            state = NOT_VALID_CHAR;
        }
        else
        {
            state = VALID_CHAR;
        }

        if (state == VALID_CHAR)
        {
            if (c >= 'A' && c <= 'z')
            {
                c = tolower(c);
                ++char_freq[c-'a'];
            }
            else if (c >= '0' && c <= '9')
            {
                ++num_freq[c-'0'];
            } 
        }
    }

    max_freq = 0;
    for (i = 0; i < ALPHA_RANGE; i++)
    {
        if (char_freq[i] > max_freq)
            max_freq = char_freq[i];
        
        if (i < NUM_RANGE && num_freq[i] > max_freq)
            max_freq = num_freq[i];
    }

    printf("Character Frequency Histogram\n\n");
    for (i = NUM_RANGE - 1; i >= 0; i--)
    {
        printf("%2d| ", i);
        for (j = 0; j < num_freq[i]; j++)
            printf("* ");
        
        printf("\n");
    }

    for (i = ALPHA_RANGE - 1; i >= 0; i--)
    {
        printf("%2c| ", (i + 'a'));
        for (j = 0; j < char_freq[i]; j++)
            printf("%3s ", "*");
        
        printf("\n");
    }

    for (i = 0; i < max_freq+2; i++)
        printf("--");
    
    printf("\n");
    printf("    ");
    for (i = 0; i < max_freq; i++)
        printf("%3d ", i+1);
    
    printf("\n");
    return 0;
}
