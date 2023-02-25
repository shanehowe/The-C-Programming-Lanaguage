#include <stdio.h>

int main()
{
    int eof_expression = getchar() != EOF;

    printf("%d\n", eof_expression);
    return 0;
}