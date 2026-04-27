#include <stdio.h>

#define MAX 5

int stack[MAX];
int top = -1;

// Fungsi push
void push(int data) {
    if (top == MAX - 1) {
        printf("Stack penuh!\n");
    } else {
        top++;
        stack[top] = data;
        printf("%d berhasil ditambahkan ke stack\n", data);
    }
}

// Fungsi pop
void pop() {
    if (top == -1) {
        printf("Stack kosong!\n");
    } else {
        printf("%d dihapus dari stack\n", stack[top]);
        top--;
    }
}

// Fungsi tampil stack
void display() {
    int i;
    if (top == -1) {
        printf("Stack kosong!\n");
    } else {
        printf("Isi stack:\n");
        for (i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    }
}

int main() {
    push(10);
    push(20);
    push(30);
    pop();

    display();

    return 0;
}