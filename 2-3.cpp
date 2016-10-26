#include <iostream>
#include <clocale>
#include<ctime>

/*Массив А целых чисел размера N проинициализировать случайными числами из промежутка от - N до N.
Не используя функции из задачи 2 - 2 Написать функции циклического сдвинга элементы массива вправо на k элементов
(1 - й станет 1 + k - ым, 2 - й станет 2 + k - ым и т.д.) и влево на k элементов.
В main написать вызов этих функций для числа k, которое вводит пользователь.
Желательно придумать формулу вычисления нового индекса элемента чтобы обойтись одним циклом по массиву А.*/

using std::cin;using std::cout;using std::swap;

void printArray(int a[], int N);
void randomArray(int a[], int N, int min, int max);
void shiftArrayToTheRight(int a[], int N,int k);
void shiftArrayToTheLeft(int a[], int N,int k);
void rollArray(int a[],int left, int right);

const int N = 10;
int main()
{

	srand(time(0));
	setlocale(LC_ALL, "Russian");
	cout << "Введите число на которое нужно сдвинуть массив\n";
	int a[N], k;
	cin >> k;
	randomArray(a, N, -N, N);
	cout << "Исходный массив:\n";
	printArray(a, N);

	shiftArrayToTheRight(a, N,k);
	cout << "Сдвинутый вправо массив\n";
	printArray(a, N);

	shiftArrayToTheLeft(a, N,k);
	cout << "Сдвинутый влево массив\n";
	printArray(a, N);

	system("pause");
}
void shiftArrayToTheRight(int a[], int N, int k) //сдвинуть вправо
{
	k = k%N;
	if (k)
	{
		rollArray(a, 0, N - k - 1);
		rollArray(a, N - k, N - 1);
		rollArray(a, 0, N - 1);
	}
}

void shiftArrayToTheLeft(int a[], int N, int k) //сдвинуть влево
{
	k = k%N;
	if (k)
	{
		rollArray(a, 0, k - 1);
		rollArray(a, k, N - 1);
		rollArray(a, 0, N - 1);
	}
}

void rollArray(int a[], int left, int right) //перевернуть массив
{
	int i = left,j = right;
	while(i<j)
	{
		swap(a[i], a[j]);
		i++;j--;
	}
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

	cout << "\n\n";
}