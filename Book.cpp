#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "Book.hpp"

using namespace std;

namespace ext
{
	ostream& operator << (ostream& out, Book book)
	{
		out << "Id: " << book.Id << "; Book title: " << book.Title << "; Author: " << book.Author << "; Price: " << book.Price << "; Quantity" << book.Quantity;
		return out;
	}

	istream& operator >> (istream& in, Book& book)
	{
		in >> book.Id >> book.Title >> book.Author >> book.Price >> book.Quantity;
		return in;
	}

	void swap(Book& book1, Book& book2)
	{
		Book temp;
		temp = book2;
		book2 = book1;
		book1 = temp;
	}

	//добавление новой книги
	Book newBook()
	{
		bool temp = true;
		Book Nbook;
		ofstream FileForId("nextId.txt", iostream::app);

		if (!FileForId.is_open())
		{
			cout << "File cannot be open" << endl;
			temp = false;
		}
		if (temp)
		{
			FileForId << 1000;
			FileForId.close();
		}
		ifstream FileOfId("nextId.txt", iostream::app);
		if (!FileOfId.is_open())
		{
			cout << "File cannot be open" << endl;
			temp = false;
		}
		if (temp)
		{
			FileOfId >> Nbook.Id;
			cout << "Введите название книги" << endl;
			cin >> Nbook.Title;
			cout << "Введите имя автора" << endl;
			cin >> Nbook.Author;
			cout << "Введите цену книги" << endl;
			cin >> Nbook.Price;
			cout << "Введите количество книг" << endl;
			cin >> Nbook.Quantity;
		}
		ofstream Library("books.bin", istream::ate | istream::binary);
		if (!Library.is_open())
		{
			cout << "File cannot be open" << endl;
			temp = false;
		}
		if (temp)
		{
			Library << Nbook;
		}
	}

	//изменение по id
	void Change(Book*& book)
	{
		cout << "Введите id книги: " << endl;
		int count;
		cin >> count;
		int pos = 0;
		bool res = false;
		ifstream Library("books.bin", istream::in | istream::binary);
		Library.seekg(0, ios_base::end);
		int size = 0;
		size = Library.tellg();
		int l = 0;
		int r = size - 1;
		Book temp;
		while (l != r - 1)
		{
			Library.seekg(sizeof(Book) * ((l + r) / 2));
			Library.read(reinterpret_cast<char*>(&temp), sizeof(Book));
			if (count == temp.Id)
			{
				res = true;
				pos = sizeof(Book) * ((l + r) / 2);
				break;
			}
			else
			{
				if (count > temp.Id)
				{
					l = (l + r) / 2;
				}
				else
				{
					r = (l + r) / 2;
				}
			}

		}
		Library.close();

		ifstream Library_ch("books.bin", istream::binary | istream::in);
		Library_ch.seekg(pos);
		Book data;
		Library.read(reinterpret_cast<char*>(&data), sizeof(Book));
		Library_ch.close();

		ofstream Library_nw("books.bin", istream::out | istream::binary | istream::ate);
		Library_nw.seekp(pos);

		cout << "Данные о книгу: " << endl;
		cout << data << endl;

		cout << "Введите новое название книги " << endl;
		cin >> data.Title;
		cout << "Введите нового автора книги " << endl;
		cin >> data.Author;
		cout << "Введите новую цену книги " << endl;
		cin >> data.Price;
		cout << "Введите новое количество книг " << endl;
		cin >> data.Quantity;
		Library_nw.write(reinterpret_cast<char*>(&data), sizeof(Book));

		Library_nw.close();

		if (!res)
		{
			cout << "Книги с id " << count << " нет" << endl;
		}
	}

