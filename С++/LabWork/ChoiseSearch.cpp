#include"InputOutput.h"
#include"List.h"
#include"Search.h"


/*Подпрограмма, которая выполняет работу над массивом:
ввод , вывод и поиск КМП .
n - Длина строки.
s - длина слова.*/
void KMPsearchActions(int n, int s)
{
	List<int>* c;
	char* text = new char[n];                     //Выделение памяти под массив. 
	char* word = new char[s];
	cout << "Введите текст.";
	InputChar(text, n);
	/*Очистка лишнего ввода.
	Исправляет проблему переполнения
	ввода при работе с char.*/
	cin.ignore(1000, '\n');
	cout << "Введите слово, которое нужно найти.";

	InputChar(word, s);
	cin.ignore(1000, '\n');
	c = KMP(text, word);
	cout << "Индексы начала вхождений шаблона в строку.\n";
	OutputList(c);
}

/*Подпрограмма, которая выполняет работу над массивом:
ввод , вывод и поиск с помощью алгоритма Бойера-Мура.
n - Длина строки.
s - длина слова.*/
void BMsearchActions(int n, int s)
{
	List<int>* c;
	char* text = new char[n];                     //Выделение памяти под массив. 
	char* word = new char[s];
	cout << "Введите текст.";
	InputChar(text, n);
	/*Очистка лишнего ввода.
	Исправляет проблему переполнения
	ввода при работе с char.*/
	cin.ignore(1000, '\n');
	cout << "Введите слово, которое нужно найти.";
	InputChar(word, s);
	cin.ignore(1000, '\n');
	c = BM(text, word);
	c = FindHead(c);
	cout << "Индексы начала вхождений шаблона в строку.\n";
	OutputList(c);
}

/*Подпрограмма, которая выполняет работу над массивом:
ввод , вывод и поиск с помощью алгоритма Рабина — Карпа.
n - Длина строки.
s - длина слова.*/
void RKsearchActions(int n, int s)
{
	List<int>* c;
	char* text = new char[n];                     //Выделение памяти под массив. 
	char* word = new char[s];
	cout << "Введите текст.";
	InputChar(text, n);
	/*Очистка лишнего ввода.
	Исправляет проблему переполнения
	ввода при работе с char.*/
	cin.ignore(1000, '\n');
	cout << "Введите слово, которое нужно найти.";
	InputChar(word, s);
	cin.ignore(1000, '\n');
	c = RK(text, word);
	c = FindHead(c);
	cout << "Индексы начала вхождений шаблона в строку.\n";
	OutputList(c);
}

/*Подпрограмма выбора поиска.*/
void ChoiseSearch()
{
	int n;                                   //Длина массива.
	cout << "Укажите длину массива.";
	cin >> n;
	int s;                                  //Длина слова.
	cout << "Введите длину слова.";
	cin >> s;
	int i = 10;                              //Переменная для выбора поиска.
											 /*Выбор поиска.*/
	while (i != 0)
	{
		cout << "\nВыберете вариант поиска:\n";
		cout << "\n1 - КМП (Алгоритм Кнута — Морриса — Пратта)\n";
		cout << "\n2 - BM (Алгоритма Бойера-Мура.)\n";
		cout << "\n3 - RK (Алгоритма Рабина — Карпа.)\n";
		cout << "0 - Выход\n";
		cin >> i;
		switch (i)
		{
		case 1:
		{
			KMPsearchActions(n, s);       //Ввод, вывод и поиск.
			break;
		}
		case 2:
		{
			BMsearchActions(n, s);         //Ввод, вывод и поиск.
			break;
		}
		case 3:
		{
			RKsearchActions(n, s);         //Ввод, вывод и поиск.
			break;
		}
		/*выход*/
		case 0:
		{
			break;
		}
		default:
		{
			cout << "Выбранный тип отсутствует.\n";
		}
		}
	}
}
