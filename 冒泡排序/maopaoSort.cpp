
#include "stdafx.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include <time.h>
#include <iostream>
using namespace std;

template <class T>

//  ��׼ð�ݷ����� ������������
//   ��ѭ��ָ��λ��A�� ��ѭ��������A�Ƚϲ�����
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
	cout << "ִ�н�������: " << tc << endl;
}


// ð�ݷ����� �Ӻ���ǰ������������αȽϣ�С����ǰ�ƶ�һ������
// ����ǵ�����  5 4 3 2 1 �����������
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
	cout << "ִ�н�������: " << tc << endl;
}
// maopaoSort1�����汾 �����ǰ�˳�����
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
	cout << "ִ�н�������: " << tc << endl;
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
	cout << "��ʱ��" << endT - beginT<<"ms"<<endl;


	for (int i = 0; i < COUNT; i++)
	{
		cout << number[i]  << " ";
	}

	int i = 3;
	cin >> i;
	return 0;
}

