#include <stdio.h>
#include <malloc.h>

/* SWAP 
    Fungsi untuk menukar isi dua element
*/

void swap(int *a, int *b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

/* PARTITIONING
    Element terakhir dalam list dijadikan pivot.
    Element dengan niali lebih kecil dari pivot diswap ke kiri pivot.
    Element dengan nilai lebih besar dari pivot di swap ke kanan pivot. */

int partition (int *bil, int l, int r) {
    //Menjadikan element terakhir list sebagai pivot
    int pivot = bil[r];
    //Tembok yang menjadi pemisah partisi kiri dan kanan
    //Pertama diletakkan di kiri element pertama
    int i = l-1;
    // Looping dari element paling kiri hingga element sebelum pivot
    for (int j = l; j <= r-1 ; j++)
    { //Jika element lebih kecil sama dengan pivot
        if (bil[j] >= pivot)
        {   //Line yang diubah
            //Geser Tembok
            i++;
            //Sekarang bil[i] element paling kanan dari partisi kiri
            //bil[i] belum tentu lebih kecil dari pivot
            //Tukar bil[i] dengn bil[j] yang sudah di cek
            swap (&bil[i], &bil[j]);
        }
    }
    //Tukar element paling kiri partisi kanan dengan pivot
    swap (&bil[i+1], &bil[r]);
    //Mengembalikan index dari pivot yang sudah benar
    return (i + 1);
    
}

/* Quick Sort
    Langkah tersebut diulang untuk setiap partisi.
    (Partisi sebutan untuk seluruh element di kiri pivot atau seluruh element si kanan pivot) */
void quickSort (int *bil, int l, int r) {
    if (l < r)
    {
        //pi adalah partitioning index
        int pi = partition(bil, l, r);
        //setelah fungsi dijalankan
        //bi[pi] (sebelum pivot) sudah berada pada posisi yang benar

        //secara terpisah dan rekrusif
        //melakukan quicksort untuk tiap partisi kiri dan kanan
        quickSort(bil, l, pi - 1);
        quickSort(bil, pi + 1, r);
    }
}

int main (int argc, char const *argv[]) {
    int *bil;
    int n;
    int i;

    printf("Jumlah Bilangan : ");
    scanf ("%d" ,&n);

    bil = (int *)malloc(sizeof(int)*n);

    for (i = 0; i < n; i++)
    {
        scanf("%d", &bil[i]);
    }
    quickSort(bil, 0, n-1);

    printf ("Hasil Pengurutan : ");
    for (i = 0; i < n; i++)
    {
        printf("%d " ,bil[i]);
    }
    return 0;
}