#include<iostream>
#include<vector>
using namespace std;
void CreatArr(vector<int>& vc, int n)
{
	for (int i = 0;i < n;i++)
	{
		int a = 0;
		cin >> a;
		vc.push_back(a);
	}
}
void InsertSort(vector<int>& vc, int n)
{
	int j;
	for (int i = 1;i < n;i++)
	{
		if (vc[i] < vc[i-1])
		{
			int temp = vc[i];
			for (j = i - 1;j >= 0 && temp < vc[j];j--)
			{
				vc[j + 1] = vc[j];
			}
			vc[j + 1] = temp;
		}
	
	}
}
void PrintArr(vector<int> vc,int n)
{
	for (int i = 0;i < n;i++)
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
	CreatArr(vc, n);
	cout << "ÅÅÐòÇ°£º" << endl;
	PrintArr(vc, n);
	InsertSort(vc, n);
	cout << "ÅÅÐòºó£º" << endl;
	PrintArr(vc, n);
	system("pause");
	return 0;
}