#include <stdio.h>

// Merge two subarrays into one sorted array
void merge(int arr[], int left, int middle, int right) {
    // ... (same as before)
}

// Merge Sort function
void mergeSort(int arr[], int left, int right) {
    // ... (same as before)
}

int main() {
    int arr[100]; // Maximum array size
    int arr_size;

    printf("Enter the number of elements: ");
    scanf("%d", &arr_size);

    printf("Enter %d elements:\n", arr_size);
    for (int i = 0; i < arr_size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Original array:\n");
    for (int i = 0; i < arr_size; i++) {
        printf("%d ", arr[i]);
    }

    mergeSort(arr, 0, arr_size - 1);

    printf("\nSorted array:\n");
    for (int i = 0; i < arr_size; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
