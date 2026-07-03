#include <iostream>
using namespace std;

// Fungsi menggunakan pengulangan (iterasi) 
int pangkatIterasi(int x, int y) {
    int hasil = 1;
    for (int i = 1; i <= y; i++) {
        hasil *= x; // Mengalikan x sebanyak y kali
    }
    return hasil;
}

int main() {
    int x, y;

    // Input dari pengguna 
    cout << "Masukkan nilai x (basis): "; 
    cin >> x; 
    cout << "Masukkan nilai y (pangkat): "; 
    cin >> y;

    // Menghitung pangkat dengan pengulangan (iterasi)
    int hasilIterasi = pangkatIterasi(x, y);
    cout << "Hasil (iterasi): " << x << "^" << y << " = " << hasilIterasi << endl;

    return 0;
}