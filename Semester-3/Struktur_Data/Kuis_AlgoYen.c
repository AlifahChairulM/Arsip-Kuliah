#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAX_NODE 10
#define JARAK_INF 1000
#define MAX_RUTE 10
#define MAX_SEMENTARA 50

// ======================== STRUKTUR DATA ========================

typedef struct {
    int node[MAX_NODE];
    int jml_node;
    int total_jarak;
} Rute;

typedef struct {
    char nama[15];
} Node;

typedef struct {
    int jml_node;
    Node node[MAX_NODE];
    int jarak[MAX_NODE][MAX_NODE];
} Peta;

typedef struct {
    Rute rute[MAX_RUTE];
    int jml_rute;
} Hasil;

// ======================== UTILITAS DASAR ========================

/**
 * NodeDalamRute: Cek apakah node sudah ada dalam rute (pencegahan loop)
 * @param node: node yang dicek
 * @param r: rute yang diperiksa
 * @param sampai_index: batas index untuk pemeriksaan
 * @return: 1 jika node ada, 0 jika tidak
 */
int NodeDalamRute(int node, Rute r, int sampai_index) {
    for (int i = 0; i < sampai_index; i++) {
        if (r.node[i] == node) {
            return 1;
        }
    }
    return 0;
}

/**
 * cetakRute: Tampilkan rute dengan format A -> B -> C (total km)
 */
void cetakRute(Rute r, Peta p) {
    if (r.jml_node == 0) {
        printf("(rute kosong)");
        return;
    }
    for (int i = 0; i < r.jml_node; i++) {
        printf("%s", p.node[r.node[i]].nama);
        if (i < r.jml_node - 1) {
            printf(" -> ");
        }
    }
    printf(" (%d km)", r.total_jarak);
}

/**
 * salinRute: Salin data rute dari sumber ke tujuan
 */
void salinRute(Rute *tuju, Rute sumber) {
    tuju->jml_node = sumber.jml_node;
    tuju->total_jarak = sumber.total_jarak;
    for (int i = 0; i < sumber.jml_node; i++) {
        tuju->node[i] = sumber.node[i];
    }
}

/**
 * RuteSama: Cek apakah dua rute identik
 * @return: 1 jika sama, 0 jika berbeda
 */
int RuteSama(Rute r1, Rute r2) {
    if (r1.jml_node != r2.jml_node) return 0;
    for (int i = 0; i < r1.jml_node; i++) {
        if (r1.node[i] != r2.node[i]) return 0;
    }
    return 1;
}

/**
 * RuteDalamArray: Cek apakah rute sudah ada dalam array hasil
 * @param r: rute yang dicek
 * @param arr: array rute yang ada
 * @param count: jumlah rute dalam array
 * @return: 1 jika ada, 0 jika tidak
 */
int RuteDalamArray(Rute r, Rute arr[], int count) {
    for (int i = 0; i < count; i++) {
        if (RuteSama(r, arr[i])) {
            return 1;
        }
    }
    return 0;
}

/**
 * tampilDetailJarak: Tampilkan detail jarak setiap edge dalam rute
 */
void tampilDetailJarak(Rute r, Peta p) {
    printf("  Detail jarak:\n");
    for (int i = 0; i < r.jml_node - 1; i++) {
        int dari = r.node[i];
        int ke = r.node[i + 1];
        int jarak = p.jarak[dari][ke];
        printf("    %s -> %s: %d km\n", p.node[dari].nama, p.node[ke].nama, jarak);
    }
}

// ======================== ALGORITMA DIJKSTRA ========================

/**
 * cariDijkstra: Cari shortest path dari start ke end
 * 
 * LOGIKA:
 * 1. Inisialisasi dist[i]=INF kecuali dist[start]=0
 * 2. Loop V kali:
 *    - Pilih node a dengan dist terkecil yang belum visited
 *    - Tandai a sebagai visited
 *    - Update dist tetangga v: jika dist[a]+jarak[a][v] < dist[v]
 * 3. Rekonstruksi rute dari end mengikuti prev[] ke start
 * 
 * @param p: peta/graf
 * @param start: node awal
 * @param end: node tujuan
 * @param blokir: matriks edge yang dilarang (1=blokir, 0=boleh)
 * @return: Rute hasil (jml_node=0 jika tidak ditemukan)
 */
