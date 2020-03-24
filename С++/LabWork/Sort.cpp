#include"InputOutput.h"
#include"Sort.h"
#include"SortActions.h"

/*����������� ����������.*/
void RadixSort(int*& array, int n)
{
	int* newArray = new int[n];		 	          //��������������� ������.
	int digit = 1;						          //���������� ��� �������.
	int digitMax = MaxDischarge(array, n);        //���������� ������������ ������.

												  /*��������� ���� ���� �� ��������� �������� �������*/
	for (int j = digitMax; j>0; j--)
	{
		int arrayDigit[10] = { 0 };			     //��������������� ������ ��� ��������.
												 /*������� �����, ������� �����
												 �������� � ���� ������.*/
		for (int i = 0; i < n; i++)
		{
			arrayDigit[(array[i] / digit) % 10]++;
		}

		/*���������� �������� �� ����������� �������,
		��� �� �������� ������� ����� ������� ������������ ��� ��� ���� ������.*/
		for (int i = 1; i < 10; i++)
		{
			arrayDigit[i] += arrayDigit[i - 1];
		}
		/* ��������� ��������������� ������ � ������� ������� ��������.*/
		for (int i = n - 1; i >= 0; i--)
		{
			newArray[--arrayDigit[(array[i] / digit) % 10]] = array[i];
		}
		/*������������ ��������������� ������ � ��������.*/
		for (int i = 0; i < n; i++)
		{
			array[i] = newArray[i];
		}

		digit *= 10;					      	//��������� � ���������� �������
	}
	delete[] newArray;

}
/*������������, ������� ���������� ���������� �������� � �����.*/
int Discharge(int N)
{
	int i = 0;
	/*����������� ���������� ��������*/
	while (N > 0)
	{
		N = N / 10;
		i++;
	}
	return i;
}

