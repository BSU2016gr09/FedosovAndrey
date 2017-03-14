#include <iostream>
#include<ctime>
using namespace std;
/*В массиве А(N,M) расположить строки, стоящие после строки с первым максимальным элементом матрицы,
в порядке возрастания количества чётных элементов в строке.*/
void give_memory(int**&, int, int);
void printArray(int **, int, int);
void initArray(int **, int, int);
void deleteMem(int** arr, int rows);
int strWithFirstMax(int** arr, int, int);
void specialSort(int**, int, int);
int amountOfEven(int*, int);
void main()
{
	srand(time(0));
	int rows, cols;
	cout << "Type rows and cols\n";
	cin >> rows >> cols;

	int** arr;
	give_memory(arr, rows, cols);
	initArray(arr, rows, cols);
	printArray(arr, rows, cols);

	specialSort(arr, rows, cols);

	printArray(arr, rows, cols);

	deleteMem(arr, rows);
	system("pause");
}
int strWithFirstMax(int** arr, int rows, int cols)
{
	int max = -100,nmax=-1;
	for (int i=0;i<rows;i++)
		for (int j=0;j<cols;j++)
			if (arr[i][j] > max) {
				max = arr[i][j]; nmax = i;
			}
	return nmax;
}
int amountOfEven(int* arr, int cols)
{
	int kol = 0;
	for (int i = 0;i < cols;i++)
		if (!(arr[i] % 2)&&(arr[i])) kol++;
	return kol;
}
void specialSort(int** arr, int rows, int cols)
{
	int str = strWithFirstMax(arr, rows, cols);
	if (str == rows - 2) return;
	bool flag = true;
	while (flag)
	{
		flag = false;
		for (int i = str + 1;i < rows - 1;i++)
			if (amountOfEven(arr[i], cols) > amountOfEven(arr[i + 1], cols)) {
				swap(arr[i], arr[i + 1]);
				flag = true;
			}
	}
}
void give_memory(int**&arr, int rows, int cols)
{
	try {
		arr = new int*[rows];
		for (int i = 0; i < rows; i++) 
			arr[i] = new int[cols];
	}
	catch (...) {
		cout << "Error" << endl;
	}
	for (int i = 0; i != rows; i++)
		arr[i] = new int[cols];
}
void printArray(int** arr, int rows, int cols)
{
	for (int i = 0; i != rows; i++) {
		for (int j = 0; j != cols; j++) {
			cout.width(3);
			cout << arr[i][j];
		}
		cout << endl;
	}
	cout << endl;
}
void deleteMem(int** arr, int rows)
{
	for (int i = 0; i < rows; i++) {
		delete[]  arr[i];
	}
	delete [] arr;
}
void initArray(int** arr, int rows, int cols)
{
	for (int i = 0; i != rows; i++)
		for (int j = 0; j != cols; j++)
			arr[i][j] = rand() % 100;
		
	cout << endl;
}