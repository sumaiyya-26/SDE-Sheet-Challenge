#include <bits/stdc++.h> 
using namespace std;
long long maxSubarraySum(int arr[], int n)
{
    long long mx=INT_MIN;
    long long currsum=0;
    for(int i=0;i<n;i++){
        if(currsum+arr[i]<0){
            mx=max(currsum,mx);
            currsum=0;
        }
        else currsum+=arr[i];
    }
    mx=max(mx,currsum); 
    return mx;
}
long long bruteforce(int arr[],int n){
    int c=0;
    int mx=INT_MIN;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int sum=0;
            for(int k=i;k<=j;k++)
            {
                sum+=arr[k];
            }
            mx=max(sum,mx);
        }
    }
    return mx;
}
long long quadratic(int arr[], int n)
{
    long long mx=INT_MIN;
    int prefix[n+1];
    prefix[0]=0;
    for(int i=1;i<=n;i++){
        prefix[i]=prefix[i-1]+arr[i-1];
    }
    for(int i=1;i<=n;i++){
        long long sum=0;
        for(int j=0;j<i;j++){
            sum=prefix[i]-prefix[j];
            mx=max(mx,sum);
        }
    }
    return mx;
}
long long kadane(int arr[],int n){

    long long mx=INT_MIN;
    long long currsum=0;
    for(int i=0;i<n;i++){
        currsum+=arr[i];
        if(currsum<0){
            currsum=0;
        }
        mx=max(mx,currsum);
    }
    return mx;
}

int main(){
    int n;cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)cin>>arr[i];
    // cout<<bruteforce(arr,n);
    // cout<<quadratic(arr,n);
    cout<<kadane(arr,n);
}