#include<bits/stdc++.h>
using namespace std;
    bool isvalid(int i,int j,int n,int m){
        if(i>=0 && i<n && j>=0 && j<m)return true;
        return false;
    }
    int f(int i,int j,vector<vector<int>>& board){
        int c=0;
        int n=board.size();
        int m=board[0].size();
        int di[8]={-1,1,0,0,-1,1,1,-1};  
        int dj[8]={0,0,-1,1,-1,1,-1,1};  
        int idx=0;
        while(idx<8){
            if(isvalid(i+di[idx],j+dj[idx],n,m) && board[i+di[idx]][j+dj[idx]] && board[i+di[idx]][j+dj[idx]]!=-3)c++;
            idx++;
        }
      return c;  
    }
    void gameOfLife(vector<vector<int>>& board) {
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[i].size();j++){
                if(board[i][j]==0){
                    int live=f(i,j,board);
                    if(live==3)board[i][j]=-3;
                }
                else if(board[i][j]==1){
                    int live=f(i,j,board);
                    if(live<2)board[i][j]=-1;
                    else if(live==2 || live==3)board[i][j]=-2;
                    else board[i][j]=-1;
                }
            }
        }
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[i].size();j++){
                if(board[i][j]==-1)board[i][j]=0;
                else if(board[i][j]==-2 || board[i][j]==-3)board[i][j]=1;
            }
        }
    }

    int main(){
        int n,m;
        cin>>n>>m;
        vector<vector<int>>v(n,vector<int>(m,0));
        for(int i=0;i<n;i++){for(int j=0;j<m;j++){int x;cin>>x;v[i][j]=x;}}
        gameOfLife(v);
        for(int i=0;i<n;i++){for(int j=0;j<m;j++){cout<<v[i][j]<<" ";}cout<<endl;}

    }