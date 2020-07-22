#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int n = 0;
	cin >> n;
	vector<int> vc;
	for (int i = 0;i < n;i++)
	{
		int a = 0;
		cin >> a;
		vc.push_back(a);
	}
	for (int i = 0;i < n-1;i++)
	{
		for (int j = 0;j < n - i - 1;j++)
		{
			if (vc[j] > vc[j + 1])
			{
				int temp = vc[j];
				vc[j] = vc[j + 1];
				vc[j + 1] = temp;
			}
		}
	}
	for (int i = 0;i < n;i++)
	{
		cout << vc[i]<<" ";
	}
	cout << endl;
	system("pause");
	return 0;
}