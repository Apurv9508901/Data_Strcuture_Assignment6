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

class Circular{
public:
    Node* head;
    Circular(){head=NULL;}
    void insertLast(int d){
        Node* n=new Node(d);
        if(!head){
            head=n;
            n->next=head;
        }else{
            Node* t=head;
            while(t->next!=head)t=t->next;
            t->next=n;
            n->next=head;
        }
    }
    void display(){
        if(!head)return;
        Node* t=head;
        do{
            cout<<t->data<<" ";
            t=t->next;
        }while(t!=head);
        cout<<head->data<<endl;
    }
};

int main(){
    Circular c;
    c.insertLast(20);
    c.insertLast(100);
    c.insertLast(40);
    c.insertLast(80);
    c.insertLast(60);
    c.display();
    return 0;
}
