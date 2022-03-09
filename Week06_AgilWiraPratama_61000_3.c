#include <stdio.h>
#include <stdlib.h>

void shellSort (int *arr, int n) {
    int i, j, gap;
    //mulai dari gap besar (n/2), lalu kurangi gapnya (gap /= 2)
    //NOTE : tidak harus menggunakan angka 2 sebagai pembagi
    //bisa gunakan angka yang lebih besar untuk perpindahan yang lebih jauh
    for (gap = n/2; gap > 0 ; gap /= 2)
    {
        //lakukan insertion sort untuk gap size ini.
        for (i = gap; i < n; i++)
        {
            //simpan arr[i] ke temp
            int temp = arr[i];

            //pindahkan nilai yang besar ke tempat yang seharusnya
            for (j = i; j >= gap && arr[j-gap] < temp; j -= gap) //line yang diubah
                arr[j] = arr[j-gap];

            //taruh temp ke lokasi yang benar 
            arr[j] = temp;
        }
    }
}

int main (int argc, char const *argv[]) {
    int i, n, *arr;
    printf("Input N = ");
    scanf ("%d" ,&n);
    arr = (int *)malloc(sizeof(int)*n);

    printf ("Masukkan Bilangan : ");
    for (i = 0; i < n; i++)
    {
        scanf ("%d ",&arr[i]);
    }
    shellSort (arr, n);
    printf ("Hasil Sort : ");
    for (i = 0; i < n; i++)
    {
        printf ("%d ", arr[i]);
    }

    return 0;
}