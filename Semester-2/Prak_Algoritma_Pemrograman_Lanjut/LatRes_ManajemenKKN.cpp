#include <iostream>
#include <fstream> //bacafile
#include <iomanip> //fixed, setprecision
using namespace std;

struct Mahasiswa { //aray dan struct
    char nama[50];
    char jenis_kelamin[10];
    char tanggal_lahir[15]; 
    int nim;
    int semester;
    char prodi[30];
    char fakultas[30];
    float ipk;
};

// Membaca seluruh data ke array pointer
int baca(Mahasiswa* data[], int maxData = 100) { //simpan data dan max data 100
    ifstream file("data_mahasiswa.dat", ios::binary); //buka file
    if (!file.is_open()) { // file gagal dibuka
        cout << "file tidak valid. \n";
        return 0;
    }
    int n = 0; // hitung jlm data
    while (n < maxData) {
        Mahasiswa* m = new Mahasiswa; //memori data baru
        if (!file.read(reinterpret_cast<char*>(m), sizeof(Mahasiswa))) { //ben iso dibaca
            delete m; // hapus memo klo gagal
            break;
        }
        data[n++] = m; //simpan pointer
    }
    file.close(); //tutup file
    return n;
}

// Menyimpan seluruh data dari array pointer ke file (overwrite)
void simpan(Mahasiswa* data[], int n) {
    ofstream file("data_mahasiswa.dat", ios::binary | ios::trunc); //buka file
    for (int i = 0; i < n; i++) {
        file.write(reinterpret_cast<char*>(data[i]), sizeof(Mahasiswa));// simpan
    }
    file.close();
}

// Sequential search NIM, return index jika ketemu, -1 jika tidak
int cari(Mahasiswa* data[], int n, int nim) {
    for (int i = 0; i < n; i++) { //loop data
        if (data[i]->nim == nim) return i; //yey nemu
    }
    return -1; // ga nemu notif  "tdk ditemukan"
}

// sorting dengan Bubble sort berdasarkan nim
void bubblesort(Mahasiswa* data[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) { //bandingkan -i
            if (data[j]->nim > data[j+1]->nim) { // j > tuker tempat
                Mahasiswa* tukar = data[j]; //proses tukar
                data[j] = data[j+1];
                data[j+1] = tukar;
            }
        }
    }
}

// Input data, update jika NIM sudah ada
void inputdata() {
    Mahasiswa* data[100]; //pointer dgn data max 100
    int n = baca(data); //simpan dan baca data

    Mahasiswa m; //m for mhs
    cout << "\nInput Data Mahasiswa\n";
    cin.ignore(); 
    cout << "Nama             : "; 
    cin.getline(m.nama, 50); //max 50 karakter
    cout << "Jenis Kelamin    : "; 
    cin.getline(m.jenis_kelamin, 10); //max 10 karakter

    // format tgl lahir: 20 Mei 2025
    int tgl, thn;
    char bln[10]; //max 10 karakter
    cout << "Tanggal Lahir\n";
    cout << "Tanggal (angka) : "; 
    cin >> tgl;
    cout << "Bulan (huruf)   : "; 
    cin >> ws; 
    cin.getline(bln, 10); //max 10 karakter
    cout << "Tahun (angka)   : "; 
    cin >> thn;
    // Gabungkan ke string tanggal_lahir
    snprintf(m.tanggal_lahir, sizeof(m.tanggal_lahir), "%d %s %d", tgl, bln, thn);

    // Input NIM, cek duplikasi, jika ada ulangi input
    while (true) { 
        cout << "NIM             : "; 
        cin >> m.nim;
        int idx = cari(data, n, m.nim); //cek nim kllo ada
        if (idx != -1) { //klo ada input ulang
            cout << "NIM sudah ada, silakan input ulang!\n";
        } else {
            break;
        }
    }
    cout << "Semester        : "; 
    cin >> m.semester; 
    cin.ignore();
    cout << "Prodi           : "; 
    cin.getline(m.prodi, 30); //max 30 karakter
    cout << "Fakultas        : "; 
    cin.getline(m.fakultas, 30); //max 30 karakter

    // Validasi IPK rentan 0-4 dan bisa desimal dgn titik
    float ipkInput;
    do {
        cout << "IPK (ex:0.0)    : "; 
        cin >> ipkInput; 
        cin.ignore();
        if (ipkInput < 0.0f || ipkInput > 4.0f) { //validasi ipk hanya 0-4
            cout << "IPK harus di antara 0 dan 4!\n";
        }
    } while (ipkInput < 0.0f || ipkInput > 4.0f); //input ulang
    m.ipk = ipkInput;

    // Simpan ke file (append)
    ofstream file("data_mahasiswa.dat", ios::binary | ios::app); //buka file
    if (file.is_open()) {
        file.write(reinterpret_cast<char*>(&m), sizeof(Mahasiswa)); // tulis file
        file.close(); //tutup fila
        cout << "Data berhasil disimpan!\n";
    } else {
        cout << "Gagal membuka file!\n";
    }
    for (int i = 0; i < n; i++) delete data[i]; //bersikhan memori
}

