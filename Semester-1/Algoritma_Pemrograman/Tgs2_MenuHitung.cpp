#include <iostream>
using namespace std;

int main() {
    int x;
    int a = 0, b = 1, fibonacci = 0;
    int i = 2; 
    
    // input pengguna
    cout << "Masukkan nilai x: ";
    cin >> x;

    // langsung tercetak hasil, ika n adalah 0 atau 1
    if (x == 0) {
        cout << "Bilangan Fibonacci ke-0 adalah 0" << endl;
    } else if (x == 1) {
        cout << "Bilangan Fibonacci ke-1 adalah 1" << endl;
    } else {
        // gunakan loop while 
        while (i <= x) {
            fibonacci = a + b;  // itung bilangan Fibonacci berikutnya
            a = b;        // untuk simpan nilai sebelumnya
            b = fibonacci;      // Update bilangan Fibonacci terbaru
            i++;
        }

        cout << "Urutan bilangan fibonacci ke-" << x << " adalah " << fibonacci << endl;
    }

    return 0;
}