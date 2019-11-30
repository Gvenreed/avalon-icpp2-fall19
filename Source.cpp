#include <iostream>
#include "CharArray.hpp"

using namespace ext;

int main()
{
	charArray str = new char[6]{ "hello" };
	charArray str2 = new char[7]{ " world" };
	char str3 = '!';
	charArray str4 = new char[17]{ "aabbaaccaaddaaee" };
	charArray str5 = new char[3]{ "aa" };
	charArray str6 = new char[2]{ "a" };
	
	int pos, len;
	std::cin >> pos;
	std::cin >> len;
	char result1 = characterAt(str, 1); // h
	char result2 = characterAt(str, 3); // l

	concatenate(str, str2); // str -> "hello world"
	append(str, str3);
	substring(str, pos, len);
	replaceString(str4, str5, str6);
}
