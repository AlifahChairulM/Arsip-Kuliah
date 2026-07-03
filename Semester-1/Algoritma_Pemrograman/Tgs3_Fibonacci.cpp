#include <iostream>
using namespace std;

//hitung jlm digit//
int hitung (int angka){ //angka 0 tetap dihitung digit//
    if(angka == 0) {
        return 1;
        }

    int jumlah = 0;
    while (angka != 0) { // Hitung jml digit dgn membagi angka dgn angka di pilih (10)//
        angka /= 10;
        jumlah++;
    }
        return jumlah;
}

//kelipatan dari bilangan//
bool Kelipatan(int bilangan1, int bilangan2) { // bil dgn kelipatan dari bil lain dan sisa bagi = 0//
    if (bilangan2 == 0) { //error handling//
        throw runtime_error ("ga bisa periksa kelipatan pembagi 0");
        }
        return bilangan1 % bilangan2 == 0;
}

// Menghitung BMI//
 float hitungBMI(float berat, float tinggi) {
    if (tinggi <= 0){ //error handling//
        throw runtime_error ("tinggi badan harus lebih dari 0");
    }
    return (berat*10000) / (tinggi * tinggi);
}

//kategoriBMI//
string kategoriBMI (float bmi) {
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

    //Menu//
int pilihmenu() {
    int menu;
    cout << "*** MENU HITUNG ***:\n";
    cout << "1. Jumlah Digit\n";
    cout << "2. Kelipatan dari Bilangan\n";
    cout << "3. BMI\n";
    cout << "4. Keluar\n";
    cout << "Masukkan pilihan Anda: ";
    cin >> menu;
    return menu;
}


int main(){
    int menu = pilihmenu();  
    try { //error handling//

    //menu tidak tersedia//
        if (menu) {
            throw runtime_error ("Pilih nomor menu yang tersedia.");}
        } catch (const runtime_error & e) {
            cout << e.what() << endl;}
    
//syarat menu 1, jml digit//
        if (menu == 1) {
            int angka;
                cout << "Masukkan angka: ";
                if (!(cin >> angka)) {
                    throw runtime_error ("masukkan bilangan bulat");
                }
            int jumlah = hitung (angka);
                cout << "Jumlah digit dari " << angka << " yaitu " << jumlah << endl;
        }
        if else (menu) {
            throw runtime_error ("Pilih nomor menu yang tersedia.");}
        } catch (const runtime_error & e) {
            cout << e.what() << endl;}
        }

    //syarat menu 2, kelipatan bil//
        else if (menu == 2) {
            int bilangan1, bilangan2;
                cout << "Masukkan angka pertama: ";
                if (!(cin >> bilangan1)) {
                    throw runtime_error ("masukkan angka bulat");
                }  
                cout << "Masukkan angka kedua: ";
                if (!(cin >> bilangan2)) {
                    throw runtime_error ("masukkan angka bulat");
                }
                if (Kelipatan (bilangan1, bilangan2) ) {
                    cout << bilangan1 << " merupakan kelipatan " << bilangan2 << endl;
                } else {
                    cout << bilangan1 << " bukan kelipatan " << bilangan2 << endl;}
        } 

    //syarat menu 3, BMI//     
        else if (menu == 3) {
            float berat, tinggi, bmi;
                cout << "Masukkan berat badan (kg): ";
            if ( ! (cin >> berat) || berat <= 0) {
                throw runtime_error ("tinggi / berat badan harus lebih dari 0 dan bernilai bulat");}            
                cout << "Masukkan tinggi badan (cm): ";
            if ( ! (cin >> tinggi) || tinggi <= 0) {
                cout << endl;
                throw runtime_error ("tinggi / berat badan harus lebih dari 0 dan bernilai bulat");}
            bmi = hitungBMI (berat, tinggi);
            cout << "Nilai bmi Anda: " << bmi << endl; 
            cout << "kategori BMI Anda: " << kategoriBMI(bmi);
        }

    //syarat menu 4, keluar//
        else if (menu == 4) {
            cout << "Mengakhiri program :) " << endl;
        }
}