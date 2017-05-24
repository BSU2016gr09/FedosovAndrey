#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include<algorithm>
#include<fstream>
#include<ctime>
/*
Правило записи книги во входной файл:

Имя автора
Фамилия автора
Название книги
Год издания Количество экземпляров Стоимость одного

*/
using namespace std;
ifstream in("input.txt",ios_base::in);
ofstream out("output.txt", ios_base::out | ios_base::trunc);
void checkFiles();

class Book {
	friend ofstream& operator<<(ofstream&, const Book&);
	friend ifstream& operator >> (ifstream&, Book&);
public:
	friend void giveMemory(char*&str, int size);	
	Book(){//конструктор по умолчанию
		this->cipherTopic = this->cipherBook = this->year = this->amount = this->cost = 0;
		this->name = this->surname = this->title = nullptr;
		giveMemory(this->name, 100);giveMemory(this->surname, 100);giveMemory(this->title, 100);
	}
	Book(char* name, char*surname, char*title, int year,int amount,int cost) {//конструктор с параметрами
		this->cipherTopic = this->cipherBook = this->year = this->amount = this->cost = 0;
		this->name = this->surname = this->title = nullptr;
		giveMemory(this->name, 100);giveMemory(this->surname, 100);giveMemory(this->title, 100);
		strcpy(this->name, name);strcpy(this->surname, surname);strcpy(this->title,title);
		this->year = year;
		this->amount = amount;this->cost = cost;
	}
	Book(const Book &obj) {//конструктор копии
		
		this->cipherTopic = obj.cipherTopic;this->cipherBook = obj.cipherBook;this->year = obj.year;
		this->amount = obj.amount; this->cost = obj.cost;
		this->name = this->surname = this->title = nullptr;
		giveMemory(this->name, 100);giveMemory(this->surname, 100);giveMemory(this->title, 100);
		strcpy(this->name, obj.name);strcpy(this->surname, obj.surname);strcpy(this->title, obj.title);
		this->year = obj.year;
		this->amount = obj.amount;this->cost = obj.cost;

	}
	Book& operator=(Book &other) {
		this->cipherTopic = other.cipherTopic; this->cipherBook = other.cipherBook;
		strcpy(this->name,other.name);strcpy(this->surname,other.surname);strcpy(this->title,other.title);
		this->year =other.year;
		this->amount =other.amount;this->cost =other.cost;
		return *this;
	}
	~Book(){
		//out << "Destructor is working\n";system("pause");
		delete[]name;
		delete[]surname;
		delete[]title;
		name = surname = title = nullptr;
	}

	void setTopic(){
		cipherTopic = rand() % 3 + 1;
	}
	/*void setYear(int year){
		this->year = year;
	}
	void setAmount(int amount) {
		this->amount = amount;
	}
	void setCost(int cost) {
		this->cost = cost;
	}*/
	char* getAuthor() {
		char* fullName;
		giveMemory(fullName, 255);
		strncpy(fullName, name,strlen(name)+1);
		fullName[strlen(name)] = ' ';
		fullName[strlen(name)+1] = '\0';
		strcat(fullName,surname);
		return fullName;

		delete[]fullName;
		fullName = nullptr;

	}
	char * getName()const {
		return name;
	}
	char* getSurname()const {
		return surname;

	}
	char* getTitle()const {
		return title;

	}
	int getCost() const{
		return cost;
	}
	int getTopic() const{
		return cipherTopic;
	}
	int getYear() const{
		return year;
	}
	int getAmount()const {
		return amount;
	}
private:
	int year, cipherTopic, cipherBook,amount,cost;
	char *name, *surname, *title;
};

typedef bool(*func)(Book&b1, Book&b2);
typedef func pf;

void printLibrary(vector<Book>&,pf);
void printBooksUpToTopicAndYear(vector<Book>&, int,int);
void printAuthorsBook(vector<Book>&,char*);
void deleteByAuthor(vector<Book>&, char*);
void deleteByYear(vector<Book>&, int );
bool cmpYear(Book&, Book&);
bool cmpSurname(Book&, Book&);
bool cmpTitle(Book&, Book&);
void workWithLibrary(vector<Book>);


void main() {
	srand(time(0));
	checkFiles();
	vector <Book> library;library.reserve(10);
	Book book;
	for(int i=0;i<5;i++){
		in >> book;
	    in.ignore();
		library.push_back(book);
	}
	for (unsigned i = 0;i < library.size();i++) //не понял что такое шифр темы и шифр книги,поэтому не запаривался пока что
		library[i].setTopic();

	
	workWithLibrary(library);
	system("pause");
}