// tampil data mhs sesuai input data pake Fungsi rekursif
void tampilkanurutinputrekursif(ifstream& file, int data = 1) { 
    Mahasiswa m;
    if (!file.read(reinterpret_cast<char*>(&m), sizeof(Mahasiswa))) {
        return; // stop rekursi
    }
    cout << "----------------------------------\n";
    cout << "Data ke " << data << endl;
    cout << "Nama         : " << m.nama << endl;
    cout << "Jenis Kelamin: " << (m.jenis_kelamin[0] == 'L' ? "Laki-laki" : "Perempuan") << endl;
    cout << "Tanggal Lahir: " << m.tanggal_lahir << endl;
    cout << "NIM          : " << m.nim << endl;
    cout << "Semester     : " << m.semester << endl;
    cout << "Prodi        : " << m.prodi << endl;
    cout << "Fakultas     : " << m.fakultas << endl;
    cout << "IPK          : " << fixed << setprecision(2) << m.ipk << endl;
    if (m.semester >= 6 && m.ipk >= 3.0) //syarat layak
        cout << "Status       : Layak ikut KKN\n";
    else
        cout << "Status       : Belum bisa ikut KKN\n";
    cout << "----------------------------------\n";
    tampilkanurutinputrekursif (file, data + 1); //panggil kembali
}

// Tampilkan seluruh data (urutan input)
void tampilkanDataUrutInput() {
    ifstream file("data_mahasiswa.dat", ios::binary);
    if (!file.is_open()) {
        cout << "File tidak valid.\n";
        return;
    }
    cout << "\nData Mahasiswa (urutan input):\n"; //file bisa dibaca
    tampilkanurutinputrekursif (file, 1);
    file.close();
    cout << "\nTekan Enter ke submenu..."; 
    cin.get();
}

// Tampilkan seluruh data (urut NIM)
void tampilurutnim() {
    Mahasiswa* data[100];
    int n = baca(data);
    if (n == 0) { //baca all data
        cout << "File tidak valid.\n";
        return;
    }
    bubblesort(data, n);
    cout << "\nData Mahasiswa (urut NIM):\n";
    for (int i = 0; i < n; i++) { //urutkan pake nim
        cout << "----------------------------------\n";
        cout << "Data ke " << i+1 << endl;
        cout << "Nama         : " << data[i]->nama << endl;
        cout << "Jenis Kelamin: " << data[i]->jenis_kelamin << endl;
        cout << "Tanggal Lahir: " << data[i]->tanggal_lahir << endl;
        cout << "NIM          : " << data[i]->nim << endl;
        cout << "Semester     : " << data[i]->semester << endl;
        cout << "Prodi        : " << data[i]->prodi << endl;
        cout << "Fakultas     : " << data[i]->fakultas << endl;
        cout << "IPK          : " << fixed << setprecision(2) << data[i]->ipk << endl;
        if (data[i]->semester >= 6 && data[i]->ipk >= 3.0)
            cout << "Status       : Layak ikut KKN\n";
        else
            cout << "Status       : Belum bisa ikut KKN\n";
    }
    for (int i = 0; i < n; i++) delete data[i];
    cout << "\nTekan Enter untuk kembali ke menu utama..."; 
    cin.get();
}

