#include<stdio.h>
#include<stdlib.h>

#define IS_ALPHABET(c) (((c >= 97) && (c <= 122)) || ((c >= 65) && (c <= 90)))

int main()
{
	char str[250];
	char *fastPtr, *slowPtr;

	printf("Enter a string: ");
	scanf("%[^\n]", str);

	fastPtr = str;
	slowPtr = str;

	while(*fastPtr != '\0') {
		/* Check for either capital or small alphabet */ 
		if (IS_ALPHABET(*fastPtr)) {
			*slowPtr = *fastPtr;
		         slowPtr++;
		}
		fastPtr++;
	}

	/* Ensure the string is terminated with NULL character */
	*slowPtr = '\0';

	printf("%s\n", str);

	return 0;
}
