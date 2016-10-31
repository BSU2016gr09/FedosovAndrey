#include <iostream>
#include <clocale>
#include<ctime>
/*1) Массив чисел размера N проинициализировать случайными числами из промежутка от 1 до N.
"Перевернуть" массив (последний элемент станет первым, 1-й станет последним, 2-й поменяется с предпоследним и т.д.) 
Внимательно проверьте случай нечетного N*/
using std::cin;using std::cout;using std::swap;
void printArray(float a[], int N);
void rollArray(float a[], int N);
void randomArray(float a[], int N, int min, int max);

const int N = 9;
int main()
{
	
	srand(time(0));
	setlocale(LC_ALL, "RussiaN");
	
	float a[N];
	randomArray(a,N,1, N);
	cout << "Исходный массив:\n";
	printArray(a, N);
	rollArray(a, N);
	cout << "Перевёрнутый массив\n";
	printArray(a, N);
	system("pause");
}
void randomArray(float a[], int N, int min, int max)
{
	float nom, denom;
	for (int i = 0;i < max;i++)
	{
		nom = (rand() % (max - min + 1) + min);
		denom = (rand() % (max - min) + (min + 0.1));

		if (nom >= denom) a[i] = nom / denom;else a[i] = denom / nom;

	}
}

void printArray(float a[], int N)
{
	for (int i = 0;i < N;i++)
		cout << a[i] << " ";

	cout << "\n\n";
}

void rollArray(float a[], int N)
{
	for(int i=0;i<N/2;i++)
	{
		swap(a[i], a[N-1-i]);i++;
	}
}