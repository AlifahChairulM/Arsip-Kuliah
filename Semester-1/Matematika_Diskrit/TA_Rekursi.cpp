#include <iostream>
#include <vector>
#include <cstdlib> // untuk fungsi system("cls") atau system("clear")
using namespace std;

int recursionCount = 0; // Hitung jumlah pemanggilan

// Fungsi rekursif untuk menghitung T(n) dengan relasi non-homogen pertama
int NH1(int n) {
    recursionCount++; 
    if (n == 1) {
        return 1;
    } else if (n == 2) {
        return 2;
    } else {
        int result = 4 * NH1(n - 1) + 2 * NH1(n - 2) + n;
        cout << "T(" << n << ") = 4 * T(" << n - 1 << ") + 2 * T(" << n - 2 << ") + " << n << endl;
        return result;
    }
}

// Fungsi rekursif untuk menghitung T(n) dengan relasi non-homogen kedua
int NH2(int n) {
    recursionCount++; 
    if (n == 1) {
        return 1;
    } else if (n == 2) {
        return 2;
    } else {
        int result = 3 * NH2(n - 1) + 5 * n;
        cout << "T(" << n << ") = 3 * T(" << n - 1 << ") + 5 * " << n << endl;
        return result;
    }
}

// Fungsi untuk menghasilkan urutan berdasarkan relasi homogen an = c1 * an-1 + c2 * an-2
void generateSequence(int n, int a0, int a1, int c1, int c2) {
    if (n <= 0) {
        cout << "Jumlah elemen harus lebih besar dari 0." << endl;
        return;
    }

    cout << "a_0: " << a0 << endl;
    if (n > 1) {
        cout << "a_1: " << a1 << endl;
    }

    for (int i = 2; i < n; i++) {
        int next = c1 * a1 + c2 * a0;
        cout << "Tahap perhitungan a_" << i << ": " << c1 << " * a_" << (i - 1) << " + " << c2 << " * a_" << (i - 2) << " = " << next << endl;
        a0 = a1;
        a1 = next;
    }
}

// Fungsi untuk menghasilkan urutan berdasarkan relasi homogen umum
void generateGeneralSequence(int n, int k, vector<int> initial_values, vector<int> coefficients) {
    if (n <= 0 || k <= 0) {
        cout << "Jumlah elemen dan koefisien harus lebih besar dari 0." << endl;
        return;
    }

    for (int i = 0; i < k; i++) {
        cout << "a_" << i << ": " << initial_values[i] << endl;
    }

    for (int i = k; i < n; i++) {
        int next = 0;
        for (int j = 0; j < k; j++) {
            next += coefficients[j] * initial_values[i - j - 1];
        }

        cout << "Tahap perhitungan a_" << i << ": ";
        for (int j = 0; j < k; j++) {
            cout << coefficients[j] << " * a_" << (i - j - 1);
            if (j != k - 1) {
                cout << " + ";
            }
        }
        cout << " = " << next << endl;

        initial_values.push_back(next);
    }
}

// Fungsi untuk penjelasan rekursi
void penjelesan_recurrence() {
    cout << "Definisi dan langkah penyelesaian relasi rekursi homogen linear." << endl;
    cout << "Langkah-langkah: ..." << endl;
    cout << "Definisi." << endl;
    cout << "Relasi Recurrence untuk barisan {an} adalah persamaan yang menyatakan an dalam salah satu atau lebih bentuk a0, a1, ..., an-1 untuk semua n dengan n >= n0 dimana n0 bilangan bulat non-negatif." << endl;
    cout << "Barisan {an} tersebut dikatakan sebagai solusi dari relasi recurrence ini bila an memenuhi relasi recurrence." << endl;
    system("pause");
    system("cls");
    cout << "Langkah dasar dalam memecahkan relasi recurrence homogen linear adalah mencari solusi dalam bentuk an = rn dengan r konstanta.\n" ;
    cout << "an = r^n; an-1 = r^n-1; an-2 = r^n-2; an = r^n; …; an-k = r^n-k adalah solusi dari\n" ;  
    cout << "persamaan rekurensi: an = c1 an-1 + c2 an-2 + … + ck an-k\n" ;                  
    cout << "jika dan hanya jika\n" ;  
    cout << "diubah menjadi persamaan solusi: r^n = c1 r^n-1 +c2 r^n-2 + … + ck r^n-k\n" ;
    cout << "Langkah1:\n";
    cout << "Seluruh suku di ruas kanan dipindahkan ke ruas kiri.\n" ;
    cout << "Bila kedua ruas dibagi dengan rn-k diperoleh:\n";
    cout << "pangkat dari r yg pertama adalah (n)-(n-k) = k\n";            
    cout << "pangkat dari r yg kedua adalah (n-1)-(n-k) = k-1\n";
    cout << "pangkat dari r yg ketiga adalah (n-2)-(n-k) = k-2\n";
    cout << "Dan seterusnya sehingga didapat: r^k - c1 r^k-1 - c2 r^k-2 - … - ck-1 r - ck = 0.\n";
    cout << "Persamaan ini disebut persamaan karakteristik dari relasi recurrence (perhatikan, k sebagai pangkat dari r, menurun).\n";
    cout << "Langkah2:\n";
    cout << "Solusi dari persamaan ini disebut akar karakteristik (ri).\n";
    cout << "Langkah3\n";
    cout << "Solusi relasi recurrence berbentuk persamaan solusi:\n";
    cout << "(perhatikan, pangkat dari r tetap yaitu n)\n";
    cout << "an = a1r1^n + a2r2^n + … + akrk^n\n";
    system("pause");
    system("cls");
}

// Fungsi utama
int main() {
    int menu, menuRNL, n;
    char kembali;

    do {
        system("cls");
        cout << "======================================\n";
        cout << "|             Relasi Rekurensi       |\n";
        cout << "======================================\n";
        cout << "1. Penjelasan Materi\n";
        cout << "2. Relasi Rekurensi Linear Homogen\n";
        cout << "3. Relasi Rekurensi Non-Homogen\n";
        cout << "0. Keluar\n";
        cout << "--------------------------------------\n";
        cout << "Pilih menu: ";
        cin >> menu;

        if (menu == 0) {
            cout << "Keluar dari program.\n";
            break;
        }

        switch (menu) {
            case 1:
                system("cls");
                penjelesan_recurrence();
                break;

            case 2:
                system("cls");
                int a0, a1, c1, c2;
                cout << "Masukkan jumlah elemen dalam urutan: ";
                cin >> n;
                cout << "Masukkan nilai awal a0: ";
                cin >> a0;
                cout << "Masukkan nilai awal a1: ";
                cin >> a1;
                cout << "Masukkan koefisien c1: ";
                cin >> c1;
                cout << "Masukkan koefisien c2: ";
                cin >> c2;
                generateSequence(n, a0, a1, c1, c2);
                break;

            case 3:
                system("cls");
                cout << "Masukkan nilai n: ";
                cin >> n;
                cout << "Pilih relasi:\n1. 4*T(n-1) + 2*T(n-2) + n\n2. 3*T(n-1) + 5*n\n";
                cin >> menuRNL;

                if (menuRNL == 1) {
                    cout << "Hasil: T(" << n << ") = " << NH1(n) << endl;
                } else if (menuRNL == 2) {
                    cout << "Hasil: T(" << n << ") = " << NH2(n) << endl;
                }
                break;

            default:
                cout << "Menu tidak valid.\n";
        }

        cout << "Kembali ke menu utama? (Y/N): ";
        cin >> kembali;
    } while (kembali == 'Y' || kembali == 'y');

    return 0;
}