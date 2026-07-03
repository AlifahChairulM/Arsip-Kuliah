#include <iostream> // memasukkan header file iostream untuk komunikasi dengan pengguna
#include <iomanip> // format output input, presisi nilai floating
#include <string> // manipulasi string
using namespace std; // memudahkan penulisan kode

int main() { // deklarasi input pengguna
//manipulasi atau ekspresi teks dengan berbagai cara
string nama;
string nim;
string plug;

// Menampilkan output "Masukkan data" ke program
cout << "Masukkan data:" << endl;
cout << "Nama\t: ";
getline(cin, nama); // membaca dan menerima string dari aliran input
cout << "NIM\t: ";
getline(cin, nim);
cout << "Plug\t: ";
getline(cin, plug);
cout << endl; // kasih spasi

// Menampilkan output "Inilah data Anda" ke program
cout << "Inilah data Anda:" << endl;
cout << "Nama\t: " << nama << endl; // "\t" untuk mengatur lebar
cout << "NIM\t: " << nim << endl;
cout << "Plug\t: " << plug << endl;
cout << endl;

// Menampilkan data dalam bentuk tabel
cout << "Dalam bentuk tabel:" << endl;
cout << "===============================================" <<
endl;
cout << left << setw(12) << "NIM" << " | " // angka dalam kurung diatur sesuai karakter nama yang ingin diisi + dilebihkan agar rapi
<< setw(23) << "Nama" << " | " // "setw" aliran output input dan lebar
<< setw(5) << "Plug" << endl;
cout << "===============================================" <<
endl;
cout << left << setw(12) << nim << " | "
<< setw(23) << nama << " | "
<< setw(5) << plug << endl;
return 0; // kode untuk keluar dari program
}