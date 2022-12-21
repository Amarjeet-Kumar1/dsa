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
//we have only given a pointer to random node in ll
//we have to delete it
//copy the next node data in curr and delete the next node
//and point to the next next next
void deleteNode(Node *ptr){
    Node *temp = ptr->next;
    ptr->data = temp->data;
    ptr->next = temp->next;
    delete temp;
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
    head->next = new Node(15);
    
    head->next->next = new Node(7);
    Node *temp = head->next->next;
    head->next->next->next = new Node(20);
    head->next->next->next->next = new Node(18);
    printLL(head);
    deleteNode(temp);
    printLL(head);
    return 0;

}

