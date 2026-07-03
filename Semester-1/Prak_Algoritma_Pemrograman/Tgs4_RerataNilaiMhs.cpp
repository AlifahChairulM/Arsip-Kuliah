#include <iostream>
#include <string>
#include <limits> // Untuk validasi input

using namespace std;

const int MAX_MHS = 100; // Batas atas data mahasiswa
const int MAX_MATKUL = 4; // Batas atas data mata kuliah

// Simpan data mahasiswa
struct Mahasiswa {
    string nama;
    double nilai[MAX_MATKUL];
    double rerata;
};

Mahasiswa mahasiswa[MAX_MHS];
int jmlmhs = 0;

// Fungsi input nilai mahasiswa
void inputNilai() {
    if (jmlmhs >= MAX_MHS) {
        cout << "Batas MAX input data mahasiswa" << endl;
        return;
    }

    // Membersihkan sisa buffer
    cin.ignore();
    cout << "Masukkan nama: ";
    getline(cin, mahasiswa[jmlmhs].nama);

    // Masukkan nama dan nilai
    cout << "Masukkan nilai mahasiswa" << endl;
    cout << "!! Catatan: titik untuk nilai tidak bulat !!" << endl;
    for (int i = 0; i < MAX_MATKUL; ++i) {
        while (true) {
            cout << "Nilai mata kuliah ke-" << (i + 1) << ": ";
            cin >> mahasiswa[jmlmhs].nilai[i];
            if (cin.fail() || mahasiswa[jmlmhs].nilai[i] < 0 || mahasiswa[jmlmhs].nilai[i] > 100) {
                cout << "Nilai harus antara 0 dan 100. Silakan coba lagi." << endl;
                cin.clear(); // Menghapus kesalahan input
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Mengabaikan input yang salah
            } else {
                break;
            }
        }
    }

    // Hitung rerata nilai
    double totalnilai = 0;
    for (int i = 0; i < MAX_MATKUL; ++i) {
        totalnilai += mahasiswa[jmlmhs].nilai[i];
    }
    mahasiswa[jmlmhs].rerata = totalnilai / MAX_MATKUL;
    jmlmhs++;
}

// Fungsi melihat nilai mahasiswa
void lihatnilai() {
    if (jmlmhs == 0) {
        cout << "Data mahasiswa tidak ditemukan" << endl;
        return;
    }
    cout << "Daftar nilai mahasiswa:" << endl;
    for (int i = 0; i < jmlmhs; ++i) {
        cout << "Nama: " << mahasiswa[i].nama << endl;
        for (int j = 0; j < MAX_MATKUL; ++j) {
            cout << "Nilai mata kuliah ke-" << (j + 1) << ": " << mahasiswa[i].nilai[j] << endl;
        }
        cout << endl;
    }
}

// Fungsi melihat rata-rata nilai mahasiswa
void reratanilai() {
    if (jmlmhs == 0) {
        cout << "Data mahasiswa tidak ditemukan" << endl;
        return;
    }
    cout << "Rerata nilai mahasiswa:" << endl;
    for (int i = 0; i < jmlmhs; ++i) {
        cout << "Nama: " << mahasiswa[i].nama << " rata-rata: " << mahasiswa[i].rerata << endl;
    }
}

// Fungsi melihat mahasiswa dengan rata-rata tertinggi
void reratatertinggi() {
    if (jmlmhs == 0) {
        cout << "Data mahasiswa tidak ditemukan" << endl;
        return;
    }
    int indeksTertinggi = 0;
    for (int i = 1; i < jmlmhs; ++i) {
        if (mahasiswa[i].rerata > mahasiswa[indeksTertinggi].rerata) {
            indeksTertinggi = i;
        }
    }
    cout << "Rerata mahasiswa tertinggi:" << endl;
    cout << "Nama: " << mahasiswa[indeksTertinggi].nama << " rata-rata: " << mahasiswa[indeksTertinggi].rerata << endl;
}

// Fungsi melihat mahasiswa dengan rata-rata terendah
void rerataterendah() {
    if (jmlmhs == 0) {
        cout << "Data mahasiswa tidak ditemukan" << endl;
        return;
    }
    int indeksTerendah = 0;
    for (int i = 1; i < jmlmhs; ++i) {
        if (mahasiswa[i].rerata < mahasiswa[indeksTerendah].rerata) {
            indeksTerendah = i;
        }
    }
    cout << "Rerata mahasiswa terendah:" << endl;
    cout << "Nama: " << mahasiswa[indeksTerendah].nama << " rata-rata: " << mahasiswa[indeksTerendah].rerata << endl;
}

// Tampilan menu
void MENU() {
    cout << "=================================\n";
    cout << "| Nilai Mahasiswa |\n";
    cout << "=================================\n";
    cout << " 1. Input nilai\n";
    cout << " 2. Seluruh nilai\n";
    cout << " 3. Rata-rata nilai\n";
    cout << " 4. Rata-rata nilai tertinggi\n";
    cout << " 5. Rata-rata nilai terendah\n";
    cout << " 0. Keluar\n";
    cout << "=================================\n";
    cout << "Pilih menu: ";
}

// Fungsi utama
int main() {
    int pilihan;
    do {
        MENU();
        cin >> pilihan;
        switch (pilihan) {
            case 1:
                inputNilai();
                break;
            case 2:
                lihatnilai();
                break;
            case 3:
                reratanilai();
                break;
            case 4:
                reratatertinggi();
                break;
            case 5:
                rerataterendah();
                break;
            case 0:
                cout << "Keluar dari program\n";
                break;
            default:
                cout << "Pilihan menu tidak valid\n";
                break;
        }
        if (pilihan != 0) {
            cout << "Kembali ke menu utama? (Y/N): ";
            char kembali;
            cin >> kembali;
            if (kembali == 'N' || kembali == 'n') {
                cout << "Keluar dari program";
                break;
            }
            cout << endl;
        }
    } while (pilihan != 0);
    return 0;
}
