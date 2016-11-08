#include <iostream>
#include <clocale>
using std::cin;using std::cout;
/*В программе задано выражение представляющее собой обратную польскую запись, например,
char test[] = "124 222 + 43 × 31 +";в виде МНОГОЦИФЕРНЫХ чисел и знаков без пробелов.
Посчитать результат записи полагая что числа вещественные.*/

double countPolishNotation(char plNot[], int N);
void updateNotation(char plNot[], int N, int&len);
void operation(double&number1, double&number2, char op);
int main()
{
	char plNot[] = { "4 2 / 43 * 31 +" };
	int N = strlen(plNot);
	setlocale(LC_ALL, "Russian");

	cout << plNot << "=";
	cout << countPolishNotation(plNot, N);

	system("pause");
}

void updateNotation(char plNot[], int N, int&len)
{
	char temp[100];
	int i = 0, j = 0;
	while (plNot[i++] != ' ') temp[j++] = ' ';

	len = j - 1;
	while (i < N)
		temp[j++] = plNot[i++];

	for (i = 0;i < N;i++)
		plNot[i] = temp[i];
}
void operation(double&number1, double&number2, char op)
{
	switch (op)
	{
	case '*':
	{number1 *= number2;break;}
	case '+':
	{number1 += number2;break;}
	case '/':
	{number1 /= number2;break;}
	case '-':
	{number1 += number2;break;}
	default: {cout << "Неизвестная операция\n";break;}
	}
}
double countPolishNotation(char plNot[], int N)
{
	double number1, number2;
	int i = 0, len;
	number1 = atof(plNot);
	updateNotation(plNot, N, len);

	while (i < N)
	{
		if ((int)plNot[i] >= 48 && (int)plNot[i] <= 57) //если встретили число 
		{
			number2 = atof(plNot);
			updateNotation(plNot, N, len);
			i += len - 1;

		}
		else
			if (plNot[i] == '*' || plNot[i] == '+' || plNot[i] == '-' || plNot[i] == '/') //если встретили операцию
			{
				operation(number1, number2, plNot[i]);

			}
		i++;
	}
	return number1;
}




