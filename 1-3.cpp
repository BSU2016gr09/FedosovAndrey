#include <iostream>
#include <clocale>
#include<ctime>
using std::cin;using std::cout;

void PrintArray(int a[], int n) // ������ �������
{
	for (int i = 0;i < n;i++)
		cout << a[i] << " ";
	cout << "\n\n";
}
bool isNaturalAndUnder101(double n) //������������ ����� 
{
	if (n>0 && n / floor(n) == 1 && n <= 100) return true;else return false;
}
int NumberOfPositiveEvenNumbers(int a[], int n) // ���������� ������ ������������� �����
{
	int count = 0;
	for (int i = 0;i < n;i++)
		if (a[i] > 0 && a[i] % 2 == 0) count++;
	return count;
}

void RandomArrayWithBorders(int a[], int n, int min, int max) // ��������� �������� ������ �� min �� max ������������
{
	max++;
	for (int i = 0;i < n;i++)
		a[i] = rand() % (max - min) + min;
}


int main()
{
	srand(time(0));
	setlocale(LC_ALL, "Russian");
	/*������������ ������ � ���������� ����������� ����� �� ������� 100, ������� ����������� � ���������� n,
	��������� ������������ �����, ������� ������ �� 10 ��������� ����� ����� �� ������� [-2n;n], ������� ������ �� ����� � ������,
	���������� � � ������� �� ����� ���������� ������������� ������ ����� � �������.*/
	double n;
	cout << "������� ����������� ����� �� ������ 100\nn=";
	cin >> n; int a[10];
	if (isNaturalAndUnder101(n))
	{
		RandomArrayWithBorders(a, 10, -2 * n, n);
		cout << "���������� ������ �� �������[-" << 2 * n << ";" << n << "]:\n";
		PrintArray(a, 10);
		cout << "���������� ������������� ������ ����� � ������� = " << NumberOfPositiveEvenNumbers(a, 10) << "\n";
	}
	else cout << n << " �� �������� ��� ������� ������\n";

	system("pause");
}