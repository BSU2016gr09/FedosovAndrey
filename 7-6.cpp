#include <iostream>
#include <clocale>
#include<ctime>
#include <iomanip>
//В матрице (n,m) удалить строки у которых максимальный элемент стоит первым, "подтянув" все остальные строки.
using std::cin;using std::cout;using std::setw;
const int N = 5, M = 5;
void printMat(int mat[][M],int&n);
void randomMat(int mat[][M]);
void delStrWithMaxFirst(int mat[][M], int&n);
void delStr(int mat[][M],int str, int&n);
int main()
{
	srand(time(0));
	setlocale(LC_ALL, "Russian");
	int mat[N][M], n = N;

	randomMat(mat);
	cout << " Исходнaя матрица:\n";
	printMat(mat,n);
	delStrWithMaxFirst(mat,n);
	cout << " Матрица без строк,с максимальным элементом на первом месте:\n";
	printMat(mat, n);
	system("pause");
}

void printMat(int mat[][M],int&n)
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
			mat[i][j] = rand() % 101 - 50; //числа от -50 до 50 
}



void delStrWithMaxFirst(int mat[][M], int&n) 
{
	int max;
	for (int i = 0;i < N;i++)
	{
		max = mat[i][0];
		for (int j = 0;j < M;j++)
			if (mat[i][j] > max) { max = mat[i][j];break; }
		if (max==mat[i][0]) delStr(mat, i, n);
	}
}

void delStr(int mat[][M], int str, int&n) 
{
	for (int i = str;i < n - 1; i++)
		for (int j = 0;j < M;j++)
			mat[i][j] = mat[i + 1][j];
	n--;
}