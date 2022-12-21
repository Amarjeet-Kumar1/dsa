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

void removeLoop(Node *head){
    Node *slow = head, *fast = head;
    while(fast != NULL && fast->next != NULL){
        slow = slow ->next;
        fast = fast->next->next;
        if(slow == fast)
            break;
    }
    if(slow != fast)
        return;

    slow = head;
    while(slow->next != fast->next){
        slow =slow->next;
        fast = fast ->next;
    }
    fast->next = NULL;
}

bool detectLoop(Node *head){
   Node *slow = head, *fast = head;
   while(fast != NULL && fast->next != NULL){
    slow = slow->next;
    fast = fast->next->next;
    if(slow == fast)
        return true;
   }
   return false;
}

int main(){
    Node *head = new Node(10);
    head->next = new Node (20);
    head->next->next = new Node (30);
    head->next->next->next = new Node (40);
    head->next->next->next->next = head->next;

    if(detectLoop(head)){
        cout<<"Yes";
    } else{
        cout<<"NO";
    }

    removeLoop(head);
    if(detectLoop(head)){
        cout<<"Yes";
    } else{
        cout<<"NO";
    }


    return 0;
}