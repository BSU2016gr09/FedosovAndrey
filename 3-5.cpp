#include <iostream>
#include <clocale>
using std::cin;using std::cout;
/*В программе задана последовательность из открывающихся и закрывающихся скобочек 3 видов.
Например, char test[] = "(aa[b(c)ddd]e{ee})"; Проверить правильность растановки скобок в этом выражении c помощью стека в котором хранятся char.
Чтобы использовать очередной элемент строки(aa[b(c)ddd]e{ ee }) достаточно написать test[0], test[1] ит..д.т.е.в цикле test[i].*/
void push(char bracket, char stack[],int&top,int N);
void pop(int&top);
bool checkBrackets(char brackets[],char stack[],int&top,int N);
int main()
{
	char brackets[] = { "(aa[b(c)ddd]e{ee})" }, stack[100]; 
	int N = strlen(brackets), top = -1;
	setlocale(LC_ALL, "Russian");
	if (checkBrackets(brackets,stack, top, N)) cout << "Скобки расставлены верно\n";else cout << "Скобки расставлены неверно\n";
	system("pause");
}

void push(char bracket, char stack[], int&top, int N) 
{
	if (top == N-1) { cout << "Стек переполнен\n"; return; }
	stack[++top] = bracket;
}
void pop(int&top)
{
	if (top == -1) { cout << "Стек пуст\n";return; }
	top--;
}

bool checkBrackets(char brackets[],char stack[],int&top, int N)//проверка расстаовки скобок
{
	for (int i = 0;i < N;i++)
	{
		if (brackets[i] == '(' || brackets[i] == '[' || brackets[i] == '{') //если встретилась открывающаяся,то добавляем в стек
			push(brackets[i], stack, top, N);
		else
			if ((brackets[i] == ')'&&stack[top] == '(') || (brackets[i] == ']'&&stack[top] == '[') || (brackets[i] == '}'&&stack[top] == '{'))
				pop(top); //если встретилась закрывающаяся и последняя в стеке открывающаяся такого же типа
			else
				if (brackets[i] == ')' || brackets[i] == ']' || brackets[i] == '}') 
					return false; //если тип открывающейся скобки в стеке не совпадает с типом закрывающейся,то расстановка неверна
	}
	if (top == -1) return true;else return false;
}