#include <iostream>
//посчитать интеграл некоторых функций
using namespace std;

typedef float(*funcs)(float);
typedef funcs pf;

float mysin(float x) { return sin(x); };
float sqrtX(float x) { return x*x; }
float mycos(float x) { return cos(x); }
float inverse(float x) { return 1 / (x*1.0); }

float integrate(float, float, pf, float);
void help();

int main() {
	funcs menu[] = { mysin,sqrtX,mycos,inverse};
	
	float a, b;
	int number;
	help();cin >> number;
	
	while (number){
		cout << "Type limits of the integration\n";cin >> a >> b;
		cout << "Type accuracy\n";float eps;cin >> eps;
		cout << integrate(a, b, menu[number], eps) << endl;
	
		cout << "Type a number again\n";
		cin >> number;
	} 

	system("pause");
}

void help() {
	cout << "Type 0 for exit\n";
	cout << "Type 1 for integration sin(x)\n";
	cout << "Type 2 for integration cos(x)\n";
	cout << "Type 3 for integration 1/x\n";
	cout << "Type 4 for integration x^2\n";
}
float integrate(float a, float b, pf func, float eps) {
	int n = 30;
	float res = 0, prevres = 0;
	do
	{
		prevres = res;
		res = 0;
		float width = abs((b - a) / n);
		for (float i = a; i <= b-width; i += width) {

			res += func(i)*width;
		}
		n*=2;
		
	} while (abstprevres-res) > eps);
	cout << "Final partioning = " << n << endl<<"Result = ";
	return res;
}
