#include<stdio.h>
#include<string.h>

/* Problem statement:
 * Reverse words in a given string
 */

void reverseString(char *s, char *e)
{
	char temp;

	while(s < e)
	{
		temp = *s;
		*s++ = *e;
		*e-- = temp;
	}
}

char *reverseWords(char *s)
{
	char *sws = s, *fws = s;

	if (s == NULL)
		return NULL;

	/* reverse the original string */
	reverseString(s, (s + strlen(s) - 1));

	while(*fws != '\0') {
		if (*fws == ' '){
			reverseString(sws, fws-1);
			sws = fws+1;
		}
		fws++;
	}

	if (*fws == '\0') {
		reverseString(sws, fws-1);
	}
	
	return s;
}

void main(void)
{
	char string[256];
	
	printf("Enter a string\n");
	scanf("%[^\n]", string);

	if (reverseWords(string) == NULL)
		printf("NULL\n");
	else
		printf("%s\n", string);	
}
