#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node *next;
        Node(int d){
            data = d;
            next = NULL;
        }
};
void printLL(Node *head){
    while(head != NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}

Node *removeDuplicate(Node *head){
    if(head == NULL) return head;
    Node *curr = head;
    while(curr->next != NULL){
        if(curr->data == curr->next->data){
            Node *temp = curr->next;
            curr->next = curr->next->next;
            delete temp;
        } else {
            curr = curr->next;
        }
        
    }
    return head;
} 

int main(){
    Node *head =  new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(20);
    head->next->next->next = new Node(20);
    printLL(head);
    head = removeDuplicate(head);
    printLL(head);
    return 0;
}