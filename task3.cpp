#include <iostream>
#include <fstream>
#include<stdio.h>

using namespace std;

struct Sportsman
{
	int num;
	string name;
	string surname;
	int res;
};
struct Sport
{
	int num;
	int res;
};

istream& operator >> (std::istream& in, Sport& stm)
{
	in >> stm.num >> stm.res;
	return in;
}

ostream& operator << (std::ostream& out, Sportsman& stm)
{
	out << stm.num << "  " << stm.name << " " << stm.surname;
	return out;
}

int main()
{
	ifstream FileOfSpotrsman("athletes.txt", iostream::app);

	if (!FileOfSpotrsman.is_open())
	{
		cout << "File cannot be open" << endl;
		return 1;
	}

	ifstream FileOfResult;
	FileOfResult.open("result.txt", iostream::app);

	if (!FileOfResult.is_open())
	{
		cout << "File cannot be open" << endl;
		return 1;
	}
	Sportsman st[20];
	Sport stm[20];
	for (int i; i < 20; ++i)
	{
		FileOfResult >> stm[i];
		FileOfSpotrsman >> st[i].num >> st[i].name >> st[i].surname;
	}
	int num=0;
	int res=0;
	for (int i = 0; i < 20; ++i)
	{
		if (res > stm[i].res) 
		{ 
			res = stm[i].res;
			num = stm[i].num;
		}
	}
	cout << st[num] << stm[num].res;
	FileOfSpotrsman.close();
	FileOfResult.close();
}
