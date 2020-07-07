#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#define SIZE (1*1024*1024*1024)

char str[SIZE];

void *slowMemset(void *s, unsigned char c, size_t n)
{
	char *retAdr = s;

	while(n) {
		*(unsigned char *)s = c;
		n--;
		s = (void *)((uint32_t)s + 1);
	}

	return retAdr;
}

void *fastMemset(void *s, unsigned char c, size_t n)
{
	void *retAdr = s;
	size_t byte4Cnt = n / 4;
	size_t byte1Cnt = n % 4;
	uint32_t wordPattern = (c << 24) | (c  << 16) | (c << 8) | c;

	while(byte4Cnt || byte1Cnt) {
		
		if ((((uint32_t)s & 0x3) == 0) && byte4Cnt) {
			while(byte4Cnt) {
				*(uint32_t *)s = wordPattern;
				byte4Cnt--;
				s = (void *)((uint32_t)s + 4 );
			}
		} else {
			while(byte1Cnt) {
				*(unsigned char *)s = c;
				byte1Cnt--;
				s = (void *)((uint32_t)s + 1);
			}
		}
	}

	return retAdr;
}

int main(void)
{
	char c, temp;
	clock_t t;
	double time_taken;

	t = clock();
	memset(str, '?', SIZE);
	t = clock() - t;
	time_taken = ((double)t)/CLOCKS_PER_SEC;
	printf("Time taken by library memset : %f\n", time_taken);
	printf("First : %c, Middle = %c and Last : %c characters\n", str[0], str[SIZE/2], str[SIZE-1]);

	printf("Enter character for slow memset\n");
	scanf("%c", &c);
	scanf("%c", &temp);

	t = clock();
	slowMemset(str, c, SIZE);
	t = clock() - t;
	time_taken = ((double)t)/CLOCKS_PER_SEC;

	printf("Time taken using slow memset : %f\n", time_taken);
	printf("First : %c, Middle = %c and Last : %c characters\n", str[0], str[SIZE/2], str[SIZE-1]);

	printf("Enter character for fast memset\n");
	scanf("%c", &c);

	t = clock();
	fastMemset(str, c, SIZE);
	t = clock() - t;
	time_taken = ((double)t)/CLOCKS_PER_SEC;

	printf("Time taken using fast memset : %f\n", time_taken);
	printf("First : %c, Middle = %c and Last : %c characters\n", str[0], str[SIZE/2], str[SIZE-1]);

	return 0;
}
