#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/* Problem statement:
 * Check if the input string is pangram or not.
 *
 * Note: Panagram : a setence containing every letter of the alphabet.
 */

int isPangram(char *s)
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
	while(idx <= 12) {
		if (alphabets[idx] ^ alphabets[26-idx-1])
			return -1;
		idx++;
	}

	return 0;
}

int main()
{
	char str[256];

	printf("Enter input string\n");
	scanf("%[^\n]", str);

	if (isPangram(str) == 0)
		printf("Is pangram\n");
	else
		printf("Is not a pangram\n");

	return 0;
}
