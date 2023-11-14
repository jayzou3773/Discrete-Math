#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
using namespace std;
#define N 13
int n;
struct tree
{
	int num;
	struct tree* Lnode;
	struct tree* Rnode;
}*fp[N];     //保存结点 

char s[2*N] ; 
//放前缀码

void init_node(int f[], int n)  //生成叶子结点
{
	int i;
	struct tree* pt;
	for (i = 0; i < n; i++)
	{
		pt = (struct tree*)malloc(sizeof(struct tree));  //生成叶子结点 
		pt->num = f[i];
		pt->Lnode = NULL;
		pt->Rnode = NULL;
		fp[i] = pt;
	}
}

void sort(struct tree* array[], int n)  //将第N-n个点插入到已排好序的序列中
{
	int i;
	struct tree* temp;
	for (i = N - n; i < N - 1; i++)
		if (array[i]->num > array[i + 1]->num)
		{
			temp = array[i + 1];
			array[i + 1] = array[i];
			array[i] = temp;
		}
}

struct tree* construct_tree(int f[], int n)  //建立树 
{
	int i;
	struct tree* pt;
	for (i = 1; i < N; i++)
	{
		pt = (struct tree*)malloc(sizeof(struct tree));  //生成非叶子结点 
		pt->num = fp[i - 1]->num + fp[i]->num;
		pt->Lnode = fp[i - 1];
		pt->Rnode = fp[i];
		fp[i] = pt;  //wl+w2
		sort(fp, N - i);
	}
	return fp[N - 1];
}

void preorder(struct tree* p, int k, char c)
{
	int j;
	if (p != NULL)
	{
		if (c == '1')
			s[k] = '0';
		else s[k] = '1';
		if (p->Lnode == NULL)
		{   //P 指向叶子 
			cout << p->num << ": ";
			for (j = 1; j <= k; j++)
				cout << s[j];
			cout << endl; 
		}
		preorder(p->Lnode, k + 1, '1');
		preorder(p->Rnode, k + 1, 'r');
	}
}

int main()
{
	
	cout << "请输入节点个数(必须是正整数):";
	cin >> n; 
	int f[80];
	cout << "请输入节点(以空格分隔):"; 
	for (int i = 0; i < n; i++)
	{
		cin >> f[i];
	}
	struct tree* head;
	init_node(f, N);  //初始化结点 
	head = construct_tree(f, N);  //生成最优树 
	s[0] = 0;
	preorder(head, 0, '1');  //遍历树 
	return 0;
}
