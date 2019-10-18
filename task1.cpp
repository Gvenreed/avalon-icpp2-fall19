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

int main()
{
	string dq;
	setlocale(LC_ALL, "");

	Student first[100];

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

	cout << "Введите категорию сортировки (Id, Grade, Name): " << endl;
	cin >> dq;

	if (dq == "Id")
	{
		for (int j = 0; j < 100; j++)
		{
			for (int g = 0; g < 99; g++)
			{
				if (first[g].Id > first[g + 1].Id)
				{
					swap(first[g].Id, first[g + 1].Id);
				}
			}
		}
	}
	else if (dq == "Grade")
	{
		for (int j = 0; j < 100; j++)
		{
			for (int g = 0; g < 99; g++)
			{
				if (first[g].Grade > first[g + 1].Grade)
				{
					swap(first[g].Grade, first[g + 1].Grade);
				}
			}
		}
	}
	else if (dq == "Name")
	{

		for (int j = 0; j < 100; j++)
		{
			for (int g = 0; g < 99; g++)
			{
				if (first[g].Name > first[g + 1].Name)
				{
					swap(first[g].Name, first[g + 1].Name);
				}
			}
		}
	}
	else
	{
		cout << "ошибка ввода" << endl;
	}
};
