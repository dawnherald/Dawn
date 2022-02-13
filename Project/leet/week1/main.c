#include"head.h"
 
int Math_max(int Num1, int Num2)
{
		if (Num1 < Num2)
			return Num2;
		else
			return Num1;
}

int Math_min(int Num1, int Num2)
{
		if (Num2 < Num1)
			return Num2;
		else
			return Num1;
}

int maxArea(int* height, int heightSize)
{
	int x = 0;
	int y = heightSize - 1;
	int MaxArea = 0;
	int max;
	while (x < y)
	{
		max = Math_min(height[x], height[y]) * (y - x);
		MaxArea = Math_max(max, MaxArea);
		if (height[x] <= height[y])
			x++;
		else
			y--;
	}
	return MaxArea;
}
int main(void)
{

	return 0;
}

 
