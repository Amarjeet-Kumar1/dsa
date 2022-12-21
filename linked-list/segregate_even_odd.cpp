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

Node *segregate(Node *head){
    Node *eS = NULL, *eE = NULL, *oS = NULL, *oE = NULL;
    for(Node *curr = head; curr != NULL; curr = curr->next ){
        int x = curr->data;
        if(x%2 == 0){
            if(eS == NULL){
                eS = curr;
                eE = eS;
            } else{
                eE->next = curr;
                eE = eE->next;
            }
        } else{
            if(oS == NULL){
                oS = curr;
                oE = oS;
            } else {
                oE->next = curr;
                oE = oE->next;
            }
        }
    }
    if(eS == NULL || oS == NULL )
        return head;
    
    eE->next = oS;
    oE->next = NULL;
    return eS;
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
    head->next->next->next = new Node(20);
    head->next->next->next->next = new Node(18);
    printLL(head);
    head = segregate(head);
    printLL(head);
    return 0;

}

