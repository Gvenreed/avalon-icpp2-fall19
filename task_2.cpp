#include <iostream>
#include  <limits>
using namespace std;

int main()
{
	setlocale(LC_ALL, "");
	char dq;
	long long int numb, sum, numb_2;
	sum = 0;
	cout << "введите тип переменной (ISBN-10 как 10, ISBN-13 как 13)" << endl;
	cin >> dq;
	cout << "введите число" << endl;
	cin >> numb;
	numb_2 = (numb - numb % 10) / 10;
	if (dq == 13)
	{
			for (int j = 1; j < 13; j++)
			{
				if (j % 2 == 0)
				{
					sum += numb_2 % 10;
				}
				else
				{
					sum += 3 * (numb_2 % 10);
				}

				numb_2 = (numb_2 - numb_2 % 10) / 10;
			}

			if (10 - (sum % 10) == numb % 10)
			{
				cout << "valid" << endl;
			}
			else
			{
				cout << "invalid" << endl;
			}
		}
	else
	{
		for (int j = 1; j < 10; j++)
		{
			sum += (numb_2 % 10) * (1 + j);

			numb_2 = (numb_2 - numb_2 % 10) / 10;
		}

		if (11 - (sum % 11) == numb % 10)
		{
			cout << "valid" << endl;
		}
		else
		{
			cout << "invalid" << endl;
		}
	}
}
