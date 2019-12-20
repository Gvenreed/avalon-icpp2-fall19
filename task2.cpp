#include <iostream>
#include <fstream>
#include<math.h>

using namespace std;

struct Triangle
{
	string color;
	int x;
	int y;
	int z;
	float wide;
	char paint;
	int per = x + y + z;
	float square = sqrt(0.5F*per*(0.5F*per -x)*(0.5F*per - y)*(0.5F*per - z));
};

ostream& operator << (ostream& out, Triangle triangle)
{
	out << triangle.x << " " << triangle.y << " " << triangle.z << " " << triangle.per << " " << triangle.square << " " << triangle.wide << " " << triangle.paint << " " << triangle.color << endl;
	return out;
}

istream& operator >> (istream& in, Triangle& triangle)
{
	in >>triangle.color >> triangle.x >> triangle.y >> triangle.z >> triangle.wide >> triangle.paint;
	return in;
}

int main()
{
	Triangle triangle[100]{};
	ifstream Input;
	ofstream Output;
	setlocale(LC_ALL, "");
	ifstream FileOfTriangle("triangle.txt", iostream::app);

	if (!FileOfTriangle.is_open())
	{
		cout << "File cannot be open" << endl;
		return 1;
	}

	ofstream FileOfTriangle_out;
	FileOfTriangle_out.open("triangel_out.txt", iostream::ate);

	if (!FileOfTriangle_out.is_open())
	{
		cout << "File cannot be open" << endl;
		return 1;
	}

	for (int i = 0; i < 100; ++i)
	{
		FileOfTriangle >> triangle[i];
		FileOfTriangle_out << triangle[i];
	}
	FileOfTriangle.close();
	FileOfTriangle_out.close();
}
