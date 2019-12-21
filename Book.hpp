#pragma once
namespace ext
{
	static const int BUFFER_SIZE = 20;	
	struct Book
	{

		int Id;
		char Title[BUFFER_SIZE];
		char Author[BUFFER_SIZE];
		float Price;
		int Quantity;
	};

	Book newBook();
	void Change(Book*& book);
	void Search_Title(int count, Book*& book);
	void Sort(Book*& book);
	void Static(Book*& book);
}
