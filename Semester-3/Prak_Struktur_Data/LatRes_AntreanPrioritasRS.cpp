//123240234_Alifah Chairul Munawar
#include <iostream>
#include <string>
using namespace std;

struct DataPasien {
    string nama;
    string keluhan;
    string prioritas; 
    DataPasien* next;
    DataPasien* prev;
};

// inisialisasi
DataPasien* depan = NULL;
DataPasien* belakang = NULL;   

struct NodeRiwayat {
    string nama;
    string keluhan;
    string prioritas;
    NodeRiwayat* next;
};

// inisialisasi
NodeRiwayat* top = NULL;

bool antrianKosong() {
    return depan == NULL;
}

void enqueueDepan(string nama, string keluhan, string prioritas) {
    DataPasien* newNode = new DataPasien();
    newNode->nama = nama;
    newNode->keluhan = keluhan;
    newNode->prioritas = prioritas;
    newNode->prev = NULL;
    newNode->next = depan;

    if (antrianKosong()) {
        depan = newNode;
        belakang = newNode;
    }
    else {
        depan->prev = newNode;
        depan = newNode;
    }
    cout << "Pasien " << nama << " (" << prioritas << ") masuk ke depan antrian.\n";
}

void enqueueBelakang(string nama, string keluhan, string prioritas) {
    DataPasien* newNode = new DataPasien();
    newNode->nama = nama;
    newNode->keluhan = keluhan;
    newNode->prioritas = prioritas;
    newNode->next = NULL;
    newNode->prev = belakang;

    if (antrianKosong()) {
        depan = newNode;
        belakang = newNode;
    }
    else {
        belakang->next = newNode;
        belakang = newNode;
    }
    cout << "Pasien " << nama << " (" << prioritas << ") masuk ke belakang antrian.\n";
}

DataPasien* dequeueDepan() {
    if (antrianKosong()) {
        cout << "Antrian kosong\n";
        return NULL;
    }
    
    DataPasien* temp = depan;
    cout << "Pasien " << depan->nama << " keluar dari antrian.\n";
    depan = depan->next;

    if (depan == NULL) { // no antrian lagi
        belakang = NULL;
    }
    else { // masih ada
        depan->prev = NULL;
    }
    return temp;
}

//Riwayat geng
bool riwayatKosong() {
    return top == NULL;
}

void pushRiwayat(DataPasien* pasien) {
    NodeRiwayat* newNode = new NodeRiwayat();
    newNode->nama = pasien->nama;
    newNode->keluhan = pasien->keluhan;
    newNode->prioritas = pasien->prioritas;
    newNode->next = top;
    top = newNode;
}

//  MENU UTAMA
void tambahPasien() {
    cout << "\n--- TAMBAH PASIEN BARU ---\n";
    string nama, keluhan, prioritas;
    cout << "Nama pasien: ";
    cin >> nama;
    cout << "Keluhan: ";
    cin >> keluhan;
    while (true) {
        cout << "Prioritas (Biasa/Darurat): ";
        cin >> prioritas;

        // Konversi ke format kapital
        if (prioritas == "biasa" || prioritas == "BIASA" || prioritas == "Biasa") {
            prioritas = "Biasa";
            break;
        }
        else if (prioritas == "darurat" || prioritas == "DARURAT" || prioritas == "Darurat") {
            prioritas = "Darurat";
            break;
        }
        else {
            cout << "Prioritas harus 'Biasa' atau 'Darurat'\n";
        }       
    }

    //enqueuePasien
    if (prioritas == "Darurat") {
        enqueueDepan(nama, keluhan, prioritas);
    }
    else {
        enqueueBelakang(nama, keluhan, prioritas);
    }
}

void layaniPasien() {
    cout << "\n--- MELAYANI PASIEN ---\n";

    //dequeuePasien
    if (antrianKosong()) {
        cout << "Tidak ada pasien untuk dilayani\n";
        return;
    }
    DataPasien* pasienDilayani = dequeueDepan();
    if (pasienDilayani != NULL) {
        pushRiwayat(pasienDilayani);
        cout << "Data pasien " << pasienDilayani->nama << " telah disimpan ke riwayat\n";
        delete pasienDilayani; 
    }
}

void tampilkanAntrian() {
    if (antrianKosong()) {
        cout << "Antrian kosong\n";
        return;
    }
    cout << "\n=== DAFTAR ANTRIAN PASIEN ===\n";
    DataPasien* temp = depan;
    int nomor = 1;
    
    while (temp != NULL) {
        cout << nomor << ". " << temp->nama << " - " << temp->keluhan 
             << " [" << temp->prioritas << "]\n";
        temp = temp->next;
        nomor++;
    }
    cout << endl;
}

void tampilkanRiwayat() {
    if (riwayatKosong()) {
        cout << "Riwayat pelayanan kosong\n";
        return;
    }
    cout << "\n=== RIWAYAT PELAYANAN PASIEN ===\n";
    NodeRiwayat* temp = top;
    int nomor = 1;
    
    while (temp != NULL) {
        cout << nomor << ". " << temp->nama << " - " << temp->keluhan 
             << " [" << temp->prioritas << "]\n";
        temp = temp->next;
        nomor++;
    }
    cout << endl;
}

int main() {
    int pilihan;
    do {
        cout << "\n==================================";
        cout << "\n    SISTEM ANTRIAN KLINIK DESA    ";
        cout << "\n==================================\n";
        cout << "1. Tambah Pasien Baru\n";
        cout << "2. Layani Pasien\n";
        cout << "3. Tampilkan Antrian\n";
        cout << "4. Tampilkan Riwayat\n";
        cout << "5. Keluar\n";
        cout << "==================================\n";
        cout << "Pilih menu (1-5): ";
        cin >> pilihan;

        switch (pilihan) {
            case 1: tambahPasien(); break;
            case 2: layaniPasien(); break;
            case 3: tampilkanAntrian(); break;    
            case 4: tampilkanRiwayat(); break;
            case 5: 
            cout << "Terima kasih telah menggunakan sistem Klinik Desa\n";
                break;
            default:
                cout << "Pilihan tidak valid, silakan pilih 1-5\n";
                break;
        }
    } while (pilihan != 5);
    
     //berish memo
     while (!antrianKosong()) {
        DataPasien* temp = dequeueDepan();
        delete temp;
    }
    while (!riwayatKosong()) {
        NodeRiwayat* temp = top;
        top = top->next;
        delete temp;
    }
    return 0;
}