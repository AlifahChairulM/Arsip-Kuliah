#include <iostream>
using namespace std;

int main() {
    int bil_prima[] = {2, 3, 5, 7, 11};
    int *tunjuk; // pointer

    //tampil bilangan awal
    cout << "\n====================================\n";
    cout << "     DAFTAR BILANGAN PRIMA AWAL    \n";
    cout << "====================================\n";
    cout << "Bilangan prima: ";
    for (int i = 0; i < 5; i++) {
        tunjuk = &bil_prima[i]; //pointer tunjuk elemen
        cout << *tunjuk << (i < 4 ? ", " : "");
    }
    
    // jeda sebelum diubah
    cout << "\n";
    cout << "\nProses penggantian semua elemen menjadi 2...\n";
    for (int i = 0; i < 5; i++) {
        tunjuk = &bil_prima[i];
        *tunjuk = 2;
    }

    //tampil bilangan habis ganti
    cout << "\n====================================\n";
    cout << "   DAFTAR BILANGAN SETELAH DIGANTI  \n";
    cout << "====================================\n";  
    for (int i = 0; i < 5; i++) {
        tunjuk = &bil_prima[i];
        cout << *tunjuk << (i < 4 ? ", " : "");
    }
    return 0;
}