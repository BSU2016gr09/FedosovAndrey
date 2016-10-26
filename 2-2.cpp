#include <iostream>
#include <clocale>
#include<ctime>
 /*Массив целых чисел размера N проинициализировать случайными числами из промежутка от - N до N.
Циклически сдвинуть элементы массива вправо на 1 элемент(последний элемент станет первым, 1 - й станет 2 - м, 2 - й станет 3 - м и т.д.)
потом циклически сдвинуть элементы массива влево на 1 элемент(первый элемент станет последним, 2 - й станет 1 - м и т.д)*/
using std::cin;using std::cout;using std::swap;

void printArray(int a[], int N);
void randomArray(int a[], int N, int min, int max);
void shiftArrayToTheRight(int a[], int N);
void shiftArrayToTheLeft(int a[],int N);
const int N = 10;
int main()
{

	srand(time(0));
	setlocale(LC_ALL, "Russian");

	int a[N + 1];
	randomArray(a, N, -N, N);
	cout << "Исходный массив:\n";
	printArray(a, N);

	shiftArrayToTheRight(a, N);
	cout << "Сдвинутый вправо массив\n";
	printArray(a, N);

	shiftArrayToTheLeft(a, N);
	cout << "Сдвинутый влево массив\n";
	printArray(a, N);
	
	system("pause");
}
void shiftArrayToTheRight(int a[], int N) //Сдвиг массива вправо
{
	int last = a[N - 1];
	for (int i = N-1;i > 0;i--)
		a[i] = a[i - 1];
	a[0] = last;
}

void shiftArrayToTheLeft(int a[], int N) //Сдвиг массива влево
{
	int first = a[0];
	for (int i = 0;i < N-1;i++)
		a[i] = a[i + 1];
	a[N - 1] = first;
}

void randomArray(int a[], int N, int min, int max) // Случайное заполнение массива от min до max
{
	max++;
	for (int i = 0;i < N;i++)
		a[i] = rand() % (max - min) + min;
}

void printArray(int a[], int N)
{
	for (int i = 0;i < N;i++)
		cout << a[i] << " ";

	cout << "\n\n";}