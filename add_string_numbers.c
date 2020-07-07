#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define LIMIT 1024

char result[LIMIT];

char *add_strings(char *num1, char *num2)
{
	size_t num1Len = strlen(num1);
	size_t num2Len = strlen(num2);
	size_t carry = 0;
	size_t sum;
	char *retPtr = result + LIMIT - 1;

	num1 = num1 + num1Len - 1;
	num2 = num2 + num2Len - 1;
	*retPtr = '\0';

	while(num1Len || num2Len) {
		sum =  (num1Len? *num1 - '0': 0) +
		       (num2Len? *num2 - '0': 0) +
			carry;
		*--retPtr = (sum % 10) + '0';
		carry     = sum / 10;

		if (num1Len > 0) {
			num1Len--;
			num1--;
		}
		if (num2Len > 0) {
			num2Len--;
			num2--;
		}
	}

	if (carry)
		*retPtr = carry + '0';

	return (retPtr);
}

int main()
{
	char num1[LIMIT/2];
	char num2[LIMIT/2];

	printf("Enter numner 1 : ");
	scanf("%s", num1);

	printf("Enter numner 2 : ");
	scanf("%s", num2);

	printf("Sum of num1 and num2 : %s\n", add_strings(num1, num2));

	return 0;
}
