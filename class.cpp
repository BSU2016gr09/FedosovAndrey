#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

/*Доделать (учитывая мои комментарии в ваших репозиториях) свои проекты с дополнительной реализацией конструкторов, деструкторов 
(в которых, просто выдается сообщение, что он сработал) и операций =, +,- тех простейших классов, которые вы делали к 6.04
В main() надо не только объявить 2-3 объекта вашего класса, но и сделать пару-тройку указателей на объеты!!! 
Проинициализировать некоторые из них теми объетами, которые уже есть, а некоторые проинициализировать с помощью оператора, NEW.
После этого, в main выполнить пару-тройку действий с объектами и с указателями (присвоение, сумма, удаление...) чтобы показать, что все методы работают!*/
using namespace std;
/*Создать класс линейных уравнений с использованием динамической памяти(выбор количества неизвестных)*/
class Linear {
	
public:
	
	Linear() {//конструктор по умолчанию
		cout << "Constructor1 is working\n";
		coeff = new int[2];
		coeff[0] = 0;coeff[1] = 0;
		size = 2;
	
	}
	Linear(int size) {//конструктор по умолчанию
		cout << "Constructor2 is working\n";
		if (size > 26) { cout << "Size set on 26(" << size << " is more than maxsize(no more letters))\n"; size = 26; }
		coeff = new int[size];
		for (int i = 0;i < size;i++) coeff[i] = 0;
		this->size = size;
	
	}
	~Linear() {//деструктор по умолчанию
		cout << "Destructor is working\n";system("pause");
		delete[] coeff;
		coeff = nullptr;
	}
	
	//оператор присваивания
	Linear& operator =(Linear &other) {
		cout << "Operator of equality is working\n";
		int tempSize = (other.size>this->size ? this->size : other.size); //берём меньший размер,чтоб не присваивать в несуществующие ячейки
		for (int i = 0;i < tempSize;i++)
		this->coeff[i] = other.coeff[i];
		return *this;
	}
	//оператор сложения
	Linear& operator +(Linear&addend) {
		int tempSize = (addend.size>this->size ? this->size : addend.size); //берём меньший размер,чтоб не прибавлять к несуществующим кф
		cout << "Operator of addition is working\n";
		for (int i = 0;i < tempSize;i++)
			this->coeff[i] +=addend.coeff[i];
		return *this;
	}
	//оператор вычитания
	Linear& operator -(Linear&subtrahend) {
		int tempSize = (subtrahend.size>this->size?this->size:subtrahend.size); //берём меньший размер,чтоб не отнимать от несуществующих кф
		for (int i = 0;i < tempSize;i++)
			this->coeff[i] -= subtrahend.coeff[i];
		return *this;
	}

	void setCoeffs() {
		cout << "Type coefficients\n";
		for (int i = 0;i < size;i++) {
			cout << char(i + 97) << "=";
			cin >> coeff[i];
		}
		cout << endl;
	}
	void getCoeffs() {
		for (int i = 0;i < size;i++) 
			cout << char(i + 97) << "=" << coeff[i] << endl;
	}
	void print() {
		int letter = 97;
		cout << coeff[0] << char(letter++);
		for (int i = 1;i < size;i++) {
			cout <<"*"<<coeff[i] <<char(letter);
			letter++;
		}
		cout << "=0\n";
		
	}

	private:
		int*coeff;
		int size;
};


void giveMemory(Linear * &tmp);
void delMem(Linear * &tmp);

void main() {
	cout << "EQ1:\n";
	Linear eq1;
	eq1.setCoeffs();
	eq1.print();
	cout << endl;

	cout << "EQ2:\n";
	cout << "How many unknows do you want?\n";
	int unknows;cin >> unknows;
	Linear eq2(unknows);
	eq2.getCoeffs();
	eq2.setCoeffs();
	cout << "Eq2 before adding:\n";
	eq2.print();
	eq2 = eq2 + eq1;
	cout << "Eq2 after\n";
	eq2.print();
	cout << endl;
	

	cout << "EQ3:\n";
	Linear eq3(4);
	eq3.setCoeffs();
	cout << "Before substraction:\n";
	eq3.print();
	eq3 = eq1 - eq2;
	cout << "After:\n";
	eq3.print();
	cout << endl;

	cout << "EQ4:\n";
	Linear *eq4 = &eq2;
	eq4->print();
	cout << endl;

	cout << "EQ5:\n";
	Linear *eq5;
	giveMemory(eq5);
	cout << "Before substraction:\n";
	eq5->print();
	*eq5 = *eq5 - *eq4;
	cout << "After:\n";
	eq5->print();
	cout << endl;

	system("pause");
}
void giveMemory(Linear * &tmp) {
	try {
		tmp = new Linear;
	}
	catch (...) {
		cout << "Allocation fault\n";
		system("pause");
	}
}

void delMem(Linear * &tmp) {
	delete tmp;
	tmp = nullptr;
}
