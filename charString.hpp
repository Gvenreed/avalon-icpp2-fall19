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
	void removeChars(charString* str, int count, int position);
	void concatenate(charString*& str1, charString*& str2);
	void substring(charString*& str, int pos, int len);
}
