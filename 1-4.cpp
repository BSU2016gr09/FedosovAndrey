#include <iostream> 
using namespace std;
/*Элементы массива А(N), значения которых – простые числа, расположить в порядке возрастания, не нарушая порядка следования других элементов.*/
void enterArr(int* arr, int n);
void printArr(int* arr, int n);
void specialSort(int* arr, int n);
bool isPrime(int num);
int main()
{
	int n;
	cout << "Size of array=";
	cin >> n;
	int* arr1 = new int[n];

	cout << "Enter array\n";
	enterArr(arr1, n);
	specialSort(arr1, n);

	cout << "Array after sort = ";
	printArr(arr1, n);

	delete[] arr1;
	system("pause");

}
bool isPrime(int num)
{
	if (num < 2) return false;
	int i = 2;
	while ((i*i) <= num)
	{
		if (!(num%i)) return false;
		i++;
	}
	return true;

}

void enterArr(int* arr, int n)
{
	for (int i = 0;i < n;i++)
		cin >> *(arr + i);
}

void printArr(int* arr, int n)
{
	for (int i = 0;i < n;i++)
		cout << *(arr + i) << " ";
	cout << endl;
}

void specialSort(int* arr, int n)
{
	bool flag = true;
	while (flag)
	{
		flag = false;
		for (int i = 0;i < n-1;i++)
		{
			if (isPrime(arr[i]))
				for (int j = i + 1;j < n;j++)
					if (isPrime(arr[j]) && (arr[i] > arr[j])) 
						{ 
							swap(arr[i], arr[j]);
							flag = true; 
							break;
						}
		}
	}
}