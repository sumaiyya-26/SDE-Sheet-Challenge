   #include<bits/stdc++.h>
    using namespace std;
     void swap(char &a,char &b){char temp=a;a=b;b=temp;}
    
    void f(int i,string a,vector<string>&ans,int n){
        if(i==n){
            ans.push_back(a);
            return;
        }
        for(int j=i;j<n;j++){
            swap(a[i],a[j]);
            f(i+1,a,ans,n);
        }
    }
    vector<string>findPermutations(string &nums) {
        vector<string>ans;
        f(0,nums,ans,nums.size());
        return ans;
    }

    int main(){
        string s;
        cin>>s;
        vector<string> ans=findPermutations(s);
        for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
    }