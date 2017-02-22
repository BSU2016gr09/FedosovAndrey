#include <iostream> 
using namespace std;
//Расположить в порядке возрастания элементы массива А(N), начиная с k-го элемента.
void enterArr(int* arr, int n);
void printArr(int* arr, int n);
void qSort(int* arr, int l, int r);
void specialSort(int* arr, int n);
int main()
{
	int n;
	cout << "Size of array=";
	cin >> n;
	int* arr1 = new int[n]; //Где выделение и контроль динамической памяти??? Почему выделение не в отдельной функции???

	cout << "Enter array\n";
	enterArr(arr1, n);
	specialSort(arr1, n);

	printArr(arr1, n);

	delete[] arr1;
	system("pause");

}

void qSort(int* arr, int l, int r) //l=left,r=right (границы сортировки)
{
	int i, j, mid;
	i = l;j = r;mid = arr[(i + j) / 2];
	do
	{
		while (arr[i] < mid)i++;
		while (arr[j] > mid)j--;
		if (i <= j) swap(arr[i++], arr[j--]);

	} while (i < j);
	if (i < r) qSort(arr, i, r);
	if (j > l) qSort(arr, l, j);
}
void enterArr(int* arr, int n)
{
	for (int i = 0;i < n;i++)
		cin >> *(arr + i);
}

void printArr(int* arr, int n)
{
	cout << "Array = ";
	for (int i = 0;i < n;i++)
		cout << *(arr + i) << " ";
	cout << endl;
}

void specialSort(int* arr, int n)
{
	cout << "Index from which we will sort = ";
	int k;cin >> k;
	qSort(arr, k, n - 1);
}