ofstream& operator<<(ofstream& output,const Book& book)
{
	output << book.getName() << " " << book.getSurname() << endl << book.getTitle() << "," << "year " << book.getYear()
		<< endl << book.getAmount() << " books, " << book.getCost() << "$ for each" << endl<<endl;
	return output;
}
ifstream& operator >> (ifstream& input, Book& book)
{
	input.getline(book.name,100,'\n');
	input.getline(book.surname, 100, '\n');
	input.getline(book.title, 100,'\n');
	
	input >> book.year >>book.amount>> book.cost;
	return input;
}
void giveMemory(char*&str,int size)
{
	try {
		str = new char[size];
	}
	catch (...)
	{
		out << "Allocation failed\n";
		system("pause");
	}
}
bool cmpYear(Book&b1, Book&b2) {return (b1.getYear() < b2.getYear());}
bool cmpSurname(Book&b1, Book&b2) { if (strcmp(b1.getSurname(), b2.getSurname()) < 0) return true;else return false; }
bool cmpTitle(Book&b1, Book&b2) { if (strcmp(b1.getTitle(), b2.getTitle()) < 0) return true;else return false; }

void printLibrary(vector<Book>&library,pf func) { //D
	out << "LIBRARY SORTED:\n";
	sort(library.begin(), library.end(),func);
	int libraryCost=0, amount=library.size();
	for (auto it = library.begin(); it != library.end(); ++it) {
		out << (*it);
		libraryCost += (*it).getCost();
	}
	out << "There are " << amount << " books in library.The total cost of books (one copy) " << libraryCost << "$\n\n";
}
void printBooksUpToTopicAndYear(vector<Book>&library, int topic,int year) {// B
	out << "LIBRARY(GIVEN TOPIC AFTER GIVEN YEAR\n";
	for (auto it = library.begin(); it != library.end(); ++it)
		if((*it).getTopic()==topic&&(*it).getYear()>year) out << (*it);
}
void printAuthorsBook(vector<Book>&library,char*author) { // C
	out << "Books of " << author << endl;
	sort(library.begin(), library.end(), cmpYear);
	for (auto it = library.begin(); it != library.end(); ++it)
		if (!strcmp((*it).getAuthor(), author))  out << (*it);	
}
void deleteByAuthor(vector<Book>&library, char*author) {
	for (auto it = library.begin(); it != library.end();) 
		if (!strcmp((*it).getAuthor(), author))  it=library.erase(it);
		else ++it;
}
void deleteByYear(vector<Book>&library, int year) {
	for (auto it = library.begin(); it != library.end();)
		if ((*it).getYear()==year) it = library.erase(it);
		else ++it;
}
void checkFiles()
{
	if (!in.is_open()) {
		cout << "error input.txt!\n";
		system("pause");
		exit(0);
	}
	if (!out.is_open())
	{
		cout << "error output.txt !\n";
		system("pause");
		exit(0);
	}
}

void workWithLibrary(vector<Book>library) {
	int stop, type, rem, print,year;
	char*author;
	giveMemory(author, 200);
	while (1) {
		cout << "Select type of work:\n";
		cout << "Print(1)\nRemoving(2)\n";
		cin >> type;
		switch (type)
		{
		case 1: {
			cout << "Select type of printing:\n"; //не добавлял сюда печать по теме после года издания,
			cout << "Print books of the given author(1)\nPrint books sorting by year(2), author's surname(3), book title(4)\n";
			cin >> print;
			switch (print)
			{
			case 1: {
				cout << "Enter fullname of author,whose books you want to print:\n";
				cin.ignore();
				cin.getline(author, 200);
				printAuthorsBook(library, author);
				break;
			}
			case 2: { printLibrary(library, cmpYear); break;}
			case 3: { printLibrary(library, cmpSurname); break; }
			case 4: { printLibrary(library, cmpTitle); break;}
			default: {cout << "Error in switch printing\n";system("pause");exit(0);break;}
			}
			break;
		}
		case 2: {
			cout << "Select type of removing:\n";
			cout << "By author(1)\nBy year(2)\n";
			cin >> rem;
			switch (rem)
			{
			case 1: {
				cout << "Enter fullname of author,whose books you want to delete:\n";
				cin.ignore();
				cin.getline(author, 200);
				deleteByAuthor(library, author);
				break;
			}
			case 2: {
				cout << "Enter the year of publication of the books you want to delete:\n";
				cin >> year;
				deleteByYear(library, year);
				break;
			}
			default: {cout << "Error in switch removing\n";system("pause");exit(0);break;}
			}
		}
		default: { break;}
		}
		cout << "If you want to stop your work enter now \'0\',else enter any number\n";cin >> stop;
		if (!stop) return;
	}
	delete[] author;
}