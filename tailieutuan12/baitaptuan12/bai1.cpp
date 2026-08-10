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
void Descend(BNode* p, queue<int>& Q);
void Descend(BNode* p, queue<int>& Q)
{
    if (p == NULL)
    {
        return;
    }
    Descend(p->Right,Q);
    Q.push(p->data);
    Descend(p->Left,Q);
}

bool Search(BNode* p, int x);
bool Search(BNode* p, int x)
{
    if (p == NULL)//to leaf node not found return false
    {
        return false;
    }
    if (p->data == x)
        return true;//found return true
    if (x < p->data)
        return Search(p->Left,x);//lower go left
    return Search(p->Right,x);//upper go right
}
int SumLeaves(BNode* p);
int SumLeaves(BNode* p)
{
    if (p == NULL)
    {
        return 0;
    }
    if (p->Left == NULL && p->Right == NULL)
    {
        return p->data;
    }
    return SumLeaves(p->Left) + SumLeaves(p->Right);
}
int findMin(BNode* p);
int findMin(BNode* p)
{
    if (p == NULL)
        return 0;
    while (p->Left != NULL)
    {
        p = p->Left;
    }
    if (p->Left == NULL)
    {
        return p->data;
    }
}
int findMax(BNode* p);
int findMax(BNode* p)
{
    if (p == NULL)
        return 0;
    while (p->Right != NULL)
        p = p->Right;
    if (p->Right == NULL)
        return p->data;
}
int GetHeight(BNode* p);
int GetHeight(BNode* p)
{
    if (p == NULL)
        return 0;
    int a = GetHeight(p->Left);
    int b = GetHeight(p->Right);
    int max = a > b ? a : b;
    return (max + 1);
}
BNode* GetMostLeft(BNode* p);
BNode* GetMostLeft(BNode* p)
{
    if (p == NULL)
        return 0;
    if (p->Left == NULL && p->Right == NULL)
        return p;
    BNode* result = GetMostLeft(p->Left);
    if (result != NULL)
        return result;
    return GetMostLeft(p->Right);
}
BNode* GetMostRight(BNode* p)
{
    if (p == NULL)
        return 0;
    if (p->Left == NULL && p->Right == NULL)
        return p;
    BNode* result = GetMostRight(p->Right);
    if (result != NULL)
        return result;
    return GetMostRight(p->Left);
}
void swapLeaves(BTree& t);
void swapLeaves(BTree& t)
{
    if (t.root == NULL)
        return;
    BNode* left = GetMostLeft(t.root);
    BNode* right = GetMostRight(t.root);
    if (left == NULL || right == NULL)
        return;
    int temp = left->data;
    left->data = right->data;
    right->data = temp;
}
int main()
{
    BTree t;
    ifstream fin("input.txt");
    Initialize(t);
    CreateBSTree(t,fin);
    queue<int> Q;
    Descend(t.root, Q);
    int needSearch;
    cout<<"Nhap can tim"<<endl;
    cin>>needSearch;
    bool found = Search(t.root,needSearch);
    int sumResult = SumLeaves(t.root);
    cout<<"Tong la "<<sumResult<<endl;
    int min = findMin(t.root);
    cout << "Min = " << min << endl;
    int max = findMax(t.root);
    cout << "Max = " << max << endl;
    int Height = GetHeight(t.root);
    cout << "Height = " << Height << endl;
    swapLeaves(t);
}
