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

Node *insertPos(Node *head, int pos, int data){
    Node *newNode = new Node(data);
    if(pos == 1){
        newNode -> next = head;
        return newNode;
    }
    Node *curr = head;
    while(pos > 2){
        pos--;
        curr = curr -> next;
        if(curr == NULL)
            return head;
    }
    
    newNode -> next = curr -> next;
    curr -> next = newNode;
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
    head = insertPos(head, 3, 5);
    printList(head);
    return 0;
}