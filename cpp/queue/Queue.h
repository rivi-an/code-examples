#pragma once
#include <string>

struct TaskInQueue
{
	int category, time, id;
};

struct LosNode
{
	std::string data;
	LosNode* next = nullptr;
};

typedef TaskInQueue QueueEleType;

class Queue
{
public:
	Queue(int maxElements);
	bool isFullCheck();
	bool isEmptyCheck();
	void addElement(QueueEleType newElement);
	void deleteElement();
	QueueEleType returnElement(int needed);
	int returnCount();
private:
	QueueEleType* queuearray;
	int maxElements, countOfElements;
};

class LosQueue
{
public:
	LosQueue(int maxElements);
	bool isFullCheck();
	bool isEmptyCheck();
	void addElement(std::string newElement);
	void deleteElement();
	std::string returnElement(int needed);
	int returnCount();
private:
	LosNode* head;
	int maxElements, countOfElements;
};

