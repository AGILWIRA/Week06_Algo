#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

void merge(int *bil, int l, int m, int r) {
    int i, j, k;

    //banyak data di sisi kiri
    int n1 = m - l + 1;

    //banyak data disi kanan
    int n2 = r - m;

    //membuat array sementara untuk bilangan di sisi kiri
    int L[n1];

    //membuat array sementara untuk di sisi kanan
    int R[n2];

    //menyalin bilangan di sisi kiri ke array L[]
    for (i = 0; i < n1; i++)
    {
        L[i] = bil[l + i];
    }
    
    //menyalin bilangan di sisi kanan ke array R[]
    for (j = 0; j < n2; j++)
    {
        R[j] = bil[m+1 + j];
    }
    
    /* Proses menggabungkan kembali bilangan di sisi kiri dan kanan menjadi bil[l...r] */
    i = 0; //Itertor untuk bilangan di sisi kiri 
    j = 0; //Iteratur untuk bilangan di sisi kanan
    k = l; //Iteratur untuk menggabungkan kembali bilangan yang terpisah di sisi kanan dan sisi kiri 

    while (i < n1 && j < n2)
    {
        if (L[i] >= R[j]) {
            //Line yang diubah
            bil[k] = L[i];
            i++;
        }
        else
        {
            bil[k] = R[j];
            j++;
        }
        k++;
    }
    //Menyalin jika ada elemen yang tersisa dari L[]
    while (i < n1)
    {
        bil[k] = L[i];
        i++;
        k++;
    }
    
    //menyalin jika ada elemen yang tersisa dari R[]
    while (j < n2)
    {
        bil[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int *bil, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(bil, l, m);
        mergeSort(bil, m+1, r);

        //proses ketika sudah menulusuri bgian kiri & kanan dari sebuah node
        merge(bil, l, m, r);
    }
}

int main(int argc, char const *argv) {
    int *bil;
    int n;
    int i;

    printf("Jumlah Bilangan : ");
    scanf ("%d" ,&n);

    bil = (int *)malloc(sizeof(int)*n);

    for (i = 0; i < n; i++)
    {
        scanf ("%d" ,&bil[i]);
    }
    
    mergeSort(bil, 0, n-1);

    printf("Hasil Pengurutan : ");
    for (i = 0; i < n; i++)
    {
        printf("%d " ,bil[i]);
    }
    return 0;
}