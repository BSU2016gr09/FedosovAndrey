#include <iostream>
//посчитать интеграл некоторых функций
using namespace std;

float mysin(float x) { return sin(x); };
float integrate(float, float, float(*func)(float), float);
float sqrtX(float x) { return x*x; }

typedef float(*func)(float);
int main() {
	
	float a, b;
	cout << "Type limits of the integration\n";cin >> a >> b;
	cout << "Type accuracy\n";float E;cin >> E;

	cout << "Intregral from sin(x): " << endl << integrate(a, b, mysin, E)<<endl;
	cout << "right result(watch the difference) = " << -cos(b)+ cos(a) << endl;

	cout << "Intregral from sqrtX: " << endl << integrate(a, b, sqrtX, E)<<endl;
	cout << "right result(watch the difference) = " << (b*b*b-a*a*a)/3 << endl; //интеграл от квадрата х=x^3/3 (a*a*a и b*b*b из-за простоты)


	system("pause");
}

float integrate(float a, float b, float(*func)(float), float E) {
	int n = 2;
	float rez = 0, oldrez = 0;
	do
	{
		oldrez = rez;
		rez = 0;
		float width = (b - a) / n;
		for (float i = a; i <= b; i += width) {
			rez += func(i)*width;
		}
		n++;
		
	} while (abs(oldrez-rez) > E);
	cout << "Final partioning = " << n << endl;
	return rez;
}
