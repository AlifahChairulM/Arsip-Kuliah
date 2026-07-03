//123240234
#include <iostream>
#include <string>
using namespace std;

struct Pasien {
    string nama;
    int umur;
    string asal_makanan;
    int kondisi; 
    Pasien* next; // setelah
    Pasien* prev; // sebelum
};

Pasien* head; // node sulung
Pasien* tail; // node bontot

// angka jd teks
string getKondisi(int a) {
    switch(a) {
        case 1: return "Level 1 - Ringan";
        case 2: return "Level 2 - Sedang";
        case 3: return "Level 3 - Berat";
        case 4: return "Level 4 - Kritis";
        default: return "Tidak Valid";
    }
}

// sisip di belakang (pakai ekor)
void tambahPasien(string nama, int umur, string asal, int kondisi) {
    Pasien* baru = new Pasien; //buat node
    baru->nama = nama;
    baru->umur = umur;
    baru->asal_makanan = asal;
    baru->kondisi = kondisi;
    baru->next = NULL; 
    baru->prev = NULL; 

    if (head == NULL) {
        head = tail = baru; 
    } else {
        tail->next = baru;  
        baru->prev = tail;  
        tail = baru;         
    }
}

//input pasien
void inputPasien() {
    string nama, asal;
            int umur, kondisi;
            cout << "-----------------------------\n";
            cout << "        Input Pasien\n";
            cout << "-----------------------------\n";
            cout << "Masukkan Nama         : ";
            cin.ignore();
            getline(cin, nama);
            cout << "Masukkan Umur         : ";
            cin >> umur;
            cout << "Masukkan Asal Makanan : ";
            cin.ignore();
            getline(cin, asal);
            cout << "Input Kondisi (1-4)   : ";
            cin >> kondisi;
            tambahPasien(nama, umur, asal, kondisi);
            cout << endl;
            cout << "-----------------------------\n";
}

// Insertion sort 
void insertionSort() {
    if (head == NULL || head->next == NULL) return;
    
    Pasien* sorted = NULL;
    Pasien* posisi = head;
    
    while (posisi != NULL) {
        Pasien* nextNode = posisi->next;
     
        if (posisi->prev != NULL)
            posisi->prev->next = posisi->next;
        if (posisi->next != NULL)
            posisi->next->prev = posisi->prev;
    
        if (sorted == NULL || sorted->umur >= posisi->umur) {
            posisi->next = sorted;
            posisi->prev = NULL;
            if (sorted != NULL)
                sorted->prev = posisi;
            sorted = posisi;
        } else {
            Pasien* temp = sorted;
            while (temp->next != NULL && temp->next->umur < posisi->umur) {
                temp = temp->next;
            }
            posisi->next = temp->next;
            posisi->prev = temp;
            if (temp->next != NULL)
                temp->next->prev = posisi;
            temp->next = posisi;
        }
        posisi = nextNode;
    }
    
    // Update head dan tail
    head = sorted;
    tail = head;
    if (tail != NULL) {
        while (tail->next != NULL) {
            tail = tail->next;
        }
    }
}

// umur (asc)
void tampilData() {
    if (head == NULL) {
        cout << "Data pasien kosong.\n";
        cout << endl;
        return;
    }

    // insertion sort
    insertionSort();

    // data urut
    Pasien* bantu = head;
    while (bantu != NULL) {
        cout << "-------------------------------\n";
        cout << "        Tampilkan Data\n";
        cout << "-------------------------------\n";
        cout << "Nama         : " << bantu->nama << endl;
        cout << "Umur (th)    : " << bantu->umur << endl;
        cout << "Asal Makanan : " << bantu->asal_makanan << endl;
        cout << "Kondisi      : " << getKondisi(bantu->kondisi) << endl;
        cout << "--------------------------------\n";
        bantu = bantu->next;
    }
}

// hapus pasien paling parah
void hapusPasien() {
    if (head == NULL) {
        cout << "Tidak ada pasien untuk dihapus.\n";
        cout << endl;
        return;
    }

    // cari prioritas tertinggi
    int prioritas = 0;
    Pasien* bantu = head;
    while (bantu != NULL) {
        if (bantu->kondisi > prioritas) {
            prioritas = bantu->kondisi;
        }
        bantu = bantu->next;
    }

    // hapus node prioritas
    bantu = head;
    while (bantu != NULL) {
        if (bantu->kondisi == prioritas) {
            if (bantu == head) {  
                head = bantu->next;
                if (head != NULL) {
                    head->prev = NULL;
                } else {
                    tail = NULL; 
                }
            } else if (bantu == tail) {  
                tail = bantu->prev;
                tail->next = NULL;
            } else  { // di tengah
                bantu->prev->next = bantu->next;
                bantu->next->prev = bantu->prev;
            }

            cout << "-----------------------------\n";
            cout << "       Pasien atas nama\n";
            cout << "-----------------------------\n";
            cout << "Nama      | " << bantu->nama << "\n";
            cout << "Prioritas | " << getKondisi(bantu->kondisi) << "\n";
            cout << "-----------------------------\n";
            cout << "Pasien telah dihapus karena selesai pengobatan\n";
            cout << endl;

            delete bantu;
            return;
        }
        bantu = bantu->next;
    }
}

// menu utama
int main() {
    int pilihan;
    do {
        cout << "==================";
        cout << "\nRumah Sakit Sehat\n";
        cout << "==================\n";
        cout << "1. Input Pasien\n";
        cout << "2. Tampilkan Data\n";
        cout << "3. Hapus Pasien\n";
        cout << "4. Keluar\n";
        cout << "==================\n";
        cout << "Menu(1-4): "; 
        cin >> pilihan;
        cout << "==================\n";
        cout << endl;

        if (pilihan == 1) {
            inputPasien();
        }
        else if (pilihan == 2) {
            tampilData();
        }
        else if (pilihan == 3) {
            hapusPasien();
        }
        else if (pilihan == 4) {
            cout << "Keluar program...\n";
        }
        else {
            cout << "Pilihan tidak valid.\n";
        }
    } while (pilihan != 4);

    return 0;
}
