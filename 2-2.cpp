#include <iostream> 
using namespace std;
//XORShift
void printArr(int* arr, int n);
void giveMemory(int*& arr, int n);
void randomArr(int* arr, int n);
int main()
{
	int n;
	cout << "Size of array=";
	cin >> n;
	int* arr;
	giveMemory(arr, n);

	
	randomArr(arr, n);
	cout << "Arr=";
	printArr(arr, n);

	delete[] arr;
	system("pause");

}
void giveMemory(int*& arr, int n)
{
	try {
		arr = new int[n];
	}
	catch (...)
	{
		cout << "Allocation failed\n";
		system("pause");
	}
}

void printArr(int* arr, int n)
{
	for (int i = 0;i < n;i++)
		cout << *(arr + i) << " ";
	cout << endl;
}
void randomArr(int* arr, int n)
{
	int tmp = 0, a = 13, b = 15, c = 5;
	cout << "Type any number\n";
	cin >> *arr;
	for (int i = 0;i < n-1;i++)
	{
		tmp ^= arr[i] << a;
		tmp ^=tmp >> b;
		arr[i+1]^=tmp << c;
	}
}