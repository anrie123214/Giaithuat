#include <stdio.h>
#include <math.h>
double hamDequi(int n);
double hamKhongDequi(int n);
//nhap so n xuat tong cac so
int main() {
    int n;
    printf("Nhap so nguyen duong n: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Vui long nhap mot so nguyen duong.\n");
        return 1;
    }

    printf("Ket qua de qui: %.2f\n", hamDequi(n));
    printf("Ket qua khong de qui: %.2f\n", hamKhongDequi(n));
    return 0;
}
double hamDequi(int n) {
    if (n == 1) {
        return 1;
    }
    double soHanghientai = 1.0/pow(1,n-1);
    if (n % 2 == 0) {
        return hamDequi(n - 1) - soHanghientai;
    } else {
        return hamDequi(n - 1) + soHanghientai;
    }
}
double hamKhongDequi(int n) {
    double tong = 0.0;
        for (int i = 1; i <= n; i++) {
            double soHanghientai = 1.0/pow(1,i-1);
            if (i % 2 == 0) {
            tong -= soHanghientai;
            } else {
            tong += soHanghientai;
            }
    }
    return tong;
}