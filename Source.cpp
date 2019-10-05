#include <iostream>
#include <string>
#include "Extention.hpp"


using namespace ext;
using namespace std;

struct Student
{
	int Id;
	int Grade;
	string Name;
};

//void sNm()
//{
//
//}
//void sGd()
//{
//
//}
//void sNm()
//{
//
//}


int main()
{
	Student first [100];

	for (int i = 0; i < 100; ++i)
	{
		
	}

	for (int i = 0; i < 100; ++i)
	{
		
	}

	for (int i = 0; i < 100; ++i)
	{		
		int lenght = GetRandomValue(3, 6);
		char letter = GetRandomValue('A', 'Z');
		first[i].Name += letter;
		first[i].Grade = GetRandomValue(0, 100);
		first[i].Id = GetRandomValue(0, 1000);
		for (int j = 1; j < lenght; ++j)
		{
			first[i].Name += GetRandomValue('a', 'z');
		}
	}

}
