#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct PHANSO
{
    int tuSo;
    int mauSo;
} PHANSO;
void nhapPhanSo(PHANSO *ps, int tuSo, int mauSo);
PHANSO* inPhanSo(PHANSO ps);
PHANSO* quiDong(PHANSO ps1, PHANSO ps2);
PHANSO* hamCong(PHANSO ps1, PHANSO ps2);
PHANSO* hamTru(PHANSO ps1, PHANSO ps2);
PHANSO* hamNhan(PHANSO ps1, PHANSO ps2);
PHANSO* hamChia(PHANSO ps1, PHANSO ps2);
int main()
{
   PHANSO ps1, ps2;
   int tuso1, mauso1, tuso2, mauso2;
   int ch;
   printf("Nhap tu so thu nhat:\n");
   scanf("%d", &tuso1);
   while ((ch = getchar()) != '\n' && ch != EOF);
   printf("Nhap mau so thu nhat:\n");
   scanf("%d", &mauso1);
   while ((ch = getchar()) != '\n' && ch != EOF);
   printf("Nhap tu so thu hai:\n");
   scanf("%d", &tuso2);
   while ((ch = getchar()) != '\n' && ch != EOF);
   printf("Nhap mau so thu hai:\n");
   scanf("%d", &mauso2);
   while ((ch = getchar()) != '\n' && ch != EOF);
   nhapPhanSo(&ps1, tuso1, mauso1);
   nhapPhanSo(&ps2, tuso2, mauso2);
   PHANSO *Px = inPhanSo(ps1);
   printf("tu so la %d, mau so la %d\n", Px->tuSo, Px->mauSo);
   PHANSO *Py = inPhanSo(ps2);
   printf("tu so la %d, mau so la %d\n", Py->tuSo, Py->mauSo);
   PHANSO *Pz = quiDong(ps1, ps2);
   printf("Phan so sau khi qui dong:\n");
   printf("tu so la %d, mau so la %d\n", Pz->tuSo, Pz->mauSo);
   PHANSO *Pt = quiDong(ps2, ps1);
   printf("Phan so sau khi qui dong:\n");
   printf("tu so la %d, mau so la %d\n", Pt->tuSo, Pt->mauSo);
    PHANSO *Pcong = hamCong(ps1, ps2);
    printf("Phan so sau khi cong:\n");
    printf("tu so la %d, mau so la %d\n", Pcong->tuSo, Pcong->mauSo);
    PHANSO *Ptru = hamTru(ps1, ps2);
    printf("Phan so sau khi tru:\n");
    printf("tu so la %d, mau so la %d\n", Ptru->tuSo, Ptru->mauSo);
    PHANSO *Pnhan = hamNhan(ps1, ps2);
    printf("Phan so sau khi nhan:\n");
    printf("tu so la %d, mau so la %d\n", Pnhan->tuSo, Pnhan->mauSo);
    PHANSO *Pchia = hamChia(ps1, ps2);
    printf("Phan so sau khi chia:\n");
    printf("tu so la %d, mau so la %d\n", Pchia->tuSo, Pchia->mauSo);
    free(Px);
    free(Py);
    free(Pz);
    free(Pt);
    free(Pcong);
    free(Ptru);
    free(Pnhan);
    free(Pchia);
} 
void nhapPhanSo(PHANSO *ps, int tuSo, int mauSo)
{
    ps->tuSo = tuSo;
    ps->mauSo = mauSo;
}
PHANSO* inPhanSo(PHANSO ps)
{
    PHANSO *ptr = (PHANSO*)malloc(sizeof(PHANSO));
    ptr->tuSo = ps.tuSo;
    ptr->mauSo = ps.mauSo;
    return ptr;
}
PHANSO* quiDong(PHANSO ps1, PHANSO ps2)
{
    PHANSO *ptr = (PHANSO*)malloc(sizeof(PHANSO));
    ptr->tuSo = ps1.tuSo * ps2.mauSo;
    ptr->mauSo = ps1.mauSo * ps2.mauSo;
    return ptr;
}
PHANSO* hamCong(PHANSO ps1, PHANSO ps2)
{
    PHANSO *ptr = (PHANSO*)malloc(sizeof(PHANSO));
    ptr->tuSo = ps1.tuSo * ps2.mauSo + ps2.tuSo * ps1.mauSo;
    ptr->mauSo = ps1.mauSo * ps2.mauSo;
    return ptr;
}
PHANSO* hamTru(PHANSO ps1, PHANSO ps2)
{
    PHANSO *ptr = (PHANSO*)malloc(sizeof(PHANSO));
    ptr->tuSo = ps1.tuSo * ps2.mauSo - ps2.tuSo * ps1.mauSo;
    ptr->mauSo = ps1.mauSo * ps2.mauSo;
    return ptr;
}
PHANSO* hamNhan(PHANSO ps1, PHANSO ps2)
{
    PHANSO *ptr = (PHANSO*)malloc(sizeof(PHANSO));
    ptr->tuSo = ps1.tuSo * ps2.tuSo;
    ptr->mauSo = ps1.mauSo * ps2.mauSo;
    return ptr;
}
PHANSO* hamChia(PHANSO ps1, PHANSO ps2)
{
    PHANSO *ptr = (PHANSO*)malloc(sizeof(PHANSO));
    ptr->tuSo = ps1.tuSo * ps2.mauSo;
    ptr->mauSo = ps1.mauSo * ps2.tuSo;
    return ptr;
}