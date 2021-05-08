#include <iostream>
#include <conio.h>
using namespace std;
#define size 8


// create a class named queue
class Queue
{
	char  array[size];
	int front, rear, count;

public:

	// method declare
	Queue();
	bool Empty();
	bool Full();
	void Insert(int x);
	void Remove();
	void Listing();
	void Menu();
	void Exit();
};

// Constructor method
Queue::Queue()
{
	front = -1;
	rear = -1;
	count = 0;
}

// is the queue empty?
bool Queue::Empty()
{
	if (front == -1 || front > rear)
		return 1;
	else
		return 0;
}

// is the queue full?
bool Queue::Full()
{
	if (rear == size - 1)
		return 1;
	else
		return 0;
}

// the process adding to the queue 
void Queue::Insert(int x)
{
	if (Full())
		cout << "Queue Dolu Ekleme Olmaz..." << endl;
	else
	{
		// adjust the front part when adding elements to the queue
		if (front == -1)
			front = 0;

		// the process insertion
		array[++rear] = x;
		count++;
		cout << "Kuyruga Eleman Eklendi ( " << count << " / " << size - count << " ):" << x << endl;
	}
}

// the process remove from the queue
void Queue::Remove()
{
	if (Empty())
		cout << "Queue Bos Kaldırma Olmaz..." << endl;
	else
	{
		count--;
		cout << "Queuetan Eleman Cikarildi( " << count << " / " << size - count << " ):" << (int)array[front] << endl;
		array[front] = NULL;

		// after removal from the queue, the back shift was performed
		for (int i = front; i <= rear; i++)
			array[i] = array[i + 1];

		rear--;
	}
}

// list the queue data structure
void Queue::Listing()
{
	if (Empty())
		cout << "Queue Bos Listingme Olmaz..." << endl;
	else
	{
		cout << "Liste Elemanlari: ";
		for (int i = front; i < rear + 1; i++)
		{
			cout << (int)array[i] << "\t";
		}
		cout << endl;
	}
}

// from application the exit
void Queue::Exit()
{
	cout << "Cikis Yapildi !!!";
	exit(1);
}

// user interface for menu
void Queue::Menu()
{
	cout << "1) Kuyruga Eleman Insert" << endl;
	cout << "2) Queuetan Eleman Cikar" << endl;
	cout << "3) Elemanlari Listing" << endl;
	cout << "4) Exit" << endl << endl;
}

// main function
int main()
{
	Queue k1;	// create a class object
	k1.Menu();

	while (true)
	{
		int choice;
		cin >> choice;
		switch (choice)
		{
		case 1:
			k1.Insert(rand() % 99 + 1);
			break;
		case 2:
			k1.Remove();
			break;
		case 3:
			k1.Listing();
			break;
		case 4:
			k1.Exit();
			break;

		default:
			cout << "Hatali Giris..." << endl;
			break;
		}
	}

	_getch();
	return 0;
}

