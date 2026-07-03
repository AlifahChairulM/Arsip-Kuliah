#include <iostream>
using namespace;
#define MAX 5

int depan = -1;
int belakang = -1;
int queue [MAX];

void buatqueue();
bool queuekosong ();
bool queuepenuh();
void enqueue(int info);
void dequeue();
void cetakqueue();

 int main(){
    buatqueue();
    cout << "sebelum queue" << endl;
    enqueue(90);
    enqueue(80);
    enqueue(10);
    enqueue(50);
    enqueue(7);
    enqueue(1);
    cetakqueue();
    cout << "queue setelah" << endl;
    dequeue();
    enqueue();
    cetakqueue();
 }

 void buatqueue(){
    depan = 0;
    belakang = 0;
 }

 bool  queuekosong(){
    if (depan == -1){
        return true;
    }
    return false;
 }

 bool queuepenuh(){
    if (belakang == MAX-1){
        return false;
    }
 }

 void enqueue(int info){
    if (queuepenuh()){
        cout <<" kebak bos\n";
        return;
    }
    if(queuekosong()){
        depan = 0;
    }
    belakang++;
    queue[belakang] = info;
 }

 void dequeue(){
    if (queuekosong()){
        cout << " Queue kosong, gak ono dihapus\n";
        return;
    }
    cout << queue [depan+1] <<  "berhasil didequeue\n";
    depan ++;

    if (depan >= belakang){
        depan = -1;
        belakang = -1;
    }
 }

 void cetakqueue(){
    if (queuekosong()){
        cout << "queue kosong, no antrian\n";
        return;
    }
    cout << "isi queue: ";
    for (int i = depan; i <= belakang; i++){
        cout << "queue" << i+1 << "." << queue[i+1] endl;
    }
 }