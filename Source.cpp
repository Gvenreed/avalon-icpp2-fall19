#include <string>
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

struct Triangle
{
	int a;
	int b;
	int c;
	double thickness;
};

int findIndex(int data[], int left, int right, int value)
{
	int middle = (left + right) / 2;
	if (data[middle] == value)
	{
		return middle;
	}
	if (data[middle] > value)
	{
		return findIndex(data, left, middle - 1, value);
	}
	else
	{
		return findIndex(data, middle + 1, right, value);
	}
}

int findIndex(int data[], int size, int value)
{
	return findIndex(data, 0, size - 1, value);
}


int main()
{
	Triangle data[100];
	ifstream fin("triangle.txt");

	int i = 0;
	while (!fin.eof())
	{
		string temp;
		getline(fin, temp);

		istringstream istream(temp);
		istream >> data[i].a >> data[i].b >> data[i].c >> data[i].thickness;
		++i;
	}

	for (int i = 0; i < 100; ++i)
	{
		string temp;
		getline(fin, temp);

		istringstream istream(temp);
		istream >> data[i].a >> data[i].b >> data[i].c >> data[i].thickness;
	}

	//Point point;
	istringstream istream("5 10");
	ostringstream ostream;

	//istream >> point.x >> point.y;
	//ostream << point.x << " " << point.y;

	cout << ostream.str() << endl;
}
