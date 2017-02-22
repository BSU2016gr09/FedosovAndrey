#include <iostream>
#include <clocale>
#include<cmath>
#include<iomanip>
// Построить график функции y=sin(2x)/x на промежутке [-6,6] с шагом 0.1
using std::cin;using std::cout;using std::setw;
int main()
{
	setlocale(LC_ALL, "Russian");
	double x = -6, y;

	while (x <= 6)
	{
		y = (sin(2*x)/x)*60; //60 - случайное число для масштаба Мне не нравится слово "случайное"!!!! Надо рассчитать для конкретной функции...

		cout <<setw(y+40) << "*\n"; //40 - число для сдвига точки ближе к центру консоли
		x += 0.1;
	}

	system("pause");
}




