#include <iostream>
#include <iomanip> // setw
#include <string> //manupulasi string
#include <cctype> // isalpha, isdigit, toupper, tolower
#include <limits> //bersihkan buffer input
using namespace std;

// Struktur simpan data penduduk
struct Penduduk {
    string nama, alamat, agama, goldar, status;
    int tahunLahir, tahunPengisian, umur;
    char rhesus;
};

// deklar variable
const int MAX_PENDUDUK = 5; //max jlm yg disimpan
Penduduk dataPenduduk[MAX_PENDUDUK]; //array data penduduk
int jumlahPenduduk = 0; //simpan jlm input

// Fungsi validasi nama pastikan huruf, spasi, tanda hubung
bool validasinama(const string & nama) {
    for (char n : nama) {
        if (!isalpha(n) && n != ' ' && n != '-') return false; 
    }
    return !nama.empty(); //kembalikan benar salah
}

// Fungsi validasi (th lahir dan pengisian)
bool validasiangka(const string& angka) {
    for (char a : angka) {
        if (!isdigit(a)) return false;
    }
    return !angka.empty();
}

// Fungsi validasi goldar
bool validasigoldar(const string& gol) {
    return gol == "A" || gol == "B" || gol == "AB" || gol == "O";
}

// Fungsi validasi rhesus darah
bool validasirhesus(char rh) {
    return rh == '+' || rh == '-';
}

// Fungsi tambah data penduduk
void tambahpenduduk() {
    if (jumlahPenduduk >= MAX_PENDUDUK) {
        cout << "Data penduduk sudah penuh!" << endl;
        return;
    }
// pembatasan data penduduk baru
    string input;
    Penduduk p;

    cin.ignore(); // Bersihkan buffer sebelum input string

    //input nama dan alamat
    do {
        cout << left << setw(17) << "Masukkan Nama                     : ";
        getline(cin, p.nama);
    } while (!validasinama(p.nama));

    cout << left << setw(17) << "Masukkan Alamat                   : ";
    getline(cin, p.alamat);

    //input data dan perhitungan umur
    do {
        cout << left << setw(17) << "Masukkan Tahun Lahir              : ";
        cin >> input;
    } while (!validasiangka(input));
    p.tahunLahir = stoi(input);

    do {
        cout << left << setw(17) << "Masukkan Tahun Pengisian Data     : ";
        cin >> input;
    } while (!validasiangka(input));
    p.tahunPengisian = stoi(input);

    p.umur = p.tahunPengisian - p.tahunLahir; //rumus umur

    cin.ignore(); // Bersihkan buffer sebelum input string

   //input data agama bisa besar kecil huruf
   do {
    cout << left << setw(17) << "Masukkan Agama                    : ";
    getline(cin, p.agama);

    // Konversi huruf pertama menjadi kapital, sisanya kecil
    if (!p.agama.empty()) {
        p.agama[0] = toupper(p.agama[0]);
        for (size_t i = 1; i < p.agama.length(); i++) {
            p.agama[i] = tolower(p.agama[i]);
        }
    }
} while (p.agama != "Islam" && p.agama != "Kristen" && p.agama != "Katolik" && 
         p.agama != "Hindu" && p.agama != "Buddha" && p.agama != "Konghucu");

    //input golddar bisa besar kecil huruf
    do {
        cout << left << setw(17) << "Masukkan Golongan Darah (A/B/AB/O): ";
        cin >> p.goldar;

        // Konversi ke huruf besar
        for (char & b : p.goldar) {
            b = toupper(b);
        }
    } while (!validasigoldar(p.goldar));

    //input rhesus darah
    do {
        cout << left << setw(17) << "Masukkan Rhesus Darah (+ atau -)  : ";
        cin >> p.rhesus;
    } while (!validasirhesus(p.rhesus));

    //input status menikah
    do {
        cout << left << setw(17) << "Masukkan Status Menikah (ya/tidak): ";
        cin >> p.status;

        // Konversi ke huruf kecil
        for (char & k : p.status) {
            k = tolower(k);
        }
    } while (p.status != "ya" && p.status != "tidak");

    // data tersimpan
    dataPenduduk[jumlahPenduduk++] = p;
    cout << "Data penduduk berhasil ditambahkan!\n";
    cout << endl;
}

