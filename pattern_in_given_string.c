#include<stdio.h>
#include<string.h>

/* Problem statement:
 * Search for given pattern in input string.
 * Return the location where pattern starts if found otherwise -1.
 */

int searchPattern(char *pSrcStr, char *pPatStr)
{
	int lenSrcStr = strlen(pSrcStr);
	int lenPatStr = strlen(pPatStr);

	int srcIdx;
	int patIdx;

	for(srcIdx=0; srcIdx <= (lenSrcStr - lenPatStr); srcIdx++)
	{
		for(patIdx=0; patIdx<lenPatStr; patIdx++)
		{
			if (pSrcStr[srcIdx+patIdx] != pPatStr[patIdx])
			{
				break;
			}
		}
		if (patIdx == lenPatStr) {
			return srcIdx;
		}
	}

	return -1;
}

void main(void)
{
	char string[1000];
	char pattern[1000];
	int  patternLoc;
	char temp;

	printf("Enter a string\n");
	scanf("%[^\n]", string);

	printf("Enter a pattern\n");
	scanf("%c", &temp);
	scanf("%[^\n]", pattern);

	patternLoc = searchPattern(string, pattern);
	if (patternLoc >= 0) {
		printf("Pattern found at index %d\n", patternLoc);
	} else {
		printf("Pattern not found\n");
	}
}
