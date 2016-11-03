#include <iostream>
#include <clocale>
using std::cin;using std::cout;
/*Реализовать функции для работы с очередью. Продемонстрировать их работоспособность вызывая из main.
Показать, что очередь размера 4 не переполняется. Если добавить 3 элемента, потом удалить 2, а потом еще раз добавить 3 элемента.*/
const int N = 4;
void pushQ(int numb,int queque[], int&tail);
int popQ(int queque[], int&head);
void printQ(int queque[], int&head, int&tail);
int sizeQ(int queque[], int&head, int&tail);
int main()
{
	int queque[N], head = 0, tail=0;
	setlocale(LC_ALL, "Russian");

	printQ(queque, head, tail);
	cout << "Добавим в очередь 3 элемента: 5,2 и 1\n";
	pushQ(5, queque, tail);
	pushQ(2, queque, tail);
	pushQ(1, queque, tail);
	printQ(queque, head,tail );
	cout << "Удалим последние 2 элемента очереди\n";
	cout << "Первым выйдет " << popQ(queque, head) << "\n";
	printQ(queque, head, tail);
	cout << "далее удалится " << popQ(queque, head)<<"\n";
	printQ(queque, head, tail);

	cout << "Добавим теперь ещё 3 элемента,например 7 ,3 и 9\n";
	pushQ(7, queque, tail);
	pushQ(3, queque, tail);
	pushQ(9, queque, tail);
	printQ(queque, head, tail);
	system("pause");
}
int sizeQ(int queque[], int&head, int&tail)
{
	if (head >= tail) return N-head + tail;
	else return tail - head;
}
void pushQ(int numb,int queque[], int&tail)
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

void printQ(int queque[], int&head, int&tail)
{
	cout << "Очередь на данный момент:\n";
	int i = head,count=0;
	while (count < sizeQ(queque,head,tail))
	{
		cout << queque[i] << " ";
		i = (i + 1) % N;
		count++;
	}
	cout << "\n\n";
}
