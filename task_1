#include <iostream>
#include  <limits>
using namespace std;

int main()
{
	long long int n, numb, sum, numb_2;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> numb;
		sum = 0;
		numb_2 = (numb - numb % 10)/10;
		for (int j = 1; j < 13; j++)
		{			
			if (j % 2 == 0)
			{
				sum += numb_2%10;
			}
			else
			{
				sum += 3*(numb_2%10);
			}

			numb_2 = (numb_2 - numb_2%10) / 10;
		}

		if (10-(sum % 10) == numb % 10)
		{
			cout << "valid" << endl;
		}
		else
		{
			cout << "invalid" << endl;
		}
	}
}
