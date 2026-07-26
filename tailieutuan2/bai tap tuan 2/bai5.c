#include <stdio.h>
#include <math.h>
int hamDequi(int n);
int hamKhongDequi(int n);
//nhap so n xuat gia tri bang cuu chuong cua n
int main() {
    int n;
    int tich;
    printf("Nhap n: ");
    scanf("%d", &n);
    printf("Bang cuu chuong de qui cua %d:\n", n);
    for (int i = 1; i <= 10; i++) {
        printf("%d x %d = %d\n", n, i, hamDequi(i)*n);
    }
    printf("\n");
    printf("------------------------------\n");
    printf("Bang cuu chuong khong de qui cua %d: ", n);
    for (int i = 1; i <= 10; i++) {
        printf("%d x %d = %d\n", n, i, hamKhongDequi(i)*n);
    }
    printf("\n");
    return 0;
}
int hamDequi(int n) {
    if (n == 1) {
        return 1;
    }
    return  1 + hamDequi(n - 1);
}
int hamKhongDequi(int n) {
    return n;
}