Rute cariDijkstra(Peta p, int start, int end, int blokir[MAX_NODE][MAX_NODE]) {
    int dist[MAX_NODE], prev[MAX_NODE], visited[MAX_NODE] = {0};
    Rute hasil;
    hasil.jml_node = 0;
    hasil.total_jarak = JARAK_INF;

    // ===== INISIALISASI =====
    for (int i = 0; i < p.jml_node; i++) {
        dist[i] = JARAK_INF;
        prev[i] = -1;
    }
    dist[start] = 0;

    // ===== LOOP UTAMA DIJKSTRA =====
    for (int count = 0; count < p.jml_node; count++) {
        // Pilih node dengan dist minimum yang belum visited
        int a = -1;
        for (int v = 0; v < p.jml_node; v++) {
            if (!visited[v] && (a == -1 || dist[v] < dist[a])) {
                a = v;
            }
        }

        // Cek kondisi berhenti
        if (a == -1 || dist[a] == JARAK_INF) break;  // Semua reachable sudah dikunjungi
        if (a == end) break;                          // Tujuan sudah dicapai (early exit)
        
        visited[a] = 1;

        // ===== RELAX EDGE =====
        for (int v = 0; v < p.jml_node; v++) {
            // Cek: v belum visited, ada edge, tidak diblokir
            if (!visited[v] && p.jarak[a][v] != JARAK_INF && !blokir[a][v]) {
                int alt = dist[a] + p.jarak[a][v];
                if (alt < dist[v]) {
                    dist[v] = alt;
                    prev[v] = a;
                }
            }
        }
    }

    // ===== REKONSTRUKSI RUTE =====
    if (dist[end] != JARAK_INF) {
        hasil.total_jarak = dist[end];

        // Trace balik dari end ke start mengikuti prev[]
        int current = end;
        while (current != -1) {
            hasil.node[hasil.jml_node++] = current;
            current = prev[current];
        }

        // Balik urutan (dari start ke end)
        for (int i = 0; i < hasil.jml_node / 2; i++) {
            int temp = hasil.node[i];
            hasil.node[i] = hasil.node[hasil.jml_node - 1 - i];
            hasil.node[hasil.jml_node - 1 - i] = temp;
        }
    }

    return hasil;
}

// ======================== ALGORITMA YEN ========================

/**
 * cariYen: Cari K rute terpendek berbeda menggunakan Algoritma Yen
 * 
 * ALUR LENGKAP:
 * 
 * TAHAP 1: RUTE PERTAMA
 *   - Panggil Dijkstra(dari, ke) tanpa blokir
 *   - Simpan hasil sebagai Rute 1
 * 
 * TAHAP 2: RUTE TAMBAHAN (K=2 sampai t)
 *   Untuk setiap K, lakukan:
 *   
 *   A. LOOP SETIAP NODE CABANG (i=0 sampai jml_node-2 dari Rute K-1):
 *      
 *      1. Setup Blokir:
 *         - Untuk setiap rute yang sudah ada (j=0..K-1):
 *           - Cari edge dari node_cabang di rute[j]
 *           - Blokir edge tersebut
 *      
 *      2. Cari Rute Cabang:
 *         - Dijkstra(node_cabang, ke) dengan blokir
 *      
 *      3. Bentuk Calon:
 *         - Rute Akar = bagian Rute K-1 dari start sampai node_cabang
 *         - Rute Cabang = hasil Dijkstra dari node_cabang ke end
 *         - Gabung: Calon = Akar + Cabang
 *         - Cek loop: setiap node baru tidak boleh duplikat
 *         - Hitung total jarak calon
 *      
 *      4. Validasi & Simpan Calon:
 *         - Cek: total_jarak != INF
 *         - Cek: calon tidak ada di hasil.rute[]
 *         - Cek: calon tidak ada di array calon[]
 *         - Jika valid: simpan ke calon[jml_calon++]
 *   
 *   B. PILIH CALON TERBAIK:
 *      - Dari semua calon yang ditemukan
 *      - Cari yang total_jaraknya paling kecil
 *      - Simpan ke hasil.rute[hasil.jml_rute++]
 *      - Hapus dari array calon[]
 *      - Jika tidak ada calon: break (tidak bisa lanjut)
 * 
 * @param p: peta/graf
 * @param dari: node asal
 * @param ke: node tujuan
 * @param t: jumlah rute yang dicari (K)
 * @return: Hasil berisi hingga t rute terpendek
 */
