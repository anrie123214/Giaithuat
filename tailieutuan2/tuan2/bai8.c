#include <stdio.h>
#include <math.h>
int hamDequi(int x, int n);
int hamKhongDequi(int x, int n);
//nhap so n va nhap xuat ket qua x mu n
int main() {
    int n, x;
    printf("Nhap n: ");
    scanf("%d", &n);
    printf("Nhap x: ");
    scanf("%d", &x);
    printf("Ket qua de qui: %d\n", hamDequi(x, n));
    printf("Ket qua khong de qui: %d\n", hamKhongDequi(x, n));
    return 0;
}
int hamDequi(int x, int n) {
    if (n == 0) {
        return 1;
    }
    return hamDequi(x, n - 1)*x;
}
int hamKhongDequi(int x, int n) {
    int tich = 1;
    for (int i = 0; i < n; i++) {
        tich *= x;
    }
    return tich;
}