// Fungsi tampilkan all data penduduk
void tampilkandata() {
    if (jumlahPenduduk == 0) { //notif jika blm pernah input data
        cout << "Tidak ada data penduduk.\n";
        return;
    }
    cout << "------------------------------\n";
    cout << "    DAFTAR DATA PENDUDUK\n";
    cout << "------------------------------\n";
    for (int i = 0; i < jumlahPenduduk; i++) {
        cout << "Penduduk ke-" << i + 1 << "\n";
        cout << left << setw(17) << "Nama" << ": " << dataPenduduk[i].nama << endl;
        cout << left << setw(17) << "Alamat" << ": " << dataPenduduk[i].alamat << endl;
        cout << left << setw(17) << "Umur" << ": " << dataPenduduk[i].umur << " tahun" << endl;
        cout << left << setw(17) << "Agama" << ": " << dataPenduduk[i].agama << endl;
        cout << left << setw(17) << "Golongan Darah" << ": " << dataPenduduk[i].goldar << dataPenduduk[i].rhesus << endl;
        cout << left << setw(17) << "Status" << ": " << (dataPenduduk[i].status == "ya" ? "Menikah" : "Belum Menikah") << endl;
        cout << "------------------------------\n";
    }
}

// Fungsi cari penduduk dgn nama 
void caripenduduk() {
    string kataKunci;
    cout << "Masukkan nama yang dicari: ";
    cin.ignore();
    getline(cin, kataKunci);
    bool ditemukan = false;
    for (int i = 0; i < jumlahPenduduk; i++) {
        if (dataPenduduk[i].nama.find(kataKunci) != string::npos) {//cek apakah ada
            cout << left << setw(17) << "Nama" << ": " << dataPenduduk[i].nama << endl;
            cout << left << setw(17) << "Alamat" << ": " << dataPenduduk[i].alamat << endl;
            cout << left << setw(17) << "Umur" << ": " << dataPenduduk[i].umur << " tahun" << endl;
            cout << left << setw(17) << "Agama" << ": " << dataPenduduk[i].agama << endl;
            cout << left << setw(17) << "Golongan Darah" << ": " << dataPenduduk[i].goldar << dataPenduduk[i].rhesus << endl;
            cout << left << setw(17) << "Status" << ": " << (dataPenduduk[i].status == "ya" ? "Menikah" : "Belum Menikah") << endl;
            cout << "------------------------------\n";
            ditemukan = true;
        }
    }
    //notif saat data tdk ditemukan
    if (!ditemukan) {
        cout << "Data tidak ditemukan.\n";
    }
}

// Fungsi untuk menghapus data penduduk berdasarkan nama
void hapuspenduduk() {
    string namaHapus;
    cout << "Masukkan nama penduduk yang ingin dihapus: ";
    cin.ignore();
    getline(cin, namaHapus);

    bool ditemukan = false;
    for (int i = 0; i < jumlahPenduduk; i++) {
        if (dataPenduduk[i].nama == namaHapus) {
            //saat data dihapus, inputan data terakhir mengisi ruang yg dihapus sebelum e
            dataPenduduk[i] = dataPenduduk[jumlahPenduduk - 1];
            jumlahPenduduk--;  // Kurangi jumlah penduduk
            ditemukan = true;
            cout << "Data penduduk dengan nama " << namaHapus << " berhasil dihapus.\n";
            break;
        }
    }

    //data tidak ditemukan
    if (!ditemukan) {
        cout << "Penduduk dengan nama " << namaHapus << " tidak ditemukan.\n";
    }
}

int main() {
    int pilihan;
    do {
        cout << "==============================\n";
        cout << "             MENU             \n";
        cout << "==============================\n";
        cout << "1. Tambah Data Penduduk\n";
        cout << "2. Tampilkan Data Penduduk\n";
        cout << "3. Cari Data Penduduk\n";
        cout << "4. Hapus Data Penduduk\n";  
        cout << "5. Keluar\n";
        cout << "------------------------------\n";
        cout << "Pilih Menu: ";
        cin >> pilihan;
        cout << "------------------------------\n";

        switch (pilihan) {
            case 1: tambahpenduduk(); break;
            case 2: tampilkandata(); break;
            case 3: caripenduduk(); break;
            case 4: hapuspenduduk();break; 
            case 5: cout << "Keluar dari program.\n"; break;
            default: cout << "Pilihan tidak valid!\n"; //opsi tidak ada
        }
    } while (pilihan != 5);

    return 0;
}