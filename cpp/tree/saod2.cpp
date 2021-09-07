#include <iostream>
#include "Tree.h"

using namespace std;
int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "1 - Вставка нового элемента\n2 - Симметричный обход дерева\n3 - Обход в ширину\n4 - среднее арифметическое\n5 - расчет длины пути до элемента\nВедите операцию: ";
    int menu;
    Tree tree;
    Node* n;
    vector <Node*> qn;
    cin >> menu;
    while (menu != 6)
    {
        switch (menu)
        {
        case 1:
            cout << "Введите значение нового элемента: ";
            n = new Node;
            cin >> n->data;
            tree.recursivePartOfAdd(n, tree.returnRoot());
            break;
        case 2:
            tree.symmetric(tree.returnRoot());
            break;
        case 3:
            qn.push_back(tree.returnRoot());
            tree.width(qn);
            break;
        case 4:
            cout <<tree.sumOfDatas(tree.returnRoot(), 0) / tree.nodeCount(tree.returnRoot()) << "\n";
            break;
        case 5:
            cout << "Введите искомое значение: ";
            cin >> menu;
            tree.wayFinder(tree.returnRoot(),menu);
            break;
        default:
            break;
        }
        cout << "Ведите операцию: ";
        cin >> menu;
    }
}
