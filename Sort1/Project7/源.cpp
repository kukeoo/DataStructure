#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <iostream>

using namespace std;

//函数模板
//两个整型交换函数
void swapInt(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

//两个浮点型交换函数
void swapDouble(double& a, double& b)
{
	double temp = a;
	a = b;
	b = temp;
}

//函数模板
template<typename T>//声明一个模板
//typename可以替换成class
//告诉编译器后面代码中紧跟着的T不要报错，T是一个通用数据类型
void mySwap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

template<typename T>
void mySelectSort(T array[], int len)
{
	for (int i = 0; i < len-1; i++)
	{
		int max = i;
		for (int j = i + 1; j < len; j++)
		{
			if (array[max] < array[j])
			{
				max = j;
			}
		}
		if (array[i] != array[max])
		{
			mySwap<int>(array[i], array[max]);
		}
		cout << "这是第" << i + 1 << "趟排序" << endl;
	}
}

template<typename T>
void myBubbleSort(T array[], int len)
{
	
	for (int i = 0; i < len - 1; i++)
	{
		bool flag = false;
		for (int j = 0; j < len - 1 - i; j++)
		{
			if (array[j] > array[j + 1])
			{
				mySwap<int>(array[j], array[j + 1]);
				flag = true;
			}
		}
		cout << "这是第" << i + 1 << "趟排序" << endl;
		if (flag == false)
		{
			return;
		}
	}
}

template<typename T>
void myInsertSort(T array[], int len)
{
	for (int i = 1; i < len; i++)
	{
		int j = i;
		T temp = array[i];
		int num = 0;
		while (j)
		{
			if (temp < array[j - 1])
			{
				array[j] = array[j - 1];
				j--;
				num++;
				cout << "这是第" << i << "趟排序中的第"<<num<<"次挪位" << endl;
			}
			else
			{
				break;
			}
		}
		array[j] = temp;
		cout << "这是第" << i << "趟排序" << endl;
	}
}

//template<typename T>
//void myShellSort(T array[], int len)
//{
//	int d = 0;//初始化增量
//	for (int d = n / 2; d >= 1; d = d / 2)
//	{
//		for (int i = 0; i < n; i += d)
//		{
//
//		}
//	}
//}

int main()
{
	//int a = 20;
	//int b = 10;
	////第一种 自动类型推导
	////mySwap(a, b);
	////第二种 显示指定类型
	//mySwap<int>(a, b);
	//cout << a << endl;
	//cout << b << endl;
	//char b[] = "dsaiunfdsaomk";
	//int len = sizeof(b) / sizeof(b[0]);
	//cout << sizeof(b);
	//myInsertSort<char>(b, len-1);
	//for (int i = 0; i < len; i++)
	//{
	//	cout << b[i] << endl;
	//}

	return 0;
}