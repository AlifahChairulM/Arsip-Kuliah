#include <iostream>
#include <iomanip>  // Untuk mengatur tampilan output angka
using namespace std;

int main() {
    double a, b, c, d, det;
    
    // Input elemen matriks
    cout << " MENGHITUNG NILAI DARI SUATU MATRIKS ORDO 2X2\n ";
    cout << "Input matrik!!\n" ;
    cout << " Masukkan elemen a: ";
    cin >> a;
    cout << " Masukkan elemen b: ";
    cin >> b;
    cout << " Masukkan elemen c: ";
    cin >> c;
    cout << " Masukkan elemen d: ";
    cin >> d;

    // Rumus hitung det
    det = (a * d) - (b * c);

    // Tampilkan cara menghitung det
    cout << "\nHitung determinan: \n";
    cout << "det(A) = (a * d) - (b * c)\n";
    cout << "       = (" << a << " * " << d << ") - (" << b << " * " << c << ")\n";
    cout << "       = " << (a * d) << " - " << (b * c) << "\n";
    cout << "       = " << det << "\n\n";

    // Cek apakah det = nol
    if (det == 0) {
        cout << "Matriks tidak memiliki invers karena determinan = 0.\n";
    } else {

        // Rumus hitung matriks invers
        double inv_a = d / det;
        double inv_b = -b / det;
        double inv_c = -c / det;
        double inv_d = a / det;

        // Tampilkan cara menghitung matriks invers
        cout << "Hitung matriks invers:\n";
        cout << "A^-1 = (1/det(A)) * [ d  -b ]\n";
        cout << "                    [ -c  a ]\n\n";
        
        cout << "     = (1 / " << det << ")  *  [ " << d << "  " << -b << " ]\n";
        cout << "                    [ " << -c << "  " << a << " ]\n";
        cout << endl;

        // Tampilkan hasil akhir dalam format matriks dengan 2 angka di belakang koma
        cout << "Sehingga nilai matriks invers:\n";
        cout << fixed << setprecision(2);
        cout << "| " << setw(5) << inv_a << "  " << setw(5) << inv_b << " |\n";
        cout << "| " << setw(5) << inv_c << "  " << setw(5) << inv_d << " |\n";
        cout << endl;
    }

    return 0;
}
