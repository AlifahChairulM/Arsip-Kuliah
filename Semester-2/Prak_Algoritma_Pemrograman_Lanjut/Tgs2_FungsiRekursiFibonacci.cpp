#include <iostream>
using namespace std;
// Fungsi rekursif untuk menghitung bilangan Fibonacci dimulai dari 1
int fibonacci(int n)
{
    if (n == 1)
        return 1;
    if (n == 2)
        return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}
// Fungsi untuk menghitung jumlah deret Fibonacci hingga elemen ke-n
int sumFibonacci(int n)
{
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += fibonacci(i);
    }
    return sum;
}
// Fungsi rekursif untuk menghitung jumlah deret 1+2+3+...+n
int sumRecursive(int n)
{
    if (n == 1)
        return 1;
    return n + sumRecursive(n - 1);
}
int main()
{
    int choice;
    do
    {
        cout << "\nMenu Program:" << endl;
        cout << "1. Program Penjumlahan Fibonacci" << endl;
        cout << "2. Program Penjumlahan Deret (Iteratif & Rekursif)" << endl;
        cout << "3. Keluar" << endl;
        cout << "Pilih menu: ";
        cin >> choice;
        if (choice == 1)
        {
            int n;
            cout << "Masukkan jumlah bilangan Fibonacci: ";
            cin >> n;
            // Menampilkan deret Fibonacci dengan tanda "+"
            cout << "Deret Fibonacci: ";
            int totalFibonacci = 0;
            for (int i = 1; i <= n; i++)
            {
                int fibonacciValue = fibonacci(i);
                cout << fibonacciValue;
                totalFibonacci += fibonacciValue; // Menambahkan ke total
                if (i < n)
                    cout << " + "; // Menambahkan tanda + jika bukan elemen terakhir
            }
            // Menampilkan jumlah Fibonacci hingga elemen ke-n
            cout << "\nJumlah Fibonacci hingga elemen ke-" << n << " adalah " << totalFibonacci << endl;
        }
        else if (choice == 2)
        {
            int n, total = 0;
            cout << "Masukkan n: ";
            cin >> n;
            // Perhitungan menggunakan perulangan
            cout << "S(" << n << ") dengan iterasi: ";
            for (int i = 1; i <= n; i++)
            {
                cout << i;
                total += i; // Menambahkan elemen ke total
                if (i < n)
                    cout << " + "; // Menambahkan tanda + jika bukan elemen terakhir
            }
            cout << " = " << total << endl;
            // Perhitungan menggunakan rekursi
            cout << "S(" << n << ") dengan rekursi: " << sumRecursive(n) << endl;
            for (int i = 1; i <= n; i++)
            {
                cout << i;
                total += i; // Menambahkan elemen ke total
                if (i < n)
                    cout << " + "; // Menambahkan tanda + jika bukan elemen terakhir
            }
            cout << " = " << total << endl;
        }
    } while (choice != 3);
    cout << "Terima kasih!" << endl;
    return 0;
}