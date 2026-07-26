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
    float average_grades;
} SINHVIEN;
void nhapsv(SINHVIEN sv[], int N, char hoTen[], char ngaySinh[],
float diemToan, float diemLy, float diemHoa, float diemTB);
SINHVIEN* xuatSVtren5(SINHVIEN sv[], int N, int *count);
SINHVIEN* xapsepTangdan(SINHVIEN sv[], int N);
//main
int main()
{
    SINHVIEN sv[100];
    int N;
    int demSVtren5;
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
        char hoTen[20];
        char ngaySinh[20];
        float diemToan;
        float diemLy;
        float diemHoa;
        float diemTB;
        char canTim[20];
        printf("Nhap ho ten sinh vien:\n");
        gets(hoTen);
        printf("Nhap ngay sinh:\n");
        gets(ngaySinh);
        printf("Nhap diem toan:\n");
        scanf("%f", &diemToan);
        while ((ch = getchar()) != '\n' && ch != EOF);
        printf("Nhap diem ly:\n");
        scanf("%f", &diemLy);
        while ((ch = getchar()) != '\n' && ch != EOF);
        printf("Nhap diem hoa:\n");
        scanf("%f", &diemHoa);
        while ((ch = getchar()) != '\n' && ch != EOF);
        diemTB=(diemToan+diemLy+diemHoa)/3;
        nhapsv(sv, i, hoTen, ngaySinh, diemToan, diemLy, diemHoa, diemTB);
    }
SINHVIEN* dstren5 = xuatSVtren5(sv, N, &demSVtren5);
    if (demSVtren5 > 0)
    {
        printf("Danh sach sinh vien co diem trung binh tren 5:\n");
        for (int i = 0; i < demSVtren5; i++)
        {
            printf("Ho ten: %s\n", dstren5[i].fullName);
            printf("Ngay sinh: %s\n", dstren5[i].dateofBirth);
            printf("Diem toan: %.2f\n", dstren5[i].math_grades);
            printf("Diem ly: %.2f\n", dstren5[i].physics_grades);
            printf("Diem hoa: %.2f\n", dstren5[i].chemistry_grades);
            printf("Diem trung binh: %.2f\n", dstren5[i].average_grades);
        }
    } else {
        printf("Khong co sinh vien nao co diem trung binh tren 5.\n");
    }
    free(dstren5);
SINHVIEN* xapSep = xapsepTangdan(sv, N);
    printf("Danh sach sinh vien sap xep tang dan theo diem trung binh:\n");
    for (int i = 0; i < N; i++)
    {
        printf("Ho ten: %s\n", xapSep[i].fullName);
        printf("Ngay sinh: %s\n", xapSep[i].dateofBirth);
        printf("Diem toan: %.2f\n", xapSep[i].math_grades);
        printf("Diem ly: %.2f\n", xapSep[i].physics_grades);
        printf("Diem hoa: %.2f\n", xapSep[i].chemistry_grades);
        printf("Diem trung binh: %.2f\n", xapSep[i].average_grades);
    }
    free(xapSep);
}
//nhap thong tin sinh vien
void nhapsv(SINHVIEN sv[], int i, char hoTen[], char ngaySinh[],
    float diemToan, float diemLy, float diemHoa, float diemTB) 
{
    strcpy((sv[i]).fullName, hoTen);
    strcpy((sv[i]).dateofBirth, ngaySinh);
    (sv[i]).math_grades = diemToan;
    (sv[i]).physics_grades = diemLy;
    (sv[i]).chemistry_grades = diemHoa;
    (sv[i]).average_grades = diemTB;
    
}

//xuat sinh vien co diem trung binh tren 5
SINHVIEN* xuatSVtren5(SINHVIEN sv[], int N, int *count)
{
    int soLuongSVtren5 = 0;
    for (int i = 0; i<N; i++)
    {
        if (sv[i].average_grades > 5)
        {
            soLuongSVtren5++;
        }
    }
    
    *count = soLuongSVtren5;
    SINHVIEN *dstren5 = (SINHVIEN*)malloc(soLuongSVtren5 * sizeof(SINHVIEN));
    for (int i = 0; i < N; i++)
    {
        if (sv[i].average_grades > 5)
        {
            dstren5[(soLuongSVtren5)] = sv[i];
            (soLuongSVtren5)++;
        }
    }
    return dstren5;
}
SINHVIEN* xapsepTangdan(SINHVIEN sv[], int N)
{
    SINHVIEN* xapSep = (SINHVIEN*)malloc(N * sizeof(SINHVIEN));
    for (int i = 0; i < N; i++)
    {
        xapSep[i] = sv[i];
    }
    
    for (int i= 0; i< N-1; i++)
    {
        for (int j =0; j<N-1-i; j++)
        {
            if (xapSep[j].average_grades > xapSep[j+1].average_grades)
            {
                SINHVIEN temp = xapSep[j];
                xapSep[j] = xapSep[j+1];
                xapSep[j+1] = temp;
            }
        }
    }
    return xapSep;
}