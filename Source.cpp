#include <iostream>
#include <fstream>

using namespace std;

int Rd(int num)
{
	return num % 10 + (num % 100 - num % 10) + (num % 1000 - num % 100);
}

int SumNum(int num)
{
	return num % 10 + (num % 100 / 10) + (num % 1000 / 100);
}

bool LU(int tick)
{
	int Fp = 0;
	int Sp = 0;
	int sumF = 0;
	int sumS = 0;
	bool res = false;
	Sp = Rd(tick);
	Fp = Rd((tick - Sp) / 1000);
	sumF = SumNum(Fp);
	sumS = SumNum(Sp);
	if (sumS == sumF)
	{
		res = true;
	}
	return res;
}

int main()
{
	setlocale(LC_ALL, "");
	ifstream fileOfTickets("tickets.txt", iostream::app);

	if (!fileOfTickets.is_open())
	{
		cout << "File cannot be open" << endl;
		return 1;
	}

	ofstream fileL;
	fileL.open("lucky.txt", iostream::ate);

	if (!fileL.is_open())
	{
		cout << "File cannot be open" << endl;
		return 1;
	}

	ofstream fileU;
	fileU.open("unlucky.txt", iostream::ate);
	if (!fileU.is_open())
	{
		cout << "File cannot be open" << endl;
		return 1;
	}

	int ticket = 0;
	int luck = 0;
	int unluck = 0;
	for (int i = 0; i < 1000; i++)
	{
		bool res;
		res = false;
		fileOfTickets >> ticket;
		res = LU(ticket);
		if (res)
		{
			luck += 1;
			fileL << ticket << endl;
		}
		else
		{
			unluck += 1;
			fileU << ticket << endl;
		}
	}
	fileL.close();
	fileU.close();
	fileOfTickets.close();
	cout << "Счастливые билеты: " << luck << endl;
	cout << "Несчастливые билеты: " << unluck << endl;
}
