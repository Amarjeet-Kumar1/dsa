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

Node *recursiveReverse(Node *curr, Node *prev = NULL){
    if(curr == NULL) return prev;
    Node *next = curr->next;
    curr->next = prev;
    return recursiveReverse(next, curr);
}

int main(){
    Node *head =  new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    printLL(head);
    head = recursiveReverse(head);
    printLL(head);
    return 0;
}