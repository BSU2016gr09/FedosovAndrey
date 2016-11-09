#include <iostream>
#include <clocale>
#include<ctime>
using std::cin;using std::cout;using std::swap;
/*Напишите игру в пьяницу на стеке между компьютером и компьютером.Колода перетусовывается и раздаётся пополам.
Они по очереди достают по карте сверху колоды.Забирает карты и кладёт себе вниз колоды тот у кого очков больше на вытянутых картах
(6 - ка берет туза, 7 - ка берет короля).Игра заканчивается если один не может сделать ход.Запоминать кол - во pushQходов в законченной игре.
Провести 5000 партий.Вывести макс. / мин. / среднее кол - во ходов в этих партиях.*/
const int N = 36;

void pushQ(int numb, int queque[], int&tail);
int popQ(int queque[], int&head);
void randomChange(int a[], int N);
void playDrunkard(int kol[],int x,int moves[],int&min,int&max);
double averageValue(int moves[]);
int main()
{
	srand(time(0));
	int max = -1, min = 9999999, moves[5000]; //массив moves только для запоминания ходов(так сказано в условии задачи)
	setlocale(LC_ALL, "Russian");
	for (int x = 0;x <5000; x++)
	{
		int kol[] = {6,7,8,9,10,11,12,13,14,6,7,8,9,10,11,12,13,14,6,7,8,9,10,11,12,13,14,6,7,8,9,10,11,12,13,14 };//колода,где 11,12,13,14 - валет,дама,король и туз соответственно
		randomChange(kol, N);
		
		playDrunkard(kol,x,moves,min,max);
		
	}
	cout << "Максимальное число ходов = " << max << "\n";
	cout << "Минимальное число ходов = " << min << "\n";
	cout << "Ходов в среднем = " << averageValue(moves) << "\n";
	system("pause");
}

double averageValue(int moves[])
{
	double turns = 0;
	for (int i = 0;i < 5000;i++)
		turns += moves[i];
	return  (turns*1.0) / (5000 * 1.0);
}
void randomChange(int a[], int N)
{
	int j;
	srand(rand());
	for (int i = 0;i < N;i++)
	{
		j = rand() % N;
		swap(a[i], a[j]);
	}

}

void pushQ(int numb, int queque[], int&tail)
{
	queque[tail] = numb;
	tail = (tail + 1) % N;

}
int popQ(int queque[], int&head)
{
	int numb = queque[head];
	head = (head + 1) % N;
	return numb;
}

void playDrunkard(int kol[],int x,int moves[],int&min,int&max)
{
	int card1, card2, countOfTurns=0,sizeQ1=0,sizeQ2=0;
	int queque1[N], queque2[N], head1 = 0, tail1 = 0, head2 = 0, tail2 = 0;
	for (int i = 0;i < N/2;i++)
	{pushQ(kol[i], queque1, tail1);sizeQ1++;}
	for (int i =N/2;i < N;i++)
	{pushQ(kol[i], queque2, tail2);sizeQ2++;}

	while ((sizeQ1 > 0 && sizeQ1<36)&&(sizeQ2 > 0 &&sizeQ2<36))
	{
		card1 = popQ(queque1,head1);sizeQ1--; //тянем 2 карты
		card2 = popQ(queque2, head2);sizeQ2--;

		if (card1 == 14 && card2 == 6) { pushQ(card2, queque2, tail2);pushQ(card1, queque2, tail2);sizeQ2 += 2; }//если забирает игрок 2
		else  if (card1 == 13 && card2 == 7) { pushQ(card2, queque2, tail2);pushQ(card1, queque2, tail2);sizeQ2 += 2; }
		else if (card1 < card2) { pushQ(card2, queque2, tail2);pushQ(card1, queque2, tail2);sizeQ2 += 2; }
	
	    if (card1 == 6 && card2 == 14) { pushQ(card1, queque1, tail1);pushQ(card2, queque1, tail1);sizeQ1 += 2; } //если забирает игрок 1
		else  if (card1 == 7 && card2 == 13) { pushQ(card1, queque1, tail1);pushQ(card2, queque1, tail1);sizeQ1 += 2;}
		else if (card1>card2) { pushQ(card1, queque1, tail1);pushQ(card2, queque1, tail1);sizeQ1 += 2;}
		if (card1==card2) { pushQ(card1, queque1, tail1);pushQ(card2, queque2, tail2);sizeQ1++;sizeQ2++;	} //если равные значения,то карты в низ колоды
		countOfTurns += 2;
		if (countOfTurns > 1000) {countOfTurns = 0;	break;	}
	}


	if (countOfTurns)
	{
		if (countOfTurns > max) max = countOfTurns;
		if (countOfTurns < min) min = countOfTurns;
	}
	else cout << "Бесконечная игра\n";
	moves[x] = countOfTurns;
}
