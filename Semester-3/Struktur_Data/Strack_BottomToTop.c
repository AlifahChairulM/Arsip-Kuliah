#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Node single linked list
struct Node {
    int data;
    struct Node* next; //kenapa harus ada struct node
};

// pointer ke bawah dan atas stack
struct Node* bottom = NULL;
struct Node* top = NULL;
int countElemen = 0;

// cek apakah stack kosong
bool isEmpty() {
    return bottom == NULL;
}

// kembalikan jumlah elemen
int size() {
    return countElemen;
}

// menambahkan elemen ke atas stack (kanan)
void push(int val) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;

    if (isEmpty()) {
        // stack kosong → bottom & top sama
        bottom = newNode;
        top = newNode;
    } else {
        // stack ada isinya → tambahkan di kanan (setelah top lama)
        top->next = newNode;
        top = newNode;
    }
    countElemen++;
}

// menghapus elemen dari atas stack (kanan)
void pop() {
    if (isEmpty()) {
        printf("Stack kosong, tidak bisa pop!\n");
        return;
    }

    if (bottom == top) {
        // hanya ada 1 elemen
        free(top);
        bottom = NULL;
        top = NULL;
    } else {
        // cari node sebelum top
        struct Node* curr = bottom;
        while (curr->next != top) {
            curr = curr->next;
        }
        free(top);           // hapus node top lama
        top = curr;          // top geser ke node sebelumnya
        top->next = NULL;    // pastikan pointer next kosong
    }
    countElemen--;
}

// melihat elemen paling atas
int peek() {
    if (isEmpty()) {
        printf("Stack kosong!\n");
        return -1; // dummy
    }
    return top->data;
}

// menampilkan semua elemen stack
void printStack() {
    if (isEmpty()) {
        printf("Stack kosong!\n");
        return;
    }

    struct Node* curr = bottom;

    // cetak node paling bawah
    printf("[ bottom | %d ]", curr->data);
    curr = curr->next;

    // cetak node tengah
    while (curr != NULL && curr->next != NULL) {
        printf(" -> %d", curr->data);
        curr = curr->next;
    }

    // cetak node paling atas
    if (curr != NULL) {
        printf(" -> [ %d | top ]", curr->data);
    }

    printf("\n");
}

// contoh penggunaan
int main() {
    system("cls"); // di Linux/Mac bisa ganti "clear"

    push(10);
    push(20);
    push(30);

    printStack(); // bottom 10 -> 20 -> top 30

    printf("Elemen teratas: %d\n", peek());
    printf("Ukuran stack: %d\n", size());

    pop();
    printStack(); // bottom 10 -> top 20

    printf("Elemen teratas sekarang: %d\n", peek());
    printf("Ukuran stack sekarang: %d\n", size());

    pop();
    pop();
    printStack(); // Stack kosong

    printf("Elemen teratas sekarang: %d\n", peek());
    printf("Ukuran stack sekarang: %d\n", size());

    return 0;
}
