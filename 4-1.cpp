#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<fstream>
#include <map>
#include <string>//я готов за это отхватить))
//В тексте определить частоту вхождения слов. Вывести "словарь" текста (не обязательно в алфавитном порядке).
using namespace std;

ifstream in("input.txt");
ofstream out("result.txt", ios_base::out | ios_base::trunc);
void showINfile();
void checkFiles();
void showOUTfile();
void fillDictionary(map<string,int>&);
void writeDictionary(map<string,int>);
void main() { 
	
	checkFiles();
	map <string, int> Dictionary;
	fillDictionary(Dictionary);
	writeDictionary(Dictionary);
	//showINfile();
	//showOUTfile();
	in.close();
	out.close();
	system("pause");
}



void checkFiles()
{
	if (!in.is_open()) {
		cout << "Файл input.txt не может быть открыт!\n";
		system("pause");
	}
	if (!out.is_open())
	{
		cout << "Файл output.txt не может быть открыт!\n";
		system("pause");
	}
}

void showINfile() {
	cout << "INPUT.TXT :\n";
	char str[1024];
	FILE * f = fopen("input.txt", "r");
	if (f == NULL) perror("Can`t open file\n");
	while (1) {
		if (feof(f)) break; //Если файл кончился, выйти из цикла 
		if (fgets(str, 1024, f) != NULL) // считать символы из файла
			puts(str);  // вывод на экран
	}
	cout << endl << endl;
	fclose(f);
}
void showOUTfile() {//в программе не вызываю,но для проверки удобно)
	cout << "OUTPUT.TXT :\n";
	char str[1024];
	FILE * f = fopen("result.txt", "rt");
	if (f == NULL) perror("Can`t open file\n");
	while (1) {
		if (feof(f)) break; //Если файл кончился, выйти из цикла 
		if (fgets(str, 1024, f) != NULL) // считать символы из файла
			puts(str);  // вывод на экран
	}
	cout << endl << endl;
	fclose(f);
}
void fillDictionary(map<string,int> &Dictionary) {
	string buff; //я бы рад заменить это на char* а потом выделить память,или на char[],но map отказывается insert`ить или emplace`ить такие типы
	while (1) {
		in >> buff;//Вот это мне не нравится!!!! Ты же не выделяешь тут слова!!!! Разделителителем по умолчанию является тольео \n\t И пробел
		if (Dictionary.count(buff) > 0) Dictionary.at(buff)++;
		else Dictionary.emplace(buff, 1);
		if (in.eof()) break;
	}
}

void writeDictionary(map<string, int> Dictionary) {
	out << "Resulting dictionary:\n";
	for (auto it = Dictionary.begin(); it != Dictionary.end(); ++it)
	{
		out << (*it).first << " : " << (*it).second << endl;
	}
}
