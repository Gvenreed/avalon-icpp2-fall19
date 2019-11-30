#include "CharArray.hpp"

namespace ext
{
	int countLength(charArray str)
	{
		int length = 0;
		while (str[length] != '\0')
		{
			++length;
		}

		return length;
	}

	char characterAt(charArray str, int number)
	{
		return str[number - 1];
	}

	void concatenate(charArray& first, charArray second)
	{
		int lengthFirst = countLength(first);
		int lengthSecond = countLength(second);

		charArray result = new char[lengthFirst + lengthSecond + 1];

		for (int i = 0; i < lengthFirst; ++i)
		{
			result[i] = first[i];
		}
		for (int i = 0; i < lengthSecond; ++i)
		{
			result[lengthFirst + i] = second[i];
		}

		result[lengthFirst + lengthSecond] = '\0';

		delete[] first;
		first = result;
	}

	void append(charArray& first, char second)
	{
		int lengthFirst = countLength(first);

		charArray result = new char[lengthFirst + 2];

		for (int i = 0; i < lengthFirst; ++i)
		{
			result[i] = first[i];
		}
		result[lengthFirst + 1] = second;

		result[lengthFirst + 2] = '\0';

		delete[] first;
		first = result;
	}

	void substring(charArray& first, int p, int l)
	{

		charArray result = new char[l];
		for (int i = p; i < p + l; ++i)
		{
			result[i - p] = first[i];
		}
		result[l] = '/0';
	}

	void replaceString(charArray& first, charArray& second, charArray& third)
	{
		int lengthFirst = countLength(first);
		int lengthSecond = countLength(second);
		int lengthThird = countLength(third);

		int num[16];
		int res = 0;
		int k = 0;
		int dq = 0;
		for (int i = 0; i < lengthFirst; i++)
		{
			int temp = 0;
			k = lengthSecond * i;
			for (int j = 0; j < lengthSecond; j++)
			{
				if (first[k] == second[j])
				{
					temp += 1;
				}
				else
				{
					temp = 0;					
				}
				k += 1;
			}
			if (temp == lengthSecond)
			{
				res += 1;
				num[dq] = k;
				dq += 1;
			}
		}
		charArray result = new char[lengthFirst + res * (-lengthSecond +lengthThird)-1];
		int g = 0;
		int rr = 0;
		int u;
		for (int i = 0; i < lengthFirst + res * (-lengthSecond +lengthThird); ++i)
		{
			
			if ((i + lengthSecond) == num[rr])
			{
				for (int j = 0; j < lengthThird; ++j)
				{
					result[g] = third[j];
					g += 1;
				}
				rr += 1;
				u = 0;
			}
			else
			{
				result[g] = first[num[rr - 1]+u+rr-1];
				g += 1;
				u += 1;
			}
		}
		result[g] = '\0';
	}
}
