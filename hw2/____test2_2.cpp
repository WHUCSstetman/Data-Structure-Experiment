#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
class edge
{
public:
	int id;
	int node_1;
	int node_2;
	int weight;
};
bool cmpweight(const edge& x, const edge& y)
{
	return x.weight < y.weight;
}
void refresh(bool visited[99][99],int node_1,int node_2)
{

}
int main()
{
	int n, e;
	cin >> n >> e;
	edge EDGE[99];
	int temp1, temp2, temp3, temp4; 
	for (int i = 0; i < e; i++)
	{
		cin >> temp1 >> temp2 >> temp3 >> temp4;
		EDGE[i].id = temp1;
		EDGE[i].node_1 = temp2;
		EDGE[i].node_2 = temp3;
		EDGE[i].weight = temp4;
	}
	int vset[99];
	sort(EDGE, EDGE + e, cmpweight);
	for (int i = 0; i < n; i++)
	{
		vset[i] = i;
	}
	int order = 1; 
	bool choice[99] = { false };
	int i = 0;
	while (order < n)
	{
		int node_1 = EDGE[i].node_1;
		int node_2 = EDGE[i].node_2;
		int n1 = vset[node_1];
		int n2 = vset[node_2];
		if (n1 != n2)
		{
			choice[i] = true;
			order++;
			for (int j = 0; j < n; j++)
			{
				if (vset[j] == n2)
				{
					vset[j] = n1;
				}
			}
		}
		i++;
	}
	int sum = 0;
	for (int j = 0; j < e; j++)
	{
		if (choice[j])
		{
			sum = sum + EDGE[j].weight;
		}
	}
	cout << sum << endl;
	vector<int> get_EDGE; int m = 0;
	for (int j = 0; j < e; j++)
	{
		if (choice[j]) 
		{
			get_EDGE.push_back(EDGE[j].id);
		}
	}
	sort(get_EDGE.begin(), get_EDGE.end());
	for (int j = 0; j < n - 1; j++)
	{
		cout << get_EDGE[j];
		if (j < n - 2)
		{
			cout << " ";
		}
	}
}
