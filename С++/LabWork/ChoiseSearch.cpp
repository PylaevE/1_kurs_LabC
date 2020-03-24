#include"InputOutput.h"
#include"List.h"
#include"Search.h"


/*������������, ������� ��������� ������ ��� ��������:
���� , ����� � ����� ��� .
n - ����� ������.
s - ����� �����.*/
void KMPsearchActions(int n, int s)
{
	List<int>* c;
	char* text = new char[n];                     //��������� ������ ��� ������. 
	char* word = new char[s];
	cout << "������� �����.";
	InputChar(text, n);
	/*������� ������� �����.
	���������� �������� ������������
	����� ��� ������ � char.*/
	cin.ignore(1000, '\n');
	cout << "������� �����, ������� ����� �����.";

	InputChar(word, s);
	cin.ignore(1000, '\n');
	c = KMP(text, word);
	cout << "������� ������ ��������� ������� � ������.\n";
	OutputList(c);
}

/*������������, ������� ��������� ������ ��� ��������:
���� , ����� � ����� � ������� ��������� ������-����.
n - ����� ������.
s - ����� �����.*/
void BMsearchActions(int n, int s)
{
	List<int>* c;
	char* text = new char[n];                     //��������� ������ ��� ������. 
	char* word = new char[s];
	cout << "������� �����.";
	InputChar(text, n);
	/*������� ������� �����.
	���������� �������� ������������
	����� ��� ������ � char.*/
	cin.ignore(1000, '\n');
	cout << "������� �����, ������� ����� �����.";
	InputChar(word, s);
	cin.ignore(1000, '\n');
	c = BM(text, word);
	c = FindHead(c);
	cout << "������� ������ ��������� ������� � ������.\n";
	OutputList(c);
}

/*������������, ������� ��������� ������ ��� ��������:
���� , ����� � ����� � ������� ��������� ������ � �����.
n - ����� ������.
s - ����� �����.*/
void RKsearchActions(int n, int s)
{
	List<int>* c;
	char* text = new char[n];                     //��������� ������ ��� ������. 
	char* word = new char[s];
	cout << "������� �����.";
	InputChar(text, n);
	/*������� ������� �����.
	���������� �������� ������������
	����� ��� ������ � char.*/
	cin.ignore(1000, '\n');
	cout << "������� �����, ������� ����� �����.";
	InputChar(word, s);
	cin.ignore(1000, '\n');
	c = RK(text, word);
	c = FindHead(c);
	cout << "������� ������ ��������� ������� � ������.\n";
	OutputList(c);
}

/*������������ ������ ������.*/
void ChoiseSearch()
{
	int n;                                   //����� �������.
	cout << "������� ����� �������.";
	cin >> n;
	int s;                                  //����� �����.
	cout << "������� ����� �����.";
	cin >> s;
	int i = 10;                              //���������� ��� ������ ������.
											 /*����� ������.*/
	while (i != 0)
	{
		cout << "\n�������� ������� ������:\n";
		cout << "\n1 - ��� (�������� ����� � ������� � ������)\n";
		cout << "\n2 - BM (��������� ������-����.)\n";
		cout << "\n3 - RK (��������� ������ � �����.)\n";
		cout << "0 - �����\n";
		cin >> i;
		switch (i)
		{
		case 1:
		{
			KMPsearchActions(n, s);       //����, ����� � �����.
			break;
		}
		case 2:
		{
			BMsearchActions(n, s);         //����, ����� � �����.
			break;
		}
		case 3:
		{
			RKsearchActions(n, s);         //����, ����� � �����.
			break;
		}
		/*�����*/
		case 0:
		{
			break;
		}
		default:
		{
			cout << "��������� ��� �����������.\n";
		}
		}
	}
}
