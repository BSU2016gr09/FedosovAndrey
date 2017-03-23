#include <iostream>
//посчитать интеграл некоторых функций
using namespace std;
// Я все таки считаю, что выражение float(*func)(float) которое у тебя используется несколько раз выгоднее сделать typedef. ПЕРЕДЕЛАЙ и новый commit
float mysin(float x) { return sin(x); };
float integrate(float, float, float(*func)(float), float);
float sqrtX(float x) { return x*x; }
// добавь еще таких подинтегральных функций. Засунь их все в массив. И потом проси пользователя ввести НОМЕР функции. После этого вызывай расчет
typedef float(*func)(float);
int main() {
	
	float a, b;
	cout << "Type limits of the integration\n";cin >> a >> b;
	cout << "Type accuracy\n";float E;cin >> E;//стандартно называют eps

	cout << "Intregral from sin(x): " << endl << integrate(a, b, mysin, E)<<endl;
	cout << "right result(watch the difference) = " << -cos(b)+ cos(a) << endl;

	cout << "Intregral from sqrtX: " << endl << integrate(a, b, sqrtX, E)<<endl;
	cout << "right result(watch the difference) = " << (b*b*b-a*a*a)/3 << endl; //интеграл от квадрата х=x^3/3 (a*a*a и b*b*b из-за простоты)


	system("pause");
}

float integrate(float a, float b, float(*func)(float), float E) {
	int n = 2;
	float rez = 0, oldrez = 0; // а что такое oldrez? Неужели он "старый? Скорее надо "предыдущий"!!!!
	do
	{
		oldrez = rez;
		rez = 0;
		float width = (b - a) / n;
		for (float i = a; i <= b; i += width) { // у тебя ЛЕВЫЕ прямоугольники, раз начинаешь с i = a и вычисляешь func(i). Значит, неверно i <= b
			rez += func(i)*width;
		}
		n++;
		
	} while (abs(oldrez-rez) > E);
	cout << "Final partioning = " << n << endl;
	return rez;
}
