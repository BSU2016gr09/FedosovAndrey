#include <iostream>
#include <clocale>
#include <cstdio>
#include <stdio.h>
/*Реализовать операции целочисленной арифметики на массивах размера MAX_SIZE = 100 (глобальная константа).
В цикле вычислить максимальное возможное на этих массивах число Фибоначчи
1, 1, 2, 3, ....и(для желающих получить 9 - 10 на экзамене) максимально возможный факториал.
Тех, кто самостоятельно реализует операцию деления выведите для последних трех чисел Фибоначчи их отношение*/

const int maxsize = 100;
int flag = 0;
using std::cin;using std::cout;using std::swap;

void initArray(int x[]);
void sumArrays(int a[], int b[], int rez[]);
void subtractArrays(int a[], int b[], int rez[]);
void multArrays(int a[], int b[], int rez[],int size1,int size2);
void divArrays(int a[], int b[], int rez[]); 
void charToNumber(char numb[], int a[],int size);
void printArray(int a[]);
bool isAGreaterThanB(int a[], int b[]); 
int maxFact(int a[], int b[], int rez[],int size1,int size2);
int maxFib(int a[], int b[], int rez[]);
void numberToArray(int num, int a[]);
int sizeOfArray(int a[]);
void copyArr(int a[], int b[]);
int main()
{
	setlocale(LC_ALL, "Russian");
	char numb[maxsize+1];
	int a[maxsize], b[maxsize], rez[maxsize],size1,size2;
	initArray(a);initArray(b);initArray(rez);

	cout << "Введите первое число\n";
	gets_s(numb);
	 size1 = strlen(numb);

	charToNumber(numb, a,size1);

	cout << "Введите второе число\n";
	gets_s(numb);
	size2 = strlen(numb);

	charToNumber(numb, b,size2);

	cout << "Сумма этих чисел = ";
	sumArrays(a, b, rez);
	printArray(rez);
	
	cout << "Разность этих чисел  = ";
	subtractArrays(a, b, rez);
	printArray(rez);

	cout << "Произведение этих чисел = ";
	multArrays(a, b, rez,size1,size2);
	printArray(rez);
	
	
	initArray(a);initArray(b);initArray(rez);a[0] = 1;
	cout << "Максимальный факториал до 100 цифр:\n";
	cout << "!" << maxFact(a, b, rez, 1, 1) << "=";
	printArray(rez);

	initArray(a);initArray(b);initArray(rez);a[0] = 1;b[0] = 2;
	cout << "Это "<< maxFib(a, b, rez) << "ое число Фибоначчи:\n";
	printArray(rez);


	system("pause");
}

void initArray(int x[])
{
	for (int i = 0;i < maxsize;i++)
		x[i] = 0;
}
void printArray(int a[])
{
	int i = maxsize - 1;
	while (i>=0&&a[i] <= 0) i--;
	if (i == -1) cout << 0;
	for (i;i > -1;i--)
		cout << a[i];
	
	cout << "\n\n";
}
void charToNumber(char numb[], int a[],int size)
{
	for (int i = 0;i <size;i++)
		a[i] = numb[size-i-1] - 48;
}


void sumArrays(int a[], int b[], int rez[])
{
	int tmp=0;
	for (int i = 0;i <maxsize;i++)
	{
		rez[i] = a[i] + b[i] + tmp;
		if (rez[i] > 9) { rez[i] -= 10;tmp = 1; }
		else tmp = 0;
	}
}
bool isAGreaterThanB(int a[], int b[])
{
	int i = maxsize - 1;
	while (i > -1 && a[i] == b[i])i--;

	if (a[i] < b[i]) return false;
	return true;
}
void subtractArrays(int a[], int b[], int rez[])
{
	int tmp = 0;
	if (!isAGreaterThanB(a, b)) { swap(a, b); cout << "-"; } //если первое число меньше второго,то ответ будет отрицательным
	for (int i = 0;i < maxsize;i++)
	{
		rez[i] = a[i] - b[i]-tmp;
		if (rez[i] < 0)
		{
			rez[i] += 10;
			tmp = 1;
		}
		else tmp = 0;
	}
	
}


void multArrays(int a[], int b[], int rez[],int size1,int size2)
{
	if (size1 + size2 >= maxsize) { flag = 1; return; }
	initArray(rez);
	for (int i = 0;i < size1;i++)
		for (int j = 0;j < size2;j++)
			rez[i + j] += (a[i] * b[j]);
	
	for (int i = 0;i < size1+size2+1;i++)
	{
		rez[i + 1] += rez[i] / 10;
		rez[i] %= 10;
		
	}
	
}
void numberToArray(int num, int a[])
{
	int i = 0;
	while (num > 0)
	{
		a[i] = num % 10;
		num /= 10;
		i++;
	}
}
int sizeOfArray(int a[])
{
	int i = maxsize - 1;
	while (i>0&&a[i] == 0)i--;
	return ++i;
}
void copyArr(int a[], int b[])
{
	for (int i = 0;i < maxsize;i++)
		a[i] = b[i];
}
int maxFact(int a[], int b[], int rez[],int size1,int size2)
{
	int i = 2;
	while (!flag)
	{
		initArray(b);
		numberToArray(i, b);

		size1 = sizeOfArray(a);
		size2 = sizeOfArray(b);

		multArrays(a, b, rez, size1, size2);
		copyArr(a, rez);
		i++;
	}
	i -= 2;
	return i;
}

int maxFib(int a[], int b[], int rez[])
{
	int count = 2;
	while (sizeOfArray(rez)<maxsize)
	{
		sumArrays(a, b, rez);
		copyArr(a, b);
		copyArr(b, rez);
		count++;
	}
	return count;	
}