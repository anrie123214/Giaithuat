#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void taoMang(int a[]); 
int timX(int a[], int x);
void sapXep(int a[]);
int main() {
    int a[20];
    taoMang(a);
    printf("Mang sau khi tao:\n");
    for (int i = 0; i < 20; i++) {
        printf("%d ", a[i]);
    }
    int x;
    printf("\nNhap gia tri x can tim: ");
    scanf("%d", &x);
    int timx = timX(a, x);
    if (timx) {
        printf("Gia tri %d co trong mang.\n", x);
    } else {
        printf("Gia tri %d khong co trong mang.\n", x);
    }
    printf("\nMang sau khi sap xep:\n");
    sapXep(a);
    for (int i = 0; i < 20; i++) {
        printf("%d ", a[i]);
    }
    int timxsapxep = timX(a, x);
    if (timxsapxep) {
        printf("\nGia tri %d co trong mang sau khi sap xep.\n", x);
    } else {
        printf("\nGia tri %d khong co trong mang sau khi sap xep.\n", x);
    }
}
void taoMang(int a[]) {
    srand(time(NULL));
    for (int i = 0; i < 20; i++) {
        a[i] = rand() % 100; //gia tri nho hon 100
    }
}
int timX(int a[], int x) {
    int found = 0;
    int left = 0;
    int right = 19;
    int mid = (right + left) / 2;
    if (x == a[mid]) {
        found = 1;
    while (left <= right) {
        if (a[mid] == x) {
            found = 1;
            break;
        } else if (a[mid] < x) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return found;
}
}
void sapXep(int a[]) {
    for (int i = 0; i < 19; i++) {
        for (int j = 0; j < 19 - i; j++) {
            if (a[j] > a[j + 1]) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}
