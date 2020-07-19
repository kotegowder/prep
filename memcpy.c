#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <time.h>

#define SIZE (1*1024*1024*1024)
//#define SIZE (19)

typedef unsigned long uint64_t;
typedef unsigned int  uint32_t;

char s_str[SIZE];
char d_str[SIZE];

void *slowMemCopy(void *d, const void *s, size_t n)
{
	char *wd = d;
	const char *ws = s;

	if ((uint64_t)wd < (uint64_t)ws) {
		while(n--)
			*wd++ = *ws++;
	} else {
		ws += n;
		wd += n;

		while(n--)
			*wd-- = *ws--;
	}

	return d;
}

void *fastMemCopy(void *d, const void *s, size_t n)
{
	uint64_t       *wd8 = d;
	const uint64_t *ws8 = s;
	size_t          wn8 = n / 8;

	uint32_t       *wd4;
	const uint32_t *ws4;
	size_t          wn4;

	char           *wd1;
	const char     *ws1;
	size_t          wn1 = n % 8;

	if ((((uint64_t)wd8 & 0x7) == 0) && (((uint64_t)ws8 & 0x7) == 0)) {
		if ((uint64_t)wd8 < (uint64_t)ws8) {
			while(wn8 != 0) {
				*wd8++ = *ws8++;
				wn8--;
			}
		} else {
			wd8 += wn8;
			ws8 += wn8;

			while(wn8 != 0) {
				*wd8-- = *ws8--;
				wn8--;
			}
		}
	}

	wd4 = (uint32_t *)wd8;
	ws4 = (uint32_t *)ws8;

	if (wn8 != 0)
		wn4 = n / 4;
	else
		wn4 = 0;

	if ((!((uint64_t)wd4 & 0x3)) && (!((uint64_t)ws4 & 0x3))) {
		if ((uint64_t)wd4 < (uint64_t)ws4) {
			while(wn4 != 0) {
				*wd4++ = *ws4++;
				wn4--;
			}
		} else {
			wd4 += wn4;
			ws4 += wn4;

			while(wn4 != 0) {
				*wd4-- = *ws4--;
				wn4--;
			}
		}
	}

	wd1 = (char *)wd4;
	ws1 = (char *)ws4;

	if (wn8 == 0)
		wn1 = n % 8;
	else if (wn4 == 0)
		wn1 = n % 4;
	else
		wn1 = n;

	if ((uint64_t)wd1 < (uint64_t)ws1) {
		while(wn1--)
			*wd1++ = *ws1++;
	} else {
		ws1 += wn1;
		wd1 += wn1;

		while(wn1--)
			*wd1-- = *ws1--;
	}

	return d;
}

		
int main(void)
{
	char ch;
	time_t t;
	double time_taken;

	printf("\nEnter a character to create source data : ");
	scanf("%c", &ch);

	/* Fill the source */
	memset(s_str, ch, SIZE);

	t = clock();
	memcpy(d_str, s_str, SIZE);
	t = clock() - t;
	time_taken = ((double)t)/CLOCKS_PER_SEC;
	printf("\nTime taken by library memcpy funtion : %f", time_taken);
	printf("\nFirst : %c Middle = %c Last : %c characters", d_str[0], d_str[SIZE/2], d_str[SIZE-1]);

	memset(d_str, 0, SIZE);
	t = clock();
	slowMemCopy(d_str, s_str, SIZE);
	t = clock() - t;
	time_taken = ((double)t)/CLOCKS_PER_SEC;
	printf("\n\nTime taken by slow memcpy funtion : %f", time_taken);
	printf("\nFirst : %c Middle = %c Last : %c characters", d_str[0], d_str[SIZE/2], d_str[SIZE-1]);

	memset(d_str, 0, SIZE);
	t = clock();
	fastMemCopy(d_str, s_str, SIZE);
	t = clock() - t;
	time_taken = ((double)t)/CLOCKS_PER_SEC;
	printf("\n\nTime taken by fast memcpy funtion : %f", time_taken);
	printf("\nFirst : %c Middle = %c Last : %c characters\n", d_str[0], d_str[SIZE/2], d_str[SIZE-1]);
	
	return 0;
}
