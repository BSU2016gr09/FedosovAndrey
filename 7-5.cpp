#include <iostream>
#include <clocale>
#include<ctime>
#include <iomanip>
using std::cin;using std::cout;using std::setw;
const int N = 10, M = 5;

void printMat(int mat[][M],int n);
void randomMat(int mat[][M]);
void delNullStr(int mat[][M],int&n);
void delStr(int mat[][M],int str, int&n);


int main()
{
	srand(time(0));
	setlocale(LC_ALL, "Russian");
	int mat[N][M],n=N;

	randomMat(mat);
	cout << " Исходнaя матрица:\n";
	printMat(mat,n);

	delNullStr(mat, n);
	cout << "Матрица без нулевых строк:\n";
	printMat(mat, n);
	system("pause");
}
void printMat(int mat[][M],int n)
{
	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < M;j++)
			cout << setw(3) << mat[i][j] << " ";
		cout << "\n";
	}
	cout << "\n";
}
void randomMat(int mat[][M])
{
	for (int i = 0;i < N;i++)
		for (int j = 0;j < M;j++)
			mat[i][j] = rand() % 2; //числа от 0 до 1
}

void delNullStr(int mat[][M],int&n) //удалить нулевые строки
{
	int flag;
	for (int i = 0;i < N;i++)
	{
		flag = 0;
		for (int j = 0;j < M;j++)
			if (mat[i][j] != 0) { flag = 1;break; }
		if (!flag) delStr(mat, i, n);
	}
}

void delStr(int mat[][M], int str, int&n) //удалить строку
{
	for (int i = str;i < n - 1; i++)
		for (int j = 0;j < M;j++)
			mat[i][j] = mat[i+1][j];
	n--;
}