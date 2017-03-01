#include <iostream>
#include<cmath>
using namespace std;
void giveMemory(int*& arr, int n);
void congruential_method1(int* arr, int n);
void congruential_method2(int* arr, int n);
void printArr(int* arr, int n);
int coeff(int &a, int&c, int&m);
bool isPrime(int num);
bool isRelativelyPrime(int num1, int num2);

//Линейный конгруэнтный генератор псевдослучайных чисел
void main() {

	cout << "Size of array=";
	int n;
	cin >> n;
	int* arr;
	giveMemory(arr, n);

	congruential_method1(arr, n);
	cout << "Random a)\n";
	printArr(arr, n);
	congruential_method2(arr, n);
	cout << "Random b)\n";
	printArr(arr, n);
	delete[] arr;
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
bool isRelativelyPrime(int num1, int num2)
{
	int i = 2;
	while ((i < num1) && (i < num2))
	{
		if (!(num1%i) && !(num2%i)) return false;
		i++;
	}
	return true;
}
int coeff(int &a, int&c, int&m)
{
	int p = 2;
	for ( m = 305897;m < 900000;m += 3)
	{
		if (isPrime(m)) //для большего периода
		for (a = 564;a < 10000;a++)
		{
			for (p;p < sqrt(m);p++)
			{
				if (isPrime(p) && !(m%p) && !((a - 1) % p))
					if (!(m % 4)) if(!((a - 1) % 4)) return 1;else;
					else return 1;
			}
		}
	}
}
void printArr(int* arr, int n)
{
	for (int i = 0;i < n;i++)
		cout << *(arr + i) << " ";
	cout << endl;
}
void giveMemory(int*& arr, int n) {

	try {
		arr = new int[n];
	}
	catch (...) {
		cout << "Allocation failed\n";
		system("pause");
	}
}
void congruential_method1(int* arr, int n)
{
	//a
	cout << "Type any number(int)\n";
	cin >> *arr;
	int a = 4096,c=150889,m=714025;
	for (int i = 1;i < n;i++)
		*(arr+i) = (*(arr+i-1)*a + c) % m;

}
void congruential_method2(int* arr, int n)
{
	//b
	cout << "Type any number(int)\n";
	cin >> *arr;
	int a=10000,c=0,m=900002;

	//int o=coeff(a, c, m); перебор коэфициентов и с=0(мультипликативный конгруэнтный метод)

	for (int i = 1;i < n;i++)
		*(arr + i) = (*(arr + i - 1)*a + c) % m;

}