#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node *next,*prev;
    Node(int d){
        data=d;
        next=prev=NULL;
    }
};

class Doubly{
public:
    Node* head;
    Doubly(){head=NULL;}
    void insertLast(int d){
        Node* n=new Node(d);
        if(!head) head=n;
        else{
            Node* t=head;
            while(t->next)t=t->next;
            t->next=n;
            n->prev=t;
        }
    }
    int size(){
        int count=0;
        Node* t=head;
        while(t){
            count++;
            t=t->next;
        }
        return count;
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
    int size(){
        if(!head)return 0;
        int count=0;
        Node* t=head;
        do{
            count++;
            t=t->next;
        }while(t!=head);
        return count;
    }
};

int main(){
    Doubly d;
    Circular c;
    d.insertLast(10);
    d.insertLast(20);
    d.insertLast(30);
    c.insertLast(5);
    c.insertLast(15);
    c.insertLast(25);
    cout<<"Size of Doubly Linked List: "<<d.size()<<endl;
    cout<<"Size of Circular Linked List: "<<c.size()<<endl;
    return 0;
}
