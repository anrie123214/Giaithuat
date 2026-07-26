#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct hangHoa {
    char Mahang[20];
    char tenhang[50];
    int soluong;
} hangHoa;
int timKiemTheoMa(hangHoa ds[], int N, char maTimKiem[]);
hangHoa* locSanPhamLonHon5(hangHoa ds[], int N, int *soLuong);
int docDuLieu(hangHoa ds[], int *N);

int main() {
    hangHoa danhSach[100];
    int N = 0;
    ; //san pham lon hon 5
    int timKiem;
    char maTimKiem[20]; //tim kiem san pham theo ma
    int count = 0; //dem so san pham lon hon 5
    if (docDuLieu(danhSach, &N)) {
        printf("Doc file thanh cong! Da load %d san pham.\n\n", N);
        }
    hangHoa *sp = locSanPhamLonHon5(danhSach, N, &count);
    printf("Danh sach san pham co so luong lon hon 5:\n");
    for (int i = 0; i < count; i++) {
        printf("-%s, %s, %d\n", sp[i].Mahang, sp[i].tenhang, sp[i].soluong);
    }
    printf("Nhap ma san pham can tim: ");
    gets(maTimKiem);
    timKiem = timKiemTheoMa(danhSach, N, maTimKiem);
        for (int i = 0; i < N; i++) {
        if (timKiem == 1 && strcmp(danhSach[i].Mahang, maTimKiem) == 0) {
            printf("San pham da duoc tim thay.\n");
            printf("Thong tin san pham: %s, %s, %d\n", danhSach[i].Mahang, danhSach[i].tenhang, danhSach[i].soluong);
            
        } else if (timKiem == 0) {
            printf("San pham khong duoc tim thay.\n");
        } 
    }
}
int docDuLieu(hangHoa ds[], int *N) {
    FILE *f = fopen("hanghoa.txt", "r");
    if (f == NULL) {
        exit(1);
    }

    if (fscanf(f, "%d", N) != 1) {
        fclose(f);
        return 0; 
    }

    for (int i = 0; i < *N; i++) {
        fscanf(f, "%s %s %d", ds[i].Mahang, ds[i].tenhang, &ds[i].soluong);
    }

    fclose(f);
    return 1;
}


hangHoa* locSanPhamLonHon5(hangHoa ds[], int N, int *soLuong) 
{
    int dem = 0;
    for (int i = 0; i < N; i++) {
        if (ds[i].soluong > 5) {
            (dem)++;
        }
    }
    *soLuong = dem;
    hangHoa *dsDaloc = (hangHoa *)malloc(dem * sizeof(hangHoa));
    int J = 0;
    for (int i = 0; i < N; i++) {
        if (ds[i].soluong > 5) {
            dsDaloc[J++] = ds[i];
        }
    }
    return dsDaloc;
}

int timKiemTheoMa(hangHoa ds[], int N, char maTimKiem[]) {

    int timThay = 0;
    for (int i = 0; i < N; i++) {
        if (strcmp(ds[i].Mahang, maTimKiem) == 0) {

            timThay = 1;
            break;
        }
    }
    return timThay;
}

