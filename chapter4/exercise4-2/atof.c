/*
    Extend atof to handle scientific
    notationnof the form
        123.45e-6
    where a floating point number may be followed by
    e or E and an optionally signed exponent
*/
#include <stdio.h>
#include <ctype.h>
#include <math.h>


double extended_atof(char s[]);

int main(void)
{
    char num[] = "12.45e-6";

    printf("Result: %.8f\n", extended_atof(num));

    return 0;
}

double extended_atof(char s[])
{
    double val, power;
    int i, sign, expo_sign, exponent;

    for (i = 0; isspace(s[i]); i++)
        ;

    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;
    
    for (val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] - '0');
    
    if (s[i] == '.')
        i++;
    
    for (power = 1.0; isdigit(s[i]); i++)
    {
        val = 10.0 * val + (s[i] - '0');
        power *= 10.0;
    }

    if (tolower(s[i]) == 'e') 
        i++;

    expo_sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;
 
    exponent = 0;
    while (isdigit(s[i]))
    {
        exponent = 10 * exponent + (s[i] - '0');
        ++i;
    }

    return (sign * val / power) * pow(10.00, (expo_sign * exponent));
}