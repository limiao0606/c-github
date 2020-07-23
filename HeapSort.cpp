#include<iostream>
using namespace std;

void Swap(int Arr[],int a, int b)
{
	int temp = Arr[a];
	Arr[a] = Arr[b];
	Arr[b] = temp;
}
//@param Arr ����������
//@param index �������Ľ����±�
//@param len ����ĳ���
void HeapAdjust(int Arr[],int index,int len)
{
	//�ȱ��浱ǰ�ڵ���±�
	int max=index;
	//�������Һ��ӵ������±�
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
//������
void HeapSort(int Arr[], int len)
{
	//��ʼ���ѣ��󶥶�
	for (int i = len / 2 - 1;i >= 0;i--)
	{
		HeapAdjust(Arr, i, len);
	}
	//�����Ѷ�Ԫ�������һ��Ԫ��
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
	cout << "����ǰ��" << endl;
	PrintArr(Arr, len);
	//������
	HeapSort(Arr, len);
	cout << "�����" << endl;
	PrintArr(Arr, len);
	system("pause");
	return 0;
}