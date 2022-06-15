    #include<bits/stdc++.h>
    using namespace std;
    struct ListNode{
        int val;
        ListNode* next;
        ListNode(int x){
            val=x;
            next=NULL;
        }
    };
    
    void LLcreate(ListNode * &head){
        int x;cin>>x;
        if(x==-1)return;
        head=new ListNode(x);
        LLcreate(head->next);
    }
    void LLprint(ListNode *head){
        if(head==NULL){cout<<"NULL";return;}
        cout<<head->val<<"->";
        LLprint(head->next);
    }
    void swap(ListNode * &l1,ListNode * &l2){
        ListNode *temp=l1;l1=l2;l2=temp;
    }
    ListNode *merge(ListNode *l1,ListNode *l2,int st,int mid,int en){
        if(l1==NULL && l2==NULL)return NULL;
        if(l1==NULL)return l2;
        if(l2==NULL)return l1;
        ListNode *temp;
        if(l1->val>l2->val){
            swap(l1,l2);
        }
        ListNode *head=l1;
        while(l1!=NULL && l2!=NULL){
            temp=NULL;
            while(l1!=NULL && l1->val<=l2->val){
                temp=l1;
                l1=l1->next;
            }
            temp->next=l2;
            swap(l1,l2);
        }
        return head;
    }
    ListNode *mergeSort(vector<ListNode*> lists,int st,int en){
        if(st==en)return lists[st];
        int mid=st+((en-st)/2);
        ListNode * head1=mergeSort(lists,st,mid);
        ListNode *head2=mergeSort(lists,mid+1,en);
        ListNode *head=merge(head1,head2,st,mid,en);
        return head;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0)return NULL;
        return mergeSort(lists,0,lists.size()-1);
    }
    int main(){
        int k;cin>>k;
        vector<ListNode *>v;
        for(int i=0;i<k;i++){
            ListNode *head=NULL;
            LLcreate(head);
            LLprint(head);
            cout<<endl;
            v.push_back(head);
        }
        ListNode *ans=mergeKLists(v);
        LLprint(ans);
    }