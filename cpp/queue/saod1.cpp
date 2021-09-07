#include "Queue.h"
#include <string>
#include <iostream>

using namespace std;

void testOfQueue()
{
	cout << "Введите максимальный размер очереди: ";
	int a;
	QueueEleType b;
	bool exit = 0;
	cin >> a;
	Queue queue(a);
	cout << "1 - проверить, пуста ли очередь\n2 - проверить, заполнена ли очередь\n3 - добавить элемент в очередь\n4 - удалить элемент из очереди\n5 - Вывести элемент, соответстующий введенному индексу\n6 - завершить работу\n";
	while (true)
	{
		if (exit) return;
		cout << "Введите номер необходимой операции: ";
		cin >> a;
		switch (a)
		{
		case 1:
			if (queue.isEmptyCheck())
				cout << "Очередь пуста\n";
			else
				cout << "Очередь не пуста\n";
			break;
		case 2:
			if (queue.isFullCheck())
				cout << "Очередь заполнена\n";
			else
				cout << "Очередь не заполнена\n";
			break;
		case 3:
			cout << "Введите новый элемент: ";
			cin >> b.category;
			queue.addElement(b);
			break;
		case 4:
			queue.deleteElement();
			break;
		case 5:
			cout << "Введите индекс искомого элемента: ";
			cin >> a;
			if (queue.returnCount()>a && a>=0)
				cout << "Искомый элемент: " << queue.returnElement(a).category << "\n";
			else
				cout << "Нет элемента с таким индексом\n";
			break;
		case 6:
			exit=1;
			break;
		default:
			cout << "Некорректный номер, повторите ввод\n";
			break;
		}
	}
}


void task2()
{
	cout << "Введите размер очереди: ";
	int a;
	cin >> a;
	Queue tasks(a);
	cout << "Введите очередь поэлементно в формате: номер_категории время_выполнения индивидуальный_номер:\n";
	TaskInQueue inpt, outpt;
	for (int i = 0; i < a; i++)
	{
		cin >> inpt.category >> inpt.time >> inpt.id;
		tasks.addElement(inpt);
	}
	int time1 = 0, time2 = 0, time3 = 0;
	int curPriority = 1;
	while (curPriority!=4)
	{
		for (int i = 0; i < a; i++)
		{
			outpt = tasks.returnElement(i);
			if (outpt.category == curPriority)
			{
				cout << "Номер сотрудника: " << outpt.id << " Время выполнения задачи: " << outpt.time << " Приоритет сотрудника: " << outpt.category << "\n"; \
				if (curPriority == 1)
					time1 += outpt.time;
				else if (curPriority == 2)
					time2 += outpt.time;
				if (curPriority == 3)
					time3 += outpt.time;
			}
		}
		curPriority++;
	}
	cout << "Итоговое время выполнения для каждой категории:\n1 - " << time1 << "\n2 - " << time2 << "\n3 - " << time3 <<"\n";
}

void testOfLosQueue()
{
	cout << "Введите максимальный размер очереди: ";
	int a;
	string b;
	bool exit = 0;
	cin >> a;
	LosQueue losQueue(a);
	cout << "1 - проверить, пуста ли очередь\n2 - проверить, заполнена ли очередь\n3 - добавить элемент в очередь\n4 - удалить элемент из очереди\n5 - Вывести элемент, соответстующий введенному индексу\n6 - завершить работу\n";
	while (true)
	{
		if (exit) return;
		cout << "Введите номер необходимой операции: ";
		cin >> a;
		switch (a)
		{
		case 1:
			if (losQueue.isEmptyCheck())
				cout << "Очередь пуста\n";
			else
				cout << "Очередь не пуста\n";
			break;
		case 2:
			if (losQueue.isFullCheck())
				cout << "Очередь заполнена\n";
			else
				cout << "Очередь не заполнена\n";
			break;
		case 3:
			cout << "Введите новый элемент: ";
			cin >> b;
			losQueue.addElement(b);
			break;
		case 4:
			losQueue.deleteElement();
			break;
		case 5:
			cout << "Введите индекс искомого элемента: ";
			cin >> a;
			if (losQueue.returnCount() > a && a >= 0)
				cout << "Искомый элемент: " << losQueue.returnElement(a) << "\n";
			else
				cout << "Нет элемента с таким индексом\n";
			break;
		case 6:
			exit = 1;
			break;
		default:
			cout << "Некорректный номер, повторите ввод\n";
			break;
		}
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	cout << "1 - тест функционала очереди на основе массива\n2 - задача №2, реализована очередью на основе массива\n3 - тест функционала очереди на основе ЛОС\nВведите номер необходимой операции: ";
	int menu;
	cin >> menu;
	while (menu != 4)
	{
		switch (menu)
		{
		case 1:
			testOfQueue();
			break;
		case 2:
			task2();
			break;
		case 3:
			testOfLosQueue();
			break;
		case 4:
			break;
		default:
			cout << "Некорректный номер\n";
			break;
		}
	cout << "Введите номер необходимой операции: ";
	cin >> menu;
	}

}
