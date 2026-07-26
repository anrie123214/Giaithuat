#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void taoMangLe(int a[], int *count);
void taoMangChan(int a[], int *count);
void swap(int *a, int *b,int *swapCount);
void quickSort(int a[],int left ,int right, int *swapCount, int *compareCount);
void quickSortgiamdan(int a[],int left ,int right, int *swapCount, int *compareCount);
void mergeSort(int arr[], int l, int m);
void merge(int arr[], int l, int m ,int r);
void mix (int a[], int b[],int c[], int n);
int main(){
    int n1 = 0;
    int n2 = 0;
    int L1[20];
    int L2[20];
    int L3[40];
    int hoanvi_count1 = 0;
    int sosanh_count1 = 0;
    int hoanvi_count2= 0;
    int sosanh_count2 = 0;
    taoMangLe(L1,&n1);
    printf("mang le la\n");
    for (int i=0; i<n1; i++) {
        printf("%d ", L1[i]);
    }
    printf("\n");
    taoMangChan(L2,&n2);
    printf("mang chan la\n");
    for (int i=0; i<n2; i++) {
        printf("%d ", L2[i]);
    }
    printf("\n");
    quickSort(L2, 0, n2-1, &hoanvi_count2, &sosanh_count2);
    printf("mang chan da sap xep la \n");
    for (int i=0; i<n2; i++) {
        printf("%d ", L2[i]);
    }
    printf("\n");
    quickSortgiamdan(L1, 0 ,n1-1, &hoanvi_count1, &sosanh_count1);
    for (int i=0; i<n1; i++) {
        printf("%d ", L1[i]);
    }
    printf("\n");
    mix(L1,L2,L3,n1+n2);
    for (int i=0; i<(n1+n2); i++) {
        printf("%d ", L3[i]);
    }
    printf("\n");
    mergeSort(L3,0,(n1+n2-1));
    for (int i=0; i<(n1+n2); i++) {
        printf("%d ", L3[i]);
    }
}
void taoMangLe(int a[], int *count){
    srand(time(NULL));
    *count = 0;
    int i = rand() % 100;
    while (*count < 20) {
        if (i % 2 != 0) {
            a[*count] = i;
            (*count)++;
        }
        i = rand() % 100;
    }
}
void taoMangChan(int a[], int *count){
    srand(time(NULL));
    *count = 0;
    int i = rand() % 100;
    while (*count < 20) {
        if (i % 2 == 0) {
            a[*count] = i;
            (*count)++;
        }
        i = rand() % 100;
    }
}
void swap(int *a, int *b, int *swapCount){
    
    int c = *a;
    *a = *b;
    *b = c;
    (*swapCount)++;
}
void quickSort(int a[],int left ,int right, 
    int *swapCount, int *compareCount){
        int i, j ,x;
        x = a[(right+left)/2];
        i = left; j = right;
        while (i<=j) { 
            //so sanh cho toi khi a[i] > x 
            while (a[i]<x){
                (*compareCount)++;
                i++;
            }
            (*compareCount)++;
            //so sanh cho toi khi a[j] < x 
            while (a[j]>x){
                (*compareCount)++;
                j--;
            }
            (*compareCount)++;
            //so sanh vi tri cua a[i] va a[j]
            //neu a[i] dung sau a[j] thi doi cho
            if (i<=j) {
                swap(&a[i],&a[j],swapCount);
                i++;
                j--;
               
            }
        }

        if (left<j)//doan t1 tu left den j
            quickSort(a,left,j,swapCount,compareCount);
        if (i<right)//neu t2 tu i den right
            quickSort(a,i,right,swapCount,compareCount);
}
void quickSortgiamdan(int a[],int left ,int right, 
    int *swapCount, int *compareCount){
        int i,j,x;
        i = left;
        j = right;
        x = a[(left+right)/2];
        while (i<=j){
            while(a[i]>x){
                (*compareCount)++;
                i++;
            }
            while(a[j]<x){
                (*compareCount)++;
                j--;
            }
            if(i<=j){
                swap(&a[i],&a[j],swapCount);
                i++;
                j--;
            }

        }
        if (left<j)
            quickSortgiamdan(a,left,j,swapCount,compareCount);
        if (i<right)
            quickSortgiamdan(a,i,right,swapCount,compareCount);
    }
void merge(int arr[], int l, int m ,int r){
    int i,j,k;
    int n1=m-l+1;
    int n2=r-m;
    int *L = malloc(n1 * sizeof *L);
    int *R = malloc(n2 * sizeof *R);
    for (int i = 0; i<n1; i++){
        L[i] = arr[l+i];
    }
    for (int j = 0; j<n2; j++){
        R[j] = arr[m+1+j];
    }
    
    i=0;
    j=0;
    k=l;
    /*so sanh tung phan tu chuoi t1 va chuoi t2 them vao arr*/
    /*while loop dung khi i hoac j cham toi cuoi chuoi, mot mang se het phan tu */
    while (i<n1 && j<n2){
        if(L[i]<=R[j]){
            arr[k]=L[i];
            i++;
        }
        else{
            arr[k]=R[j];
            j++;
        }
        k++;
    }
    /*2 truong hop L hoac R het phan tu them chuoi con lai*/
    /*i is at index something the while loop continue adding*/
    while (i<n1){
        arr[k] = L[i];
        i++;
        k++;
    }
    /*j is at index something after the while loop continue adding */
    while (j<n2){
        arr[k] = R[j];
        k++;
        j++;
    }
}
void mergeSort(int arr[], int l, int r){
    /**/
    if (l<r){
    int m = (l+r)/2;
    mergeSort(arr,l,m);
    mergeSort(arr,m+1,r);
    merge(arr,l,m,r);
    }
}
void mix (int a[], int b[],int c[], int n) {
    int k = 0;
    for (int i = 0; i < n; i++) {
        c[2*i] = a[i];
        c[2*i + 1] = b[i];
        k++;
    }
}
