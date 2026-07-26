#include <iostream>
#include <string.h>


//declaration
typedef struct SV
{
    int mssv;
    float diemToan;
    float diemLy;
    float diemHoa;
    float diemTB;
    char ho[20];
    char ten[20];
}SV;

typedef struct Node
{

        SV data;
        struct Node* next;
        struct Node* prev;

        // 1. Default Constructor: Called when you use `new Node()`
        Node() {
            next = NULL;
            prev = NULL;
        }

        // 2. Direct Value/Reference Constructor: Called when you use `new Node(tempSV)`
        Node(const SV& inputData) {
            data = inputData;
            next = NULL;
            prev = NULL;
        }

        // 3. Pointer Constructor: Called when you use `new Node(&tempSV)`
        Node(const SV* inputData) {
            if (inputData != NULL) {
                data = *inputData; // Dereferences pointer safely
            }
            next = NULL;
            prev = NULL;
        }
} Node;
typedef struct List
{
    Node *head;
    int size;
} List;

//function
void initialize(List *list);
void readFile(List *list, const char *filename);
List* SearchToan8(List *list,List *list2);
void diemTB(List*list);
int diemTBhon7(List*list);
SV diemLyNhat(List*list);
int deleteSV(List*list, int msCanXoa);
void themSV(List* list, SV sinhVienCanThem,int k);
void xoaNhohon6(List* list);
void writeFile(const char* filename, List* list);
SV searchSV(List* list, char* tenCanTim);
int main()
{
    List DSSV;
    List *ptrDSSV = &DSSV;
    initialize(ptrDSSV);
    readFile(ptrDSSV,"input.txt");
    printf("%d\n",ptrDSSV->head->data.mssv);
    List dsToanTren8;
    initialize(&dsToanTren8);
    SearchToan8(ptrDSSV,&dsToanTren8);
    printf("%d\n",dsToanTren8.head->data.mssv);
    diemTB(ptrDSSV);
    std::cout<<ptrDSSV->head->data.diemTB<<std::endl;
    int soSVDiemTBhon7 = diemTBhon7(ptrDSSV);
    std::cout << soSVDiemTBhon7 << std::endl;
    SV svLyNhat = diemLyNhat(ptrDSSV);
    std::cout << svLyNhat.diemLy<<" "<<svLyNhat.mssv << std::endl;
    int msCanXoa;
    std::cout<<"Nhap ma so can xoa:"<<std::endl;
    std::cin>>msCanXoa;
    bool flag = deleteSV(ptrDSSV,msCanXoa);
    if (flag)
    {
        std::cout<<"Ma so %d da xoa "<<msCanXoa<<std::endl;
    } else
    {
        std::cout<<"khong tim thay"<<std::endl;
    }
    SV sinhVienCanThem;
    std::cout<<"Nhap thong tin can them "<<std::endl;
    std::cin >> sinhVienCanThem.mssv
             >> sinhVienCanThem.diemToan
             >> sinhVienCanThem.diemHoa
             >> sinhVienCanThem.diemLy
             >> sinhVienCanThem.ho
             >> sinhVienCanThem.ten;
    std::cout<<"Nhap vi tri can then:"<<std::endl;
    int viTriThem;
    std::cin>>viTriThem;
    themSV(ptrDSSV,sinhVienCanThem,2);
    std::cout<<ptrDSSV->head->next->data.mssv<<std::endl;
    xoaNhohon6(ptrDSSV);
    std::cout<<ptrDSSV->size<<std::endl;
    writeFile("output.txt",ptrDSSV);
    char tenCanTim[20];
    std::cout<<"Nhap ten can tim:"<<std::endl;
    std::cin>>tenCanTim;
    SV SVCanTim = searchSV(ptrDSSV,tenCanTim);
    printf("%f",SVCanTim.diemToan);
}
void initialize(List *list)
{
    list->head = NULL;
    list->size = 0;
}
void readFile(List *list, const char *filename)
{
    FILE *f = fopen(filename,"r");
        if (f == NULL)
        {
            printf("Error opening file");
            return;
        }
    fscanf(f,"%d",&list->size);
    Node* current = NULL;
    for (int i=0;i<list->size;i++)
    {

        Node* node = new Node();
        if (node == NULL) break;
        fscanf(f,"%d %f %f %f %s %s",
            &node->data.mssv,
            &node->data.diemToan,
            &node->data.diemLy,
            &node->data.diemHoa,
            node->data.ho,
            node->data.ten);

        if (list->head == NULL)
        {
            list->head = node;
            current = node;
        }
        else
        {
            current->next = node;
            node->prev = current;
            current = node;
        }
    }
    fclose(f);
}

