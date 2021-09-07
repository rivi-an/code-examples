#pragma once
#include <vector>

struct Node
{
	int data=0;
	bool red = 1;
	Node* left = nullptr;
	Node* right = nullptr;
	Node* parent = nullptr;
};

class Tree
{
private:
	Node* root = nullptr;
public:
	Node* findGrandparent(Node* n);
	Node* findUncle(Node* n);
	Node* returnRoot();
	void leftRotate(Node* n);
	void rightRotate(Node* n);
	void recursivePartOfAdd(Node* n, Node* current);
	void addElementCase1(Node* n);
	void addElementCase2(Node* n);
	void addElementCase3(Node* n);
	void addElementCase4(Node* n);
	void addElementCase5(Node* n);
	void symmetric(Node* n);
	void width(std::vector <Node*> qn);
	int sumOfDatas(Node* n, int currentSum = 0);
	int nodeCount(Node* n, int currentCount=0);
	void wayFinder(Node* n, int neededData, int currentLength = 0);
};

