#include<iostream>
using namespace std;

void Swap(int Arr[],int a, int b)
{
	int temp = Arr[a];
	Arr[a] = Arr[b];
	Arr[b] = temp;
}
//@param Arr 待调整数组
//@param index 待调整的结点的下标
//@param len 数组的长度
void HeapAdjust(int Arr[],int index,int len)
{
	//先保存当前节点的下标
	int max=index;
	//保存左右孩子的数组下标
	int lchild = index * 2+1;
	int rchild = index * 2 + 2;

	if (lchild<len && Arr[lchild]>Arr[max])
	{
		max = lchild;
	}
	if (rchild<len && Arr[rchild]>Arr[max])
	{
		max = rchild;
	}
	if (max != index)
	{
		Swap(Arr,max,index);
		HeapAdjust(Arr,max,len);
	}
}
//堆排序
void HeapSort(int Arr[], int len)
{
	//初始化堆，大顶堆
	for (int i = len / 2 - 1;i >= 0;i--)
	{
		HeapAdjust(Arr, i, len);
	}
	//交换堆顶元素与最后一个元素
	for (int i = len - 1;i >= 0;i--)
	{
		Swap(Arr,0,i);
		HeapAdjust(Arr,0,i);
		
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
	int Arr[] = {4,2,8,0,5,7,1,3,9};
	int len = sizeof(Arr) / sizeof(Arr[0]);
	cout << "排序前：" << endl;
	PrintArr(Arr, len);
	//堆排序
	HeapSort(Arr, len);
	cout << "排序后：" << endl;
	PrintArr(Arr, len);
	system("pause");
	return 0;
}