#include <stdio.h>
#include <math.h>
int hamDequi(int n);
int hamKhongDequi(int n);
//nhap so n xuat gia tri thu n cua day so fibonaci
int main() {
    int n;
    printf("Nhap n: ");
    scanf("%d", &n);
    printf("Ham de qui: %d\n", hamDequi(n));
    printf("Ham khong de qui: %d\n", hamKhongDequi(n));
    return 0;
}
int hamDequi(int n) {
    if (n == 1 || n == 2) {
        return 1;
    }
    return hamDequi(n - 1) + hamDequi(n - 2) ;
}
int hamKhongDequi(int n) {
    int a = 1, b = 1, c;
    if (n == 1 || n == 2) {
        return 1;
    }
    for (int i = 3; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return c;
}