#include <iostream>
#include <clocale>
#include<ctime>

/*Массив А чисел размера N проинициализировать случайными числами из промежутка от -N до N. 
Не используя функции из задачи 2-2 Написать функции (без swap и аналогов) циклического сдвига элементов массива вправо на k элементов
(1-й станет 1+k -ым, 2-й станет 2+k -ым и т.д.) и влево на k элементов. В main написать вызов этих функций для числа k, которое вводит пользователь.
(k может быть в частности =0, тогда сдвига нет, k=1 - задача аналогично предыдущей 2-2.cpp и т.д)
Надо придумать формулу вычисления нового индекса элемента чтобы обойтись одним циклом по массиву А., а не двумя вложенными циклами!*/

using std::cin;using std::cout;using std::swap;
void printArray(float a[], int N);
void randomArray(float a[], int N, int min, int max);
void shiftArrayToTheRight(float a[],float b[], int N,int k);
void shiftArrayToTheLeft(float a[],float b[], int N,int k);


const int N = 10;
int main()
{

	srand(time(0));
	setlocale(LC_ALL, "Russian");
	cout << "Введите число на которое нужно сдвинуть массив\n";
	float a[N], b[N] ;
	int k;
	cin >> k;
	randomArray(a, N, -N, N);
	cout << "Исходный массив:\n";
	printArray(a, N);

	shiftArrayToTheRight(a,b, N,k);
	cout << "Сдвинутый вправо массив\n";
	printArray(b, N);

	shiftArrayToTheLeft(b,a, N,k);
	cout << "Сдвинутый влево массив\n";
	printArray(a, N);

	system("pause");
}
void shiftArrayToTheRight(float a[],float b[], int N, int k) //сдвинуть вправо
{
	k = k%N;
		int nextI = 0;
		for (int i = 0;i < N;i++)
		{
			nextI = i + k;
			if (nextI > N - 1) nextI -= N;
			b[nextI] = a[i];
		}
}

void shiftArrayToTheLeft(float a[],float b[], int N, int k) //сдвинуть влево
{
	k = k%N;
		int nextI = 0;
		for (int i = 0;i < N;i++)
		{
			nextI = i - k;
			if (nextI < 0) nextI += N;
			b[nextI] = a[i];
		}
}

void randomArray(float a[], int N, int min, int max)
{
	float nom, denom;
	for (int i = 0;i < N;i++)
	{
		nom = (rand() % (max - min + 1) + min);
		denom = ((rand() % (max - min) + min) / 5);
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
