//alifah chairul m_123240234_IF-F//
#include <iostream>

using namespace std;

// Fungsi hitung pangkat
int PR(int x, int y) {
    if (y == 0) {
        return 1; // Basis bila x^0 = 1
    } else {
        return x * PR(x, y - 1); // Rekursi
    }
}

int main() {
    int x, y;

    // Input pengguna
    cout << "Masukkan nilai x: ";
    cin >> x;
    cout << "Masukkan nilai y: "; //pangkat
    cin >> y;

    // hitung pangkat dengan rekursi
    int hasil = PR(x, y);

    // tampilkan hasil
    cout << "Hasil (rekursi): " << x << "^" << y << " = " << hasil << endl;

    return 0;
}
