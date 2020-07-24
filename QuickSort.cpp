#include<iostream>
using namespace std;
void QuickSort(int Arr[], int start,int end)
{
	int i = start;
	int j = end;
	//��׼��
	int temp = Arr[start];
	if (i < j)
	{
		//����������Ԫ�ض��ͻ�׼�����бȽ�
		while (i<j)
		{
			//���������ұȻ�׼��С��Ԫ��
			while (i<j&&Arr[j] >= temp)
			{
				j--;
			}
			//���
			if (i < j)
			{
				Arr[i] =Arr[j];
				i++;
			}
			//���������ұȻ�׼�����Ԫ��
			while (i < j && Arr[i] < temp)
			{
				i++;
			}
			//���
			if (i < j)
			{
				Arr[j] = Arr[i];
				j--;
			}
		}
		//�ѻ�׼������iλ��
		Arr[i] = temp;
		//����벿�ֿ�������
		QuickSort(Arr, start, i - 1);
		//���Ұ벿�ֿ�������
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
	cout << "����ǰ��" << endl;
	PrintArr(Arr, len);
	QuickSort(Arr, 0,len-1);
	cout << "�����" << endl;
	PrintArr(Arr, len);
	system("pause");
	return 0;
}