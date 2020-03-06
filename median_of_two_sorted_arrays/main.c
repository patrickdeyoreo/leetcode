#include "median_of_two_sorted_arrays.h"

/**
 * joinSortedArrays - join to sorted arrays
 * @array1: pointer to the first element of an array
 * @size1: size of the array pointed to by array1
 * @array2: pointer to the first element of an array
 * @size2: size of the array pointed to by array22
 *
 * Return: If memory allocation fails, return NULL.
 * Otherwise, return a pointer to first element of the resulting array.
 */
int *joinSortedArrays(
	const int *array1, size_t size1, const int *array2, size_t size2
){
	int *res = malloc(sizeof(*res) * (size1 + size2));

	if (!res)
		return (NULL);

	res += size1 + size2;

	while (size1 && size2)
	{
		if (array1[size1 - 1] > array2[size2 - 1])
			*--res = array1[--size1];
		else
			*--res = array2[--size2];
	}
	while (size1--)
		*--res = array1[size1];
	while (size2--)
		*--res = array2[size2];

	return (res);
}

/**
 * printSortedArray - print an array of integers
 * @array: pointer to the first element of an array
 * @size: size of the array pointed to by array
 * @pre: string to print before the array
 * @sep: string to print between array elements
 * @end: string to print after the array
 */
void printSortedArray(
	const int *array, size_t size,
	const char *pre, const char *sep, const char *end
){
	fputs(pre, stdout);
	while (size--)
		printf("%d%s", *array++, size ? sep : "");
	fputs(end, stdout);
}

/**
 * main - entry point
 *
 * Return: Always 0.
 */
int main(void)
{
	int list0[] = {0, 2, 4, 6, 8};
	int list1[] = {1, 2, 3, 4};
	int list2[] = {2, 4, 8};
	int list3[] = {3, 5, 7};
	int list4[] = {1, 2};
	int list5[] = {3, 4};
	int *lists[] = {
		list0,
		list1,
		list2,
		list3,
		list4,
		list5,
		NULL
	};
	int sizes[] = {
		sizeof(list0) / sizeof(*list0),
		sizeof(list1) / sizeof(*list1),
		sizeof(list2) / sizeof(*list2),
		sizeof(list3) / sizeof(*list3),
		sizeof(list4) / sizeof(*list4),
		sizeof(list5) / sizeof(*list5),
		0
	};
	int *joined = NULL;
	double median = 0;
	size_t i = 0;
	size_t j = 0;

	while (i < sizeof(lists) / sizeof(*lists))
	{
		j = i;
		while (++j < sizeof(lists) / sizeof(*lists))
		{
			printf("* list A [size = %u]: ", sizes[i]);
			printSortedArray(lists[i], sizes[i], "[", ", ", "]\n");
			printf("* list B [size = %u]: ", sizes[j]);
			printSortedArray(lists[j], sizes[j], "[", ", ", "]\n");
			joined = joinSortedArrays(lists[i], sizes[i], lists[j], sizes[j]);
			printf("* joined [size = %u]: ", sizes[i] + sizes[j]);
			printSortedArray(joined, sizes[i] + sizes[j], "[", ", ", "]\n");
			free(joined);
			joined = NULL;
			median = findMedianSortedArrays(lists[i], sizes[i], lists[j], sizes[j]);
			printf("> median: %f\n\n", median);
		}
		++i;
	}
	return (0);
}
