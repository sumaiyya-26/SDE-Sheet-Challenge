#include<bits/stdc++.h>
using namespace std;
const int N=9;
    bool isValid(int x,int y,int k,int grid[N][N]){
        int j=0;
        while(j<9){
            if(grid[x][j]==k)return false;
            j++;
        }
        int i=0;
        while(i<9){
            if(grid[i][y]==k)return false;
            i++;
        }
        if(x%3==0)i=x;
        else if(x%3==1)i=x-1;
        else if(x%3==2)i=x-2;
        
        if(y%3==0)j=y;
        else if(y%3==1)j=y-1;
        else if(y%3==2)j=y-2;
        
        for(int p=i;p<i+3;p++){
            for(int q=j;q<j+3;q++){
                if(grid[p][q]==k)return false;
            }
        }
        return true;
    }
    bool helper(int grid[N][N],int i,int j){
        if(i==N)return true;
        int nrow=0;
        int ncol=0;
        if(j!=N-1){
            nrow=i;
            ncol=j+1;
        }
        else{
            nrow=i+1;
            ncol=0;
        }
        if(grid[i][j]!=0){
            if(helper(grid,nrow,ncol))return true;
        }
        else{
            for(int k=1;k<=9;k++){
                if(isValid(i,j,k,grid)){
                    grid[i][j]=k;
                    if(helper(grid,nrow,ncol))return true;
                    else grid[i][j]=0;
                }
            }
        }
        return false;
    }
    bool SolveSudoku(int grid[N][N])  
    { 
        // Your code here
        return helper(grid,0,0);
    }
    
    //Function to print grids of the Sudoku.
    void printGrid (int grid[N][N]) 
    {
        // Your code here 
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                cout<<grid[i][j]<<" ";
            }
        }
    }

    int main(){
        int grid[9][9];
        for(int i=0;i<9;i++){for(int j=0;j<9;j++)cin>>grid[i][j];}
        SolveSudoku(grid);
        printGrid(grid);
    }