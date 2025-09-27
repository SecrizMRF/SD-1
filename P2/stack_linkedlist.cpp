#include <iostream>
#include <stack>
using namespace std;

struct Node {
    int value;
    Node *next;
};


Node *head = NULL;
Node *tail = NULL;

void push( int n ) {
    Node *newNode = new Node;
    newNode -> value = n;
    newNode -> next = NULL;

    if (head == NULL) {
        head = newNode;
        tail = newNode;
    } else {
        newNode -> next = head;
        head = newNode;
    }
}

void pop() {
    if (head == NULL) {
        cout << "List kosong!\n";
        return;
    }
    Node *temp = head;
    head = head->next;
    if (head == NULL) tail = NULL;
    delete temp;
}

void display() {
    Node *temp = head;
    cout << "Isi Stack: ";
    while (temp != NULL) {
        cout << temp->value << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    system("cls");
    int pil, value, jumlah;

    do {
        cout << "Pilih menu:\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Print\n";
        cout << "Pilihan: ";
        cin >> pil;
        
        switch (pil) {
            case 1:
                cout << "Mau berapa data? ";
                cin >> jumlah;
                cout << endl;
                for (int i = 0; i < jumlah; i++) {
                    cout << "Masukkan nilai-" << i + 1 << ": ";
                    cin >> value;
                    push(value);
                }
                break;
            case 2:
                pop();
                getchar();
                break;
            case 3:
                display();
                getchar();
                break;
            default:
                cout << "Pilihan tidak valid!\n";
                break;
            }
            cout << endl;
        } while (pil != 0);
    }