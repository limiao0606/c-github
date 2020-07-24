#include<iostream>
using namespace std;
void QuickSort(int Arr[], int start,int end)
{
	int i = start;
	int j = end;
	//基准数
	int temp = Arr[start];
	if (i < j)
	{
		//数组中所有元素都和基准数进行比较
		while (i<j)
		{
			//从右向左找比基准数小的元素
			while (i<j&&Arr[j] >= temp)
			{
				j--;
			}
			//填坑
			if (i < j)
			{
				Arr[i] =Arr[j];
				i++;
			}
			//从左向右找比基准数大的元素
			while (i < j && Arr[i] < temp)
			{
				i++;
			}
			//填坑
			if (i < j)
			{
				Arr[j] = Arr[i];
				j--;
			}
		}
		//把基准树放在i位置
		Arr[i] = temp;
		//对左半部分快速排序
		QuickSort(Arr, start, i - 1);
		//对右半部分快速排序
		QuickSort(Arr, i+1, end);
	}
}
void PrintArr(int Arr[], int len)
{
	for (int i = 0;i < len;i++)
	{
		cout << Arr[i] << " ";
	}
	cout << endl;
}

int main()
{
	int Arr[] = { 4,2,8,0,5,7,1,3,9 };
	int len = sizeof(Arr) / sizeof(Arr[0]);
	cout << "排序前：" << endl;
	PrintArr(Arr, len);
	QuickSort(Arr, 0,len-1);
	cout << "排序后：" << endl;
	PrintArr(Arr, len);
	system("pause");
	return 0;
}