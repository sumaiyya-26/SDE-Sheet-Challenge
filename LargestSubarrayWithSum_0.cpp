    #include<bits/stdc++.h>
    using namespace std;

    //Tle only 185 tcs are passing
    //vvvimp unordered map
    //we can implement like this too.
    // if()
    // else{
    //     if
    //     else
    // }
    int hashmap(vector<int>a,int n){
        unordered_map<int,int>mp;
        int mx=0;
        int prefixsum=0;
        for(int i=0;i<n;i++){
            prefixsum+=a[i];
            if(prefixsum==0)mx=i+1;
            else if(mp.find(prefixsum)!=mp.end()){
                mx=max(mx,i-mp[prefixsum]);
            }
            else{
                mp[prefixsum]=i;
            }
        }
        return mx;
    }
    int maxLen(vector<int>&A, int n)
    {   
        // Your code here
        int mxlen=0;
        int prefix[n+1]={0};
        prefix[0]=0;
        for(int i=1;i<=n;i++)
        prefix[i]=prefix[i-1]+A[i-1];
        
        for(int i=1;i<=n;i++){
            int sum=0;
            for(int j=0;j<i;j++){
                sum=prefix[i]-prefix[j];
                if(sum==0){
                    mxlen=max(mxlen,i-j);
                }
            }
        }
        
        int ans=hashmap(A,n);
    //   return mxlen;
    return ans;
    }
    int main(){
        int n;cin>>n;
        vector<int>v;for(int i=0;i<n;i++){int x;xin>>x;v.push_back(x);}
        cout<<maxLen(v,n);
    }