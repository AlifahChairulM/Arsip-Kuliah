#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Node single linked list
struct Node {
    int data;
    struct Node* next; //kenapa harus struct
};

// pointer ke atas stack
struct Node* top = NULL;
int countElemen = 0;

// cek apakah stack kosong
bool isEmpty() {
    return top == NULL;
}

// kembalikan jumlah elemen
int size() {
    return countElemen;
}

// menambahkan elemen ke atas stack
void push(int val) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = top; // node baru menunjuk ke node sebelumnya
    top = newNode;       // update top
    countElemen++;
}

// menghapus elemen dari atas stack
void pop() {
    if (isEmpty()) {
        printf("Stack kosong, tidak bisa pop!\n");
        return;
    }
    struct Node* temp = top;
    top = top->next;
    free(temp); //hapus node top lama
    countElemen--;
}

// melihat elemen paling atas
int peek() {
    if (isEmpty()) {
        printf("Stack kosong!\n");
        return -1; // nilai dummy
    }
    return top->data;
}

// menampilkan semua elemen stack
void printStack() {
    if (isEmpty()) {
        printf("Stack kosong!\n");
        return;
    }

    struct Node* curr = top;

    // cetak node paling atas
    printf("[ top | %d ]", curr->data);
    curr = curr->next;

    // cetak node tengah
    while (curr != NULL && curr->next != NULL) {
        printf(" -> %d", curr->data);
        curr = curr->next;
    }

    // cetak node paling bawah (bottom)
    if (curr != NULL) {
        printf(" -> [ %d | bottom ]", curr->data);
    }

    printf("\n");
}

// contoh penggunaan
int main() {
    system("cls"); 
    push(10);
    push(20);
    push(30);

    printStack(); // [ top | 30 ] -> 20 -> [ 10 | bottom ]

    printf("Elemen teratas: %d\n", peek());
    printf("Ukuran stack: %d\n", size());

    pop();
    printStack(); // [ top | 20 ] -> [ 10 | bottom ]

    printf("Elemen teratas sekarang: %d\n", peek());
    printf("Ukuran stack sekarang: %d\n", size());

    pop();
    pop();
    printStack(); // Stack kosong

    printf("Elemen teratas sekarang: %d\n", peek());
    printf("Ukuran stack sekarang: %d\n", size());

    return 0;
}