// Submenu tampilkan data
void tampildata() {
    int sub;
    do {
        cout << "\n======================================\n";
        cout << "        SUBMENU TAMPILKAN DATA        \n";
        cout << "======================================\n";
        cout << "1. Tampilkan seluruh data (urut input)\n";
        cout << "2. Tampilkan data (nim dgn ascending)\n";
        cout << "3. Kembali ke menu utama\n";
        cout << "======================================\n";
        cout << "Pilih: ";
        cin >> sub; cin.ignore();
        if (sub == 1) tampilkanDataUrutInput(); //syarat
        else if (sub == 2) tampilurutnim();
        else if (sub == 3) break;
        else cout << "Pilihan tidak valid!\n";
    } while (sub != 3);
}

// Fungsi cari dengan sequential berdasar nim
void caridata() {
    ifstream file("data_mahasiswa.dat", ios::binary);
    if (!file.is_open()) { //buka file
        cout << "File tidak valid.\n";
        return;
    }
    int cariNIM;
    cout << "\nMasukkan NIM yang dicari: "; cin >> cariNIM; cin.ignore();
    Mahasiswa m;
    bool ditemukan = false; //cari nim
    while (file.read(reinterpret_cast<char*>(&m), sizeof(Mahasiswa))) {
        if (m.nim == cariNIM) {
            cout << "\nData Ditemukan\n";
            cout <<"----------------------------------\n";
            cout << "Nama         : " << m.nama << endl;
            cout << "Jenis Kelamin: " << m.jenis_kelamin << endl;
            cout << "Tanggal Lahir: " << m.tanggal_lahir << endl;
            cout << "NIM          : " << m.nim << endl;
            cout << "Semester     : " << m.semester << endl;
            cout << "Prodi        : " << m.prodi << endl;
            cout << "Fakultas     : " << m.fakultas << endl;
            cout << "IPK          : " << fixed << setprecision(2) << m.ipk << endl;
            if (m.semester >= 6 && m.ipk >= 3.0) //syarat lolos
                cout << "Status       : Layak ikut KKN\n";
            else
                cout << "Status       : Belum bisa ikut KKN\n";
                cout <<"----------------------------------\n";
            ditemukan = true; // nemu nim cocok
            break;
        }
    }
    if (!ditemukan) {
        cout << "\nData tidak ditemukan.\n";
    }
    file.close();
    cout << "\nTekan Enter untuk kembali ke menu utama..."; 
    cin.get();
}

// Fungsi tampilkan mahasiswa yang layak ikut KKN
void tampilkanlayakKKN() {
    ifstream file("data_mahasiswa.dat", ios::binary);
    if (!file.is_open()) {
        cout << "File tidak valid.\n";
        return;
    }
    Mahasiswa m;
    int no = 1;
    cout << "\n--- Layak ikut KKN ---\n";
    bool ada = false; //cek ada ato ga
    while (file.read(reinterpret_cast<char*>(&m), sizeof(Mahasiswa))) {
        if (m.semester >= 6 && m.ipk >= 3.0) { //syarat
            cout << "Data ke " << no++ << endl;
            cout << "Nama : " << m.nama << endl;
            cout << "NIM  : " << m.nim << endl;
            cout << "IPK  : " << fixed << setprecision(2) << m.ipk << endl;
              cout << "----------------------\n";
            ada = true;
        }
    }
    if (!ada) cout << "Tidak ada mahasiswa yang layak ikut KKN.\n"; 
    file.close();
    cout << "\nTekan Enter untuk kembali ke menu utama..."; 
    cin.get();
}

