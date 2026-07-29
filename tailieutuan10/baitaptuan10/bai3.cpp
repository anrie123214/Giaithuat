#include <iostream>
#include <string.h>

//declalaration
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
void initList3(List *list);
Node* InsertHead3(List *list, char data);

void DeleteHead3(List *list);

bool Push3(List *list, char data);


char Pop3(List *list);

void inputStore(char* input,List* list);
void outputStore(char* output,List* list);


int main() {
    char input[20];
    char output[20];
    List stack;
    List* ptrStack = &stack;
    initList3(ptrStack);
    std::cout<<"Enter string: "<<std::endl;
    std::cin>>input;
    inputStore(input,ptrStack);
    int n = ptrStack->size;
    outputStore(output,ptrStack);
    for (int i=0;i<n;i++) {
        printf("%c",output[i]);
    }
}

void initList3(List *list) {
    list->head = NULL;
    list->size = 0;
}
Node * InsertHead3(List *list, char data) {
    Node* node = new Node;
    node->data = data;
    node->next = list->head;
    list->head = node;
    return node;
}
void DeleteHead3(List *list) {
    Node *temp = list->head;
    list->head = list->head->next;
    delete temp;
}

bool Push3(List *list, char data) {
    Node *p = InsertHead3(list,data);
    if (p != NULL ) {
        list->size++;
        return true;
    }
    return  false;
}
char Pop3(List *list) {
    if (list->head != NULL){
        char data = list->head->data;
        list->size--;
        DeleteHead3(list);
        return data;
    }
}

void inputStore(char* input, List *list) {
    int counter = 0;
    while (input[counter]!=NULL) {
        Push3(list,input[counter]);
        counter++;
    }
}
void outputStore(char* output,List* list) {
    int n = list->size;
    for (int i=0;i<n;i++) {
        output[i] = Pop3(list);
    }
}

