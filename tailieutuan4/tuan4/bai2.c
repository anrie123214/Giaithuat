#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct SINHVIEN {
    int maSo;
    char ho[100];
    char ten[100];
} SINHVIEN;
typedef struct Node {
    SINHVIEN data;
    struct Node* next;
} Node;
// function prototypes
int docDulieu(const char* filename, Node** head, int *count);//doc du lieu tu file
Node* taoNode(SINHVIEN sv); //tao node moi
void themVaoCuoi(Node** head, SINHVIEN sv); //them sinh vien vao cuoi danh sach
Node* timSinhVien(Node* head, int N, int maSo);
Node* timSinhVien(Node* head, int N, int maSo);
Node* interchangeSort(Node* head);
Node* findnamewithrecursive(Node* head,char left, char right, char canTim[], int N);
Node* findnamewithoutrecursive(Node* head, char canTim[], int N);
Node* interchangeSortbyName(Node* head, char name[], int N);
void swap(Node* a, Node* b);

// main function
int main() {
    // doc du lieu tu file
    int count = 0;
    Node* ds_sinhvien = NULL;
    if (docDulieu("input.txt", &ds_sinhvien, &count)) {
        printf("Doc file thanh cong! Da load %d sinh vien.\n\n", count);
    }
    //tim kiem
    printf("tim kiem sinh vien theo ma so:\n");
    int maSoCanTim;
    printf("Nhap ma so sinh vien can tim: ");
    scanf("%d", &maSoCanTim);
    Node* svTimDuoc = timSinhVien(ds_sinhvien, count, maSoCanTim);
    if (svTimDuoc != NULL) {
        printf("Sinh vien da duoc tim thay.\n");
        printf("Thong tin sinh vien: %d, %s, %s\n", svTimDuoc->data.maSo, svTimDuoc->data.ho, svTimDuoc->data.ten);
    } else {
        printf("Sinh vien khong duoc tim thay.\n");
    }
    // sap xep
    Node* ds_xapsep = interchangeSort(ds_sinhvien);
    printf("\nDanh sach sinh vien sau khi sap xep:\n");
    Node* current = ds_xapsep;
    while (current != NULL) {
        printf("%d, %s, %s\n", current->data.maSo, current->data.ho, current->data.ten);
        current = current->next;
    }
    //sap xep theo ten
    Node* ds_xapseptheoten = interchangeSortbyName(ds_sinhvien, current->data.ten, count);
    printf("\nDanh sach sinh vien sau khi sap xep theo ten:\n");
    current = ds_xapseptheoten;
    while (current != NULL) {
        printf("%d, %s, %s\n", current->data.maSo, current->data.ho, current->data.ten);
        current = current->next;
    }
    //tim kiem theo ten
    char tenCanTim[100];
    printf("\nNhap ten sinh vien can tim: ");
    scanf("%s", tenCanTim);
    Node* svTimTheoTenbangdequi = findnamewithrecursive(ds_sinhvien, 0, count-1, tenCanTim, count);
    printf("\nKet qua tim kiem theo ten bang de qui:\n");
    if (svTimTheoTenbangdequi != NULL) {
        printf("Sinh vien da duoc tim thay.\n");
        printf("Thong tin sinh vien: %d, %s, %s\n", svTimTheoTenbangdequi->data.maSo, svTimTheoTenbangdequi->data.ho, svTimTheoTenbangdequi->data.ten);
    } else {
        printf("Sinh vien khong duoc tim thay.\n");
    }
    Node* svTimTheoTenkhongdequi = findnamewithoutrecursive(ds_sinhvien, tenCanTim, count);
    printf("\nKet qua tim kiem theo ten khong bang de qui:\n");
    if (svTimTheoTenkhongdequi != NULL) {
        printf("Sinh vien da duoc tim thay.\n");
        printf("Thong tin sinh vien: %d, %s, %s\n", svTimTheoTenkhongdequi->data.maSo, svTimTheoTenkhongdequi->data.ho, svTimTheoTenkhongdequi->data.ten);
    } else {
        printf("Sinh vien khong duoc tim thay.\n");
    }
}
// function definitions
int docDulieu(const char* filename, Node** head, int *count) {
    FILE *f = fopen(filename, "r");
    SINHVIEN sv_temp;
    int dem = 0;
    if (f == NULL) {
        printf("Loi: Khong mo duoc file %s\n", filename);
        return 0;
    }
    while (fscanf(f, "%d %s %s", &sv_temp.maSo, sv_temp.ho, sv_temp.ten) != EOF) {
       themVaoCuoi(head, sv_temp);
       dem++; 
       
    }
    *count = dem;
    fclose(f);
    return 1;
}
Node* taoNode(SINHVIEN sv) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = sv;
    temp->next = NULL;
    return temp;
}
void themVaoCuoi(Node** head, SINHVIEN sv) {
    Node* temp = taoNode(sv);
    if (*head == NULL) {
        *head = temp;
    } else {
        Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = temp;
    }
}
Node* timSinhVien(Node* head, int N, int maSo) {
    Node* current = head;
    while (current != NULL) {
        if (current->data.maSo == maSo) {
            return current; 
        }
        current = current->next;
    }
    return current; 
}
void swap(Node* a, Node* b) {
    SINHVIEN temp = a->data;
    a->data = b->data;
    b->data = temp;
}

Node* interchangeSort(Node* head) {
    for (Node* i = head; i != NULL && i->next != NULL; i = i->next) {
        for (Node* j = i->next; j != NULL; j = j->next) {
            if (i->data.maSo > j->data.maSo) {
                swap(i, j);
            }
        }
        }
    return head;
}
Node* interchangeSortbyName(Node* head, char name[], int N) {
    for (Node* i = head; i != NULL && i->next != NULL; i = i->next) {
        for (Node* j = i->next; j != NULL; j = j->next) {
            if (strcmp(i->data.ten, j->data.ten) > 0) {
                swap(i, j);
            }
        }
        }
    return head;
}
Node* findnamewithrecursive(Node* head,char left, char right, char canTim[], int N)
{
    if (head == NULL) {
        return NULL;
    }
    Node* current = head;
    Node** arr = (Node**)malloc(N * sizeof(Node*));
    Node* result = NULL;
    int i = 0;
    while (current != NULL) {
        arr[i++] = current;
        current = current->next;
    }
    int mid = left + (right - left) / 2;
    if (strcmp(arr[mid]->data.ten, canTim) == 0) {
        result = arr[mid];
    } else if (strcmp(arr[mid]->data.ten, canTim) < 0) {
        result = findnamewithrecursive(head, mid + 1, right, canTim, N);
    } else {
        result = findnamewithrecursive(head, left, mid - 1, canTim, N);
    }
    free(arr);
    return result;
}
Node* findnamewithoutrecursive(Node* head, char canTim[], int N){
    if (head == NULL) {
        return NULL;
    }
    Node* current = head;
    Node** arr = (Node**)malloc(N * sizeof(Node*));
    Node* result = NULL;
    int left = 0, right = N-1;
    for (int i = 0; i < N; i++) {
        arr[i] = current;
        current = current->next;
    }
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (strcmp(arr[mid]->data.ten, canTim) == 0) {
            result = arr[mid];
            break;
        } else if (strcmp(arr[mid]->data.ten, canTim) < 0) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    free(arr);
    return result;
}