//alifah chairul m_123240234_IF-F//
#include <iostream>
using namespace std;

int main() {
    int x, y;
    long long hasil = 1; // untuk menangani angka besar
    
    // input pengguna
    cout << "Masukkan nilai X: ";
    cin >> x;
    cout << "Masukkan nilai Y: ";
    cin >> y; 
    
    // Perulangan hitung x^y 
    cout << "Proses Iterasi:" << endl;
    for (int i = 0; i < y; i++) {
        hasil *= x;
        cout << "Iterasi " << i + 1 << " result = " << hasil << endl;
    }
    
    // tampilkan hasil akhir 
    cout << x << "^" << y << " adalah " << hasil << endl;
    return 0;
}