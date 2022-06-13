    
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
    Node *f(Node * head,int l,int r){
        if(head==NULL || l==r)return head;
        // int pos=0;
        int pos=1;
        // ListNode dummy(-1);
        // dummy.next=head;
        // ListNode *nodebeforeSublist= &dummy;
        // ListNode *nodebeforeSublist= head;
        Node *dummy=new Node(-1);
        dummy->next=head;
        Node *nodebeforeSublist= dummy;
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
        // return head;
    }
    Node* reverseBetween(Node* head, int l, int r) {
        if(head==NULL)return NULL;
        Node * ans=NULL;
        ans=f(head,l,r);
        return ans;
    }

    int main(){
        Node * head=NULL;
        LLcreate(head);
        LLprint(head);
        cout<<endl;
        
       int l,r;cin>>l>>r;
       LLprint(reverseBetween(head,l,r));
       return 0;
    }