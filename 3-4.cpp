#include <iostream>
#include <clocale>
using std::cin;using std::cout;
/*Окончательно реализовать функции для работы стека на массиве. Сделать парные ф-ции push/pop для массива double и для массива char.
Создать стек чисел и стек символов. 
Продемонстрировать их работоспособность вызывая их из main. В частности, показать, что стек не переполняется.*/
const int N = 2;

void pushSym(char sym, char stackSym[], int&top1);
void pushNumb(double numb, double stackNumb[], int&top2);
void popSym(int&top1);
void popNumb(int&top2);
void printStackSym(char stackSym[]);
void printStackNumb(double stackNumb[]);
int main()
{
	char stackSym[N];
	double stackNumb[N];
	int top1 = -1, top2 = -1;
	setlocale(LC_ALL, "Russian");
	cout << "Размер стека = " << N << "\n";
	cout << "Добавим в стек  букву 'a':\n";
	pushSym('a', stackSym, top1);

	printStackSym(stackSym);
	cout << "Добавим в стек  букву 't':\n";
	pushSym('t', stackSym, top1);
	printStackSym(stackSym);

	cout << "Добавим в стек  букву 'e':\n";
	pushSym('e', stackSym, top1);
	printStackSym(stackSym);//в исходном коде N=2,так что буква "e" не добавится,т.к. стек не переполняется;

	cout << "Теперь удалим из стека последнюю букву и заменим её на букву 's'\n";
	popSym(top1);
	pushSym('s', stackSym, top1);
	printStackSym(stackSym);
	cout << "Очистим стек  \n";
	popSym(top1);popSym(top1);
	cout << "Если ещё раз попробовать удалить элемент,будет написано,что удалять нечего\n";
	popSym(top1);

	cout << "Добавим в стек число 5 :\n";
	pushNumb(5, stackNumb, top2);

	printStackNumb(stackNumb);
	cout << "Добавим в стек 8 :\n";
	pushNumb(8, stackNumb, top2);
	printStackNumb(stackNumb);

	cout << "Добавим в стек 10:\n";
	pushNumb(10, stackNumb, top2);
	printStackNumb(stackNumb);//в исходном коде N=2,так что число 10 не добавится,т.к. стек не переполняется;

	cout << "Теперь удалим из стека последнee число и заменим его на 1 \n";
	popSym(top2);
	pushNumb(1, stackNumb, top2);
	printStackNumb(stackNumb);
	cout << "Очистим стек  \n";
	popSym(top2);popSym(top2);
	cout << "Если ещё раз попробовать удалить элемент,будет написано,что удалять нечего\n";
	popSym(top2);

	system("pause");
}
void printStackNumb(double stackNumb[])
{
	cout << "Стек из чисел:\n";
	for (int i = 0;i < N;i++)
		cout << stackNumb[i] << " ";
	cout << "\n";
}
void printStackSym(char stackSym[])
{
	cout << "Стек из символов:\n";
	for (int i = 0;i < N;i++)
		cout << stackSym[i] << " ";
	cout << "\n";
}
void pushSym(char sym, char stackSym[], int&top1)
{
	if (top1 == N - 1) { cout << "Стек переполнен\n"; return; }
	stackSym[++top1] = sym;
}
void popSym(int&top1)
{
	if (top1 == -1) { cout << "Стек пуст\n";return; }
	top1--;
}
void pushNumb(double numb, double stackNumb[], int&top2)
{
	if (top2 == N - 1) { cout << "Стек переполнен\n"; return; }
	stackNumb[++top2] = numb;
}
void popNumb(int&top2)
{
	if (top2 == -1) { cout << "Стек пуст\n";return; }
	top2--;
}