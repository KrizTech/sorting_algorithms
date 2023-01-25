#include <stdio.h>
#include <stdlib.h>

#define BASE 10

void radix_sort(int* array, size_t size) {
    int max = array[0];
    for (size_t i = 1; i < size; i++) {
        if (array[i] > max) {
            max = array[i];
        }
    }

    int* temp = (int*) malloc(size * sizeof(int));

    for (int exp = 1; max/exp > 0; exp *= BASE) {
        int count[BASE] = {0};

        for (size_t i = 0; i < size; i++) {
            count[(array[i]/exp) % BASE]++;
        }

        for (int i = 1; i < BASE; i++) {
            count[i] += count[i - 1];
        }

        for (size_t i = size - 1; i < size; i--) {
            temp[count[(array[i]/exp) % BASE] - 1] = array[i];
            count[(array[i]/exp) % BASE]--;
        }

        for (size_t i = 0; i < size; i++) {
            array[i] = temp[i];
        }

        printf("Array after sorting on digit %d: [ ", exp);
        for (size_t i = 0; i < size; i++) {
            printf("%d ", array[i]);
        }
        printf("]\n");
    }

    free(temp);
}
