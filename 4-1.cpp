#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_DEPRECATE
#include <iostream>
#include<fstream>
#include <map>
#include <string>
#include <algorithm> // для сортировки.Я надеюсь можно уже пользоваться такой,и не писать свой пузырь или qsort
#include<vector>

//В тексте определить частоту вхождения слов. Вывести "словарь" текста (не обязательно в алфавитном порядке).
using namespace std;

ifstream in("input.txt");
ofstream out("result.txt", ios_base::out | ios_base::trunc);
void showINfile();
void checkFiles();
void showOUTfile();
void fillDictionary(map<string,int>&);
void writeDictionary(vector <pair<string, int>>&); //по ссылке ведь оптимальнее передавать,т.к. не создаётся копия и,следовательно,не занимается лишнее место?
bool compare(const pair<string, int>&i, const pair<string, int>&j);
void main() { 
	
	checkFiles();
	map <string, int> Dictionary;
	fillDictionary(Dictionary);
	vector <pair<string, int>> duplicate(Dictionary.begin(), Dictionary.end());
	sort(duplicate.begin(), duplicate.end(), compare);
	writeDictionary(duplicate);
	//showINfile();
	//showOUTfile();
	in.close();
	out.close();
	system("pause");
}

bool compare(const pair<string, int>&i, const pair<string, int>&j)
{
	return i.second > j.second;
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
	string str; 
	const char* delim = " ,!'@#$%^“”&*()-\\_=+/{}[]–\"\'.°";//не нашёл я как добавить разделители сюда in>>str;но зато теперь построчный ввод
	while (1) {
		getline(in,str);
		char *dup = strdup(str.c_str());
		char *buff = strtok(dup,delim);
		while (buff) {
			string word(buff);
			if (Dictionary.count(word) > 0) Dictionary.at(word)++;
			else Dictionary.emplace(word, 1);
			buff = strtok(NULL,delim);
		}
		if (in.eof()) break;
		free(dup);buff = nullptr;dup = nullptr;
		
	}
}

void writeDictionary(vector <pair<string, int>>& Dictionary) {
	out << "Resulting dictionary:\n";
	for (auto it = Dictionary.begin(); it != Dictionary.end(); ++it)
	{
		out << (*it).first << " : " << (*it).second << endl;
	}
}
