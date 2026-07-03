#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <iomanip>
#include <algorithm>

using namespace std;
using namespace chrono;

//algoritma bubble sort
void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

vector<int> generateRandomData(int size) {
    vector<int> data(size);
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 10000);
    
    for (int i = 0; i < size; i++) {
        data[i] = dis(gen);
    }
    return data;
}

double measureTime(vector<int> data) {
    auto start = high_resolution_clock::now();
    bubbleSort(data);
    auto end = high_resolution_clock::now();
    
    duration<double> diff = end - start;
    return diff.count();
}

//ststus untuk keterangan  berdasar waktu eksekusi
string getStatus(double time) {
    if (time < 1) return "Sangat Cepat";
    else if (time < 5) return "Cepat";
    else if (time < 10) return "Sedang";
    else if (time < 30) return "Lambat";
    else return "Sangat Lambat";
}

//menu utama
int main() {
    vector<int> sizes = {10, 100, 1000, 10000, 20000, 30000, 40000, 50000, 
                         60000, 70000, 80000, 90000, 100000};
    vector<double> times;
    
    cout << "===============================================================" << endl;
    cout << "TEST BUBBLE SORT - C++" << endl;
    cout << "===============================================================" << endl;
    cout << left << setw(15) << "Jumlah Data" 
         << setw(20) << "Waktu (detik)" 
         << "Keterangan" << endl;
    cout << "---------------------------------------------------------------" << endl;
    
    for (int size : sizes) {
        vector<int> data = generateRandomData(size);
        double execTime = measureTime(data);
        times.push_back(execTime);
        
        cout << left << setw(15) << size 
             << setw(20) << fixed << setprecision(6) << execTime 
             << getStatus(execTime) << endl;
    }
    
    cout << "===============================================================" << endl;
    
    return 0;
}