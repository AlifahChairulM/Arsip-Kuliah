#include <iostream>
#include <string>
#include <vector>
#include <iomanip> // Untuk format waktu
#include <ctime>
#include <thread>
#include <chrono>

using namespace std;

// Fungsi untuk membersihkan layar konsol
void clearScreen()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

// Struktur untuk menyimpan data tanaman
struct Tanaman
{
    string nama;
    string lokasi;
    int jam;
    int menit;
    bool sudahDisiram = false; // Status penyiraman
};

// Fungsi untuk mendapatkan waktu saat ini
tm dapatkanWaktuSaatIni()
{
    time_t t = time(0);
    tm *sekarang = localtime(&t);
    return *sekarang;
}

// Fungsi untuk menampilkan menu utama
void tampilkanMenuUtama()
{
    cout << "\n==========================================\n";
    cout << "                MENU UTAMA                \n";
    cout << "==========================================\n";
    cout << "1. Tambah Tanaman Baru\n";
    cout << "2. Cek Status Penyiraman\n";
    cout << "3. Lihat Semua Tanaman\n";
    cout << "4. Edit Tanaman\n";
    cout << "5. Hapus Tanaman\n";
    cout << "6. Keluar\n";
    cout << "Pilih opsi (1-6): ";
}

// Fungsi untuk menampilkan header pada setiap sub-menu
void tampilkanHeader(const string &judul)
{
    clearScreen();
    cout << "\n==========================================\n";
    cout << "                " << judul << "                \n";
    cout << "==========================================\n";
}

// Fungsi untuk menambahkan tanaman baru
void tambahTanaman(vector<Tanaman> &tanaman)
{
    tampilkanHeader("TAMBAH TANAMAN BARU");
    Tanaman tanamanBaru;

    cin.ignore(); // Membersihkan buffer
    cout << "Masukkan nama tanaman: ";
    getline(cin, tanamanBaru.nama);

    cout << "Masukkan lokasi tanaman: ";
    getline(cin, tanamanBaru.lokasi);

    do
    {
        cout << "Atur waktu penyiraman (jam, format 24 jam): ";
        cin >> tanamanBaru.jam;
        cout << "Atur waktu penyiraman (menit): ";
        cin >> tanamanBaru.menit;

        if (tanamanBaru.jam < 0 || tanamanBaru.jam > 23 || tanamanBaru.menit < 0 || tanamanBaru.menit > 59)
        {
            cout << "Waktu tidak valid. Silakan masukkan ulang.\n";
        }
    } while (tanamanBaru.jam < 0 || tanamanBaru.jam > 23 || tanamanBaru.menit < 0 || tanamanBaru.menit > 59);

    tanaman.push_back(tanamanBaru);
    cout << "Tanaman berhasil didaftarkan!\n";
}

// Fungsi untuk mengecek status penyiraman
void cekStatusPenyiraman(vector<Tanaman> &tanaman)
{
    tampilkanHeader("CEK STATUS PENYIRAMAN");
    if (tanaman.empty())
    {
        cout << "\nTidak ada tanaman yang terdaftar!\n";
        return;
    }

    tm waktuSaatIni = dapatkanWaktuSaatIni();
    for (auto &t : tanaman)
    {
        if (waktuSaatIni.tm_hour > t.jam ||
            (waktuSaatIni.tm_hour == t.jam && waktuSaatIni.tm_min >= t.menit))
        {
            if (!t.sudahDisiram)
            {
                cout << "\nPeringatan! Tanaman '" << t.nama
                     << "' di lokasi '" << t.lokasi
                     << "' sudah waktunya disiram.\n";

                string jawaban;
                do
                {
                    cout << "Apakah Anda sudah menyiram tanaman ini? (ya/tidak): ";
                    cin >> jawaban;
                    if (jawaban == "ya" || jawaban == "Ya")
                    {
                        t.sudahDisiram = true;
                        cout << "Status: Tanaman telah disiram ^_^ .\n";
                    }
                    else if (jawaban == "tidak" || jawaban == "Tidak")
                    {
                        cout << "Silakan segera menyiram tanaman T_T.\n";
                    }
                    else
                    {
                        cout << "Input tidak valid. Masukkan 'ya' atau 'tidak'.\n";
                    }
                } while (!t.sudahDisiram);
            }
            else
            {
                cout << "\nTanaman '" << t.nama << "' sudah disiram hari ini.\n";
            }
        }
        else
        {
            cout << "\nTanaman '" << t.nama
                 << "' belum waktunya disiram. Jadwal penyiraman: "
                 << setfill('0') << setw(2) << t.jam << ":"
                 << setfill('0') << setw(2) << t.menit << endl;
        }
    }
}

