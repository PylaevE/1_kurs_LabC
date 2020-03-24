#include"BinaryTree.h"
#include"InputOutput.h"
#include<iostream>
#include <Windows.h>

using namespace std;
//Создание узла
AVLTree *binTreeCreate(int key)
{
	AVLTree * binTree = new AVLTree;	//Выделение памяти для узла
	binTree->key = key;				//Ему присваивается значение ключевого поля
	binTree->left = NULL;				//Левый потомок отутствует
	binTree->right = NULL;				//Правый потомок отсутствует
	binTree->HeightTree = 1;				//Высота дерева 0
	return binTree;
}


/*Подпрограмма, которая возвращает
высоту поддерева.*/
int HeightTree(AVLTree* p)
{
	return (p != NULL) ? p->HeightTree : 0;
}


/*Подпрограмма, которая высчитывает баланс высот
между правым и левым поддеревом*/
int BalanceHeight(AVLTree* p)
{
	int balHeight = 0;
	if (p != NULL)
	{
		balHeight = HeightTree(p->right) - HeightTree(p->left);
	}
	return balHeight;
}


/*Подпрограмма, которая восстанавливает
корректное значение поля height(Высота) заданного узла*/
void FixHeight(AVLTree* p)
{
	int hleft = HeightTree(p->left);             //Высота левого поддерева.
	int hright = HeightTree(p->right);           //Высота правого поддерева.
	p->HeightTree = MaxElement(hleft, hright) + 1; //Высчитываем высоту.

}


/*Малое правое вращение.*/
AVLTree* SmallTurnRight(AVLTree* p)
{
	AVLTree* q = p->left;     //Сохраняем указатель на левый потомок
	p->left = q->right;    //Левый потомок корня == правому потомку левого потомка
	q->right = p;          //Левый потомок корня становится корнем
	FixHeight(p);          //Пересчитываем высоту.
	FixHeight(q);          //Пересчитываем высоту.
	q->left = Balance(q->left);
	q->right = Balance(q->right);
	return q;
}


/*Малое левое вращение.*/
AVLTree* SmallTurnLeft(AVLTree* q)
{
	AVLTree* p = q->right;     //Сохраняем указатель на правый потомок
	q->right = p->left;     //Правый потомок корня == левому потомку правого потомка
	p->left = q;            //Правый потомок корня становится корнем
	FixHeight(q);           //Пересчитываем высоту.
	FixHeight(p);           //Пересчитываем высоту.
	p->left = Balance(p->left);
	p->right = Balance(p->right);
	return p;
}


/*Подпрограмма, которая выполняет
балансировку задаваемого узла.*/
AVLTree* Balance(AVLTree* p)
{
	FixHeight(p);            //Пересчитываем высоту.
							 /*Если поддерево разбалансировано ( разность высот превышает 2 и (-2)),
							 то совершаем балансировку при помощи малых вращений.*/
	if (BalanceHeight(p) == 2)
	{
		/*Большое правое вращение. (МПВ+МЛВ)*/
		if (BalanceHeight(p->right) < 0)
		{
			/*Малое правое вращение.*/
			p->right = SmallTurnRight(p->right);
		}
		/*Малое левое вращение.*/
		p = SmallTurnLeft(p);
	}
	else
	{
		if (BalanceHeight(p) == -2)
		{
			/*Большое левое вращение. (МЛВ+МПВ)*/
			if (BalanceHeight(p->left) > 0)
			{
				/*Малое левое вращение.*/
				p->left = SmallTurnLeft(p->left);
			}
			/*Малое правое вращение.*/
			p = SmallTurnRight(p);
		}
	}

	return p; // балансировка не нужна
}