Hasil cariYen(Peta p, int dari, int ke, int t) {
    Hasil hasil;
    hasil.jml_rute = 0;

    Rute calon[MAX_SEMENTARA];
    int jml_calon = 0;

    printf("\n========== MEMULAI ALGORITMA YEN ==========\n");
    printf("Mencari %d rute terpendek dari %s ke %s\n\n", 
           t, p.node[dari].nama, p.node[ke].nama);

    // ===== TAHAP 1: RUTE PERTAMA =====
    printf("[TAHAP 1] Cari Rute Pertama\n");
    printf("Memanggil: Dijkstra(%s, %s) tanpa blokir\n", 
           p.node[dari].nama, p.node[ke].nama);

    int blokir_kosong[MAX_NODE][MAX_NODE] = {0};
    Rute rute_pertama = cariDijkstra(p, dari, ke, blokir_kosong);

    if (rute_pertama.jml_node == 0) {
        printf("\n[ERROR] Tidak ada rute dari %s ke %s!\n", 
               p.node[dari].nama, p.node[ke].nama);
        return hasil;
    }

    hasil.rute[hasil.jml_rute++] = rute_pertama;
    printf("✓ Rute 1 ditemukan: ");
    cetakRute(rute_pertama, p);
    printf("\n\n");

    // ===== TAHAP 2: RUTE TAMBAHAN =====
    for (int k = 1; k < t && hasil.jml_rute == k; k++) {
        Rute rute_sebelum = hasil.rute[k - 1];

        printf("[TAHAP 2.%d] Cari Rute %d\n", k, k + 1);
        printf("Rute sebelumnya: ");
        cetakRute(rute_sebelum, p);
        printf("\n");
        printf("Node cabang yang akan dicoba: ", k + 1);
        for (int i = 0; i < rute_sebelum.jml_node - 1; i++) {
            printf("%s", p.node[rute_sebelum.node[i]].nama);
            if (i < rute_sebelum.jml_node - 2) printf(", ");
        }
        printf("\n\n");

        // ===== LOOP SETIAP NODE CABANG =====
        for (int i = 0; i < rute_sebelum.jml_node - 1; i++) {
            int node_cabang = rute_sebelum.node[i];

            printf("  [Node Cabang %d] %s\n", i + 1, p.node[node_cabang].nama);

            // ===== SETUP BLOKIR =====
            int blokir[MAX_NODE][MAX_NODE] = {0};
            printf("    Blokir edge:\n");

            for (int j = 0; j < k; j++) {
                Rute rute_ada = hasil.rute[j];

                for (int m = 0; m < rute_ada.jml_node - 1; m++) {
                    if (rute_ada.node[m] == node_cabang) {
                        int node_berikut = rute_ada.node[m + 1];
                        blokir[node_cabang][node_berikut] = 1;
                        printf("      - %s -> %s (dari Rute %d)\n", 
                               p.node[node_cabang].nama, 
                               p.node[node_berikut].nama, 
                               j + 1);
                        break;
                    }
                }
            }

            // ===== CARI RUTE CABANG =====
            printf("    Memanggil: Dijkstra(%s, %s) dengan blokir\n", 
                   p.node[node_cabang].nama, p.node[ke].nama);

            Rute rute_cabang = cariDijkstra(p, node_cabang, ke, blokir);

            if (rute_cabang.jml_node == 0) {
                printf("    → Tidak ada rute cabang\n\n");
                continue;
            }

            printf("    → Rute cabang: ");
            cetakRute(rute_cabang, p);
            printf("\n");

            // ===== BENTUK CALON RUTE =====
            Rute calon_baru;
            calon_baru.jml_node = 0;
            calon_baru.total_jarak = 0;

            // Rute akar (dari start sampai node_cabang)
            printf("    Bentuk calon:\n");
            printf("      Akar (rute lama): ");
            for (int j = 0; j <= i; j++) {
                calon_baru.node[calon_baru.jml_node++] = rute_sebelum.node[j];
                printf("%s", p.node[rute_sebelum.node[j]].nama);
                if (j <= i - 1) printf(" -> ");

                if (j > 0) {
                    calon_baru.total_jarak += 
                        p.jarak[rute_sebelum.node[j - 1]][rute_sebelum.node[j]];
                }
            }
            printf(" (jarak akar: %d)\n", calon_baru.total_jarak);

            // Rute cabang dengan cek loop
            printf("      Cabang (rute baru): ");
            int loop_terdeteksi = 0;
            for (int j = 1; j < rute_cabang.jml_node; j++) {
                int node_tambah = rute_cabang.node[j];

                // Cek duplikat (pencegahan loop)
                if (NodeDalamRute(node_tambah, calon_baru, calon_baru.jml_node)) {
                    printf("\n      [LOOP!] Node %s sudah ada dalam akar → calon DITOLAK\n", 
                           p.node[node_tambah].nama);
                    loop_terdeteksi = 1;
                    break;
                }

                calon_baru.node[calon_baru.jml_node++] = node_tambah;
                printf("%s", p.node[node_tambah].nama);
                if (j < rute_cabang.jml_node - 1) printf(" -> ");

                calon_baru.total_jarak += 
                    p.jarak[rute_cabang.node[j - 1]][rute_cabang.node[j]];
            }
            printf(" (jarak cabang: %d)\n", 
                   calon_baru.total_jarak - 
                   (i > 0 ? p.jarak[rute_sebelum.node[i-1]][rute_sebelum.node[i]] : 0));

            if (loop_terdeteksi) {
                printf("    ✗ Calon ditolak (ada loop)\n\n");
                continue;
            }

            // ===== VALIDASI CALON =====
            printf("    Validasi calon:\n");
            printf("      Total jarak: %d\n", calon_baru.total_jarak);
            printf("      Duplikat di hasil? %s\n", 
                   RuteDalamArray(calon_baru, hasil.rute, hasil.jml_rute) ? "YA" : "TIDAK");
            printf("      Duplikat di calon[]? %s\n", 
                   RuteDalamArray(calon_baru, calon, jml_calon) ? "YA" : "TIDAK");

            if (calon_baru.total_jarak != JARAK_INF &&
                !RuteDalamArray(calon_baru, hasil.rute, hasil.jml_rute) &&
                !RuteDalamArray(calon_baru, calon, jml_calon)) {

                calon[jml_calon++] = calon_baru;
                printf("    ✓ Calon diterima dan disimpan\n");
                printf("      Calon #%d: ", jml_calon);
                cetakRute(calon_baru, p);
                printf("\n");
            } else {
                printf("    ✗ Calon ditolak (jarak INF atau duplikat)\n");
            }
            printf("\n");
        }

        // ===== PILIH CALON TERBAIK =====
        printf("  [Pilih Calon] Total calon ditemukan: %d\n", jml_calon);

        if (jml_calon > 0) {
            printf("    Daftar calon:\n");
            for (int i = 0; i < jml_calon; i++) {
                printf("      Calon %d: ", i + 1);
                cetakRute(calon[i], p);
                printf("\n");
            }

            int idx_terbaik = 0;
            for (int i = 1; i < jml_calon; i++) {
                if (calon[i].total_jarak < calon[idx_terbaik].total_jarak) {
                    idx_terbaik = i;
                }
            }

            printf("    → PILIH: Calon %d (jarak %d terkecil)\n", 
                   idx_terbaik + 1, calon[idx_terbaik].total_jarak);

            hasil.rute[hasil.jml_rute++] = calon[idx_terbaik];
            printf("\n✓ Rute %d dipilih: ", k + 1);
            cetakRute(calon[idx_terbaik], p);
            printf("\n\n");

            // Hapus calon yang dipilih
            for (int i = idx_terbaik; i < jml_calon - 1; i++) {
                calon[i] = calon[i + 1];
            }
            jml_calon--;

        } else {
            printf("    [STOP] Tidak ada calon ditemukan, pencarian dihentikan\n\n");
            break;
        }
    }

    printf("========== ALGORITMA YEN SELESAI ==========\n");
    printf("Total rute ditemukan: %d dari %d yang diminta\n\n", hasil.jml_rute, t);

    return hasil;
}

