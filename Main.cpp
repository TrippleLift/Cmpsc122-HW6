//Programmer:  Joseph Chang
//Section:     #004
//Activity:    #6
//Date:        Apr 21, 2018
//File name:   Main.cpp

#include <stack>
#include <queue>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
using namespace std;

template <class T>
void sort(T *arr, int);
template <class T>
void printArr(T arr[], int);

int main()
{
	srand(time(0));
	
	//double
	double arr[10];
	for (int i = 0; i < 10; i++)
	{
		arr[i] = rand() / (rand() % 100 + 1.0);
	}
	printArr(arr, 10); //before sort
	sort(arr, 10);
	printArr(arr, 10); //after sort

	//char
	char arrC[10];
	for (int i = 0; i < 10; i++)
	{
		arrC[i] = char(rand() % 26 + 97);
	}
	printArr(arrC, 10); //before sort
	sort(arrC, 10);
	printArr(arrC, 10); //after sort

	//string
	string arrSt[10];
	for (int i = 0; i < 10; i++)
	{
		int length = rand() % 10 + 1;
		for (int j = 0; j < length; j++)
		{
			arrSt[i] += char(rand() % 26 + 97);
		}
	}
	printArr(arrSt, 10); //before sort
	sort(arrSt, 10);
	printArr(arrSt, 10); //after sort
	

	system("pause");
	return 0;
}

template <class T>
void sort(T *arr, int size)
{
	queue<T> que;
	for (int i = 0; i < size; i++)
		que.push(arr[i]);

	stack<T> sta;
	while (!que.empty())
	{
		if (sta.empty() || sta.top() >= que.front())
		{
			sta.push(que.front());
			que.pop();
		}
		else
		{
			que.push(sta.top());
			sta.pop();
		}
	}

	for (int i = 0; i < size; i++)
	{
		arr[i] = sta.top();
		sta.pop();
	}
}

template <class T>
void printArr(T arr[], int size)
{
	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}