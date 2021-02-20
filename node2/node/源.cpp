#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

typedef struct Node
{
	int data;
	Node* next;
}Node,*LinkedList;

LinkedList LinkedListInit()
{
	Node* L;
	L = (Node*)malloc(sizeof(Node));
	if (L == NULL)
	{
		cout << "申请内存空间失败！" << endl;
	}
	return L;
}

LinkedList LinkedListCreatH()
{
	Node* L =LinkedListInit();
	L->next = NULL;

	int x;
	while (scanf("%d", &x) != EOF)
	{
		Node* p;
		p = (Node*)malloc(sizeof(Node));
		p->data = x;
		p->next = L->next;
		L->next = p;
	}
	return L;
}

LinkedList LinkedListCreatT()
{
	Node* L = LinkedListInit();
	L->next = NULL;

	Node* r;
	r = L;

	int x;
	while (scanf("%d", &x) != EOF)
	{
		Node* p;
		p = (Node*)malloc(sizeof(Node));
		p->data = x;
		r->next = p;
		r = p;
	}
	r->next = NULL;
	return L;
}

LinkedList LinkedListInsert(LinkedList L, int i, int x)
{
	Node* pre;
	pre = L;
	int tempi = 0;
	for (tempi = 1; tempi < i; tempi++)
	{
		pre = pre->next;
	}
	Node* p;
	p = (Node*)malloc(sizeof(Node));
	p->data = x;
	p->next = pre->next;
	pre->next = p;
	return L;
}

LinkedList LinkedListDelete(LinkedList L, int i)
{
	if (i < 1)
		cout << "请输入大于等于1的正整数！" << endl;
	Node* pre;
	pre = L;
	int tempi = 0;
	for(tempi = 1;tempi < i;tempi++)
	{
		pre = pre->next;
	}
	Node* p = pre->next;
	pre->next = p->next;
	free(p);
	return L;
}

int LinkedListFind(LinkedList L, int x)
{
	Node* ret;
	int num;
	num = 1;
	L = L->next;
	while (L != NULL)
	{
		ret = L;
		if (ret->data == x)
		{
			cout << "找到第一个数据域为" << x << "的元素，他是链表中的第" << num << "个元素。" << endl;
			return num;
		}
		L = L->next;
		num++;
	}
	cout << "未找到该元素！" << endl;
	return -1;
}

void LinkedListFree(LinkedList& L)
{
	cout << "执行释放函数" << endl;
	Node* ret;
	do
	{
		ret = L;
		L = L->next;
		free(ret);
	} while (L != NULL);
	if (L == NULL)
	{
		cout << "释放函数执行完毕" << endl;
	}
}

int main()
{
	cout << "请输入单链表的数据：";
	LinkedList list,start;
	list = LinkedListCreatT();
	//LinkedListDelete(list, 3);
	for (start = list->next; start != NULL; start = start->next)
	{
		cout << start->data<<endl;
	}
	LinkedListFind(list, 6);
	LinkedListFree(list);
	if (list == NULL)
	{
		cout << "链表已释放完毕" << endl;
	}
	return 0;
}