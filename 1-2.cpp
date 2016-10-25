#include <iostream>
#include <clocale>
using std::cin;using std::cout;using std::swap;

bool isNaturalAndFiveDigit(double n)//������������ ����� (����������� � �����������)
{
	if (n>9999 && n<100000 && n / floor(n) == 1) return true;else return false;
}


int MaxFromDigits(int n)  // ������������ �����,���������� �� ���� ����� n
{
	int answer, a[5], i = 0;
	bool flag = true;
	while (n > 0)
	{
		a[i] = n % 10;
		n /= 10;
		i++;
	}
	while (flag)
	{
		flag = false;i = 0;
		while (i < 4)
		{
			if (a[i] > a[i + 1]) { swap(a[i], a[i + 1]); flag = true; }
			i++;
		}
	}
	answer = a[4] * 10000 + a[3] * 1000 + a[2] * 100 + a[1] * 10 + a[0];
	return answer;

}
int main()
{
	setlocale(LC_ALL, "Russian");
	/*������������ ������ � ���������� ����������� ����������� �����, ������� ����������� � ���������� n,
	��������� ������������ �����, ��������� � ������� �� ����� ����� �� ���� ��������� ����� n, ���,
	����� ���������� ����� ��������� ������������ �� ���������.
	��������, ���� ������������ ��� ����� 22195, �� ��������� ������ ������� ����� 95221.*/
	double n;
	cout << "������� ����������� ����������� �����\nn=";
	cin >> n;
	if (isNaturalAndFiveDigit(n))
		cout << "������������ �����,��������� �� ���� ����� n = " << MaxFromDigits(n) << "\n";
	else cout <<"��� ����� �� �������� ��� ������� ������\n";

	system("pause");
}