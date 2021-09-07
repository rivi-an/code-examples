#include "Queue.h"
#include <iostream>
using namespace std;
Queue::Queue(int maxElements)
{
	queuearray = new QueueEleType[maxElements];
	countOfElements = 0;
	this->maxElements = maxElements;
}

bool Queue::isEmptyCheck()
{
	if (countOfElements == 0) return 1;
	return 0;
}

bool Queue::isFullCheck()
{
	if (countOfElements == maxElements) return 1;
	return 0;
}

void Queue::addElement(QueueEleType newElement)
{
	if (!isFullCheck())
	{
		queuearray[countOfElements] = newElement;
		countOfElements++;
		return;
	}
	cout << "Невозможно добавить элемент, очередь заполнена\n";
	return;
}

void Queue::deleteElement()
{
	if (!isEmptyCheck())
	{
		for (int i = 1; i < countOfElements; i++)
		{
			queuearray[i - 1] = queuearray[i];
		}
		countOfElements--;
		cout << "Элемент успешно удалён\n";
		return;
	}
	cout << "Невозможно удалить элемент, очередь уже пуста\n";
	return;
}

QueueEleType Queue::returnElement(int needed)
{
		return queuearray[needed];
}

int Queue::returnCount()
{
	return countOfElements;
}

LosQueue::LosQueue(int maxElements)
{
	countOfElements = 0;
	this->maxElements = maxElements;
}

bool LosQueue::isEmptyCheck()
{
	if (countOfElements == 0) return 1;
	return 0;
}

bool LosQueue::isFullCheck()
{
	if (countOfElements == maxElements) return 1;
	return 0;
}

void LosQueue::addElement(string newElement)
{
	if (!isFullCheck())
	{
		if (isEmptyCheck())
		{
			head = new LosNode;
			head->data = newElement;
		}
		else
		{
			LosNode* tmp = head;
			while (tmp->next != nullptr)
				tmp = tmp->next;
			tmp->next = new LosNode;
			tmp->next->data = newElement;
		}
		countOfElements++;
		return;
	}
	cout << "Невозможно добавить элемент, очередь заполнена\n";
	return;
}


void LosQueue::deleteElement()
{
	if (!isEmptyCheck())
	{
		head = head->next;
		countOfElements--;
		cout << "Элемент успешно удалён\n";
		return;
	}
	cout << "Невозможно удалить элемент, очередь уже пуста\n";
	return;
}

string LosQueue::returnElement(int needed)
{
		LosNode* tmp = head;
		for (int i = 0; i < needed; i++)
		{
			tmp = tmp->next;
		}
		return tmp->data;
}

int LosQueue::returnCount()
{
	return countOfElements;
}