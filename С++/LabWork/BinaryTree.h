#pragma once
#include<iostream>

//��������� ���� ������
struct AVLTree
{
	int key;			    //�������� ����
	int HeightTree;			//������ ������
	AVLTree *left;		        //��������� �� ����� ����
	AVLTree *right;		    //��������� �� ������ ����
};


void BinaryTree();

/*������������, ������� ����������
���������� �� ���� ���������.*/
template<typename T>
T MaxElement(T first, T second)
{
	T max = first;
	/*���� ������ ������� ������ �������,
	�� ���������� ���.*/
	if (first < second)
	{
		max = second;
	}
	return max;
}

/*������������, ������� ������� ��
����� �������� ������(������������ �� 90 ��������.
level - ������ ������.*/
template<typename T>
void PrintTree(T* p, int level)
{
	if (p != NULL)
	{
		PrintTree(p->right, level + 1);             //����� ������� ���������.
		for (int i = 0; i < level; i++) cout << "   ";
		cout << p->key << endl;
		PrintTree(p->left, level + 1);             //����� ������ ���������.
	}

}

/*��������������� ������������,
��� ������ ��������� ������ �� �����.*/
template<typename T>
void Print(T*tree)
{
	if (tree != NULL)
	{
		PrintTree(tree, tree->HeightTree);
	}
	else
	{
		cout << "������ �����.";
	}

}


/*������������, ������� ����������
������ ���������.*/
int HeightTree(AVLTree* p);


/*������������, ������� ����������� ������ �����
����� ������ � ����� ����������*/
int BalanceHeight(AVLTree* p);


/*������������, ������� ���������������
���������� �������� ���� height(������) ��������� ����*/
void FixHeight(AVLTree* p);


/*����� ������ ��������.*/
AVLTree* SmallTurnRight(AVLTree* p);

/*����� ����� ��������.*/
AVLTree* SmallTurnLeft(AVLTree* q);


/*������������, ������� ���������
������������ ����������� ����.*/
AVLTree* Balance(AVLTree* p);

/*������������, ������� ��������� �������
�������� � �������� ������.
k - ����.*/
AVLTree* InsertNode(AVLTree* p, int k);

/*������������, ������� ���������
����� ���� � ����������� ������ � ���������.*/
AVLTree* FindMinNode(AVLTree* p);

/*������������, ������� ��������� ��������
���� � ����������� ������ �� ���������.*/
AVLTree* DeleteMinNode(AVLTree* p);

/*������������, ������� ���������
�������� ����� �� ��������� ������.*/
AVLTree* DeleteNode(AVLTree* p, int k);