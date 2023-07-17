#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
class ListNode
{
public:
	int num;
	ListNode* next;
	ListNode* pre;
};
class List
{
public:
	ListNode* headNode;
	ListNode* backNode;
	int size = 0;
	void push_back(int n)
	{
		ListNode*p=new ListNode;
		p->num = n;
		if (size==0)
		{
			headNode = p;
			backNode = p;
		}
		else
		{
			p->pre = backNode;
			backNode->next = p;
			backNode = p;
		}
		size++;
	}
	void delet_back()
	{
		if (size>0)
		{
			backNode->pre->next = NULL;
			size--;
		}
		else
		{
			cout << "error!";
		}
	}
};
int main()
{
	List l1, l2;
	string s1, s2;
	getline(cin, s1);
	getline(cin, s2);
	string TEMP; int start = 0;
	for (int i = 0; i < s1.size(); i++)
	{
		if (s1[i] == ' '||i== s1.size()-1)
		{
			TEMP = s1.substr(start, i);
			start = i + 1;
			int n = stoi(TEMP);
			l1.push_back(n);
			TEMP.clear();
		}
	}
	start = 0;
	for (int i = 0; i < s2.size()+1; i++)
	{
		if (s2[i] == ' ' || i == s2.size() - 1)
		{
			TEMP = s2.substr(start, i );
			start = i + 1;
			int n = stoi(TEMP);
			l2.push_back(n);
			TEMP.clear();
		}
	}
	vector<int>NUM;
	ListNode*  temp = l1.headNode;
	for(int i=0;i<l1.size;i++)
	{
		NUM.push_back(temp->num);
		if (i != l1.size - 1)
		{
			temp = temp->next;
		}
	}
	temp = l2.headNode;
	for (int i = 0; i < l2.size; i++)
	{
		NUM.push_back(temp->num);
		if (i != l2.size - 1)
		{
			temp = temp->next;
		}
	}
	int count = 0;
	sort(NUM.begin(), NUM.end()); 
	for (int i = 0; i < NUM.size(); i++)
	{
		if (i > 0)
		{
			for (int j = 0; j < i; j++)
			{
				if (NUM[i] == NUM[j])
				{
					NUM[i] = 999;
					count++;
				}
			}
		}
	}
	sort(NUM.begin(), NUM.end());
	List l; 
	for (int i = 0; i < NUM.size(); i++)
	{
		l.push_back(NUM[i]);
		if (NUM[i] != 999)
		{
			cout << NUM[i] ;
			if (i != (NUM.size() - count ))
			{
				cout << " ";
			}
		}
		
	}
}


