#include "hashTab.h"

int HashTabInterface::hashFunc(std::string key)
{
	int tmp = 0;
	for (int i = 0; i < 10; i++)
	{
		tmp += (int)key[i];
		tmp /= ((int)key[i] - 47);
	}
	return tmp % maxSize;
}

HashTabInterface::HashTabInterface(int maxSize)
{
	this->maxSize = maxSize;
	hashTab = new Node[maxSize];
}

void HashTabInterface::pushElement(Node newElement)
{
	int currentPosToPush = hashFunc(newElement.phoneNumber), movePos=1, counter = 0;
	bool failed = 0;
	std::cout << "������� �������� ������� �� ������� " << currentPosToPush << "\n";
	while (hashTab[currentPosToPush].phoneNumber != "empty")
	{
		if (hashTab[currentPosToPush].phoneNumber == newElement.phoneNumber)
		{
			failed = 1;
			std::cout << "������������ � ������ �������� ��� �������� � �������\n";
			break;
		}
		currentPosToPush =(currentPosToPush + movePos) % maxSize;
		movePos += 2;
		counter++;
		std::cout << "��������! �������� �� ������� " << currentPosToPush<<"\n";
		if (counter == maxSize)
		{
			failed = 1;
			std::cout << "������ ������� ��������, ���������� ���������� ����������\n";
			break;
		}
	}
	if (!failed)
	{
		hashTab[currentPosToPush] = newElement;
		std::cout << "������� �������� �� ������� " << currentPosToPush << "\n";
	}

}

void HashTabInterface::findElement(std::string lf)
{
	int currentPosToLook = hashFunc(lf), movePos = 1;
	while (hashTab[currentPosToLook].phoneNumber != "empty" && hashTab[currentPosToLook].phoneNumber!= lf)
	{
		currentPosToLook = (currentPosToLook + movePos) % maxSize;
		movePos += 2;
	}
	if (hashTab[currentPosToLook].phoneNumber == lf)
		std::cout << "������������ ������ �� ������� " << currentPosToLook << ", ��� �����: " << hashTab[currentPosToLook].address << "\n";
	else
		std::cout << "�����������m �� ������\n";
}

void HashTabInterface::deleteElement(std::string lfd)
{
	int currentPosToLook = hashFunc(lfd), movePos = 1;
	while (hashTab[currentPosToLook].phoneNumber != "empty" && hashTab[currentPosToLook].phoneNumber != lfd)
	{
		currentPosToLook = (currentPosToLook + movePos) % maxSize;
		movePos += 2;
	}
	if (hashTab[currentPosToLook].phoneNumber == lfd)
	{
		std::cout << "������������ ������ �� ������� " << currentPosToLook << " � �����\n";
		hashTab[currentPosToLook].phoneNumber = "deleted";
		hashTab[currentPosToLook].address = "deleted";
	}
	else
		std::cout << "������������ �� ������\n";
}

void HashTabInterface::printTab()
{
	std::cout << "�������   �����    �����\n";
		for (int i = 0; i < maxSize; i++)
		{
			std::cout << i<<"         ";
			std::cout<<hashTab[i].phoneNumber<<"    ";
			std::cout << hashTab[i].address << "\n";
		}
}
