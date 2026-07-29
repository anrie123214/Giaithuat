#include <iostream>
#include <string.h>

//declaration
typedef struct Node
{
    char data;
    Node *next;
};
typedef struct List
{
    Node *head;
    Node *tail;
    int size;
};
void initList2(List *list);
Node* InsertLast(List *list, char data);
void DeleteHead2(List *list);
bool Push2(List *list, char data);
char Pop2(List *list);
int main()
{
    List Queue;
    List *ptrQueue = &Queue;
    initList2(ptrQueue);
    Push2((ptrQueue), 'E');
    printf("%c",ptrQueue->head->data);
    Push2((ptrQueue), 'A');
    Push2((ptrQueue), 'S');
    Pop2((ptrQueue));
    Push2((ptrQueue), 'Y');
    Pop2((ptrQueue));
    Push2((ptrQueue), 'Q');
    Push2((ptrQueue), 'U');
    Push2((ptrQueue), 'E');
    Pop2((ptrQueue));
    Pop2((ptrQueue));
    Pop2((ptrQueue));
    Push2((ptrQueue), 'S');
    Push2((ptrQueue), 'T');
    Pop2((ptrQueue));
    Pop2((ptrQueue));
    Pop2((ptrQueue));
    Push2((ptrQueue), 'I');
    Push2((ptrQueue), 'O');
    Pop2((ptrQueue));
    Push2((ptrQueue), 'N');
    Pop2((ptrQueue));
    Pop2((ptrQueue));
    Pop2((ptrQueue));

}
void initList2(List *list)
{
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
}

Node* InsertLast(List* list, char data)
{
    Node *node = new Node;
    node->data = data;
    node->next = NULL;
    if (list->size == 0)
    {

        list->head = node;
        list->tail = node;
        return node;
    } else
    {
        list->tail->next = node;
        list->tail = node;
        return node;
    }
}

void DeleteHead2(List* list)
{
    if (list->size != 0)
    {
        Node *node = list->head;
        list->head = list->head->next;
        delete node;
        if (list->size == 0)
        {
            list->tail = NULL;
        }
    } else return;
}

bool Push2(List* list, char data)
{
    Node *p = InsertLast(list,data);
    if (p != NULL)
    {
        list->size++;
        return true;

    }
    return false;
}

char Pop2(List* list)
{
    if (list->size != 0)
    {
        char data = list->head->data;
        DeleteHead2(list);
        list->size--;
        if (list->size == 0)
            list->tail = NULL;
        return data;
    }
}
