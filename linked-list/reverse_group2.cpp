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

Node *reverseK(Node *head, int k){
    Node *curr = head, *prevFirst = NULL;
    bool isFirstPass = true;
    
    while(curr != NULL){
        Node *first = curr ,*prev = NULL;
        int count = 0;
        while(curr != NULL && count < k){
            Node *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }
        if(isFirstPass){ isFirstPass = false; head = prev;}
        else {prevFirst-> next = prev;}
        
        prevFirst = first;
    }
   
    return head;
}

int main(){
    Node *head =  new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    head->next->next->next->next = new Node(50);
    int k = 3;
    printLL(head);
    head = reverseK(head, k);
    printLL(head);
    return 0;
}