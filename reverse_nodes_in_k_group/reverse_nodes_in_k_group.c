#include "reverse_nodes_in_k_group.h"

/**
 * reverseKGroup - reverse nodes within groups of size k
 * @head: head of the list to operate on
 * @k: the size of each group
 *
 * Return: pointer to the head of the resulting list
 */
ListNode_t *reverseKGroup(ListNode_t *head, int k)
{
	ListNode_t **group = &head;

	while (group && *group)
		group = _reverseKGroup(group, *group, k);
	return (head);
}


/**
 * _reverseKGroup - reverse nodes within groups of size k (helper function)
 * @head: the address of a pointer to the head of the list
 * @current: a pointer to the current node
 * @k: the size of each group
 *
 * Return: pointer to the head of the resulting list
 */
ListNode_t **_reverseKGroup(ListNode_t **head, ListNode_t *current, int k)
{
	if (k > 1)
	{
		if (!current->next)
			return (NULL);
		head = _reverseKGroup(head, current->next, k - 1);
		if (!head)
			return (NULL);
		current->next = (*head);
	}
	*head = current;
	return (&current->next);
}
