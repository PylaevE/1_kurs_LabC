#include"BinaryTree.h"
#include"InputOutput.h"
#include<iostream>
#include <Windows.h>

using namespace std;
//�������� ����
AVLTree *binTreeCreate(int key)
{
	AVLTree * binTree = new AVLTree;	//��������� ������ ��� ����
	binTree->key = key;				//��� ������������� �������� ��������� ����
	binTree->left = NULL;				//����� ������� ����������
	binTree->right = NULL;				//������ ������� �����������
	binTree->HeightTree = 1;				//������ ������ 0
	return binTree;
}


/*������������, ������� ����������
������ ���������.*/
int HeightTree(AVLTree* p)
{
	return (p != NULL) ? p->HeightTree : 0;
}


/*������������, ������� ����������� ������ �����
����� ������ � ����� ����������*/
int BalanceHeight(AVLTree* p)
{
	int balHeight = 0;
	if (p != NULL)
	{
		balHeight = HeightTree(p->right) - HeightTree(p->left);
	}
	return balHeight;
}


/*������������, ������� ���������������
���������� �������� ���� height(������) ��������� ����*/
void FixHeight(AVLTree* p)
{
	int hleft = HeightTree(p->left);             //������ ������ ���������.
	int hright = HeightTree(p->right);           //������ ������� ���������.
	p->HeightTree = MaxElement(hleft, hright) + 1; //����������� ������.

}


/*����� ������ ��������.*/
AVLTree* SmallTurnRight(AVLTree* p)
{
	AVLTree* q = p->left;     //��������� ��������� �� ����� �������
	p->left = q->right;    //����� ������� ����� == ������� ������� ������ �������
	q->right = p;          //����� ������� ����� ���������� ������
	FixHeight(p);          //������������� ������.
	FixHeight(q);          //������������� ������.
	q->left = Balance(q->left);
	q->right = Balance(q->right);
	return q;
}


/*����� ����� ��������.*/
AVLTree* SmallTurnLeft(AVLTree* q)
{
	AVLTree* p = q->right;     //��������� ��������� �� ������ �������
	q->right = p->left;     //������ ������� ����� == ������ ������� ������� �������
	p->left = q;            //������ ������� ����� ���������� ������
	FixHeight(q);           //������������� ������.
	FixHeight(p);           //������������� ������.
	p->left = Balance(p->left);
	p->right = Balance(p->right);
	return p;
}


/*������������, ������� ���������
������������ ����������� ����.*/
AVLTree* Balance(AVLTree* p)
{
	FixHeight(p);            //������������� ������.
							 /*���� ��������� ���������������� ( �������� ����� ��������� 2 � (-2)),
							 �� ��������� ������������ ��� ������ ����� ��������.*/
	if (BalanceHeight(p) == 2)
	{
		/*������� ������ ��������. (���+���)*/
		if (BalanceHeight(p->right) < 0)
		{
			/*����� ������ ��������.*/
			p->right = SmallTurnRight(p->right);
		}
		/*����� ����� ��������.*/
		p = SmallTurnLeft(p);
	}
	else
	{
		if (BalanceHeight(p) == -2)
		{
			/*������� ����� ��������. (���+���)*/
			if (BalanceHeight(p->left) > 0)
			{
				/*����� ����� ��������.*/
				p->left = SmallTurnLeft(p->left);
			}
			/*����� ������ ��������.*/
			p = SmallTurnRight(p);
		}
	}

	return p; // ������������ �� �����
}


/*������������, ������� ��������� ������� �������� � �������� ������.
k - ����.*/
AVLTree* InsertNode(AVLTree* p, int k)
{
	/*���� ��������� ������, ��������� ����.*/
	if (p == NULL)
	{
		p = binTreeCreate(k);
	}
	/*����������� ����� ������� ����� ��� �������.*/
	else
	{/*���� ���� ������ ����� ����*/
		if (k < p->key)
		{
			/*���� ����� � ��������� ����� ����*/
			p->left = InsertNode(p->left, k);
		}
		/*���� ���� ������ ��� ����� ����� ����*/
		else
		{
			/*���� ������ � ��������� ����� ����*/
			p->right = InsertNode(p->right, k);
		}
		/*������������ ������.*/
		p = Balance(p);
	}
	return p;
}


