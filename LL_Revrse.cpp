#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    struct Node *next;

    //constructor
    Node(int val){
        data=val;
        next=NULL;
    }
};
void LLcreate(Node *  &head){
    int x;
    cin>>x;
    if(x==-1)return;
    head=new Node(x);
    head->data=x;
    head->next=NULL;
    LLcreate(head->next);
}
void LLprint(Node *head){
    if(head==NULL)return;
    cout<<head->data<<" ";
    LLprint(head->next);
}
//No need to pass by refernece as actual head pointer to change hi nahi ho rha hai;
// we are returning the newhead;
// and not the head
Node * RecursiveReverse(Node * head){
    if(head->next==NULL)return head;
    Node * HeadAfterReversing=RecursiveReverse(head->next);
    head->next->next=head;
    head->next=NULL;
    return HeadAfterReversing;
    // return head;  when we return head this means 1(if LL is 1 2 3 4 5) and noe the list is revesed so 5(5 4 3 2 1) is k a next is NULL
    //so if we return head then print m only 1 print hoga as 1 ke bad NULLL hai.(whther we pass by refence or pass by value ,head return krne se 1 print hoga bs)
}
Node * IterativeReverse(Node * &head){
    Node *a=head,*b=NULL,*c=NULL;
    while(a!=NULL){
        c=b;
        b=a;
        a=a->next;
        b->next=c;
    }
    head=b;
    return head;
}
Node* LLreverse(struct Node * &head){
    if(head==NULL)return head;
    return RecursiveReverse(head);
    // return IterativeReverse(head);
}
int main(){
    Node * head=NULL;
    LLcreate(head);
    LLprint(head);
    cout<<endl;
    head=LLreverse(head);
    LLprint(head);
    return 0;
}    
