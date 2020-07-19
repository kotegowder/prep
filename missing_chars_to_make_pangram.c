#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/* Problem statement:
 * Find all missing characters in a given setence to make it panagram.
 *
 * Note: Panagram : a setence containing every letter of the alphabet.
 */

void missingChars(char *s)
{
	char *wp;
	char alphabets[26] = "abcdefghijklmnopqrstuvwxyz";
	int idx;

	wp = s;
	while(*wp != '\0') {
		idx = *wp++ % 97;
		if (alphabets[idx] != '-')
			alphabets[idx] = '-';
	}

	idx = 0;
	while(idx < 26) {
		if (alphabets[idx] != '-')
			printf("%c", alphabets[idx]);
		idx++;
	}

	printf("\n");
}

int main()
{
	char str[256];

	printf("Enter input string\n");
	scanf("%[^\n]", str);

	missingChars(str);

	return 0;
}
