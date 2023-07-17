#include<iostream>
#include<fstream>
using namespace std;
int main()
{
	int m, n, x, y; 
	ifstream fin;
	fin.open("in.txt", ios::in);
	fin >> m >> n >> x >> y;
	int num[1003][1003] = { 0 };
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			fin >> num[i][j];
		}
	}
	int max=0;int sum=0;
	for (int i = 0; i < m - x+1; i++)
	{
		for (int j = 0; j < n - y+1; j++)
		{
			for (int k = 0; k < x; k++)
			{
				for (int l = 0; l < y ; l++)
				{
					sum = sum + num[i + k][j + l];
				}
			}
			if (sum > max)
			{
				max = sum;
			}
			sum = 0;
		}
	}
	cout << max;
}


