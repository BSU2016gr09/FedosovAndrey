#include <iostream>
#include <clocale>
using std::cin;using std::cout;

bool isNatural(double n) 
{
	if (n > 0 && n / floor(n) == 1) return true;else return false;
}

int DigitSum(int n)  // ����� ���� ����� n
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
	/*������������ ������ � ���������� ����������� �����, ��������� ������������ �����,
	��������� � ������� �� ����� ����� ���� ��������� ������������� �����.*/
	double n;
	cout << "������� ����������� ����� \nn=";
	cin >> n;
	if (isNatural(n))
		cout << "����� ���� ����� n = " << DigitSum(n) << "\n";
	else cout << "��� ����� �� �������� ����������� \n";

	system("pause");
}


