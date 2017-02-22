#include <iostream>
#include <clocale>
#include<ctime>
#include <iomanip>
/*Найти в случайной матрице седловую точку если она там есть.
Седловой точкой называется элемент матрицы который является минимумом в строке и максимумом в столбце.*/
using std::cin;using std::cout;using std::setw;

const int N = 3, M = 3;

void printMat(int mat[][M]);
void randomMat(int mat[][M]);
bool isMinInStr(int a[],int min);
bool isMaxInCol(int mat[][M],int max,int col);
int saddlePoint(int mat[][M]);

int main()
{
	srand(time(0));
	setlocale(LC_ALL, "Russian");
	int mat[N][M]={7,8,9,5,4,3,1,2,2 /*10,8,8,5,4,3,1,2,2*/}; // это 2 примера для разных седловых.В рандомном массиве редко находится такая точка.

	//randomMat(mat);
	cout << " Исходнaя матрица:\n";
	printMat(mat);

	cout <<"Седловой точкой является "<<saddlePoint(mat) << "(Если 0,значит седловой точки нет в матрице)\n";

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
			mat[i][j] = rand() % 100+1; //числа от 1 до 100 
}

bool isMinInStr(int a[],int min)
{
	for (int i = 0;i < M;i++)
		if (a[i] < min) return false;
	return true;
}
bool isMaxInCol(int mat[][M], int max,int col)
{
	for (int i = 0;i < N;i++)
		if (mat[i][col] > max) return false;
	return true;
}
int saddlePoint(int mat[][M])
{
	for (int i = 0;i < N;i++)
		for (int j = 0;j < M;j++)
			if (isMinInStr(mat[i], mat[i][j])) if (isMaxInCol(mat, mat[i][j], j))  return mat[i][j];

	return 0;
}
