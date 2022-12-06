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

Node *insertEnd(Node *head, int x){
    Node *temp = new Node(x);
    if(head == NULL){
        return temp;
    }
    Node *curr = head;
    while(curr->next != NULL){
        curr = curr->next;
    }
    curr->next = temp;
    return head;

    
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
    head = insertEnd(head, 10);
    head = insertEnd(head, 20);
    head = insertEnd(head, 30);
    printList(head);
    head = insertEnd(head, 40);
    printList(head);
    return 0;
}