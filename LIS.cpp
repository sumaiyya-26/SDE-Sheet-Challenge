#include<bits/stdc++.h>
using namespace std;

int recur(int a[],int i,int n,int prev,int cnt){
    if(i>=n)return cnt;
    int pick=0;
    if(a[i]>a[prev]){
        pick=recur(a,i+1,n,i,cnt+1);
    }
    int notpick=recur(a,i+1,n,prev,cnt);
    return max(pick,notpick);
}
int memosol(int a[],int i,int prev,int cnt,int n,int **dp){
    if(i==n)return 0;
    if(dp[i][prev+1]!=-1)return dp[i][prev+1];
    int pick=0;
    if(a[i]>a[prev] || prev==-1){
        pick=1+memosol(a,i+1,i,cnt,n,dp);
    }
    int notpick=0+memosol(a,i+1,prev,cnt,n,dp);
    return dp[i][prev+1]=max(pick,notpick);
}

int dpsol(int a[],int n,int **dp){
//     vector<vector<int>>dp(n+1,vector<int>(n+1,0));
    for(int i=n-1;i>=0;i--)
    {
        for(int j=i-1;j>=-1;j--)
        {
            int len=0+dp[i+1][j+1];
            if( j==-1 || a[i]>a[j])
            {
                len=max(len,1+dp[i+1][i+1]);
            }
            dp[i][j+1]=len;
        }
    } 
    return dp[0][-1+1];
}
int longestIncreasingSubsequence(int arr[], int n)
{
    // Write Your Code here
    return recur(arr,0,n,-1,0);
    int** dp =new int* [n];
    for(int i=0;i<n;i++){
        dp[i]=new int[n+1];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<=n;j++){
            dp[i][j]=-1;
        }
    }
//     return memosol(arr,0,-1,0,n,dp);
    
    int** DP =new int* [n+1];
    for(int i=0;i<=n;i++){
        DP[i]=new int[n+1];
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            DP[i][j]=0;
        }
    }
    return dpsol(arr,n,DP);
}
int main(){
    int n;cin>>n;
    int a[n];
    for(int i=0;i<n;i++)cin>>a[i];
    cout<<longestIncreasingSubsequence(a,n);
}