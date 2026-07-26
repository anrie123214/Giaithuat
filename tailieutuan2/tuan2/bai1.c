#include <stdio.h>
#include <math.h>
int hamDequi(int n);
void hamKhongDequi(int n, int f[]);
//nhap so n xuat day so fibonaci tu 1 den n
int main() {
    int n;
    long long f[100]; 
    printf("Nhap n: ");
    scanf("%d", &n);
    printf("day so ham de qui la: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", hamDequi(i));
    }
    printf("\n");
    hamKhongDequi(n, f);
    printf("day so ham khong de qui la: ");
    for (int i = 0; i < n; i++) {
        printf("%lld ", f[i]);
    }
    printf("\n");
    return 0;
}
int hamDequi(int n) {
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    return hamDequi(n - 1) + hamDequi(n - 2);
}
void hamKhongDequi(int n, long long f[]) {
    if (n >= 1) f[0] = 0;
    if (n >= 2) f[1] = 1;
    for (int i = 2; i < n; i++) {
        f[i] = f[i - 1] + f[i - 2];
    }
}
