#pragma once
#include<iostream>
using namespace std;

/*Вывод элементов массива на экран.*/
template<typename T>
void Output(T array, int r)
{
	for (int i = 0; i < r; i++)                       //Вывод элементов  массива.
	{
		cout << array[i] ;
	}
	cout << endl;
}

/*Ввод элементов массива на экран.*/
template<typename T>
void Input(T array, int length)
{
	cout << "Введите значения элементов массива:\n";
	for (int i = 0; i < length; i++)                  //Ввод элементов  массива.
	{
		cin >> array[i];
	}
}

/*Ввод элементов массива на экран.
Присваивание нуль терминатора в конце строки.*/
template<typename T>
void InputChar(T array, int length)
{
	cout << "Введите значения элементов массива:\n";
	for (int i = 0; i < length; i++)                  //Ввод элементов  массива.
	{
		cin >> array[i];
	}
	array[length] = '\0';
}

/*Вывод преобразованного выражения на экран.*/
template<typename T>
void RefreshOut(T * elemStack, T * firstElemQ)
{
	int i = 0;
	char * str = new char[255];		//Строка, в которую записываем исходные стэк и кучу
									/*Пока очередь не пуста, посимвольно заполняем строку из очереди*/
	while (firstElemQ != NULL)
	{
		str[i] = firstElemQ->key;
		firstElemQ = firstElemQ->next;
		i++;
	}
	/*Пока стэк не пуст, посимвольно заполняем строку из стэка*/
	while (elemStack != NULL)
	{
		str[i] = elemStack->key;
		elemStack = elemStack->prev;
		i++;
	}
	/*Вывод преобразованного выражения*/
	for (i--; i >= 0; i--)
	{
		cout << str[i];
	}
	delete str;
}

