#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<fstream>
//В тексте определить частоту вхождения слов. Вывести "словарь" текста (не обязательно в алфавитном порядке).
using namespace std;

ifstream in("input.txt");
ofstream out("result.txt");

void delmm(char* str) { delete[] str; }
void checkFiles();
void giveMemory(char**&,int);
void giveMemory(char*&,int);
int countRows();
void printText(char**, int);
void showFrequency(char**, int);
void delWord(char**,char*,int);
void writeText(char**&, int);
void help();
void delMem(char**&text, int rows) { for (int i = 0;i < rows;i++) delete[] text[i]; delete[] text; }
typedef void(*func)(char**,int);
void main() { 
	checkFiles();
	func menu[] = {printText,showFrequency };
	char** text;
	int rows = countRows();
	giveMemory(text,rows);
	writeText(text,rows);

	help();
	int chosen = 1;
	while (chosen!=2) {
		cin >> chosen;
		if(chosen>0&&chosen<3)
		menu[chosen-1](text, rows);
	}

	
	//delMem(text, rows); Не могу найти ошибку,пишет 5-1.exe вызвал срабатывание точки останова
	in.close();
	out.close();
	system("pause");
}
void help() {
	cout << "Enter 0 for exit\n";
	cout << "Enter 1 for showing text(only before showing dictionary)\n";
	cout << "Enter 2 for showing dictionary(result.txt)\n";
}
int countRows() {

	int rows = 0;
	char* str;
	giveMemory(str, 255);
	FILE * ptrFile = fopen("input.txt", "r");
	if (ptrFile == nullptr) {
		cout << "Файл не открыт\n";
			system("pause");
	}
	else {
		while (!feof(ptrFile)) {
			fgets(str, 255, ptrFile);
			rows++;
		}
	}
	
	fclose(ptrFile);
	delete[] str;
	return rows;
}
void printText(char** text, int rows) {
	for (int row = 0;row < rows;row++)
		cout << text[row] << endl;
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
void giveMemory(char ** &text,int size) {
	try {
		text = new char*[size];
	
	}
	catch (...) {
		cout << "Allocation failed\n";
		system("pause");
	}
}
void giveMemory(char*& str,int size){
	try {
		str = new char[size];
	}
	catch (...) {
		cout << "Allocation failed\n";
		system("pause");
	}
}
void writeText(char**& text, int rows) {
	char* str;
	giveMemory(str, 255);
	int i = 0;
	for(i;i<rows;i++){
		
		in.getline(str, 255,'\n');
		giveMemory(text[i], strlen(str)+2);
		strcpy(text[i], str);
	}
	delete[] str;//вот тут работает
}
void delWord(char**text,char*word,int rows) {
	if (!strlen(word)) return;
	int count = 1;
	out << word << " - ";

	for (int i = 0;i < rows;i++) {
		char* str;
		giveMemory(str, 255);
		while (strstr(text[i], word)) {
			count++;

			char* ptr = strstr(text[i], word);
			int st = strlen(text[i]) - strlen(ptr);
			strncpy(str, text[i], st);
			str[st] = '\0';
			ptr += strlen(word);
			strcat(str, ptr);
			text[i] = str;
			
		}
		//delete [] str тут та же ошибка //У тебя str локальная внутри цикла
		str = nullptr;
	}
	out << count << endl;
	
}
void showFrequency(char**text, int rows) {
	char* word;
	
	
	giveMemory(word,255);

	for (int i = 0;i < rows;i++) {
		while (text[i][0])
		{
			char* ptr = text[i];
			ptr += strspn(text[i], " ");
			text[i] = ptr; //прыгнули на начало слова
			strcpy(word, text[i]);//скопировали строку с начала первого
			ptr = strpbrk(text[i], " "); //нашли начало следующего слова
			if (!ptr) text[i][0] = '\0';
			else
				text[i] = ptr;
			
			word[strcspn(word, " ")] = '\0'; //обрезали скопированную строку
			delWord(text, word, rows);
		}
	}
}
