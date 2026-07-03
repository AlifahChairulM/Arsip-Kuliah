#include <iostream>
#include <string>
#include <iomanip> // setw
#include <cctype>  // isdigit dan isalpha
#include <limits>  // numeric_limits
using namespace std;
// Penyimpanan data pegawai
struct Pegawai
{
    string nama, nip;
    int totalhari, gajiperhari;
};
// Fungsi cek nama hanya huruf dan spasi
bool hanyahuruf(const string &str)
{
    for (char c : str)
    {
        if (!isalpha(c) && c != ' ')
        {
            return false;
        }
    }
    return true;
}
// Fungsi cek NIP, total hari, gaji per hari hanya angka
bool hanyaangka(const string &str)
{
    for (char c : str)
    {
        if (!isdigit(c))
        {
            return false;
        }
    }
    return true;
}
// Fungsi bersihkan layar
void bersihkanlayar()
{
    system("cls");
}
int main()
{
    int jumlahpegawai;
    // Validasi input jumlah pegawai
    while (true)
    {
        cout << "Masukkan jumlah pegawai: ";
        cin >> jumlahpegawai;
        if (cin.fail() || jumlahpegawai <= 0)
        {                                                        // Deteksi salah inputcout << "Jumlah pegawai harus berupa bilangan asli!\n";cin.clear(); // Bersihkan kesalahan
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Hapus input salah
        }
        else
        {
            cin.ignore(); // Bersihkan sisa buffer
            break;
        }
    }
    Pegawai *pegawai = new Pegawai[jumlahpegawai];
    bersihkanlayar(); // Bersihkan layar setelah input jumlah pegawai// Input data pegawai
    for (int i = 0; i < jumlahpegawai; i++)
    {
        cout << "\n Masukkan Data Pegawai ke-" << i + 1 << ":\n";
        // Validasi Nama
        while (true)
        {
            cout << setw(15) << left << "Nama" << " : ";
            getline(cin, pegawai[i].nama);
            if (hanyahuruf(pegawai[i].nama))
                break; // Untuk inputulang
            cout << "!!! Nama harus berisi huruf !!!\n";
        }
        // Validasi NIP
        while (true)
        {
            cout << setw(15) << left << "NIP" << " : ";
            getline(cin, pegawai[i].nip);
            if (hanyaangka(pegawai[i].nip))
                break;
            cout << "!!! NIP harus berisi angka !!!\n";
        }
        // Validasi Total Hari
        while (true)
        {
            cout << setw(15) << left << "Total Hari" << " : ";
            cin >> pegawai[i].totalhari;
            if (cin.fail() || pegawai[i].totalhari <= 0)
            {
                cout << "!!! Total hari harus angka positif !!!\n"; // Input ulang
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            else
            {
                cin.ignore();
                break;
            }
        }
        // Validasi Gaji per hari
        while (true)
        {
            cout << setw(15) << left << "Gaji per Hari" << " : ";
            cin >> pegawai[i].gajiperhari;
            if (cin.fail() || pegawai[i].gajiperhari <= 0)
            {
                cout << "!!! Gaji per hari harus bilangan asli !!!\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            else
            {
                cin.ignore();
                break;
            }
        }
    }
    bersihkanlayar(); // Bersihkan layar setelah input data pegawai// Output data pegawai
    cout << "\nMENAMPILKAN DATA GAJI PEGAWAI\n";
    for (int i = 0; i < jumlahpegawai; i++)
    {
        int totalgaji = pegawai[i].totalhari * pegawai[i].gajiperhari; // hitung total gaji
        cout << "------------------------------\n";
        cout << " Data Pegawai ke-" << i + 1 << "\n";
        cout << "------------------------------\n";
        cout << setw(15) << left << "Nama" << " : " << pegawai[i].nama << endl;
        cout << setw(15) << left << "NIP" << " : " << pegawai[i].nip << endl;
        cout << setw(15) << left << "Total Hari" << " : " << pegawai[i].totalhari << endl;
        cout << setw(15) << left << "Gaji per Hari" << " : " << pegawai[i].gajiperhari << endl;
        cout << setw(15) << left << "Total Gaji" << " : " << totalgaji << endl;
    }
    return 0;
}