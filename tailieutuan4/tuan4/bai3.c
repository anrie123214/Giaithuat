#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// function prototypes
void taoMangChan(int a[], int *count);
void taoMangLe(int a[], int *count);
void bubbleSort(int a[], int n, int *swapCount, int *compareCount);
void insertSort(int a[], int n, FILE *f);
void mix (int a[], int b[], int c[], int n);
int main() {
    int dem=0;
    int l1[20];
    int l2[20];
    printf("Mang chan sau khi tao:\n");
    taoMangChan(l1, &dem);
    for (int i = 0; i < dem; i++) {
        printf("%d ", l1[i]);
    }
    printf("\nMang le sau khi tao:\n");
    taoMangLe(l2, &dem);
    for (int i = 0; i < dem; i++) {
        printf("%d ", l2[i]);
    }
    printf("\n");
    printf("\nMang chan sau khi sap xep:\n");
    int swapCount1, compareCount1;
    bubbleSort(l1, dem, &swapCount1, &compareCount1);
    for (int i = 0; i < dem; i++) {
        printf("%d ", l1[i]);
    }
    printf("\nMang le sau khi sap xep:\n");
    printf("\nSo lan hoan vi mang chan: %d\n", swapCount1);
    printf("So lan so sanh mang chan: %d\n", compareCount1);
    FILE *f = fopen("insertion.txt", "w");
    if (f == NULL) {
        printf("Error opening file!\n");
        return 1;
    }
    insertSort(l2, dem, f);
    fclose(f);
    int l3[40];
    mix(l1,l2,l3,20);         
    printf("mang sau khi lam tron la\n");
    for (int i=0; i<dem; i++){
        printf("%d ",l3[i]);
}
}
void taoMangLe(int a[], int *count){
    srand(time(NULL));
    *count = 0;
    int i = rand() % 100;
    while (*count < 20) {
        if (i % 2 != 0) {
            a[*count] = i;
            (*count)++;
        }
        i = rand() % 100;
    }
}
void taoMangChan(int a[], int *count) {
    srand(time(NULL));
    *count = 0;
    int i = rand() % 100;
    while (*count < 20) {
        if (i % 2 == 0) {
            a[*count] = i;
            (*count)++;
        }
        i = rand() % 100;
    }
}
void bubbleSort(int a[], int n, int *swapCount, int *compareCount) {
    *swapCount = 0;
    *compareCount = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = n - 1; j > i; j--) {
            (*compareCount)++;
            if (a[j] < a[j - 1]) {
                int temp = a[j];
                a[j] = a[j - 1];
                a[j-1] = temp;
                (*swapCount)++;
            }
        }
    }
}
void insertSort(int a[], int n, FILE *f) {
    for (int i = 1; i < n; i++) {
        int key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
        fprintf(f, "Buoc %d: ", i);
        for (int k = 0; k < n; k++) {
            fprintf(f, "%d ", a[k]);
        }
        fprintf(f, "\n");
    }
}
void mix (int a[], int b[],int c[], int n) {
    int k = 0;
    for (int i = 0; i < n; i++) {
        c[2*i] = a[i];
        c[2*i + 1] = b[i];
        k++;
    }
    for (int i = 0; i < k - 1; i++) {
        for (int j = k - 1; j > i; j--) {
            if (a[j] < a[j - 1]) {
                int temp = a[j];
                a[j] = a[j - 1];
                a[j-1]=temp;
            }
        }
    }
}
