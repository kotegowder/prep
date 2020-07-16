#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <unistd.h>
#include <time.h>

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

ll_status_t pushAtHead(Node **hRef)
{
	int value;
	Node *newNode = (Node *)malloc(sizeof(Node));

	if (newNode == NULL) {
		printf("\nError: Not enough memory for new node");
		return LL_ERROR_NO_MEMORY;
	}

	printf("\nEnter the value for the node: ");
	scanf("%d", &value);

	newNode->value = value;

	if (*hRef == NULL) {
		newNode->next  = NULL;
		*hRef = newNode;
		return LL_SUCCESS;
	}

	newNode->next = *hRef;
	*hRef         = newNode;

	return LL_SUCCESS;
}

ll_status_t pushAtTail(Node **hRef)
{
	int value;
	Node *newNode = (Node *)malloc(sizeof(Node));

	if (newNode == NULL) {
		printf("\nError: Not enough memory for new node");
		return LL_ERROR_NO_MEMORY;
	}

	printf("\nEnter the value for the node: ");
	scanf("%d", &value);

	newNode->value = value;
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

ll_status_t insertAfter(Node **hRef)
{
	Node *curNode = *hRef;
	int  value;
	int  newValue;

	printf("\nEnter the node value after which the new node to be inserted: ");
	scanf("%d", &value);

	while ((curNode != NULL) && (curNode->value != value)) {
		curNode = curNode->next;
	}

	if (curNode == NULL) {
		printf("\nError: There is no node with the value : %d", value);
		return LL_ERROR_NOT_FOUND;
	}
	
	Node *newNode = (Node *)malloc(sizeof(Node));

	if (newNode == NULL) {
		printf("\nError: Not enough memory for new node");
		return LL_ERROR_NO_MEMORY;
	}

	printf("\nEnter the value for the new node: ");
	scanf("%d", &newValue);

	newNode->value = newValue;
	newNode->next  = curNode->next;

	curNode->next  = newNode;

	return LL_SUCCESS;
}

void display(Node *curNode)
{
#ifdef DEBUG
	int cnt = 0;
#endif
	printf("\n");
	while(curNode != NULL) {
		printf("%d->", curNode->value);
#ifdef DEBUG
		fflush(stdout);
		cnt++;
		if (cnt == 10)
			break;
		sleep(1);
#endif
		curNode = curNode->next;
	}

	printf("NULL\n");
}

ll_status_t countList(Node *curNode)
{
	int count = 0;

	while(curNode != NULL)
	{
		count++;
		curNode = curNode->next;
	}
	printf("\nNumber of items in Linked List : %d\n", count);

	return LL_SUCCESS;
}

ll_status_t printMiddle(Node *head)
{
	Node *fastNode = head;
	Node *slowNode = head;

	if (head == NULL) {
		printf("\nEmpty list");
		return LL_ERROR_EMPTY;
	}

	while ((fastNode != NULL) && (fastNode->next != NULL))
	{
		fastNode = fastNode->next->next;
		slowNode = slowNode->next;
	}

	printf("\nThe middle element : %d", slowNode->value);

	return LL_SUCCESS;	
}

ll_status_t deleteMiddle(Node **hRef)
{
	Node *fastNode = *hRef;
	Node *slowNode = *hRef;
	Node *prevNode = NULL;

	if (*hRef == NULL) {
		printf("\nEmpty list");
		return LL_ERROR_EMPTY;
	}

	if (fastNode->next == NULL) {
		/* there is only one ele in list */
		free(fastNode);
		*hRef = NULL;
		return LL_SUCCESS;
	}

	while ((fastNode != NULL) && (fastNode->next != NULL))
	{
		fastNode = fastNode->next->next;
		prevNode = slowNode;
		slowNode = slowNode->next;
	}

	prevNode->next = slowNode->next;
	free(slowNode);

	return LL_SUCCESS;
}

ll_status_t swapNodes(Node **hRef)
{
	int x, y;
	char c;

	printf("\nEnter first node value  : ");
	scanf("%d", &x);
	scanf("%c", &c);
	printf("\nEnter second node value : ");
	scanf("%d", &y);

	if (x == y)
		return LL_SUCCESS;

	Node *preX = NULL;
	Node *curX = *hRef;
	Node *preY = NULL;
	Node *curY = *hRef;
	Node *temp = NULL;

	while ((curX != NULL) && (curX->value != x)) {
		preX = curX;
		curX = curX->next;
	}
	
	while ((curY != NULL) && (curY->value != y)) {
		preY = curY;
		curY = curY->next;
	}

	/* If x or y not found, no swap required */
	if ((curX == NULL) || (curY == NULL)) {
		printf("\nError: value not found in list");
		return LL_ERROR_NOT_FOUND;
	}

	if (preX != NULL) {
		preX->next = curY;	
	} else {
		*hRef = curY;
	}

	if (preY != NULL) {
		preY->next = curX;
	} else {
		*hRef = curX;
	}

	temp       = curY->next;
	curY->next = curX->next;
	curX->next = temp;

	return LL_SUCCESS;
}	

static ll_status_t isValuePresent(Node *curNode, int value) {

	while (curNode && (curNode->value != value)) {
		curNode = curNode->next;
	}

	if (curNode == NULL)
		return LL_ERROR_NOT_FOUND;

	return LL_SUCCESS;
}

ll_status_t createLoop(Node **hRef) {
	int limit = 8;
	int cnt;
	int value;
	Node *curNode, *loopEnd;
	time_t t;

	srand ((unsigned) time(&t));

	for(cnt = 0; cnt < limit;) {
		value = rand() % 10;
		if (isValuePresent(*hRef, value)) {
			Node *newNode = (Node *)malloc(sizeof(Node));
			newNode->value = value;
			if (*hRef == NULL) {
				newNode->next = NULL;
				*hRef = newNode;
				cnt++;
				continue;
			}

			newNode->next = *hRef;
			*hRef         = newNode;
			cnt++;
		}
	}

	do {
		value = rand() % 10;
	}while (isValuePresent(*hRef, value));

	curNode = *hRef; 

	/* locate the Node with 'value' where the loop can be connected */
	while(curNode->value == value)
		curNode = curNode->next;

	loopEnd = curNode;

	/* locate the end of linked list */
	curNode = *hRef;
	while(curNode->next != NULL)
		curNode = curNode->next;

	/* Connect the end of single list to the value node */
	curNode->next = loopEnd;

	return LL_SUCCESS;
}

ll_status_t isLoopInList(Node *curNode) {
	Node *fastNode = curNode;
	Node *slowNode = curNode;

	while(fastNode && (fastNode->next != NULL)) {
		fastNode = fastNode->next->next;
		slowNode = slowNode->next;

		/* if they meet at same node, there is loop */
		if (slowNode == fastNode) {
			return LL_SUCCESS;
		}
	}

	return LL_ERROR_NO_LOOP;
}

ll_status_t removeLoop(Node **hRef) {
	Node *fastNode = *hRef;
	Node *slowNode = *hRef;
	Node *currNode;

	while(fastNode && (fastNode->next != NULL)) {
		slowNode = slowNode->next;
		fastNode = fastNode->next->next;

		if (slowNode == fastNode)
			break;
	}

	currNode = *hRef;
	while(1) {
		while ((currNode != slowNode->next) && (currNode != slowNode))
			currNode = currNode->next;

		/* we need to move the slowNode pointer to next */
		if (currNode == slowNode) {
			slowNode = slowNode->next;
			currNode = *hRef;
			continue;
		}

		/* make slowNode next to NULL */
		slowNode->next = NULL;
		break;
	}
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

ll_status_t deleteList(Node **hRef) {

	Node *currNode = *hRef;
	Node *nextNode;

	while(currNode != NULL) {
		nextNode = currNode->next;
		free(currNode);
		currNode = nextNode;
	}

	*hRef = NULL;

	return LL_SUCCESS;
}

ll_status_t removeElement(Node **hRef) {
	int value;
	Node *currNode = *hRef;
	Node *prevNode;

	printf("\nEnter the value which is to be removed : ");
	scanf("%d", &value);

	while (currNode && (currNode->value != value)) {
		prevNode = currNode;
		currNode = currNode->next;
	}

	if (currNode == NULL) {
		printf("\nError: %d is not present in list", value);
		return LL_SUCCESS;
	}

	if (currNode->next == NULL) {
		free(currNode);
		*hRef = NULL;
		return LL_SUCCESS;
	}

	prevNode->next = currNode->next;
	free(currNode);

	return LL_SUCCESS;
}
		
int main()
{
	Node *headNode = NULL;
	int option  = 0;

	printf("Singly Linked List Example - All Operations\n");

	do {

		printf("\nOptions\n");
		printf("\n 1: Add at head");
		printf("\n 2: Add at tail");
		printf("\n 3: Insert after");
		printf("\n 4: Display");
		printf("\n 5: Get list count");
		printf("\n 6: Print middle");
		printf("\n 7: Delete middle");
		printf("\n 8: Swap nodes");
		printf("\n 9: Create loop(start with empty list)");
		printf("\n10: Is loop present in list");
		printf("\n11: Remove loop");
		printf("\n12: Reverse list");
		printf("\n13: Remove element");
		printf("\n14: Delete list");
		printf("\nEnter your choice : ");
		scanf("%d", &option);
		switch (option) {
			case 1:
				assert(0 == pushAtHead(&headNode));
				break;
			case 2:
				assert(0 == pushAtTail(&headNode));
				break;
			case 3:
				assert(0 == insertAfter(&headNode));
				break;
			case 4:
				display(headNode);
				break;
			case 5:
				assert(0 == countList(headNode));
				break;
			case 6:
				assert(0 == printMiddle(headNode));
				break;
			case 7:
				assert(0 == deleteMiddle(&headNode));
				break;
			case 8:
				assert(0 == swapNodes(&headNode));
				break;
			case 9:
				assert(0 == createLoop(&headNode));
				break;
			case 10:
				if (isLoopInList(headNode))
					printf("\nNo loop in list");
				else
					printf("\nLoop present in list");

				break;
			case 11:
				assert(0 == removeLoop(&headNode));
				break;
			case 12:
				assert(0 == reverseList(&headNode));
				break;
			case 13:
				assert(0 == removeElement(&headNode));
				break;
			case 14:
				assert(0 == deleteList(&headNode));
				break;
			default:
				printf("\nRecieved input which is not listed!");
				printf("\nExiting.");
				break;
		}
	} while (option <= 14);

	return 0;
}
