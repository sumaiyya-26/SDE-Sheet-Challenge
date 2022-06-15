    #include<bits/stdc++.h>
    using namespace std;
    
    struct Node{
        int val;
        Node *next;
        Node *random;
        Node(int x){
            val=x;
            next=NULL;
            random=NULL;
        }
    };
    Node* copyRandomList(Node* head) {
        Node *it=head, *front=head;
        while(it!=NULL){
            front=it->next;
            Node *copy=new Node(it->val);
            it->next=copy;
            copy->next=front;
            it=front;
        }
        it=head;
        while(it!=NULL){
            if(it->random!=NULL){
                it->next->random=it->random->next;
            }
            it=it->next->next;
        }
        it=head;
        Node *dummy=new Node(-1);
        Node *pseudoHead=dummy,*copy=dummy;
        while(it!=NULL){
            front=it->next->next;
            copy->next=it->next;
            copy=copy->next;
            it->next=front;
            it=front;
        }
        return dummy->next;
    }
    void LLcreate(Node* &head){
        int x;cin>>x;
        if(x==-1)return;
        head=new Node(x);
        LLcreate(head->next);
    }
    void LLprint(Node *head){
        if(head==NULL){cout<<"NULL";return;}
        if(head->random)cout<<"data = "<<head->val<<" random = "<<head->random->val<<" ->";
        else cout<<"data = "<<head->val<<" -> ";
        LLprint(head->next);
    }
    void LLcreateRandom(Node *h){
        Node *head=h;
        int pos,Ranpos;
        cin>>pos;
        pos-=1;
        while(pos && head!=NULL){
            head=head->next;
            pos--;
            if(pos==0){
                Node *temp=h;
                cin>>Ranpos;
                Ranpos--;
                while(Ranpos && temp!=NULL){
                    temp=temp->next;
                    Ranpos--;
                }
                head->random=temp;
            }
        }
    }
    int main(){
        Node *head=NULL;
        LLcreate(head);
        int q;cin>>q;
        while(q--)
        LLcreateRandom(head);
        LLprint(head);
        Node *copy=copyRandomList(head);
        LLprint(copy);
    }