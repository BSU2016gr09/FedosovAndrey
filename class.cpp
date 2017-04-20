#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

/*Доделать (учитывая мои комментарии в ваших репозиториях) свои проекты с дополнительной реализацией конструкторов, деструкторов 
(в которых, просто выдается сообщение, что он сработал) и операций =, +,- тех простейших классов, которые вы делали к 6.04
В main() надо не только объявить 2-3 объекта вашего класса, но и сделать пару-тройку указателей на объеты!!! 
Проинициализировать некоторые из них теми объетами, которые уже есть, а некоторые проинициализировать с помощью оператора, NEW.
После этого, в main выполнить пару-тройку действий с объектами и с указателями (присвоение, сумма, удаление...) чтобы показать, что все методы работают!*/
using namespace std;

class Linear {
	
public:
	
	Linear() {//конструктор по умолчанию
		cout << "Constructor1 is working\n";
		a = 0;b = 0;//Неправда,там раньше была ненужная инициализация x=0,
		//но корень уравнения верно считал ,что х может быть любым числом
		//так что я хорошо отучился в 6ом классе (почему это при a=b=0 получили х=0? вы что не учились в 6 классе????)
	}
	Linear(double a,double b) {//конструктор2  (Это не по умолчанию!!!!)
		cout << "Constructor2 is working\n";
		this->a = a;
		this->b = b;
	}
	~Linear() {//деструктор по умолчанию
		cout << "Destructor is working\n";
		
	}
	
	//оператор присваивания
	Linear& operator =(Linear &other) {
		cout << "Operator of equality is working\n";
		this->a = other.a;
		this->b = other.b;
		return *this;
	}
	//ну сложение коэфициентов получается,вроде адекватная идея(оператор сложения УРАВНЕНИЙ????? Как это сложить уравнение?)
	Linear& operator +(Linear addend) {
		cout << "Operator of addition is working\n";
		this->a += addend.a;
		this->b += addend.b;
		return *this;
	}
	//(оператор вычитания УРАВНЕНИЙ?????) 
	Linear& operator -(Linear subtrahend) {
		cout << "Operator of subtraction is working\n";
		this->a -= subtrahend.a;
		this->b -= subtrahend.b;
		return *this;
	}
	
	void setFirstCF(double a) {
		this->a = a;
	}
	void setSecondCF(double b) {
		this->b = b;
	}
	double getFirstCF() {
		return (*this).a;
	}
	double getSecondCF() {
		return (*this).b;
	}
	void printEquation() {
	if (b>=0)	cout << a << "x+" << b << "=0\n"; 
	else cout << a << "x" << b << "=0\n";
	}
	void root() {
		cout << "Finding root...\n";
		if (!a)
			if (!b) { cout << "Any number\n";return; }
			else { cout << "No solution\n"; return; }
		else			;
		cout << (double)(-b) / double(a) << endl;
	}

	private:
		double a, b;//исправил(а зачем хранить х? И чему он равен, если вы его не инициализируете????) 
};

void giveMemory(Linear * &tmp);
void delMem(Linear * &tmp);

void main() {
	cout << "EQUATION1" << endl;
	Linear eq1;
	eq1.printEquation();
	eq1.root();
	cout << endl << endl;

	cout << "EQUATION2" << endl;
	Linear eq2(4, 1);
	cout << "a=" << eq2.getFirstCF() << endl;
	cout << "b=" << eq2.getSecondCF() << endl;
	eq2.printEquation();
	eq2.root();
	cout << endl << endl;

	cout << "EQUATION3" << endl;
	Linear eq3;
	eq3.setFirstCF(5); //первый кф ставлю 5
	eq3=eq3+eq2; //инициализирую второй кф суммой с предыдущим уравнением
	cout << "a=" << eq3.getFirstCF() << endl;
	cout << "b=" << eq3.getSecondCF() << endl;
	eq2.setFirstCF(2); 
	eq2.setSecondCF(6);
	eq3=eq3-eq2; //работа разности
	eq3.printEquation();
	eq3.root();
	cout << endl << endl;

	cout << "EQUATION4" << endl;
	Linear* eq4 = &eq3;
	eq4->printEquation();
	eq4->root();
	cout << endl << endl;

	cout << "EQUATION5" << endl;
	Linear* eq5;
	giveMemory(eq5);
	(*eq5) = *eq4 + eq2;
	eq5->printEquation();
	eq5->root();
	
	
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
