#define _CRT_SECURE_NO_WARNINGS
//Улучшу ввод и хранение массива книг когда подключу файлы,пока просто показываю,что все функции готовы и работают
#include <iostream>
#include <vector>
#include<algorithm>
#include<ctime>

using namespace std;

class Book {
	friend ostream& operator<<(ostream&, const Book&);
	friend istream& operator >> (istream&, Book&);
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
		
		this->cipherTopic = this->cipherBook = this->year = this->amount = this->cost = 0;
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
		//cout << "Destructor is working\n";system("pause");
		delete[]name;
		delete[]surname;
		delete[]title;
		name = surname = title = nullptr;
	}

	void setTopic(){
		cipherTopic = rand() % 3 + 1;//1-novel;2-adventure;3-science;
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
	char* getAuthorsSurname() {
		char* srn;
		giveMemory(srn, 255);
		strcpy(srn, surname);
		return srn;

		delete[]srn;
		srn = nullptr;

	}
	char* getTitle() {
		char* ttl;
		giveMemory(ttl, 100);
		strcpy(ttl,title);
		return ttl;

		delete[]ttl;
		ttl= nullptr;

	}
	int getCost() {
		return cost;
	}
	int getTopic() {
		return cipherTopic;
	}
	int getYear() {
		return year;
	}
	int getAmount() {
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
bool cmpYear(Book&, Book&);
bool cmpSurname(Book&, Book&);
bool cmpTitle(Book&, Book&);
void deleteByAuthor(vector<Book>&, char*);
void deleteByYear(vector<Book>&, int );



void main() {
	srand(time(0));
	vector <Book> library;library.reserve(6);
	Book book1("Fedor", "Dostoevskiy", "Idiot", 2003, 52, 140), book2("Fedor", "Dostoevskiy", "Prestuplenie i nakazanie", 2017, 5, 1000), book3("Edmund", "Zverovich", "Analiz", 2007, 17, 523), book4("Lev", "Talstoy", "Voina i mir", 1980, 1, 666), book5, book6;
	cin >> book5;
	cin.ignore();
	//cin >> book6;
	library.push_back(book1);
	library.push_back(book2);
	library.push_back(book3);
	library.push_back(book4);
	library.push_back(book5);
	//library.push_back(book6);

	for (unsigned i = 0;i < library.size();i++) //не понял что такое шифр темы и шифр книги,поэтому не запаривался пока что
		library[i].setTopic();

	cout << "Current library:\n";
	printLibrary(library, cmpYear);
	cout << "Print up to topic 1(topic of each book is random[1-3]) after a 2001 year:\n";
	printBooksUpToTopicAndYear(library, 1, 2001);

	cout << "Printing books of Fedor Dostoevskiy:\n";
	printAuthorsBook(library, "Fedor Dostoevskiy");

	int mode;
	while (1) {
		system("pause");
		system("cls");
		cout << "How do you want to print the library?Sort by title(1), by author's surname(2),by year of publication(3)\n";
		cin >> mode;
		cout << "CURRENT LIBRARY:\n\n";
		switch (mode)
		{
		case 1: {printLibrary(library, cmpTitle);break;}
		case 2: {printLibrary(library, cmpSurname);break;}
		case 3: {printLibrary(library, cmpYear);break;}
		default: {cout << "Error in case\n";system("pause");}
		}
		int quit = 1;
		cout << "if you want to exit type 0\n";cin >> quit;
		if (!quit) break;
	}
	int year;
	while (1) {
		system("pause");
		system("cls");
		cout << "Remove Dostoevsky books(1),delete by year(2)\n";
		cin >> mode;
		switch (mode)
		{
		case 1: {deleteByAuthor(library, "Fedor Dostoevskiy");cout << "CURRENT LIBRARY:\n\n";printLibrary(library, cmpYear);break;}
		case 2: {cin >> year;deleteByYear(library, year);cout << "CURRENT LIBRARY:\n\n";printLibrary(library, cmpYear);break;}
		default: {cout << "Error in case\n"; system("pause");}
		}
		int quit = 1;
		cout << "if you want to exit type 0\n";cin >> quit;
		if (!quit) break;
	}
	
	system("pause");
}



ostream& operator<<(ostream& output, const Book& book)
{
	output << book.name << " " << book.surname << endl << book.title << "," <<"year "<<book.year << endl <<book.amount<<" books, "<< book.cost << "$ for each" << endl<<endl;
	return output;
}
istream& operator >> (istream& input, Book& book)
{
	cout << "Type description of a book by the following way:\nName\nSurname\nTitle\nYear Amount Cost\n\n";

	
	input.getline(book.name,100,'\n');
	
	input.getline(book.surname, 100,'\n');

	input.getline(book.title, 100,'\n');
	
	input >> book.year >>book.amount>> book.cost;
	cout << endl;
	
	return input;
}
void giveMemory(char*&str,int size)
{
	try {
		str = new char[size];
	}
	catch (...)
	{
		cout << "Allocation failed\n";
		system("pause");
	}
}
bool cmpYear(Book&b1, Book&b2) {return (b1.getYear() < b2.getYear());}
bool cmpSurname(Book&b1, Book&b2) { if (strcmp(b1.getAuthorsSurname(), b2.getAuthorsSurname()) < 0) return true;else return false; }
bool cmpTitle(Book&b1, Book&b2) { if (strcmp(b1.getTitle(), b2.getTitle()) < 0) return true;else return false; }

void printLibrary(vector<Book>&library,pf func) { //D
	sort(library.begin(), library.end(),func);
	int libraryCost=0, amount=library.size();
	for (auto it = library.begin(); it != library.end(); ++it) {
		cout << (*it);
		libraryCost += (*it).getCost();
	}
	cout << "There are " << amount << " books in library.The total cost of books (one copy) " << libraryCost << "$\n\n";
}
void printBooksUpToTopicAndYear(vector<Book>&library, int topic,int year) {// B
	for (auto it = library.begin(); it != library.end(); ++it)
		if((*it).getTopic()==topic&&(*it).getYear()>year) cout << (*it);

}
void printAuthorsBook(vector<Book>&library,char*author) { // C

	sort(library.begin(), library.end(), cmpYear);
	for (auto it = library.begin(); it != library.end(); ++it)
		if (!strcmp((*it).getAuthor(), author))  cout << (*it);
		
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