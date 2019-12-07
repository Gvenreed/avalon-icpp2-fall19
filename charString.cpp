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

		while (temp->nextSymbol != nullptr)
		{
			temp = temp->nextSymbol;
		}
		temp->nextSymbol = ptr;
	}
	void characterAt(charString* str, int num)
	{
		int pos = 0;
		charString* temp = str;
		while (pos != num)
		{
			temp = temp->nextSymbol;
			pos += 1;
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
	void removeChars(charString* str, int count, int position)
		{
			charString* savedPtr = str;

			int currentPos = 1;
			while (currentPos != position - 1)
			{
				str = str->nextSymbol;
				++currentPos;
			}

			for (int i = 1; i <= count; ++i)
			{
				charString* temp = str->nextSymbol;
				str->nextSymbol = temp->nextSymbol;
				delete temp;
			}
		}
	void concatenate(charString*& str1, charString*& str2)
	{
		charString* temp = str1;
		charString* temp2 = str2;

		while (temp->nextSymbol != nullptr)
		{
			temp = temp->nextSymbol;
		}
		while (temp2->nextSymbol != nullptr)
		{
			temp->nextSymbol = temp2;
			temp2 = temp2->nextSymbol;
		}
	}
	void substring(charString*& str, int pos, int len)
	{
		charString* saved = str;
		charString* temp = nullptr;
		int i = 0;
		while (i != pos)
		{
			saved = saved->nextSymbol;
			i += 1;
		}
		temp = saved;
		for (int j=1; j < len-1; ++j)
		{
			temp->nextSymbol = saved;
			saved = saved->nextSymbol;
		}
	}
}
