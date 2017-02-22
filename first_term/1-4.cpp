#include <iostream>
#include <clocale>
#include<ctime>
using std::cin;using std::cout;

void PrintElementsWithOddNumbers(int a[], int n) // ������ ��������� � ��������� ��������
{
	int i = 1;
	while (i < n)
	{
		cout << a[i] << " ";i += 2;
	}
	cout << "\n";
}
void PrintElementsWithEvenNumbers(int a[], int n) // ������ ��������� � ������� ��������
{
	int i = 0;
	while (i < n)
	{
		cout << a[i] << " ";i += 2;
	}
	cout << "\n";
}
void RandomArrayWithBorders(int a[], int n, int min, int max) // ��������� �������� ������ �� min �� max ������������
{
	max++;
	for (int i = 0;i < n;i++)
		a[i] = rand() % (max - min) + min;
}
void PrintArray(int a[], int n) // ������ �������
{
	for (int i = 0;i < n;i++)
		cout << a[i] << " ";
	cout << "\n\n";
}

const int n = 20;
int main()
{
	srand(time(0));
	setlocale(LC_ALL, "Russian");
	/* �������� ������ ������������ ����� ������� N (����� N �������� ��� ���������).
	������������������� �������� ��������� ������� ���������� ������� �� ���������� �� -50 �� 50.
	������� �������� ������� ��������� � ��������� �������������� (1-�, 3-�, 5-�,...) � ����� - � �������.*/
	
	int  a[n];
	RandomArrayWithBorders(a, n, -50, 50);
	cout << "�������� ������:";
	PrintArray(a, n);
	cout << "�������� � ��������� ��������:";
	PrintElementsWithOddNumbers(a, n);
	cout << "�������� � ������� ��������:";
	PrintElementsWithEvenNumbers(a, n);

	system("pause");
}





