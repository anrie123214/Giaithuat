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
int nhapsv(SINHVIEN *sv, char hoTen[], char ngaySinh[], 
    float diemToan, float diemLy, float diemHoa);
int thongTinsv(SINHVIEN *sv, char hoTen[]);
int main() 
{
    SINHVIEN sv;
    char hoTen[20];
    char ngaySinh[20];
    float diemToan;
    float diemLy;
    float diemHoa;
    char canTim[20];
    int ch;
    printf("Nhap ho ten sinh vien:");
    gets(hoTen);
    printf("Nhap ngay sinh:");
    gets(ngaySinh);
    printf("Nhap diem toan:");
    scanf("%f", &diemToan);
    while ((ch = getchar()) != '\n' && ch != EOF);  
    printf("Nhap diem ly:");
    scanf("%f", &diemLy);
    while ((ch = getchar()) != '\n' && ch != EOF);  
    printf("Nhap diem hoa:");
    scanf("%f", &diemHoa);
    while ((ch = getchar()) != '\n' && ch != EOF);  
    nhapsv(&sv, hoTen, ngaySinh, diemToan, diemLy, diemHoa);
    printf("Ho ten sv can tim\n");
    gets(canTim);
    int x = thongTinsv(&sv, canTim);
    if (x == 1) {
        printf("Thong tin sinh vien:\n");
        printf("Ho ten: %s\n", sv.fullName);
        printf("Ngay sinh: %s\n", sv.dateofBirth);
        printf("Diem toan: %.2f\n", sv.math_grades);
        printf("Diem ly: %.2f\n", sv.physics_grades);
        printf("Diem hoa: %.2f\n", sv.chemistry_grades);
    } else {
        printf("Khong tim thay sinh vien co ho ten: %s\n", canTim);
    }

}  
int nhapsv(SINHVIEN *sv, char hoTen[], char ngaySinh[],
    float diemToan, float diemLy, float diemHoa) {
    strcpy((*sv).fullName, hoTen);
    strcpy((*sv).dateofBirth, ngaySinh);
    (*sv).math_grades = diemToan;
    (*sv).physics_grades = diemLy;
    (*sv).chemistry_grades = diemHoa;
    return 1;
}
int thongTinsv(SINHVIEN *sv, char hoTen[]) {
    if (strcmp((*sv).fullName, hoTen) == 0)
    return 1;
    return 0;
}