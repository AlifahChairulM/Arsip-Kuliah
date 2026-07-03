# include <iostream>
using namespace std;

struct Node{ //buat node
    int info;
    Node* next;
};

Node* head ; //dekla head and tail
Node* tail ;

void buatlist(){
    head = NULL;
    tail = head;
}

bool isiListEmpty(){ //cek list kosong
    if(head == NULL)
        return true;
    else{
        return false;
    }
}

void sisipNode(int infoBaru){ //sisip node di akhir
    Node* nodeBaru = (Node*)malloc(sizeof(Node)); //alokasi memori
    nodeBaru->info = infoBaru; //isi info
    nodeBaru->next = NULL; //next null

    if(isiListEmpty()){ //cek list kosong
        head = nodeBaru; //head dan tail sama dengan baru
        tail = nodeBaru;

    }else if(nodeBaru->info <= head->info){ //sisip di awal
        tail -> next = nodeBaru; //next tail sama dengan baru
        head = nodeBaru; //head sama dengan baru

    }
    else if(nodeBaru->info >= tail->info){ //sisip di akhir
        tail -> next = nodeBaru; //next tail sama dengan baru
        tail = nodeBaru; //tail sama dengan baru
    }
    else{ //sisip di tengah
        Node* bantu = head; //bantu mulai dari head
        while(bantu->next->info < nodeBaru->info){ //looping selama info bantu next lebih kecil dari info baru
            bantu = bantu->next; //bantu geser ke next
        }
    }
}

void sisipDepan(int infoBaru){ //sisip node di depan
    Node* nodeBaru = (Node*)malloc(sizeof(Node)); //alokasi memori
    nodeBaru->info = infoBaru; //isi info
    nodeBaru->next = NULL; //next null
    if(isiListEmpty()){ //cek list kosong
        head = nodeBaru; //head dan tail sama dengan baru
        tail = nodeBaru;
    }
    else{ //sisip di depan
        nodeBaru->next = head; //next baru sama dengan head
    }
        head = nodeBaru; //head sama dengan baru
}

void sisipBelakang(int infoBaru){ //sisip node di belakang
    Node* nodeBaru = (Node*)malloc(sizeof(Node)); //alokasi memori
    nodeBaru->info = infoBaru; //isi info
    nodeBaru->next = NULL; //next null
    if(isiListEmpty()){ //cek list kosong
        head = nodeBaru; //head dan tail sama dengan baru
        tail = nodeBaru;
    }
    else{ //sisip di belakang
        nodeBaru-> next = tail; //next baru sama dengan tail
    }
        tail = nodeBaru; //tail sama dengan baru
}

void sisipTengah(int infoBaru){ //sisip node di tengah
    Node* nodeBaru = (Node*)malloc(sizeof(Node)); //alokasi memori
    nodeBaru->info = infoBaru; //isi info
    nodeBaru->next = NULL; //next null
    Node* bantuan = head; //bantu mulai dari head
    while (bantuan -> next -> info< nodeBaru ->info){ //cek list kosong
        bantuan = bantuan -> next; //bantu geser ke next
    }
    nodeBaru -> next = bantuan -> next; //next baru sama dengan bantu next
    bantuan -> next = nodeBaru; //bantu next sama dengan baru
}

void displyList(){
    Node* bantu =head;
    while (bantu != NULL){ //looping selama bantu tidak null ///berhenti klo bntuan = nulll
        cout << bantu->info << " "; //tampilkan info bantu
        bantu = bantu->next; //bantu geser ke next
    }
    cout << endl;
}

void hapusNode(int infoBaru){
    Node* bantu = head; //hapus mulai dari head
    if(isiListEmpty()){ //cek list kosong
        cout << "List kosong kak" << endl;
    }
    else if(infoBaru == head->info){ //hapus di awal
        head = head->next; //head sama dengan hapus next
        free(bantu); //hapus hapus
    }
    else{ //hapus di tengah atau akhir
        while(bantu -> next->info!= infoBaru && bantu->next != NULL){ //looping selama bantu next info tidak sama dengan info baru dan bantu next tidak null
            bantu = bantu->next; //bantu geser ke next
        }
        if(bantu -> next ->info = infoBaru){ //cek list kosong
           Node* bantuHapus = bantu -> next; //bantu hapus sama dengan bantu next
           if (bantuHapus == tail){ //cek jika bantu hapus adalah tail
                tail = bantu; //tail sama dengan bantu
           }
            bantu -> next = bantuHapus -> next; //bantu next sama dengan bantu hapus next
            free(bantuHapus); //hapus bantu hapus
        }
        else{ //hapus di tengah atau akhir
            cout<< "\N data kosong" << endl;
        }
    }
}

int main(){
    buatlist();
    sisipDepan(6);
    sisipBelakang(15);
    sisipTengah(10);
    sisipNode(5);
    displyList();
    hapusNode(7);
    displyList();
    return 0;
}
