#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
    Node(int d){
        data = d;
        next = NULL;
    }
};

void detectLoop(Node *head){
    Node *temp;
    Node  *curr = head;
    while(curr != NULL){
        if(curr->next == NULL){
            cout<<"NO";
            return;
        }
        if(curr->next == temp){
            cout<<"Yes";
            return;
        }
        Node *curr_next = curr->next;
        curr->next = temp;
        curr = curr_next;
        
    }
    cout<<"No";
}

int main(){
    Node *head = new Node(10);
    head->next = new Node (20);
    head->next->next = new Node (30);
    head->next->next->next = new Node (40);
    // head->next->next->next->next = head->next;
    detectLoop(head);


    return 0;
}