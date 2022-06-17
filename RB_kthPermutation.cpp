  #include<bits/stdc++.h>
  using namespace std;
  string getPermutation(int n, int k) {
        int f=1;
        for(int i=1;i<n;i++){
            f=f*i;
        }
        vector<int>v;
        for(int i=1;i<=n;i++)v.push_back(i);
        string ans="";
        k=k-1;
        while(1){
            ans+=to_string(v[k/f]);
            v.erase(v.begin()+k/f);
            if(v.size()==0)break;
            k=k%f;
            f=f/v.size();
        }
        return ans;
    }
    int main(){
        int n,k;cin>>n>>k;
        string ans=getPermutation(n,k);
        cout<<ans;
    }