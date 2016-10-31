#include <iostream>
#include <clocale>
#include<ctime>
/* Массив чисел размера N проинициализировать случайными числами из промежутка от -N до N.
Циклически сдвинуть (не переставить, а именно сдвинуть!
Т.е. нельзя использовать swap или аналоги надо использовать только присваивание a[i]=.....) элементы массива вправо на 1 элемент
(последний элемент станет первым, 1-й станет 2-м, 2-й станет 3-м и т.д.)
потом циклически сдвинуть элементы массива влево на 1 элемент (первый элемент станет последним, 2-й станет 1-м и т.д)*/

using std::cin;using std::cout;using std::swap;
void printArray(float a[], int N);
void randomArray(float a[], int N, int min, int max);
void shiftArrayToTheRight(float a[], int N);
void shiftArrayToTheLeft(float a[], int N);
const int N = 10;
int main()
{

	srand(time(0));
	setlocale(LC_ALL, "Russian");

	float a[N];

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
void shiftArrayToTheRight(float a[], int N) //Сдвиг массива вправо
{
	float last = a[N - 1];
	for (int i = N - 1;i > 0;i--)
		a[i] = a[i - 1];
	a[0] = last;
}

void shiftArrayToTheLeft(float a[], int N) //Сдвиг массива влево
{
	float first = a[0];
	for (int i = 0;i <N;i++)
		a[i] = a[i+1];
	a[N - 1] = first;
}

void randomArray(float a[], int N, int min, int max)
{
	float nom, denom;
	for (int i = 0;i < max;i++)
	{
		nom = (rand() % (max - min + 1) + min);
		denom = ((rand() % (max - min) + min)/5);
		if (denom < 0) denom -= 1.1;else denom += 1.1;
		a[i] = nom / denom;
	}
}


void printArray(float a[], int N)
{
	for (int i = 0;i < N;i++)
		cout << a[i] << " ";

	cout << "\n\n";
}