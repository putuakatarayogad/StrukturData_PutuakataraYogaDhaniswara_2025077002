#include <stdio.h>

int main() {

    //Looping Dasar
    printf("Angka 1 sampai 10:\n");
    for(int i = 1; i <= 10; i++) {
        printf("%d ", i);
    }

    //Bilangan genap dari 1 sampai 50
    for(int i = 2; i <= 50; i += 2){
        printf("%d", i);
    }

    //Kasus Perhitungan
    int N, jumlah = 0;

    printf("Masukkan angka N: ");
    scanf("%d", &N);

    //Menghitung jumlah bilangan dari 1 sampai N
    for(int i = 1; i <= N; i++) {
        jumlah += i;
    }

    printf("Jumlah bilangan dari 1 sampai %d adalah %d\n", N, jumlah);

    //Studi Kasus Sederhana
    int nilai[5];
    int total = 0;
    float rata_rata;

    //Meminta input 5 nilai
    for(int i = 0; i < 5; i++) {
        printf("Masukkan nilai ke-%d:", i+1);
        scanf("%d", &nilai[i]);
        total += nilai[i];
    }

    rata_rata = total / 5.0;

    printf("Total nilai: %d\n", total);
    printf("Rata-rata nilai: %.2f\n", rata_rata);

    return 0;
}

