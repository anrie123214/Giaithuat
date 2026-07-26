#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//type def
typedef struct SV
{
    int mssv;
    float diemToan;
    float diemLy;
    float diemHoa;
    float diemTB;
    char ho[20];
    char ten[20];
} SV;
typedef struct Node
{
    SV data;
    struct Node* next;
} Node;
typedef struct List
{
    Node* head;
    int size;
}List;
//declaration
void readFile(const char* filename, List* list, int *count);
void initialize(List *list);
void searchSVbehon8(List *list, List *newList);
void diemTB(List *list);
SV diemLy(List *list);
SV diemHoa(List *list);
Node* MergeSortTheoMssv(Node* node, int size);
Node* mergeTheoMssv(Node* node1,Node* node2);
void sortTheoMssv(List* list);
Node* MergeSortTheoTen(Node* node, int size);
Node* mergeTheoTen(Node* node1, Node* node2);
void sortTheoTen(List* list);
void writeFile(const char* filename, List* list);
int countTBhon7(List* list);
bool deleteSV(List*list, int msSVCanXoa);
void themSV(List* list, SV sinhvienCanThem);
void sortTheoTenHo(List* list);
Node* mergeTheoTenHo(Node* nodeA, Node* NodeB);
Node* MergeSortTheoTenHo(Node* node, int size);
//main
int main()
{
    int soSV;
    List dsSV;
    initialize(&dsSV);
    printf("something\n");
    readFile("input.txt",&dsSV,&soSV);
    printf("%d\n",dsSV.size);
    printf("----------\n");
    List* ptrdsSV = &dsSV;
    List dsSVdiemToanbehon8;
    searchSVbehon8(ptrdsSV,&dsSVdiemToanbehon8);
    printf("%d\n",dsSVdiemToanbehon8.size);
    printf("%f\n",dsSVdiemToanbehon8.head->data.diemToan);
    printf("------------\n");
    diemTB(&dsSV);
    printf("%f\n",dsSV.head->next->next->next->data.diemTB);
    printf("------------\n");
    int soSVTBlonhon7 = countTBhon7(ptrdsSV);
    printf("%d\n",soSVTBlonhon7);
    printf("------------\n");
    SV sinhVienLyNhat;
    sinhVienLyNhat = diemLy(ptrdsSV);
    printf("%f\n",sinhVienLyNhat.diemLy);
    printf("------------\n");
    SV sinhVienHoaNhat;
    sinhVienHoaNhat = diemHoa(ptrdsSV);
    printf("%f\n",sinhVienHoaNhat.diemHoa);
    printf("------------\n");
    sortTheoMssv(ptrdsSV);
    printf("%d\n",ptrdsSV->head->data.mssv);
    printf("%d\n",ptrdsSV->head->next->data.mssv);
    printf("%d\n",ptrdsSV->head->next->next->data.mssv);
    writeFile("output1.txt", ptrdsSV);
    printf("------------\n");
    sortTheoTen(ptrdsSV);
    printf("%d\n",ptrdsSV->head->data.mssv);
    printf("%d\n",ptrdsSV->head->next->data.mssv);
    printf("%d\n",ptrdsSV->head->next->next->data.mssv);
    writeFile("output2.txt", ptrdsSV);
    printf("------------\n");
    printf("Nhap mssv can xoa:\n");
    int mssvCanXoa;
    scanf("%d",&mssvCanXoa);
    deleteSV(ptrdsSV,mssvCanXoa);
    printf("------------\n");
    SV svCanThem1;
    printf("nhap sv can them\n");
    scanf("%d %f %f %f %s %s" , &svCanThem1.mssv, &svCanThem1.diemToan,
        &svCanThem1.diemLy, &svCanThem1.diemHoa
        ,svCanThem1.ho,svCanThem1.ten);
    themSV(ptrdsSV,svCanThem1);
    diemTB(ptrdsSV);
    sortTheoMssv(ptrdsSV);
    writeFile("output3.txt",ptrdsSV);
    SV svCanThem2;
    printf("nhap sv can them 2\n");
    scanf("%d %f %f %f %s %s" , &svCanThem2.mssv, &svCanThem2.diemToan,
        &svCanThem2.diemLy, &svCanThem2.diemHoa
        ,svCanThem2.ho,svCanThem2.ten);
    themSV(ptrdsSV,svCanThem2);
    diemTB(ptrdsSV);
    sortTheoTenHo(ptrdsSV);
    writeFile("output4.txt",ptrdsSV);
}
void initialize(List *list)
{
    list->head = NULL;
    list->size = 0;
}

