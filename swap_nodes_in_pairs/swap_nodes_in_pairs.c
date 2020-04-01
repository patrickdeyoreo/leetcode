#include <stdlib.h>

/**
 * struct ListNode - linked list node
 * @val: integer value
 * @next: pointer to next node
 */
typedef struct ListNode {
	int val;
	struct ListNode *next;
} ListNode_t;

/**
 * swapPairs - solution A
 * @head: head of the list to operate on
 *
 * Return: pointer to the head of the resulting list
 */
ListNode_t *swapPairs(ListNode_t *head)
{
	ListNode_t *next;

	if (!head)
		return (NULL);
	next = head->next;
	if (!next)
		return (head);
	head->next = swapPairs(next->next);
	next->next = head;
	return (next);
}
