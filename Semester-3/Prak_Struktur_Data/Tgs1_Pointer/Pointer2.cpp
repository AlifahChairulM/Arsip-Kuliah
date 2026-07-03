#include <iostream>
#include <string>
using namespace std;

struct dataBuku {
    string judul;
    int harga;
};

int main() {
    dataBuku *buku1;
    buku1 = new dataBuku(); // objek dinamis

    // Input data buku
    buku1->judul = "Struktur Data Praktikum";
    buku1->harga = 75000;

    // Tampilkan data buku
    cout << "\n================================\n";
    cout << "            Data Buku";
    cout << "\n================================\n";
    cout << "Judul : " << buku1->judul << endl;
    cout << "Harga : Rp " << buku1->harga << endl;
    cout << "--------------------------------\n";

    // Hapus objek
    delete buku1;
    return 0;
}