void searchSVbehon8(List* list,List* newList)
{
    Node* current = list->head;
    initialize(newList);
    Node* target = newList->head;
    int diemToancuaSV;
    Node* tail = NULL;
    while (current != NULL) {

        diemToancuaSV = (int)current->data.diemToan * 10;

        if (diemToancuaSV < 80)
        {
            target = (Node*)malloc(sizeof(Node));
            target->data = current->data;
            target->next = NULL;
            newList->size++;
        }
        if (newList->head == NULL)
        {
            newList->head = target;
            tail = target;
        }
        else
        {
            tail->next = target;
            tail = target;
        }
        current = current->next;
    }
    free(target);
}

void readFile(const char* filename, List* list, int* count)
{
    FILE *f = fopen(filename, "r");
    if (f == NULL)
    {
        printf("Can't open file");
        return;
    }
    fscanf(f, "%d", &list->size);
    Node* current = NULL;

    for (int i = 0; i < list->size; i++)
    {
        Node* temp;
        temp = (Node*)malloc(sizeof(Node));
        if (temp == NULL) break;
        fscanf(f, "%d %f %f %f %s %s" , &temp->data.mssv, &temp->data.diemToan,
        &temp->data.diemLy, &temp->data.diemHoa, temp->data.ho, temp->data.ten);
        temp->next = NULL;
        if (list->head == NULL)
        {
            list->head = temp;
            current = temp;
        } else
        {
            current->next = temp;
            current = temp;
        }
    }
        *count = list->size;
        fclose(f);
}
void diemTB(List* list)
{
    Node* current = list->head;
    while (current != NULL)
    {
        current->data.diemTB = (current->data.diemToan + current->data.diemLy + current->data.diemHoa)/3.0f;
        current = current->next;
    }
}



Node* MergeSortTheoTen(Node* node, int size)
{
    if (node == NULL || size <= 1) return node;
    int middle;
    Node* current = node;
    middle = size/2;
    // move to the middle
    for (int i=0; i<middle-1; i++) current = current->next;
    // split the train, right take the last half left take the first half
    Node* right = current->next;
    current->next = NULL;
    Node* left = node;
    // recursive
    Node* lefthead = MergeSortTheoTen(left,middle);
    Node* righthead = MergeSortTheoTen(right,size - middle);
    return mergeTheoTen(lefthead,righthead);
}
Node* mergeTheoTen(Node* node1, Node* node2)
{
    if (node1 == NULL) return node2;
    if (node2 == NULL) return node1;
    Node* mergeNode = NULL;
    if (strcmp(node1->data.ten,node2->data.ten) < 0)
    {
        mergeNode = node1;
        mergeNode->next = mergeTheoTen(node1->next,node2);
    } else
    {
        mergeNode = node2;
        mergeNode->next = mergeTheoTen(node1,node2->next);
    }
    return mergeNode;
}
void sortTheoMssv(List* list)
{
    if (list == NULL || list->head == NULL ) return;
    list->head = MergeSortTheoMssv(list->head, list->size);
}

void writeFile(const char* filename, List* list)
{
    FILE* f= fopen(filename,"w");
    if (f == NULL)
    {
        printf("Can't open file");
        return;
    }
    fprintf(f,"%d\n",list->size);
    Node* current = list->head;
    while (current != NULL)
    {
        fprintf(f, "%d %.1f %.1f %.1f %.1f %s %s\n" , current->data.mssv, current->data.diemToan,
                current->data.diemLy, current->data.diemHoa,
                (current->data.diemToan + current->data.diemLy + current->data.diemHoa)/3.0f,
                current->data.ho, current->data.ten);
        current = current->next;
    }
    fclose(f);
    printf("nhap thanh cong %d sinh vien\n", list->size);
}



void sortTheoTen(List* list)
{
    if (list == NULL || list->head == NULL) return;
    list->head = MergeSortTheoTen(list->head, list->size);
}



Node* MergeSortTheoMssv(Node* node, int size)
{
    if (node == NULL || size <= 1) return node;
    int middle;
    Node* current = node;
    middle = size/2;
    //move the middle node
    for (int i=0; i<middle-1; i++) current = current->next;
    //split the train, right take the middle half left take the first of the train
    Node* right =  current->next;
    current->next = NULL; // Cut connection last trailers of the left part point to null
    Node* left = node;
    //mergeTheoMssv
    Node* lefthead = MergeSortTheoMssv(left,middle);
    Node* righthead = MergeSortTheoMssv(right,size - middle);
    return mergeTheoMssv(lefthead,righthead);
}

Node* mergeTheoMssv(Node* node1, Node* node2)
{
    if (node1 == NULL) return node2;
    if (node2 == NULL) return node1;
    Node* mergeNode = NULL;
    if (node1->data.mssv < node2->data.mssv)
    {
        mergeNode = node1;
        mergeNode->next = mergeTheoMssv(node1->next, node2);
    } else
    {
        mergeNode = node2;
        mergeNode->next = mergeTheoMssv(node1, node2->next);
    }
    return mergeNode;
}


