#pragma once
#include <iostream>

struct Node
{
	std::string phoneNumber="empty", address="empty";
	//bool deleted = 0;
};
class HashTabInterface
{
private:

	Node* hashTab;
	int maxSize=0;
	int hashFunc(std::string key);
	//void moveIfCollision();
public:
	HashTabInterface(int maxSize);
	void pushElement(Node newElement);
	void findElement(std::string lf);
	void deleteElement(std::string lfd);
	void printTab();
};

