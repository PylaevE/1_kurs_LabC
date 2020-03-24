#pragma once
/*������������ ������ ������.*/
void ChoiseSearch();

/*������������, ������� ��������� ������ ��� ��������:
���� , ����� � ����� ��� .
n - ����� ������.
s - ����� �����.*/
void KMPsearchActions(int n, int s);

/*������������, ������� ��������� ������ ��� ��������:
���� , ����� � ����� � ������� ��������� ������-����.
n - ����� ������.
s - ����� �����.*/
void BMsearchActions(int n, int s);

/*������������, ������� ��������� ������ ��� ��������:
���� , ����� � ����� � ������� ��������� ������ � �����.
n - ����� ������.
s - ����� �����.*/
void RKsearchActions(int n, int s);