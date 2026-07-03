#include <iostream>
using namespace std;

int main() {
    char *nama1 = (char *)"hanif";
    char *nama2 = (char *)"fathimah";
    char *nama3 = (char *)"zahira";

    // Menukar pointer
    char *temp = nama1;
    nama1 = nama3;
    nama3 = nama2;
    nama2 = temp;

    // Menampilkan hasil
    cout << "nama1: " << nama1 << endl;
    cout << "nama2: " << nama2 << endl;
    cout << "nama3: " << nama3 << endl;

    return 0;
}
