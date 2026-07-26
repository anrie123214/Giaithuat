#include <stdio.h>
#include <math.h>
float hamDequi(int n);
float hamKhongDequi(int n);
//nhap so n tinh ket qua day so
int main() {
    int n;
    printf("Nhap n: ");
    scanf("%d", &n);
    printf("Ket qua de qui: %.2f\n", hamDequi(n));
    printf("Ket qua khong de qui: %.2f\n", hamKhongDequi(n));
    return 0;
}
float hamDequi(int n) {
    if (n == 1) {
        return 1;
    }
    return  hamDequi(n - 1) + 1.0 / n;
}
float hamKhongDequi(int n) {
    float tong = 0;
    for (int i = 1; i <= n; i++) {
        if (i == 1) {
            tong += 1;
        } else {
            tong += 1.0 / i;
        }
    }
    return tong;
}