#include <iostream>
#include <string.h>

using namespace std;
struct BNode
{
    int data;
    BNode* left;
    BNode* right;

};
struct BTree
{
    BNode* root;
    int size;
};
//dclare
BNode* CreateNode(int data);

BNode* CreateNode(int data)
{
    BNode* Node = new BNode;
    if (Node!=NULL)
    {
        Node->data=data;//assign its data
        Node->left=NULL;//set left to null
        Node->right=NULL;//set right to null
    }
    return Node;
}
void Initialize(BTree& Tree);

void Initialize(BTree& Tree)
{
    Tree.root=NULL;
    Tree.size=0;
}

void CreateBTree(BNode* &p, int x);

void CreateBTree(BNode*& p, int x)
{
    if (x == -1)
        return;//x là leaf node (null external nodes)
    p = CreateNode(x); //create new node with x as data
    if (p!=NULL)
    {

    }
}

