#include<iostream>
#include"List.h"
#include"InputOutput.h"
using namespace std;






/*Функция определения приоритета знака оператора*/
int Priority(char symbol)
{
	int import = 0;			//Степень приоритета данной операции
	switch (symbol)
	{
	case'(':
	case')':
	{
		import = 1;
		break;
	}
	case'+':
	case'-':
	{
		import = 2;
		break;
	}
	case'*':
	case'/':
	{
		import = 3;
		break;
	}
	case'^':
	{
		import = 4;
		break;
	}
	default:
	{
		import = 0;
		break;
	}
	}
	return import;
}

/*Подпрограмма, которая инфиксную форму
записи в префиксную.
(Прямая польская запись)*/
void PrePN(char * expr)
{
	int len = strlen(expr);			        	    //Длина выражения.
	List<char> * elemStack = NULL;		        	//Последний элемент стека.
	List<char> * firstElemQ = NULL;		            //Первый элемент очереди.
	List<char> * elemQ = NULL;			        	//Последний элемент очереди.
													//Посимвольно проверяем выражение с конца.
	for (int i = len - 1; i >= 0; i--)
	{
		/*Если элемент не соответствует ни одному из операторов.*/
		if ((expr[i] != '+') && (expr[i] != '-') && (expr[i] != '*') && (expr[i] != '/') && (expr[i] != '^') && (expr[i] != '(') && (expr[i] != ')'))
		{
			/*И если очередь пуста, то записываем элемент в неё*/
			if (firstElemQ == NULL)
			{
				firstElemQ = PushBack(firstElemQ, expr[i]);		     //Добавление первого элемента
				elemQ = firstElemQ;									 //Последний становится первым
			}
			//Если в очереди есть элементы, добавляем следующий 
			else
			{
				elemQ = PushBack(elemQ, expr[i]);					//Добавляем следующий элемент
			}
		}
		/*Если элемент соответствует оператору*/
		else
		{
			/*Если нет разделителя, то ставим его*/
			if (elemQ != NULL && elemQ->key != ' ')
			{
				elemQ = PushBack(elemQ, ' ');
			}
			/*И если стэк пуст, то добавляем в него оператор*/
			if (elemStack == NULL)
			{
				elemStack = PushBack(elemStack, expr[i]);			//Добавление оператора в стэк
			}
			/*Иначе, если приоритет оператора больше чем записанный,
			или он равен ")", то  добавляем его в стэк*/
			else if (Priority(expr[i]) >= Priority(elemStack->key) || (expr[i] == ')'))
			{
				elemStack = PushBack(elemStack, expr[i]);			//Добавление оператора в стэк
			}
			/*Если приоритет меньше, и оператор не равен ")",
			то записываем его в очередь*/
			else if (Priority(expr[i]) < Priority(elemStack->key) && expr[i] != ')')
			{
				/*Пока не нашли элемента в стэке с приоритетом равным приоритету текущего символа*/
				while (elemStack != NULL  && Priority(expr[i]) < Priority(elemStack->key))
				{
					elemQ = PushBack(elemQ, elemStack->key);		//Запись элемента в очередь
					elemStack = PopBack(elemStack);				//Удаляем элемент с верхушки стэка
				}
				/*Если элемент равен "(", то удаляем последний элемент стэка,
				который является скобкой*/
				if (expr[i] == '(')
				{
					elemStack = PopBack(elemStack);
				}
				/*Иначе записываем элемент*/
				else
				{
					elemStack = PushBack(elemStack, expr[i]);
				}
			}
		}
	}
	RefreshOut(elemStack, firstElemQ);		//Запись преобразованного выражения наоборот и ее вывод
	DeleteQueue(firstElemQ);				//Удаление очереди
	DeleteStack(elemStack);					//Удаление стэка

}


/*Функция для проверки выражения на правильность*/
bool Check(char * str)
{
	int len = strlen(str);			//Длина строки
	bool correct = true;			//Корректность выражения
	int NumLeftBkt = 0;				//Количество открывающих скобок
	int NumRightBkt = 0;			//Количество закрывающих скобок				
									//Проходим по строке
	for (int i = 0; i < len; i++)
	{
		/*Если подряд идут операторы, возвращаем false*/
		if (Priority(str[i]) > 1 && Priority(str[i + 1]) > 1)
		{
			correct = false;
			i = len;
		}
		/*Если подряд идут скобки, возвращаем false*/
		//else if (Priority(str[i]) == 1 && Priority(str[i + 1]) == 1)
		else if ((str[i] == '(' && str[i + 1] == ')') || (str[i] == ')' && str[i + 1] == '('))
		{
			correct = false;
			i = len;
		}
		/*Если после операнда идёт открывающаяся скобка,
		или после закрывающейся скобки идёт операнд,
		при этом не конец строки, то возвращаем false*/
		else if ((Priority(str[i]) == 0 && str[i + 1] == '(') || (str[i] == ')' && Priority(str[i + 1]) == 0 && i + 1 != len))
		{
			correct = false;
			i = len;
		}
		/*Если выражение начинается или кончается знаком оператора, то возвращаем false*/
		else if (Priority(str[0]) > 1 || Priority(str[i]) > 1 && i == len - 1)
		{
			correct = false;
			i = len;
		}
		/*Если нашли открывающуюся скобку, записываем ее в счётчик*/
		else if (str[i] == '(')
		{
			NumLeftBkt++;
		}
		/*Если нашли закрывающуюся, и количество открывающихся больше,
		то записываем в счётчик*/
		else if (str[i] == ')' && NumLeftBkt > NumRightBkt)
		{
			NumRightBkt++;
		}
	}
	/*Если количество скобок нечетное, возвращаем false*/
	if ((NumLeftBkt + NumRightBkt) % 2 != 0)
	{
		correct = false;
	}
	return correct;
}


/*Подпрограмма, выбора дальнейших действий.*/
void PNMenu()
{

	char* expr = new char[255];		//Выделение памяти для строки
	int choice = -1;			//Переменная выбора
								//Выбор действий
	while (choice != 0)
	{
		cout << "1 - Преобразовать выражение\n0 - Выход\n";
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			cout << "Введите выражение(не более 255 символов, без пробелов), унарный минус - <<!>>: ";

			/*Ввод выражения с использованием стандартного потока ввода.*/
			cin >> expr;
			/*Пока строка пуста, или в выражении содержатся ошибки,
			выводим соответствующее выражение*/
			while (strlen(expr) == 0 || Check(expr) == false)
			{
				cout << "Строка пуста или неправильна, введите выражение: ";
				cin >> expr;
			}
			cout << "\nПрямая польская запись: ";
			PrePN(expr);			//Вызов функции работы с ППЗ
		}
		}
		cout << endl;
	}
}