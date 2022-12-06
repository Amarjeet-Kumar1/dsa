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

//search in linked list of given head and key
int searchLL(Node *head, int x){
    Node *curr = head;
    int count = 1;
    while(curr != NULL){
        if(curr->data == x){
            return count;
        } else {
            count++;
            curr = curr->next;
        }
    }
    return -1;
}

//recursively
int rSearchLL(Node *head, int x){
    if(head == NULL)
        return -1;
    
    if(head -> data == x)
        return 1;
    else {
    int res = rSearchLL(head->next, x);
    if(res == -1)
        return  -1;
    else 
        return (res+1);
    }
    
}

int main(){
    Node *head = new Node(10);
    head ->next = new Node(5);
    head ->next ->next = new Node(20);
    head ->next ->next->next = new Node(15);
    cout<<searchLL(head, 15)<<endl;
    cout<<rSearchLL(head, 20);
    

    return 0;
}