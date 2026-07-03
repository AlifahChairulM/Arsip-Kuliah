#include <iostream>
#include <string>
using namespace std;

struct Pasien {
    string nama;
    int umur;
    string asal_makanan;
    int kondisi;
    Pasien* next; // pointer ke node lanjut   
};
Pasien* kepala; // pointer ke node kepala

// buat list baru
void buatListBaru() {
    kepala = new Pasien; //alokasi
    kepala->umur = 0;    // simpan jml node
    kepala->next = kepala; // tunjuk diri sendiri   
}

// cek list kosong
bool cekListKosong() {
    return (kepala->umur == 0);
}

// konversi angka jd teks
string getKondisi(int a) {
    switch(a) {
        case 1: return "Level 1 - Ringan";
        case 2: return "Level 2 - Sedang";
        case 3: return "Level 3 - Berat";
        case 4: return "Level 4 - Kritis";
        default: return "Tidak Valid";
    }
}

// tambah node pasien di belakang
void tambahPasien(string nama, int umur, string asal, int kondisi) {
    Pasien* baru = new Pasien;
    baru->nama = nama;
    baru->umur = umur;
    baru->asal_makanan = asal;
    baru->kondisi = kondisi;

    // sisip di belakang 
    Pasien* bantu = kepala;
    while (bantu->next != kepala) {
        bantu = bantu->next;
    }
    baru->next = kepala; 
    bantu->next = baru;
    kepala->umur += 1; // tambah jumlah node
}

// input data pasien
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
    } while (kondisi < 1 || kondisi > 4);

    tambahPasien(nama, umur, asal, kondisi);
    cout << "\n-----------------------------\n\n";
}

// umur(asc)
void tampilData() {
    if (cekListKosong()) {
        cout << "Data pasien kosong.\n\n";
        return;
    }

    int n = kepala->umur;
    bool ditukar;

  // Bubble sort murni pada linked list
do {
    ditukar = false;
    Pasien* prev = kepala;             
    Pasien* posisi = kepala->next;  
    Pasien* nextNode = posisi->next;   
    
    for (int i = 0; i < n - 1; i++) {
        if (posisi->umur > nextNode->umur) {
            posisi->next = nextNode->next;  
            nextNode->next = posisi;       
            prev->next = nextNode;           
            // Update 
            ditukar = true;
            prev = nextNode;            
            nextNode = posisi->next;  
        } else {
            prev = posisi;            
            posisi = nextNode;        
            nextNode = nextNode->next;  
        }
    } 
    n--; // Optimasiosisi benar
} while (ditukar);

    // sudah terurut
    Pasien* bantu = kepala->next;  
    while (bantu != kepala) {
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
    cout << endl;
}

// hapus pasien paling parah
void hapusPasien() {
    if (cekListKosong()) {
        cout << "Tidak ada pasien untuk dihapus.\n";
        return;
    }

    // cari prioritas tertinggi
    int prioritas = 0;
    Pasien* bantu = kepala->next;
    while (bantu != kepala) {
        if (bantu->kondisi > prioritas) {
            prioritas = bantu->kondisi;
        }
        bantu = bantu->next;
    }

    // cari node sek mau dihapus
    Pasien* prev = kepala;
    bantu = kepala->next;
    while (bantu != kepala) {
        if (bantu->kondisi == prioritas) {
            prev->next = bantu->next; // putus node
            cout << "-----------------------------\n";
            cout << "       Pasien atas nama\n";
            cout << "-----------------------------\n";
            cout << "Nama      | " << bantu->nama << "\n";
            cout << "Prioritas | " << getKondisi(bantu->kondisi) << "\n";
            cout << "-----------------------------\n";
            cout << "Pasien telah dihapus karena selesai pengobatan\n\n";
            delete bantu; //hapus memo
            kepala->umur -= 1;
            return;
        }
        prev = bantu;
        bantu = bantu->next;
    }
}

// menu utamaaa
int main() {
    buatListBaru();
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
        cout << "==================\n\n";

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
    delete kepala; // hapus node dummy
    return 0;
}
