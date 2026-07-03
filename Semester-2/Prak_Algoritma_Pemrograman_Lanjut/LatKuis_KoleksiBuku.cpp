#include <iostream>
//#include <string>
#include <cstdlib> // cls
#include <cctype> // isalpha
using namespace std;

#define USERNAME "alifah"
#define PASSWORD "234"
const int MAX_BUKU = 100; // batas max transaksi

struct Buku { // simpan dlm struct
    int id;
    string judul;
    string penulis; 
    int tahunterbit;
};

Buku koleksi[MAX_BUKU];//simpan buku
int jumlahBuku = 0;//simpan jlm buku

void hilang() {
    system("cls");
}

bool hanyaHuruf(const string& str) {
    for (char c : str) {
        if (!isalpha(c) && c != ' ') return false;
    }
    return true;
}

// Login dengan rekursi
bool login(int percobaan = 3) { //batas percobaan
    if (percobaan == 0) { //percobaan batas max
        cout << "Percobaan mencapai batas. Program berakhir.\n";
        return false;
    }
    string username, password;
    cout << "Masukkan Username: ";
    cin >> username;
    cout << "Masukkan Password: ";
    cin >> password;
    
    if (username == USERNAME && password == PASSWORD) { // login berhasil
        hilang();
        cout << "Selamat Datang :) \n";
        return true;
    } else {
        cout << "! Login gagal, Sisa percobaan " << percobaan - 1 << " kali !\n"; 
        return login (percobaan - 1); //login gagal dan percobaan berkurang
    }
}

void tambahBuku() {
    int n;
    cout << "Masukkan jumlah buku yang ingin ditambahkan: ";
    cin >> n;

    while (cin.fail() || n <= 0 || jumlahBuku + n > MAX_BUKU) {
        hilang();
        cout << "Input melebihi kapasitas. Masukkan ulang: ";
        cin >> n;
    }

    for (int i = 0; i < n; ++i) {
        Buku b;
        cout << "\n--- Buku ke-" << (i + 1) << " ---\n";

        cout << "ID Buku: ";
        cin >> b.id;
        while (cin.fail()) {
            //hilang();
            cout << "ID Buku harus berupa angka!\n";
            cout << "ID Buku: ";
            cin >> b.id;
        }

        bool duplikat = false;
        for (int j = 0; j < jumlahBuku; ++j) {
            if (koleksi[j].id == b.id) {
                duplikat = true;
                break;
            }
        }
        if (duplikat) {
            cout << "ID sudah digunakan. Buku tidak ditambahkan.\n";
            continue;
        }
 
        cout << "Judul Buku: ";
        cin >> b.judul;

        do {
            cout << "Penulis: ";
            cin >> b.penulis;
            if (!hanyaHuruf(b.penulis)) {
                cout << "Nama penulis hanya boleh huruf dan spasi.\n";
            }
        } while (!hanyaHuruf(b.penulis));

        cout << "Tahun Terbit: ";
        cin >> b.tahunterbit;
        while (cin.fail()) {
          
            cout << "Tahun terbit harus angka!\n";
            cout << "Tahun Terbit: ";
            cin >> b.tahunterbit;
        }

        koleksi[jumlahBuku++] = b;
        cout << "Buku berhasil ditambahkan.\n";
        cout << endl;
    }
}

void tampilkanBuku(int index = 0) {
    if (jumlahBuku == 0) {
        cout << "Tidak ada buku dalam koleksi.\n";
        cout << endl;
        return;
    }
    if (index < jumlahBuku) {
        cout << " --- Buku ke-" << (index + 1) << " ---\n";
        cout << "ID: " << koleksi[index].id << "\n";
        cout << "Judul: " << koleksi[index].judul << "\n";
        cout << "Penulis: " << koleksi[index].penulis << "\n";
        cout << "Tahun Terbit: " << koleksi[index].tahunterbit << "\n";
        cout << "-------------------\n";
        cout << endl;
        tampilkanBuku(index + 1);
    }
}
 
void cariBuku() {
    if (jumlahBuku == 0) {
        cout << "Koleksi kosong. Tidak dapat mencari.\n";
        return;
    }

    cout << "\nDaftar Buku Saat Ini:\n";
    tampilkanBuku();

    string judulCari;
    cout << "Masukkan judul buku yang ingin dicari: ";
    cin >> judulCari;

    bool ditemukan = false;
    for (int i = 0; i < jumlahBuku; ++i) {
        if (koleksi[i].judul == judulCari) {
            cout << "\nBuku Ditemukan:\n";
            cout << "ID: " << koleksi[i].id << "\n";
            cout << "Judul: " << koleksi[i].judul << "\n";
            cout << "Penulis: " << koleksi[i].penulis << "\n";
            cout << "Tahun Terbit: " << koleksi[i].tahunterbit << "\n";
            ditemukan = true;
            cout << endl;
            break;
        }
    }  

    if (!ditemukan) {
        cout << "Buku dengan judul \"" << judulCari << "\" tidak ditemukan.\n";
    }
}

void hapusBuku() {
    if (jumlahBuku == 0) {
        cout << "Koleksi kosong. Tidak ada buku yang bisa dihapus.\n";
        return;
    }

    int idHapus;
    cout << "Masukkan ID buku yang ingin dihapus: ";
    cin >> idHapus;

    while (cin.fail()) {
       
        cout << "ID tidak valid! Masukkan ulang: ";
        cin >> idHapus;
    }

    int indeks = -1;
    for (int i = 0; i < jumlahBuku; ++i) {
        if (koleksi[i].id == idHapus) {
            indeks = i;
            break;
        }
    }

    if (indeks == -1) {
        cout << "Buku dengan ID " << idHapus << " tidak ditemukan.\n";
        return;
    }

    for (int i = indeks; i < jumlahBuku - 1; ++i) {
        koleksi[i] = koleksi[i + 1];
    }

    jumlahBuku--;
    cout << "Buku berhasil dihapus.\n";
}

//fungsi menu utama
int main() {
    if (!login()) {
        return 0;
    }
    int pilihan;
    do {
       
        cout << "=== SISTEM MANAJEMEN PERPUSTAKAAN ===\n";
        cout << "1. Tambah Buku\n";
        cout << "2. Tampilkan Daftar Buku\n";
        cout << "3. Cari Buku (berdasarkan Judul)\n";
        cout << "4. Hapus Buku (berdasarkan ID)\n";
        cout << "5. Keluar\n";
        cout << "Pilih menu (1-5): ";
        cin >> pilihan;
        cout << endl;

        switch (pilihan) {
            case 1:
                tambahBuku();
                break;
            case 2:
                tampilkanBuku();
                break;
            case 3:
                cariBuku();
                break;
            case 4:
                hapusBuku();
                break;
            case 5:
                cout << "Terima kasih telah menggunakan sistem.\n";
                break;
            default:
                cout << "Pilihan tidak valid!\n";
        }
     
    } while (pilihan != 5);
    return 0;
}