// Fungsi edit data mahasiswa yg diinput
void editdata() {
    Mahasiswa* data[100];
    int n = baca(data);
    if (n == 0) {// data yg dibaca
        cout << "Tidak ada data untuk diedit.\n";
        return;
    }
    int cariNIM;
    cout << "\nMasukkan NIM mahasiswa yang akan diedit: "; 
    cin >> cariNIM; 
    cin.ignore();
    int idx = cari(data, n, cariNIM); //input nim cari
    if (idx == -1) { //cari nim
        cout << "Data dengan NIM tersebut tidak ditemukan.\n";
        for (int i = 0; i < n; i++) delete data[i];
        return;
    }
    Mahasiswa* m = data[idx]; //nemu nim
    cout << "\nData lama:\n";
    cout << "Nama           : " << m->nama << endl;
    cout << "Jenis Kelamin  : " << m->jenis_kelamin << endl;
    cout << "Tanggal Lahir  : " << m->tanggal_lahir << endl;
    cout << "Semester       : " << m->semester << endl;
    cout << "Prodi          : " << m->prodi << endl;
    cout << "Fakultas       : " << m->fakultas << endl;
    cout << "IPK            : " << fixed << setprecision(2) << m->ipk << endl;

    cout << "\n------ Edit Data ------\n";
    cout << "Nama           : "; 
    cin.ignore(); cin.getline(m->nama, 50);
    char jk;
    do {
    cout << "J.Kelamin (L/P): ";
    cin >> jk;
    jk = toupper(jk);
    if (jk != 'L' && jk != 'P') {
        cout << "Input hanya boleh 'L' (Laki-laki) atau 'P' (Perempuan)!\n";
    }
    } while (jk != 'L' && jk != 'P');
    m->jenis_kelamin[0] = jk;
    m->jenis_kelamin[1] = '\0';
    cin.ignore();
    int tgl, thn;
    char bulan[10];
    cout << "Tanggal Lahir\n";
    cout << "Tanggal (angka): "; 
    cin >> tgl;
    cout << "Bulan (huruf)  : "; 
    cin >> ws; cin.getline(bulan, 10);
    cout << "Tahun  (angka) : "; 
    cin >> thn;
    snprintf(m->tanggal_lahir, sizeof(m->tanggal_lahir), "%d %s %d", tgl, bulan, thn); //gabung tgl
    cout << "Semester       : "; 
    cin >> m->semester; 
    cin.ignore();
    cout << "Prodi          : "; 
    cin.getline(m->prodi, 30);
    cout << "Fakultas       : "; 
    cin.getline(m->fakultas, 30);
    float ipkInput;
    do {
        cout << "IPK            : "; 
        cin >> ipkInput; 
        cin.ignore();
        if (ipkInput < 0.0f || ipkInput > 4.0f) { //syarat ip
            cout << "IPK harus di antara 0 dan 4!\n";
        }
    } while (ipkInput < 0.0f || ipkInput > 4.0f); //input ukang 0-4
    m->ipk = ipkInput;

    simpan(data, n); //berhsil update dan simpan
    cout << "\n-----------------------\n";
    cout << "Data berhasil diupdate!\n";
    for (int i = 0; i < n; i++) delete data[i];
}

// Fungsi hapus data mahasiswa
void hapusdata() {
    Mahasiswa* data[100];
    int n = baca(data);
    if (n == 0) { //baca data
        cout << "Tidak ada data untuk dihapus.\n";
        return;
    }
    int cariNIM;
    cout << "\nMasukkan NIM mahasiswa yang akan dihapus: "; 
    cin >> cariNIM; 
    cin.ignore();
    int idx = cari(data, n, cariNIM); //input nimcari
    if (idx == -1) { //nemu ga?
        cout << "Data dengan NIM tersebut tidak ditemukan.\n";
        for (int i = 0; i < n; i++) delete data[i];
        return;
    }
    // Hapus data pada index idx
    delete data[idx];//bersihkan memo
    for (int i = idx; i < n - 1; i++) {
        data[i] = data[i + 1];
    }
    n--;
    //sumpan yg dihapus lalu data setelahnya maju
    simpan(data, n);
    cout << "Data berhasil dihapus!\n";
    for (int i = 0; i < n; i++) delete data[i];
}

//menu utama
int main() {
    int pilihan;
    do {
        cout << "\n=====================\n";
        cout << "|    MENU  UTAMA    |\n";
        cout << "=====================\n";
        cout << "| 1. Input data     |\n";
        cout << "| 2. Tampilkan data |\n";
        cout << "| 3. Cari data      |\n";
        cout << "| 4. Data Layak KKN |\n";
        cout << "| 5. Edit data      |\n";
        cout << "| 6. Hapus data     |\n"; 
        cout << "| 7. Keluar         |\n";
        cout << "=====================\n";
        cout << "Pilih menu: ";
        cin >> pilihan; 
        cin.ignore();

        switch (pilihan) {
            case 1: inputdata(); break;
            case 2: tampildata(); break;
            case 3: caridata(); break;
            case 4: tampilkanlayakKKN(); break;
            case 5: editdata(); break;
            case 6: hapusdata(); break; 
            case 7: 
            cout << "Keluar dari program.\n"; break;
            default: 
            cout << "Pilihan tidak valid.\n";
        }
    } while (pilihan != 7);
    return 0;
}
