#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
int docDulieu(int arr[],int *N);
int tong(int arr[],int N);
int nhoNhat(int arr[],int N);
int lonNhat(int arr[],int N);
int soLe(int arr[],int N);
int* mangLe(int arr[],int N);
int main()
{
    int N;
    int arr[100];
    docDulieu(arr,&N);
    printf("cac phan tu trong mang la:%d \n",N);
    printf("tong cac phan tu trong mang la %d \n",tong(arr,N));
    int soluongLe = soLe(arr,N);
    
    int *mangCacSoLe = mangLe(arr, N);
    
    for (int i = 0; i < soluongLe; i++)
    {
        printf("so le trong mang la %d \n", mangCacSoLe[i]);
    }
    free(mangCacSoLe);
    printf("so nho nhat trong mang la %d \n",nhoNhat(arr,N));
    printf("so lon nhat trong mang la %d \n",lonNhat(arr,N));
    printf("so luong so le trong mang la %d \n",soLe(arr,N));
}
int docDulieu(int arr[],int *N)
{
    FILE* f;
    f = fopen("input1.txt", "r");
    fscanf(f, "%d", N);
     
    for (int i = 0; i < *N; i++)
    {
        fscanf(f, "%d", &arr[i]);
    }
    fclose(f);
    return 0;
}
int tong(int arr[],int N)
{
    int sum=0;
    for (int i=0; i<N; i++)
    {
        sum+=arr[i];
    }
    return sum;
}
int nhoNhat(int arr[],int N)
{
    int min=arr[0];
    for (int i=1; i<N; i++)
    {
        if (arr[i]<min)
        {
            min=arr[i];
        }
    }
    return min;
}
int lonNhat(int arr[],int N)
{
    int max=arr[0];
    for (int i=1; i<N; i++)
    {
        if (arr[i]>max)
        {
                max =arr[i];
        }
    }
    return max;
}
int* mangLe(int arr[],int N)
{
    int count = 0;
    for (int i=0; i<N; i++)
    {
        if (arr[i]%2!=0)
        {
            (count)++;
        }
    }
    int j = 0;
    int *ketQua = (int *)malloc(count * sizeof(int));
    for (int i = 0; i < N; i++) {
        if (arr[i] % 2 != 0) {
            ketQua[j++] = arr[i];
        }
    }
    return ketQua;
}
int soLe(int arr[],int N)
{
    int count = 0;
    for (int i=0; i<N; i++)
    {
        if (arr[i]%2!=0)
        {
            (count)++;
        }
    }
    return count;
}
