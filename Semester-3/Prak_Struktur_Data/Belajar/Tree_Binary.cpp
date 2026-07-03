#include <iostream>
using namespace std;

struct node{
    int data;
    node*kiri;
    node * kanan;
};
node* akar;

node* buatnode(int data){
    node* baru =  new node();
    baru ->data = data;
    baru ->kiri = NULL;
    baru ->kanan = NULL;
    return baru;
}

node* sisipnode (node* akar, int data){
    if(akar == NULL){
        return buatnode(data);
    }
    if(data < akar -> data){
        akar -> kiri = sisipnode(akar -> kiri, data);
    } else if (data > akar -> data){
        akar -> kanan = sisipnode (akar -> kanan, data);
    }
    return akar;
}

void inorder (node* akar){
    if(akar != NULL){
        inorder (akar -> kiri);
        cout << akar -> data << " ";
        inorder (akar -> kanan);
    }
}

void preorder (node* akar){
    if(akar != NULL){
        cout << akar -> data << " ";
        preorder (akar -> kiri);
        preorder (akar -> kanan);
    }
}

void postorder (node* akar){
    if(akar != NULL){
        postorder (akar -> kiri);
        postorder (akar -> kanan);
        cout << akar -> data << " ";
    }
}

node* hapusnode (node* akar, int data){
    if(akar == NULL){
        cout << "Data tidak ditemukan dalam tree." << endl;
        return akar;
    }
    if(data < akar -> data){
        akar -> kiri = hapusnode (akar -> kiri, data);
    } else if (data > akar -> data){
        akar -> kanan = hapusnode (akar -> kanan, data);
    } else {
        if(akar -> kiri == NULL){
            node* temp = akar -> kanan;
            delete akar;
            return temp;
        } else if (akar -> kanan == NULL){
            node* temp = akar -> kiri;
            delete akar;
            return temp;
        }
        node* temp = akar -> kanan;
        while(temp && temp -> kiri != NULL){
            temp = temp -> kiri;
        }
        akar -> data = temp -> data;
        akar -> kanan = hapusnode (akar -> kanan, temp -> data);
    }
    return akar;
}

node* nilaimin (node* akar){
    node* current = akar;
    while(current && current -> kiri != NULL){
        current = current -> kiri;
    }
    return current;
}

int main(){
    akar = NULL;
    akar = sisipnode(akar, 50);
    sisipnode(akar, 30);
    sisipnode(akar, 20);
    sisipnode(akar, 40);
    sisipnode(akar, 70);
    hapusnode (akar, 20);
    sisipnode(akar, 60);
    sisipnode(akar, 80);

    cout << "Inorder traversal: ";
    inorder(akar);
    cout << endl;

    cout << "Preorder traversal: ";
    preorder(akar);
    cout << endl;

    cout << "Postorder traversal: ";
    postorder(akar);
    cout << endl;

    return 0;
}   