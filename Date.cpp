#include <iostream>
#include "Date.hpp"

using namespace std;
using namespace ext;

namespace ext
{
	enum class Month
	{
		January = 1,
		February,
		March,
		April,
		May,
		June,
		July,
		August,
		September,
		October,
		Novemver,
		December
	};

	int MonthtoInt(Month MM) {
		switch (MM)
		{
		case ext::Month::January:
			return 1;
			break;
		case ext::Month::February:
			return 2;
			break;
		case ext::Month::March:
			return 3;
			break;
		case ext::Month::April:
			return 4;
			break;
		case ext::Month::May:
			return 5;
			break;
		case ext::Month::June:
			return 6;
			break;
		case ext::Month::July:
			return 7;
			break;
		case ext::Month::August:
			return 8;
			break;
		case ext::Month::September:
			return 9;
			break;
		case ext::Month::October:
			return 10;
			break;
		case ext::Month::Novemver:
			return 11;
			break;
		case ext::Month::December:
			return 12;
			break;
		}
	}

	enum class DateFormat
	{
		MonthAsInt,
		MonthAsString
	};

	enum class Season
	{
		Winter,
		Spring,
		Summer,
		Autumn
	};

	enum class SortBy
	{
		Date,
		Season
	};

	struct Date
	{
		int year;
		Month month;
		int day;
	};

	struct TimeDelta
	{
		int delta;
	};

	/*
		Возвращает Юлианскую дату
		https://ru.wikipedia.org/wiki/%D0%AE%D0%BB%D0%B8%D0%B0%D0%BD%D1%81%D0%BA%D0%B0%D1%8F_%D0%B4%D0%B0%D1%82%D0%B0
		раздел "Вычисление номера юлианского дня (JDN) по дате григорианского календаря"
		Тестовые данные					Ожидаемый результат
		1.12.2018					2458454
		1.1.2018					2458120
		1.6.2000					2451697
		21.12.2012					2456283
	*/
	TimeDelta countJND(Date date)
	{
		int a = (14 - MonthtoInt(date.month)) / 12;
		int y = date.year + 4800 - a;
		int m = MonthtoInt(date.month) + 12 * a - 3;
		int answ = (date.day + ((153 * m + 2) / 5) + 365 * y + (y / 4) - (y / 100) + (y / 400) - 32045);
		return TimeDelta{ answ };
	}

	/*
		Рассчитывает количество дней между двумя датами.
		При реализвации используйте CountJND
	*/
	TimeDelta countDistance(Date from, Date to)
	{
		TimeDelta answ = countJND(to) - countJND(from);
		return answ;
	}

	/*
		Выводит в консоль
	*/
	void print(Date data, DateFormat format = DateFormat::MonthAsInt)
	{
		cout << data.day << "/" << MonthtoInt(data.month) << "/" << data.year << endl;
	}
	void print(Month month, DateFormat format = DateFormat::MonthAsInt)
	{

	}
	void print(TimeDelta delta)
	{
		cout << delta.delta << endl;
	}

	/*
		Возвращает сезон (зима, весна, лето, осень) передаваемой даты
	*/
	Season getSeason(Date date)
	{
			switch (date.month)
			{
			case Month::January:
			case Month::February:
			case Month::December:
				return Season::Winter;
				break;
			case Month::March:
			case Month::April:
			case Month::May:
				return Season::Spring;
				break;
			case Month::June:
			case Month::July:
			case Month::August:
				return Season::Summer;
				break;
			case Month::October:
			case Month::Novemver:
			case Month::September:
				return Season::Autumn;
				break;
			default:
				break;
			}
	}
	Season getSeason(Month month)
	{
		if ((static_cast<int>(month) == 12) || (static_cast<int>(month) == 1) || (static_cast<int>(month) == 2))
		{
			return Season::Winter;
		}
		if ((static_cast<int>(month) > 2) & (static_cast<int>(month) < 6))
		{
			return Season::Spring;
		}
		if ((static_cast<int>(month) > 5) & (static_cast<int>(month) < 9))
		{
			return Season::Summer;
		}
		if ((static_cast<int>(month) > 8) & (static_cast<int>(month) < 12))
		{
			return Season::Autumn;
		}
	}

