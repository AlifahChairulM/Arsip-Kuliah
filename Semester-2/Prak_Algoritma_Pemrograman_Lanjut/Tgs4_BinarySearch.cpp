#include <iostream>
using namespace std;

int BinarySearch(int x[], int size, int cari) {
    int kiri = 0; // elemen sulung = kecil
    int kanan = size - 1; // elemen bontot = besar
    while (kiri <= kanan) {
        int median =(kiri + kanan) / 2; //khas binary
        if (x[median] == cari) // nilai nemu
            return median;
        else if (x[median] < cari) //nilai besar ke kanan
            kiri = median + 1;
        else 
            kanan = median - 1; //nilai kecil ke kiri
    }
    return -1;// klo ga nemu
}

int main() {
    int JmlTiket; //input jlm tiket
    cout << "Masukkan jumlah tiket: ";
    cin >> JmlTiket;

    int harga[JmlTiket]; //input harga tiket
    cout << "Masukkan harga tiket: " << endl;
    for (int i = 0; i < JmlTiket; i++) {
        cout << "Harga tiket ke-" << i + 1 << ": ";
        cin >> harga[i];
    }

// Periksa apakah array sudah urut
if (!IsSorted(harga, JmlTiket)) {
    cout << "\nData belum terurut. Mengurutkan harga tiket...\n";
    SortArray(harga, JmlTiket); // Jika belum urut, diurutkan dulu
    cout << "Data setelah diurutkan: ";
    for (int i = 0; i < JmlTiket; i++) {
        cout << harga[i] << " ";
    }
    cout << endl;
} else {
    cout << "\nData sudah terurut.\n";
}

    //cari harga yg dicari
    int cari;
    cout << "Masukkan harga tiket yang ingin dicari: ";
    cin >> cari;

    int indeks = BinarySearch(harga, JmlTiket, cari); //panggil fungsi

        if (indeks != -1)
            cout << "Harga tiket ditemukan pada indeks " << indeks << endl;
        else
            cout << "Haga tiket tidak ditemukan" <<endl;
        return 0;
}