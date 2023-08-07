#include <bits/stdc++.h>
using namespace std;

int partition(int A[], int l, int h) {
    int pivot = A[l];
    int i = l, j = h;

    while (i < j) {
        while (A[i] <= pivot && i <= h) // Include i <= h to avoid out-of-bounds access
            i++;
        while (A[j] > pivot)
            j--;

        if (i < j)
            swap(A[i], A[j]);
    }

    // Place the pivot element at its correct position
    swap(A[l], A[j]);

    return j;
}

void quickSort(int A[], int l, int h) {
    if (l < h) {
        int j = partition(A, l, h);
        quickSort(A, l, j - 1); // Sort elements before the pivot
        quickSort(A, j + 1, h); // Sort elements after the pivot
    }
}

int main() {
    int A[] = {7, 6, 10, 5, 9, 2, 1, 15, 7, INT32_MAX};
    int n = sizeof(A) / sizeof(A[0]);

    quickSort(A, 0, n - 1); // Pass n -  to exclude the INT32_MAX element from sorting

    for (int i = 0; i < n - 1; i++)
        printf("%d ", A[i]);
    printf("\n");

    return 0;
}
