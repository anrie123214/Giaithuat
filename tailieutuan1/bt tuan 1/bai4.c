#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct SINHVIEN 
{
    char fullName[20];
    char dateofBirth[20];
    float math_grades;
    float physics_grades;
    float chemistry_grades;
} SINHVIEN;
void nhapsv(SINHVIEN sv[], int N, char hoTen[], char ngaySinh[],
float diemToan, float diemLy, float diemHoa); 
SINHVIEN xuatMotSV(SINHVIEN sv[], int N, char canTim[]);
int main()
{
    SINHVIEN sv[100];
    int N;
    char canTim[20];
    char hoTen[20];
    char ngaySinh[20];
    float diemToan;
    float diemLy;
    float diemHoa;
    int ch;
    printf("Nhap so luong sinh vien:");
    scanf("%d",&N);
    while ((ch = getchar()) != '\n' && ch != EOF);
    for (int i=0; i<N; i++)
    {
        printf("Nhap ho ten sinh vien thu %d:\n", i + 1);
        gets(hoTen);
        printf("Nhap ngay sinh:\n");
        gets(ngaySinh);
        printf("Nhap diem toan:\n");
        scanf(" %f", &diemToan);
        while ((ch = getchar()) != '\n' && ch != EOF);
        printf("Nhap diem ly:\n");
        scanf(" %f", &diemLy);
        while ((ch = getchar()) != '\n' && ch != EOF);
        printf("Nhap diem hoa:\n");
        scanf(" %f", &diemHoa);
        while ((ch = getchar()) != '\n' && ch != EOF);
        nhapsv(sv, i, hoTen, ngaySinh, diemToan, diemLy, diemHoa);
    }
    printf("Nhap ho ten sinh vien can tim\n");
    gets(canTim);
    SINHVIEN x = xuatMotSV(sv, N, canTim);
    if (strlen(x.fullName) > 0)
    {
    printf("Thong tin sinh vien can tim la\n");
    printf("Ho ten: %s\n", x.fullName);
    printf("Ngay sinh: %s\n", x.dateofBirth);
    printf("Diem toan: %.2f\n", x.math_grades);
    printf("Diem ly: %.2f\n", x.physics_grades);
    printf("Diem hoa: %.2f\n", x.chemistry_grades);
    } else {
        printf("Khong tim thay sinh vien co ho ten: %s\n", canTim);
    }
}
void nhapsv(SINHVIEN sv[], int index, char hoTen[], char ngaySinh[],
    float diemToan, float diemLy, float diemHoa) 
    {
    strcpy((sv[index]).fullName, hoTen);
    strcpy((sv[index]).dateofBirth, ngaySinh);
    (sv[index]).math_grades = diemToan;
    (sv[index]).physics_grades = diemLy;
    (sv[index]).chemistry_grades = diemHoa;
    }

SINHVIEN xuatMotSV(SINHVIEN sv[], int N, char canTim[])
    {
    for (int i=0; i<N; i++)
    {
    strcmp((sv[i]).fullName, canTim);
    if (strcmp((sv[i]).fullName, canTim) == 0)
    return sv[i];
    }
    SINHVIEN empty = {"", "", 0, 0, 0};
    return empty;
}