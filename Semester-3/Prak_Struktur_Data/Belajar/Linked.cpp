#include <iostream>
using namespace std;

struct infoNode{
    int id;
    char name[30];
};

struct Node{ //bikin node baru versi tunggal
    infoNode info;
    Node* next;
};

Node* head;
Node* tail;

void buatList(){
    head = (Node*)malloc(sizeof(Node));
    tail = (Node*)malloc(sizeof(Node));
    head->next = tail;
    head->info.id = -9999;
    tail->info.id = 9999;
    tail->next = NULL;
}

bool isListEmpty(){
    if (head->next == NULL){
        return true;
    }
    return false;
}

void sisipNode(infoNode infoBaru){
    Node* bantuan = head;
    Node* nodeBaru = (Node*)malloc(sizeof(Node));
    nodeBaru->info = infoBaru;
    while (bantuan->next->info.id < infoBaru.id){ //
        bantuan = bantuan->next;
    }
    nodeBaru->next = bantuan->next;
    bantuan->next = nodeBaru;
}

void hapusNode(int infoHapus){
    Node* bantuan = head;
    Node* bantuanHapus;
    if(isListEmpty()){
        cout << "Listnya kosong kak";
    }
    else{
        while(bantuan->next->info.id < infoHapus && bantuan->next != tail){
            bantuan = bantuan->next;
        }
        if (bantuan->next->info.id == infoHapus){
            bantuanHapus = bantuan->next;
            bantuan->next = bantuanHapus->next;
            free(bantuanHapus);
            cout << "Node telah dihapus dari list\n";
        }
        else{
            cout << "Node tidak ditemukan dalam list\n";
        }
    }
}

void cetakList(){
    Node* bantuan;
    bantuan = head->next;
    while(bantuan != tail){
        cout << "\nID\t: " << bantuan->info.id << endl;
        cout << "\nNama\t: " << bantuan->info.name << endl;
        bantuan = bantuan->next;
    }
}

int main(){
    int menu, num;
    char option;
    buatList();
    do{
        cout << "Pilih salah satu menu berikut!\n";
        cout << "1. Sisip Data\n";
        cout << "2. Hapus Data\n";
        cout << "3. Cetak Data\n";
        cin >> menu;
        switch (menu){
        case 1:    
            cout << "Mau masukin berapa data?"; cin >> num;
            if(num == 0 ){
                cout << "Invalid input\n";
            }
            else {
                for (int i = 0; i < num; i++){
                    infoNode newInfo;
                    cout << "\nID\t: "; cin >> newInfo.id;
                    cin.ignore();
                    cout << "\nName\t: "; cin.getline(newInfo.name, sizeof(newInfo.name));
                    cout << endl;
                    sisipNode(newInfo);
                }
            }
            break;
        case 2:
            int id;
            cout << "Masukkan info yang mau dihapus: "; cin >> id;
            hapusNode(id);
            break;
        case 3:
            cetakList();
            break;
        default:
            cout << "Pilihan menu tidak valid";
        }
        cout << "\nKembali ke menu utama? (y/n)"; cin >> option;
    } while(tolower(option) == 'y');
}