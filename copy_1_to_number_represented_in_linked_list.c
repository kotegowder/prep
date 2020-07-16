#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef enum
{
	LL_SUCCESS               = 0,
	LL_ERROR_NO_MEMORY       = 128,
	LL_ERROR_NOT_FOUND       = 129,
	LL_ERROR_EMPTY           = 130,
	LL_ERROR_NO_LOOP         = 131,
}ll_status_t;

struct node
{
	int value;
	struct node *next;
};

typedef struct node Node;

ll_status_t pushAtTail(Node **hRef, int num)
{
	Node *newNode = (Node *)malloc(sizeof(Node));

	if (newNode == NULL) {
		printf("\nError: Not enough memory for new node");
		return LL_ERROR_NO_MEMORY;
	}

	newNode->value = num;
	newNode->next  = NULL;

	if (*hRef == NULL) {
		*hRef = newNode;
		return LL_SUCCESS;
	}

	Node *curNode = *hRef;

	while(curNode->next != NULL) {
		curNode = curNode->next;
	}

	curNode->next = newNode;

	return LL_SUCCESS;  
}

ll_status_t reverseList(Node **hRef) {
	Node *prevNode = NULL;
	Node *currNode = *hRef;
	Node *nextNode;

	while(currNode != NULL) {
		nextNode       = currNode->next;
		currNode->next = prevNode;
		prevNode       = currNode;
		currNode       = nextNode;
	}

	*hRef = prevNode;

	return LL_SUCCESS;
}

void displayList(Node *currNode) {
	while(currNode != NULL) {
		printf("%d", currNode->value);
		currNode = currNode->next;
	}
	printf("\n");
}

int main(void)
{
	Node *headNode = NULL, *currNode;	
	int idx, sum, carry = 1;
	char num[100];

	printf("\nEnter the number: ");
	scanf("%s", num);

	for(idx=0; num[idx] != '\0'; idx++) {
		pushAtTail(&headNode, (num[idx] - '0'));
	}

	/* Let's reverse the list */
	reverseList(&headNode);

	currNode = headNode;

	while(currNode != NULL) {
		sum             = (currNode->value + carry);
		currNode->value = sum % 10;
		carry           = sum / 10;
		currNode        = currNode->next;
	}

	if (carry) {
		pushAtTail(&headNode, carry);
	}

	/* Finally reverse the list to get answer */
	reverseList(&headNode);

	displayList(headNode);

	free(headNode);

	return 0;
}
