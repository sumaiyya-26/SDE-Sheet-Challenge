   #include<bits/stdc++.h>
    using namespace std;
    void swap(char &a,char &b){char temp=a;a=b;b=temp;}
    
    void f(int i,string a,vector<string>&ans,int n,string &osf){
        if(i==n){
            ans.push_back(osf);
            return;
        }
        for(int j=i;j<n;j++){
            swap(a[i],a[j]);
            osf+=a[i];
            f(i+1,a,ans,n,osf);
            int x=osf.length();
            x-=1;
            osf.erase(osf.begin()+x);
        }
    }
    vector<string>findPermutations(string &nums) {
        vector<string>ans;
        string osf="";
        f(0,nums,ans,nums.size(),osf);
        return ans;
    }
    int main(){
        string s;
        cin>>s;
        vector<string> ans=findPermutations(s);
        for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
    }