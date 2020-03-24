#include"SortActions.h"
#include"Sort.h"
#include<iostream>
using namespace std;

/*����������� ��� ������ ���������� ���� int.*/
void SortActionsInt(int n)
{
	int i = 10;                              //���������� ��� ������ ����������.
											 /*����� ����������.*/
	while (i != 0)
	{
		cout << "\n�������� ��� ����������:\n";
		cout << "\n1-���������� ���������\n2-���������� �����";
		cout << "\n3-������� ����������\n4-����������� ����������";
		cout << "\n5-������������� ����������\n0-�����\n";
		cin >> i;
		switch (i)
		{
		case 1:
		{
			BubbleSortActions<int>(n);       //����, ����� � ����������.
			break;
		}
		case 2:
		{
			ShellSortActions<int>(n);        //����, ����� � ����������.
			break;
		}
		case 3:
		{
			QuickSortActions<int>(n);        //����, ����� � ����������.
			break;
		}
		case 4:
		{
			RadixSortActions<int>(n);        //����, ����� � ����������.
			break;
		}
		case 5:
		{
			HeapSortActions<int>(n);         //����, ����� � ����������.
			break;
		}
		/*�����*/
		case 0:
			break;
		default:
		{
			cout << "��������� ��� �����������.\n";
		}
		}
	}
}


/*����������� ��� ������ ���������� ���� Char*/
void SortActionsChar(int n)
{
	int i = 10;                               //���������� ��� ������ ����������.
											  /*����� ����������.*/
	while (i != 0)
	{
		cout << "\n�������� ��� ����������:\n";
		cout << "\n1-���������� ���������\n2-���������� �����";
		cout << "\n3-������� ����������";
		cout << "\n4-������������� ����������\n0-�����\n";
		/*������� ������� �����.
		���������� �������� ������������
		����� ��� ������ � char.*/
		cin.ignore(1000, '\n');
		cin >> i;
		switch (i)
		{
		case 1:
		{
			BubbleSortActions<char>(n);      //����, ����� � ����������.
			break;
		}
		case 2:
		{
			ShellSortActions<char>(n);       //����, ����� � ����������.
			break;
		}
		case 3:
		{
			QuickSortActions<char>(n);       //����, ����� � ����������.
			break;
		}
		case 4:
		{
			HeapSortActions<char>(n);         //����, ����� � ����������.
			break;
		}
		/*�����*/
		case 0:
			break;
		default:
		{
			cout << "��������� ��� �����������.\n";
		}
		}
	}
}


/*����������� ��� ������ ���������� ���� Double*/
void SortActionsDouble(int n)
{
	int i = 10;                               //���������� ��� ������ ����������.
											  /*����� ����������.*/
	while (i != 0)
	{
		cout << "\n�������� ��� ����������:\n";
		cout << "\n1-���������� ���������\n2-���������� �����";
		cout << "\n3-������� ����������";
		cout << "\n4-������������� ����������\n0-�����\n";
		cin >> i;
		switch (i)
		{
		case 1:
		{
			BubbleSortActions<double>(n);     //����, ����� � ����������.
			break;
		}
		case 2:
		{
			ShellSortActions<double>(n);      //����, ����� � ����������.
			break;
		}
		case 3:
		{
			QuickSortActions<double>(n);      //����, ����� � ����������.
			break;
		}
		case 4:
		{
			HeapSortActions<double>(n);         //����, ����� � ����������.
			break;
		}
		/*�����*/
		case 0:
			break;
		default:
		{
			cout << "��������� ��� �����������.\n";
		}
		}
	}
}


/*����������� ��� ������ ���������� ���� Float*/
void SortActionsFloat(int n)
{
	int i = 10;                              //���������� ��� ������ ����������.
											 /*����� ����������.*/
	while (i != 0)
	{
		cout << "\n�������� ��� ����������:\n";
		cout << "\n1-���������� ���������\n2-���������� �����";
		cout << "\n3-������� ����������";
		cout << "\n4-������������� ����������\n0-�����\n";
		cin >> i;
		switch (i)
		{
		case 1:
		{
			BubbleSortActions<float>(n);      //����, ����� � ����������.
			break;
		}
		case 2:
		{
			ShellSortActions<float>(n);       //����, ����� � ����������.
			break;
		}
		case 3:
		{
			QuickSortActions<float>(n);       //����, ����� � ����������.
			break;
		}
		case 4:
		{
			HeapSortActions<float>(n);         //����, ����� � ����������.
			break;
		}
		/*�����*/
		case 0:
			break;
		default:
		{
			cout << "��������� ��� �����������.\n";
		}
		}
	}
}