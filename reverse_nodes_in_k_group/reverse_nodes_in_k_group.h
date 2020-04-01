#include <stdlib.h>
#include <stdio.h>

#ifndef REVERSE_NODES_IN_K_GROUP_H
#define REVERSE_NODES_IN_K_GROUP_H

/**
 * struct ListNode - linked list node
 * @data: integer value
 * @next: pointer to next node
 */
typedef struct ListNode {
	int data;
	struct ListNode *next;
} ListNode_t;

ListNode_t *reverseKGroup(ListNode_t *head, int k);
ListNode_t **_reverseKGroup(ListNode_t **head, ListNode_t *current, int k);
void printList(ListNode_t *head);
void deleteList(ListNode_t *head);
void deleteFirstNode(ListNode_t **head);

#endif
