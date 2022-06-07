#include<bits/stdc++.h>
using namespace std;
int f(string s1,string s2,int n,int m){
    if(n==0){
        return m;
    }
    if(m==0){
        return n;
    }
    if(s1[n-1]==s2[m-1])return 0+f(s1,s2,n-1,m-1);
    int replace=1+f(s1,s2,n-1,m-1);
    int del=1+f(s1,s2,n-1,m);
    int insert=1+f(s1,s2,n,m-1);
    return min(min(del,insert),replace);
}
int memosoln(string s1,string s2,int n,int m,vector<vector<int>>&dp)
{
    if(n==0){
        return m;
    }
    if(m==0){
        return n;
    }
    if(dp[n-1][m-1]!=-1)return dp[n-1][m-1];
    if(s1[n-1]==s2[m-1])return 0+f(s1,s2,n-1,m-1);
    int replace=1+f(s1,s2,n-1,m-1);
    int del=1+f(s1,s2,n-1,m);
    int insert=1+f(s1,s2,n,m-1);
    return dp[n-1][m-1]=min(min(del,insert),replace);
}
int dpsoln(string s1,string s2,int n,int m,vector<vector<int>>&dp){
    for(int i=0;i<=n;i++){
        dp[i][0]=i;
    }
    for(int j=0;j<=m;j++){
        dp[0][j]=j;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s1[i-1]==s2[j-1]){
                dp[i][j]=dp[i-1][j-1];
            }
            else{
                int replace=1+dp[i-1][j-1];
                int del=1+dp[i-1][j];
                int insert=1+dp[i][j-1];
                dp[i][j]=min(replace,min(del,insert));
            }
        }
    }
    return dp[n][m];
}
int editDistance(string str1, string str2)
{
    //write you code here
    int n=str1.length();
    int m=str2.length();
//     return f(str1,str2,n,m);
//     vector<vector<int>>dp(n,vector<int>(m,-1));
//     return memosoln(str1,str2,n,m,dp);
       vector<vector<int>>dp(n+1,vector<int>(m+1,0));
       return dpsoln(str1,str2,n,m,dp);
}
int main(){
    string s1,s2;
    cin>>s1>>s2;
    cout<<editDistance(s1,s2);
}