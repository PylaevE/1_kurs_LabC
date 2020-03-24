#include"InputOutput.h"
#include"Sort.h"
#include"SortActions.h"

/*Поразрядная сортировка.*/
void RadixSort(int*& array, int n)
{
	int* newArray = new int[n];		 	          //Вспомогательный массив.
	int digit = 1;						          //Переменная для разряда.
	int digitMax = MaxDischarge(array, n);        //Определяем максимальный разряд.

												  /*Выполняем цикл пока не достигнем старшего разряда*/
	for (int j = digitMax; j>0; j--)
	{
		int arrayDigit[10] = { 0 };			     //Вспомогательный массив для разрядов.
												 /*Подсчет чисел, которые будут
												 попадать в свой карман.*/
		for (int i = 0; i < n; i++)
		{
			arrayDigit[(array[i] / digit) % 10]++;
		}

		/*Добавление значений из преведущего кармана,
		что бы получить индексы после которых заканчивется тот или иной разряд.*/
		for (int i = 1; i < 10; i++)
		{
			arrayDigit[i] += arrayDigit[i - 1];
		}
		/* Запрлняем вспомогательный массив с помощью массива разрядов.*/
		for (int i = n - 1; i >= 0; i--)
		{
			newArray[--arrayDigit[(array[i] / digit) % 10]] = array[i];
		}
		/*Переписываем вспомогательный массив в основной.*/
		for (int i = 0; i < n; i++)
		{
			array[i] = newArray[i];
		}

		digit *= 10;					      	//Переходим к следующему разряду
	}
	delete[] newArray;

}
/*Подпрограмма, которая определяет количество разрядов в числе.*/
int Discharge(int N)
{
	int i = 0;
	/*Определение количества разрядов*/
	while (N > 0)
	{
		N = N / 10;
		i++;
	}
	return i;
}

