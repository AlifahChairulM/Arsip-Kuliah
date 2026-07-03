#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int pilihan, belanja, total_belanja, setelah_diskon, umur, lama_sewa, jumlah_buku, biaya_sewa;
    float diskon;
    cout << "===================\n";
    cout << "|" << setw(10) << "MENU" << setw(10) << "|\n";
    cout << "===================\n";
    cout << "| 1. Membeli buku |\n";
    cout << "| 2. Menyewa buku |\n";
    cout << "| 3. Exit         |\n";
    cout << "===================\n";
    cout << endl;

    // Input pilihan dari user
    cout << "Input pilihan (1-3): ";
    cin >> pilihan;

    switch (pilihan) {
        case 1: // Beli buku
            cout << "Masukkan usia Anda: ";
            cin >> umur;
            cout << "Masukkan total belanja Anda: ";
            cin >> belanja;

            // Menghitung diskon berdasarkan generasi
            if (2024 - umur >= 1965 && 2024 - umur <= 1979) {
                // Gen X discount rates
                if (belanja >= 300000) {
                    diskon = 0.15;
                } else if (belanja >= 200000) {
                    diskon = 0.10;
                } else if (belanja >= 100000) {
                    diskon = 0.05;
                } else {
                    diskon = 0.0;
                }
            } else if (2024 - umur >= 1980 && 2024 - umur <= 1994) {
                // Gen Y discount rates
                if (belanja >= 300000) {
                    diskon = 0.20;
                } else if (belanja >= 200000) {
                    diskon = 0.15;
                } else if (belanja >= 100000) {
                    diskon = 0.10;
                } else {
                    diskon = 0.0;
                }
            } else if (2024 - umur >= 1995 && 2024 - umur <= 2009) {
                // Gen Z discount rates
                if (belanja >= 300000) {
                    diskon = 0.25;
                } else if (belanja >= 200000) {
                    diskon = 0.20;
                } else if (belanja >= 100000) {
                    diskon = 0.15;
                } else {
                    diskon = 0.0;
                }

                // Tambahan diskon untuk mahasiswa Gen Z
                if (2024 - umur >= 2003 && 2024 - umur <= 2006) {
                    if (belanja >= 300000) {
                        float tambahan_diskon = (belanja - (belanja * diskon)) * 0.05;
                        diskon += tambahan_diskon / belanja;
                    }
                }
            } else {
                diskon = 0.0;
            }

            // Menghitung total belanja setelah diskon
            setelah_diskon = belanja * diskon;
            total_belanja = belanja - setelah_diskon;
            cout << "Total belanja akhir: " << total_belanja << "\n";
            break;

        case 2: // Sewa buku
            int hari;
            cout << "Masukkan usia Anda: ";
            cin >> umur;
            cout << "Masukkan jumlah buku: ";
            cin >> jumlah_buku;
            cout << "Masukkan hari sewa (1 untuk Senin, 2 untuk Selasa, dst): ";
            cin >> hari;
            cout << "Masukkan lama sewa (dalam minggu): ";
            cin >> lama_sewa;

            // Menghitung biaya sewa berdasarkan generasi dan hari sewa
            int harga_sewa;
            if (2024 - umur >= 1965 && 2024 - umur <= 1979) { // Gen X
                if (hari >= 1 && hari <= 5) {
                    harga_sewa = 10000;
                } else {
                    harga_sewa = 20000;
                }
            } else if (2024 - umur >= 1980 && 2024 - umur <= 1994) { // Gen Y
                if (hari >= 1 && hari <= 5) {
                    harga_sewa = 7500;
                } else {
                    harga_sewa = 15000;
                }
            } else if (2024 - umur >= 1995 && 2024 - umur <= 2009) { // Gen Z
                if (hari >= 1 && hari <= 5) {
                    harga_sewa = 5000;
                } else {
                    harga_sewa = 10000;
                }
            } else {
                harga_sewa = 2000;
            }

            // Menghitung total biaya sewa
            biaya_sewa = (harga_sewa * jumlah_buku * lama_sewa);
            cout << "Biaya sewa Anda: Rp" << biaya_sewa << "\n";
            break;

        case 3: // Exit
            cout << "Keluar dari program" << endl;
            break;

        default:
            cout << "Pilihan tidak valid!\n";
            break;
    }

    return 0;
}
