#include"head.h"
#include<algorithm>

 

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
	int n = numsSize;
	BubbleSort(  nums ,  15); //对数组进行排序；
	for (int first = 0; first < n; first++) {
		if(nums[first]==nums[first-1]&&first>0)   //判断重复条件，枚举过程中如果还是和之前元素一样，就直接跳过本次循环；
			continue;
		int third=n-1;                            //确定第三个指针；
		int	target = -nums[n - 1];                    //设定第一个指针对应的相反数，用以判断第二个第三个指针的左右遍历；
		for (int second = first + 1; second < n; second++) {
			if (nums[second] == nums[second - 1] && second > first + 1) {
				continue;
			}
			while (second<third && nums[second] + nums[third]>target)
				third--;
			if (second == third)
				break;
			if (nums[second] + nums[third] == target) {
				returnColumnSizes[0] = nums[first];
				returnColumnSizes[1] = nums[second];
				returnColumnSizes[2] = nums[third];

			}

		}
	}
	return returnColumnSizes;
	

}
 
void BubbleSort(int a[], int n)
{
	int t;
	for (int i = 0; i < n; i++)
	{
		for (int j = n - 1; j > i; j--)
		{
			if (a[j - 1] > a[j])
			{
				t = a[j - 1];
				a[j - 1] = a[j];
				a[j] = t;
			}
		}
		printf("NO.%d:  ", i + 1);

		for (int j = 0; j < n; j++)
		{
			printf("%2d", a[j]);

		}
		printf("\n");
	}
}
 
