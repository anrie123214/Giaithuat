#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
typedef struct
{
    int mssv;
    float toan;
    float ly;
    float hoa;
    float tb;
    char ho[20];
    char ten[20];
}SV;
typedef struct
{
    int n;
    SV sinhvien[MAX];
} Clist;
//prototypes-----------------------------------------------------------------------------
void initialize(Clist *list);
void readFile(Clist *list, const char *filename);
void searchSV(Clist *list, Clist *list2);
void findAvg(Clist *list);
int findAvg_more_than_7(Clist *list);
SV findLy_highest(Clist *list);
void delSV(Clist *list, int canXoa);
void insertSV(Clist *list, SV sv_canThem ,int canThem);
void delSV_hoa_nhohon6(Clist *list);
void search_ForSV(Clist *list, char tenSV[],SV* sinhvienCantim);
void writeFile(Clist *list, const char *filename);
//main function------------------------------------------------------
int main()
{
    Clist tableSV;
    Clist diemToanduoi84;
    Clist* ptrtableSV = &tableSV;
    SV sinhVien_ly_caonhat;
    int tren_7 = 0;
    initialize(&tableSV);
    initialize(&diemToanduoi84);
    readFile(&tableSV, "input.txt");
    searchSV(ptrtableSV, &diemToanduoi84);
    for(int i = 0; i < tableSV.n; i++) {
        printf("Student %d Math Score: %f\n", i, tableSV.sinhvien[i].toan);
    }
    printf("\n");
    printf("%d\n",diemToanduoi84.n);

    for(int i = 0; i < diemToanduoi84.n; i++) {
        printf("Student %d Math Score: %f\n", i, diemToanduoi84.sinhvien[i].toan);
    }
    printf("\n");
    findAvg(&tableSV);
    for (int i = 0; i < tableSV.n; i++)
    {
        printf("sinh vien %d co diem :%.2f\n",tableSV.sinhvien[i].mssv, tableSV.sinhvien[i].tb);
    }

    tren_7 = findAvg_more_than_7(ptrtableSV);
    printf("So sinh vien tren 7: %d",tren_7);
    sinhVien_ly_caonhat = findLy_highest(ptrtableSV);
    printf("\n");
    printf("%f",sinhVien_ly_caonhat.ly);
    printf("\n");
    int canXoa;
    printf("Hay nhap mssv can xoa");
    scanf("%d", &canXoa);
    delSV(ptrtableSV, canXoa);
    printf("So SV hien tai la :\n");
    for(int i = 0; i < ptrtableSV->n; i++)
    {
        printf("%d\n", ptrtableSV->sinhvien[i].mssv);
    }
    printf("\n");
    int canThem;
    printf("nhap vi tri can them:\n");
    scanf("%d", &canThem);
    SV sv_canThem;
    printf("Hay nhap mssv, diem toan, diem hoa, diem ly cua sv can them theo dung thu tu:\n");
    scanf("%d %f %f %f",
         &sv_canThem.mssv,
         &sv_canThem.toan,
         &sv_canThem.ly,
         &sv_canThem.hoa
         );
    while (getchar() != '\n');
    printf("Hay nhap ho cua sv can them\n");
    fgets(sv_canThem.ho, sizeof(sv_canThem.ho), stdin);
    sv_canThem.ho[strcspn(sv_canThem.ho, "\n")] = 0;
    printf("Hay nhap ten cua sv can them\n");
    fgets(sv_canThem.ten, sizeof(sv_canThem.ten), stdin);
    sv_canThem.ten[strcspn(sv_canThem.ten, "\n")] = 0;
    fflush(stdin);
    insertSV(ptrtableSV, sv_canThem ,canThem);
    printf("So SV hien tai la :\n");
    for(int i = 0; i < ptrtableSV->n; i++)
    {
        printf("%d\n", ptrtableSV->sinhvien[i].mssv);
    }
    printf("\n");
    delSV_hoa_nhohon6(ptrtableSV);
    printf("So SV hien tai la :\n");
    for(int i = 0; i < ptrtableSV->n; i++)
    {
        printf("%d\n", ptrtableSV->sinhvien[i].mssv);
    }
    printf("\n");
    int n1;
    char tenSV[20];
    SV timThay_sv;
    printf("nhap ten sv can tim\n");
    scanf("%s",&tenSV);
    search_ForSV(ptrtableSV,tenSV,&timThay_sv);
    printf("Thong tin sv can tim la: \n");
    printf("Mssv cua sv can tim la : %d\n",timThay_sv.mssv);
    printf("diem toan cua sv can tim: %f\n",timThay_sv.toan);
    printf("diem hoa cua sv can tim: %f\n",timThay_sv.hoa);
    printf("diem ly cua sv can tim: %f\n",timThay_sv.ly);
    printf("ho cua sv can tim:%s\n",timThay_sv.ho);
    printf("ten cua sv can tim:%s\n",timThay_sv.ten);
    writeFile(ptrtableSV,"sinhvien.txt");
}
//definning functions------------------------------------------------------
void initialize(Clist *list)
{
    list->n = 0;
}
void readFile(Clist *list, const char *filename)
{
    FILE *f = fopen(filename, "r");
    if (f == NULL)
    {
        printf("Can't open file %s\n", filename);
        return;
    }
    fscanf(f, "%d", &list->n);
    for (int i = 0; i < list->n; i++)
    {
        fscanf(f,"%d %f %f %f %s %s",
                 &list->sinhvien[i].mssv,
                 &list->sinhvien[i].toan,
                 &list->sinhvien[i].ly,
                 &list->sinhvien[i].hoa,
                 list->sinhvien[i].ho,
                 list->sinhvien[i].ten
                 );
    }
    fclose(f);
    printf("Successfully loaded %d sinh vien", list->n);
}

