#include <iostream>
#include <fstream>
#include <string>
#include "Book.hpp"

using namespace std;
using namespace ext;


int main()
{
	//menu
	int num = 0;
	cout << "Чтобы запустить добавление книги нажмите 1" << endl;
	cout << "Чтобы запустить редактирование книги (по id) нажмите 2" << endl;
	cout << "Чтобы запустить поиск книги (по названию) нажмите 3" << endl;
	cout << "Чтобы запустить отсортированный просмотр книг нажмите 4" << endl;
	cout << "Чтобы открыть статистику количества книг в библиотеке и общюю стоимость всех книг нажмите 5" << endl;
	cin >> num;
	switch (num)
	{
	case 1 : Book newBook();
		break;
	case 2: void Change(Book * &book);
		break;
	case 3: void Search_Title(int count, Book * &book);
		break;
	case 4: void Sort(Book * &book);
		break;
	case 5 : void Static(Book * &book);
		break;
	default :
		cout << "Ошибка ввода" << endl;
	}
}
