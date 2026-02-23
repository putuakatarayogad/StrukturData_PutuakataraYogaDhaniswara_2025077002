#include <stdio.h>

int hitungTotal(int arr[], int size) {
    int total = 0;
    for(int i = 0; i < size; i++) {
        total += arr[i];
    }
    return total;
}

float hitungRataRata(int arr[], int size) {
    int total = hitungTotal(arr, size);
    return (float) total / size;
}

int nilaiTertinggi(int arr[], int size) {
    int max = arr[0];
    for(int i = 1; i < size; i++) {
        if(arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

void tampilkanData(int arr[], int size) {
    printf("Data Nilai:\n");
    for(int i = 0; i < size; i++) {
        printf("Nilai ke-%d : %d\n", i+1, arr[i]);
    }
}

int main() {
    int nilai[10];

    for(int i = 0; i < 10; i++) {
        printf("Masukkan nilai ke-%d: ", i+1);
        scanf("%d", &nilai[i]);
    }

    printf("\n===== HASIL =====\n");
    tampilkanData(nilai, 10);
    printf("Total Nilai      : %d\n", hitungTotal(nilai, 10));
    printf("Rata-rata Nilai  : %.2f\n", hitungRataRata(nilai, 10));
    printf("Nilai Tertinggi  : %d\n", nilaiTertinggi(nilai, 10));

    return 0;
}