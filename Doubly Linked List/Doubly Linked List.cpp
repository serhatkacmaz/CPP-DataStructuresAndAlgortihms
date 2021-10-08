#include <iostream>
using namespace std;

struct DoublyList
{
	int data;
	DoublyList* prev;
	DoublyList* next;
};

DoublyList* first = NULL;
DoublyList* final = NULL;

void Insert(int data)
{
	DoublyList* p = new DoublyList;
	p->data = data;
	p->next = NULL;
	p->prev = NULL;

	if (first != NULL) // if list is full
	{
		final->next = p;
		p->prev = final;
		final = p;
		final->next = NULL;
	}
	else // if list is empty
	{
		first = p;
		final = p;
		first->next = NULL;
		first->prev = NULL;
	}
	cout << "Added data." << endl;
}
void Display()
{
	if (first == NULL) // if list is empty
	{
		cout << "The List is empty. Do not display. !!!" << endl;
	}
	else
	{
		DoublyList* p = new DoublyList;
		p = first;
		while (p != NULL)
		{
			cout << p->data << "\t";
			p = p->next;
		}
	}

}
void Search(int data)
{
	if (first == NULL)	// if list is empty
	{
		cout << "The List is empty. Do not searching. !!!" << endl;
	}
	else
	{
		bool isData = false;	// is there any data?
		DoublyList* p = new DoublyList;
		p = first;
		while (p != NULL)
		{
			if (data == p->data)  // There is data
			{
				cout << " The value " << data << " was found at " << p << endl;
				isData = true;
				break;
			}
			p = p->next;
		}
		if (isData == false)
		{
			cout << "There is not value on list !!!" << endl;
		}
	}

}
void Delete(int data)
{
	if (first == NULL)
	{
		cout << "The List is empty. No deletion is performed !!!" << endl;
	}
	else
	{
		bool isData = false;  //is there data to delete?
		DoublyList* p = new DoublyList;
		p = first;
		while (p != NULL)
		{
			if (data == p->data)
			{
				isData = true;
				break;
			}
			p = p->next;
		}
		if (p == first)	// if data is first
		{

			if (first->next != NULL)  // if there is not a single data in the list, make the data next to it prev = null
			{
				first->next->prev = NULL;
			}
			first = first->next;
			free(p);
			cout << "Deleted." << endl;
		}
		else if (p == final)   // if data is end
		{
			final->prev->next = NULL;
			final = final->prev;
			free(p);
			cout << "Deleted." << endl;
		}
		else if (p != first && p != final && isData == true)  // if data is in the middle of list
		{
			p->next->prev = p->prev;
			p->prev->next = p->next;
			free(p);
			cout << "Deleted." << endl;
		}
		else if (isData == false)  // there is not data to delete on list
		{
			cout << "There is not value on list !!!" << endl;
		}
	}

}

int main()
{
	int choice = 0;
	int number = 0;
	while (true)
	{
		cout << "1)Insert\t 2)Delete\t 3)Search\t 4)Display\t 5)Exit\nMake a choice: ";
		cin >> choice;
		cout << endl;
		switch (choice)
		{
		case 1:
			cout << "Data: ";
			cin >> number;
			Insert(number);
			cout << endl;
			break;
		case 2:
			cout << "Data: ";
			cin >> number;
			Delete(number);
			cout << endl;
			break;
		case 3:
			cout << "Data: ";
			cin >> number;
			Search(number);
			cout << endl;
			break;
		case 4:
			cout << "Display: " << endl;
			Display();
			cout << endl;
			break;
		case 5:
			cout << "Made Exit" << endl;
			exit(1);
			break;
		default:
			cout << "Error !!!" << endl;
			break;
		}
	}

	return 0;
}

