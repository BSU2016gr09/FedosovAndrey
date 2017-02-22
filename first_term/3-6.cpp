#include <iostream>
#include <clocale>
using std::cin;using std::cout;
/*В программе задано выражение представляющее собой обратную польскую запись, например,
char test[] = "1 2 + 4 × 3 +";в виде одноциферных чисел и знаков без пробелов.
Посчитать результат записи полагая что числа вещественные.*/
void push(char sym, double stack[], int&top, int N);
void pop(int&top);
void operation(char sym, double stack[], int&top);
double countPolishNotation(char plNotation[], double stack[], int&top, int N);

int main()
{
	char plNotation[] = { "825*+132*+4-/" };
	int N = strlen(plNotation), top = -1;
	double stack[100];
	setlocale(LC_ALL, "Russian");

	cout << plNotation << '=' << countPolishNotation(plNotation,stack,top,N)<<'\n';
	system("pause");
}

void operation(char sym,double stack[],int&top) //выполняем операцию
{
	
	switch (sym)
	{
	case '*':
	{stack[top-1] *= stack[top];break;}
	case '/':
	{stack[top-1] /= stack[top];break;}
	case '+':
	{stack[top-1] += stack[top];break;}
	case '-':
	{stack[top-1] -= stack[top];break;}
	default: {cout << "Неизвестная операция\n";break;}
	}
	pop(top);
}
void push(char sym, double stack[], int&top, int N) 
{
	if (top == N - 1) { cout << "Стек переполнен\n"; return; }
	stack[++top] = sym - 48;
}
void pop(int&top)
{
	if (top == -1) { cout << "Стек пуст\n";return; }
	top--;
}

double countPolishNotation(char plNotation[],double stack[],int&top, int N) //считаем польскую запись
{
	for (int i = 0;i < N;i++)
	{
		if ((int)plNotation[i] >= 48 && (int)plNotation[i] <= 57) //если встретили число
			push(plNotation[i], stack, top, N);//добавляем в стек
		else
			if (plNotation[i] == '*' || plNotation[i] == '/' || plNotation[i] == '+' || plNotation[i] == '-') //если встретили операцию
				operation(plNotation[i],stack, top); //выполняем операцию
	}
	return stack[top];
}