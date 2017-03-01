#include <iostream> 
#include<ctime>
#include<cmath>
using namespace std;
/*Даны точки плоскости своими координатами в виде двух одномерных массивов.
Точки плоскости рассортировать по возрастанию расстояния до прямой ax + by + c = 0.*/
void randomArr(int* arr, int n);
void printPoints(int* arr1,int* arr2, int n);
void specialSort(double* arr_dist, int* arr1, int* arr2, int l, int r);
double dist(int x, int y, int a, int b, int c);
void countDistances(int* arr1, int* arr2,double* arr_dist,int n);
void give_memory(int*& arr1, int*& arr2, double*& arr_dist, int n);
int main()
{
	srand(time(0));
	int n;
	cout << "Size of arrays=";
	cin >> n;
	int* arr1;
	int* arr2;
	double* arr_dist;
	give_memory(arr1, arr2, arr_dist, n);
	randomArr(arr1, n);
	randomArr(arr2, n);
	cout << "Points:\n";
	printPoints(arr1,arr2, n);
	countDistances(arr1, arr2, arr_dist, n);

	/*for (int i = 0;i < n;i++)
		cout << arr_dist[i] << "; ";
	cout << endl;*/

	//цикл для проверки сортировки(выводит расстояния от точек до прямой)


	specialSort(arr_dist, arr1, arr2, 0, n - 1);
	cout << "Points after sort\n";
	printPoints(arr1, arr2, n);
	delete[] arr1;
	delete[] arr2;
	delete[] arr_dist;
	system("pause");

}
void give_memory(int*& arr1, int*& arr2,double*& arr_dist, int n) {

	try {
		arr1 = new int[n];
		arr2 = new int[n];
		arr_dist = new double[n];
	}
	catch (...) {
		cout << "Allocation failed\n";
		system("pause");
	}
}
double dist(int x, int y, int a, int b, int c)
{
	return abs(a*x + b*y + c)*1.0 / sqrt(a*a + b*b)*1.0;
}

void randomArr(int* arr, int n)
{
	for (int i = 0;i < n;i++)
		*(arr + i)=rand()%20;
}

void printPoints(int* arr1,int* arr2, int n)
{
	for (int i = 0;i < n;i++)
		cout << "(" << *(arr1 + i) << ", " << *(arr2 + i) << ")" << "; ";
	cout << endl;
}
void countDistances(int* arr1, int* arr2, double* arr_dist, int n)
{
	int a, b, c;
	cout << "Enter 'a' 'b' 'c' for the equation ax+by+c=0\n";
	cout << "a=";cin >> a;
	cout << "b=";cin >> b;
	cout << "c=";cin >> c;

	for (int i = 0;i < n;i++)
		*(arr_dist + i) = dist(*(arr1 + i), *(arr2 + i), a, b, c);
}

void specialSort(double* arr_dist,int* arr1,int* arr2, int l, int r)
{
	int i, j;
	double mid;
	i = l;j = r;mid = arr_dist[(i + j) / 2];
	do
	{
		while (arr_dist[i] < mid)i++;
		while (arr_dist[j] > mid)j--;
		if (i <= j)
		{
			swap(arr_dist[i], arr_dist[j]);
			swap(arr1[i], arr1[j]);
			swap(arr2[i], arr2[j]);
			i++;j--;
		}

	} while (i < j);
	if (i < r) specialSort(arr_dist,arr1,arr2, i, r);
	if (j > l) specialSort(arr_dist,arr1,arr2, l, j);
	
}
