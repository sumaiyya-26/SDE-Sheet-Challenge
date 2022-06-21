#include<iostream>
using namespace std;
typedef struct avlnode
{
    int data,h;
    struct avlnode *lc=NULL,*rc=NULL;
}*avlptr;
avlptr root=NULL;
int height(avlptr t)
{
    int left,right;
    if(t->lc)left=t->lc->h;
    else left=0;
    if(t->rc)right=t->rc->h;
    else right=0;
    return 1+max(left,right);
}
int diff(avlptr t)
{
    int left,right;
    if(t->lc)left=t->lc->h;
    else left=0;
    if(t->rc)right=t->rc->h;
    else right=0;
    return left-right;
}
avlptr LL(avlptr t)
{
    avlptr tl,tlr;
    tl=t->lc;
    tlr=t->lc->rc;
    
    tl->rc=t;
    t->lc=tlr;
    t->h=height(t);
    tl->h=height(tl);
    
    if(root==t)
    root=tl;
    return tl;
}
avlptr RR(avlptr t)
{
    avlptr tl,tlr;
    tl=t->rc;
    tlr=t->rc->lc;
    
    tl->lc=t;
    t->rc=tlr;
    t->h=height(t);
    tl->h=height(tl);
    
    if(root==t)
    root=tl;
    return tl;
}

avlptr RL(avlptr t)
{
    avlptr tl,tlr;
    tl=t->rc;
    tlr=t->rc->lc;
    
    t->rc=tlr->lc;
    tl->lc=tlr->rc;
    tlr->rc=tl;
    tlr->lc=t;
    
    tl->h=height(tl);
    t->h=height(t);
    tlr->h=height(tlr);
    
    if(root==t)
    root=tlr;
    
    return tlr;
}
avlptr LR(avlptr t)
{
    avlptr tl,tlr;
    tl=t->lc;
    tlr=t->lc->rc;
    
    t->lc=tlr->rc;
    tl->rc=tlr->lc;
    tlr->lc=tl;
    tlr->rc=t;
    
    tl->h=height(tl);
    t->h=height(t);
    tlr->h=height(tlr);
    
    if(root==t)
    root=tlr;
    
    return tlr;
}
avlptr create(avlptr t,int n)
{
    avlptr temp=NULL;
    if(t==NULL)
    {
        temp=new avlnode;
        temp->data=n;
        temp->lc=temp->rc=NULL;
        temp->h=1;
        return temp;
    }
    if(n<t->data)
    t->lc=create(t->lc,n);
    else if(n>t->data)
    t->rc=create(t->rc,n);
    
    t->h=height(t);
    
    if(diff(t)==2 && diff(t->lc)==1)
    return LL(t);
    else if(diff(t)==2 && diff(t->lc)==-1)
    return LR(t);
    else if(diff(t)==-2 && diff(t->rc)==-1)
    return RR(t);
    else if(diff(t)==-2 && diff(t->rc)==1)
    return RL(t);
    else return t;
}
void preorder(avlptr t)
{
    if(t==NULL)return;
    cout<<t->data<<" ";
    preorder(t->lc);
    preorder(t->rc);
}
int main()
{
    int n;cin>>n;
    root=create(root,n);
    preorder(root);cout<<endl;
    while(cin>>n && n!=-1)
    {
        create(root,n);
        preorder(root);
        cout<<endl;
    }
}