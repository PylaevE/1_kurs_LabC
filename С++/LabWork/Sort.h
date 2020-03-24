#pragma once


/*Попрограмма, которая обменивает значения  аргументов*/
template<typename T>
void Swap(T *array, int i, int j)
{
	T element = array[j];     // Временная переменная для хранения элемента массива.
	array[j] = array[i];      // Перестановка элементов массива.
	array[i] = element;
}

/*Подрограмма сортировки массива Пузырьком(по возрастанию)*/
template<typename T>
void BubbleSort(T* array, int n)
{
	for (int i = 0; i < n - 1; i++)             //Внешний цикл прохода.
	{
		for (int j = n - 1; j > i; j--)        //Внутренний цикл прохода.
		{
			if (array[j] < array[j - 1])       //Сравнивание двух соседних элементов.
			{
				Swap(array, j, j - 1);         //Обменивает значения аргументов
			}
		}
	}
}

/*сортировка методом Шелла*/
template<typename T>
void ShellSort(T*array, int n)
{
	int step;
	for (step = n / 2; step > 0; step /= 2)                   //Пока шаг больше 0, выполняем цикл с уменьшением шага.
															  //В выбранном шаге.
		for (int i = 0; i < (n / step); i++)			      //Создание набора.
		{
			for (int j = i; j < n - step; j += step)          //Сортируем данные внутри набора.
			{
				if (array[j] > array[j + step])               //Сравниваем элементы.
				{
					Swap(array, j + step, j);                 //Обменивает значения аргументов с шагом.
					if (j > 0)                                //Проверка выхода за пределы массива.
					{
						j -= step * 2;
					}
					else
					{
						j -= step;
					}

				}

			}
		}
}

/*Быстрая сортировка*/
template<typename T>
void QuickSort(T*array, int left, int right)
{
	int indMiddle = (left + right) / 2;            //Нахождение индекса среднего элемента массива.
	T middle = array[indMiddle];                   //Опорный элемент.
	int i = left;                                  //Индекс левой границы.
	int j = right;                                 //Индекс правой границы.           
	do {
		while ((array[i] < middle) && (i < right)) //Увеличиваем i,
			i++;                                   // пока i - й элемент меньше опорного.
		while ((array[j] > middle) && (j > left))  //Уменьшаем j, 
			j--;                                   //пока j-й элемент больше опорного.
		if (i <= j)                                //Если i всё ещё меньше j, то ,  и декрементируем j
		{
			Swap(array, i, j);                     //меняем i-й и j-й элементы местами.
			i++;                                   //Увеличиваем i.
			j--;                                   //Уменьшаем j.
		}
	} while (i <= j);                              //Если i вдруг становится больше j, 
												   //то прерываем цикл.
	if (left < j)                                  //Рекурсивно вызываем сортировку 
	{                                              //для левой и правой части массива/
		QuickSort(array, left, j);
	}
	if (right > i)
	{
		QuickSort(array, i, right);
	}
}
/*Поразрядная сортировка.*/
void RadixSort(int*& array, int n);

/*Подпрограмма, которая ищет
максимальный разряд в массиве.*/
template<typename T>
int MaxDischarge(T*array, int n)
{
	int max, constmax = 0;                        //Переменные для разрядов.
												  /*Просматриваем массив, ищем максимальный разряд*/
	for (int i = 0; i < n; i++)
	{
		max = Discharge(array[i]);                //Ищем сколько разрядов в числе. 
		if (max > constmax)                       //Проверяем максимальный разряд.
		{
			constmax = max;
		}
	}
	return constmax;
}

/*Просеивание вниз.
Подпрограмма, которая сравнивает потомков с
предком и ставит больший элемент на место предка.
end-Последний элемент массиваю
parent-Индекс "предка".*/
template<typename T>
void SiftDown(T *array, int end, int parent)
{
	int maxChild = 0;     //Индекс максимального потомка.
	bool theExchangeWas = true;
	/*Проверяем существование индекса "предка".*/
	while ((parent * 2 + 1 <= end ) && theExchangeWas)
	{
		/*Поиск максиального потомка*/
		maxChild = MaxChild(end, array, parent);
		/*Если предок меньше максимального потомка
		меняем их местами.*/
		if (array[parent] < array[maxChild])
		{
			Swap(array, parent, maxChild);   //Меняем местами элементы.
			parent = maxChild;
		}
		else
			theExchangeWas = false;                      //Выход из цикла.
	}
}
/*Подпрограмма, которая ищет максимального "потомка".
end-Последний элемент массива.*/
template<typename T>
int MaxChild(int end, T*array, int parent)
{
	int left = parent * 2 + 1;           //Индекс левого потомка.
	int right = parent * 2 + 2;          //Индекс правого потомка.
	int maxChild = left;                    //Индекс максимального потомка.
	/*Если правый потомок существует.*/
	if (left != end)
	{
		/*Находим наибольший из потомков.*/
		if (array[left] < array[right])
		{
			maxChild = right;
		}
	}
	return maxChild;
}

/*Пирамидальная сортировка.
n-Длина массива.*/
template<typename T>
void HeapSort(T* array, int n)
{
	int end = n - 1;                    //Индекс последнего элемента массива.
	/*Сортируем дерево, так чтобы все
	потомки были меньше своих предков. */
	for (int i = n / 2 - 1; i >= 0; i--)
	{
		SiftDown(array, end, i);   //Сравниваем элементы.
	}
	/*Переносим максимальный элемент в конец массива.
	Сортируем дерево, так чтобы все
	потомки были меньше своих предвков.*/
	for (int i = n - 1; i >= 1; i--)
	{
		/*Переносим из максимальный элемент из вершины дерева в конец.*/
		Swap(array, i, 0);
		SiftDown(array, i - 1, 0);   //Сравниваем элементы.
	}
}