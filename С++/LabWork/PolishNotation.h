#pragma once
#include"List.h"

/*������������, ������ ���������� ��������.*/
void PNMenu();

/*������� ��� �������� ��������� �� ������������*/
bool Check(char * str);

/*����������� ���������� ��������*/
int Priority(char symbol);

/*������ �������� ������*/
void PrePN(char * expr);


