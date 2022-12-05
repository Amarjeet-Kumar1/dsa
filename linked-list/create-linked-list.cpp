#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *next; // self referencial structure
    //constructor
    Node(int x){
        data = x;
        next = NULL;
    }

};

int main(){
    // Node *head = new Node(10); //head node created with data as 10 and next pointer as NULL
    // Node *temp1 = new Node(20); // ,,, address stored in temp1 pointer
    // Node *temp2 = new Node(30);

    // // link nodes
    // head -> next = temp1;
    // temp1 -> next = temp2;

    // or short and cleaner way of linking
    Node *head = new Node(10);
    head -> next = new Node(30);
    head -> next -> next = new Node(30);

    return 0;
}