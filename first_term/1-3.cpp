#include <iostream>
#include <clocale>
#include<ctime>
using std::cin;using std::cout;

void PrintArray(int a[], int n) // Печать массива
{
	for (int i = 0;i < n;i++)
		cout << a[i] << " ";
	cout << "\n\n";
}
bool isNaturalAndUnder101(double n) //корректность ввода 
{
	if (n>0 && n / floor(n) == 1 && n <= 100) return true;else return false;
}
int NumberOfPositiveEvenNumbers(int a[], int n) // Количество чётных положительных чисел
{
	int count = 0;
	for (int i = 0;i < n;i++)
		if (a[i] > 0 && a[i] % 2 == 0) count++;
	return count;
}

void RandomArrayWithBorders(int a[], int n, int min, int max) // Заполняем случайно массив от min до max включительно
{
	max++;
	for (int i = 0;i < n;i++)
		a[i] = rand() % (max - min) + min;
}


int main()
{
	srand(time(0));
	setlocale(LC_ALL, "Russian");
	/*Пользователь вводит с клавиатуры натуральное число не большее 100, которое сохраняется в переменную n,
	проверить корректность ввода, создать массив из 10 случайных целых чисел из отрезка [-2n;n], вывести массив на экран в строку,
	подсчитать и и вывести на экран количество положительных чётных чисел в массиве.*/
	double n;
	cout << "Введите натуральное число не больше 100\nn=";
	cin >> n; int a[10];
	if (isNaturalAndUnder101(n))
	{
		RandomArrayWithBorders(a, 10, -2 * n, n);
		cout << "Полученный массив на отрезке[-" << 2 * n << ";" << n << "]:\n";
		PrintArray(a, 10);
		cout << "Количество положительных чётных чисел в массиве = " << NumberOfPositiveEvenNumbers(a, 10) << "\n";
	}
	else cout << n << " не подходит под условие задачи\n";

	system("pause");
}