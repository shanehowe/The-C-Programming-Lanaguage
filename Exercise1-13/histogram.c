#include <stdio.h>

#define WORD_FOUND 0
#define NOT_WORD_FOUND 1

int main()
{
    int word_length[100]; // Assuming no word will be greater than 100 chars
    int c, state, i, len, max_index_used, j, max_word_length;

    // Initialize all values to 0
    for (i = 0; i < 100; i++)
        word_length[i] = 0;
    
    len = max_index_used = max_word_length = 0;
    state = NOT_WORD_FOUND; 
    while((c = getchar()) != EOF)
    {
        if (c == ' ' || c == '\n' || c == '\t')
        {
            ++word_length[len - 1];
            state = WORD_FOUND; // Change state so we do not increment len

            if (len > max_index_used)
                max_index_used = len;

            len = 0;
        }
        else
        {
            state = NOT_WORD_FOUND;
        }

        if (state == NOT_WORD_FOUND)
            ++len;  // So long as we havent encountered a white space increment len
    }
    int line_no;

    // Find max value in array
    for (i = 0; i < max_index_used; i++)
        if (word_length[i] > max_word_length)
            max_word_length = word_length[i];

    
    printf("---------------------------------------\n");
    printf("*       Word Length Histogram         *\n");
    printf("---------------------------------------\n");
    line_no = max_word_length;
    for (i = max_word_length - 1; i >= 0; i--)
    {
        printf("%3d |", (i+1));

        for (j = 0; j < max_index_used; j++)
        {
            if (word_length[j] >= line_no)
                printf("%3s", "#");
            else 
                printf("   ");     
        }
        --line_no;
        printf("\n");
    }

    printf("%2s", " ");
    for (i = 0; i <= max_index_used; i++)
        printf("---");
    
    printf("\n%2s", " ");
    for (i = 0; i <= max_index_used; i++)
        printf("%3d", i);


    printf("\n\nThe Y axis (vertical) represents the number of occurances of a word with that length \n");
    printf("The X axis (horizontal) represents the length of the word\n");

    return 0;
}