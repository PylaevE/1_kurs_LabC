#pragma once


/*�����������, ������� ���������� ��������  ����������*/
template<typename T>
void Swap(T *array, int i, int j)
{
	T element = array[j];     // ��������� ���������� ��� �������� �������� �������.
	array[j] = array[i];      // ������������ ��������� �������.
	array[i] = element;
}

/*����������� ���������� ������� ���������(�� �����������)*/
template<typename T>
void BubbleSort(T* array, int n)
{
	for (int i = 0; i < n - 1; i++)             //������� ���� �������.
	{
		for (int j = n - 1; j > i; j--)        //���������� ���� �������.
		{
			if (array[j] < array[j - 1])       //����������� ���� �������� ���������.
			{
				Swap(array, j, j - 1);         //���������� �������� ����������
			}
		}
	}
}

/*���������� ������� �����*/
template<typename T>
void ShellSort(T*array, int n)
{
	int step;
	for (step = n / 2; step > 0; step /= 2)                   //���� ��� ������ 0, ��������� ���� � ����������� ����.
															  //� ��������� ����.
		for (int i = 0; i < (n / step); i++)			      //�������� ������.
		{
			for (int j = i; j < n - step; j += step)          //��������� ������ ������ ������.
			{
				if (array[j] > array[j + step])               //���������� ��������.
				{
					Swap(array, j + step, j);                 //���������� �������� ���������� � �����.
					if (j > 0)                                //�������� ������ �� ������� �������.
					{
						j -= step * 2;
					}
					else
					{
						j -= step;
					}

				}

			}
		}
}

/*������� ����������*/
template<typename T>
void QuickSort(T*array, int left, int right)
{
	int indMiddle = (left + right) / 2;            //���������� ������� �������� �������� �������.
	T middle = array[indMiddle];                   //������� �������.
	int i = left;                                  //������ ����� �������.
	int j = right;                                 //������ ������ �������.           
	do {
		while ((array[i] < middle) && (i < right)) //����������� i,
			i++;                                   // ���� i - � ������� ������ ��������.
		while ((array[j] > middle) && (j > left))  //��������� j, 
			j--;                                   //���� j-� ������� ������ ��������.
		if (i <= j)                                //���� i �� ��� ������ j, �� ,  � �������������� j
		{
			Swap(array, i, j);                     //������ i-� � j-� �������� �������.
			i++;                                   //����������� i.
			j--;                                   //��������� j.
		}
	} while (i <= j);                              //���� i ����� ���������� ������ j, 
												   //�� ��������� ����.
	if (left < j)                                  //���������� �������� ���������� 
	{                                              //��� ����� � ������ ����� �������/
		QuickSort(array, left, j);
	}
	if (right > i)
	{
		QuickSort(array, i, right);
	}
}
/*����������� ����������.*/
void RadixSort(int*& array, int n);

/*������������, ������� ����
������������ ������ � �������.*/
template<typename T>
int MaxDischarge(T*array, int n)
{
	int max, constmax = 0;                        //���������� ��� ��������.
												  /*������������� ������, ���� ������������ ������*/
	for (int i = 0; i < n; i++)
	{
		max = Discharge(array[i]);                //���� ������� �������� � �����. 
		if (max > constmax)                       //��������� ������������ ������.
		{
			constmax = max;
		}
	}
	return constmax;
}

/*����������� ����.
������������, ������� ���������� �������� �
������� � ������ ������� ������� �� ����� ������.
end-��������� ������� ��������
parent-������ "������".*/
template<typename T>
void SiftDown(T *array, int end, int parent)
{
	int maxChild = 0;     //������ ������������� �������.
	bool theExchangeWas = true;
	/*��������� ������������� ������� "������".*/
	while ((parent * 2 + 1 <= end ) && theExchangeWas)
	{
		/*����� ������������ �������*/
		maxChild = MaxChild(end, array, parent);
		/*���� ������ ������ ������������� �������
		������ �� �������.*/
		if (array[parent] < array[maxChild])
		{
			Swap(array, parent, maxChild);   //������ ������� ��������.
			parent = maxChild;
		}
		else
			theExchangeWas = false;                      //����� �� �����.
	}
}
/*������������, ������� ���� ������������� "�������".
end-��������� ������� �������.*/
template<typename T>
int MaxChild(int end, T*array, int parent)
{
	int left = parent * 2 + 1;           //������ ������ �������.
	int right = parent * 2 + 2;          //������ ������� �������.
	int maxChild = left;                    //������ ������������� �������.
	/*���� ������ ������� ����������.*/
	if (left != end)
	{
		/*������� ���������� �� ��������.*/
		if (array[left] < array[right])
		{
			maxChild = right;
		}
	}
	return maxChild;
}

/*������������� ����������.
n-����� �������.*/
template<typename T>
void HeapSort(T* array, int n)
{
	int end = n - 1;                    //������ ���������� �������� �������.
	/*��������� ������, ��� ����� ���
	������� ���� ������ ����� �������. */
	for (int i = n / 2 - 1; i >= 0; i--)
	{
		SiftDown(array, end, i);   //���������� ��������.
	}
	/*��������� ������������ ������� � ����� �������.
	��������� ������, ��� ����� ���
	������� ���� ������ ����� ��������.*/
	for (int i = n - 1; i >= 1; i--)
	{
		/*��������� �� ������������ ������� �� ������� ������ � �����.*/
		Swap(array, i, 0);
		SiftDown(array, i - 1, 0);   //���������� ��������.
	}
}