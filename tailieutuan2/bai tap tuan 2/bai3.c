#include <stdio.h>
#include <math.h>
int hamDequi(int n);
int hamKhongDequi(int n);
//nhap so n xuat tong cac so tu 1 den n
int main() {
    int n;
    printf("Nhap so nguyen duong n: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Vui long nhap mot so nguyen duong.\n");
        return 1;
    }

    printf("Ket qua de qui: %d\n", hamDequi(n));
    printf("Ket qua khong de qui: %d\n", hamKhongDequi(n));
    return 0;
}
int hamDequi(int n) {
    
    if (n == 0) {
        return 0;
    }
    return hamDequi(n - 1) + n;
}
int hamKhongDequi(int n) {
    int tong = 0;
    for (int i = 1; i <= n; i++) {
        tong += i;
    }
    return tong;
}