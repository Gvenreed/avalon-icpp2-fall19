#include "Date.hpp"

namespace ext {

	TimeDelta countJND(Date date)
	{
		{
			int month, g, y2, month2, res;
			Date date2;
			month = static_cast<int>(date.month);
			g = (14 - month) / 12;
			y2 = date.year + 4800 - g;
			month2 = month + 12 * g - 3;
			res = date.day + ((153 * month2 + 2) / 5) + 365 * y2 + (y2 / 4) - (y2 / 100) + (y2 / 400) - 32045;
			date2.day = date.day;
			date2.month = static_cast<Month>(month + 12 * g - 3);
			date2.year = 365 * y2 + (y2 / 4) - (y2 / 100) + (y2 / 400) - 32045;
		}
	}
	TimeDelta countDistance(Date from, Date to)
	{

	}
}
