#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node(int d){
        data=d;
        next=NULL;
    }
};

bool isCircular(Node* head){
    if(!head)return false;
    Node* t=head->next;
    while(t!=NULL && t!=head)t=t->next;
    return (t==head);
}

int main(){
    Node* head=new Node(10);
    Node* second=new Node(20);
    Node* third=new Node(30);
    head->next=second;
    second->next=third;
    third->next=head; 
    if(isCircular(head)) cout<<"Circular Linked List";
    else cout<<"Not Circular Linked List";
    return 0;
}
