#pragma once
#include<iostream>
using namespace std;
/*Структура.*/
struct stop
{
	char key;                                         //Информационная часть структуры.
	int otdal;                                        //Информационная часть структуры.											   
};

/*Структура.*/
template<typename T>
struct List
{
	T key;                                         //Информационная часть структуры.
	List* next;                                    //Адрес следующего элемента списка.
	List* prev;                                    //Адрес предыдущего элемента списка.
};

/*Добавление элемента в список.В конец.*/
template<typename T>
List<T> * PushBack(List<T> *lst, T t)
{
	List<T> *p;
	List<T> *Current = new List<T>;                   // Выделение памяти.
    /*Если список не пустой добавляем элемент справа.*/
	if (lst != NULL)
	{
		p = lst->next;                               // Сохранение указателя на следующий элемент списка.
		lst->next = Current;                         // Предыдущий элемент списка указывает на создаваемый.
		Current->key = t;                            // Сохранение поля данных добавляемого элемента списка.
		Current->next = p;                           // Созданный элемент списка указывает на следующий элемент списка.
		Current->prev = lst;                         // Созданный элемент списка указывает на предыдущий элемент списка.
		if (p != NULL)                               // Проверка указателя
			p->prev = Current;
	}
	else //Инициализируем список.
	{
		Current->key = t;
		Current->next = NULL;                        // Указатель на следующий узел.
		Current->prev = NULL;                        // Указатель на предыдущий узел.
	}
	return(Current);
}

/*Добавление элемента в список. В начало*/
template<typename T>
List<T> * PushFront(List<T> *lst, T t)
{
	List<T> *p;
	List<T> *Current = new List<T>;                         // Выделение памяти.
	List<T>* first;
	/*Если список не пустой добавляем элемент слева.*/
	if (lst != NULL)
	{
		first = lst;
		p = first->prev;                           // Сохранение указателя на следующий элемент списка.
		first->prev = Current;                     // Предыдущий элемент списка указывает на создаваемый.
		Current->key = t;                          // Сохранение поля данных добавляемого элемента списка.
		Current->next = first;                     // Созданный элемент списка указывает на следующий элемент списка.
		Current->prev = p;                         // Созданный элемент списка указывает на предыдущий элемент списка.
		if (p != NULL)                             // Проверка указателя
			p->next = Current;
	}
	else //Инициализируем список.
	{
		Current->key = t;
		Current->next = NULL;                      // Указатель на следующий узел.
		Current->prev = NULL;                      // Указатель на предыдущий узел.
	}
	return(Current);
}


/*Подпрограмма, которая возвращает
указатель на последний элемент списка.*/
template<typename T>
List<T>* Findend(List<T>* list)
{
	List<T> *K = new List<T>;
	K = NULL;
	while (list != NULL)
	{
		K = list;					        //возвращаем указатель на следующий элемент.
		list = list->next;
	}
	return K;
}

/*Подпрограмма, которая возвращает
указатель на первый элемент списка.*/
template<typename T>
List<T>* FindHead(List<T>* list)
{
	List<T> *K = new List<T>;
	K = NULL;
	while (list != NULL)
	{
		K = list;					//возвращаем указатель на первый элемент.
		list = list->prev;
	}
	return K;
}

/*Вывод списка на экран*/
template<typename T>
void OutputList(List<T>*first)
{
	List<T>* p = first;
	if (p != NULL)                               //Проверка указателя.
	{
		while (p != NULL)                        //Вывод.
		{
			cout << p->key << " ";
			p = p->next;
		}
	}
	else
	{
		cout << "Список пуст." << endl;
	}
}

/*Подпрограмма, которая находит в списке
длины префикосов(суффиксов) с нужным индексом.
ind - индекс префикса.*/
template<typename T>
T Findind(List<T>* c, int ind)
{
	List<T> *K = new List<T>;
	K = FindHead(c);
	int i = 1;
	while (i < ind)
	{
		K = K->next;
		i++;
	}
	return K->key;
}

/*Подпрограмма, которая находит в списке
длины префикосов(суффиксов) с нужным индексом.
ind - индекс префикса.*/
template<typename T>
int FindMaxcount(List<T>* c, int ind)
{
	List<T> *K = c;
	int max = 0;             //Максимальная длина суффикса.
	int i = 0;
	/*Поиск максмальной длины.*/
	while (i < ind)
	{
		if (K->key>max)
		{
			max = K->key;
		}
		K = K->next;
		i++;
	}
	return max;
}


/*Подпрограмма, которая выполняет
удаление первого элемента списка. */
template<typename T>
List<T>* PopFront(List<T> *h)
{
	List<T> *p = h;
	if (h != NULL)
	{
		p = h->next;						//элемент, предшествующий h
		if (h->next != NULL)				//при наличии элемента после удаляемого
			p->prev = h->prev;				//переставляем указатель с удаляемого на следующий
		free(h);                            //освобождаем память удаляемого элемента
	}
	return(p);
}

/*Подпрограмма, которая выполняет
удаление последнего элемента списка. */
template<typename T>
List<T>* PopBack(List<T> *h)
{
	List<T> *p = h;
	if (h != NULL)
	{
		p = h->prev;						//элемент, предшествующий h
		if (h->prev != NULL)				//при наличии элемента после удаляемого
			p->next = h->next;				//переставляем указатель с удаляемого на следующий
		free(h);							//освобождаем память удаляемого элемента
	}
	return(p);
}


//Функция удаления очереди
template<typename T>
void DeleteQueue(List<T> * first)
{
	List<T> * next = NULL;
	//Пока первый элемент не будет равен нулю, удаляем элементы очереди
	while (first != NULL)
	{
		next = first->next;					//Настроили указатель на первый элемент
		delete first;							//Удалили его
		first = next;							//Следующий элемент стал первым
	}
}


//Функция удаления стэка
template<typename T>
void DeleteStack(List<T>* elemStack)
{
	List<T>* prev = NULL;
	//Пока элементы есть, удаляем их
	while (elemStack != NULL)
	{
		prev = elemStack->prev;				//Настраиваем указатель на предыдущий элемент
		delete elemStack;						//Удаляем его
		elemStack = prev;						//Переходим к следующему элементу
	}
}
