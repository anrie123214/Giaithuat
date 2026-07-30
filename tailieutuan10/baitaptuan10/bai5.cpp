#include <iostream>
#include <fstream>
#include <string>

//declaration
struct Node
{
    std::string data;
    Node *next;
};
struct List
{
    Node *head;
    int size;
};
struct ListQueue
{
    Node *head;
    Node *tail;
    int size;
};
void initList5(List* L);
void initListQueue5(ListQueue* L);
Node* createNode(std::string data);
Node* InsertHead5(List* L,std::string data);
bool Push5(List* L,std::string data);
Node* InsertLast5(ListQueue* L, std::string data);
bool PushQueue5(ListQueue* L, std::string data);
void readFile1(const char* FILENAME, List* L);
void readFile2(const char* FILENAME, List* L);
void readFile3(const char* FILENAME, ListQueue* L);
std::string search(Node* node, std::string data);
void initList5(List* L)
{
    L->head = NULL;
    L->size = 0;
}

void initListQueue5(ListQueue* L)
{
    L->head = NULL;
    L->tail = NULL;
    L->size = 0;
}

Node* createNode(std::string data)
{
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

Node* InsertHead5(List* L, std::string data)
{
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = L->head;
    L->head = newNode;
    return newNode;
}
bool Push5(List* L, std::string data)
{
    Node* newNode = InsertHead5(L,data);
    if ( newNode != NULL)
    {
        L->size++;
        return true;
    }
    return false;
}

Node* InsertLast5(ListQueue* L, std::string data)
{
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = NULL;//point newNode->next to Null
    if (L->head == NULL)// if list is blank
    {
        L->head = newNode; // head = new node
        L->tail = newNode;// tail = new node
    } else
    {
        L->tail->next = newNode;//add new node to tail
        L->tail = newNode;// update tail
    }
    return newNode;
}

bool PushQueue5(ListQueue* L, std::string data)
{
    Node* newNode = InsertLast5(L,data);
    if (newNode != NULL)
    {
        L->size++;
        return true;
    }
    return false;
}


void readFile1(const char* FILENAME, List* L){
    std::ifstream f(FILENAME); //input file stream
    if (!f)
    {
        printf("Can't open file");
        return;
    }
    Node* current = L->head;
    std::string data;
    while (f>>data)
    {
        Node* newNode = createNode(data);
        if (L->head == NULL)
        {
            L->head = newNode;//make new node list->head
            current = newNode;//update the ptr to current position

        } else
        {
            current->next = newNode;//connect old nodes
            current = newNode;//update the ptr to the current position
        }
        L->size++;
    }
}


void readFile2(const char* FILENAME, List* L)
{
    std::ifstream f(FILENAME);
    if (!f)
    {
        printf("Can't open file");
        return;
    }
    std::string data;
    while (f>>data)
    {
        Push5(L,data);
    }
}

void readFile3(const char* FILENAME, ListQueue* L)
{
    std::ifstream f(FILENAME);
    if (!f)
    {
        printf("Can't open file");
    }
    std::string data;
    while (f>>data)
    {
        PushQueue5(L,data);
    }
}

std::string search(Node* node, std::string data)
{
    std::string result = "Khong tim thay";
    while (node != NULL)
    {
        if (node->data == data)
        {
            result = node->data;
        }
        node = node->next;
    }
    return result;
}

int main()
{
    List L;
    initList5(&L);
    readFile1("input.txt", &L);
    for (Node* current = L.head; current != NULL; current = current->next)
    {
        std::cout << current->data << std::endl;
    }
    std::cout << std::endl;
    List L2;
    initList5(&L2);
    readFile2("input.txt", &L2);
    for (Node* current = L2.head; current != NULL; current = current->next)
    {
        std::cout << current->data << std::endl;
    }
    std::cout << std::endl;
    ListQueue L3;
    initListQueue5(&L3);
    readFile3("input.txt", &L3);
    for (Node* current = L3.head; current != NULL; current = current->next)
    {
        std::cout << current->data << std::endl;
    }
    std::cout << std::endl;
    std::string result1 = search(L.head,"Hello");
    std::cout << result1 << std::endl;
    std::string result2 = search(L2.head,"Hello");
    std::cout << result2 << std::endl;
    std::string result3 = search(L3.head,"Hello");
    std::cout << result3 << std::endl;
}
