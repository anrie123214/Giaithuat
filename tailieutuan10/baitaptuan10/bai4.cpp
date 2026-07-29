#include <iostream>
#include <string.h>

//declaration
typedef struct Node
{
    int data;
    Node *next;
};
typedef struct List
{
    Node *head;
    int size;
};
void initList4(List* L);

void initList4(List *L) {
    L->head = NULL;
    L->size = 0;
}

Node* InsertHead(List* L,int data);

Node * InsertHead(List *L, int data) {
    Node *temp = new Node;
    temp->data = data;
    temp->next = L->head;
    L->head = temp;
    return temp;
}

Node* DeleteHead(List* L);

Node * DeleteHead(List *L) {
    Node *temp = L->head;
    L->head = L->head->next;
    free(temp);
}

bool Push4(List* L, int data);
bool Push4(List *L, int data) {
    Node *p = InsertHead(L,data);
    if (p != NULL) {
        L->size++;
        return true;
    }
    return false;
}
int Pop4(List* L);
int Pop4(List *L) {
    if (L->head == NULL) {
        return NULL;
    }
    int result = L->head->data;
    DeleteHead(L);
    L->size--;
    return result;
}
void binaryConvert(List* L,int n) {
    int remainder;
    while (n != 0) {
        remainder = n%2;
        n = n/2;
        Push4(L,remainder);
    }
};

//main
int main() {
    List L;

    List* ptr = &L;
    initList4(ptr);
    int input = 0;
    std::cout << "Nhap so nguyen duong n" << std::endl;
    std::cin >> input;
    binaryConvert(ptr,input);
    for (Node* ptrNode = L.head; ptrNode != NULL; ptrNode = ptrNode->next) {
        printf("%d ",ptrNode->data);
    }
}