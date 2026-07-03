#include <iostream> //output input
#include <iomanip>// tabel 
#include <cctype>   // isalpha isdigit
#include <limits> // For std::numeric_limits
using namespace std;

// Struktur data
struct Mahasiswa {
    string nim, nama, angkatan, jurusan;
    float tugas, uts, uas, rerata;
};

// Array simpan data mahasiswa 
Mahasiswa daftar_mhs[45]; //max 45mhs
int jumlah_mhs = 0; 

// Fungsi validasi huruf dan spasi ( Nama Jurusan)
bool hanyaHuruf(const string & str) {
    if (str.empty()) return false; // Cegah input kosong
    for (char c : str) {
        if (!isalpha(c) && c != ' ') return false;// klo salah balek 
    }
    return true;
}

// Fungsi validasi hanya angka (nim angkatan, tugas, uts, uas)
bool hanyaAngka(const string & str) {
    if (str.empty()) return false;
    for (char c : str) {
        if (!isdigit(c)) return false;
    }
    return true;
}

// input Nama Jurusan 
string inputHuruf(const string & label) {
    string input;
    do {
        cout << label << ": ";
        getline(cin, input);
        if (!hanyaHuruf(input)) {cout << "Hanya Huruf!\n";}
    } while (!hanyaHuruf(input));
    return input;
}

// input NIM Angkatan  Tgs UTS UAS
string inputAngka(const string & label) {
    string input;
    do {
        cout << label << ": ";
        cin >> input;
        if (!hanyaAngka(input)) {cout << "Hanya Angka!\n";}
    } while (!hanyaAngka(input));
    cin.ignore(); // Hindari buffer
    return input;
}

//input rentang nilai
float inputNilai(const string & label) {
    float nilai;
    while (true) {
        cout << label << ": ";
        cin >> nilai;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
            cout << "Hanya Angka!\n";
            continue; //tampikan ulang
        } 

        if (nilai < 0 || nilai > 100) {
            cout << "Nilai harus antara 0 - 100!\n";
            continue;
            
        }else{}
        return nilai;
        }
    }

// Hitung nilai rata-rata
void hitung_rata_rata(Mahasiswa & mhs) {
    mhs.rerata = (mhs.tugas * 0.25) + (mhs.uts * 0.35) + (mhs.uas * 0.40); //bobot per penilaian
}

// Tambah data mahasiswa
void tambah_mahasiswa() {
    int jumlah, lebar_label = 15;// agar rapi
    cout << "Jumlah mahasiswa yang ingin ditambahkan: ";
    cin >> jumlah;
    cin.ignore();
    
    for (int i = 0; i < jumlah; i++) {
        cout << "\nData Mahasiswa ke-" << (jumlah_mhs + 1) << ":\n";
        Mahasiswa & mhs = daftar_mhs[jumlah_mhs];

        mhs.nim = inputAngka("NIM");
        mhs.nama = inputHuruf("Nama");
        mhs.angkatan = inputAngka("Angkatan");
        mhs.jurusan = inputHuruf("Jurusan");
        mhs.tugas = inputNilai("Nilai Tugas");
        mhs.uts = inputNilai("Nilai UTS");
        mhs.uas = inputNilai("Nilai UAS");
        
        hitung_rata_rata(mhs); //pake array 
        jumlah_mhs++;
    }
    cout << "\nData mahasiswa berhasil ditambahkan!\n\n";
}

// Tmpilkan daftar mahasiswa
void lihat_mahasiswa() {
    if (jumlah_mhs == 0) {
        cout << "\nBelum ada data mahasiswa.\n";
        return;
    }
    int nim = 4, nama = 10, jurusan = 8, angkatan = 9;
    int tugas = 6, uts = 6, uas = 6, rata = 10;
    cout << "                                 Data Mahasiswa                                 ";
    cout << "\n============================================================================\n";
    cout << "| " << left << setw(nim) << "NIM" 
         << "| " << setw(nama) << "Nama" 
         << "| " << setw(jurusan) << "Jurusan" 
         << "| " << setw(angkatan) << "Angkatan" 
         << "| " << setw(tugas) << "Tugas"
         << "| " << setw(uts) << "UTS"
         << "| " << setw(uas) << "UAS"
         << "| " << setw(rata) << "Rata-rata"
         << "|\n";
    cout << "============================================================================\n";

    for (int i = 0; i < jumlah_mhs; i++) {
        cout << "| " << left << setw(nim) << daftar_mhs[i].nim
             << "| " << setw(nama) << daftar_mhs[i].nama
             << "| " << setw(jurusan) << daftar_mhs[i].jurusan
             << "| " << setw(angkatan) << daftar_mhs[i].angkatan
             << "| " << setw(tugas) << daftar_mhs[i].tugas
             << "| " << setw(uts) << daftar_mhs[i].uts
             << "| " << setw(uas) << daftar_mhs[i].uas
             << "| " << fixed << setprecision(2) << setw(rata) << daftar_mhs[i].rerata
             << "|\n";
    }
    cout << "============================================================================\n";
}

