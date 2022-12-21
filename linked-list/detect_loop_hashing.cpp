#include<iostream>
#include<unordered_set>
using namespace std;

struct Node{
    int data;
    Node *next;
    Node(int d){
        data = d;
        next = NULL;
    }
};

bool detectLoop(Node *head){
    unordered_set<Node *> set;
    for(Node* curr = head; curr != NULL; curr = curr->next){
        if(set.find(curr) != set.end())
            return true;
        set.insert(curr);
    }
    return false;
}

int main(){
    Node *head = new Node(10);
    head->next = new Node (20);
    head->next->next = new Node (30);
    head->next->next->next = new Node (40);
    // head->next->next->next->next = head->next;

    if(detectLoop(head)){
        cout<<"Yes";
    } else{
        cout<<"NO";
    }


    return 0;
}