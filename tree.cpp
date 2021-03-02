#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

//�����
typedef struct Node
{
	int data;
	Node* left;
	Node* right;
}Node,*Tree;

//����������
Tree createBinaryTree()
{
	Node* n;
	n = (Node*)malloc(sizeof(Node));
	int Value;
	cin >> Value;
	if (Value == -1)
	{
		free(n);
		n = NULL;
		return NULL;
	}
	else
	{
		n->data = Value;
		n->left = createBinaryTree();
		n->right = createBinaryTree();
		return n;
	}
}

//ǰ�����
void preOrder(Tree n)
{
	if (n != NULL)
	{
		cout << n->data << " ";
		preOrder(n->left);
		preOrder(n->right);
	}
}

//�������
void inOrder(Tree n)
{
	if (n != NULL)
	{
		preOrder(n->left);
		cout << n->data << " ";
		preOrder(n->right);
	}
}

//�������
void postOrder(Tree n)
{
	if (n != NULL)
	{
		preOrder(n->left);
		preOrder(n->right);
		cout << n->data << " ";
	}
}
//�������ڴֱ�
//һ������ʹ�ö���������BST
//���Խ����������Ӷ�
//������ ��>��>��

void releaseTree(Tree t)
{
	if (t != NULL)
	{
		releaseTree(t->left);
		releaseTree(t->right);
		free(t);
		t = NULL;
	}
}

int main()
{
	Tree t = createBinaryTree();
	cout << "ǰ�������";
	preOrder(t);
	cout << endl;
	cout << "���������";
    inOrder(t);
	cout << endl;
	cout << "���������";
    postOrder(t);
	cout << endl;
	releaseTree(t);
	return 0;
}