   #include<bits/stdc++.h>
   using namespace std;
    void setZeroes(vector<vector<int>>& matrix) {
        int col=1;
        for(int i=0;i<matrix.size();i++){
            if(matrix[i][0]==0)col=0;
            for(int j=1;j<matrix[0].size();j++){
                if(matrix[i][j]==0){
                    matrix[0][j]=0;
                    matrix[i][0]=0;
                }
            }
        }
        for(int i=matrix.size()-1;i>=0;i--){
            for(int j=matrix[i].size()-1;j>0;j--){
                if(matrix[i][0]==0 || matrix[0][j]==0){
                    matrix[i][j]=0;
                }
            }
            if(col==0)matrix[i][0]=0;
        }
    }
    int main(){
        int n,m;
        cin>>n>>m;
        vector<vector<int>>v(n,vector<int>(m,0));
        for(int i=0;i<n;i++){for(int j=0;j<m;j++){int x;cin>>x;v[i][j]=x;}}
        setZeroes(v);
    }