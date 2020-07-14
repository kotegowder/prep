#include<stdio.h>
#include<stdlib.h>

int countSetBits(int n)
{
	if (n == 0)
		return 0;

	int cnt = 0;

	while(n) {
		cnt++;
		n = n & (n-1);
	}

	return cnt;
}

int nextNumberWithSameSetBits(int num)
{
	int expectedBits = countSetBits(num);

	int setBits;

	if (expectedBits == 0)
		return expectedBits;

	do
	{
		setBits = countSetBits(++num);
	}while(setBits != expectedBits);

	return num;
}

int main()
{
	int num;

	printf("Enter number : ");
	scanf("%d", &num);

	printf("Next higher number with same number of set bits : %d\n", nextNumberWithSameSetBits(num));

	return 0;
}
