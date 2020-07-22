#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void)
{
	char *day0 = "Sunday";
	char *day1 = "Monday";
	char *day2 = "Tuesday";
	char *day3 = "Wednesday";
	char *day4 = "Thursday";
	char *day5 = "Friday";
	char *day6 = "Saturday";
	char **week;
	int x, y;
	char *temp;

	week = (char **)malloc(sizeof(char *) * 7);
	if( week == NULL) {
		printf("\nError: Not enough memory");
		exit(1);
	}

	*(week + 0) = day0;
	*(week + 1) = day1;
	*(week + 2) = day2;
	*(week + 3) = day3;
	*(week + 4) = day4;
	*(week + 5) = day5;
	*(week + 6) = day6;

	for(x=0; x<7; x++)
		printf("\n%s", *(week + x));
	
	printf("\n\nSorted week days:");

	for(x = 0; x < 6; x++) {
		for(y = x + 1; y < 7; y++) {
			if (strcmp(week[x], week[y]) > 0) {
				temp = week[x];
				week[x] = week[y];
				week[y] = temp;
			}
		}
	}

	for(x=0; x<7; x++)
		printf("\n%s", *(week + x));
	printf("\n");

	return 0;
}
