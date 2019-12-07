#include <iostream>
#include "charString.hpp"     

using namespace std;
using namespace ext;

int main()
{
	charString* s1 = new charString{ 'h' };
	charString* s2 = new charString{ 'e' };
	charString* s3 = new charString{ 'l' };
	charString* s4 = new charString{ 'l' };
	charString* s5 = new charString{ ' ' };
	int num = 2;
	charString* ptr = nullptr;
	ptr = s1;
	s1->nextSymbol = s2;
	s2->nextSymbol = s3;
	s4->nextSymbol = s5;

	append(ptr, 'l');
	print(ptr);
	concatenate(ptr, s4);
	substring(ptr, 1, 2);
}
