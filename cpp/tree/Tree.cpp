#include "Tree.h"
#include <iostream>


Node* Tree::findGrandparent(Node* n)
{
	{
		if ((n != nullptr) && (n->parent != nullptr))
			return n->parent->parent;
		else
			return nullptr;
	}
}

Node* Tree::findUncle(Node* n)
{
	Node* g = findGrandparent(n);
	if (g == nullptr)
		return nullptr;
	if (n->parent == g->left)
		return g->right;
	else
		return g->left;
}

Node* Tree::returnRoot()
{
	return root;
}

void Tree::leftRotate(Node* n)
{
	Node* pivot = n->right;
	pivot->parent = n->parent;
	if (pivot->parent == nullptr)
		root = pivot;
	if (n->parent != nullptr) {
		if (n->parent->left == n)
			n->parent->left = pivot;
		else
			n->parent->right = pivot;
	}
	n->right = pivot->left;
	if (pivot->left != nullptr)
		pivot->left->parent = n;
	n->parent = pivot;
	pivot->left = n;
}

void Tree::rightRotate(Node* n)
{
	Node* pivot = n->left;
	pivot->parent = n->parent;
	if (pivot->parent == nullptr)
		root = pivot;
	if (n->parent != nullptr) {
		if (n->parent->left == n)
			n->parent->left = pivot;
		else
			n->parent->right = pivot;
	}
	n->left = pivot->right;
	if (pivot->right != nullptr)
		pivot->right->parent = n;
	n->parent = pivot;
	pivot->right = n;
}

void Tree::recursivePartOfAdd(Node* n, Node* current)
{
	if (current == nullptr)
	{
		root = n;
		root->red = 0;
	}
	else if (n->data <= current->data)
	{
		if (current->left != nullptr)
			recursivePartOfAdd(n, current->left);
		else
		{
			current->left = n;
			current->left->parent = current;
			addElementCase1(current->left);
		}
	}
	else if (n->data>current->data)
	{
		if (current->right != nullptr)
			recursivePartOfAdd(n, current->right);
		else
		{
			current->right = n;
			current->right->parent = current;
			addElementCase1(current->right);
		}
	}
}

void Tree::addElementCase1(Node* n)
{
	if (n->parent == nullptr)
	{
		n->red = 0;
	}
	else
	{
		addElementCase2(n);
	}
}

void Tree::addElementCase2(Node* n)
{
	if (!n->parent->red)
		return;
	else
		addElementCase3(n);
}

void Tree::addElementCase3(Node* n)
{
	Node* u = findUncle(n);
	if (u != nullptr && u->red)
	{
		n->parent->red = 0;
		u->red = 0;
		Node* g = findGrandparent(n);
		g->red = 1;
		addElementCase1(g);
	}
	else
	{
		addElementCase4(n);
	}
}

void Tree::addElementCase4(Node* n)
{
	Node* g = findGrandparent(n);
	if (n == n->parent->right && n->parent == g->left)
	{
		leftRotate(n->parent);
		n = n->left;
	}
	else if (n == n->parent->left && n->parent == g->right)
	{
		rightRotate(n->parent);
		n = n->right;
	}
	addElementCase5(n);
}

void Tree::addElementCase5(Node* n)
{
	Node* g = findGrandparent(n);

	n->parent->red = 0;
	g->red = 1;
	if (n == n->parent->left && n->parent == g->left) {
		rightRotate(g);
	}
	else {
		leftRotate(g);
	}
}

void Tree::symmetric(Node* n)
{
	if (n != nullptr)
	{
		symmetric(n->left);
		std::cout << n->data << " ";
		symmetric(n->right);
	}
}

void Tree::width(std::vector<Node*> qn)
{
	int toPrint = qn.size();
	for (int i = 0; i < toPrint; i++)
	{
		if (qn[i]->left != nullptr)
			qn.push_back(qn[i]->left);
		if (qn[i]->right != nullptr)
			qn.push_back(qn[i]->right);
	}
	for (int i = 0; i < toPrint; toPrint--)
	{
		std::cout << qn[i]->data<<" ";
		qn.erase(qn.begin());
	}
	if (!qn.empty())
		width(qn);
}

int Tree::sumOfDatas(Node* n, int currentSum)
{
	if (n != nullptr)
	{
		currentSum += n->data;
		currentSum = sumOfDatas(n->left, currentSum);
		currentSum = sumOfDatas(n->right, currentSum);
	}
	return currentSum;
}

int Tree::nodeCount(Node* n, int currentCount)
{
	if (n != nullptr)
	{
		currentCount = nodeCount(n->left, currentCount);
		currentCount++;
		currentCount = nodeCount(n->right, currentCount);
	}
	return currentCount;
}

void Tree::wayFinder(Node* n, int neededData, int currentLength)
{
	if (n == nullptr)
		std::cout << "Узел с введенным значением не найден\n";
	else if (neededData == n->data)
		std::cout << "Длина пути равна " << currentLength<<"\n";
	else if (neededData < n->data)
		wayFinder(n->left, neededData, currentLength + 1);
	else
		wayFinder(n->right, neededData, currentLength + 1);
}

