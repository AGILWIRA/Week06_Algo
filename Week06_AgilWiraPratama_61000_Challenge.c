#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

typedef struct mahasiswa
{
    char nama[30];
    int nilaiTugas[15];
    int nilaiAkhir;

    struct mahasiswa *next, *prev;
} mahasiswa;

int avg(int *nilaiTugas)
{
    int sum = 0;
    for (int i = 4; i < 14; i++)
    {
        sum += nilaiTugas[i];
    }
    return sum/10;
}

void inputStudent(struct mahasiswa **head, struct mahasiswa **tail)
{
    char nama[30];
    int nilaiTugas[15];
    int nilaiAkhir;
    int i;
    struct mahasiswa *curr, *node;
    system("cls");
    printf("================================\n");
    printf("----   Input Data Mahasiswa  ---\n");
    printf("================================\n");
    printf("Nama\t\t: ");
    fflush(stdin);
    scanf("%[^\n]", &nama);
    for (i = 0; i < 14; i++)
    {
        printf("Nilai ke-%d\t: ", i + 1);
        fflush(stdin);
        scanf("%d", &nilaiTugas[i]);
    }
    nilaiAkhir = avg(nilaiTugas);

    node = (struct mahasiswa *)malloc(sizeof(struct mahasiswa));
    node->next = NULL;

    strcpy(node->nama, nama);
    for (i = 0; i < 14; i++)
    {
        node->nilaiTugas[i] = nilaiTugas[i];
    }
    node->nilaiAkhir = nilaiAkhir;

    if ((*head) == NULL)
    {
        (*tail) = node;
        (*head) = node;
    }
    else
    {
        node->next = NULL;
        node->prev = (*tail);
        (*tail)->next = node;
        (*tail) = node;
    }
    printf("Input data berhasil!\n");
    system("pause");
}

void swap(int *bil1, int *bil2)
{
    int temp;
    temp = *bil1;
    *bil1 = *bil2;
    *bil2 = temp;
}

int partition(int *bil, int l, int r)
{
    int j;
    int pivot = bil[r];
    int i = l - 1;
    for (j = l; j <= r - 1; j++){
        if (bil[j] <= pivot)
        {
            i++;
            swap(&bil[i], &bil[j]);
        }
    }
    swap(&bil[i + 1], &bil[r]);
    return (i + 1);
}

void quickSort(int *bil, int l, int r)
{
    if (l < r)
    {
        int pi = partition(bil, l, r);

        quickSort(bil, l, pi - 1);
        quickSort(bil, pi + 1, r);
    }
}

void merge(int *bil, int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1];
    int R[n2];
    for (i = 0; i < n1; i++)
    {
        L[i] = bil[l + i];
    }

    for (j = 0; j < n2; j++)
    {
        R[j] = bil[m + 1 + j];
    }

    i = 0;
    j = 0;
    k = l;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
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

    while (i < n1)
    {
        bil[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        bil[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int *bil, int l, int r)
{
    if (l < r)
    {
        int m = (l + r) / 2;

        mergeSort(bil, l, m);
        mergeSort(bil, m + 1, r);

        merge(bil, l, m, r);
    }
}

void shellSort(int *arr, int n)
{
    int i, j, gap;
    for (gap = n / 2; gap > 0; gap /= 2)
    {
        for (i = gap; i < n; i++)
        {
            int temp = arr[i];

            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];
            arr[j] = temp;
        }
    }
}

void heapify(int *bil, int n, int i)
{
    int maks = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && bil[l] > bil[maks])
    {
        maks = l;
    }
    if (r < n && bil[r] > bil[maks])
    {
        maks = r;
    }
    if (maks != i)
    {
        swap(&bil[i], &bil[maks]);
        heapify(bil, n, maks);
    }
}

void heapSort(int *bil, int n)
{
    int i;

    for (i = n / 2 - 1; i >= 0; i--)
    {
        heapify(bil, n, i);
    }

    for (i = n - 1; i >= 0; i--)
    {
        swap(&bil[0], &bil[i]);

        heapify(bil, i, 0);
    }
}

void menuSort(mahasiswa **head, mahasiswa **tail)
{
    mahasiswa *curr;
    curr = (*head);
    int choice, choiceSort, i, nilailast;
    int *nilai;
    nilai = (int *)malloc(sizeof(int) * 14);
    system("cls");
    printf("1. Ascending\n");
    printf("2. Descending\n");
    printf("Pilih: ");
    scanf("%d", &choiceSort);

    system("cls");
    printf("1. Quick Sort\n");
    printf("2. Merge Sort\n");
    printf("3. Shell Sort\n");
    printf("4. Heap Sort\n");
    printf("Pilih: ");
    scanf("%d", &choice);

    while (curr != NULL)
    {
        for (i = 0; i < 14; i++)
        {
            nilai[i] = curr->nilaiTugas[i];
        }
        if (choice == 1)
            quickSort(nilai, 0, 13);
        else if (choice == 2)
            mergeSort(nilai, 0, 13);
        else if (choice == 3)
            shellSort(nilai, 14);
        else if (choice == 4)
            heapSort(nilai, 14);
        for (int j = 0; j < 14; j++)
        {
            curr->nilaiTugas[j] = nilai[j];
        }
        curr = curr->next;
    }
    prinData((&*head), choiceSort);
    printf("\n Data berhasil di sort!\n");
}

void prinData(struct mahasiswa **head, int n)
{
    if (*head == NULL)
    {
        printf("Data masih kosong!\n");
        return;
    }
    mahasiswa *temp = *head;
    while (temp != NULL)
    {
        printf("==========\n");
        printf("Nama: %s\n", temp->nama);
        printf("Nilai Tugas: ");
        for (int i = 0; i < 14; i++)
        {
            printf("%i ", temp->nilaiTugas[i]);
        }
        printf("\n");
        printf("Nilai Akhir: %i\n", temp->nilaiAkhir);
        temp = temp->next;
    }
}

int main() {
    int choice;
    mahasiswa *head, *tail;
    head = tail = NULL;
    while (1)
    {
        printf ("\n\n----  MENU  ----\n");
        printf ("----------------\n");
        printf ("1. Input Data\n");
        printf ("2. Sort Nilai\n");
        printf ("3. Data\n");
        printf ("0. Exit\n");
        printf ("Pilihan : ");
        scanf ("%d" ,&choice);
        printf ("\n");
        switch (choice)
        {
        case 1:
            inputStudent(&head, &tail);
            getch();
            break;
        case 2:
            menuSort(&head, &tail);
            getch();
            break;
        case 3:
            prinData (&head, &tail);
            getch();
            break;
        case 0:
            return 0;
        default:
            printf ("\nEROR - Menu yang anda pilih tidak tersedia");
            getch();
            break;
        }
    }
}