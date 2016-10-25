#include <iostream>
#include <clocale>
#include<ctime>
using std::cin;using std::cout;

void PrintElementsWithOddNumbers(int a[], int n) // Печать элементов с нечётными номерами
{
	int i = 1;
	while (i < n)
	{
		cout << a[i] << " ";i += 2;
	}
	cout << "\n";
}
void PrintElementsWithEvenNumbers(int a[], int n) // Печать элементов с чётными номерами
{
	int i = 0;
	while (i < n)
	{
		cout << a[i] << " ";i += 2;
	}
	cout << "\n";
}
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

const int n = 20;
int main()
{
	srand(time(0));
	setlocale(LC_ALL, "Russian");
	/* Объявить массив вещественных чисел размера N (число N объявить как константу).
	Проинициализировать значения элементов массива случайными числами из промежутка от -50 до 50.
	Вывести значения сначала элементов с нечетными коэффициентами (1-й, 3-й, 5-й,...) а затем - с четными.*/
	
	int  a[n];
	RandomArrayWithBorders(a, n, -50, 50);
	cout << "Исходный массив:";
	PrintArray(a, n);
	cout << "Элементы с нечётными номерами:";
	PrintElementsWithOddNumbers(a, n);
	cout << "Элементы с чётными номерами:";
	PrintElementsWithEvenNumbers(a, n);

	system("pause");
}





