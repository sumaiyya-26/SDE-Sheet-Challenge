       
       #include<bits/stdc++.h>
       using namespace std;
        int f1(int j,int i,vector<vector<int>>g,vector<vector<int>>mvc,int n,int m){
         if(i==n-1 && (j>=0 && j<=m-1)){
             return g[i][j];
         }
        if(i>=n || (j<0 || j>=m) )return INT_MAX;
        int mn=INT_MAX;
        for(int col=0;col<m;col++){
            mn=min(mn,f1(col,i+1,g,mvc,n,m)+mvc[g[i][j]][col]);
        }
        return mn+g[i][j];
    }
    
    
    
    
       int f1memo(int j,int i,vector<vector<int>>g,vector<vector<int>>mvc,int n,int m,vector<vector<int>>&dp){
         if(i==n-1 && (j>=0 && j<=m-1)){
             return g[i][j];
         }
        if(i>=n || (j<0 || j>=m) )return INT_MAX;
        if(dp[i][j]!=-1)return dp[i][j];
        int mn=INT_MAX;
        for(int col=0;col<m;col++){
            mn=min(mn,f1memo(col,i+1,g,mvc,n,m,dp)+mvc[g[i][j]][col]);
        }
        return dp[i][j]=mn+g[i][j];
    }
    
    
    
    int f1Tab(vector<vector<int>>g,vector<vector<int>>mvc,int n,int m,vector<vector<int>>&dp){
            for(int j=0;j<m;j++){
                dp[n-1][j]=g[n-1][j];
            }
            int mn=INT_MAX;
        for(int i=n-2;i>=0;i--){
            for(int j=0;j<m;j++){
                mn=INT_MAX;
                for(int col=0;col<m;col++){
                    mn=min(mn,dp[i+1][col]+mvc[g[i][j]][col]);
                }
                dp[i][j]=g[i][j]+mn;
            }
        }
        int ans=INT_MAX;
        for(int j=0;j<m;j++){
            ans=min(ans,dp[0][j]);
        }
        return ans;

    }
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int mn=INT_MAX;
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        vector<vector<int>>dpTab(n,vector<int>(m,0));
        // for(int j=0;j<grid[0].size();j++)
        // {
            // int x=f1(j,0,grid,moveCost,n,m);
            // int x=f1memo(j,0,grid,moveCost,n,m,dp);
            // mn=min(x,mn);
        // } 
        // return mn;
        return f1Tab(grid,moveCost,n,m,dpTab);
    }

    int main(){
        int n,m;cin>>n>>m;
        vector<vector<int>>g(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int x;cin>>x;g[i][j]=x;
            }
        }
        vector<vector<int>>moveCost(n*m,vector<int>(n,0));
        for(int i=0;i<n*m;i++){
            for(int j=0;j<n;j++){
                int x;cin>>x;g[i][j]=x;
            }
        }
        return minPathCost(g,moveCost);
    }