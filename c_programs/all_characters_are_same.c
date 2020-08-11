#include<stdio.h>
#include<stdlib.h>
#include <string.h>

/* Problem statement:
 * 
 * Check if all the characters in a given input string are same
 */

int allCharsSame(char *s)
{
	for(int idx=1; s[idx] != '\0'; idx++) {
		if (s[0] ^ s[idx])
			return 0;
	}

	return 1;
}

int main()
{
	char str[250];

	printf("Enter string: ");
	scanf("%[^\n]", str);


	if (allCharsSame(str))
		printf("Same\n");
	else
		printf("Different\n");

	return 0;
}
