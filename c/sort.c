#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

void print_array(int array[], int array_length) {
    int i;

    printf("\n");
    for (i = 0; i < array_length; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int * read_array(int array_length) {
    int *array = malloc(array_length * sizeof(int));
    int i;

    for (i = 0; i < array_length; i++) {
        scanf("%d", &array[i]);
    }
    return array;
}

void bubble_sort_inplace(int *array, int array_length) {
    int i,j,aux;

    // Sorts the array
    for (i = 0; i < array_length-1; i++) {
        for (j = 0; j < array_length-1; j++) {
            if (array[j] > array[j+1]) {
                aux = array[j+1];
                array[j+1] = array[j];
                array[j] = aux;
            }
        }
    }
}

int * bubble_sort(int *array, int array_length) {
    int i,j,aux;
    int *array_copy = malloc(array_length * sizeof(int));

    // Copying the array and sorting it's copy
    memcpy(array_copy, array, array_length * sizeof(int));
    bubble_sort_inplace(array_copy, array_length);
    return array_copy;
}

int min_index(int *array, int start_index, int end_index) {
    int i;
    int min = INT_MAX;
    int min_index = -1;

    for (i = start_index; i < end_index; i++) {
        if (array[i] < min) {
            min = array[i];
            min_index = i;
        }
    }
    return min_index;

}

void selection_sort_inplace (int *array, int array_length) {
    int i, aux;

    for (i = 0; i < array_length; i++) {
        int min_value_index = min_index(array, i, array_length);
        if ( array[min_value_index] < array[i]) {
            aux = array[i];
            array[i] = array[min_value_index];
            array[min_value_index] = aux;
        }
    }
}

int * selection_sort(int *array, int array_length) {
    int i,j,aux;
    int *array_copy = malloc(array_length * sizeof(int));

    // Copying the array and sorting it's copy
    memcpy(array_copy, array, array_length * sizeof(int));
    selection_sort_inplace(array_copy, array_length);
    return array_copy;
}

int main () {
    int *arr;
    int *sorted_array;
    int arr_length;
    int i, j, k;
    int aux;

    printf("Array size: ");
    scanf("%d", &arr_length);

    arr = read_array(arr_length);

    // sorted_array = bubble_sort(arr, arr_length);
    sorted_array = selection_sort(arr, arr_length);

    printf("\nSorted array\n");
    print_array(sorted_array, arr_length);
    printf("\n");

    return 0;
}