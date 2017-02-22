#include <iostream>
#include <clocale>
#include<ctime>
#include <iomanip>
using std::cin;using std::cout;using std::setw;
const int N = 10, M = 3;
//В матрице (n,m) найти те строки и вывести их номера, элементы которых образуют возрастающую последовательность.
void printMat(int mat[][M]);
void randomMat(int mat[][M]);
bool isIncreasing(int a[]);
void printNumbersOfIncreasingStrings(int mat[][M]);
int main()
{
	srand(time(0));
	setlocale(LC_ALL, "Russian");
	int mat[N][M];

	randomMat(mat);
	cout << " Исходнaя матрица:\n";
	printMat(mat);

	cout << "Номера строк,элементы которых образуют возрастающую последовательность:\n";
	printNumbersOfIncreasingStrings(mat);

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

bool isIncreasing(int a[])
{
	for (int i = 1;i < M;i++)
		if (a[i - 1] >= a[i]) return false;
	return true;
}
void printNumbersOfIncreasingStrings(int mat[][M])
{
	if (M == 1) return;
	for (int i = 0;i < N;i++)
		if (isIncreasing(mat[i])) cout << i << " ";
	cout << "\n";
		
}
