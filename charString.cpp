#include "charString.hpp"
#include <iostream>

using namespace std;

namespace ext
{
	void append(charString*& str, char symbol)
	{
		charString* ptr = new charString{ symbol };
		
		if (str == nullptr)
		{
			str = ptr;
			return;
		}

		charString* temp = str;

		while (temp-> nextSymbol != nullptr)
		{
			temp = temp->nextSymbol;
		}
		temp->nextSymbol = ptr;
	}
	void characterAt(charString* str, int num)
	{
		int temp;
		while (temp != num)
		{
			
		}
	}
	void print(charString* str)
	{
		while (str != nullptr)
		{
			cout << str->symbol;
			str = str->nextSymbol;
		}
	}
}
