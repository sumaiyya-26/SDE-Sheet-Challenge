#include<bits/stdc++.h>
using namespace std;

int matrixMultiplication(vector<int> &arr, int N)
{
    // Write your code here.
    vector<vector<int>>dp(N+1,vector<int>(N-1,0));
    for(int g=0;g<N-1;g++){
        for(int i=0,j=g;j<N-1;j++,i++){
            if(g==0)dp[i][j]=0;
            else if(g==1)dp[i][j]=arr[i]*arr[j]*arr[j+1];
            else{
                int mn=INT_MAX;
                for(int k=i;k<j;k++){
                    int leftcost=dp[i][k];
                    int rightcost=dp[k+1][j];
                    int mulcost=arr[i]*arr[k+1]*arr[j+1];
                    int totalcost=leftcost+rightcost+mulcost;
                    if(totalcost<mn){
                        mn=totalcost;
                    }
                }
                dp[i][j]=mn;
            }
        }
    }
    return dp[0][N-2];
}
int main(){
    int n;cin>>n;
    vector<int>v;
    for(int i=0;i<n;i++){int x;cin>>x;v.push_back(x);}
    cout<<matrixMultiplication(v,n);
}