// Cari mahasiswa dgn NIM dgn jenis linear search
void cari_mahasiswa() {
    string nim_cari;
    cout << "Masukkan NIM mahasiswa yang dicari: ";
    cin >> nim_cari;
    
    for (int i = 0, lebar_label = 18; i < jumlah_mhs; i++) {
        if (daftar_mhs[i].nim == nim_cari) {
            cout << "\nData Mahasiswa Ditemukan:\n";
            cout << left << setw(lebar_label) << "NIM" << ":" << daftar_mhs[i].nim << "\n";
            cout << left << setw(lebar_label) << "Nama" << ":" << daftar_mhs[i].nama << "\n";
            cout << left << setw(lebar_label) << "Angkatan" << ":" << daftar_mhs[i].angkatan << "\n";
            cout << left << setw(lebar_label) << "Jurusan" << ":"<< daftar_mhs[i].jurusan << "\n";
            cout << left << setw(lebar_label) << "Nilai Tugas" << ":"<< daftar_mhs[i].tugas << "\n";
            cout << left << setw(lebar_label) << "Nilai UTS" << ":"<< daftar_mhs[i].uts << "\n";
            cout << left << setw(lebar_label) << "Nilai UAS" << ":"<< daftar_mhs[i].uas << "\n";
            cout << left << setw(lebar_label) << "Nilai Rata-rata" << ":"<< daftar_mhs[i].rerata << "\n\n";
            return;
        }
    }
    cout << "Data Mahasiswa tidak ditemukan.\n\n";
}

// Edit data mahasiswa dgn NIM
void edit_mahasiswa() {
    string nim_edit;
    cout << "Masukkan NIM mahasiswa yang ingin diedit: ";
    cin >> nim_edit;
    cin.ignore(); //bersih buffer
    
    for (int i = 0, lebar_label = 15; i < jumlah_mhs; i++) {
        if (daftar_mhs[i].nim == nim_edit) { //edit

            cout << "\nMasukkan Data Baru:\n";
            cout << left << setw (lebar_label) << "Nama Mahasiswa" << ": ";
            getline(cin, daftar_mhs[i].nama);
            
            cout << left << setw (lebar_label) << "Angkatan" << ": ";
            cin >> daftar_mhs[i].angkatan;
            cin.ignore(); // Hindari buffer
            
            cout << left << setw (lebar_label) << "Jurusan" << ": ";
            getline(cin, daftar_mhs[i].jurusan);
            
            cout << left << setw (lebar_label) << "Nilai Tugas" << ": ";
            cin >> daftar_mhs[i].tugas;
            
            cout << left << setw (lebar_label) << "Nilai UTS" << ": ";
            cin >> daftar_mhs[i].uts;
            
            cout << left << setw (lebar_label) << "Nilai UAS" << ": ";
            cin >> daftar_mhs[i].uas;
            
            hitung_rata_rata (daftar_mhs[i]);
            cout << "\nData mahasiswa berhasil diperbarui!\n\n";
            return;
        }
    }
    cout << "Data Mahasiswa tidak ditemukan.\n\n";
}

// Menu utama
void menu() {
    while (true) {
        cout << "\n======== MENU UTAMA ========\n";
        cout << "1. Menambah Data Mahasiswa\n";
        cout << "2. Melihat Data Mahasiswa\n";
        cout << "3. Mencari Data Mahasiswa\n";
        cout << "4. Mengedit Data Mahasiswa\n";
        cout << "5. Keluar Dari Program";
        cout << "\n============================\n";
        cout << "Pilih menu: ";
        
        int pilihan;
        cin >> pilihan;
        
        switch (pilihan) {
            case 1:
                tambah_mahasiswa();
                break;
            case 2:
                lihat_mahasiswa();
                break;
            case 3:
                cari_mahasiswa();
                break;
            case 4:
                edit_mahasiswa();
                break;
            case 5:
                cout << "\nProgram berakhir!\n";
                return;
            default:
                cout << "\nPilihan tidak valid, silakan coba lagi!\n";
        }
    }
}

// Program jalan
int main() {
    menu();
return 0;
}