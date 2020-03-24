#pragma once
#include<iostream>

//Структура узла дерева
struct AVLTree
{
	int key;			    //Ключевое поле
	int HeightTree;			//Высота дерева
	AVLTree *left;		        //Указатель на левый узел
	AVLTree *right;		    //Указатель на правый узел
};


void BinaryTree();

/*Подпрограмма, которая определяет
наибольший из двух элементов.*/
template<typename T>
T MaxElement(T first, T second)
{
	T max = first;
	/*Если второй элемент больше первого,
	то возвращаем его.*/
	if (first < second)
	{
		max = second;
	}
	return max;
}

/*Подпрограмма, которая выводит на
экран бинарное дерево(Перевернутое на 90 градусов.
level - высота дерева.*/
template<typename T>
void PrintTree(T* p, int level)
{
	if (p != NULL)
	{
		PrintTree(p->right, level + 1);             //Вывод правого поддерева.
		for (int i = 0; i < level; i++) cout << "   ";
		cout << p->key << endl;
		PrintTree(p->left, level + 1);             //Вывод левого поддерева.
	}

}

/*Вспомогательная подпрограмма,
для вывода бинарного дерева на экран.*/
template<typename T>
void Print(T*tree)
{
	if (tree != NULL)
	{
		PrintTree(tree, tree->HeightTree);
	}
	else
	{
		cout << "Дерево пусто.";
	}

}


/*Подпрограмма, которая возвращает
высоту поддерева.*/
int HeightTree(AVLTree* p);


/*Подпрограмма, которая высчитывает баланс высот
между правым и левым поддеревом*/
int BalanceHeight(AVLTree* p);


/*Подпрограмма, которая восстанавливает
корректное значение поля height(Высота) заданного узла*/
void FixHeight(AVLTree* p);


/*Малое правое вращение.*/
AVLTree* SmallTurnRight(AVLTree* p);

/*Малое левое вращение.*/
AVLTree* SmallTurnLeft(AVLTree* q);


/*Подпрограмма, которая выполняет
балансировку задаваемого узла.*/
AVLTree* Balance(AVLTree* p);

/*Подпрограмма, которая выполняет вставку
элемента в бинарное дерево.
k - ключ.*/
AVLTree* InsertNode(AVLTree* p, int k);

/*Подпрограмма, которая выполняет
поиск узла с минимальным ключом в поддереве.*/
AVLTree* FindMinNode(AVLTree* p);

/*Подпрограмма, которая выполняет удаление
узла с минимальным ключем из поддерева.*/
AVLTree* DeleteMinNode(AVLTree* p);

/*Подпрограмма, которая выполняет
удаление ключа из бинарного дерева.*/
AVLTree* DeleteNode(AVLTree* p, int k);