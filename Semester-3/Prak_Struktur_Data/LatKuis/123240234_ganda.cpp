//123240234
#include <iostream>
#include <string>
using namespace std;

struct Pasien {
    string nama;
    int umur;
    string asal_makanan;
    int kondisi; 
    Pasien* next; 
    Pasien* prev; 
}; 

Pasien* head, *tail, *baru, *bantu, *hapus;

void buatList() {
    head = NULL;
    tail = NULL;
}

//konversi angka jd teks
string getKondisi(int a) {
    switch(a) {
        case 1: return "Level 1 - Ringan";
        case 2: return "Level 2 - Sedang";
        case 3: return "Level 3 - Berat";
        case 4: return "Level 4 - Kritis";
        default: return "Tidak Valid";
    }
}

// sisip di belakang urut dateng
void tambahPasien(string nama, int umur, string asal, int kondisi) {
    baru = new Pasien; //buat node baru
    baru->nama = nama;
    baru->umur = umur;
    baru->asal_makanan = asal;
    baru->kondisi = kondisi;
    baru->next = NULL; 
    baru->prev = NULL; 

    if (head == NULL) {
        head = baru;
        tail = baru;
    } else {
        // Tambah tail
        tail->next = baru; 
        baru->prev = tail; 
        tail = baru; // update 
    }
}

// fungsi input pasien
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

    // validasi kondisi (1-4)
    do {
        cout << "Input Kondisi (1-4)   : ";
        cin >> kondisi;
        if (kondisi < 1 || kondisi > 4) {
            cout << "Kondisi tidak valid! Harus 1-4.\n";
        }
    } while (kondisi < 1 || kondisi > 4);

    tambahPasien(nama, umur, asal, kondisi);
    cout << "\nData pasien berhasil ditambahkan!\n";
    cout << "-----------------------------\n\n";
}

// Insertion sort umur (asc)
void insertionSort() {
    if (head == NULL || head->next == NULL) return; 
    
    Pasien* sorted = NULL; 
    Pasien* posisi = head; 
    
    while (posisi != NULL) {
        Pasien* nextNode = posisi->next; 
        
        // Lepaskan node dari list asli
        if (posisi->prev != NULL) 
            posisi->prev->next = posisi->next;
        if (posisi->next != NULL) 
            posisi->next->prev = posisi->prev;
        
        // Insert ke sorted list
        if (sorted == NULL || sorted->umur >= posisi->umur) {
            posisi->next = sorted;
            posisi->prev = NULL;
            if (sorted != NULL) 
                sorted->prev = posisi;
            sorted = posisi;
        } else {
            // Cari posisi yang tepat
            Pasien* temp = sorted;
            while (temp->next != NULL && temp->next->umur < posisi->umur) {
                temp = temp->next;
            }
            // Insert setelah temp
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
    // Update tail
    tail = head;
    if (tail != NULL) {
        while (tail->next != NULL) {
            tail = tail->next;
        }
    }
}

// urut asc umur
void tampilData() {
    if (head == NULL) {
        cout << "Data pasien kosong.\n";
        cout << endl;
        return;
    }
    //insertion sort untuk mengurutkan list asli
    insertionSort();

    //header
    cout << "-------------------------------\n";
    cout << "        Tampilkan Data\n";
    cout << "-------------------------------\n";
    
    bantu = head;
    while (bantu != NULL) {
        cout << "Nama         : " << bantu->nama << endl;
        cout << "Umur (th)    : " << bantu->umur << endl;
        cout << "Asal Makanan : " << bantu->asal_makanan << endl;
        cout << "Kondisi      : " << getKondisi(bantu->kondisi) << endl;
        cout << "--------------------------------\n";
        bantu = bantu->next;
    }
    cout << endl;
}

// Hapus pasien paling parah
void hapusPasien() {
    if (head == NULL) {
        cout << "Tidak ada pasien untuk dihapus.\n";
        cout << endl;
        return;
    }

    // cari prioritas 
    int prioritas = 0;
    bantu = head;
    while (bantu != NULL) {
        if (bantu->kondisi > prioritas) {
            prioritas = bantu->kondisi;
        }
        bantu = bantu->next;
    }

    // hapus node pertama prioritas
    bantu = head;
    while (bantu != NULL) {
        if (bantu->kondisi == prioritas) {
            if (bantu == head && bantu == tail) {
                // Hanya satu node
                head = NULL;
                tail = NULL;
            } else if (bantu == head) {
                head = head->next;
                head->prev = NULL;
            } else if (bantu == tail) {
                tail = tail->prev;
                tail->next = NULL;
            } else {
                // tengah
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

//menu utama
int main() {
    buatList();
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
    
    // Bersihkan memory 
    bantu = head;
    while (bantu != NULL) {
        hapus = bantu;
        bantu = bantu->next;
        delete hapus;
    }
    return 0;
}