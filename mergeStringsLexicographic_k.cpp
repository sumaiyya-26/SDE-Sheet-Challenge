//merge 2 strings in lexicographical order(sorted order)
//restriction: U cants take more than k elements from the same string in one go 
//stop if any of the string is empty

#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n,m,k;cin>>n>>m>>k;
    string a,b;
    cin>>a;
    cin>>b;
    
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    
    int c1=0,c2=0;
    int i=0,j=0;
    string c="";
    
    while(i<n && j<m){
        if(a[i]==b[j]){
            if(n==m){
                if(c1<k){c+=a[i];i++;c1++;c2=0;}
                else if(c2<k){c+=b[j];j++;c2++;c1=0;}
            }
            else if(n<m){
                if(c1<k){c+=a[i];i++;c1++;c2=0;}
                else if(c2<k){c+=b[j];j++;c2++;c1=0;}
            }
            else{
                if(c2<k){c+=b[j];j++;c2++;c1=0;}
                else if(c1<k){c+=a[i];i++;c1++;c2=0;}
            }
        }
        else if(a[i]<b[j]){
            if(c1<k){c+=a[i];i++;c1++;c2=0;}
            else if(c2<k){c+=b[j];j++;c2++;c1=0;}
        }
        else{
            if(c2<k){c+=b[j];j++;c2++;c1=0;}
            else if(c1<k){c+=a[i];i++;c1++;c2=0;}
        }
    }
    cout<<c<<endl;
    
}
int main(){
    int t;cin>>t;
    while(t--)solve();
}