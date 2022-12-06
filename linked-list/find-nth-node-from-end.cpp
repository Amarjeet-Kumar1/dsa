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

//using length of linked list
//two traversal
// void nthFromEnd(Node *head, int n){

//     Node *curr;
//     int length = 0;
//     for(curr = head; curr != NULL; curr = curr->next)
//         length++;

//     if(length < n) return;
//     curr = head;
//     for(int i = 0; i < (length - n ); i++)
//         curr = curr->next;

//     cout<<curr->data;
    
// }

//efficient solution without length
//use two pointer approach
//move first pointer n steps ahead and start traversing
//when first pointer reaches after end, second pointer reaches desired location
void nthFromEnd(Node *head, int n){
    if(head == NULL) return;
    Node *first = head, *second = head;
    while(n--){
        if(first == NULL) return;
        first = first->next;
    }   
    while(first != NULL){
        first = first->next;
        second = second->next;
    }
    cout<<second->data;
}

int main(){
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    head->next->next->next->next = new Node(50);
    
    nthFromEnd(head, 2);
    return 0;
}