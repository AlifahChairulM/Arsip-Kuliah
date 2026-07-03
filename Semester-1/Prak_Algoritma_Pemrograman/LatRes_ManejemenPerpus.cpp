#include <iostream>
using namespace std;

int main() {
    int pilihan;
    string nama, nim, tanggalPinjam, tanggalKembali, judulBuku;
    char kondisiBuku;
    double harga, uangDiberikan, uangKembali;

    cout << "==PERPUSTAKAAN==\n";
    cout << "1. Meminjam buku\n";
    cout << "2. Mengembalikan buku\n";
    cout << "3. Membeli buku\n";
    
    cout << "Input pilihan: ";
    cin >> pilihan;
    cin.ignore(); // Membersihkan newline dari buffer

    switch (pilihan) {
        case 1:
            // Meminjam buku
            cout << "Nama: ";
            getline(cin, nama);
            cout << "NIM: ";
            getline(cin, nim);
            cout << "Tanggal Pinjam (dd MMM yyyy): ";
            getline(cin, tanggalPinjam);

            cout << "\n==MEMINJAM BUKU==\n";
            cout << "Nama: " << nama << endl;
            cout << "NIM: " << nim << endl;
            cout << "Tanggal Pinjam: " << tanggalPinjam << endl;
            break;

        case 2:
            // Mengembalikan buku
            cout << "Nama: ";
            getline(cin, nama);
            cout << "NIM: ";
            getline(cin, nim);
            cout << "Tanggal Kembali (dd MMM yyyy): ";
            getline(cin, tanggalKembali);
            cout << "Buku dalam kondisi baik atau tidak (y/n): ";
            cin >> kondisiBuku;
            cin.ignore(); // Membersihkan newline dari buffer

            cout << "\n==MENGEMBALIKAN BUKU==\n";
            cout << "Nama: " << nama << endl;
            cout << "NIM: " << nim << endl;
            cout << "Tanggal Kembali: " << tanggalKembali << endl;

            if (kondisiBuku == 'y' || kondisiBuku == 'Y') {
                cout << "Terimakasih" << endl;
            } else {
                cout << "Anda bayar denda" << endl;
            }
            break;

        case 3:
            // Membeli buku
            cout << "Nama: ";
            getline(cin, nama);
            cout << "Judul Buku: ";
            getline(cin, judulBuku);
            cout << "Harga: ";
            cin >> harga;
            cout << "Uang Diberikan: ";
            cin >> uangDiberikan;

            uangKembali = uangDiberikan - harga;

            cout << "\n==MEMBELI BUKU==\n";
            cout << "Nama: " << nama << endl;
            cout << "Judul Buku: " << judulBuku << endl;
            cout << "Harga: " << harga << endl;
            cout << "Uang Diberikan: " << uangDiberikan << endl;
            cout << "Uang Kembali: " << uangKembali << endl;
            break;

        default:
            cout << "Pilihan tidak valid" << endl;
            break;
    }

    return 0;
}