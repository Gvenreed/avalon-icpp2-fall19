#include "CharArray.hpp"

using namespace ext;

int main()
{
	charArray str = new char[6]{ "hello" };
	charArray str2 = new char[7]{ " world" };
	char str3 = '!';
	int pos, len;
	pos = 2;
	len = 3;
	char result1 = characterAt(str, 1); // h
	char result2 = characterAt(str, 3); // l

	concatenate(str, str2); // str -> "hello world"
	append(str, str3);
	substring(str, pos, len);
}
