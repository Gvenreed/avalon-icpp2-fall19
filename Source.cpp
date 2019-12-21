#include <iostream>
#include <fstream>
#include <string>

using namespace std;

static const int BUFFER_SIZE = 20;

struct Book
{
	
	int Id;
	char Title[BUFFER_SIZE];
	char Author[BUFFER_SIZE];
	float Price;
	int Quantity;
};

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

void Search_Title (int count, Book*& book)
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

int Search_Id(int l, int r, Book*& book, int count)
{
	bool res = false;
	ifstream Library("books.bin", istream::in | istream::binary);
	Book data;
	while (l != r - 1)
	{
		Library.seekg(sizeof(Book)*((l + r) / 2));
		Library >> data;

		if (count == data.Id)
		{
			res = true;
			return sizeof(Book)*((l + r) / 2);
			break;
		}
		else
		{
			if (count > data.Id)
			{
				l = (l + r) / 2;
			}
			else
			{
				r = (l + r) / 2;
			}
		}

	}
	if (!res)
	{
		cout << "Книги с id " << count << " нет" << endl;
	}
	Library.close();
}

int main()
{
	ifstream Library ("books.bin", istream::in | istream::binary);

	if (!Library.is_open())
	{
		cout << "File cannot be open" << endl;
		return 1;
	}

	Library.seekg(0, ios_base::end);
	int size = Library.tellg();
	int count = size / sizeof(Book);
	Book* book = new Book[count];
	Library.read(reinterpret_cast<char*>(book), sizeof(Book) * count);

//изменение по id
	int id;
	cin >> id;
	
	Library.seekg(id);

	Library.close();
}
