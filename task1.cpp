#include <stdio.h>
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
	printf("%s%5s%10s%5s%20s%15s%15s", str, dq, str2, dq, str3, dq, str4);
	printf("\n");
	printf("%19s%8s%7s%13s%4s%15s%3s%16s", dq, str5, dq, str6, dq, str7, dq, str8);
	printf("\n");
	for (int i = 0; i < 91; ++i)
	{
		printf("-");
	}
	printf("\n");
	int s, s1, s2;
	s = sizeof(bool);
	s1 = 0;
	s2 = 1;
	printf("%s%15s%14d%s", str9, dq, s, dq, s1, dq, s2);
}
