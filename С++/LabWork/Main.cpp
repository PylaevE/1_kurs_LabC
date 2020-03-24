#include<iostream>
#include"InputOutput.h"
#include"locale.h"
#include"ChoiseSerach.h"
#include"ChoiceOfDataType.h"
#include"SteckQueue.h"
#include"BinaryTree.h"
#include"PolishNotation.h"
using namespace std;

/*Программа, которая реализует алгоритмы
сортировки и поиска для различных типов данных*/
int main()
{
	setlocale(LC_ALL, "Rus");
	int i = 6;                               //Переменная для выбора типа данных
	
	/*Выбор действия , которое будет совершаться над массивом.
	(Поиск, Сортировка)*/
	while (i != 0)
	{
		cout << "\nВыберете действие, которое будет совершаться над массивом.";
		cout << "\n1 - Сортировка\n2 - Поиск\n3 - Стек, Очередь";
		cout << "\n4 - Бинарное дерево.\n5 - Польская запись.\n0 - Выход\n";
		cin >> i;
		switch (i)

		{
			/*Сортировка.*/
		case 1:
		{
			DataTypeSort();
			break;
		}
		/*Поиск*/
		case 2:
		{
			ChoiseSearch();
			break;
		}
		/*Стек, Очередь*/
		case 3:
		{
			SteckQueue();
			break;
		}
		/*Бинарное дерево.*/
		case 4:
		{
			BinaryTree();
			break;
		}
		/*Польская запись.*/
		case 5:
		{
			PNMenu();
			break;
		}
		/*выход*/
		case 0:
			break;
		default:
		{
			cout << "Выбранное действие отсутствует.";
			cout << "Повторите ввод.";
		}
		}
	}

return 0;
}