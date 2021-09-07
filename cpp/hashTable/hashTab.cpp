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
	std::cout << "Попытка добавить элемент на позицию " << currentPosToPush << "\n";
	while (hashTab[currentPosToPush].phoneNumber != "empty")
	{
		if (hashTab[currentPosToPush].phoneNumber == newElement.phoneNumber)
		{
			failed = 1;
			std::cout << "Пользователь с данным номерном уже сохранен в таблице\n";
			break;
		}
		currentPosToPush =(currentPosToPush + movePos) % maxSize;
		movePos += 2;
		counter++;
		std::cout << "Коллизия! Смещение на позицию " << currentPosToPush<<"\n";
		if (counter == maxSize)
		{
			failed = 1;
			std::cout << "Ресурс таблицы исчерпан, невозможно продолжить заполнение\n";
			break;
		}
	}
	if (!failed)
	{
		hashTab[currentPosToPush] = newElement;
		std::cout << "Элемент добавлен на позицию " << currentPosToPush << "\n";
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
		std::cout << "Пользователь найден на позиции " << currentPosToLook << ", его адрес: " << hashTab[currentPosToLook].address << "\n";
	else
		std::cout << "Пользователm не найден\n";
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
		std::cout << "Пользователь найден на позиции " << currentPosToLook << " и удалён\n";
		hashTab[currentPosToLook].phoneNumber = "deleted";
		hashTab[currentPosToLook].address = "deleted";
	}
	else
		std::cout << "Пользователь не найден\n";
}

void HashTabInterface::printTab()
{
	std::cout << "Позиция   Номер    Адрес\n";
		for (int i = 0; i < maxSize; i++)
		{
			std::cout << i<<"         ";
			std::cout<<hashTab[i].phoneNumber<<"    ";
			std::cout << hashTab[i].address << "\n";
		}
}
