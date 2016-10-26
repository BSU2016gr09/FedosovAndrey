#include <iostream>
#include <clocale>
using std::cin;using std::cout;

bool isNatural(double n) 
{
	if (n > 0 && n / floor(n) == 1) return true;else return false;
}

int DigitSum(int n)  // Имя функции лучше с маленькой буквы!!!! Сумма цифр числа n
{
	int sum = 0;
	while (n > 0)
	{
		sum += n % 10;
		n /= 10;
	}
	return sum;

}
int main()
{
	setlocale(LC_ALL, "Russian");
	/*Пользователь вводит с клавиатуры натуральное число, проверить корректность ввода,
	вычислить и вывести на экран сумму цифр введённого пользователем числа.*/
	double n;
	cout << "Введите натуральное число \nn=";
	cin >> n;
	if (isNatural(n))
		cout << "Сумма цифр числа n = " << DigitSum(n) << "\n";
	else cout << "Это число не является натуральным \n";

	system("pause");
}


