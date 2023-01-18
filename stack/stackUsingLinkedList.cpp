#include<iostream>
using namespace std;
class Stack{
    private:
        struct Node{
            int data;
            Node *next;
            Node(int d){
                data = d;
                next = NULL;
            }
        }; 
    public:
        
        Node *head = NULL;

        void push(int x){
            Node *temp = new Node(x);
            temp->next = head;
            head = temp;

        }
        int pop(){
            if(head == NULL){
                cout<<"Stack underflow";
                return INT_MIN;
            }
            int res = head->data;
            Node *temp = head;
            head = head->next;
            delete(temp);
            return res;

        }
        int topy(){
            if(head == NULL){
                return INT_MIN;
            }
            return head->data;
        }
};
int main(){
    Stack st;
    st.push(6);
    st.push(5);
    st.pop();
    st.pop();
    cout<<st.topy();
    return 0;
}