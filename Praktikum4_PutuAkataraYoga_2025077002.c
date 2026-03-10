#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* head = NULL;

void tambahAwal(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = head;

    if (head != NULL) {
        head->prev = newNode;
    }

    head = newNode;
}

void tambahAkhir(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node* temp = head;

    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        newNode->prev = NULL;
        head = newNode;
        return;
    }

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
}

void hapusAwal() {
    if (head == NULL) {
        printf("List kosong!\n");
        return;
    }

    struct Node* temp = head;
    head = head->next;

    if (head != NULL) {
        head->prev = NULL;
    }

    free(temp);
    printf("Node pertama berhasil dihapus.\n");
}

void tampilMaju() {
    struct Node* temp = head;

    if (temp == NULL) {
        printf("List kosong.\n");
        return;
    }

    printf("Data dalam list: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int pilihan, data;

    tambahAkhir(10);
    tambahAkhir(20);
    tambahAkhir(30);
    tambahAkhir(40);
    tambahAkhir(50);

    do {
        printf("\n=== MENU DOUBLY LINKED LIST ===\n");
        printf("1. Tambah di awal\n");
        printf("2. Tambah di akhir\n");
        printf("3. Hapus di awal\n");
        printf("4. Tampil maju\n");
        printf("5. Keluar\n");
        printf("Pilih: ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                printf("Masukkan data: ");
                scanf("%d", &data);
                tambahAwal(data);
                break;

            case 2:
                printf("Masukkan data: ");
                scanf("%d", &data);
                tambahAkhir(data);
                break;

            case 3:
                hapusAwal();
                break;

            case 4:
                tampilMaju();
                break;

            case 5:
                printf("Program selesai.\n");
                break;

            default:
                printf("Pilihan tidak valid.\n");
        }

    } while (pilihan != 5);

    return 0;
}