/*������������, ������� ���������
����� ���� � ����������� ������ � ���������.*/
AVLTree* FindMinNode(AVLTree* p)
{
	if (p->left != NULL)
	{
		p = FindMinNode(p->left);
	}
	return p;
}


/*������������, ������� ��������� ��������
���� � ����������� ������ �� ���������.*/
AVLTree* DeleteMinNode(AVLTree* p)
{
	/*����� ���������� �� �������� ���� ����� p*/
	if (p->left != NULL)
	{
		p->left = DeleteMinNode(p->left);
		/*������������ ������.*/
		p = Balance(p);
	}
	else
	{
		p = p->right;
	}
	return p;
}


/*������������, ������� ���������
�������� ����� �� ��������� ������.*/
AVLTree* DeleteNode(AVLTree* p, int k)
{
	if (p != NULL)
	{

		/*����������� ����� ������� ��������*/
		/*���� ���� ������ ����� ����*/
		if (k < p->key)
		{
			/*���� ����� � ������� ������ ����*/
			p->left = DeleteNode(p->left, k);
		}
		else
		{/*���� ���� ������ ����� ����*/
			if (k > p->key)
			{
				/*���� ������ � ������� ������ ����*/
				p->right = DeleteNode(p->right, k);
			}
			/*���� ������ ���� ������, �� ������� ���.*/
			else
			{
				/*���������� ����� ������ � ������� ����������� ���� p*/
				AVLTree* leftCurrent = p->left;
				AVLTree* rightCurrent = p->right;
				delete p; //������� ���� p.

				if (rightCurrent == NULL)
				{
					p = leftCurrent;
				}
				/*�����, ���� � ������, �� ���������� ��������,
				��������� ���������� ������� � ������ �� �������
				(��������� ���������� ������� �� ����� ����������),
				����� ����� ������ ���� � ������� �������� ���������� �������.*/
				else
				{
					AVLTree* min = FindMinNode(rightCurrent);
					min->right = DeleteMinNode(rightCurrent);
					min->left = leftCurrent;
					p = min;
				}
				if (p != NULL)
				{
					FixHeight(p);                //������������� ������.
					p = Balance(p);               //������������ ������.
				}
			}


		}

	}
	return p;
}


/*������������, ������� ��������� ������
��� �������� �������.
(���������� � �������� �������� �� ������.)*/
void BinaryTree()
{
	int element;
	int i = 5;                               //���������� ��� ������ ���� ������.
	AVLTree* p = NULL;
	/*����� ������, ������ ����������� �� ������.
	(����������, �������� ��������)*/
	while (i != 0)
	{
		cout << "\n�������� ��������, ������� ����� ����������� .";
		cout << "\n1 - �������� ������� � ������.";
		cout << "\n2 - ������� ������� �� ������. \n0 - �����\n";
		cin >> i;
		switch (i)
		{
			/*���������� �������� � ������.*/
		case 1:
		{
			cout << " ������� �������, ������� ���������� ��������.\n";
			cin >> element;
			p = InsertNode(p, element);         //���������� ����.
			Print(p);                           //����� �� �����.
			//print(p, 100, 5, 2, 'k');

			break;
		}
		/*�������� �������� � ������ �����.*/
		case 2:
		{
			cout << " ������� �������, ������� ���������� �������.\n";
			cin >> element;
			p = DeleteNode(p, element);      //�������� ����.
			Print(p);                        //����� �� �����.
			break;
		}
		/*�����*/
		case 0:
			break;
		default:
		{
			cout << "��������� �������� �����������.";
			cout << "��������� ����.";
		}
		}
	}

}