SV diemHoa(List* list)
{
    SV sinhVienCanTim;
    int diemHoaThapNhat, diemHoaTiepTheo;
    Node* pinnacle = list->head;
    Node* current = list->head->next;

    while (current != NULL)
    {
        if (current->next == NULL) {
            break;
        } else {
            diemHoaThapNhat = pinnacle->data.diemHoa * 10;
            diemHoaTiepTheo = current->data.diemHoa * 10;
            if (diemHoaThapNhat > diemHoaTiepTheo)
            {
                diemHoaThapNhat = diemHoaTiepTheo;
                sinhVienCanTim = current->next->data;
                pinnacle = current;
            } else
            {
                sinhVienCanTim = pinnacle->data;
            }
            printf("%d-",sinhVienCanTim.mssv);
        }
        current = current->next;
    }
    return sinhVienCanTim;
}

SV diemLy(List* list)
{
    SV sinhvienCanTim;
    int diemLyCaoNhat,diemLyTiepTheo;
    Node* pinnacle = list->head;
    Node* current = list->head->next;
    while (current != NULL)
    {
        if (current->next == NULL){
            break;
        } else {
            diemLyCaoNhat = pinnacle->data.diemLy * 10;
            diemLyTiepTheo = current->data.diemLy * 10;
            if (diemLyCaoNhat < diemLyTiepTheo)
            {
                diemLyCaoNhat = diemLyTiepTheo;
                sinhvienCanTim = current->data;
                pinnacle = current;
            } else {
                sinhvienCanTim = pinnacle->data;
            }
            printf("%d-",sinhvienCanTim.mssv);

        }
        current = current->next;
    }
    return sinhvienCanTim;
}


int countTBhon7(List* list)
{
    Node* current = list->head;
    int count = 0;
    while (current != NULL)
    {
        current->data.diemTB = (int)current->data.diemTB * 10;
        if (current->data.diemTB > 70)
        {
            count++;
        }
        current = current->next;
    }
    return count;
}


bool deleteSV(List* list,int msSVCanXoa)
{
    if (list->head == NULL) return 0;

    Node* prev = list->head;
    Node* current = prev->next;
    // xoa phan tu o dau ds
    if (msSVCanXoa == list->head->data.mssv)
    {
        list->head = list->head->next;
        free(prev);
        list->size--;
        return 1;
    }else
    {
        while (prev != NULL)
        {
            if (current->next == NULL)
            {
                printf("Tim khong thay sv co MSSV tren \n");
                return 0;
            }
            if (current->data.mssv == msSVCanXoa)
            {
                prev->next = current->next;
                free(current);
                list->size--;
                return 1;
            }
            prev = current;
            current = current->next;
        }

    }
}

void themSV(List* list, SV sinhvienCanThem)
{
    Node* addedNode = (Node*)malloc(sizeof(Node));
    addedNode->data = sinhvienCanThem;
    addedNode->next = list->head;
    list->head = addedNode;
    list->size++;
}

void sortTheoTenHo(List* list)
{
    if (list->head == NULL || list == NULL ) return;
    list->head = MergeSortTheoTenHo(list->head, list->size);
}

Node* mergeTheoTenHo(Node* NodeA, Node* NodeB)
{
    if (NodeA == NULL) return NodeB;
    if (NodeB == NULL) return NodeA;
    Node* mergeNode = NULL;
    if (strcmp(NodeA->data.ten, NodeB->data.ten) < 0)  {
        mergeNode = NodeA;
        mergeNode->next = mergeTheoTenHo(NodeA->next, NodeB);
    } else if (strcmp(NodeA->data.ten, NodeB->data.ten) == 0){
        if (strcmp(NodeA->next->data.ho, NodeB->data.ho) < 0)
        {
            mergeNode = NodeA;
            mergeNode->next = mergeTheoTenHo(NodeA->next, NodeB);

        }else
        {
            mergeNode = NodeB;
            mergeNode->next = mergeTheoTenHo(NodeA,NodeB->next);
        }
    }else
    {
        mergeNode = NodeB;
        mergeNode->next = mergeTheoTenHo(NodeA, NodeB->next);
    }
    return mergeNode;
}

Node* MergeSortTheoTenHo(Node* node, int size)
{
    if (node == NULL || size <= 1) return node;
    int middle = size/2;
    Node* current = node;
    //jump to the middle
    for (int i = 0; i < middle-1; i++) current = current->next;
    //split
    Node* right= current->next;;
    current->next = NULL;
    Node* left = node;
    //merge
    Node* leftHead = MergeSortTheoTenHo(left,middle);
    Node* rightHead = MergeSortTheoTenHo(right,size-middle);
    return mergeTheoTenHo(leftHead,rightHead);
}
