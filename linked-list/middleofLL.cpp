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
Node *insertEnd(Node *head, int x){
    Node *temp = new Node(x);
    if(head == NULL)
        return temp;
    Node *curr = head;
    while(curr->next != NULL){
        curr = curr->next;
    }
    curr->next = temp;
    return head;
}
void printList(Node *head){
    Node *curr = head;
    while(curr != NULL){
        cout<<curr->data<<" ";
        curr = curr->next;
    }
    cout<<endl;
}

//requires two traversal
// void printMiddle(Node *head){
//     if(head == NULL) return;
//     int count = 0;
//     Node *curr;
//     for(curr = head; curr != NULL; curr = curr -> next)
//         count++;
//     curr = head;
//     for(int i = 0; i < count/2; i++)
//         curr = curr -> next;
//     cout<<curr->data;
// }


//efficient solution
//using slow and fast pointer
//slow moves 1 steps and fast move 2 steps at a time
//when fast reaches end or after end slow reaches at middle
void printMiddle(Node *head){
    if(head == NULL) return;
    Node *slow = head, *fast = head;
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    cout<<slow->data;
}


int main(){
    Node *head = NULL;
    head = insertEnd(head, 10);
    head = insertEnd(head, 5);
    head = insertEnd(head, 20);
    head = insertEnd(head, 15);
    head = insertEnd(head, 25);
    head = insertEnd(head, 30);
    printList(head);
    printMiddle(head);
    return 0;
}