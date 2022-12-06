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

Node *delTail(Node *head){
    
    if(head == NULL)
        return NULL;
    if(head -> next == NULL){
        delete head;
        return NULL;
    }
    Node *temp = head;
    while(temp ->next -> next != NULL){
        temp = temp->next;
    }
    delete (temp->next);
    temp->next = NULL;
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
    Node *head = new Node(10);
    head -> next = new Node(20);
    head -> next -> next = new Node(30);
    head -> next -> next -> next = new Node(40);
    printList(head);
    head = delTail(head);
    printList(head);
    return 0;
}