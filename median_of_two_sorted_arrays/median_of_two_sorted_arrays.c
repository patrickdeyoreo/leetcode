#include "median_of_two_sorted_arrays.h"

#define AVG(a, b) (((a) + (b)) / 2.0)
#define MAX(a, b) (((a) > (b)) ? (a) : (b))
#define MIN(a, b) (((a) < (b)) ? (a) : (b))

/**
 * findMedianSortedArrays - solution (helper)
 * @small: pointer to the first element of the smaller array
 * @smallSize: size of the array pointed to by small
 * @large: pointer to the first element of the larger array
 * @largeSize: size of the array pointed to by small
 * @lower: lower partition bound of the smaller array (inclusive)
 * @upper: upper partition bound of the smaller array (exclusive)
 *
 * Return: the median of the two arrays
 */
double findMedianSortedArrays_(
	int *small, int smallSize, int *large, int largeSize, int lower, int upper
){
	int smallPart = (lower + upper) / 2;
	int largePart = (smallSize + largeSize + 1) / 2 - smallPart;
	double smallMaxLower = smallPart != 0 ? small[smallPart - 1] : 0;
	double smallMinUpper = smallPart != smallSize ? small[smallPart] : 0;
	double largeMaxLower = largePart != 0 ? large[largePart - 1] : 0;
	double largeMinUpper = largePart != largeSize ? large[largePart] : 0;

	if (smallPart == 0 && largePart != largeSize)
		smallMaxLower = largeMinUpper;
	if (smallPart != 0 && largePart == largeSize)
		largeMinUpper = smallMaxLower;
	if (largePart == 0 && smallPart != smallSize)
		largeMaxLower = smallMinUpper;
	if (largePart != 0 && smallPart == smallSize)
		smallMinUpper = largeMaxLower;

	if (smallMaxLower <= largeMinUpper && largeMaxLower <= smallMinUpper)
	{
		if ((smallSize + largeSize) % 2 == 0)
			return (AVG(MAX(smallMaxLower, largeMaxLower),
						MIN(smallMinUpper, largeMinUpper)));
		else
			return (MAX(smallMaxLower, largeMaxLower));
	}
	if (smallMaxLower > largeMinUpper)
		return (findMedianSortedArrays_(
				small, smallSize, large, largeSize, lower, smallPart - 1
		));
	else
		return (findMedianSortedArrays_(
				small, smallSize, large, largeSize, smallPart + 1, upper
		));
}

/**
 * findMedianSortedArrays - solution
 * @nums1: pointer to the first element of an array
 * @nums1Size: size of the array pointed to by nums1
 * @nums2: pointer to the first element of an array
 * @nums2Size: size of the array pointed to by nums2
 *
 * Return: the median of the two arrays
 */
double findMedianSortedArrays(
	int *nums1, int nums1Size, int *nums2, int nums2Size
){
	if (!nums1Size)
	{
		if (nums2Size % 2 == 0)
			return (AVG(nums2[nums2Size / 2],
						nums2[nums2Size / 2 - 1]));
		else
			return (nums2[nums2Size / 2]);
	}
	if (!nums2Size)
	{
		if (nums1Size % 2 == 0)
			return (AVG(nums1[nums1Size / 2],
						nums1[nums1Size / 2 - 1]));
		else
			return (nums1[nums1Size / 2]);
	}
	if (nums1Size > nums2Size)
		return (findMedianSortedArrays(
				nums2, nums2Size, nums1, nums1Size
		));
	if (nums1[0] >= nums2[nums2Size - 1])
	{
		if (nums1Size == nums2Size)
			return (AVG(nums1[0], nums2[nums2Size - 1]));
		else if ((nums1Size + nums2Size) % 2 == 0)
			return (AVG(nums2[(nums1Size + nums2Size - 1) / 2],
						nums2[(nums1Size + nums2Size + 1) / 2]));
		else
			return (nums2[(nums1Size + nums2Size) / 2]);
	}
	if (nums2[0] >= nums1[nums1Size - 1])
	{
		if (nums2Size == nums1Size)
			return (AVG(nums2[0], nums1[nums1Size - 1]));
		else if ((nums2Size + nums1Size) % 2 == 0)
			return (AVG(nums2[(nums2Size - nums1Size - 1) / 2],
						nums2[(nums2Size - nums1Size + 1) / 2]));
		else
			return (nums2[(nums1Size - nums2Size) / 2]);
	}
	return (findMedianSortedArrays_(
			nums1, nums1Size, nums2, nums2Size, 0, nums1Size
	));
}
