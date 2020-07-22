#include<stdio.h>
#include<string.h>

/* Probelm statement:
 * Remove duplicate characters from a given string.
 */

#define TABLE_SIZE  256
#define NOT_CHECKED 0x0
#define CHECKED     0x1

char *removeDupChar(char *s)
{
	unsigned char table[TABLE_SIZE] = {0};
	char         *fws               = s;
	char         *sws               = s;
	unsigned char idx;

	if(s == NULL)
		return NULL;

	while((idx = *fws) != '\0')
	{
		if(table[idx] == NOT_CHECKED) {
			table[idx] = CHECKED;
			*sws++     = idx;
		}
		fws++;
	}

	*sws = '\0';
	
	return s;
}

void main(void)
{
	char string[256];

	printf("Enter input string(limit to 256 characters)\n");
	scanf("%[^\n]", string);

	printf("Output string is = %s\n", removeDupChar(string));
}
