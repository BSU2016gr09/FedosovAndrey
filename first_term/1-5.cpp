#include <iostream>
#include <clocale>
#include<ctime>
using std::cin;using std::cout;

void RandomArrayWithBorders(int a[], int n, int min, int max) // Заполняем случайно массив от min до max включительно
{
	max++;
	for (int i = 0;i < n;i++)
		a[i] = rand() % (max - min) + min;
}

void PrintArray(int a[], int n) // Печать массива
{
	for (int i = 0;i < n;i++)
		cout << a[i] << " ";
	cout << "\n\n";
}
void NegativeToArrayC(int a[], int n, int *c, int&j)  // отрицательные элементы в массив С
{
	for (int i = 0;i<n;i++)
		if (a[i] < 0) { c[j] = a[i]; j++; }
}

void PositiveToArrayB(int a[], int n, int b[], int&j) // Положительные элементы в массив B
{
	for (int i = 0;i<n;i++)
		if (a[i] > 0) { b[j] = a[i]; j++; }
}
const int n = 20;
int main()
{
	srand(time(0));
	setlocale(LC_ALL, "Russian");
	/* Объявить массив А вещественных чисел размера N (число N объявить как константу).
	Проинициализировать значения элементов массива случайными числами из промежутка от -50 до 50.
	"Разделить" массив А на два массива: положительные записать в массив В, отрицательные - в С.*/
	
	int  a[n], c[n], b[n], j = 0;
	RandomArrayWithBorders(a, n, -50, 50);
	NegativeToArrayC(a, n, c, j);
	cout << "Исходный массив:";
	PrintArray(a, n);
	cout << "Массив C отрицательных чисел исходного массива:";
	PrintArray(c, j);
	j = 0;
	PositiveToArrayB(a, n, b, j);
	cout << "Массив B положительных чисел исходного массива:";
	PrintArray(b, j);

	system("pause");
}





