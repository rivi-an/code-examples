#include <iostream>
#include "hashTab.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	int menu;
	cout << "Введите максимальный размер таблицы: ";
	cin >> menu;
	HashTabInterface tab(menu);
	Node workwith;
	cout << "1 - вставка элемента в таблицу\n2 - удаление элемента из таблицы\n3 - поиск элемента в таблице\n4 - вывод таблицы\n5 - выход из программы\nВведите номер операции: ";
	cin >> menu;
	while (menu!=5)
	{
		switch (menu)
		{
		case 1:
			cout << "Введите номер: ";
			cin >> workwith.phoneNumber;
			cout << "Введите адрес: ";
			cin >> workwith.address;
			tab.pushElement(workwith);
			break;
		case 2:
			cout << "Введите номер: ";
			cin >> workwith.phoneNumber;
			tab.deleteElement(workwith.phoneNumber);
			break;
		case 3:
			cout << "Введите номер: ";
			cin >> workwith.phoneNumber;
			tab.findElement(workwith.phoneNumber);
			break;
		case 4:
			tab.printTab();
			break;
		default:
			cout << "Некорректный ввод, повторите попытку\n";
			break;
		}
		cout << "Введите номер операции: ";
		cin >> menu;
	}
}