// ======================== FUNGSI PETA ========================

void buatPeta(Peta *p) {
    p->jml_node = 10;
    char *nama_SMA[] = {
        "TELADAN", "SMADA", "PADMANABA", "PATBHE", "MACHE",
        "NAMCHE", "SMAVEN", "DELAYOTA", "GANZA", "SMUTEN"
    };

    for (int i = 0; i < p->jml_node; i++) {
        strcpy(p->node[i].nama, nama_SMA[i]);
    }

    for (int i = 0; i < p->jml_node; i++) {
        for (int j = 0; j < p->jml_node; j++) {
            p->jarak[i][j] = (i == j) ? 0 : JARAK_INF;
        }
    }

    // Isi jarak antar SMA
    p->jarak[0][1] = p->jarak[1][0] = 2;
    p->jarak[0][9] = p->jarak[9][0] = 3;
    p->jarak[0][3] = p->jarak[3][0] = 5;
    p->jarak[1][2] = p->jarak[2][1] = 4;
    p->jarak[1][4] = p->jarak[4][1] = 6;
    p->jarak[2][4] = p->jarak[4][2] = 3;
    p->jarak[2][6] = p->jarak[6][2] = 7;
    p->jarak[3][4] = p->jarak[4][3] = 4;
    p->jarak[3][5] = p->jarak[5][3] = 6;
    p->jarak[4][5] = p->jarak[5][4] = 2;
    p->jarak[4][6] = p->jarak[6][4] = 5;
    p->jarak[5][7] = p->jarak[7][5] = 3;
    p->jarak[5][8] = p->jarak[8][5] = 8;
    p->jarak[6][7] = p->jarak[7][6] = 4;
    p->jarak[7][8] = p->jarak[8][7] = 5;
    p->jarak[8][9] = p->jarak[9][8] = 6;
}

