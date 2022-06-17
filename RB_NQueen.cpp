#include<bits/stdc++.h>
using namespace std;
bool issafe(int i,int j,int n,vector<vector<int>>&board){
    int x=i,y=j;
    while(y>=0){
        if(board[x][y]==1)return false;
        y--;
    }
    x=i;y=j;
    while(x>=0 && y>=0){
        if(board[x][y]==1)return false;
        x--;
        y--;
    }
    x=i;y=j;
    while(x<n && y>=0){
        if(board[x][y]==1)return false;
        x++;
        y--;
    }
    return true;
}
    void addsol(vector<vector<int>>&ans,vector<vector<int>>&board,int n){
        vector<int>temp;
        for(int j=0;j<n;j++){
            for(int i=0;i<n;i++){
                if(board[i][j]==1){
                    temp.push_back(i+1);
                    break;
                }
            }
        }
        ans.push_back(temp);
    }
    void f(int j,int n,vector<vector<int>>&board,vector<vector<int>>&ans){
        if(j==n){
            addsol(ans,board,n);
            return;
        }
        for(int i=0;i<n;i++){
          if(issafe(i,j,n,board)){
            board[i][j]=1;
            f(j+1,n,board,ans);
            board[i][j]=0;
          }
        }  
    }
    vector<vector<int>> nQueen(int n) {
        // code here
        vector<vector<int>>ans;
        vector<vector<int>>board(n,vector<int>(n,0));
        f(0,n,board,ans);
        // cout<<ans.size()<<endl;
        return ans;
    }

    int main(){
        int n;cin>>n;
        vector<vector<int>>ans=nQueen(n);
        for(int i=0;i<ans.size();i++){
            for(int j=0;j<ans[i].size();j++){
                cout<<ans[i][j]<<" ";
            }
            cout<<endl;
        }
        return 0;
    }