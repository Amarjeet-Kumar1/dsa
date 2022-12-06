#include<iostream>
using namespace std;

//create node using structure
struct Node{
    int data;
    Node *next;
    Node(int d){
        data = d;
        next = NULL;
    }
};

//print all node of list 
void printList(Node *head){
    //assign head to curr
    Node *curr = head;
    //check if curr is after the last node which is null
    while(curr != NULL){
        cout<<curr->data<<" ";
        //shift curr to next
        curr = curr->next;
    }
}

//print all node of list recursively
void rPrint(Node *head){
    if(head == NULL)
        return;
    cout<<head->data<<" ";
    rPrint(head->next);
}

int main(){
    Node *head = new Node(20);
    head -> next = new Node(12);
    head -> next -> next = new Node(30);
    head -> next -> next -> next= new Node(20);
    printList(head);
    rPrint(head);

}