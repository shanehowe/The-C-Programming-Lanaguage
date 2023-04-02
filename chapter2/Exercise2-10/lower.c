/*
    Rewrite the function lower, which converts
    upper case letters to lower with a conditional
    expression instead of if-else
*/

#include <stdio.h>

int conditional_lower(int c);

int main(void)
{
    char name[4] = "CaT";
    int i;

    for (i = 0; name[i] != '\0'; ++i)
        printf("%c", conditional_lower(name[i]));
    
    printf("\n");
    return 0;
}

int conditional_lower(int c)
{
    return (c >= 'A' && c <= 'Z') ? c + 'a' - 'A' : c;
}