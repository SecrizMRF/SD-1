#include <iostream>
using namespace std;

//deklarasi struktur node

struct node {
    int value;
    node *next;
};

node *head = NULL;
node *tail = NULL;


//dekklarasi fungsi insert di node pertama/paling depan
void insertFirst( int n ) {
    node *newNode = new node;
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


//deklarasi fungsi insert di node terakhir/paling belakang
void insertLast ( int n ) {
    node *newNode = new node;
    newNode -> value = n;
    newNode -> next = NULL;

    if (head == NULL) {
        head = newNode;
        tail = head;
    } else {
        tail -> next = newNode;
        tail = newNode;
    }
}


//deklarasi fungsi insert setelah node yang ditentukan
void insertAfter ( int n, int check ) {
    if (head == NULL) {
        cout << "List kosong!" << endl;
        return;
    }

    node *newNode = new node;
    newNode -> value = n;
    newNode -> next = NULL;

    node *p = head;
    while (p != NULL && p -> value != check) {
        p = p -> next;
    }

    if (p == NULL) {
        cout << "Node dengan nilai " << check << " tidak ditemukan!" << endl;
        delete newNode;
    } else {
        newNode -> next = p -> next;
        p -> next = newNode;
        if (p == tail) {
            tail = newNode;
        }
    }

}

//cetak linked list
void display() {
    node *temp = head;
    cout << "Isi Linked List: ";
    while (temp != NULL) {
        cout << temp -> value << " -> ";
        temp = temp -> next;
    }
    cout << "NULL" << endl;
}

int main () {
    system("cls");
    insertFirst(10);
    insertLast(20);
    insertLast(30);
    insertAfter(25, 20);
    insertFirst(5);

    display();
    return 0;
}