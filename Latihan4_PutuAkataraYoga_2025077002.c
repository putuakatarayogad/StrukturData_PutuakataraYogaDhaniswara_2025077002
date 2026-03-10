//NIM
//NAMA
//NILAI

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char nim[20];
    char nama[50];
    int nilai;
    struct Node *prev;
    struct Node *next;
};

struct Node *head = NULL;
struct Node *tail = NULL;

void tambahAwal() {
    struct Node *baru = (struct Node*)malloc(sizeof(struct Node));

    printf("Masukkan NIM  : ");
    scanf("%s", baru->nim);
    printf("Masukkan Nama : ");
    scanf("%s", baru->nama);
    printf("Masukkan Nilai: ");
    scanf("%d", &baru->nilai);

    baru->prev = NULL;
    baru->next = head;

    if (head != NULL) {
        head->prev = baru;
    } else {
        tail = baru;
    }

    head = baru;
}

void tambahAkhir() {
    struct Node *baru = (struct Node*)malloc(sizeof(struct Node));

    printf("Masukkan NIM  : ");
    scanf("%s", baru->nim);
    printf("Masukkan Nama : ");
    scanf("%s", baru->nama);
    printf("Masukkan Nilai: ");
    scanf("%d", &baru->nilai);

    baru->next = NULL;
    baru->prev = tail;

    if (tail != NULL) {
        tail->next = baru;
    } else {
        head = baru;
    }

    tail = baru;
}

void hapusData() {
    char nim[20];
    printf("Masukkan NIM yang ingin dihapus: ");
    scanf("%s", nim);

    struct Node *temp = head;

    while (temp != NULL) {
        if (strcmp(temp->nim, nim) == 0) {

            if (temp == head)
                head = temp->next;

            if (temp == tail)
                tail = temp->prev;

            if (temp->prev != NULL)
                temp->prev->next = temp->next;

            if (temp->next != NULL)
                temp->next->prev = temp->prev;

            free(temp);

            printf("Data berhasil dihapus\n");
            return;
        }
        temp = temp->next;
    }

    printf("Data tidak ditemukan\n");
}

void tampilMaju() {
    struct Node *temp = head;

    if (temp == NULL) {
        printf("Data kosong\n");
        return;
    }

    while (temp != NULL) {
        printf("%s (%s : %d)", temp->nama, temp->nim, temp->nilai);
        if (temp->next != NULL)
            printf(" -> ");
        temp = temp->next;
    }
    printf("\n");
}

void tampilMundur() {
    struct Node *temp = tail;

    if (temp == NULL) {
        printf("Data kosong\n");
        return;
    }

    while (temp != NULL) {
        printf("%s (%s : %d)", temp->nama, temp->nim, temp->nilai);
        if (temp->prev != NULL)
            printf(" -> ");
        temp = temp->prev;
    }
    printf("\n");
}

int main() {

    int pilih;

    do {
        printf("\n=== MENU DOUBLY LINKED LIST ===\n");
        printf("1. Tambah data di awal\n");
        printf("2. Tambah data di akhir\n");
        printf("3. Hapus data\n");
        printf("4. Tampilkan data maju\n");
        printf("5. Tampilkan data mundur\n");
        printf("6. Keluar\n");
        printf("Pilih menu: ");
        scanf("%d", &pilih);

        switch(pilih) {
            case 1:
                tambahAwal();
                break;
            case 2:
                tambahAkhir();
                break;
            case 3:
                hapusData();
                break;
            case 4:
                tampilMaju();
                break;
            case 5:
                tampilMundur();
                break;
        }

    } while (pilih != 6);

    return 0;
}