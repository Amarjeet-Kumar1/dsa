#include<iostream>
using namespace std;

//doubly linked list
struct Node{
    int data;
    Node *next;
    Node *prev;
    Node(int d){
        data = d;
        next = prev = NULL;
    }
};


int main(){
    Node *head = new Node(10);
    head -> next = new Node(30);
    head -> next -> prev = head;
    head -> next -> next = new Node(40);
    head -> next -> next -> prev = head -> next;
    return 0;
}