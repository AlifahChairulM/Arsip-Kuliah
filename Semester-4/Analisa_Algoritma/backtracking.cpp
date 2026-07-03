#include <iostream>
#include <vector>

using namespace std;

// Fungsi untuk mencetak konfigurasi papan catur (solusi)
void printSolusi(const vector<vector<int>>& papan, int N) {
    static int hitung = 1;
    cout << "--- Solusi ke-" << hitung++ << " ---\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (papan[i][j] == 1)
                cout << " Q "; // Q menandakan posisi Ratu
            else
                cout << " . "; // Titik menandakan kotak kosong
        }
        cout << "\n";
    }
    cout << "\n";
}

// Fungsi Pembatas (Bounding Function): Mengecek apakah posisi aman untuk menaruh Ratu
   bool isAman(const vector<vector<int>>& papan, int baris, int kolom, int N) {
    int i, j;

    // 1. Cek baris yang sama di sebelah kiri
    for (i = 0; i < kolom; i++) {
        if (papan[baris][i] == 1) return false;
    }

    // 2. Cek diagonal kiri atas
    for (i = baris, j = kolom; i >= 0 && j >= 0; i--, j--) {
        if (papan[i][j] == 1) return false;
    }

    // 3. Cek diagonal kiri bawah
    for (i = baris, j = kolom; j >= 0 && i < N; i++, j--) {
        if (papan[i][j] == 1) return false;
    }

    return true; // Mengembalikan true jika aman (memenuhi fungsi kriteria)
}

// Fungsi Rekursif Backtracking
bool selesaikanNQueensUtil(vector<vector<int>>& papan, int kolom, int N) {
    // Base Case: Jika semua Ratu sudah berhasil ditempatkan di setiap kolom
    if (kolom >= N) {
        printSolusi(papan, N);
        return true; 
    }

    bool adaSolusi = false;

    // Mencoba menempatkan Ratu di setiap baris pada kolom saat ini
    for (int i = 0; i < N; i++) {
        // Menerapkan Fungsi Pembatas
        if (isAman(papan, i, kolom, N)) {
            // Tempatkan Ratu (Kandidat Solusi)
            papan[i][kolom] = 1;

            // Rekursi untuk kolom berikutnya (Pencarian Mendalam / DFS)
            adaSolusi = selesaikanNQueensUtil(papan, kolom + 1, N) || adaSolusi;

            // RUNUT-BALIK (BACKTRACK): Jika jalur ini tidak mengarah ke solusi (Simpul Mati),
            // hapus kembali ratu dari posisi ini untuk mencoba kemungkinan lain.
            papan[i][kolom] = 0;
        }
    }

    return adaSolusi;
}

void selesaikanNQueens(int N) {
    // Inisialisasi matriks papan catur N x N dengan nilai 0 (kosong)
    vector<vector<int>> papan(N, vector<int>(N, 0));

    if (!selesaikanNQueensUtil(papan, 0, N)) {
        cout << "Tidak ada solusi yang ditemukan untuk N = " << N << "\n";
    }
}

int main() {
    int N;
    cout << "Masukkan nilai N (Ukuran Papan & Jumlah Ratu): ";
    cin >> N;
    
    cout << "\nMencari solusi untuk " << N << "-Queens...\n\n";
    selesaikanNQueens(N);
    
    return 0;
}