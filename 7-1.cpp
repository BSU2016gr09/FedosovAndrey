#include <iostream>
#include <clocale>
#include<ctime>
#include <iomanip>
//Найти в случайной матрице минимум в каждом столбце.
using std::cin;using std::cout;using std::setw;
const int N = 5, M = 5;
void printMat(int mat[][M]);
void randomMat(int mat[][M]);
void minFromEachColumn(int mat[][M]);

int main()
{
	srand(time(0));
	setlocale(LC_ALL, "Russian");
	int mat[N][M];

	randomMat(mat);
	cout << " Исходнaя матрица:\n";
	printMat(mat);
    minFromEachColumn(mat);
	system("pause");
}
void printMat(int mat[][M])
{
	for (int i = 0;i < N;i++)
	{
		for (int j = 0;j < M;j++)
			cout <<setw(3)<< mat[i][j] << " ";
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

void minFromEachColumn(int mat[][M])
{
	int min;
	for (int j = 0;j < M;j++)
	{
		min = mat[0][j];
		for (int i = 0;i < N;i++)
			if (mat[i][j] < min) min = mat[i][j];
		cout << "Минимум в " << j << "-ом стоблце :" << min << "\n";
	}
}