/*Подпрограмма, которая выполняет вставку элемента в бинарное дерево.
k - ключ.*/
AVLTree* InsertNode(AVLTree* p, int k)
{
	/*если поддерево пустое, добавляем узел.*/
	if (p == NULL)
	{
		p = binTreeCreate(k);
	}
	/*Рекурсивный поиск нужного места для вставки.*/
	else
	{/*Если ключ меньше ключа узла*/
		if (k < p->key)
		{
			/*Идем влево и добавляем новый узел*/
			p->left = InsertNode(p->left, k);
		}
		/*Если ключ больше или равен ключу узла*/
		else
		{
			/*Идем вправо и добавляем новый узел*/
			p->right = InsertNode(p->right, k);
		}
		/*Балансировка дерева.*/
		p = Balance(p);
	}
	return p;
}


/*Подпрограмма, которая выполняет
поиск узла с минимальным ключом в поддереве.*/
AVLTree* FindMinNode(AVLTree* p)
{
	if (p->left != NULL)
	{
		p = FindMinNode(p->left);
	}
	return p;
}


/*Подпрограмма, которая выполняет удаление
узла с минимальным ключем из поддерева.*/
AVLTree* DeleteMinNode(AVLTree* p)
{
	/*Поиск следующего по величине узла после p*/
	if (p->left != NULL)
	{
		p->left = DeleteMinNode(p->left);
		/*Балансировка дерева.*/
		p = Balance(p);
	}
	else
	{
		p = p->right;
	}
	return p;
}


/*Подпрограмма, которая выполняет
удаление ключа из бинарного дерева.*/
AVLTree* DeleteNode(AVLTree* p, int k)
{
	if (p != NULL)
	{

		/*Рекурсивный поиск нужного элемента*/
		/*Если ключ меньше ключа узла*/
		if (k < p->key)
		{
			/*Идем влево и удаляем нужный узел*/
			p->left = DeleteNode(p->left, k);
		}
		else
		{/*Если ключ больше ключа узла*/
			if (k > p->key)
			{
				/*Идем вправо и удаляем нужный узел*/
				p->right = DeleteNode(p->right, k);
			}
			/*Если нужный узел найден, то удаляем его.*/
			else
			{
				/*запоминаем корни левого и правого поддеревьев узла p*/
				AVLTree* leftCurrent = p->left;
				AVLTree* rightCurrent = p->right;
				delete p; //Удаляем узел p.

				if (rightCurrent == NULL)
				{
					p = leftCurrent;
				}
				/*Иначе, ищем в правом, от удаляемого элемента,
				поддереве наименьший элемент и меняем их местами
				(переносим наименьший элемент на место удаляемого),
				после этого удалем узел в котором хранился наименьший элемент.*/
				else
				{
					AVLTree* min = FindMinNode(rightCurrent);
					min->right = DeleteMinNode(rightCurrent);
					min->left = leftCurrent;
					p = min;
				}
				if (p != NULL)
				{
					FixHeight(p);                //Пересчитываем высоту.
					p = Balance(p);               //Балансировка дерева.
				}
			}


		}

	}
	return p;
}


/*Подпрограмма, которая выполняет работу
над бинарным деревом.
(Добавление и удаление элемента из дерева.)*/
void BinaryTree()
{
	int element;
	int i = 5;                               //Переменная для выбора типа данных.
	AVLTree* p = NULL;
	/*Выбор работы, котора выполняется со стеком.
	(Добавление, Удаление элемента)*/
	while (i != 0)
	{
		cout << "\nВыберете действия, которые будут выполняться .";
		cout << "\n1 - Добавить элемент в дерево.";
		cout << "\n2 - Удалить элемент из дерева. \n0 - Выход\n";
		cin >> i;
		switch (i)
		{
			/*Дабавление элемента в дерево.*/
		case 1:
		{
			cout << " Укажите элемент, который необходимо добавить.\n";
			cin >> element;
			p = InsertNode(p, element);         //Добавление узла.
			Print(p);                           //Вывод на экран.
			//print(p, 100, 5, 2, 'k');

			break;
		}
		/*Удаление элемента с головы стека.*/
		case 2:
		{
			cout << " Укажите элемент, который необходимо удалить.\n";
			cin >> element;
			p = DeleteNode(p, element);      //Удаление узла.
			Print(p);                        //Вывод на экран.
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

}
