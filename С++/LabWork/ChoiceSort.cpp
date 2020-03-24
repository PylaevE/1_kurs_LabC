#include"SortActions.h"
#include"Sort.h"
#include<iostream>
using namespace std;

/*Подрограмма для выбора сортировки типа int.*/
void SortActionsInt(int n)
{
	int i = 10;                              //Переменная для выбора сортировки.
											 /*Выбор сортировки.*/
	while (i != 0)
	{
		cout << "\nВыберете тип сортировки:\n";
		cout << "\n1-Сортировка пузырьком\n2-Сортировка Шелла";
		cout << "\n3-Быстрая Сортировка\n4-Поразрядная сортировка";
		cout << "\n5-Пирамидальная сортировка\n0-Выход\n";
		cin >> i;
		switch (i)
		{
		case 1:
		{
			BubbleSortActions<int>(n);       //Ввод, вывод и сортировка.
			break;
		}
		case 2:
		{
			ShellSortActions<int>(n);        //Ввод, вывод и сортировка.
			break;
		}
		case 3:
		{
			QuickSortActions<int>(n);        //Ввод, вывод и сортировка.
			break;
		}
		case 4:
		{
			RadixSortActions<int>(n);        //Ввод, вывод и сортировка.
			break;
		}
		case 5:
		{
			HeapSortActions<int>(n);         //Ввод, вывод и сортировка.
			break;
		}
		/*выход*/
		case 0:
			break;
		default:
		{
			cout << "Выбранный тип отсутствует.\n";
		}
		}
	}
}


/*Подрограмма для выбора сортировки типа Char*/
void SortActionsChar(int n)
{
	int i = 10;                               //Переменная для выбора сортировки.
											  /*Выбор сортировки.*/
	while (i != 0)
	{
		cout << "\nВыберете тип сортировки:\n";
		cout << "\n1-Сортировка пузырьком\n2-Сортировка Шелла";
		cout << "\n3-Быстрая Сортировка";
		cout << "\n4-Пирамидальная сортировка\n0-Выход\n";
		/*Очистка лишнего ввода.
		Исправляет проблему переполнения
		ввода при работе с char.*/
		cin.ignore(1000, '\n');
		cin >> i;
		switch (i)
		{
		case 1:
		{
			BubbleSortActions<char>(n);      //Ввод, вывод и сортировка.
			break;
		}
		case 2:
		{
			ShellSortActions<char>(n);       //Ввод, вывод и сортировка.
			break;
		}
		case 3:
		{
			QuickSortActions<char>(n);       //Ввод, вывод и сортировка.
			break;
		}
		case 4:
		{
			HeapSortActions<char>(n);         //Ввод, вывод и сортировка.
			break;
		}
		/*выход*/
		case 0:
			break;
		default:
		{
			cout << "Выбранный тип отсутствует.\n";
		}
		}
	}
}


/*Подрограмма для выбора сортировки типа Double*/
void SortActionsDouble(int n)
{
	int i = 10;                               //Переменная для выбора сортировки.
											  /*Выбор сортировки.*/
	while (i != 0)
	{
		cout << "\nВыберете тип сортировки:\n";
		cout << "\n1-Сортировка пузырьком\n2-Сортировка Шелла";
		cout << "\n3-Быстрая Сортировка";
		cout << "\n4-Пирамидальная сортировка\n0-Выход\n";
		cin >> i;
		switch (i)
		{
		case 1:
		{
			BubbleSortActions<double>(n);     //Ввод, вывод и сортировка.
			break;
		}
		case 2:
		{
			ShellSortActions<double>(n);      //Ввод, вывод и сортировка.
			break;
		}
		case 3:
		{
			QuickSortActions<double>(n);      //Ввод, вывод и сортировка.
			break;
		}
		case 4:
		{
			HeapSortActions<double>(n);         //Ввод, вывод и сортировка.
			break;
		}
		/*выход*/
		case 0:
			break;
		default:
		{
			cout << "Выбранный тип отсутствует.\n";
		}
		}
	}
}


/*Подрограмма для выбора сортировки типа Float*/
void SortActionsFloat(int n)
{
	int i = 10;                              //Переменная для выбора сортировки.
											 /*Выбор сортировки.*/
	while (i != 0)
	{
		cout << "\nВыберете тип сортировки:\n";
		cout << "\n1-Сортировка пузырьком\n2-Сортировка Шелла";
		cout << "\n3-Быстрая Сортировка";
		cout << "\n4-Пирамидальная сортировка\n0-Выход\n";
		cin >> i;
		switch (i)
		{
		case 1:
		{
			BubbleSortActions<float>(n);      //Ввод, вывод и сортировка.
			break;
		}
		case 2:
		{
			ShellSortActions<float>(n);       //Ввод, вывод и сортировка.
			break;
		}
		case 3:
		{
			QuickSortActions<float>(n);       //Ввод, вывод и сортировка.
			break;
		}
		case 4:
		{
			HeapSortActions<float>(n);         //Ввод, вывод и сортировка.
			break;
		}
		/*выход*/
		case 0:
			break;
		default:
		{
			cout << "Выбранный тип отсутствует.\n";
		}
		}
	}
}