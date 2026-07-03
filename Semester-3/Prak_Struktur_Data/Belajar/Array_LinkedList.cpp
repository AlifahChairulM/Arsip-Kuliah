//aray stack
#include <iostream>
using namespace std;

#define max 50
int top = 0;
int stack [max];

void buatstack();
bool stackkosong();
bool stackpenuh();
void push(int IB);
void pop();
void cetakstack();

int main (){
    buatstack();
    push(15);
    push(76);
    push(12);
    push(21);
    cout << "sebelum pop" << endl;
    cetakstack();
    pop();
    pop();
    cout << " setelah pop"<< endl;
    cetakstack();
}

void buatstack(){
    stack [top] = 0;
}

bool stackkosong(){
    if(top==0){
        return true;
    }
    else{
        return false;
    }
}

bool stackpenuh(){
    if(top==max){
        return true;
    }
    else{
        return false;
    }
}

void push(int IB){
    if (stackpenuh()){
        cout << "stack penuh" << endl;
    }
    else{
        top++;
        stack[top]=IB;
        stack[0]=top;
    } 
}

void pop(){
    if (stackkosong()){
        cout << "stack kosong" << endl;
    }
    else{
        top--;
        stack[0]=top;
    }
}

void cetakstack(){
    for(int i = top; i>0; i--){
        cout << stack [i] << endl;
    }
}





//linked singel stack
#include <iostream>
using namespace std;

struct node{
    int data;
    node* next;
};

Node* bottom, *top, *newNode;

void buatstack();
bool stackkosong();
bool stackpenuh();
void push(int IB);
void pop();
void cetakstack();

int main(){
    buatstack();
    push(50);
    push(12);
    push(76);
    push(21);
    cout << "sebelum pop" << endl;
    cetakstack();
    cout << "\n";
    pop();
    pop();
    cout << " setelah pop"<< endl;
    cetakstack();
}

void buatstack(){
    bottom = null;
    top = null;
}

void stackkosong(){
    if (bottom == null){
        return true;
    }else{
        return false;
    }
}

void push(int IB){
    newNode = new Node();
    newNode -> data = IB;
    newNode -> next = null;
    if(stackkosong()){
        bottom = newNode;
        top = newNode;
    }
    else{
        top -> next = newNode;
        top = newNode;
    }
}

void pop(){
    if (stackkosong()){
        cout << "stack masih kosong" << endl;
    }
    else{
        Node *temp ; *hapus;
        temp = bottom;
        while (temp -> next != top){
            temp = temp -> next;
        }
        hapus = top;
        top = temp;
        top -> next = null;
        delete(hapus);
    }
}

void cetakstack(){
    node *temp;
    temp = bottom;
    while(temp  != null)
        cout << temp -> data << endl;
        temp = temp -> next;
}
