#include <iostream>
#include <string>
using namespace std;

int main() {
    string nama1 = "hanif";
    string nama2 = "fathimah";
    string nama3 = "zahira";

    // Menukar isi string
    string temp = nama1;
    nama1 = nama3;
    nama3 = nama2;
    nama2 = temp;

    // Menampilkan hasil
    cout << "nama1: " << nama1 << endl;
    cout << "nama2: " << nama2 << endl;
    cout << "nama3: " << nama3 << endl;

    return 0;
}
