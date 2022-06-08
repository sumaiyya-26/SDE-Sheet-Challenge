    #include<bits/stdc++.h>
    using namespace std;
    //TC:O(N! * N)
    //SC:O(1)
    void swap(int &a,int &b){int temp=a;a=b;b=temp;}
    void f(int i,vector<int>a,vector<vector<int>>&ans,int n){
        if(i==n){
            ans.push_back(a);
            return;
        }
        for(int j=i;j<n;j++){
            swap(a[i],a[j]);
            f(i+1,a,ans,n);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        f(0,nums,ans,nums.size());
        return ans;
    }
    int main(){
        int n;cin>>n;
        vector<int>v;
        for(int i=0;i<n;i++){int x;cin>>x;v.push_back(x);}
        vector<vector<int>>ans=permute(v);
    }