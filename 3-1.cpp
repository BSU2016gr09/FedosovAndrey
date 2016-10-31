#include <iostream>
#include <clocale>
#include <conio.h>
#include<ctime>
#include<iomanip>
/*1) Напишите игру в кости между человеком и компьютером.Они по очереди кидают по два кубика.Побеждает тот у кого сумма больше.
Игра заканчивается если набрана сумма >50. Кубики рисуйте в отдельной ф - ции псевдографикой(см.рисунок в качестве примера).
+ -- - +
| O |
| O |
| O |
+-- - +*/
using std::cin;using std::cout;using std::setw;

void playBones();
void drawcube(int value);
int main()
{
	srand(time(0));
	setlocale(LC_ALL, "Russian");
	playBones();
	system("pause");
}

void throwing(int &x,int &y) //бросок
{
	x = rand() % 6 + 1;
	y = rand() % 6 + 1;
}
void playBones()
{
	int playerScore=0, compScore=0, throw1, throw2;
	while (playerScore < 50 && compScore < 50)
	{
		cout << "Нажмите t,если хотите бросить кости.Нажмите q,если хотите выйти\n";
		int button = _getch();
		switch (button)
		{
		case 't':
		{ // 	system("cls");
		    throwing(throw1, throw2);
			playerScore += throw1+throw2;
			cout << "YOU`VE GOT " << throw1+throw2 << "\n";
			drawcube(throw1);
			drawcube(throw2);
			throwing(throw1, throw2);
			compScore += throw1 + throw2;
			cout << "COMPUTER HAVE GOT " << throw2+throw1 << "\n";
			drawcube(throw1);
			drawcube(throw2);
			cout << setw(0) << "YOUR SCORE          ||          COMPUTER SCORE\n";
			cout << setw(4) << playerScore;
			cout << setw(35) << compScore << "\n";
			break;
		}
		case 'q': exit(0);
		default:{cout<<"Вы нажали не ту кнопку,проверьте раскладку клавиатуры.Возможно включен CapsLock\n\n"; break;}
		}
		
	}
	if (compScore == playerScore) cout  << "DRAW\n"; 
	if (compScore < playerScore)  cout << "YOU WON\n";
	if (compScore > playerScore) cout <<"COMPUTER WON\n"; 
    }
void drawcube(int value)
{
	switch (value)
	{
	case 1:
	{
		cout << "+---------+\n";
		cout << "|         |\n";
		cout << "|    O    |\n";
		cout << "|         |\n";
		cout << "+---------+\n\n";
		break;
	}
	case 2:
	{
		cout << "+---------+\n";
		cout << "| O       |\n";
		cout << "|         |\n";
		cout << "|       O |\n";
		cout << "+---------+\n\n";
		break;
	}
	case 3:
	{
		cout << "+---------+\n";
		cout << "| O       |\n";
		cout << "|    O    |\n";
		cout << "|       O |\n";
		cout << "+---------+\n\n";
		break;
	}
	case 4:
	{
		cout << "+---------+\n";
		cout << "| O     O |\n";
		cout << "|         |\n";
		cout << "| O     O |\n";
		cout << "+---------+\n\n";
		break;
	}
	case 5:
	{
		cout << "+---------+\n";
		cout << "| O     O |\n";
		cout << "|    O    |\n";
		cout << "| O     O |\n";
		cout << "+---------+\n\n";
		break;
	}
	case 6:
	{
		cout << "+---------+\n";
		cout << "| O     O |\n";
		cout << "| O     O |\n";
		cout << "| O     O |\n";
		cout << "+---------+\n\n";
		break;
	}
	default:
		cout << "Ошибка\n";
	}
}