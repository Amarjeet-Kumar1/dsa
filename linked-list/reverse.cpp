#include<iostream>
#include<vector>
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


//naive solution
//two traversal

// Node *reverseLL(Node *head){
//     vector<int> arr;
//     for(Node *curr = head; curr != NULL; curr = curr->next){
//         arr.push_back(curr->data);
//     }
//     for(Node *curr = head; curr != NULL; curr = curr->next){
//         curr->data = arr.back();
//         arr.pop_back();
//     }
//     return head;

    
// }

//efficient solution
//we hold three node at a time

Node *reverseLL(Node *head){
    if(head == NULL || head->next == NULL)
        return head;
    Node *prev = NULL, *curr = head;
    while(curr != NULL){
        Node *next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next; 
    }
    return prev;
}


void printLL(Node *head){
    Node *curr = head;
    while(curr != NULL){
        cout<<curr->data<<" ";
        curr = curr->next;
    }
    cout<<endl;
}
int main(){
    Node *head = new Node(10);
    head -> next = new Node(20);
    head -> next -> next = new Node(30);
    head -> next -> next -> next = new Node(40);
    printLL(head);
    head = reverseLL(head);
    printLL(head);
    return 0;
}