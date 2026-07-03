#include <iostream>
#include <string>
using namespace std;

struct Pasien {
    string nama;         
    int umur;             
    string asal_makanan;  
    int kondisi;         
    Pasien* next;// Pointer ke node lanjut
};

Pasien* head = NULL;// Pointer kepala linked list

// konversi angka kondisi jd teks 
string getKondisi(int a) {
    switch(a) {
        case 1: return "Level 1 - Ringan";    
        case 2: return "Level 2 - Sedang";    
        case 3: return "Level 3 - Berat";     
        case 4: return "Level 4 - Kritis";    
        default: return "Tidak Valid";        
    }
}

// + baru di akhir linked list (sisip belakang)
void tambahPasien(string nama, int umur, string asal, int kondisi) {
    Pasien* baru = new Pasien;// Alokasi memori node baru
    baru->nama = nama;          
    baru->umur = umur;          
    baru->asal_makanan = asal;  
    baru->kondisi = kondisi;    
    baru->next = NULL;// Node baru jd bontot

    // linked list kosong,node baru = head
    if (head == NULL) {
        head = baru;
    } else {
        // Traverse 
        Pasien* bantu = head;
        while (bantu->next != NULL) {
            bantu = bantu->next;
        }
        bantu->next = baru;// Hub akhir ke baru
    }
}

// input data pasien dari user
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
    
    // Validasi input kondisi (harus 1-4)
    do {
        cout << "Input Kondisi (1-4)   : ";
        cin >> kondisi;
        if (kondisi < 1 || kondisi > 4) {
            cout << "Kondisi tidak valid! Harus 1-4.\n";
        }
    } while (kondisi < 1 || kondisi > 4);

    // Panggil fungsi untuk menambahkan pasien
    tambahPasien(nama, umur, asal, kondisi);
    cout << "-----------------------------\n";
    cout << "Data pasien berhasil ditambahkan!\n";
    cout << endl;
}

// urut berdasarkan umur (asc)
void tampilData() {
    if (head == NULL) {
        cout << "Data pasien kosong.\n";
        cout << endl;
        return;
    }

    // insertion sort pada linked list
    Pasien* sortedHead = NULL;// Head sudah terurut
    Pasien* posisi = head;// Pointer traverse list asli
    
    while (posisi != NULL) {
        Pasien* nextNode = posisi->next;// Simpan node next
        
        if (sortedHead == NULL || sortedHead->umur >= posisi->umur) {
            // awal sorted list
            posisi->next = sortedHead;
            sortedHead = posisi;
        } else {
            // Cari posisi tepat
            Pasien* temp = sortedHead;
            while (temp->next != NULL && temp->next->umur < posisi->umur) {
                temp = temp->next;
            }
            // posisi yang ditemukan
            posisi->next = temp->next;
            temp->next = posisi;
        }
        posisi = nextNode;// Pindah ke node nex
    }

    // header 1x muncul
    cout << "-------------------------------\n";
    cout << "        Tampilkan Data\n";
    cout << "-------------------------------\n";

    // Tampilkan all data dari sorted list
    Pasien* bantu = sortedHead;
    while (bantu != NULL) {
        cout << "Nama         : " << bantu->nama << endl;
        cout << "Umur (th)    : " << bantu->umur << endl;
        cout << "Asal Makanan : " << bantu->asal_makanan << endl;
        cout << "Kondisi      : " << getKondisi(bantu->kondisi) << endl;
        cout << "--------------------------------\n";
        bantu = bantu->next;// Pindah ke node berikutnya
    }
}

// kondisi paling parah
void hapusPasien() {
    if (head == NULL) {
        cout << "Tidak ada pasien untuk dihapus.\n";
        cout << endl;  
        return;
    }

    // Cari prioritas
    int prioritas = 0;  
    Pasien* bantu = head;
    while (bantu != NULL) {
        if (bantu->kondisi > prioritas) {
            prioritas = bantu->kondisi;// Update 
        }
        bantu = bantu->next;
    }

    // Cari dan hapas prioritas
    Pasien* prev = NULL;// Pointer ke node sebelumnya
    bantu = head;
    while (bantu != NULL) {
        if (bantu->kondisi == prioritas) {
            if (prev == NULL) {
                head = bantu->next;
            } else {
                prev->next = bantu->next;
            }
            
            cout << "-----------------------------\n";
            cout << "       Pasien atas nama\n";
            cout << "-----------------------------\n";
            cout << "Nama      | " << bantu->nama << "\n";
            cout << "Prioritas | " << getKondisi(bantu->kondisi) << "\n";
            cout << "-----------------------------\n";
            cout << "Pasien telah dihapus karena selesai pengobatan\n";
            cout << endl;
            
            delete bantu;// Bebaskan memori
            return;        
        }
        prev = bantu;      
        bantu = bantu->next;  
    }
}

// Fungsi utama program
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

        // Proses pilihan user
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
            cout << "Pilihan tidak valid.\n";// Hinput ga valid
        }
    } while (pilihan != 4);    // Loop 
    return 0;// Akhir program
}