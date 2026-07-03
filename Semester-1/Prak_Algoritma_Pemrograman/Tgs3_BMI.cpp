#include <iostream>
#include <stdexcept>
using namespace std;

// tampilkan menu
int pilihmenu() {
    int menu;
    cout << "*** MENU HITUNG ***\n";
    cout << "1. Jumlah Digit\n";
    cout << "2. Kelipatan dari Bilangan\n";
    cout << "3. BMI\n";
    cout << "4. Keluar\n";
    cout << "Masukkan pilihan Anda: ";
    cin >> menu;
    return menu;
}

// hitung jumlah digit dalam angka
int hitung(int angka) {
    if (angka == 0) {
        return 1;
    }
    int jumlah = 0;
    while (angka != 0) {
        angka /= 10;
        jumlah++;
    }
    return jumlah;
}

// cek hub kelipatan bil 1 dan 2
bool Kelipatan(int bilangan1, int bilangan2) {
    if (bilangan2 == 0) {
        throw runtime_error("Tidak bisa memeriksa kelipatan dengan pembagi 0");
    }
    return bilangan1 % bilangan2 == 0;
}

// hitung BMI
float hitungBMI(float berat, float tinggi) {
    if (tinggi <= 0) {
        throw runtime_error("Tinggi badan harus lebih dari 0");
    }
    return (berat * 10000) / (tinggi * tinggi);
}

// kategori BMI
string kategoriBMI(float bmi) {
    if (bmi < 18.5) {
        return "KURUS (ayo tingkatkan bb)";
    } else if (bmi >= 18.5 && bmi < 24.9) {
        return "NORMAL (terus pertahankan)";
    } else if (bmi >= 25 && bmi < 29.9) {
        return "GEMUK (ayo turunkan bb)";
    } else {
        return "OBESITAS (ayo hidup sehat)";
    }
}

int main() {
    int menu = pilihmenu();
    try {
        // Error handling
        if (menu < 1 || menu > 4) {
            throw runtime_error("Pilih nomor menu yang tersedia.");
        }
        // syarat menu 1
        if (menu == 1) {
            int angka;
            cout << "Masukkan angka: ";
            if (!(cin >> angka)) {
                throw runtime_error("Masukkan bilangan bulat.");
            }
            int jumlah = hitung(angka);
            cout << "Jumlah digit dari " << angka << " yaitu " << jumlah << endl;
        }
        // syarat menu 2
        else if (menu == 2) {
            int bilangan1, bilangan2;
            cout << "Masukkan angka pertama: ";
            if (!(cin >> bilangan1)) {
                throw runtime_error("Masukkan angka bulat.");
            }
            cout << "Masukkan angka kedua: ";
            if (!(cin >> bilangan2)) {
                throw runtime_error("Masukkan angka bulat.");
            }
            if (Kelipatan(bilangan1, bilangan2)) {
                cout << bilangan1 << " merupakan kelipatan " << bilangan2 << endl;
            } else {
                cout << bilangan1 << " bukan kelipatan " << bilangan2 << endl;
            }
        }
        // syarat menu 3
        else if (menu == 3) {
            float berat, tinggi, bmi;
            cout << "Masukkan berat badan (kg): ";
            if (!(cin >> berat) || berat <= 0) {
                throw runtime_error("Berat badan harus lebih dari 0 dan bernilai bulat.");
            }
            cout << "Masukkan tinggi badan (cm): ";
            if (!(cin >> tinggi) || tinggi <= 0) {
                throw runtime_error("Tinggi badan harus lebih dari 0 dan bernilai bulat.");
            }
            bmi = hitungBMI(berat, tinggi);
            cout << "Nilai BMI Anda: " << bmi << endl;
            cout << "Kategori BMI Anda: " << kategoriBMI(bmi) << endl;
        }
        // syarat menu 4
        else if (menu == 4) {
            cout << "Mengakhiri program :)" << endl;
        }
    } catch (const runtime_error &e) {
        cout << e.what() << endl;
    }
    return 0;
}
