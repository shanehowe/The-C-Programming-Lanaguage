/*
    Write a function htoi(s) which converts
    a string of decimal digits (including and optional 0x or 0X)
    into its equivelant integer values
*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

#define MAX_LINE 50

int htoi(char s[]);
void mygetline(char line[], int max_line);

int main(void)
{
    char hex_value[MAX_LINE];
    int decimal_value;

    printf("Enter the value in hex (can be prefixed with 0x or 0X): ");
    mygetline(hex_value, MAX_LINE);
    decimal_value = htoi(hex_value);

    if (decimal_value == -1)
        printf("Invalid input. Chars must be between 0-9 or A-F\n");
    else
        printf("Decimal: %d\n", decimal_value);

    return 0;
}

/* Read input into line */
void mygetline(char line[], int max_line)
{
    int i, c;

    for (i = 0; i < max_line - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        line[i] = c;

   line[i] = '\0';
}

int htoi(char s[])
{
    int string_length, has_prefix, i, exponent, current_char;
    long long decimal_value;

    has_prefix = 0;
    string_length = strlen(s);

    // Check if the string contains a prefix
    if (string_length >= 2)
    {
        char first_char, second_char;
        first_char = s[0];
        second_char = tolower(s[1]);

        if (first_char == '0' && second_char == 'x')
            has_prefix = 1;
    }

    // Move i passed prefix if it does
    if (has_prefix)
    {
        i = 2;
        exponent = string_length - 3;
    }
    else
    {
        i = 0;
        exponent = string_length - 1;
    }
    
    // The conversion
    decimal_value = 0;
    for (; i < string_length; ++i)
    {
        current_char = toupper(s[i]);

        if (isalpha(current_char))
        {
            // If the current value is an invalid letter
            if (current_char < 'A' || current_char > 'F')
                return -1;

            decimal_value += (int)(current_char - 'A' + 10) * pow(16, exponent); 
        }
        else
            decimal_value += (current_char - '0') * pow(16, exponent);
        
        exponent--;
    }

    return decimal_value;
}