// Fungsi untuk menampilkan semua tanaman yang terdaftar
void tampilkanSemuaTanaman(const vector<Tanaman> &tanaman)
{
    tampilkanHeader("DAFTAR SEMUA TANAMAN");
    if (tanaman.empty())
    {
        cout << "\nTidak ada tanaman yang terdaftar!\n";
        return;
    }

    cout << "\nDaftar Tanaman:\n";
    for (size_t i = 0; i < tanaman.size(); ++i)
    {
        cout << i + 1 << ". Nama: " << tanaman[i].nama
             << "\n   Lokasi: " << tanaman[i].lokasi
             << "\n   Waktu Penyiraman: "
             << setfill('0') << setw(2) << tanaman[i].jam << ":"
             << setfill('0') << setw(2) << tanaman[i].menit
             << "\n   Status: "
             << (tanaman[i].sudahDisiram ? "Sudah Disiram" : "Belum Disiram")
             << "\n----------------------------------\n";
    }
}

// Fungsi untuk mengedit tanaman
void editTanaman(vector<Tanaman> &tanaman)
{
    tampilkanHeader("EDIT TANAMAN");
    if (tanaman.empty())
    {
        cout << "\nTidak ada tanaman yang terdaftar!\n";
        return;
    }

    tampilkanSemuaTanaman(tanaman);
    cout << "Pilih nomor tanaman yang ingin diedit: ";
    int pilihan;
    cin >> pilihan;

    if (pilihan < 1 || pilihan > tanaman.size())
    {
        cout << "Pilihan tidak valid.\n";
        return;
    }

    Tanaman &t = tanaman[pilihan - 1];

    cin.ignore(); // Membersihkan buffer
    cout << "Masukkan nama baru (kosongkan untuk tidak mengubah): ";
    string namaBaru;
    getline(cin, namaBaru);
    if (!namaBaru.empty())
        t.nama = namaBaru;

    cout << "Masukkan lokasi baru (kosongkan untuk tidak mengubah): ";
    string lokasiBaru;
    getline(cin, lokasiBaru);
    if (!lokasiBaru.empty())
        t.lokasi = lokasiBaru;

    cout << "Masukkan waktu penyiraman baru (jam -1 untuk tidak mengubah): ";
    int jamBaru;
    cin >> jamBaru;
    if (jamBaru != -1)
        t.jam = jamBaru;

    cout << "Masukkan waktu penyiraman baru (menit -1 untuk tidak mengubah): ";
    int menitBaru;
    cin >> menitBaru;
    if (menitBaru != -1)
        t.menit = menitBaru;

    cout << "Tanaman berhasil diperbarui!\n";
}

// Fungsi untuk menghapus tanaman
void hapusTanaman(vector<Tanaman> &tanaman)
{
    tampilkanHeader("HAPUS TANAMAN");
    if (tanaman.empty())
    {
        cout << "\nTidak ada tanaman yang terdaftar!\n";
        return;
    }

    tampilkanSemuaTanaman(tanaman);
    cout << "Pilih nomor tanaman yang ingin dihapus: ";
    int pilihan;
    cin >> pilihan;

    if (pilihan < 1 || pilihan > tanaman.size())
    {
        cout << "Pilihan tidak valid.\n";
        return;
    }

    tanaman.erase(tanaman.begin() + (pilihan - 1));
    cout << "Tanaman berhasil dihapus!\n";
}

int main()
{
    vector<Tanaman> tanaman;
    int pilihan;
    string konfirmasi;

    while (true)
    {
        clearScreen();
        tampilkanMenuUtama();
        cin >> pilihan;

        switch (pilihan)
        {
        case 1:
            tambahTanaman(tanaman);
            break;
        case 2:
            cekStatusPenyiraman(tanaman);
            break;
        case 3:
            tampilkanSemuaTanaman(tanaman);
            break;
        case 4:
            editTanaman(tanaman);
            break;
        case 5:
            hapusTanaman(tanaman);
            break;
        case 6:
            cout << "Anda yakin ingin keluar? (ya/tidak): ";
            cin >> konfirmasi;
            if (konfirmasi == "ya" || konfirmasi == "Ya")
            {
                cout << "Terima kasih telah menggunakan program ini!\n";
                return 0;
            }
            break;
        default:
            cout << "Pilihan tidak valid. Silakan pilih antara 1 hingga 6.\n";
        }

        this_thread::sleep_for(chrono::seconds(5));
    }

    return 0;
}