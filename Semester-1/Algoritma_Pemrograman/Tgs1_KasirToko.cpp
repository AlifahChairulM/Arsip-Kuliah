#include <iostream>
using namespace std;

int main() {
int jumlah, totalbelanja, harga, jumlahtotal, jumlahbayar;
string input, kode;

cout <<"===================" <<endl;
cout << " Toko Jayamahe" << endl;
cout <<"===================" <<endl;
cout << "Barang yang tersedia : " <<endl;
cout << "01 - Leptop santai" <<endl;
cout << "02 - Leptop kerja" <<endl;
cout << "03 - Hp sekolah" <<endl;
cout << endl;
cout << "Barang yang dipilih : ";
cin >> kode;
cout << "Jumlah              : ";
cin >> jumlah;

if(kode == "01"){ // fungsi if pertama
  cout << "leptop santai";
  harga = 6000000;
}else if (kode == "02"){
  cout << "leptop kerja";
  harga = 8000000;
}else if (kode == "03"){
  cout << "hp sekolah";
  harga = 2000000;
}else{
  cout << "Maaf barang yang dipilih tidak tersedia";// bila data tidak ada pada pilihan
}
cout <<endl;
//struk pembayaran
cout << "===================" << endl;
cout <<"     Pembayaran" <<endl;
cout << "==================="<< endl;
cout <<"Harga         : " << harga << endl;
cout <<"Jumlah        : " << jumlah << endl;

totalbelanja = harga * jumlah;//rumus total belanja
cout<<"Total belanja : "<< totalbelanja << endl;

}