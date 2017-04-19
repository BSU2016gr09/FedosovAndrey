/*В строке найти сумму цифр, содержащихся во всех словах и слово с максимальной суммой цифр. */
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

int sumInWord(char* str,int&Max,char* &max);
int sumInSentence(char* str);
void giveMemory(char* &str);

void main() {

	char* str;
	giveMemory(str);
	cin.getline(str, strlen(str));
	cout << "The sum of all digits from the sentence = " << sumInSentence(str) << endl;


	delete[] str;

	system("pause");
}
void giveMemory(char* &str)
{
	try {
		str = new char[255];
	}
	catch (...)
	{
		cout << "Allocation failed\n";
		system("pause");
	}
}
int sumInWord(char* str, int&Max,char* &max) {
	int i = -1,sum=0;
	while (str[++i])
	{
		if (str[i] >= '0'&&str[i] <= '9')  sum += int(str[i]) - 48;
		
	}
	if (sum > Max) {
		strcpy(max, str);
		Max = sum;
	}
	str = nullptr; //Ты пошагово выполни и поймешь почему эти два указателя ссылаются на одну область почему-то в функции ниже при изменении str2 изменяется и строка max тоже
	return sum;
}
int sumInSentence(char* str) {

	char* str2;
	char* max;
	int sum = 0,Max=0;
	giveMemory(str2);
	giveMemory(max);
	max[0] = '\0';
	char* ptr = str;

	while (str[0])
	{
		ptr += strspn(str, " ");
		str = ptr; //прыгнули на начало слова

		strcpy(str2, str);//скопировали строку с начала первого
		ptr = strpbrk(str, " "); //нашли начало следующего слова
		if (!ptr) str[0] = '\0';
		else
		str = ptr;

		str2[strcspn(str2, " ")] = '\0'; //обрезали скопированную строк

		sum += sumInWord(str2,Max,max);

	}
	delete[] str2;
	cout << "The word with the maximum sum of the digits " << max << endl;
	return sum;
}
