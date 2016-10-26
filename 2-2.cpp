#include <iostream>
#include <clocale>
#include<ctime>
 /*������ ����� ����� ������� N ������������������� ���������� ������� �� ���������� �� - N �� N.
���������� �������� �������� ������� ������ �� 1 �������(��������� ������� ������ ������, 1 - � ������ 2 - �, 2 - � ������ 3 - � � �.�.)
����� ���������� �������� �������� ������� ����� �� 1 �������(������ ������� ������ ���������, 2 - � ������ 1 - � � �.�)*/
using std::cin;using std::cout;using std::swap;

void printArray(int a[], int N);
void randomArray(int a[], int N, int min, int max);
void shiftArrayToTheRight(int a[], int N);
void shiftArrayToTheLeft(int a[],int N);
const int N = 10;
int main()
{

	srand(time(0));
	setlocale(LC_ALL, "Russian");

	int a[N + 1];
	randomArray(a, N, -N, N);
	cout << "�������� ������:\n";
	printArray(a, N);

	shiftArrayToTheRight(a, N);
	cout << "��������� ������ ������\n";
	printArray(a, N);

	shiftArrayToTheLeft(a, N);
	cout << "��������� ����� ������\n";
	printArray(a, N);
	
	system("pause");
}
void shiftArrayToTheRight(int a[], int N) //����� ������� ������
{
	int last = a[N - 1];
	for (int i = N-1;i > 0;i--)
		a[i] = a[i - 1];
	a[0] = last;
}

void shiftArrayToTheLeft(int a[], int N) //����� ������� �����
{
	int first = a[0];
	for (int i = 0;i < N-1;i++)
		a[i] = a[i + 1];
	a[N - 1] = first;
}

void randomArray(int a[], int N, int min, int max) // ��������� ���������� ������� �� min �� max
{
	max++;
	for (int i = 0;i < N;i++)
		a[i] = rand() % (max - min) + min;
}

void printArray(int a[], int N)
{
	for (int i = 0;i < N;i++)
		cout << a[i] << " ";

	cout << "\n\n";}