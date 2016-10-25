#include <iostream>
#include <clocale>
#include<ctime>
using std::cin;using std::cout;using std::swap;

void PositiveThenNegativeSort(int a[], int n) //����������� ������ ����� ������� : ������� �������������,����� �������������
{
	int pointer = 0, i = 0;
	while (i < n)
	{
		if (a[i] > 0) { swap(a[i], a[pointer]);pointer++; }
		i++;
	}
}

void PrintArray(int a[], int n) // ������ �������
{
	for (int i = 0;i < n;i++)
		cout << a[i] << " ";
	cout << "\n\n";
}

void RandomArrayWithBorders(int a[], int n, int min, int max) // ��������� �������� ������ �� min �� max ������������
{
	max++;
	for (int i = 0;i < n;i++)
		a[i] = rand() % (max - min) + min;
}

const int n = 20;
int main()
{/*6)**��� ��������
 �������� ������ � ������������ ����� ������� N(����� N �������� ��� ���������).
 ������������������� �������� ��������� ������� ���������� ������� �� ���������� �� - 50 �� 50.
 "�������������" ������ � �� �����(�.�.�� ��������� ��������������� �������� � � �)
 ����� ������� : ������������� �������� ������� � ����������� � ������, ������������� ����������� � ����� ������� �.
 (��������� �����, ��� ��������� �������� ����� ��� �������� ������ �����!)*/
	srand(time(0));
	setlocale(LC_ALL, "Russian");
	int a[20];
	RandomArrayWithBorders(a, n, -50,50);
	cout << "�������� ������\n";
	PrintArray(a, n);
	PositiveThenNegativeSort(a, n);
	cout << "��������������� ������\n";
	PrintArray(a, n);

	system("pause");
}





