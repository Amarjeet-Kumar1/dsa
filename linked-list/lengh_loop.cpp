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

int lengthLoop(Node *head){
    Node *slow = head, *fast = head;
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast)
            break;
    }
    if(slow != fast)
        return 0;
    
    int count = 1;
    while(fast ->next != slow){
        fast = fast->next;
        count++;
    }
    return count;

}

int main(){
    Node *head = new Node(10);
    head->next = new Node (20);
    head->next->next = new Node (30);
    head->next->next->next = new Node (40);
    head->next->next->next->next = head->next;

    cout<<lengthLoop(head);


    return 0;
}