#include <iostream>
#include <clocale>
#include<ctime>
using std::cin;using std::cout;using std::swap;

void PositiveThenNegativeSort(int a[], int n) //Сортировать массив таким образом : сначала положительные,потом отрицательные
{
	int pointer = 0, i = 0;
	while (i < n)
	{
		if (a[i] > 0) { swap(a[i], a[pointer]);pointer++; }
		i++;
	}
}

void PrintArray(int a[], int n) // Печать массива
{
	for (int i = 0;i < n;i++)
		cout << a[i] << " ";
	cout << "\n\n";
}

void RandomArrayWithBorders(int a[], int n, int min, int max) // Заполняем случайно массив от min до max включительно
{
	max++;
	for (int i = 0;i < n;i++)
		a[i] = rand() % (max - min) + min;
}

const int n = 20;
int main()
{/*6)**для желающих
 Объявить массив А вещественных чисел размера N(число N объявить как константу).
 Проинициализировать значения элементов массива случайными числами из промежутка от - 50 до 50.
 "Отсортировать" массив А на месте(т.е.не используя вспомогательных массивов В и С)
 таким образом : положительные значения массива А переместить в начало, отрицательные переместить в конец массива А.
 (Проверить потом, что программа работает когда все элементы одного знака!)*/
	srand(time(0));
	setlocale(LC_ALL, "Russian");
	int a[20];
	RandomArrayWithBorders(a, n, -50,50);
	cout << "Исходный массив\n";
	PrintArray(a, n);
	PositiveThenNegativeSort(a, n);
	cout << "Отсортированный массив\n";
	PrintArray(a, n);

	system("pause");
}





