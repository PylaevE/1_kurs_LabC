#include<iostream>
#include"InputOutput.h"
#include"locale.h"
#include"ChoiseSerach.h"
#include"ChoiceOfDataType.h"
#include"SteckQueue.h"
#include"BinaryTree.h"
#include"PolishNotation.h"
using namespace std;

/*���������, ������� ��������� ���������
���������� � ������ ��� ��������� ����� ������*/
int main()
{
	setlocale(LC_ALL, "Rus");
	int i = 6;                               //���������� ��� ������ ���� ������
	
	/*����� �������� , ������� ����� ����������� ��� ��������.
	(�����, ����������)*/
	while (i != 0)
	{
		cout << "\n�������� ��������, ������� ����� ����������� ��� ��������.";
		cout << "\n1 - ����������\n2 - �����\n3 - ����, �������";
		cout << "\n4 - �������� ������.\n5 - �������� ������.\n0 - �����\n";
		cin >> i;
		switch (i)

		{
			/*����������.*/
		case 1:
		{
			DataTypeSort();
			break;
		}
		/*�����*/
		case 2:
		{
			ChoiseSearch();
			break;
		}
		/*����, �������*/
		case 3:
		{
			SteckQueue();
			break;
		}
		/*�������� ������.*/
		case 4:
		{
			BinaryTree();
			break;
		}
		/*�������� ������.*/
		case 5:
		{
			PNMenu();
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

return 0;
}