void tampilDaftarSMA(Peta p) {
    printf("\n=========================================\n");
    printf("            DAFTAR KODE SMA\n");
    printf("=========================================\n");
    for (int i = 0; i < p.jml_node; i++) {
        printf("  %d: %s\n", i, p.node[i].nama);
    }
    printf("=========================================\n");
}

void menuCariRute(Peta p) {
    int dari, ke, t;
    printf("\nMasukkan data pencarian:\n");
    printf("Kode SMA asal   : ");
    scanf("%d", &dari);
    printf("Kode SMA tujuan : ");
    scanf("%d", &ke);
    printf("Jumlah rute     : ");
    scanf("%d", &t);

    if (dari < 0 || dari >= p.jml_node || ke < 0 || ke >= p.jml_node) {
        printf("\n[ERROR] Kode SMA tidak valid! Harus antara 0 dan %d\n", p.jml_node - 1);
        return;
    }
    if (t < 1 || t > MAX_RUTE) {
        printf("\n[ERROR] Jumlah rute harus antara 1 dan %d!\n", MAX_RUTE);
        return;
    }
    if (dari == ke) {
        printf("\n[ERROR] SMA asal dan tujuan tidak boleh sama!\n");
        return;
    }

    Hasil hasil = cariYen(p, dari, ke, t);

    printf("\n===============================================\n");
    printf("              HASIL AKHIR\n");
    printf("===============================================\n");

    if (hasil.jml_rute == 0) {
        printf("Tidak ada rute ditemukan!\n");
        return;
    }

    for (int i = 0; i < hasil.jml_rute; i++) {
        printf("\n[RUTE %d]\n", i + 1);
        printf("Jarak Total: %d km\n", hasil.rute[i].total_jarak);
        printf("Jalur: ");
        cetakRute(hasil.rute[i], p);
        printf("\n");
        tampilDetailJarak(hasil.rute[i], p);
        printf("-----------------------------------------------\n");
    }
}

// ======================== MAIN ========================

int main() {
    Peta p;
    int peta_siap = 0;

    printf("===============================================\n");
    printf("   ALGORITMA YEN - PENCARIAN K RUTE TERPENDEK\n");
    printf("         Peta SMA Negeri Yogyakarta\n");
    printf("===============================================\n");

    int pil;
    do {
        printf("\nMENU UTAMA:\n");
        printf("1. Tampilkan daftar SMA\n");
        printf("2. Cari Rute Terpendek (Algoritma Yen)\n");
        printf("3. Keluar\n");
        printf("Pilihan (1-3): ");
        scanf("%d", &pil);

        switch (pil) {
        case 1:
            if (!peta_siap) {
                buatPeta(&p);
                peta_siap = 1;
                printf("\nPeta berhasil dibuat dengan %d SMA\n", p.jml_node);
            }
            tampilDaftarSMA(p);
            break;
        case 2:
            if (!peta_siap) {
                buatPeta(&p);
                peta_siap = 1;
                printf("\nPeta berhasil dibuat dengan %d SMA\n", p.jml_node);
                tampilDaftarSMA(p);
            }
            menuCariRute(p);
            break;
        case 3:
            printf("\nTerima kasih telah menggunakan program ini!\n");
            break;
        default:
            printf("\n[ERROR] Pilihan tidak valid! Masukkan 1-3\n");
        }
    } while (pil != 3);

    return 0;
}