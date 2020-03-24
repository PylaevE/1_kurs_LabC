#include<iostream>
#include"ChoiceSort.h"


using namespace std;

/*����� ���� ������ ��� ����������.*/
void DataTypeSort()
{
	int i = 5;                               //���������� ��� ������ ���� ������
	int n;                                   //����� �������.
	cout << "������� ����� �������.";
	cin >> n;
	/*����� ���� ������ ��� �������
	(�������������, ����������, ������������*/
	while (i != 0)
	{
		cout << "\n�������� ��� ������:\n";
		cout << "1 - int\n2 - char\n3 - double\n4 - float\n0 - �����\n";


		/*������� ������� �����.
		���������� �������� ������������
		����� ��� ������ � char.*/
		cin.ignore(1000, '\n');

		cin >> i;
		switch (i)
		{
			/*��� ������ int*/
		case 1:
		{
			SortActionsInt(n);               //����� ���������� ��� ���� int.
			break;
		}
		/*��� ������ char*/
		case 2:
		{
			SortActionsChar(n);              //����� ���������� ��� ���� char.
			break;
		}
		/*��� ������ double*/
		case 3:
		{
			SortActionsDouble(n);            //����� ���������� ��� ���� double.
			break;
		}
		/*��� ������ float*/
		case 4:
		{
			SortActionsFloat(n);             //����� ���������� ��� ���� float.
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
