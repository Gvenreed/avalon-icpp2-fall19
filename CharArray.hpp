#pragma once

namespace ext
{
	using charArray = char*;

	char characterAt(charArray array, int number);
	void concatenate(charArray & first, charArray second);
	void append(charArray& first, char second);
	void substring(charArray& first, int p, int l);
}
