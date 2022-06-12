#include<bits/stdc++.h>
using namespace std;
   
   // int goldMemoization(int i,int j,int n,int m ,vector<vector<int>>g,vector<vector<int>>&dp){
        // if(i<0 || i>=n || j>=m){
        //     return 0;
        // }
        // if(dp[i][j]!=-1)return dp[i][j];
        // int a=gold(i,j+1,n,m,g,dp);
        // int b=gold(i-1,j+1,n,m,g,dp);
        // int c=gold(i+1,j+1,n,m,g,dp);
        // int maxgold=max(a,max(b,c));
        // return dp[i][j]=g[i][j]+maxgold;
    // }
        int gold(int x,int y,int n,int m ,vector<vector<int>>g,vector<vector<int>>&dp){
        for(int j=m-1;j>=0;j--){
            for(int i=n-1;i>=0;i--){
                int a=0,b=0,c=0;
                if(j+1<=m-1)a=dp[i][j+1];
                if(i-1>=0 && j+1<=m-1)b=dp[i-1][j+1];
                if(i+1<=n-1 && j+1<=m-1)c=dp[i+1][j+1];
                int maxgold=max(a,max(b,c));
                dp[i][j]=maxgold +g[i][j];
            }
        }
        int mx=INT_MIN;
        for(int i=0;i<=n-1;i++){
            mx=max(dp[i][0],mx);
        }
        return mx;
    }
    int maxGold(int n, int m, vector<vector<int>> M)
    {
        // code here
       int g=INT_MIN;
        vector<vector<int>>dp(n,vector<int>(m,0));
       for(int i=0;i<n;i++){
        //   vector<vector<int>>dp(n,vector<int>(m,-1));
           int goldCollected=gold(i,0,n,m,M,dp);
           g=max(g,goldCollected);
       }
       return g;
    }
    int main(){
        int n,m;cin>>n>>m;
        vector<vector<int>>g(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
               int x;cin>>x;
               g[i][j]=x;
            }
        }
        cout<<maxGold(n,m,g);
    }