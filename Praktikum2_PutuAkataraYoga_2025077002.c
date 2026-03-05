#include <stdio.h>
#include <stdlib.h>

// Struktur node
struct Node {
    int data;
    struct Node* next;
};

// Membuat node baru
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Menambahkan node di awal
void insertFirst(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

// Menambahkan node di akhir
void insertLast(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    
    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
}

// Menampilkan isi linked list
void display(struct Node* head) {
    struct Node* temp = head;
    printf("Isi Linked List: ");

    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Menghapus node berdasarkan nilai
void deleteValue(struct Node** head, int value) {
    struct Node *temp = *head, *prev = NULL;

    if (temp != NULL && temp->data == value) {
        *head = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Data tidak ditemukan\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
}

int main() {
    struct Node* head = NULL;

    // Membuat minimal 5 node
    insertLast(&head, 10);
    insertLast(&head, 20);
    insertLast(&head, 30);
    insertLast(&head, 40);
    insertLast(&head, 50);

    display(head);

    // Tambah di awal
    insertFirst(&head, 5);
    printf("Setelah tambah di awal:\n");
    display(head);

    // Tambah di akhir
    insertLast(&head, 60);
    printf("Setelah tambah di akhir:\n");
    display(head);

    // Hapus node berdasarkan nilai
    deleteValue(&head, 30);
    printf("Setelah menghapus nilai 30:\n");
    display(head);

    return 0;
}