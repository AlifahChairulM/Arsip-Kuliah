#include <iostream> // Library untuk input/output
#include <string>   // Library untuk tipe data string
using namespace std; // Menggunakan namespace std agar tidak perlu menulis std::

//ini linked listnya
struct DaftarNode { // Struktur node untuk linked list
    string namaPeserta;      // Nama peserta
    string devisi;           // Divisi peserta
    DaftarNode* sesudah;     // Pointer ke node berikutnya
};

DaftarNode* head = nullptr; // Pointer ke node awal (head) dari linked list

// Fungsi untuk menambah data peserta ke linked list
void inputData(const string& nama, const string& devisi) {
    DaftarNode* baru = new DaftarNode{nama, devisi, nullptr}; // Buat node baru
    if (!head) head = baru; // Jika linked list kosong, node baru jadi head
    else {
        DaftarNode* iterasi = head; // Mulai dari head
        while (iterasi->sesudah) iterasi = iterasi->sesudah; // Iterasi ke node terakhir
        iterasi->sesudah = baru; // Tambahkan node baru di akhir
    }
}

// Fungsi untuk menampilkan seluruh daftar peserta
void tampilkanPendaftar() {
    if (!head) { // Jika linked list kosong
        cout << "Belum ada pendaftar.\n"; return;
    }
    cout << "=== Daftar Peserta MMC ===\n"; // Judul daftar
    int nomor = 1; // Nomor urut peserta
    for (DaftarNode* iterasi = head; iterasi; iterasi = iterasi->sesudah) // Iterasi seluruh node
        cout << nomor++ << ". " << iterasi->namaPeserta << ", " << iterasi->devisi << endl; // Tampilkan data
}

// Fungsi untuk menghapus peserta berdasarkan nama
void hapusPendaftar() {
    if (!head) { // Jika linked list kosong
        cout << "Belum ada pendaftar.\n"; return;
    }
    string namaHapus; // Variabel untuk nama yang akan dihapus
    cout << "Masukkan nama peserta yang ingin dihapus: ";
    getline(cin, namaHapus); // Input nama peserta yang akan dihapus
    DaftarNode* iterasi = head; // Mulai dari head
    DaftarNode* sebelum = nullptr; // Pointer ke node sebelum yang dihapus
    while (iterasi) { // Iterasi seluruh node
        if (iterasi->namaPeserta == namaHapus) { // Jika nama ditemukan
            if (sebelum) sebelum->sesudah = iterasi->sesudah; // Hubungkan node sebelum ke node setelah yang dihapus
            else head = iterasi->sesudah; // Jika node yang dihapus adalah head, pindahkan head
            delete iterasi; // Hapus node
            cout << "Peserta " << namaHapus << " telah dihapus.\n"; // Pesan konfirmasi
            return;
        }
        sebelum = iterasi; // Simpan node sebelumnya
        iterasi = iterasi->sesudah; // Pindah ke node berikutnya
    }  
    cout << "Peserta dengan nama " << namaHapus << " tidak ditemukan.\n"; // Pesan jika nama tidak ditemukan
}   

// Fungsi untuk memilih divisi peserta
string pilihDevisi() {
    int opsi; // Variabel untuk input pilihan divisi
    cout << "Pilih divisi:\n"
         << "1. Fotografi\n"
         << "2. Videografi\n"
         << "3. Desain\n"
         << "4. Game Dev\n"
         << "5. Humas\n"
         << "6. E-sport\n"
         << "7. Sekretaris\n"
         << "Pilihan (1-7): ";
    cin >> opsi; // Input pilihan divisi
    cin.ignore(); // Membersihkan buffer
    switch (opsi) { // Mengembalikan nama divisi sesuai input
        case 1: return "Fotografi";
        case 2: return "Videografi";
        case 3: return "Desain";
        case 4: return "Game Dev";
        case 5: return "Humas";
        case 6: return "E-sport";
        case 7: return "Sekretaris";
        default: return "Tidak Valid";
    }
}

// Fungsi utama program
int main() {
    int pilihan; // Variabel untuk menu pilihan
    string nama, devisi; // Variabel untuk input nama dan divisi
    do {
        // Tampilkan menu utama
        cout << "\n=== MENU PENDAFTARAN MMC ===\n"
             << "1. Tambahkan Pendaftar\n"
             << "2. Tampilkan Daftar\n"
             << "3. Hapus Daftar\n"
             << "4. Keluar\n"
             << "Pilih menu: ";
        cin >> pilihan; // Input pilihan menu
        cin.ignore(); // Membersihkan buffer
        if (pilihan == 1) { // Tambah pendaftar
            cout << "Masukkan nama peserta: ";
            getline(cin, nama); // Input nama peserta   
            devisi = pilihDevisi(); // Input divisi peserta
            inputData(nama, devisi); // Tambahkan data ke linked list
        } else if (pilihan == 2) tampilkanPendaftar(); // Tampilkan daftar
        else if (pilihan == 3) hapusPendaftar(); // Hapus pendaftar
        else if (pilihan == 4) cout << "Program selesai.\n"; // Keluar
        else cout << "Pilihan tidak valid!\n"; // Jika input tidak valid
    } while (pilihan != 4); // Ulangi sampai pilih keluar
    return 0; // Selesai
}