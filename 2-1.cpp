#include <iostream>
#include <clocale>
#include<ctime>
/*1) Массив целых чисел размера N проинициализировать случайными числами из промежутка от 1 до N.
"Перевернуть" массив (последний элемент станет первым, 1-й станет последним, 2-й поменяется с предпоследним и т.д.) 
Внимательно проверьте случай нечетного N*/
using std::cin;using std::cout;using std::swap;

void PrintArray(int a[], int N);
void RollArray(int a[], int N);
void RandomArray(int a[], int n, int min, int max);

const int N = 10;
int main()
{
	
	srand(time(0));
	setlocale(LC_ALL, "RussiaN");
	
	int a[N];
	RandomArray(a,N,1, N);
	cout << "Исходный массив:\n";
	PrintArray(a, N);
	RollArray(a, N);
	cout << "Перевёрнутый массив\n";
	PrintArray(a, N);
	system("pause");
}
void RandomArray(int a[], int N, int min, int max)
{
	max++;
	for (int i = 0;i < N;i++)
		a[i] = rand() % (max - min) + min;
}

void PrintArray(int a[], int N)
{
	for (int i = 0;i < N;i++)
		cout << a[i] << " ";

	cout << "\n\n";
}

void RollArray(int a[], int N)
{
	for (int i = 0;i < N / 2;i++)
	 swap(a[i], a[N - i - 1]);

}


