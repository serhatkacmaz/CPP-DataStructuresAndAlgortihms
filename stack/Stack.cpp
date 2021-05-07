// stack is (Last In FirstOut)

#include <iostream>
using namespace std;
#define size 100

class Stack
{
	char array[size];
	int tos;			// top of stack

public:

	// constructor 
	Stack()
	{
		tos = 0;
	}

	// item insertion process
	void push(char ch)
	{
		if (tos == size) // stack full?
			cout << "Stack  full\n";
		else
		{
			array[tos] = ch;
			tos++; // stack pointer
		}
	}

	// item remove process
	char pop()
	{
		if (tos == 0) // stack is empty
		{
			cout << "Stack bos\n";
			return -1;
		}
		else
		{
			tos--;
			array[tos];
		}
	}

	// stack length
	int Size()
	{
		return tos;
	}

	// last incoming item
	int top()
	{
		int x = tos - 1;
		return array[x];
	}
};

// parenthesis controlling method
char Bracket_Control(string text)
{
	Stack symbol;
	for (int i = 0; i < text.length(); i++)
	{
		switch (text[i])
		{
		case'(':
		case'[':
		case'{':
			symbol.push(text[i]);
			break;

		case')':
			if (symbol.Size() == 0 || symbol.top() != '(')
				return ')';
			else
				symbol.pop();
			break;

		case'}':
			if (symbol.Size() == 0 || symbol.top() != '{')
				return '}';
			else
				symbol.pop();
			break;

		case']':
			if (symbol.Size() == 0 || symbol.top() != '[')
				return ']';
			else
				symbol.pop();
			break;
		}
	}
	if (symbol.Size() > 0)
		return symbol.top();
	else
		return 'e';
}
int main()
{
	string text;
	cout << "Bir metin giriniz: ";
	cin >> text;

	switch (Bracket_Control(text)) {
	case 'e':
		cout << "parantez hatasi yok..." << endl;
		break;
	case '(':
		cout << ") parantezi eksik..." << endl;
		break;
	case '[':
		cout << "] parantezi eksik..." << endl;
		break;
	case '{':
		cout << "} parantezi eksik..." << endl;
		break;
	case ')':
		cout << "( parantezi eksik..." << endl;
		break;
	case ']':
		cout << "[ parantezi eksik..." << endl;
		break;
	case '}':
		cout << "{ parantezi eksik..." << endl;
		break;
	}
	return 0;
}