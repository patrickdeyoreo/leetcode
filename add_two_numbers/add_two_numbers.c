#include <stdlib.h>

/**
 * struct ListNode - linked list node
 * @val: integer value
 * @next: pointer to next node
 */
struct ListNode
{
	int val;
	struct ListNode *next;
};

/**
 * addTwoNumbers_ - solution A (helper)
 * @l1: pointer to a non-empty list of digits from least to most significant
 * @l2: pointer to a non-empty list of digits frpm least to most significant
 * @sum: pointer to a pointer to the tail of the resulting list
 */
void addTwoNumbers_(struct ListNode *l1, struct ListNode *l2, struct ListNode **sum)
{
	if (!l1 && !l2)
		return;
	if (!*sum)
		(*sum) = calloc(1, sizeof(**sum));
	if (!*sum)
		return;
	if (l1)
		(*sum)->val += l1->val, l1 = l1->next;
	if (l2)
		(*sum)->val += l2->val, l2 = l2->next;
	if ((*sum)->val >= 10)
	{
		(*sum)->next = calloc(1, sizeof(**sum));
		if (!(*sum)->next)
			return;
		(*sum)->next->val = (*sum)->val / 10;
		(*sum)->val %= 10;
	}
	addTwoNumbers_(l1, l2, &(*sum)->next);
}

/**
 * addTwoNumbers - solution A
 * @l1: pointer to a non-empty list of digits from least to most significant
 * @l2: pointer to a non-empty list of digits frpm least to most significant
 *
 * Return: If memory allocation fails, return NULL.
 * Otherwise, return a pointer to a new list containing the sum of l1 and l2.
 */
struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2)
{
	struct ListNode *sum = NULL;

	addTwoNumbers_(l1, l2, &sum);
	return (sum);
}

/**
 * addTwoNumbers - solution B
 * @l1: pointer to a non-empty list of digits from least to most significant
 * @l2: pointer to a non-empty list of digits frpm least to most significant
 *
 * Return: If memory allocation fails, return NULL.
 * Otherwise, return a pointer to a new list containing the sum of l1 and l2.
 */
struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2)
{
	struct ListNode *sum = NULL, **l3 = &sum;
	int c = 0;

	do {
		*l3 = calloc(1, sizeof(**l3));
		if (!*l3)
			break;
		if (c)
			(*l3)->val += 1;
		if (l1)
			(*l3)->val += l1->val, l1 = l1->next;
		if (l2)
			(*l3)->val += l2->val, l2 = l2->next;
		c = (*l3)->val >= 10;
		if (c)
			(*l3)->val %= 10;
	} while ((l3 = &(*l3)->next), l1 || l2 || c);

	return (sum);
}
