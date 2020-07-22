#include<stdio.h>
#include<stdlib.h>

#define MY_SIZEOF(type) (int)((char *)(&type+ 1) - (char *)(&type))

int main(int argc, char *argv[])
{
	char ch;
	int i;
	double d;
	struct
	{
		char ch;
		int iv;
		double dd;
	}my_s;

	printf("\nSizeof ch   = %d", MY_SIZEOF(ch));
	printf("\nSizeof i    = %d", MY_SIZEOF(i));
	printf("\nSizeof d    = %d", MY_SIZEOF(d));
	printf("\nSizeof my_s = %d", MY_SIZEOF(my_s));

	return 0;
}
