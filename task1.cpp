#include <stdio.h>
#include <limits>
#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "");
	char str[] = "Тип переменной";
	char dq[] = "|";
	char str2[] = "Размер,";
	char str3[] = "Значение";
	char str4[] = "Количество";
	char str5[] = "байт";
	char str6[] = "Минимальное";
	char str7[] = "Максимальное";
	char str8[] = "значимых бит";
	char str9[] = "bool";
	char str10[] = "unsigned short";
	char str11[] = "short";
	char str12[] = "unsigned int";
	char str13[] = "int";
	char str14[] = "unsigned long";
	char str15[] = "long";
	char str16[] = "unsigned long long";
	char str17[] = "long long";
	char str18[] = "char";
	char str19[] = "float";
	char str20[] = "double";
	printf("%s%5s%10s%5s%20s%15s%15s", str, dq, str2, dq, str3, dq, str4);
	printf("\n");
	printf("%19s%8s%7s%13s%4s%15s%3s%16s", dq, str5, dq, str6, dq, str7, dq, str8);
	printf("\n");
	for (int i = 0; i < 91; ++i)
	{
		printf("-");
	}
	printf("\n");
	int s, s1, s2, s3;
	s = sizeof(bool);
	s1 = numeric_limits<bool>::min();
	s2 = numeric_limits<bool>::max();
	s3 = numeric_limits<bool>::digits;
	printf("%s%15s%14d%s%9d%8s%9d%9s%9d", str9, dq, s, dq, s1, dq, s2, dq, s3);

	printf("\n");
	s = sizeof(unsigned short);
	s1 = numeric_limits<unsigned short>::min();
	s2 = numeric_limits<unsigned short>::max();
	s3 = numeric_limits<unsigned short>::digits;
	printf("%s%5s%14d%s%9d%8s%9d%9s%9d", str10, dq, s, dq, s1, dq, s2, dq, s3);

	printf("\n");
	s = sizeof(short);
	s1 = numeric_limits<short>::min();
	s2 = numeric_limits<short>::max();
	s3 = numeric_limits<short>::digits;
	printf("%s%14s%14d%s%9d%8s%9d%9s%9d", str11, dq, s, dq, s1, dq, s2, dq, s3);

	printf("\n");
	s = sizeof(unsigned int);
	s1 = numeric_limits<unsigned int>::min();
	s2 = numeric_limits<unsigned int>::max();
	s3 = numeric_limits<unsigned int>::digits;
	printf("%s%7s%14d%s%9d%8s%9d%9s%9d", str12, dq, s, dq, s1, dq, s2, dq, s3);

	printf("\n");
	s = sizeof(int);
	s1 = numeric_limits<int>::min();
	s2 = numeric_limits<int>::max();
	s3 = numeric_limits<int>::digits;
	printf("%s%16s%14d%s%14d%3s%14d%4s%9d", str13, dq, s, dq, s1, dq, s2, dq, s3);

	printf("\n");
	s = sizeof(unsigned long);
	s1 = numeric_limits<unsigned long>::min();
	s2 = numeric_limits<unsigned long>::max();
	s3 = numeric_limits<unsigned long>::digits;
	printf("%s%6s%14d%s%9d%8s%9d%9s%9d", str14, dq, s, dq, s1, dq, s2, dq, s3);

	printf("\n");
	s = sizeof(long);
	s1 = numeric_limits<long>::min();
	s2 = numeric_limits<long>::max();
	s3 = numeric_limits<long>::digits;
	printf("%s%15s%14d%s%14d%3s%14d%4s%9d", str15, dq, s, dq, s1, dq, s2, dq, s3);

	printf("\n");
	s = sizeof(unsigned long long);
	s1 = numeric_limits<unsigned long long>::min();
	s2 = numeric_limits<unsigned long long>::max();
	s3 = numeric_limits<unsigned long long>::digits;
	printf("%s%s%14d%s%9d%8s%9d%9s%9d", str16, dq, s, dq, s1, dq, s2, dq, s3);

	printf("\n");
	s = sizeof(long long);
	s1 = numeric_limits<long long>::min();
	s2 = numeric_limits<long long>::max();
	s3 = numeric_limits<long long>::digits;
	printf("%s%10s%14d%s%9d%8s%9d%9s%9d", str17, dq, s, dq, s1, dq, s2, dq, s3);

	printf("\n");
	s = sizeof(char);
	s1 = numeric_limits<char>::min();
	s2 = numeric_limits<char>::max();
	s3 = numeric_limits<char>::digits;
	printf("%s%15s%14d%s%9d%8s%9d%9s%9d", str18, dq, s, dq, s1, dq, s2, dq, s3);

	printf("\n");
	s = sizeof(float);
	s1 = numeric_limits<float>::min();
	s2 = numeric_limits<float>::max();
	s3 = numeric_limits<float>::digits;
	printf("%s%14s%14d%s%9d%8s%14d%4s%9d", str19, dq, s, dq, s1, dq, s2, dq, s3);

	printf("\n");
	s = sizeof(double);
	s1 = numeric_limits<double>::min();
	s2 = numeric_limits<double>::max();
	s3 = numeric_limits<double>::digits;
	printf("%s%13s%14d%s%9d%8s%14d%4s%9d", str20, dq, s, dq, s1, dq, s2, dq, s3);
	
	//#2
	
	#include <iostream>
#include "Extention.hpp"

using namespace ext;
using namespace std;

int main()
{
	int YearNum[10][12];
	int arr[10][12];
	int Max[12];
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 12; j++)
		{
			YearNum[i][j] = GetRandomValue(1000, 100000);
		}
	}

	for (int i = 0; i < 10; i++)
	{
		int dq = GetRandomValue(0, 12);
		int er = GetRandomValue(0, 10);
		for (int j = dq; j < 12; j++)
		{
			YearNum[er][j] = -1;
		}
	}

	for (int i = 0; i < 10; i++)
	{
		for (int k = 0; k < 11; k++)
		{
			for (int j = 0; j < 11; j++)
			{
				int temp;
				if (YearNum[i][j] > YearNum[i][j + 1])
				{
					temp = YearNum[i][j];
					YearNum[i][j] = YearNum[i][j + 1];
					YearNum[i][j + 1] = temp;
				}
				temp = 0;
			}
		}
	}

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 11; j++)
		{
			cout << YearNum[i][j] << " ";
		}
		cout << endl;
	}
	int x, y,z;
	x = 0; 
	y = 0;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 12; j++)
		{
			if (YearNum[i][j] != -1)
			{
				arr[x][y] = YearNum[i][j];
				y += 1;
			}
		}
		y = 0;
	x += 1;
	}

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 12; j++)
		{
			if (arr[i][j] < 0)
			{
				arr[i][j] = 0;
			}
		}
	}
	
	for (int i = 0; i < 10; i++)
	{
		int u;
		u = 0;
		for (int j = 0; j < 12; j++)
		{
			if (arr[i][j] != 0)
			{
				u += 1;				
			}

		}
		cout << u << " ";
		if (u % 2 == 0)
		{
			Max[i] = (arr[i][u/2 - 1] + (arr[i][u/2]))/2;
		}
		else
		{
			Max[i] = arr[i][(u-1)/2];
		}
	}
	cout << endl;
	for (int i = 0; i < 12; i++) 
	{
		int temp;
		for (int j = 0; j < 11; j++)
		{
			if (Max[j] < Max[j + 1])
			{
				temp = Max[j];
				Max[j] = Max[j + 1];
				Max[j + 1] = temp;
				temp = 0;
			}
		}
	}
	cout << endl;

	cout << Max[0] << endl;
}
}