	/*
		Написать перегрузку для следующих логических операторов
	*/
	bool operator == (const Date lhs, const Date rhs)
	{
		return (lhs.day == rhs.day) && (lhs.month == rhs.month) && (lhs.year == rhs.year);
	}
	bool operator != (const Date lhs, const Date rhs)
	{
		return !(lhs == rhs);
	}
	bool operator < (const Date lhs, const Date rhs)
	{
		return ((lhs.day < rhs.day) && ((static_cast<int>(lhs.month)) < (static_cast<int>(rhs.month))) && (lhs.year < rhs.year));
	}
	bool operator <= (const Date lhs, const Date rhs)
	{
		return ((lhs.day <= rhs.day) && ((static_cast<int>(lhs.month)) <= (static_cast<int>(rhs.month))) && (lhs.year <= rhs.year));
	}
	bool operator > (const Date lhs, const Date rhs)
	{
		return ((lhs.day > rhs.day) && ((static_cast<int>(lhs.month)) > (static_cast<int>(rhs.month))) && (lhs.year > rhs.year));
	}
	bool operator >= (const Date lhs, const Date rhs)
	{
		return ((lhs.day >= rhs.day) && ((static_cast<int>(lhs.month)) >= (static_cast<int>(rhs.month))) && (lhs.year >= rhs.year));
	}

	/*
		Написать перегрузку для следующих арифметических операторов
	*/

	Date JDNToDate(TimeDelta delta) {
		Date output;
		int a = delta.delta + 32044;
		int b = ((4 * a) + 3) / 146097;
		int c = a - ((146097 * b) / 4);
		int d = ((4 * c) + 3) / 1461;
		int e = c - ((1461 * d) / 4);
		int m = ((5 * e) + 2) / 153;
		output.day = e - ((153 * m + 2) / 5) + 1;
		output.month = static_cast<Month>(m + 3 - 12 * (m / 10));
		output.year = (100 * b) + d - 4800 + (m / 10);
		return output;
	}

	Date operator + (const Date date, const TimeDelta delta) 
	{
		TimeDelta one = countJND(date);
		return JDNToDate(one + delta);
	}

	Date operator + (const TimeDelta delta, const Date date) {
		TimeDelta one = countJND(date);
		return JDNToDate(one + delta);
	}

	TimeDelta operator + (const TimeDelta lhs, const TimeDelta rhs)
	{
		TimeDelta one;
		one.delta = lhs.delta + rhs.delta;
		return one;
	}

	Date operator - (const Date date, const TimeDelta delta)
	{
		TimeDelta one = countJND(date);
		return JDNToDate(one - delta);
	}
	Date operator - (const TimeDelta delta, const Date date)
	{
		TimeDelta one = countJND(date);
		return JDNToDate(one - delta);
	}
	TimeDelta operator - (const TimeDelta lhs, const TimeDelta rhs)
	{
		TimeDelta one;
		one.delta = lhs.delta - rhs.delta;
		return one;
	}

	TimeDelta operator * (const TimeDelta delta, int multiplier)
	{
		TimeDelta one;
		one.delta = (delta.delta * multiplier);
		return one;
	}
	TimeDelta operator * (int multiplier, const TimeDelta delta)
	{
		TimeDelta one;
		one.delta = (multiplier * delta.delta);
		return one;
	}
	TimeDelta operator / (const TimeDelta delta, int multiplier)
	{
		TimeDelta one;
		one.delta = (delta.delta / multiplier);
	}


	/*-----Часть для домашнего задания №4-----*/

	TimeDelta operator ++ (TimeDelta& delta)
	{
		++delta.delta;
		return delta;
	}
	TimeDelta operator ++ (TimeDelta& delta, int)
	{
		TimeDelta temp = delta;
		++delta.delta;
		return temp;
	}

