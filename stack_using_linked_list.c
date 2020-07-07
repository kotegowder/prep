#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct lifo
{
	int value;
	struct lifo *next;
}stack_t;

void stack_init(stack_t **pTop)
{
	/* Initialize top to NULL, indicating empty stack */
	*pTop = NULL;
}

void push (stack_t **pTop, int value)
{
	stack_t *new = (stack_t *)malloc(sizeof(stack_t));
	if (new == NULL) {
		printf("Error: Stack is full\n");
		return;
	}

	new->value = value;
	new->next  = *pTop;

	*pTop = new;

	return;
}

int pop (stack_t **pTop)
{
	int     value;
	stack_t *temp;

	if (pTop == NULL) {
		printf("Error: Empty stack\n");
		return -1;
	}


	value = (*pTop)->value;
	temp  = *pTop;
	*pTop = (*pTop)->next;

	free(temp);

	return value;
}

int isStackEmpty (stack_t *pTop)
{
	return (pTop == NULL);
}

int main(void)
{
	stack_t *A, *B;

	printf("Create Stack A and B\n");
	stack_init(&A);
	stack_init(&B);

	printf("Check if A and B are empty in the begining\n");
	if (isStackEmpty(A) && isStackEmpty(B))
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
	
	if (isStackEmpty(B))
		printf("Stack B is empty as expected\n");

	return 0;
}
