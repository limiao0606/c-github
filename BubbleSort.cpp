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
void Swap(int a, int b, int n)
{
	int temp = a;
	a = b;
	b = temp;
}
void BubbleSort(vector<int> &vc, int n)
{
	for (int i = 0;i < n - 1;i++)
	{
		for (int j = 0;j < n - i - 1;j++)
		{
			if (vc[j] > vc[j + 1])
			{
				swap(vc[j],vc[j+1]);
			}
		}
	}
}
void Print(vector<int> &vc, int n)
{
	for (int i = 0;i < n;i++)
	{
		cout << vc[i] << " ";
	}
}
int main()
{
	int n = 0;
	cin >> n;
	vector<int> vc;
	CreatArr(vc, n);
	cout << "ÅÅÐòÇ°£º" << endl;
	Print(vc,n);
	cout << endl;
	BubbleSort(vc,n);
	cout << "ÅÅÐòºó£º" << endl;
	Print(vc, n);
	system("pause");
	return 0;
}