	TimeDelta operator -- (TimeDelta& delta)
	{
		--delta.delta;
		return delta;
	}
	TimeDelta operator -- (TimeDelta& delta, int)
	{
		TimeDelta temp = delta;
		--delta.delta;
		return temp;
	}
	Date operator ++ (Date& delta)
	{
		delta.day++;
		delta.month = static_cast<Month>(static_cast<int>(delta.month) + 1);
		delta.year++;	
		return delta;
	}
	Date operator ++ (Date& delta, int)
	{
		delta.day++;
		delta.month = static_cast<Month>(static_cast<int>(delta.month) + 1);
		delta.year++;
		return delta;
	}

	Date operator -- (Date& delta)
	{
		delta.day--;
		delta.month = static_cast<Month>(static_cast<int>(delta.month) -1);
		delta.year--;
		return delta;
	}
	Date operator -- (Date& delta, int)
	{
		delta.day--;
		delta.month = static_cast<Month>(static_cast<int>(delta.month) - 1);
		delta.year--;
		return delta;
	}

	/*
		Меняет даты местами
	*/
	void swap(Date& lhs, Date& rhs)
	{
		Date temp;
		temp.day = lhs.day;
		lhs.day = rhs.day;
		rhs.day = temp.day;

		temp.month = lhs.month;
		lhs.month = rhs.month;
		rhs.month = temp.month;
		
		temp.year = lhs.year;
		lhs.year = rhs.year;
		rhs.year = temp.year;
	}

	/*
		Меняет временные интервалы местами
	*/
	void swap(TimeDelta& lhs, TimeDelta& rhs)
	{
		TimeDelta t;
		t.delta = lhs.delta;
		lhs.delta = rhs.delta;
		rhs.delta = t.delta;
	}

	/*
		Возвращает ссылку на большую дату
	*/
	Date& max(Date & lhs, Date & rsh)
	{
		if (lhs > rsh)
		{
			return lhs;
		}
		else
		{
			return rsh;
		}
	}

	/*
		Возвращает указатель на меньшую дату
	*/
	Date& min(Date& lhs, Date& rsh)
	{
		if (lhs < rsh)
		{
			return lhs;
		}
		else
		{
			return rsh;
		}
	}

	/*
		Возвращает указатель на минимальную дату в переданном массиве дат
	*/
	Date& getMinDate(Date dates[], int size)
	{
		Date min = dates[0];

		for (int i = 1; i < size; ++i)
		{
			if (countJND(dates[i]).delta < countJND(min).delta)
			{
				min = dates[i];
			}
		}
		return min;
	}

	/*
		Возвращает указатель на максимальную дату в переданном массиве дат
	*/
	Date& getMaxDate(Date dates[], int size)
	{
		Date max = dates[0];

		for (int i = 1; i < size; ++i)
		{
			if (countJND(dates[i]).delta > countJND(max).delta)
			{
				max = dates[i];
			}
		}
		return max;
	}

	/*
		Сортирует массив дат по указанному критерию
	*/
	void sort(Date dates[], SortBy sortBy = SortBy::Date)
	{

	}

	/*
		Проверяет может ли существовать дата с передаваемыми значениями.
		В случае успеха возвращает true, и заполняет дату по переданному адресу.
		Если дата с переданными параметрами существовать не может,
		возвращает пустой указатель.
	*/

	bool ch(int year)
	{
		bool ch;
		if ((year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0)))
		{
			ch = true;
		}
		else
		{
			ch = false;
		}
		return ch;
	}

	int MD(bool vis, int month)
	{
		int md;
		int mx = month % 2;
		switch (mx)
		{
		case 1:

			if ((month == 9) || (month == 11))
			{
				md = 30;
			}
			else
			{
				md = 31;
			}
			break;
		case 0:
			if ((month == 8) || (month == 10) || (month == 12))
			{
				md = 31;
			}
			else if (month == 2)
			{
				md = 28;
			}
			else
			{
				md = 30;
			}
			break;
		}
		if ((vis) && (month == 2))
		{
			md = 29;
		}
	}

	Date* tryFillDate(int year, int month, int day)
	{
		Date date;
		bool res = false;
		bool hc = ch(year);
		int  md = MD(hc, month), monthx;
		md = MD(hc, month);
		if ((day < md) && (month <= 12))
		{
			date.day = day;
			date.month = static_cast<Month>(month);
			date.year = year;
			res = true;
		}
		else
		{
			res = false;
		}
		return res;
	}
}
