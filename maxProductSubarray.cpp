#include<bits/stdc++.h>
using namespace std;
void swap(int &a,int &b){
    int temp=a;a=b;b=temp;
}
int maximumProduct(vector<int> &arr, int n)
{
	// Write your code here
    int mx=arr[0];
    int mn=arr[0];
    int ans=arr[0];
    for(int i=1;i<n;i++){
        if(arr[i]<0){
            swap(mx,mn);
        }
        mx=max(mx*arr[i],arr[i]);
        mn=min(mn*arr[i],arr[i]);
        ans=max(ans,mx);
    }
    return ans;
}
int main(){
    int n;cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++){int x;cin>>x;a[i]=x;}
    maximumProduct(a,n);
}