#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

//树结点
typedef struct Node
{
	int data;
	Node* left;
	Node* right;
}Node,*Tree;

//二叉树建立
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

//前序遍历
void preOrder(Tree n)
{
	if (n != NULL)
	{
		cout << n->data << " ";
		preOrder(n->left);
		preOrder(n->right);
	}
}

//中序遍历
void inOrder(Tree n)
{
	if (n != NULL)
	{
		preOrder(n->left);
		cout << n->data << " ";
		preOrder(n->right);
	}
}

//后序遍历
void postOrder(Tree n)
{
	if (n != NULL)
	{
		preOrder(n->left);
		preOrder(n->right);
		cout << n->data << " ";
	}
}
//方法过于粗暴
//一般我们使用二叉搜索树BST
//可以降低搜索复杂度
//任意结点 右>根>左

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
	cout << "前序遍历：";
	preOrder(t);
	cout << endl;
	cout << "中序遍历：";
    inOrder(t);
	cout << endl;
	cout << "后序遍历：";
    postOrder(t);
	cout << endl;
	releaseTree(t);
	return 0;
}