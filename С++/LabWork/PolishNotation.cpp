#include<iostream>
#include"List.h"
#include"InputOutput.h"
using namespace std;






/*������� ����������� ���������� ����� ���������*/
int Priority(char symbol)
{
	int import = 0;			//������� ���������� ������ ��������
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

/*������������, ������� ��������� �����
������ � ����������.
(������ �������� ������)*/
void PrePN(char * expr)
{
	int len = strlen(expr);			        	    //����� ���������.
	List<char> * elemStack = NULL;		        	//��������� ������� �����.
	List<char> * firstElemQ = NULL;		            //������ ������� �������.
	List<char> * elemQ = NULL;			        	//��������� ������� �������.
													//����������� ��������� ��������� � �����.
	for (int i = len - 1; i >= 0; i--)
	{
		/*���� ������� �� ������������� �� ������ �� ����������.*/
		if ((expr[i] != '+') && (expr[i] != '-') && (expr[i] != '*') && (expr[i] != '/') && (expr[i] != '^') && (expr[i] != '(') && (expr[i] != ')'))
		{
			/*� ���� ������� �����, �� ���������� ������� � ��*/
			if (firstElemQ == NULL)
			{
				firstElemQ = PushBack(firstElemQ, expr[i]);		     //���������� ������� ��������
				elemQ = firstElemQ;									 //��������� ���������� ������
			}
			//���� � ������� ���� ��������, ��������� ��������� 
			else
			{
				elemQ = PushBack(elemQ, expr[i]);					//��������� ��������� �������
			}
		}
		/*���� ������� ������������� ���������*/
		else
		{
			/*���� ��� �����������, �� ������ ���*/
			if (elemQ != NULL && elemQ->key != ' ')
			{
				elemQ = PushBack(elemQ, ' ');
			}
			/*� ���� ���� ����, �� ��������� � ���� ��������*/
			if (elemStack == NULL)
			{
				elemStack = PushBack(elemStack, expr[i]);			//���������� ��������� � ����
			}
			/*�����, ���� ��������� ��������� ������ ��� ����������,
			��� �� ����� ")", ��  ��������� ��� � ����*/
			else if (Priority(expr[i]) >= Priority(elemStack->key) || (expr[i] == ')'))
			{
				elemStack = PushBack(elemStack, expr[i]);			//���������� ��������� � ����
			}
			/*���� ��������� ������, � �������� �� ����� ")",
			�� ���������� ��� � �������*/
			else if (Priority(expr[i]) < Priority(elemStack->key) && expr[i] != ')')
			{
				/*���� �� ����� �������� � ����� � ����������� ������ ���������� �������� �������*/
				while (elemStack != NULL  && Priority(expr[i]) < Priority(elemStack->key))
				{
					elemQ = PushBack(elemQ, elemStack->key);		//������ �������� � �������
					elemStack = PopBack(elemStack);				//������� ������� � �������� �����
				}
				/*���� ������� ����� "(", �� ������� ��������� ������� �����,
				������� �������� �������*/
				if (expr[i] == '(')
				{
					elemStack = PopBack(elemStack);
				}
				/*����� ���������� �������*/
				else
				{
					elemStack = PushBack(elemStack, expr[i]);
				}
			}
		}
	}
	RefreshOut(elemStack, firstElemQ);		//������ ���������������� ��������� �������� � �� �����
	DeleteQueue(firstElemQ);				//�������� �������
	DeleteStack(elemStack);					//�������� �����

}


/*������� ��� �������� ��������� �� ������������*/
bool Check(char * str)
{
	int len = strlen(str);			//����� ������
	bool correct = true;			//������������ ���������
	int NumLeftBkt = 0;				//���������� ����������� ������
	int NumRightBkt = 0;			//���������� ����������� ������				
									//�������� �� ������
	for (int i = 0; i < len; i++)
	{
		/*���� ������ ���� ���������, ���������� false*/
		if (Priority(str[i]) > 1 && Priority(str[i + 1]) > 1)
		{
			correct = false;
			i = len;
		}
		/*���� ������ ���� ������, ���������� false*/
		//else if (Priority(str[i]) == 1 && Priority(str[i + 1]) == 1)
		else if ((str[i] == '(' && str[i + 1] == ')') || (str[i] == ')' && str[i + 1] == '('))
		{
			correct = false;
			i = len;
		}
		/*���� ����� �������� ��� ������������� ������,
		��� ����� ������������� ������ ��� �������,
		��� ���� �� ����� ������, �� ���������� false*/
		else if ((Priority(str[i]) == 0 && str[i + 1] == '(') || (str[i] == ')' && Priority(str[i + 1]) == 0 && i + 1 != len))
		{
			correct = false;
			i = len;
		}
		/*���� ��������� ���������� ��� ��������� ������ ���������, �� ���������� false*/
		else if (Priority(str[0]) > 1 || Priority(str[i]) > 1 && i == len - 1)
		{
			correct = false;
			i = len;
		}
		/*���� ����� ������������� ������, ���������� �� � �������*/
		else if (str[i] == '(')
		{
			NumLeftBkt++;
		}
		/*���� ����� �������������, � ���������� ������������� ������,
		�� ���������� � �������*/
		else if (str[i] == ')' && NumLeftBkt > NumRightBkt)
		{
			NumRightBkt++;
		}
	}
	/*���� ���������� ������ ��������, ���������� false*/
	if ((NumLeftBkt + NumRightBkt) % 2 != 0)
	{
		correct = false;
	}
	return correct;
}


/*������������, ������ ���������� ��������.*/
void PNMenu()
{

	char* expr = new char[255];		//��������� ������ ��� ������
	int choice = -1;			//���������� ������
								//����� ��������
	while (choice != 0)
	{
		cout << "1 - ������������� ���������\n0 - �����\n";
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			cout << "������� ���������(�� ����� 255 ��������, ��� ��������), ������� ����� - <<!>>: ";

			/*���� ��������� � �������������� ������������ ������ �����.*/
			cin >> expr;
			/*���� ������ �����, ��� � ��������� ���������� ������,
			������� ��������������� ���������*/
			while (strlen(expr) == 0 || Check(expr) == false)
			{
				cout << "������ ����� ��� �����������, ������� ���������: ";
				cin >> expr;
			}
			cout << "\n������ �������� ������: ";
			PrePN(expr);			//����� ������� ������ � ���
		}
		}
		cout << endl;
	}
}