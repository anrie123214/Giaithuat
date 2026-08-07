#include <iostream>
#include <string.h>
#include <fstream>
#include <queue>
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

void CreateBTree(BTree &t, ifstream &fin);

void CreateBTree(BTree &t, ifstream &fin)
{
    int x;
    if (!(fin >> x))
        return;// if the file empty stop
    t.root = CreateNode(x); // create root node
    t.size++;
    queue<BNode*> Q;// create a queue of nodes
    Q.push(t.root);
    while (!Q.empty()) {
        BNode* p = Q.front();// get a node at the front of the queue
        Q.pop(); // pop that node
        if (fin>>x) {
            p->left = CreateNode(x);
            t.size++;
            Q.push(p->left); // push node p->left node  to the queue
        }
        if (fin>>x) {
            p->right = CreateNode(x);
            t.size++;
            Q.push(p->right); // push node p->left node to the queue
        }
    }
}
void NLR(BTree& p, queue<int> &Q);

void NLR(BNode* p,queue<int> &Q) {
    if (!p)
        return;

    Q.push(p->data);
    NLR(p->left, Q);
    NLR(p->right, Q);
}
void LNR(BNode* p,queue<int> &Q);

void LNR(BNode* p, queue<int> &Q) {
    if (!p)
        return;
    LNR(p->left, Q);
    Q.push(p->data);
    LNR(p->right, Q);
}
void LRN(BNode* p,queue<int> &Q);

void LRN(BNode* p,queue<int> &Q) {
    if (!p)
        return;
    LRN(p->left, Q);
    LRN(p->right, Q);
    Q.push(p->data);
}
int countNodes(BTree* t);

int countNodes(BNode* t) {
    if (t == NULL) {
        return 0;
    }
    return 1+ countNodes(t->left) + countNodes(t->right);
}
int countLeafNodes(BTree* t);
int countLeafNodes(BNode* t) {
    if (t == NULL) {
        return 0;
    }
    if (t->left == NULL && t->right == NULL) {
        return 1;
    }
    return countLeafNodes(t->left) + countLeafNodes(t->right);
}
int SumInternal(BNode *p);
int SumInternal(BNode *p)
{
    if (p == NULL)
        return 0;

    if (p->left == NULL && p->right == NULL)
        return 0;

    return p->data + SumInternal(p->left) + SumInternal(p->right);
}
bool Search(BNode* p,int k);
bool Search(BNode* p,int k) {
    if (!p)
        return 0;
    if (p->data == k) {
        return 1;
    }
    if (Search(p->left,k)) {
        return 1;
    }
    return Search(p->right,k);
}
void DisplayAtLevel(BNode *p, int k);
void DisplayAtLevel(BNode *p, int k) {
    if (p == NULL)
        return;
    if (k==0) {
        cout << p->data << endl;
        return;
    }
    DisplayAtLevel(p->left, k-1);
    DisplayAtLevel(p->right, k-1);
}
int GetHeight(BNode* p);
int GetHeight(BNode* p)
{
    if (p == NULL)
        return 0;
    int a = GetHeight(p->left);
    int b = GetHeight(p->right);
    int max = a > b ? a : b;
    return (max + 1);
}
int main() {
    BTree t;
    Initialize(t);
    ifstream fin("input.txt");
    CreateBTree(t,fin);
    //NLR
    queue<int> NLRtraverse;
    NLR(t.root,NLRtraverse);
    while(!NLRtraverse.empty()) {
        cout << NLRtraverse.front() << " ";
        NLRtraverse.pop();
    }
    cout<<endl;
    //LNR
    queue<int> LNRtraverse;
    LNR(t.root,LNRtraverse);
    while(!LNRtraverse.empty()) {
        cout << LNRtraverse.front() << " ";
        LNRtraverse.pop();
    }
    cout<<endl;
    //LRN
    queue<int> LRNtraverse;
    LRN(t.root,LRNtraverse);
    while(!LRNtraverse.empty()) {
        cout << LRNtraverse.front() << " ";
        LRNtraverse.pop();
    }
    cout<<endl;
    int Nodes = countNodes(t.root);
    cout << Nodes << endl;
    int leafNodes = countLeafNodes(t.root);
    cout << leafNodes << endl;
    int sumNodes = SumInternal(t.root->left) + SumInternal(t.root->right);
    cout<<sumNodes<<endl;
    int k;
    cout<<"insert level"<<endl;
    cin>>k;
    DisplayAtLevel(t.root,k);
    int s;
    cout<<"insert value"<<endl;
    cin>>s;
    bool found = Search(t.root,s);
    if (found){
        cout<<"found value"<<endl;
    } else {
        cout<<"not found"<<endl;
    }
    cout<<GetHeight(t.root)<<endl;
}
