#include<bits/stdc++.h>
using namespace std;

bool isValid(int node,int k,int n,bool graph[101][101],int color[]){
    for(int v=0;v<n;v++){
        if(v!=node && graph[v][node]==1 && color[v]==k)return false;
    }
    return true;
}
bool solve(int node,int color[],int m,int n,bool graph[101][101]){
    if(node==n){
        return true;
    }
    for(int k=1;k<=m;k++){
        if(isValid(node,k,n,graph,color)){
            color[node]=k;
            if(solve(node+1,color,m,n,graph))return true;
            else color[node]=0;
        }
    }
    return false;
}
bool graphColoring(bool graph[101][101], int m, int n) {
    int colour[n]={0};
    if(solve(0,colour,m,n,graph)==true)return true;
    return false;
}
int main(){
    int n,e;
    cin>>n>>e;
    bool graph[101][101]={0};
    for(int i=1;i<=e;i++){
        int u,v;
        cin>>u>>v;
        graph[u][v]=1;
        graph[v][u]=1;
    }
    int m;cin>>m;
    cout<<graphColoring(graph,m,n);
}