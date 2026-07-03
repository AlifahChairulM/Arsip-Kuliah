#include <iostream>
using namespace std;

int main() {
    char kalimat[] = "Pemrograman Dasar Turbo C";
    char *ptr = kalimat;

    cout << ptr << endl;// all kalimat
    cout << (ptr + 12) << endl; //dasar turbo c
    cout << (ptr + 18) << endl; //turbo c

    return 0;
}
