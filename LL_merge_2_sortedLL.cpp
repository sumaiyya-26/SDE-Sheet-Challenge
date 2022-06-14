#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node *next;

    node(int x){
        data=x;
        next=NULL;
    }
};
void LLcreate(node * &head){
    int x;cin>>x;
    if(x==-1)return;
    head=new node(x);
    LLcreate(head->next);
}
void LLprint(node *head){
    if(head==NULL){cout<<"NULL";return;}
    cout<<head->data<<"->";
    LLprint(head->next);
}
void swap(node * &l1,node* &l2){
        node *temp=l1;l1=l2;l2=temp;
    }

    //merging Inplace
    node* mergeTwoLists(node* list1, node* list2) {
        if(list1==NULL)return list2;
        if(list2==NULL)return list1;
        node *l1=list1,*l2=list2;
        if(l1->data>l2->data){
             swap(l1,l2);
        }
        node * ans=l1 ;
        while(l1!=NULL && l2!=NULL){
           node *temp=NULL;
            while(l1!=NULL && l1->data<=l2->data){
                temp=l1;
                l1=l1->next;
            }
            temp->next=l2;
            swap(l1,l2);
        }
        return ans;
    }
int main(){
     node *head1=NULL;
     LLcreate(head1);
     LLprint(head1);
    node *head2=NULL;
     LLcreate(head2);
     LLprint(head2);
     node *ans=mergeTwoLists(head1,head2);
     LLprint(ans);
}    