#include<iostream>
#include<vector>
using namespace std;
void CreatArr(vector<int> &vc,int n)
{
	for (int i = 0;i < n;i++)
	{
		int a = 0;
		cin >> a;
		vc.push_back(a);
	}
}
void swap(int a,int b,int n)
{
	int temp = a;
	a = b;
	b = temp;
}
void SelectSort(vector<int> &vc,int n)
{
	int min;
	for (int i = 0;i < n;i++)
	{
		min = i;
		for (int j = i+1;j < n;j++)
		{
			if (vc[min] > vc[j])
			{
				min = j;
			}
		}
		if (i != min)
		{
			swap(vc[min],vc[i]);
		}
	}
}
void PrintArr(vector<int> &vc, int n)
{
	for(int i=0;i<n;i++)
	{
		cout << vc[i] << " ";
	}
	cout << endl;
}
int main()
{
	int n = 0;
	cin >> n;
	vector<int> vc;
	CreatArr(vc,n);
	cout << "ÅÅÐòÇ°£º" << endl;
	PrintArr(vc, n);
	SelectSort(vc,n);
	cout << "ÅÅÐòºó£º" << endl;
	PrintArr(vc,n);
	system("pause");
	return 0;
}