List* SearchToan8(List* list,List* list2)
{
    Node* current = list->head;
    Node* current2 = list2->head;

    while (current != NULL)
    {
        float diemX10 = current->data.diemToan * 10;
        if (diemX10 > 80)
        {
            Node*temp = new Node(current->data);
            list2->size++;
            if (list2->head == NULL)
            {
                list2->head = temp;
                current2 = temp; //current2 now move to temp which is also the head now

            } else
            {
                current2->next = temp; // current2 next which is temp next now is temp(newnode)
                temp->prev = current2;//establish the prev pointer of the new node
                current2 = temp;// move to the new node
            }
        }
        current = current->next;
    }
    return list2;
}
void diemTB(List* list)
{
    Node* current = list->head;
    while (current != NULL)
    {
        current->data.diemTB = (current->data.diemToan + current->data.diemHoa + current->data.diemLy)/3.0f;
        current = current->next;
    }
}

int diemTBhon7(List* list)
{
    int count = 0;
    Node* current = list->head;
    while (current != NULL)
    {
        float diemX10 = current->data.diemTB * 10;
        if (diemX10 < 70)
        {
            count++;
        }
        current = current->next;
    }
    return count;
}

SV diemLyNhat(List* list)
{
    Node* pin = list->head;
    Node *current = list->head->next;
    SV svCanTim;
    while (current != NULL)
    {
        float diemX10 = pin->data.diemLy * 10;
        float diemX10p2 = current->data.diemLy * 10;
        if (diemX10 < diemX10p2)
        {
            pin = current;
        }
        current = current->next;
    }
    return pin->data;
}

int deleteSV(List* list, int msCanXoa)
{
    Node* current = list->head;
    int flag = 0;
    while (current != NULL)
    {
        if (current->data.mssv == msCanXoa)
        {
            current->prev = current->next;
            current->next = current->prev;
            delete current;
            return 1;
        } else
        {
            if (current->next == NULL) return 0;
        }
        current = current->next;
    }
}

void themSV(List* list, SV sinhVienCanThem, int k)
{
    Node* addedNode = new Node(sinhVienCanThem);
    Node* current = list->head;
    if (k>list->size) return;
    if (k == 1)
    {
        addedNode->next = list->head;
        list->head->prev = addedNode;
        list->head = addedNode;
        list->size++;
    } else
    {
        for (int i=0;i<k-1;i++) current = current->next;// vi tri k
        addedNode->prev = current->prev;
        addedNode->next = current;
        current->prev->next = addedNode;
        current->prev = addedNode;
        list->size++;
    }
}

void xoaNhohon6(List* list)
{
    Node* current = list->head;

    while (current != NULL)
    {
        Node*nextNode = current->next;
        int diemX10 = current->data.diemHoa * 10;
        if (diemX10 < 60)
        {
            if (current->prev != NULL) //if not head
            {
                current->prev->next = current->next;
            } else
            {
                list->head = nextNode;
            }
            if (current->next != NULL)//if not tail
            {
                current->next->prev = current->prev;
            }
            delete current;
            list->size--;
        }
        current = nextNode;
    }
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

SV searchSV(List* list, char* tenCanTim)
{
    Node* current = list->head;
    while (current != NULL)
    {
        if (strcmp(tenCanTim, current->data.ten) == 0)
        {
            return current->data;
        }
        current = current->next;
    }
}

