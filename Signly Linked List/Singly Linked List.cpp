#include <iostream>
#include <conio.h>
using namespace std;

// create a structure named Node
struct Node
{
	int data;	// data
	Node* next;	// a referenceto the next node
};

Node* first = NULL;
Node* final = NULL;
bool list_control = false;

// Linked list insertion a item
void Insert(int data)
{
	Node* p = new Node;
	p->data = data;
	p->next = NULL;


	if (first != NULL)
	{
		final->next = p;
		final = final->next;
	}
	// if the list is empty
	else
	{
		first = p;
		final = first;
	}
}

// Linked list display
void Listing()
{
	Node* p = first;
	if (p == NULL)
		cout << "Liste Bos..." << endl;
	else
	{
		while (p != NULL)
		{
			cout << p->data << endl;
			p = p->next;
		}
	}
}

// Linked list from removel a item
void Delete(int data)
{
	Node* p, * previous;
	if (first == NULL)
		cout << "Liste Bos Silme olamaz..." << endl;
	else
	{
		p = first;
		previous = NULL;

		// until it is empty
		while (p)
		{
			if (data == p->data)
			{
				list_control = true;
				break;
			}

			previous = p;
			p = p->next;
		}

		// has the wanted element been found
		if (list_control == true)
		{
			list_control = false;

			// delete the first element
			if (p == first)
			{
				first = first->next;
				free(p);
			}

			// delete the final element
			else if (p == final)
			{
				previous->next = NULL;
				final = previous;
				free(p);
			}

			// delete the middle element
			else if (p != first && p != final)
			{
				previous->next = p->next;
				free(p);
			}
		}
		else
			cout << "Silinecek Eleman Listede Yok" << endl;
	}
}


// Search method
void Search(int data)
{
	bool search = false;
	Node* p;
	p = first;

	if (first == NULL)
		cout << "Liste Bos Arama Yaplmaz..." << endl;
	else
	{
		// until it is empty
		while (p)
		{
			// has the wanted element been found
			if (p->data == data)
				search = true;

			p = p->next;
		}

		if (search)
			cout << "Eleman Listede Var..." << endl;
		else
			cout << "Eleman Listede Yok..." << endl;
	}

}


// main function
int main()
{
	int choice;
	int number;

	// user interface for menu
	do
	{
		cout << endl;
		cout << "1)Ekleme:" << endl;
		cout << "2)Listeleme" << endl;
		cout << "3)Silme" << endl;
		cout << "4)Arama" << endl;
		cout << "5)Cikis" << endl;

		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "Ekleme Yap:" << endl;
			cin >> number;
			Insert(number);
			break;
		case 2:
			Listing();
			break;
		case 3:
			cout << "Silme Yap:" << endl;
			cin >> number;
			Delete(number);
			break;
		case 4:
			cout << "Arama Yap:" << endl;
			cin >> number;
			Search(number);
			break;
		case 5:
			cout << "Cikis...";
			break;
		default: cout << "Hatali Giris !!! " << endl;
			break;
		}

	} while (choice != 5);

	_getch();

	return 0;
}

