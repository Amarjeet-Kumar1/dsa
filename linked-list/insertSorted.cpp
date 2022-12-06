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

Node *insertSorted(Node *head, int x){
    Node *temp = new Node(x);
    if(head == NULL)
        return temp;
    if(head->data > x){
        temp->next = head;
        return temp;
    }
    Node *curr = head;
    while((curr->next != NULL) && (curr->next->data < x)){
        curr = curr->next;
    }
    
    temp -> next = curr->next;
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
    // Node *head = NULL;
    Node *head = new Node(10);
    head -> next = new Node(20);
    head -> next -> next = new Node(30);
    head -> next -> next -> next = new Node(40);
    printList(head);
    head = insertSorted(head, 5);
    printList(head);
    return 0;
}