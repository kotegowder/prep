#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAXSIZE 100

typedef struct lifo
{
	int value[MAXSIZE];
	int top;
}stack_t;

void stack_init (stack_t *pS)
{
	/* pS->top points to the last element pushed in.
	 * Initially -1 */
	pS->top = -1;
}

void push (stack_t *pS, int value)
{
	/* Check if stack is full */
	if (pS->top == (MAXSIZE - 1)) {
		printf("Error: Stack overflow\n");
		return;
	}

	pS->value[++(pS->top)] = value;

	return;
}

int pop (stack_t *pS)
{
	if (pS->top == -1) {
		printf("Error: Empty stack\n");
		return -1;
	}

	return pS->value[pS->top--];
}

int isStackEmpty (stack_t *pS)
{
	return (pS->top == -1);
}

int main(void)
{
	stack_t A, B;

	printf("Create Stack A and B\n");
	stack_init(&A);
	stack_init(&B);

	printf("Check if A and B are empty in the begining\n");
	if (isStackEmpty(&A) && isStackEmpty(&B))
		printf("Both are empty\n");
	else {
		printf("Not empty\n");
		return -1;
	}

	push(&A, 10);
	push(&A, 20);
	push(&A, 30);
	push(&B, 100);
	push(&B, 200);

	printf("Pop from A : %d\n", pop(&A));
	printf("Pop from B : %d\n", pop(&B));

	push(&A, pop(&B));
	
	if (isStackEmpty(&B))
		printf("Stack B is empty as expected\n");

	return 0;
}
