#pragma once
#include"List.h"

/*Подпрограмма, выбора дальнейших действий.*/
void PNMenu();

/*Функция для проверки выражения на правильность*/
bool Check(char * str);

/*Определение приоритета операции*/
int Priority(char symbol);

/*Прямая польская запись*/
void PrePN(char * expr);


