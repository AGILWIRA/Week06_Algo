#include <stdio.h>
#include <stdlib.h>

void swap(int *bil1, int *bil2)
{
    int temp;

    temp = *bil1;
    *bil1 = *bil2;
    *bil2 = temp;
}

int heapify(int *bil, int n, int i)
{
    //int i akan menjadi indeks root sementara

    int maks = i;      //Mengambil index root sebagai nilai maks
    int l = 2 * i + 1; //Rumus untuk mengambil index array anak di sebelah kiri
    int r = 2 * i + 2; //Rumus untuk mengambil index array anak di sebelah kanan

    //Proses pengecekan, apakah nilai dari anak disebelah kiri > dari nilai maks
    if (l < n && bil[l] < bil[maks])
    { //Line yang diubah
        maks = l;
    }

    //Proses pengecekan, apakah nilai dari anak di sebelah kanan > dari nilai maks
    if (r < n && bil[r] < bil[maks])
    { //Line yang diubah
        maks = r;
    }

    //Proses pengecekan, apakah maks masih sama dengan root
    if (maks != i)
    {
        swap(&bil[i], &bil[maks]);

        //Melakukan heapify kembali terhadap sub-tree yang terkena dampak dari melakukan swap
        heapify(bil, n, maks);
    }
}

int heapSort(int *bil, int n)
{
    int i;

    //Melakukan heapify dimulai dari parent yang berada pada index terbesar
    for (i = n / 2 - 1; i >= 0; i--)
    {
        heapify(bil, n, i);
    }

    //Menukarkan elemen pada index[0] dengan index[(n--) - 1]
    //Satu persatu menghilangkan elemen dari heap sehingga tidak lagi terlibat dalam proses heapify.
    //----------------------------------------------------------------------------------------------
    for (i = n - 1; i >= 0; i--)
    {
        // Menukarkan elemen pada index[0] ke indeks[(n--) - 1]
        swap(&bil[0], &bil[i]);

        // Melakukan proses max heapify
        heapify(bil, i, 0);
    }
}

int main(int argc, char const *argv[])
{
    int *bil;
    int n;
    int i;

    printf("Jumlah bilangan: ");
    scanf("%d", &n);

    bil = (int *)malloc(sizeof(int) * n);

    for (i = 0; i < n; i++)
    {
        scanf("%d", &bil[i]);
    }

    heapSort(bil, n);

    printf("Hasil pengurutan: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", bil[i]);
    }
    printf("\n");

    return 0;
}