#include <iostream>
#include <clocale>
#include<ctime>

/*������ � ����� ����� ������� N ������������������� ���������� ������� �� ���������� �� - N �� N.
�� ��������� ������� �� ������ 2 - 2 �������� ������� ������������ ������� �������� ������� ������ �� k ���������
(1 - � ������ 1 + k - ��, 2 - � ������ 2 + k - �� � �.�.) � ����� �� k ���������.
� main �������� ����� ���� ������� ��� ����� k, ������� ������ ������������.
���������� ��������� ������� ���������� ������ ������� �������� ����� �������� ����� ������ �� ������� �.*/

using std::cin;using std::cout;using std::swap;

void printArray(int a[], int N);
void randomArray(int a[], int N, int min, int max);
void shiftArrayToTheRight(int a[], int N,int k);
void shiftArrayToTheLeft(int a[], int N,int k);
void rollArray(int a[],int left, int right);

const int N = 10;
int main()
{

	srand(time(0));
	setlocale(LC_ALL, "Russian");
	cout << "������� ����� �� ������� ����� �������� ������\n";
	int a[N], k;
	cin >> k;
	randomArray(a, N, -N, N);
	cout << "�������� ������:\n";
	printArray(a, N);

	shiftArrayToTheRight(a, N,k);
	cout << "��������� ������ ������\n";
	printArray(a, N);

	shiftArrayToTheLeft(a, N,k);
	cout << "��������� ����� ������\n";
	printArray(a, N);

	system("pause");
}
void shiftArrayToTheRight(int a[], int N, int k) //�������� ������
{
	k = k%N;
	if (k)
	{
		rollArray(a, 0, N - k - 1);
		rollArray(a, N - k, N - 1);
		rollArray(a, 0, N - 1);
	}
}

void shiftArrayToTheLeft(int a[], int N, int k) //�������� �����
{
	k = k%N;
	if (k)
	{
		rollArray(a, 0, k - 1);
		rollArray(a, k, N - 1);
		rollArray(a, 0, N - 1);
	}
}

void rollArray(int a[], int left, int right) //����������� ������
{
	int i = left,j = right;
	while(i<j)
	{
		swap(a[i], a[j]);
		i++;j--;
	}
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

	cout << "\n\n";
}