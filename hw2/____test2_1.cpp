#include <iostream>
#include <stdlib.h>
#include <string.h>
#include<cstdio>
using namespace std;
class node_symbol
{
public:
	char symbol;
	node_symbol* link;
	void push(char c)
	{
		node_symbol* p = this;
		node_symbol* t = new node_symbol;
		t->symbol = c;
		t->link = NULL;
		while (p->link != NULL)
		{
			p = p->link;
		}
		p->link = t;
	}
	char pop()
	{
		node_symbol* p = this;
		node_symbol* t = p;
		while (p->link != NULL)
		{
			t = p;
			p = p->link;
		}
		t->link = NULL;
		return p->symbol;
	}
	char top()
	{
		node_symbol* p = this;
		while (p->link != NULL)
		{
			p = p->link;
		}
		return p->symbol;
	}
	bool isempty()
	{
		node_symbol* p = this;
		if (p->link == NULL)
			return 1;
		else
			return 0;
	}
}; 
class node
{
public:
	char data[20];
	node* left;
	node* right;
}; 
class node_stack
{
public:
	node* nd;
	node_stack* next;
	void push(node* ND)
	{
		node_stack* p = this;
		node_stack* q = new node_stack;
		q->next = NULL;
		q->nd = ND;
		while (p->next != NULL)
		{
			p = p->next;
		}
		p->next = q;
	}
	node* pop()
	{
		node_stack* p = this;
		node_stack* t = NULL;
		while (p->next != NULL)
		{
			t = p;
			p = p->next;
		}
		t->next = NULL;
		node* rtn = p->nd;
		free(p);
		return rtn;
	}
}; 
class tree
{
public:
	node* root;
};
int translate(char back_symbol[], char str[])
{
	char c;
	int i = 0;
	int k = 0;
	c = back_symbol[i];
	back_symbol[i] = ' ';
	i++;
	while (c == ' ')
	{
		c = back_symbol[i];
		back_symbol[i] = ' ';
		i++;
	}
	if (c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')' || c == '=')
	{
		str[0] = c;
		str[1] = '\0';
		return 1;
	}

	while (c >= '0' && c <= '9')
	{
		str[k++] = c;
		c = back_symbol[i];
		back_symbol[i] = ' ';
		i++;
	}
	str[k] = '\0';
	return i;
}
bool judge(char c, char top)
{
	if (c == '+' || c == '-')
	{
		if (top == '(')
			return 1;
		else
			return 0;
	}
	if (c == '*' || c == '/')
	{
		if (top == '(' || top == '+' || top == '-')
			return 1;
		return 0;
	}
	if (c == '(')
		return 1;

}
void get_order(node* Node)
{
	if (Node == NULL)
		return;
	if (Node->left != NULL)
		get_order(Node->left);
	if (Node->right != NULL)
		get_order(Node->right);
	cout << Node->data;

	return;
}
int  calculate(node* Node)
{
	if (Node->left == NULL && Node->right == NULL)
	{
		int num = 0;
		for (int i = 0; i < strlen(Node->data); i++)
		{
			num = num * 10 + Node->data[i] - '0';
		}
		return num;
	}
	if (Node->data[0] == '+')
		return  calculate(Node->left) + calculate(Node->right);
	if (Node->data[0] == '-')
		return  calculate(Node->left) - calculate(Node->right);
	if (Node->data[0] == '*')
		return  calculate(Node->left) * calculate(Node->right);
	if (Node->data[0] == '/')
		return  calculate(Node->left) / calculate(Node->right);
}
int main()
{
	char back_symbol[100];
	int len = 0;
	char c;
	node_symbol* symbol_stack = new node_symbol;
	c = getchar();
	while (1)
	{
		if (c == ' ')
		{
			c = getchar();
			continue;
		}
		if (c == '=')
			break;
		if (c == ')')
		{
			char tem = symbol_stack->pop();
			while (tem != '(')
			{
				back_symbol[len++] = tem;
				tem = symbol_stack->pop();
			}
			c = getchar();
			continue;
		}
		int flag = 0;
		while (c >= '0' && c <= '9')
		{
			flag = 1;
			back_symbol[len++] = c;
			c = getchar();
		}
		if (flag == 1)
		{
			back_symbol[len++] = ' ';
			continue;
		}
		if (c == '+' || c == '-' || c == '*' || c == '/' || c == '(')
		{
			if (symbol_stack->isempty())
			{
				symbol_stack->push(c);
				c = getchar();
				continue;
			}
			if (symbol_stack->isempty() == 0 && judge(c, symbol_stack->top()) > 0)
			{
				symbol_stack->push(c);
			}
			else if (judge(c,symbol_stack->top()) <= 0)
			{
				while (symbol_stack->isempty() == 0 && judge(c, symbol_stack->top()) <= 0)
				{
					char tem = symbol_stack->pop();
					back_symbol[len++] = tem;
				}
				symbol_stack->push(c);
			}
			c = getchar();
		}
	}
	while (symbol_stack->isempty() == 0)
	{
		char tem = symbol_stack->pop();
		back_symbol[len++] = tem;
	}
	back_symbol[len++] = '=';
	back_symbol[len++] = '\0';

	char tmp[20];
	node_stack* tree_stack = new node_stack;
	while (translate(back_symbol, tmp) > 0)
	{
		if (tmp[0] >= '0' && tmp[0] <= '9')
		{
			node* p = new node;
			strcpy(p->data, tmp);
			p->left = NULL;
			p->right = NULL;
			tree_stack->push(p);
		}
		else
		{
			if (tmp[0] == '=')
				break;

			node* p = new node;
			strcpy(p->data, tmp);
			p->left = NULL;
			p->right = NULL;

			node* t = tree_stack->pop();
			p->right = t;
			t = tree_stack->pop();
			p->left = t;
			tree_stack->push(p);
		}
	}
	cout << tree_stack->next->nd->data << " ";
	if (tree_stack->next->nd->left)
	{
		cout << tree_stack->next->nd->left->data << " ";
	}
	if (tree_stack->next->nd->right)
	{
		cout << tree_stack->next->nd->right->data;
	}
	puts("");
	cout << calculate(tree_stack->next->nd);
}
