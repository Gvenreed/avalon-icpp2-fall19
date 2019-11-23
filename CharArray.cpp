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
}
