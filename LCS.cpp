#include<bits/stdc++.h>
using namespace std;
int lcs(string s, string t)
{
	//Write your code here
    int x=s.length();
    int y=t.length();
    int dp[x+1][y+1];
    for(int i=0;i<=x;i++){for(int j=0;j<=y;j++){dp[i][j]=0;}}
    for(int i=1;i<=s.length();i++){
        for(int j=1;j<=t.length();j++){
            if(s[i-1]==t[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    return dp[x][y];
}
int main(){
    string s1,s2;
    cin>>s1>>s2;
    cout<<lcs(s1,s2);
}