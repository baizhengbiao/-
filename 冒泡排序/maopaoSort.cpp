
#include "stdafx.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include <time.h>
#include <iostream>
using namespace std;

template <class T>

//  标准冒泡法排序 大数交换后移
//   外循环指定位置A， 内循环依次与A比较并交换
void maopaoSort(T array[], int count)
{
	int tc = 0;
	if (array == nullptr || count < 2)
	{
		return;
	}
	for (int i = 0; i < count; i++)
	{
		for (int j = i+1; j <count; j++)
		{
			if (array[i] > array[j])
			{
				swap(array[i], array[j]);
	
				tc ++;
			}
		}

	}
	cout << "执行交换次数: " << tc << endl;
}


// 冒泡法变种 从后向前，相邻两个逐次比较，小的向前移动一个步长
// 如果是倒序列  5 4 3 2 1 是最糟糕的情况
template <class T>
void maopaoSort1(T array[], int count)
{
	int tc = 0;
	if (array == nullptr || count < 2)
	{
		return;
	}
	for (int i = 0; i < count; i++)
	{
		for (int j = count -1; j > i; j--)
		{
			if (array[j] < array[j-1])
			{
				swap(array[j], array[j-1]);

				tc++;
			}
		}

	}
	cout << "执行交换次数: " << tc << endl;
}
// maopaoSort1改良版本 添加提前退出条件
template <class T>
void maopaoSort2(T array[], int count)
{
	int tc = 0;
	if (array == nullptr || count < 2)
	{
		return;
	}
	for (int i = 0; i < count; i++)
	{
		bool flag = false;
		for (int j = count - 1; j > i; j--)
		{
		
			if (array[j] < array[j-1])
			{
				swap(array[j], array[j-1]);
				flag = true;
				tc++;
			}
		}
		if (!flag)
			break;
	}
	cout << "执行交换次数: " << tc << endl;
}
int _tmain(int argc, _TCHAR* argv[])
{
	const int COUNT = 100;
	int number[COUNT];

	for (int i = 0; i < COUNT; i++)
	{
		number[i] = rand() % COUNT;
		 
	}
	clock_t beginT = clock();
	maopaoSort2(number, COUNT);
	clock_t endT = clock();
	cout << "耗时间" << endT - beginT<<"ms"<<endl;


	for (int i = 0; i < COUNT; i++)
	{
		cout << number[i]  << " ";
	}

	int i = 3;
	cin >> i;
	return 0;
}

