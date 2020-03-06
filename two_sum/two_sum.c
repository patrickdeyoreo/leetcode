#include <stdlib.h>

#define SIZE 1979
#define ABS(x) ((x) < 0 ? -(x) : (x))
#define HASH(x) (ABS(x) % SIZE)

/**
 * struct hash_node_s - hash table chain node
 * @next: pointer to the next node in a chain
 * @key: key of the item in the hash table
 * @value: value of the item in the hash table
 */
typedef struct hash_node_s
{
	struct hash_node_s *next;
	int key;
	int value;
} hash_node_t;

/**
 * hash_node_del - delete a hash table chain
 * @chain: pointer to a hash table chain
 */
void hash_node_del(hash_node_t *chain)
{
	if (chain)
	{
		hash_node_del(chain->next);
		free(chain);
	}
}

/**
 * hash_table_del - delete a hash table
 * @table: pointer to a hash table
 */
void hash_table_del(hash_node_t *(*table)[SIZE])
{
	size_t index = 0;

	while (index < SIZE)
		hash_node_del((*table)[index++]);
}

/**
 * hash_node_put - insert an item into a hash table chain
 * @chain: pointer to a hash table chain
 * @key: key of the item
 * @value: value of the item
 *
 * Return: If memory allocation fails, return NULL.
 * Otherwise, return a pointer to the item.
 */
hash_node_t *hash_node_put(hash_node_t **chain, int key, int value)
{
	hash_node_t *item;

	if (*chain && key > (*chain)->key)
		return (hash_node_put(&(*chain)->next, key, value));

	item = malloc(sizeof(*item));
	if (item)
	{
		item->key = key;
		item->value = value;
		item->next = *chain;
		*chain = item;
	}
	return (item);
}

/**
 * hash_table_put - insert an item into a hash table
 * @table: pointer to a hash table
 * @key: key of the item
 * @value: value of the item
 *
 * Return: If memory allocation fails, return NULL.
 * Otherwise, return a pointer to the item.
 */
hash_node_t *hash_table_put(hash_node_t *(*table)[SIZE], int key, int value)
{
	return (hash_node_put(*table + HASH(key), key, value));
}

/**
 * hash_node_get - get an item from a hash table chain
 * @chain: pointer to a hash table chain
 * @key: the key of the item
 *
 * Return: If the key does not exist in the table, return NULL.
 * Otherwise, return a pointer to to the item.
 */
hash_node_t *hash_node_get(hash_node_t *chain, int key)
{
	if (chain)
	{
		if (key > chain->key)
			return (hash_node_get(chain->next, key));
		if (key == chain->key)
			return (chain);
	}
	return (NULL);
}

/**
 * hash_table_get - get an item from a hash table
 * @table: pointer to a hash table
 * @key: the key of the item
 *
 * Return: If the key does not exist in the table, return NULL.
 * Otherwise, return a pointer to to the item.
 */
hash_node_t *hash_table_get(hash_node_t *(*table)[SIZE], int key)
{
	return (hash_node_get((*table)[HASH(key)], key));
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
	hash_node_t *table[SIZE] = {0};
	hash_node_t *item = NULL;
	int *result = NULL;
	int i = 0;

	for (*returnSize = 0; i < numsSize; ++i)
	{
		item = hash_table_get(&table, target - nums[i]);
		if (item)
		{
			result = malloc(sizeof(*result) * 2);
			if (result)
			{
				result[0] = item->value;
				result[1] = i;
				*returnSize = 2;
			}
			break;
		}
		hash_table_put(&table, nums[i], i);
	}
	hash_table_del(&table);
	return (result);
}
