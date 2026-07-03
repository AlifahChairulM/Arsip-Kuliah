#include <iostream>
#include <fstream>
using namespace std;

// Struktur data 
struct NilaiProtek2 {
    int nosiswa[5];
    char nama[20];
    int nilai[3];
};

// Fungsi untuk menulis data ke file
void tulisKeFile(const char* namafile) {
    ofstream file(namafile, ios::binary); //buka file
    if (!file) {
        cout << "Gagal membuka file untuk menulis.\n";
        return;
    }

    int jumlah;
    cout << "Masukkan jumlah data (min 10): ";
    cin >> jumlah;
    cin.ignore(); 

    if (jumlah < 1) { //pastikan data minimal 10
        cout << "Jumlah minimal 10 data!\n";
        file.close();
        return;
    }

    NilaiProtek2 data;
    for (int i = 0; i < jumlah; i++) {
        cout << "\nData ke-" << i + 1 << endl;

        // Input No Siswa dengan validasi hanya angka
        cout << "Masukkan 5 No Siswa: \n";
        for (int j = 0; j < 5; j++) {
            char label = 'A' + j; //urutan no
            int temp;
            while (true) {
                cout << "  No Siswa " << label << ": ";
                cin >> temp;
                if (cin.fail()) { // Hanya cek input harus angka
                    cout << "  Hanya angka!\n";
                    cin.clear();
                    cin.ignore(1000, '\n');
                } else {
                    data.nosiswa[j] = temp;
                    break;
                }
            }
        }
        cin.ignore(); 

        // Input Nama hanya huruf dan spasi
        while (true) {
            cout << "Masukkan Nama: ";
            cin.getline(data.nama, 20);
            bool valid = true;
            for (int c = 0; data.nama[c] != '\0'; c++) { //cek huruf
                if (!isalpha(data.nama[c]) && data.nama[c] != ' ') {
                    valid = false;
                    break;
                }
            }
            if (!valid || data.nama[0] == '\0') { // klo salah input
                cout << "  Nama hanya huruf dan spasi!\n";
            } else {
                break;
            }
        }

        // Input Nilai hanya angka 0-100
        const char* labelNilai[3] = {"UH", "UTS", "UAS"};
        cout << "Masukkan 3 Nilai (UH, UTS, UAS), 0-100:\n";
        for (int k = 0; k < 3; k++) {
            int temp;
            while (true) {
                cout << "  Nilai " << labelNilai[k] << ": ";
                cin >> temp;
                if (cin.fail() || temp < 0 || temp > 100) { //validasi nilai
                    cout << "  Nilai hanya 0-100!\n";
                    cin.clear();
                    cin.ignore(1000, '\n');
                } else {
                    data.nilai[k] = temp;
                    break;
                }
            }
        }
        cin.ignore(); 

        // Simpan ke file
        file.write(reinterpret_cast<char*>(&data), sizeof(NilaiProtek2));
    }

    file.close();
    cout << "\nData berhasil disimpan ke file.\n";
}

// Fungsi untuk membaca data dari file
void bacaDariFile(const char* namafile) { //alifah234.txt buat cek yg udah diinput
    ifstream file(namafile, ios::binary); //buka fila
    if (!file) {
        cout << "File tidak valid atau tidak ditemukan.\n";
        return;
    }

    NilaiProtek2 data;
    int index = 1;
    while (file.read(reinterpret_cast<char*>(&data), sizeof(NilaiProtek2))) { //baca per blok struct
        cout << "\nData ke-" << index++ << endl;
        cout << "No Siswa: ";
        for (int j = 0; j < 5; j++) {
            cout << data.nosiswa[j] << " ";
        }
        cout << "\nNama    : " << data.nama << endl;
        cout << "Nilai   : ";
        for (int k = 0; k < 3; k++) {
            cout << data.nilai[k] << " ";
        }
        cout << endl;
    }

    file.close();
}

//menu utama
int main() {
    int pilihan;
    char namafile[100];
    do {
        cout << endl;
        cout << "--- MENU UTAMA ----\n";
        cout << "1. Tulis ke file\n";
        cout << "2. Baca dari file\n";
        cout << "3. Keluar\n";
        cout << "===================\n";
        cout << "Masukkan Pilihan Anda [1-3] : ";
        cin >> pilihan;
        cin.ignore(); 

        switch (pilihan) {
            case 1:
                cout << "Masukkan nama file untuk menyimpan data (nama.txt): ";
                cin.getline(namafile, 100);
                tulisKeFile(namafile);
                break;
            case 2:
                cout << "Masukkan nama file untuk dibaca (nama.txt): ";
                cin.getline(namafile, 100);
                bacaDariFile(namafile);
                break;
            case 3:
                cout << "Keluar dari program.\n";
                break;
            default:
                cout << "Pilihan tidak valid!\n";// salah input
        }
    } while (pilihan != 3);
  
    return 0;
}