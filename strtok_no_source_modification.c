#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char delim_hash[256] = {0};
const char *srcPtr;
char retStr[1024];

char *_strtok(const char *str, const char *delim)
{
	static int idx = 0;
	static int end;
	int curIdx = 0;
	char *retPtr = retStr;

	if (str != NULL) {
		srcPtr = str;

		while(*delim != '\0') {
			delim_hash[*delim] = 1;
			delim++;
		}
	}

	while (srcPtr[idx] != '\0') {
		if (delim_hash[srcPtr[idx]] == 1) {
			while (delim_hash[srcPtr[idx]] == 1) {
				retPtr[curIdx] = '\0';
				idx++;
				curIdx++;
			}
			break;
		}
		retPtr[curIdx++] = srcPtr[idx++];
	}

	if (end == idx)
		return NULL;
	retPtr[curIdx] = '\0';
	end = idx;
	return retPtr;
}

int main()
{
	const char str[1024];
	const char delim[256];
	char *token, temp;

	printf("Enter string : ");
	scanf("%[^\n]", str);

	printf("Enter delimiter string : ");
	scanf("%c", &temp);
	scanf("%[^\n]", delim);

	token = _strtok(str, delim);

	while(token != NULL) {
		printf("Token : %s\n", token);
		token = _strtok(NULL, delim);
	}

	return 0;
}
