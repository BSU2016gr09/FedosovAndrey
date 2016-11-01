#include <iostream>
#include <clocale>
#include<ctime>
//В массиве размера N, заполненного случ.числами от 0 до 10, определить максимальную длину последовательности равных элементов.
using std::cin;using std::cout;
const int N = 15;
void randomArray(float a[], int N);
void printArray(float a[], int N);
int countOfRepeatingNumbers(float a[], int N);
int main()
{
	srand(time(0));
	setlocale(LC_ALL, "Russian");
	float a[N];
	randomArray(a, N);
	cout << "Исходный массив:\n";
	printArray(a, N);
	cout << "Максимальная длина последовательности равных элементов = " << countOfRepeatingNumbers(a, N) << "\n";

	system("pause");
}


void randomArray(float a[], int N)
{
	float nom, denom;
	for (int i = 0;i < N;i++)
	{
		nom = rand() % 11;
		denom = rand() % 6 + 1;
		a[i] = nom / denom;
	}
}
void printArray(float a[], int N)
{
	for (int i = 0;i < N;i++)
		cout << a[i] << " ";
	cout << "\n";
}
int countOfRepeatingNumbers(float a[], int N)
{
	int count,max = 1,i=0;
	while (i<N-1) //идём по массиву
	{
		count = 1;
		  while (i<N-1&&a[i]==a[i+1]) //считаем последовательность
		  {count++;i++; }
		  if (count > max) max = count;
		  i++;
	}
	return max;
}

