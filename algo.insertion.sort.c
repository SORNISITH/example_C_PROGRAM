#include <stdio.h>
#include <stdlib.h>
#define SIZE 6

void insertion_sort(int size, int arr[size]);
void print_arr(int a[], int size);

int main(int argc, char* argv[])
{

    int arr[SIZE] = { 8, 7, 10, 9, 1, 5 };
    print_arr(arr, SIZE);
    insertion_sort(SIZE, arr);
    print_arr(arr, SIZE);
    return EXIT_SUCCESS;
}
void insertion_sort(int size, int arr[size])
{
    for (int i = 1; i < size; i++) {
        int temp = arr[i];
        int j = i - 1;
        while (j <= i && arr[j] > temp) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}

void print_arr(int a[], int size)
{
    for (int i = 0; i < size; i++) {
        if (i == 0) {
            printf(" %d ", a[i]);
        } else {
            printf(", %d ", a[i]);
        }
    }
    printf("\n");
}

// pointer

// int main(int argc, char* argv[])
// {
//     int arr[7] = { 10, 5, 3, 1, 6, 8, 9 };
//     int len = sizeof(arr) / sizeof(int);
//     int *p_start = arr + 1, *p_end = arr + len - 1;
//
//     for (; p_start <= p_end; p_start++) {
//         for (int k = 0; k <= p_start - arr; k++) {
//             if (*p_start < arr[k]) {
//                 *p_start ^= arr[k];
//                 arr[k] ^= *p_start;
//                 *p_start ^= arr[k];
//             }
//         }
//     }
//
//     for (int i = 0; i < len; i++) {
//         printf("%d-", arr[i]);
//     }
//
//     return EXIT_SUCCESS;
// }
