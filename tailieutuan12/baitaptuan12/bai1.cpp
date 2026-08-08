#include<fstream>
#include <queue>
#include<iostream>
using namespace std;


struct BNode
{
    int data;
    BNode *Left;
    BNode *Right;
};
struct BTree
{
    BNode *root;
    int size;
};
BNode *CreateNode12(int data);
BNode* CreateNode12(int data)
{
    BNode *node = new BNode;
    node->data = data;
    node->Left = NULL;
    node->Right = NULL;
    return node;
}

void Initialize(BTree &t);
void Initialize(BTree &t)
{
    t.root = NULL;
    t.size = 0;
}
int InsertNode(BNode* &p,int x);
int InsertNode(BNode* &p,int x)
{
    if (p!=NULL)
    {
        if (p->data == x)
            return 0;//x already exist in the tree
        else if (x < p->data)
            return InsertNode(p->Left,x);
        else if (x > p->data)
            return InsertNode(p->Right,x);
    } else // tree has no root yet
    {
        p = CreateNode12(x);
        if (p == NULL)
        {
            return -1;//cant create new node
        }
        return 1;
    }
}
void CreateBSTree(BTree &t,ifstream &fin);
void CreateBSTree(BTree &t,ifstream &fin)
{
    int x;
    while (fin >> x)
    {
        InsertNode(t.root,x);
    }
}
int main()
{
    BTree t;
    ifstream fin("input.txt");
    Initialize(t);
    CreateBSTree(t,fin);
}