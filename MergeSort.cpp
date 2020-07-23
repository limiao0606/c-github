#include<iostream>
#include<time.h>
#include<sys/timeb.h>
using namespace std;

#define MAX 10
//��������
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
	int length = 0;         //��ʾ�����ռ��ж��ٸ�Ԫ��
	//�ϲ�������������
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
	//i�������
	while (i_start <= i_end)
	{
		temp[length] = Arr[i_start];
		i_start++;
		length++;
	}
	//j�������
	while (j_start <= j_end)
	{
		temp[length] = Arr[j_start];
		j_start++;
		length++;
	}
	//�����ռ串��ԭ�ռ�
	for (int i=0;i<length;i++)
	{
		Arr[start + i] = temp[i];
	
	}
}
//�鲢����
void MergeSort(int Arr[], int start, int end, int* temp)
{
	if (start >= end)
	{
		return;
	}
	int mid = (start + end) / 2;
	//����
	//����
	MergeSort(Arr,start,mid,temp);
	//�Ұ��
	MergeSort(Arr, mid+1,end,temp);
	Merge(Arr,start,end,mid,temp);

}
//��ӡ����
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
	cout << "����ǰ��"<<endl;
	PrintArr(Arr,MAX);
	//�����ռ�
	int* temp = (int*)malloc(sizeof(int)*MAX);
	MergeSort(Arr,0,MAX-1,temp);
	cout << "�����" << endl;
	PrintArr(Arr, MAX);
	free(temp);
	free(Arr);
	system("pause");
	return 0;
}