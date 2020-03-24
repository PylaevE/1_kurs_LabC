#pragma once
#include<iostream>
using namespace std;
/*���������.*/
struct stop
{
	char key;                                         //�������������� ����� ���������.
	int otdal;                                        //�������������� ����� ���������.											   
};

/*���������.*/
template<typename T>
struct List
{
	T key;                                         //�������������� ����� ���������.
	List* next;                                    //����� ���������� �������� ������.
	List* prev;                                    //����� ����������� �������� ������.
};

/*���������� �������� � ������.� �����.*/
template<typename T>
List<T> * PushBack(List<T> *lst, T t)
{
	List<T> *p;
	List<T> *Current = new List<T>;                   // ��������� ������.
    /*���� ������ �� ������ ��������� ������� ������.*/
	if (lst != NULL)
	{
		p = lst->next;                               // ���������� ��������� �� ��������� ������� ������.
		lst->next = Current;                         // ���������� ������� ������ ��������� �� �����������.
		Current->key = t;                            // ���������� ���� ������ ������������ �������� ������.
		Current->next = p;                           // ��������� ������� ������ ��������� �� ��������� ������� ������.
		Current->prev = lst;                         // ��������� ������� ������ ��������� �� ���������� ������� ������.
		if (p != NULL)                               // �������� ���������
			p->prev = Current;
	}
	else //�������������� ������.
	{
		Current->key = t;
		Current->next = NULL;                        // ��������� �� ��������� ����.
		Current->prev = NULL;                        // ��������� �� ���������� ����.
	}
	return(Current);
}

/*���������� �������� � ������. � ������*/
template<typename T>
List<T> * PushFront(List<T> *lst, T t)
{
	List<T> *p;
	List<T> *Current = new List<T>;                         // ��������� ������.
	List<T>* first;
	/*���� ������ �� ������ ��������� ������� �����.*/
	if (lst != NULL)
	{
		first = lst;
		p = first->prev;                           // ���������� ��������� �� ��������� ������� ������.
		first->prev = Current;                     // ���������� ������� ������ ��������� �� �����������.
		Current->key = t;                          // ���������� ���� ������ ������������ �������� ������.
		Current->next = first;                     // ��������� ������� ������ ��������� �� ��������� ������� ������.
		Current->prev = p;                         // ��������� ������� ������ ��������� �� ���������� ������� ������.
		if (p != NULL)                             // �������� ���������
			p->next = Current;
	}
	else //�������������� ������.
	{
		Current->key = t;
		Current->next = NULL;                      // ��������� �� ��������� ����.
		Current->prev = NULL;                      // ��������� �� ���������� ����.
	}
	return(Current);
}


/*������������, ������� ����������
��������� �� ��������� ������� ������.*/
template<typename T>
List<T>* Findend(List<T>* list)
{
	List<T> *K = new List<T>;
	K = NULL;
	while (list != NULL)
	{
		K = list;					        //���������� ��������� �� ��������� �������.
		list = list->next;
	}
	return K;
}

/*������������, ������� ����������
��������� �� ������ ������� ������.*/
template<typename T>
List<T>* FindHead(List<T>* list)
{
	List<T> *K = new List<T>;
	K = NULL;
	while (list != NULL)
	{
		K = list;					//���������� ��������� �� ������ �������.
		list = list->prev;
	}
	return K;
}

/*����� ������ �� �����*/
template<typename T>
void OutputList(List<T>*first)
{
	List<T>* p = first;
	if (p != NULL)                               //�������� ���������.
	{
		while (p != NULL)                        //�����.
		{
			cout << p->key << " ";
			p = p->next;
		}
	}
	else
	{
		cout << "������ ����." << endl;
	}
}

/*������������, ������� ������� � ������
����� ����������(���������) � ������ ��������.
ind - ������ ��������.*/
template<typename T>
T Findind(List<T>* c, int ind)
{
	List<T> *K = new List<T>;
	K = FindHead(c);
	int i = 1;
	while (i < ind)
	{
		K = K->next;
		i++;
	}
	return K->key;
}

/*������������, ������� ������� � ������
����� ����������(���������) � ������ ��������.
ind - ������ ��������.*/
template<typename T>
int FindMaxcount(List<T>* c, int ind)
{
	List<T> *K = c;
	int max = 0;             //������������ ����� ��������.
	int i = 0;
	/*����� ����������� �����.*/
	while (i < ind)
	{
		if (K->key>max)
		{
			max = K->key;
		}
		K = K->next;
		i++;
	}
	return max;
}


/*������������, ������� ���������
�������� ������� �������� ������. */
template<typename T>
List<T>* PopFront(List<T> *h)
{
	List<T> *p = h;
	if (h != NULL)
	{
		p = h->next;						//�������, �������������� h
		if (h->next != NULL)				//��� ������� �������� ����� ����������
			p->prev = h->prev;				//������������ ��������� � ���������� �� ���������
		free(h);                            //����������� ������ ���������� ��������
	}
	return(p);
}

/*������������, ������� ���������
�������� ���������� �������� ������. */
template<typename T>
List<T>* PopBack(List<T> *h)
{
	List<T> *p = h;
	if (h != NULL)
	{
		p = h->prev;						//�������, �������������� h
		if (h->prev != NULL)				//��� ������� �������� ����� ����������
			p->next = h->next;				//������������ ��������� � ���������� �� ���������
		free(h);							//����������� ������ ���������� ��������
	}
	return(p);
}


//������� �������� �������
template<typename T>
void DeleteQueue(List<T> * first)
{
	List<T> * next = NULL;
	//���� ������ ������� �� ����� ����� ����, ������� �������� �������
	while (first != NULL)
	{
		next = first->next;					//��������� ��������� �� ������ �������
		delete first;							//������� ���
		first = next;							//��������� ������� ���� ������
	}
}


//������� �������� �����
template<typename T>
void DeleteStack(List<T>* elemStack)
{
	List<T>* prev = NULL;
	//���� �������� ����, ������� ��
	while (elemStack != NULL)
	{
		prev = elemStack->prev;				//����������� ��������� �� ���������� �������
		delete elemStack;						//������� ���
		elemStack = prev;						//��������� � ���������� ��������
	}
}
