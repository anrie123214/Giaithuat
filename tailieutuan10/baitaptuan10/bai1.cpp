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
     int size;
};
void initList(List *list);

Node* InsertHead(List *list, char data);
void DeleteHead(List *list);
bool Push(List *list, char data);
char Pop(List *list);
int main()
{
          List stack;
          List *ptrStack = &stack;
          initList((ptrStack));
          Push((ptrStack), 'E');
          printf("%c",ptrStack->head->data);
          Push((ptrStack), 'A');
          Push((ptrStack), 'S');
          Pop((ptrStack));
          Push((ptrStack), 'Y');
          Pop((ptrStack));
          Push((ptrStack), 'Q');
          Push((ptrStack), 'U');
          Push((ptrStack), 'E');
          Pop((ptrStack));
          Pop((ptrStack));
          Pop((ptrStack));
          Push((ptrStack), 'S');
          Push((ptrStack), 'T');
          Pop((ptrStack));
          Pop((ptrStack));
          Pop((ptrStack));
          Push((ptrStack), 'I');
          Push((ptrStack), 'O');
          Pop((ptrStack));
          Push((ptrStack), 'N');
          Pop((ptrStack));
          Pop((ptrStack));
          Pop((ptrStack));
     }

void initList(List* list)
{
     list->head = NULL;
     list->size = 0;
}

Node* InsertHead(List *list, char data)
{
     Node *node = new Node;
     node->data = data;
     node->next = list->head;
     list->head = node;
     return node;
}

void DeleteHead(List* list)
{
     Node *head = list->head;
     list->head = list->head->next;
     delete head;
}

bool Push(List *list, char data)
{
     Node *p = InsertHead(list, data);
     if (p!=NULL)
     {
          return true;
          list->size++;
     }
     return false;
}

char Pop(List* list)
{
     if (list->head!=NULL)
     {
         char temp = list->head->data;
          DeleteHead(list);
          return temp;
     }
     list->size--;
     return NULL;
}