	//поиск по названию
	void Search_Title(int count, Book*& book)
	{
		string title;
		getline(cin, title);

		Book* ptr = nullptr;
		for (int i = 0; i < count; ++i)
		{
			string temp(book[i].Title);
			if (title == temp)
			{
				ptr = &book[i];
				break;
			}
		}

		if (ptr == nullptr)
		{
			cout << "book with title " << title << " not found" << endl;
		}
		else
		{
			cout << ptr->Id << " " << ptr->Title << " " << ptr->Author << " " << ptr->Price << " " << ptr->Quantity << endl;
		}

	}

	//сортировка по автору и названию
	void Sort(Book*& book)
	{
		ifstream Library_11("books.bin", istream::binary | istream::in);
		Library_11.seekg(0, ios_base::end);
		int size = 0;
		size = Library_11.tellg();
		ofstream Library_temp("temp_books.bin", istream::binary | istream::in);
		Book book0;
		for (int i = 0; i < size / sizeof(Book); ++i)
		{
			Library_11.read(reinterpret_cast<char*>(&book0), sizeof(Book));
			Library_temp.write(reinterpret_cast<char*>(&book0), sizeof(Book));
		}
		ofstream Library_22("books.bin", istream::out | istream::binary | istream::ate);
		Library_11.close();
		Library_22.close();
		Library_temp.close();

		//сортировка по автору
		ifstream Library_1("temp_books.bin", istream::binary | istream::in);
		ofstream Library_2("temp_books.bin", istream::out | istream::binary);
		for (int i = 0; i < size / sizeof(Book); ++i)
		{
			Book book1;
			Book book2;
			for (int j = 0; j < size / sizeof(Book); ++j)
			{
				
				Library_1.read(reinterpret_cast<char*>(&book1), sizeof(Book));
				Library_1.read(reinterpret_cast<char*>(&book2), sizeof(Book));
				if (book1.Author > book2.Author)
				{

					swap(book1, book2);
					Library_2.write(reinterpret_cast<char*>(&book1), sizeof(Book));
					Library_2.write(reinterpret_cast<char*>(&book2), sizeof(Book));
					
				}
			}
		}
		Library_1.close();
		Library_2.close();

		//сортировка по названию
		ifstream Library_3("temp_books.bin", istream::binary | istream::ate);
		ofstream Library_4("temp_books.bin", istream::out | istream::binary);
		for (int i = 0; i < size / sizeof(Book); ++i)
		{
			Book book1;
			Book book2;
			
			for (int j = 0; j < size / sizeof(Book); ++j)
			{
				Library_3.read(reinterpret_cast<char*>(&book1), sizeof(Book));
				Library_3.read(reinterpret_cast<char*>(&book2), sizeof(Book));
				if ((book1.Title > book2.Title) && (book1.Author == book2.Author))
				{			
					swap(book1, book2);
					Library_4.write(reinterpret_cast<char*>(&book1), sizeof(Book));
					Library_4.write(reinterpret_cast<char*>(&book2), sizeof(Book));
				}
			}
		}
		Library_3.close();
		Library_4.close();

		cout << "Отсортированный список: " << endl;

		ifstream Library_5("books.bin", istream::binary | istream::in);
		Book book3;
		for (int j = 0; j < size / sizeof(Book); ++j)
		{
			Library_5.read(reinterpret_cast<char*>(&book3), sizeof(Book));
			cout << book3 << endl;
		}
		Library_5.close();
	}

	//статистика

	void Static(Book*& book)
	{
		ifstream Library("books.bin", istream::binary | istream::in);
		Library.seekg(0, ios_base::end);
		int size = 0;
		float pr_sum = 0;
		int q_sum = 0;
		size = Library.tellg();
		Library.seekg(0);
		Book book1;
		for (int i = 0; i < size / sizeof(Book); ++i)
		{
			Library.read(reinterpret_cast<char*>(&book1), sizeof(Book));
			pr_sum += book1.Price;
			q_sum += book1.Quantity;
			Library.seekg(i * sizeof(Book));
		}
		cout << "Общая стоимость всех книг: " << pr_sum << endl;
		cout << "Всего книг в библиотеке: " << q_sum << endl;
		Library.close();
	}
}
