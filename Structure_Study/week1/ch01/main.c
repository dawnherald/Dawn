#include<stdio.h>计算生日日期
//int main(void)
//{
//	char your[30], birthday[10];
//	char* birth1, * birth2=birthday;
//	gets(your);
//	for (birth1 = your + 6; birth1 < your + 14; birth1++)
//	{
//		*birth2 = *birth1;
//		birth2++;
//	}
//	*birth2 = '\0';
//	printf("%s", birthday);
//	return 0;
//}
//#include<stdio.h>输出每周几，和手写大字母
//int main(void)
//{
//	char *week[] = {"Monday","Tuesday","Wednesday","Thursday","Friday","saturday","Sunday"};
//	char** pwe=week;
//	printf("%-10x%-10x\n",&week[0][0],pwe);
//	for (; pwe < week + 7; pwe++)
//	{
//		printf("%-10c%-10s\n",**pwe,*pwe);
//	 
//	}
//
//	return 0;
//}
//#include<stdio.h> 用指针以及函数输入输出冒泡排序
//void inarry(int*);
//void outarry(int*);
//void bubble(int[]);
//void swap2(int*, int*);
//int main(void) 
//{
//	int array[10];
//	int* px = array;
//	inarry(array);
//	bubble(array);
//	outarry(array);
//	return 0;
//
// }
//void inarry(int *prr)
//{
//	int num_i;
//	for (num_i = 0; num_i <  10; num_i++)
//	{
//		scanf_s("%d",prr+num_i);
//	}
//}
//void outarry(int arr[])
//{
//	int num_i;
//	for (num_i = 0; num_i < 10; num_i++)
//	{
//		printf("%d\n", arr[num_i]);
//	}
//
//}
//void bubble(int arr[])
//{
//	int num_i, num_j, num_tra=0;
//	for (num_i = 1; num_i < 10; num_i++)
//	{
//		for (num_j = 0; num_j < 10 - num_i; num_j++)
//		{
//			if (arr[num_j] > arr[num_j + 1])
//			{
//				swap2(arr + num_j, arr + num_j + 1);
//
//			}
//		}
//	}
//}
//void swap2(int* px, int* py)
//{
//	int tra;
//	tra = *px, * px = *py, * py = tra;
//}
//#include<stdio.h>
//int main(void)
//{
//	struct test
//	{
//		char name;
//		int number;
//		int score;
//	};
//	printf("%d",sizeof(struct test));
//}
#include<stdio.h>
int main(void)
{
	struct date //先放结构里面最小的单元进行声明；不然会出错；
	{
		int year;
		int month;
		int day;
	}; 
	struct  student
	{
		char name;
		int number;
		int score;
		struct date birthday;
	}; 
	struct student x = { "sb",11,99,{2000,8,99} };
	
	printf("%d\n", sizeof(struct student));
	printf("%d年 ",x.birthday.year);
}
