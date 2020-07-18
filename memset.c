#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#define BYTE8
#define SIZE (1*1024*1024*1024)

typedef unsigned int uint32_t;
typedef unsigned long uint64_t;

char str[SIZE];

void *slowMemset(void *s, unsigned char c, size_t n)
{
	char *retAdr = s;

	while(n) {
		*(unsigned char *)s = c;
		n--;
		s++;
	}

	return retAdr;
}

void *fastMemset(void *s, unsigned char c, size_t n)
{
	void *retAdr = s;
#ifdef BYTE8
	size_t byte8Cnt = n / 8;
	size_t byte1Cnt = n % 8;
#else
	size_t byte4Cnt = n / 4;
	size_t byte1Cnt = n % 4;
#endif
	uint32_t wordPattern = (c << 24) | (c  << 16) | (c << 8) | c;
#ifdef BYTE8
	uint64_t longPattern = (((uint64_t)wordPattern << 32) | wordPattern);
#endif

#ifdef BYTE8
	while(byte8Cnt || byte1Cnt) {
		if ((((unsigned long)s & 0x7) == 0) && byte8Cnt) {
			while(byte8Cnt) {
				*(uint64_t *)s = longPattern;
				byte8Cnt--;
				s = s + 8;
			}
		}
#else
	while(byte4Cnt || byte1Cnt) {
                if ((((unsigned long)s & 0x3) == 0) && byte4Cnt) {
			while(byte4Cnt) {
				*(uint32_t *)s = wordPattern;
				byte4Cnt--;
				s = s + 4 ;
			}
		}
#endif
		else {
			while(byte1Cnt) {
				*(unsigned char *)s = c;
				byte1Cnt--;
				s++;
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
	printf("First : %c Middle = %c Last : %c characters\n", str[0], str[SIZE/2], str[SIZE-1]);

	printf("\nEnter character for slow memset\n");
	scanf("%c", &c);
	scanf("%c", &temp);

	t = clock();
	slowMemset(str, c, SIZE);
	t = clock() - t;
	time_taken = ((double)t)/CLOCKS_PER_SEC;

	printf("Time taken using slow memset : %f\n", time_taken);
	printf("First : %c Middle = %c Last : %c characters\n", str[0], str[SIZE/2], str[SIZE-1]);

	printf("\nEnter character for fast memset\n");
	scanf("%c", &c);

	t = clock();
	fastMemset(str, c, SIZE);
	t = clock() - t;
	time_taken = ((double)t)/CLOCKS_PER_SEC;

	printf("Time taken using fast memset : %f\n", time_taken);
	printf("First : %c Middle = %c Last : %c characters\n", str[0], str[SIZE/2], str[SIZE-1]);

	return 0;
}
