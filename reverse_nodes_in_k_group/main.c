#include "reverse_nodes_in_k_group.h"


/**
 * main - entry point
 *
 * Return:
 * 1 if memory allocation fails,
 * 0 otherwise.
 */
int main()
{
	ListNode_t *head = NULL, **tail = &head;
	int k = 15;

	while (--k && (*tail = malloc(sizeof(*head))))
	{
		(*tail)->next = NULL;
		(*tail)->data = k;
		tail = &(*tail)->next;
	}
	if (k)
	{
		deleteList(head);
		return (1);
	}
	puts("initial list:");
	printList(head);
	while (head)
	{
		k = 8;
		do {
			printf("reversing (k = %d)...\n", k);
			head = reverseKGroup(head, k);
			printList(head);
		} while (--k > 1);
		puts("deleting first node...");
		deleteFirstNode(&head);
	}
	return (0);
}


/**
 * deleteList - delete a list
 * @head: the address of a pointer to the first node
 */
void deleteFirstNode(ListNode_t **head)
{
	ListNode_t *temp = NULL;

	if (head && *head)
	{
		temp = *head;
		*head = (*head)->next;
		free(temp);
	}
}


/**
 * deleteList - delete a list
 * @head: the address of a pointer to the first node
 */
void deleteList(ListNode_t *head)
{
	if (head)
	{
		deleteList(head->next);
		free(head);
	}
}


/**
 * printList - print a list
 * @head: a pointer to the first node
 */
void printList(ListNode_t *head)
{
	if (head)
	{
		printf("%d", head->data);
		if (head->next)
		{
			printf(" -> ");
			printList(head->next);
		}
		else
		{
			puts("");
		}
	}
}
