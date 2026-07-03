#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 5

char stack[MAX][100]; // array of string untuk nama piring
int top = -1;

int isEmpty() {
    return top == -1;
}

int isFull() {
    return top == MAX - 1;
}

void push() {
    if (isFull()) {
        printf("Tumpukan piring penuh!\n");
        return;
    }
    char nama[100];
    printf("Masukkan nama piring: ");
    getchar(); // buang newline dari input sebelumnya
    fgets(nama, sizeof(nama), stdin);

    // hapus newline dari fgets
    nama[strcspn(nama, "\n")] = '\0';

    strcpy(stack[++top], nama);
    printf("Piring '%s' berhasil ditambahkan.\n", nama);
}

void pop() {
    if (isEmpty()) {
        printf("Tumpukan piring kosong!\n");
        return;
    }
    printf("Piring '%s' diambil dari tumpukan.\n", stack[top--]);
}

void peek() {
    if (isEmpty()) {
        printf("Tumpukan piring kosong!\n");
        return;
    }
    printf("Piring paling atas: %s\n", stack[top]);
}

void size() {
    printf("Jumlah piring dalam stack: %d\n", top + 1);
}

void all() {
    if (isEmpty()) {
        printf("Tumpukan piring kosong!\n");
        return;
    }
    printf("Isi tumpukan piring:\n");
    for (int i = top, nomor = top + 1; i >= 0; i--, nomor--) {
        printf("%d. %s\n", nomor, stack[i]);
    }
}

int main() {
    int pilihan;

    do {
        system("cls"); // kalau di Linux/Mac ganti dengan system("clear");
        printf("\n=== Tumpukan Piring (Stack Array) ===\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. isEmpty\n");
        printf("5. Size\n");
        printf("6. Cetak isi tumpukan\n");
        printf("7. Keluar\n");
        printf("========================\n");
        printf("Pilih menu: ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                system("cls");
                push();
                system("pause");
                break;
            case 2:
                system("cls");
                pop();
                system("pause");
                break;
            case 3:
                system("cls");
                peek();
                system("pause");
                break;
            case 4:
                system("cls");
                printf("%s\n", isEmpty() ? "Tumpukan kosong." : "Tumpukan tidak kosong.");
                system("pause");
                break;
            case 5:
                system("cls");
                size();
                system("pause");
                break;
            case 6:
                system("cls");
                all();
                system("pause");
                break;
            case 7:
                system("cls");
                printf("Keluar dari program.\n");
                system("pause");
                break;
            default:
                printf("Pilihan tidak valid!\n");
        }
    } while (pilihan != 7);

    return 0;
}