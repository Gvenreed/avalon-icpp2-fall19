#pragma once
namespace ext
{
	struct charString
	{
		char symbol;
		charString* nextSymbol;
	};
	void characterAt(charString* str, int num);
	void append(charString* & str, char symbol);
	void print(charString* str);
}
