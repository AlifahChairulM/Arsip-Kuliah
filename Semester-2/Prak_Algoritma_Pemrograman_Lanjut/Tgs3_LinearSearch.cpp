#include <iostream>
#include <algorithm> // sort

using namespace std;

int main() {
    int A, cari;

    // Input jml data
    cout << "Masukkan jumlah data: ";
    cin >> A;

    int arr[A];

    // Input elemen array
    for (int i = 0; i < A; i++) {
        cout << "Masukkan data ke-" << i + 1 << ": ";
        cin >> arr[i];
    }

    // Urutkan array
    sort(arr, arr + A);

    // Tampilkan data setelah diurutkan
    cout << "Data telah diurutkan: ";
    for (int i = 0; i < A; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Input data yang ingin dicari
    cout << "Masukkan data yang dicari: ";
    cin >> cari;

    // Pencarian data (Linear)
    int posisi = -1;
    for (int i = 0; i < A; i++) {
        if (arr[i] == cari) {
            posisi = i;
            break;
        }
    }

    //hasil pencarian
    if (posisi != -1)
        cout << "Data ditemukan di indeks ke-" << posisi << endl;
    else
        cout << "Data tidak ditemukan!" << endl;

    return 0;
}
