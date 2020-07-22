#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char delim_hash[256] = {0};
char *prevPtr;
int limitIdx;

char *_strtok(char *str, const char *delim)
{
	static int idx = 0;
	char *retPtr;
	char *mPtr;

	if (str != NULL) {
		limitIdx = strlen(str);
		prevPtr = str;

		while(*delim != '\0') {
			delim_hash[*delim] = 1;
			delim++;
		}
	}

	retPtr = prevPtr;
	mPtr   = prevPtr;
	while (idx < limitIdx) {
		if (delim_hash[*mPtr] == 1) {
			while (delim_hash[*mPtr] == 1) {
				*mPtr = '\0';
				mPtr++;
				idx++;
			}
			prevPtr = mPtr;
			mPtr = NULL;
			break;
		}
		mPtr++;
		idx++;
	}

	if (mPtr == prevPtr)
		return NULL;

	return retPtr;
}

int main()
{
	char str[1024];
	const char delim[256];
	char *token;

	printf("Enter string : ");
	scanf("%s", str);

	printf("Enter delimiter string : ");
	scanf("%s", delim);

	token = _strtok(str, delim);

	while(token != NULL) {
		printf("Token : %s\n", token);
		token = _strtok(NULL, delim);
	}

	return 0;
}
