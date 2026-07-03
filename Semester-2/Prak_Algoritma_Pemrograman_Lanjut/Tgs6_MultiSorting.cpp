#include <iostream>
#include <iomanip> // ben rapi
#include <cstdlib> // untuk data/array acak
#include <ctime> // waktu now
using namespace std;

const int urut = 50; //jml data ato array acak dan akan diurutkan

// Fungsi tampilkan data
void tampilkandata(int arr[], int size) {
    for (int i = 0; i < size; i++) { //perulangan data
        cout << setw(4) << arr[i] << " "; //spasi antar angka
        if ((i + 1) % 10 == 0) { // Setiap 10 angka, pindah baris
            cout << endl;
        }
    }
}

// Bubble Sort
void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) { //perulangan, tukar
        for (int j = 0; j < size - i - 1; j++) { //data terbesar dah di akhir
            if (arr[j] > arr[j + 1]) { // bandingkan 2 data
                // Tukar elemen
                int tukar = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tukar;
            }
        }
    }
}

// Insertion Sort
void insertionSort(int arr[], int size) {
    for (int i = 1; i < size; i++) { // indeks 1 anggap benar lalu cek
        int key = arr[i]; //sek mau di tukar
        int j = i - 1;// j mundur ke posisi benar
        while (j >= 0 && arr[j] > key) { // nikai di kiri j > maka geser kanan
            arr[j + 1] = arr[j]; 
            j--; // cek ada yg lebih > dari key
        }
        arr[j + 1] = key; // key diposisi benar
    }
}

// Selection Sort
void selectionSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) { // cari terkecil
        int indekskecil = i; // tandai yg kecil
        for (int j = i + 1; j < size; j++) { //cek ada yg lebih kecil
            if (arr[j] < arr[indekskecil]) { //misal ada yg lebih kecil
                indekskecil = j; // kecil di temukan dan update
            }
        }
        // Tukar elemen
        int temp = arr[i];
        arr[i] = arr[indekskecil];
        arr[indekskecil] = temp;
    }
}

// Shell Sort
void shellSort(int arr[], int size) {
    for (int gap = size / 2; gap > 0; gap /= 2) { //cari nilai gap
        for (int i = gap; i < size; i++) { // interasi data
            int temp = arr[i]; //simpan gap now
            int j; 
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap]; //geser kanan
            }
            arr[j] = temp; //posisi tepat
        }
    }
}

// Quick Sort
void quickSort(int arr[], int awal, int akhir) {
    if (awal < akhir) {
        int pivot = arr[akhir]; //data akhir jd pivot
        int i = awal - 1; //bila ada data lebih < pivot
        for (int j = awal; j < akhir; j++) {
            if (arr[j] <= pivot) {
                i++;
                // Tukar elemen
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        // Tukar pivot ke posisi benar
        int temp = arr[i + 1];
        arr[i + 1] = arr[akhir];
        arr[akhir] = temp;
        int pi = i + 1; // posisi pivot benar
        quickSort(arr, awal, pi - 1); //urut kiri pivot
        quickSort(arr, pi + 1, akhir); //urut kanan pivot
    }
}

int main() {
    srand(time(0)); // kasih data random per program
    char ulang;

    do {
        int data[urut]; //simpan data acak
        for (int i = 0; i < urut; i++) {
            data[i] = rand() % 100; //isi dan hasil data 
        }

        //tampilkan data acak
        cout << endl;
        cout << "50 Data Acak Yang Akan Diurutkan:\n";
        tampilkandata(data, urut);
        cout << endl;
        cout << "=====================\n";
        cout << "   Program Sorting   \n";
        cout << "=====================\n";
        cout << "1. Bubble Sort\n";
        cout << "2. Insertion Sort\n";
        cout << "3. Selection Sort\n";
        cout << "4. Shell Sort\n";
        cout << "5. Quick Sort\n";
        cout << "=====================\n";
        cout << "Pilihan: ";
        int pilihan;
        cin >> pilihan;
        cout << endl;

        switch (pilihan) {
            case 1:
                bubbleSort(data, urut);
                cout << "Bubble Sort";
                break;
            case 2:
                insertionSort(data, urut);
                cout << "Insertion Sort";
                break;
            case 3:
                selectionSort(data, urut);
                cout << "Selection Sort";
                break;
            case 4:
                shellSort(data, urut);
                cout << "Shell Sort";
                break;
            case 5:
                quickSort(data, 0, urut - 1);
                cout << "Quick Sort";
                break;
            default:
                cout << "Pilihan tidak valid.\n";
                continue;
        }

        cout << " dengan 50 Data Acak Yang Telah Diurutkan:\n";
        tampilkandata(data, urut);

        cout << "\nLagi (y/t)? ";
        cin >> ulang;
    } while (ulang == 'y' || ulang == 'Y');

    return 0;
}
