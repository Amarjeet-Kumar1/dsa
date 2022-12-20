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
    Node *curr = head;
    int count = 1;
    while(curr != NULL){
        Node *next = curr->next;
        Node *temp = head;
        int tc = count;
        while(tc--){
            if(temp == next){
                cout<<"Yes";
                return;
            }
            temp = temp->next;
        }
        curr = curr->next;
        count++;
    }
    cout<<"No";
}

int main(){
    Node *head = new Node(10);
    head->next = new Node (20);
    head->next->next = new Node (30);
    head->next->next->next = new Node (40);
    head->next->next->next->next = head;
    detectLoop(head);


    return 0;
}