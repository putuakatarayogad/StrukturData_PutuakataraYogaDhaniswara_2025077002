#include <stdio.h>

#define MAX 10

int data[MAX];
int next[MAX];
int prev[MAX];

int head = -1;
int tail = -1;
int freeHead = 0;

// Inisialisasi free list
void init() {
    for (int i = 0; i < MAX - 1; i++) {
        next[i] = i + 1;
    }
    next[MAX - 1] = -1;
}

// Ambil node dari free list
int allocate() {
    if (freeHead == -1) return -1;
    int newNode = freeHead;
    freeHead = next[freeHead];
    return newNode;
}

// Kembalikan node ke free list
void deallocate(int idx) {
    next[idx] = freeHead;
    freeHead = idx;
}

// Insert di awal
void insertAwal(int val) {
    int newNode = allocate();
    if (newNode == -1) {
        printf("List penuh!\n");
        return;
    }

    data[newNode] = val;
    next[newNode] = head;
    prev[newNode] = -1;

    if (head != -1) {
        prev[head] = newNode;
    } else {
        tail = newNode;
    }

    head = newNode;
}

// Insert di akhir
void insertAkhir(int val) {
    int newNode = allocate();
    if (newNode == -1) {
        printf("List penuh!\n");
        return;
    }

    data[newNode] = val;
    next[newNode] = -1;
    prev[newNode] = tail;

    if (tail != -1) {
        next[tail] = newNode;
    } else {
        head = newNode;
    }

    tail = newNode;
}

// Delete di awal
void deleteAwal() {
    if (head == -1) {
        printf("List kosong!\n");
        return;
    }

    int temp = head;
    head = next[head];

    if (head != -1) {
        prev[head] = -1;
    } else {
        tail = -1;
    }

    deallocate(temp);
}

// Delete di akhir
void deleteAkhir() {
    if (tail == -1) {
        printf("List kosong!\n");
        return;
    }

    int temp = tail;
    tail = prev[tail];

    if (tail != -1) {
        next[tail] = -1;
    } else {
        head = -1;
    }

    deallocate(temp);
}

// Tampil maju
void tampilMaju() {
    int curr = head;
    printf("Maju: ");
    while (curr != -1) {
        printf("%d ", data[curr]);
        curr = next[curr];
    }
    printf("\n");
}

// Tampil mundur
void tampilMundur() {
    int curr = tail;
    printf("Mundur: ");
    while (curr != -1) {
        printf("%d ", data[curr]);
        curr = prev[curr];
    }
    printf("\n");
}

// Main
int main() {
    init();

    insertAwal(10);
    insertAwal(20);
    insertAkhir(30);
    insertAkhir(40);

    tampilMaju();
    tampilMundur();

    deleteAwal();
    deleteAkhir();

    tampilMaju();
    tampilMundur();

    return 0;
}