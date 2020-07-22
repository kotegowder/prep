#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[])
{
	if (argc != 2) {
		printf("Error: Number argument is missing!\n");
		return -1;
	}

	int num = atoi(argv[1]);
	int sum;

	for(sum=0; num; sum += num%10, num /= 10);

	printf("\nSum of digits = %d", sum);

	return 0;
}
