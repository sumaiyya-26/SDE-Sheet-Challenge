    
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
int count(Node * head){
    int c=0;
    while(head!=NULL){
        c++;
        head=head->next;
    }
    return c;
}       
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
    Node *sublistReverse(Node * head,int l,int r){
        if(head==NULL || l==r)return head;
        Node *dummy=new Node(-1);
        dummy->next=head;
        Node *nodebeforeSublist= dummy;
        int pos=1;
        while(pos<l){
           nodebeforeSublist=nodebeforeSublist->next;
            pos++;
        }
        Node *wp=nodebeforeSublist->next;
        while(l<r){
            Node* temp=wp->next;
            wp->next=temp->next;
            temp->next=nodebeforeSublist->next;
            nodebeforeSublist->next=temp;
            l++;
        }
        return dummy->next;
    }
    Node* reverseInGrpK(Node* head,int k) {
        int c=count(head);
        int q=c/k;
        int r=c%k;
        int left=1;
        int right=k;
        Node* ans=NULL;
        while(q){
            
            ans=sublistReverse(head,left,right);
            left=right+1;
            right=right+k;
            q--;
            head=ans;
        }
        // last grp nhi bana 
        // if(r){
        //     left=right+1;
        //     right=right+r;
        //     ans=sublistReverse(head,left,right);
        // }
        return ans;
    }

    int main(){
        Node * head=NULL;
        LLcreate(head);
        LLprint(head);
        cout<<endl;
        
       int k;cin>>k;
       head=reverseInGrpK(head,k);
       LLprint(head);
       return 0;
    }