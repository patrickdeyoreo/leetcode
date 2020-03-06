#include <stdlib.h>

/**
 * struct ListNode - linked list node
 * @val: integer value
 * @next: pointer to next node
 */
struct ListNode {
	const char *data;
	struct ListNode *next;
};

/**
 * swapPairs - solution A
 * @head: head of the list to operate on
 *
 * Return: pointer to the head of the resulting list
 */
struct ListNode *swapPairs(struct ListNode *head)
{
	struct ListNode *next;

	if (!head)
		return (NULL);
	next = head->next;
	if (!next)
		return (head);
	head->next = swapPairs(next->next);
	next->next = head;
	return (next);
}
