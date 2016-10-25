#include <iostream>
#include <clocale>
#include<ctime>
using std::cin;using std::cout;

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
void NegativeToArrayC(int a[], int n, int *c, int&j)  // ������������� �������� � ������ �
{
	for (int i = 0;i<n;i++)
		if (a[i] < 0) { c[j] = a[i]; j++; }
}

void PositiveToArrayB(int a[], int n, int b[], int&j) // ������������� �������� � ������ B
{
	for (int i = 0;i<n;i++)
		if (a[i] > 0) { b[j] = a[i]; j++; }
}
const int n = 20;
int main()
{
	srand(time(0));
	setlocale(LC_ALL, "Russian");
	/* �������� ������ � ������������ ����� ������� N (����� N �������� ��� ���������).
	������������������� �������� ��������� ������� ���������� ������� �� ���������� �� -50 �� 50.
	"���������" ������ � �� ��� �������: ������������� �������� � ������ �, ������������� - � �.*/
	
	int  a[n], c[n], b[n], j = 0;
	RandomArrayWithBorders(a, n, -50, 50);
	NegativeToArrayC(a, n, c, j);
	cout << "�������� ������:";
	PrintArray(a, n);
	cout << "������ C ������������� ����� ��������� �������:";
	PrintArray(c, j);
	j = 0;
	PositiveToArrayB(a, n, b, j);
	cout << "������ B ������������� ����� ��������� �������:";
	PrintArray(b, j);

	system("pause");
}





