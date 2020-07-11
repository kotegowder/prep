#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/* Problem statement
 * You are given two non-empty linked lists representing two non-negative integers.
 * The digits are stored in reverse order and each of their nodes contain a single digit.
 * Add the two numbers and return it as a linked list.
 *
 * You may assume the two numbers do not contain any leading zero, except the number 0 itself.*/

struct ListNode {
	int val;
    	struct ListNode *next;
};

void addAtHead(struct ListNode **ref, int val) {
	struct ListNode *new = (struct ListNode *)malloc(sizeof(struct ListNode));

	new->val = val;

	if (*ref == NULL) {
		new->next = NULL;
		*ref = new;
		return;
	}

	new->next = *ref;
	*ref      = new;

	return;
}

void addAtTail(struct ListNode **ref, int val) {
    struct ListNode *new = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *curNode = *ref;

    new->val = val;
    new->next = NULL;

    if (*ref == NULL) {
        *ref = new;
        return;
    }

    while(curNode->next != NULL)
        curNode = curNode->next;

    curNode->next = new;

    return;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){

    struct ListNode *head = NULL;
    int carry = 0, sum;

    while((l1 != NULL) || (l2 != NULL)) {

        sum = ((l1 != NULL) ? l1->val : 0) +
              ((l2 != NULL) ? l2->val : 0) +
              carry;
        addAtTail(&head, sum%10);
        carry = sum / 10;

        if (l1 != NULL)
            l1 = l1->next;

        if (l2 != NULL)
            l2 = l2->next;
    }

    if (carry)
        addAtTail(&head, carry);

    return head;
}

int main(void)
{
	struct ListNode *L1=NULL, *L2=NULL;
	int L1Cnt, L2Cnt, val, num=0, mult_factor=1;

	printf("Enter number of elements in List 1 : ");
	scanf("%d", &L1Cnt);

	for(int i=0; i<L1Cnt; i++) {
		printf("Enter value : ");
		scanf("%d", &val);
		addAtHead(&L1, val);
	}

	printf("Enter number of elements in List 2 : ");
	scanf("%d", &L2Cnt);

	for(int i=0; i<L2Cnt; i++) {
		printf("Enter value : ");
		scanf("%d", &val);
		addAtHead(&L2, val);
	}

	struct ListNode *res = addTwoNumbers(L1, L2);
	struct ListNode *curNode = res;

	/* Reverse the digits to get final sum */
	while(curNode != NULL) {
		num += (curNode->val * mult_factor);
		mult_factor *= 10;
		curNode = curNode->next;
	}

	free(L1);
	free(L2);
	free(res);

	printf("Sum = %d\n", num);

	return 0;
}
