#include <iostream>
#include <clocale>
#include<ctime>
#include <iomanip>
using std::cin;using std::cout;using std::setw; using std::swap;
//Транспонировать случайную квадратную матрицу (n,n)
const int N = 5, M = 5;
void printMat(int mat[][M]);
void randomMat(int mat[][M]);
void transposeMat(int mat[][M]);

int main()
{
	srand(time(0));
	setlocale(LC_ALL, "Russian");
	int mat[N][M]/* = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25 }*/;

	randomMat(mat);
	cout << " Исходнaя матрица:\n";
	printMat(mat);

	transposeMat(mat);
	cout << " Транспонированная матрица:\n";
	printMat(mat);
	

	system("pause");
}
void printMat(int mat[][M])
{
	for (int i = 0;i < N;i++)
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

void transposeMat(int mat[][M])
{
	for (int i = 0;i < N-1;i++)
	{
		int j = i;
		while (j++ < M-1)
			swap(mat[i][j], mat[j][i]);
	}
}
