#include<iostream>
using namespace std;

class Node{
public:
    char data;
    Node *next,*prev;
    Node(char d){
        data=d;
        next=prev=NULL;
    }
};

class Doubly{
public:
    Node* head;
    Doubly(){head=NULL;}
    void insertLast(char d){
        Node* n=new Node(d);
        if(!head) head=n;
        else{
            Node* t=head;
            while(t->next)t=t->next;
            t->next=n;
            n->prev=t;
        }
    }
    bool isPalindrome(){
        if(!head)return true;
        Node* left=head;
        Node* right=head;
        while(right->next) right=right->next;
        while(left!=right && right->next!=left){
            if(left->data!=right->data) return false;
            left=left->next;
            right=right->prev;
        }
        return true;
    }
};

int main(){
    Doubly d;
    string s;
    cin>>s;
    for(char c:s)d.insertLast(c);
    if(d.isPalindrome()) cout<<"Palindrome";
    else cout<<"Not Palindrome";
    return 0;
}
