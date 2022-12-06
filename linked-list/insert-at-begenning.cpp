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

Node *insertBegin(Node *head, int x){
    Node *temp = new Node(x);
    temp->next = head;
    return temp;
}
void printList(Node *head){
    //assign head to curr
    Node *curr = head;
    //check if curr is after the last node which is null
    while(curr != NULL){
        cout<<curr->data<<" ";
        //shift curr to next
        curr = curr->next;
    }
    cout<<endl;
}

int main(){
    Node *head = NULL;
    head = insertBegin(head, 30);
    head = insertBegin(head, 20);
    head = insertBegin(head, 10);
    printList(head);
    head = insertBegin(head, 5);
    printList(head);
    return 0;
}