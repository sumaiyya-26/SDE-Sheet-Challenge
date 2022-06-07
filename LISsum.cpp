#include<bits/stdc++.h>
using namespace std;
int recur(vector<int>a,int i,int previdx,int n){
    if(i==n)return 0;
    int pick=0;
    if(a[i]>a[previdx]){
        pick=a[i]+recur(a,i+1,i,n);
    }
    int notpick=recur(a,i+1,previdx,n);
    return max(pick,notpick);
}
int memosol(vector<int>a,int i,int previdx,int n,vector<vector<int>>&dp){
    if(i==n)return 0;
    int pick=0;
    if(a[i]>a[previdx]){
        pick=a[i]+memosol(a,i+1,i,n,dp);
    }
    if(dp[i][previdx+1]!=-1)return dp[i][previdx+1];
    int notpick=memosol(a,i+1,previdx,n,dp);
    return dp[i][previdx+1]=max(pick,notpick);
}
int maxIncreasingDumbbellsSum(vector<int> &rack, int n)
{
//     return recur(rack,0,-1,n);
    
//     int** dp= new int* [n];
//     for(int i=0;i<n;i++){
//         dp[i]=new int[n+1];
//     }
//     for(int i=0;i,n;i++){
//         for(int j=0;j<=n;j++){
//             dp[i][j]=-1;
//         }
//     }
    vector<vector<int>>dp(n,vector<int>(n+1,-1));
    return memosol(rack,0,-1,n,dp);
}
int main(){
    int n;
    cin>>n;
    vector<int>rack(n);
    for(int i=0;i<n;i++){int x;cin>>x;rack[i]=x;}
    cout<<maxIncreasingDumbbellsSum(rack,n);
}