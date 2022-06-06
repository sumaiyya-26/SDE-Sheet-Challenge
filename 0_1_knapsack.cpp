#include<bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{
	// Write your code here
    int dp[n][w+1];
    for(int i=0;i<n;i++){for(int j=0;j<=w;j++){dp[i][j]=0;}}
    for(int j=weights[0];j<=w;j++)dp[0][j]=values[0];
    for(int i=1;i<n;i++){
        for(int j=1;j<=w;j++){
            int pick=0;
            if(weights[i]<=j){
                pick=values[i]+dp[i-1][j-weights[i]];
            }
            int notpick=dp[i-1][j];
            dp[i][j]=max(pick,notpick);
        }
    }
    return dp[n-1][w];
}
int main(){
    int n,w;
    cin>>n>>w;
    vector<int>values(n);
    vector<int>weights(n);
    for(int i=0;i<n;i++){int x;cin>>x;values[i]=x;}
    for(int i=0;i<n;i++){int x;cin>>x;weights[i]=x;}
    cout<<maxProfit(values,weights,n,w);
}