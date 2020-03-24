#include<iostream>
#include"ChoiceSort.h"


using namespace std;

/*Выбор типа данных для сортировки.*/
void DataTypeSort()
{
	int i = 5;                               //Переменная для выбора типа данных
	int n;                                   //Длина массива.
	cout << "Укажите длину массива.";
	cin >> n;
	/*Выбор типа данных для массива
	(целочисленный, символьный, вещественный*/
	while (i != 0)
	{
		cout << "\nВыберете тип данных:\n";
		cout << "1 - int\n2 - char\n3 - double\n4 - float\n0 - Выход\n";


		/*Очистка лишнего ввода.
		Исправляет проблему переполнения
		ввода при работе с char.*/
		cin.ignore(1000, '\n');

		cin >> i;
		switch (i)
		{
			/*тип данных int*/
		case 1:
		{
			SortActionsInt(n);               //Выбор сортировки для типа int.
			break;
		}
		/*тип данных char*/
		case 2:
		{
			SortActionsChar(n);              //Выбор сортировки для типа char.
			break;
		}
		/*тип данных double*/
		case 3:
		{
			SortActionsDouble(n);            //Выбор сортировки для типа double.
			break;
		}
		/*тип данных float*/
		case 4:
		{
			SortActionsFloat(n);             //Выбор сортировки для типа float.
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
