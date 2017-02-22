#include <iostream> 
using namespace std;
/*Положительные элементы массива А(N) переставить в конец массива, сохраняя порядок следования. 
Отрицательные элементы расположить в порядке убывания. Дополнительный массив не использовать.*/
void enterArr(int* arr, int&negative, int n);
void printArr(int* arr, int n);
void qSort(int* arr, int l, int r);
void specialSort(int* arr,int negative, int n);
int main()
{
	int n,negative=0;
	cout << "Size of array=";
	cin >> n;
	int* arr = new int[n];

	cout << "Enter array\n";
	enterArr(arr,negative,n);

	specialSort(arr,negative,n);
	cout << "Array after sort = ";
	printArr(arr, n);

	delete[] arr;
	system("pause");

}

void qSort(int* arr, int l, int r) //l=left,r=right (границы сортировки)
{
	int i, j, mid;
	i = l;j = r;mid = arr[(i + j) / 2];
	do
	{
		while (arr[i] > mid)i++;
		while (arr[j] < mid)j--;
		if (i <= j) swap(arr[i++], arr[j--]);

	} while (i < j);
	if (i < r) qSort(arr, i, r);
	if (j > l) qSort(arr, l, j);
}
void enterArr(int* arr,int&negative, int n)
{
	for (int i = 0;i < n;i++)
	{
		cin >> *(arr + i);
		if (arr[i] < 0) negative++;
	}
}

void printArr(int* arr, int n)
{
	for (int i = 0;i < n;i++)
		cout << *(arr + i) << " ";
	cout << endl;
}

void specialSort(int* arr,int negative, int n)
{
	for (int i=n-1;i>0;i--)
		if (arr[i] < 0)
			for (int j = i - 1;j >= 0;j--)
				if (arr[j] > 0)
				{
					swap(arr[i], arr[j]);
					break;
				}
	qSort(arr, 0, negative-1);
}
