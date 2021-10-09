#include <iostream>

using namespace std;

class Node{
public:
    int data;
    Node *next;


};
class LinkedList{
private:
    Node *first;
public:
    LinkedList(){first=NULL;}
    LinkedList(int A[],int n);
    ~LinkedList();
    void Display();
    void Insert(int index,int x);
    void Delete(int index);
    int Length();


};
LinkedList::LinkedList(int A[],int n){
    int i;
    Node *t,*last;
    first = new Node;
    first->data=A[0];
    first->next=NULL;
    last=first;
    for(int i=1;i<n;i++){
        t=new Node;
        t->data = A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}
LinkedList::~LinkedList(){
    Node *p=first;
    while(first){

        first=first->next;
        delete p;
        p=first;
    }
}
void LinkedList::Display(){
    Node *p = first;
    while(p){
        cout<<p->data<<endl;
        p=p->next;

    }
}
int LinkedList::Length(){
    Node *p=first;
    int c=0;
    while(p){
        c++;
        p=p->next;
    }
    return c;

}
void LinkedList::Insert(int pos,int x){
    Node *n = new Node;
    Node *p = first;
    n->data=x;
    n->next=NULL;
    if(pos>0){
        for(int i=1;i<pos&&p;i++){
            p=p->next;

        }
        if(p){
            n->next = p->next;
            p->next = n;
        }

    }else if(pos==0){
        n->next=p;
        first=n;
    }
}
void LinkedList::Delete(int pos){
    Node *m;
    Node *p = first;
    if(pos> Length())return;
    if(pos==1){
        m=first;
        first=first->next;
        free(m);
    }else{
        for(int i=1;i<pos;i++){
            m=p;
            p=p->next;

        }
        m->next=p->next;
        free(p);
    }
}
int main()
{
    int A[]={1,2,5,8,9};
    LinkedList ll = LinkedList(A,5);

    ll.Display();
    return 0;
}
