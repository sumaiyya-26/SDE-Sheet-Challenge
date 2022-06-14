#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    node *next;

    node(int val){
        data=val;
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
void makeLoop(node *head,int pos){
    int c=1;
    node *temp=head;
    while(c!=pos){
        head=head->next;
        c++;
    }
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=head;
}
bool isCycle(node *head){
    if(head==NULL || head->next==NULL)return false;
    node *fp=head,*sp=head;
    //any of the while loop conditions can be used;
    // while(fp->next!=NULL && fp->next->next!=NULL)
    while(fp!=NULL && fp->next!=NULL){
        fp=fp->next->next;
        sp=sp->next;
        if(sp==fp)return true;
    }
    return false;
}
void removeLoop(node *head){
    if(head==NULL || head->next==NULL)return;
    node *fp=head,*sp=head;

    // while(fp->next!=NULL && fp->next->next!=NULL)
    while(fp!=NULL && fp->next!=NULL){
        fp=fp->next->next;
        sp=sp->next;
        if(sp==fp){
            sp=head;
            while(sp->next!=fp->next){
                sp=sp->next;
                fp=fp->next;
            }
            fp->next=NULL;
            return;
        }
    }
}
node *headOfLoop(node *head){
    if(head==NULL || head->next==NULL)return NULL;
    node *fp=head,*sp=head;
     while(fp!=NULL && fp->next!=NULL){
        fp=fp->next->next;
        sp=sp->next;
        if(sp==fp){
            sp=head;
            while(sp!=fp){
                sp=sp->next;
                fp=fp->next;
            }
            return fp;
        }
    }
    return NULL;
}

int lengthOfLoop(node *head){
    if(head==NULL || head->next==NULL)return 0;
    node *fp=head,*sp=head;
    int c=0;
     while(fp!=NULL && fp->next!=NULL){
        fp=fp->next->next;
        sp=sp->next;
        if(sp==fp){
            sp=head;
            while(sp!=fp){
                sp=sp->next;
                fp=fp->next;
            }
            fp=fp->next;
            c++;
            while(sp!=fp){
                fp=fp->next;
                c++;
            }
            return c;
        }
    }
    return 0;
}

int main(){
    node *head=NULL;
    LLcreate(head);
    LLprint(head);
    int pos;
    cin>>pos;
    makeLoop(head,pos);
    // LLprint(head);infinite
    cout<<isCycle(head)<<endl;
    // removeLoop(head);
    // LLprint(head);
    node *headLoop=headOfLoop(head);
    cout<<headLoop->data<<endl;
    cout<<lengthOfLoop(head);
}