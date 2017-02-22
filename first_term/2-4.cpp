#include <iostream>
#include <clocale>
#include<ctime>
using std::cin;using std::cout;using std::swap;
/*4. Массив целых чисел размера N проинициализировать случайными числами из промежутка от 1 до N.
"Перетусовать" элементы массива двумя способами, предложенными на паре :
1) просто меняя местами случайные элементы 2) с использованием доп.массива
*/

const int N = 30;
void printArray(int a[], int N);
void randomArray(int a[], int N, int min, int max);
void randomChange(int a[], int N);
void randomShuffle(int a[], int b[], int N);
int main()
{
	int a[N],b[N];
	srand(time(0));
	setlocale(LC_ALL, "Russian");
	
	randomArray(a, N, 1,N);
	cout << "Исходный массив:\n";
	printArray(a, N);
	randomChange(a, N);
	cout << "Разбросанный массив1:\n";
	printArray(a, N);
	randomShuffle(a, b, N);
	cout << "Разбросанный массив2:\n";
	printArray(b, N);

	system("pause");
}


void randomShuffle(int a[], int b[], int N)
{
	int j;
	for (int i = 0;i < N;i++)
	{
		j = rand() % N;
		if (a[j]) { b[i] = a[j]; a[j] = 0; }
		else {
			while (!a[j])
			{
				srand(rand());//зачем это?????
				j = rand() % N;
			}
			b[i] = a[j];a[j] = 0;
		}
	}
}
void randomChange(int a[], int N)
{
	int j;
	for (int i = 0;i < N;i++)
	{
		j = rand() % N;
		swap(a[i], a[j]);
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

	cout << "\n\n";}