void searchSV(Clist *list, Clist *list2)
{

    for (int i = 0; i < list->n; i++)
    {
        int diemToan = (int)(list->sinhvien[i].toan * 10);
        if (diemToan < 84)
        {
            list2->sinhvien[i] = list->sinhvien[i];
            list2->n++;
        }
    }
}

void findAvg(Clist* list)
{
    for (int i = 0; i < list->n; i++)
    {
        list->sinhvien[i].tb = (list->sinhvien[i].toan + list->sinhvien[i].ly + list->sinhvien[i].hoa)/3;
    }
}

int findAvg_more_than_7(Clist* list)
{
    int tren_7 = 0;
    for (int i = 0; i < list->n; i++)
    {
        int diemTB = (int)(list->sinhvien[i].tb * 10);
        if (diemTB > 70)
        {
            tren_7++;
        }
    }
    return tren_7;
}

SV findLy_highest(Clist* list)
{
    SV sinhVien_ly_caonhat = list->sinhvien[0];
    for (int i = 0; i < list->n; i++){
        {
            int diemLy = (int)(list->sinhvien[i].ly * 10);
            if (diemLy > (int)(sinhVien_ly_caonhat.ly * 10))
            {
                sinhVien_ly_caonhat = list->sinhvien[i];
            }
        }
    }
    return sinhVien_ly_caonhat;
}

void delSV(Clist* list, int canXoa)
{
    int target_index = 0;
    for (int i = 0; i < list->n; i++)
    {
        if (list->sinhvien[i].mssv == canXoa)
        {
            target_index = i;
        }
        else continue;
    }
    for (int i = target_index; i < list->n-1; i++)
    {
        list->sinhvien[i] = list->sinhvien[i+1];
    }
    list->n--;
}

void insertSV(Clist* list, SV sv_canThem, int canThem)
{
    for (int i = list->n; i > canThem; i--)
    {
        list->sinhvien[i] = list->sinhvien[i-1];
    }
    list->sinhvien[canThem] = sv_canThem;
    list->n++;
}

void delSV_hoa_nhohon6(Clist* list)
{
        SV transientSV[100];
        int remainingCount = 0;

        for (int i = 0; i < list->n; i++) {
            if (list->sinhvien[i].hoa >= 6.0) {
                transientSV[remainingCount] = list->sinhvien[i];
                remainingCount++;
            }
        }

        for (int i = 0; i < remainingCount; i++) {
            list->sinhvien[i] = transientSV[i];
        }

        list->n = remainingCount;
    }

void search_ForSV(Clist* list, char tenSV[],SV* sinhvienCantim)
{
    SV sv_cantim;
    for (int i = 0; i < list->n; i++)
    {
        if (strcmp(list->sinhvien[i].ten, tenSV) == 0)
        {
            sv_cantim = list->sinhvien[i];
        }
        else continue;
    }
    *sinhvienCantim = sv_cantim;
}

void writeFile(Clist* list, const char* filename)
{
    FILE* f = fopen(filename, "w");
    if (f == NULL)
    {
        printf("Can't open file\n");
        return;
    }
    fprintf(f,"%d\n",list->n);
    for (int i = 0; i < list->n; i++)
    {
        fprintf(f, "%d %.2f %.2f %.2f %s %s\n",
                    list->sinhvien[i].mssv,
                    list->sinhvien[i].toan,
                    list->sinhvien[i].ly,
                    list->sinhvien[i].hoa,
                    list->sinhvien[i].ho,
                    list->sinhvien[i].ten);
    }
    fclose(f);
    printf("Da luu %d sinh vien vao file %s thanh cong!\n", list->n, filename);
}

