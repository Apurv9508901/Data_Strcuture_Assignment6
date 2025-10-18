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
    void insertFirst(int d){
        Node* n=new Node(d);
        if(!head) head=n;
        else{
            n->next=head;
            head->prev=n;
            head=n;
        }
    }
    void insertLast(int d){
        Node* n=new Node(d);
        if(!head) head=n;
        else{
            Node* t=head;
            while(t->next) t=t->next;
            t->next=n;
            n->prev=t;
        }
    }
    void insertAfter(int key,int d){
        Node* t=head;
        while(t&&t->data!=key)t=t->next;
        if(!t)return;
        Node* n=new Node(d);
        n->next=t->next;
        n->prev=t;
        if(t->next)t->next->prev=n;
        t->next=n;
    }
    void insertBefore(int key,int d){
        Node* t=head;
        while(t&&t->data!=key)t=t->next;
        if(!t)return;
        Node* n=new Node(d);
        n->next=t;
        n->prev=t->prev;
        if(t->prev)t->prev->next=n;
        else head=n;
        t->prev=n;
    }
    void delNode(int key){
        Node* t=head;
        while(t&&t->data!=key)t=t->next;
        if(!t)return;
        if(t->prev)t->prev->next=t->next;
        else head=t->next;
        if(t->next)t->next->prev=t->prev;
        delete t;
    }
    void search(int key){
        Node* t=head;
        while(t){
            if(t->data==key){
                cout<<"Found\n";
                return;
            }
            t=t->next;
        }
        cout<<"Not Found\n";
    }
    void display(){
        Node* t=head;
        while(t){
            cout<<t->data<<" ";
            t=t->next;
        }
        cout<<endl;
    }
};

class Circular{
public:
    Node* head;
    Circular(){head=NULL;}
    void insertFirst(int d){
        Node* n=new Node(d);
        if(!head){
            head=n;
            n->next=head;
        }else{
            Node* t=head;
            while(t->next!=head)t=t->next;
            n->next=head;
            t->next=n;
            head=n;
        }
    }
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
    void insertAfter(int key,int d){
        if(!head)return;
        Node* t=head;
        do{
            if(t->data==key){
                Node* n=new Node(d);
                n->next=t->next;
                t->next=n;
                return;
            }
            t=t->next;
        }while(t!=head);
    }
    void insertBefore(int key,int d){
        if(!head)return;
        Node* t=head;
        Node* p=NULL;
        do{
            if(t->data==key){
                Node* n=new Node(d);
                if(!p){
                    Node* last=head;
                    while(last->next!=head)last=last->next;
                    n->next=head;
                    head=n;
                    last->next=head;
                }else{
                    n->next=t;
                    p->next=n;
                }
                return;
            }
            p=t;
            t=t->next;
        }while(t!=head);
    }
    void delNode(int key){
        if(!head)return;
        Node* t=head;
        Node* p=NULL;
        do{
            if(t->data==key){
                if(p){
                    p->next=t->next;
                    if(t==head)head=t->next;
                }else{
                    Node* last=head;
                    while(last->next!=head)last=last->next;
                    if(head->next==head){head=NULL;delete t;return;}
                    head=head->next;
                    last->next=head;
                }
                delete t;
                return;
            }
            p=t;
            t=t->next;
        }while(t!=head);
    }
    void search(int key){
        if(!head){cout<<"Not Found\n";return;}
        Node* t=head;
        do{
            if(t->data==key){cout<<"Found\n";return;}
            t=t->next;
        }while(t!=head);
        cout<<"Not Found\n";
    }
    void display(){
        if(!head)return;
        Node* t=head;
        do{
            cout<<t->data<<" ";
            t=t->next;
        }while(t!=head);
        cout<<endl;
    }
};

int main(){
    Doubly d;
    Circular c;
    int ch,t,x,y;
    while(1){
        cout<<"1.Doubly Insert First\n2.Doubly Insert Last\n3.Doubly Insert After\n4.Doubly Insert Before\n5.Doubly Delete\n6.Doubly Search\n7.Doubly Display\n";
        cout<<"8.Circular Insert First\n9.Circular Insert Last\n10.Circular Insert After\n11.Circular Insert Before\n12.Circular Delete\n13.Circular Search\n14.Circular Display\n15.Exit\n";
        cin>>ch;
        switch(ch){
            case 1:cin>>x;d.insertFirst(x);break;
            case 2:cin>>x;d.insertLast(x);break;
            case 3:cin>>t>>x;d.insertAfter(t,x);break;
            case 4:cin>>t>>x;d.insertBefore(t,x);break;
            case 5:cin>>x;d.delNode(x);break;
            case 6:cin>>x;d.search(x);break;
            case 7:d.display();break;
            case 8:cin>>x;c.insertFirst(x);break;
            case 9:cin>>x;c.insertLast(x);break;
            case 10:cin>>t>>x;c.insertAfter(t,x);break;
            case 11:cin>>t>>x;c.insertBefore(t,x);break;
            case 12:cin>>x;c.delNode(x);break;
            case 13:cin>>x;c.search(x);break;
            case 14:c.display();break;
            case 15:return 0;
        }
    }
}
