#include <stdio.h>

#define TAB_WIDTH 5
#define BUFFER_SIZE 1000

int mygetline(char line[], int buffer_size);
void detab(char original_line[], char detabed_line[]);

int main(void)
{
	char line[BUFFER_SIZE];
	char newline[BUFFER_SIZE];
	
	while (mygetline(line, BUFFER_SIZE) > 0)
	{
		detab(line, newline);
		printf("%s", newline);
	}
	
	
	
	return 0;
}

/* Reads a string into line and returns the length */
int mygetline(char line[], int buffer_size)
{
	int i, c;
	
	for (i = 0; i < buffer_size - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
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


void detab(char original_line[], char detabed_line[])
{
	int i, j, c, nwhites;

	for (i = j = 0; (c = original_line[i]) != '\0'; ++i)
	{
		if (c == '\t')
		{
			nwhites = TAB_WIDTH - j % TAB_WIDTH;
			while(nwhites-- > 0)
				detabed_line[j++] = ' ';
		}
		else 
		{
			detabed_line[j++] = c;
		}
	}
	detabed_line[j++] = '\0';
}
