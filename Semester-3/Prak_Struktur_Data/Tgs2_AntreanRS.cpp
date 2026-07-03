//Tuliskan deskripsi tugas dalam bentuk paragraf yang dibuat secara singkat dan deskriptif 
//123240234//
#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;

struct DataPasien {
    string nama;
    int idPasien;
    DataPasien* next;
};

struct Antrian {
    DataPasien* front;
    DataPasien* rear;
    int jumlah;
    int idAntrian;
};

struct Riwayat {
    DataPasien* atas;
    int jumlah;
};

Antrian* buatAntrian() {
    Antrian* antrianNew = new Antrian();
    antrianNew->front = antrianNew->rear = nullptr;
    antrianNew->jumlah = 0;
    antrianNew->idAntrian = 1;
    return antrianNew;
}

Riwayat* buatRiwayat() {
    Riwayat* riwayatNew = new Riwayat();
    riwayatNew->atas = nullptr;
    riwayatNew->jumlah = 0;
    return riwayatNew;
}

void tambahPasien(Antrian* antrianNew) {
    string namaPasien;
    cout << "Masukkan nama pasien: ";
    cin >> namaPasien;
    DataPasien* pasienNew = new DataPasien();
    pasienNew->nama = namaPasien;
    pasienNew->idPasien = antrianNew->idAntrian++; 
    pasienNew->next = nullptr;
   
    if (antrianNew->rear == nullptr) {
        antrianNew->front = antrianNew->rear = pasienNew;
    } else {
        antrianNew->rear->next = pasienNew;
        antrianNew->rear = pasienNew;
    }
    antrianNew->jumlah++;
    cout << "Pasien \"" << namaPasien << "\", ID: " << pasienNew->idPasien << " masuk ke antrian." << endl;
}

void layaniPasien(Antrian* antrianNew, Riwayat* riwayatNew) {
    if (antrianNew->front == nullptr){
        cout << "Tidak ada pasien dalam antrian." << endl;
    } else {
        DataPasien* pasienDilayani = antrianNew->front; 
        antrianNew->front = antrianNew->front->next;
        if (antrianNew->front == nullptr) {
            antrianNew->rear = nullptr;
        }
        antrianNew->jumlah--;
        cout << "Pasien dengan nama \"" << pasienDilayani->nama 
             << "\", ID: " << pasienDilayani->idPasien << " telah dilayani." << endl;
        
        pasienDilayani->next = riwayatNew->atas;
        riwayatNew->atas = pasienDilayani;
        riwayatNew->jumlah++;
    }
}

void lihatAntrian(Antrian* antrianNew) {
    if (antrianNew->front == nullptr) { 
        cout << "Antrian kosong." << endl;
        return;
    }
    cout << "Daftar Antrian Pasien:" << endl;
    DataPasien* pasienSekarang = antrianNew->front;
    while (pasienSekarang != nullptr) {
        cout << "ID: " << pasienSekarang->idPasien << " | Nama: " << pasienSekarang->nama << endl;
        pasienSekarang = pasienSekarang->next;
    }
}

void lihatRiwayat(Riwayat* riwayatNew) {
    if (riwayatNew->atas == nullptr) {
        cout << "Riwayat pasien kosong." << endl;
        return;
    }
    cout << "Riwayat Pasien yang sudah Dilayani:" << endl;
    DataPasien* pasienSekarang = riwayatNew->atas;
    while (pasienSekarang != nullptr) {
        cout << "ID: " << pasienSekarang->idPasien << " | Nama: " << pasienSekarang->nama << endl;
        pasienSekarang = pasienSekarang->next;
    }
}

void hapusRiwayat(Riwayat* riwayatNew) {
    if (riwayatNew->atas == nullptr) {
        cout << "Tidak ada data riwayat untuk dihapus." << endl;
    } else {
        DataPasien* pasienDihapus = riwayatNew->atas;
        riwayatNew->atas = riwayatNew->atas->next;
        riwayatNew->jumlah--;
        cout << "Pasien dengan nama \"" << pasienDihapus->nama 
             << "\" dan ID " << pasienDihapus->idPasien 
             << " telah dihapus permanent dari riwayat." << endl;
        delete pasienDihapus;
    }
}

void keluar(Antrian* antrianNew, Riwayat* riwayatNew) {
    cout << "Terima kasih telah menggunakan sistem antrean rumah sakit." << endl;
    while (antrianNew->front != nullptr) {
        DataPasien* temp = antrianNew->front;
        antrianNew->front = antrianNew->front->next;
        delete temp;
    }
    antrianNew->rear = nullptr;
    antrianNew->jumlah = 0;
    
    while (riwayatNew->atas != nullptr) {
        DataPasien* temp = riwayatNew->atas;
        riwayatNew->atas = riwayatNew->atas->next;
        delete temp;
    }
    riwayatNew->jumlah = 0;
    
    delete antrianNew;
    delete riwayatNew;
}

int main() {
    Antrian* antrianNew = buatAntrian();
    Riwayat* riwayatNew = buatRiwayat();
    int pilihan;
    
    do {
        cout << "\n==========================================" << endl;
        cout << "|          SISTEM ANTREAN PASIEN         |" << endl;
        cout << "|          RUMAH SAKIT JAYAMAHE          |" << endl;
        cout << "==========================================" << endl;
        cout << "|  " << left << setw(38) << "1. Tambah Pasien ke Antrian" << "|" << endl;
        cout << "|  " << left << setw(38) << "2. Layani Pasien (Pindah ke Riwayat)" << "|" << endl;
        cout << "|  " << left << setw(38) << "3. Lihat Antrian Pasien" << "|" << endl;
        cout << "|  " << left << setw(38) << "4. Lihat Riwayat Pasien" << "|" << endl;
        cout << "|  " << left << setw(38) << "5. Hapus Data Riwayat Terakhir" << "|" << endl;
        cout << "|  " << left << setw(38) << "6. Keluar" << "|" << endl;
        cout << "==========================================" << endl;
        cout << "Pilih menu [1-6]: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1: tambahPasien(antrianNew); break;
            case 2: layaniPasien(antrianNew, riwayatNew); break;
            case 3: lihatAntrian(antrianNew); break;
            case 4: lihatRiwayat(riwayatNew); break;
            case 5: hapusRiwayat(riwayatNew); break;
            case 6: keluar(antrianNew, riwayatNew); break;
            default: 
                cout << "Pilihan tidak valid. Silakan pilih menu 1-6." << endl; 
                break;
        }
    } while (pilihan != 6);
    return 0;
}