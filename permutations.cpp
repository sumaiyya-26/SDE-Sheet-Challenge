    #include<bits/stdc++.h>
    using namespace std;
    void swap(int &a,int &b){int temp=a;a=b;b=temp;}
    
    void f(int i,vector<int>a,vector<vector<int>>&ans,int n,vector<int>&ds){
        if(i==n){
            ans.push_back(ds);
            return;
        }
        for(int j=i;j<n;j++){
            swap(a[i],a[j]);
            ds.push_back(a[i]);
            f(i+1,a,ans,n,ds);
            ds.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>ds;
        f(0,nums,ans,nums.size(),ds);
        return ans;
    }
    

    int main(){
        int n;cin>>n;
        vector<int>v;
        for(int i=0;i<n;i++){int x;cin>>x;v.push_back(x);}
        vector<vector<int>>ans=permute(v);
    }