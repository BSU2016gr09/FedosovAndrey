#include <iostream>
#include <clocale>
#include<ctime>
//В массиве размера N, заполненного случ.числами от 0 до 10, подсчитать количество элементов, встречающихся более одного раза.
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
	cout << "Количество повторяющихся элементов = " << countOfRepeatingNumbers(a,N) << "\n";
	
	system("pause");
}


void randomArray(float a[], int N)
{
	float nom, denom;
	for (int i = 0;i < N;i++)
	{
		nom = rand() % 11;
		denom = rand() % 6+1;
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
	int count = 0;
	for (int i = 0;i < N - 1;i++)
	{
		if (a[i] >= 0)
			for (int j = i + 1;j < N;j++)
				if (a[i] == a[j] && a[j] != -1) //если нашло 2 повторяющихся элемента
					if (j == N - 1) count++;
					else {
						int k = j + 1;
						for (k;k < N;k++) // "удаляем" следующие вхождения
							if (a[k] == a[j]) a[k] = -1;

						count++;break;
					}    //увеличиваем счётчик и завершаем цикл;
	}
	return count;
}

