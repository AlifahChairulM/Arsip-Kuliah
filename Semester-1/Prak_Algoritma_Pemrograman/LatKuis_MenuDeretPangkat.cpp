#include <iostream>
#include <cmath>
using namespace std;

int main() {
int pilihan, jumlah_deret, i , a, b, total, basis, pangkat, hasil = 1;
string input, kode,lanjut, ulang;

cout <<"===================" <<endl;
cout << "  Toko Jayamahe" << endl;      
cout <<"===================" <<endl;
cout << "Menu Utama : " <<endl;
cout << "1 - Deret Biasa" <<endl;
cout << "2 - Deret penjumlahan" <<endl;
cout << "3 - Menu Bintang" <<endl;
cout << "4 - Exit" <<endl;
cout << endl;
cout << "Opsi: ";
cin >> pilihan;

switch (pilihan){
case 1 :{ 
  cout << "Jumlah deret yang diinginkan : ";
  cin >> jumlah_deret;
  for (i = 1; i <= jumlah_deret; i++)
  cout <<i<<" ";
  cin >> jumlah_deret;
  break;}
  
case 2:
  cout << "Masukkan basis :"; cin >> basis;
  cout << "Masukkan pangkat: "; cin >> pangkat;
  for (int i = 1; i <= pangkat; i++) {

    hasil *= basis;
      cout << basis;
      if ( i  < pangkat) {
        cout << " * ";} 
  }
  cout << " = " << hasil << endl;
  break;
case 3: {
    cin >> jumlah_deret, b, basis, pangkat;
    for (i = 1; i <= jumlah_deret; i++)   
        cout <<i<<" ";
    for ( a=2; a<= b; i++){
        cout << "^"<< i;
        total = basis ^ pangkat;}
        cout <<"="<< total ;}
    break;
}
}