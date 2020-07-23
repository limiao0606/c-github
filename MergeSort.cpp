#include<iostream>
#include<time.h>
#include<sys/timeb.h>
using namespace std;

#define MAX 10
//创建数组
int* CreatArr()
{
	srand((unsigned int)time(NULL));
	int* Arr = (int *)malloc(sizeof(int) *MAX);
	for (int i = 0;i < MAX;i++)
	{
		Arr[i] = rand() % MAX;
	}
	return Arr;
}
void Merge(int Arr[],int start, int end,int mid, int* temp)
{
	int i_start = start;
	int i_end = mid;
	int j_start = mid + 1;
	int j_end = end;
	int length = 0;         //表示辅助空间有多少个元素
	//合并两个有序序列
	while (i_start <= i_end && j_start <= j_end)
	{
		if (Arr[i_start] < Arr[j_start])
		{
			temp[length] = Arr[i_start];
			length++;
			i_start++;
		}
		else
		{
			temp[length] = Arr[j_start];
			j_start++;
			length++;
		}
	}
	//i这个序列
	while (i_start <= i_end)
	{
		temp[length] = Arr[i_start];
		i_start++;
		length++;
	}
	//j这个序列
	while (j_start <= j_end)
	{
		temp[length] = Arr[j_start];
		j_start++;
		length++;
	}
	//辅助空间覆盖原空间
	for (int i=0;i<length;i++)
	{
		Arr[start + i] = temp[i];
	
	}
}
//归并排序
void MergeSort(int Arr[], int start, int end, int* temp)
{
	if (start >= end)
	{
		return;
	}
	int mid = (start + end) / 2;
	//分组
	//左半边
	MergeSort(Arr,start,mid,temp);
	//右半边
	MergeSort(Arr, mid+1,end,temp);
	Merge(Arr,start,end,mid,temp);

}
//打印数组
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
	int * Arr = CreatArr();
	cout << "排序前："<<endl;
	PrintArr(Arr,MAX);
	//辅助空间
	int* temp = (int*)malloc(sizeof(int)*MAX);
	MergeSort(Arr,0,MAX-1,temp);
	cout << "排序后：" << endl;
	PrintArr(Arr, MAX);
	free(temp);
	free(Arr);
	system("pause");
	return 0;
}