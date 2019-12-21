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

ostream& operator << (ostream& out, Triangle x)
{
	out << x.a << " " << x.b << " " << x.c << " " << x.thickness;
	return out;
}

istream& operator >> (istream& in, Triangle& x)
{
	in >> x.a >> x.b >> x.c >> x.thickness;
	return in;
}


int perimeter(Triangle x)
{
	return x.a + x.b + x.c;
}

int main()
{
	setlocale(LC_ALL, "");
	bool res = false;
	int size, l, r;
	int request;
	Triangle data;
	data.a = 1;
	data.c = 1;
	data.b = 1;
	data.thickness = 0;
	ifstream FileOfTriangle("triangle.bin", istream::in | istream::binary);

	if (!FileOfTriangle.is_open())
	{
		cout << "File cannot be open" << endl;
		return 1;
	}

	cout << "Введите периметр" << endl;
	cin >> request;
	FileOfTriangle.seekg(0, ios_base::end);
	size = FileOfTriangle.tellg();
	l= 0; 
	r= size - 1;
	while (l != r-1)
	{
		FileOfTriangle.seekg(sizeof(Triangle)*((l + r) / 2));
		FileOfTriangle >> data;
		
		if (request == perimeter(data))
		{
			cout << data;
			res = true;
			break;
		}
		else
		{
			if (request > perimeter(data))
			{
				l = (l + r) / 2;
			}
			else
			{
				r = (l + r) / 2;
			}
		}
		
	}
	if (!res)
	{
		cout << "Треугольника с таким периметром нет" << endl;
	}
	FileOfTriangle.close();
}
