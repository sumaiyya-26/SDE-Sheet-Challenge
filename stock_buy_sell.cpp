#include <bits/stdc++.h> 
using namespace std;
  int maxProfit(vector<int>& a) {
        int b=0,s=0,profit=0;
        while(s<a.size()){
            if(a[s]-a[b]<0){
                b=s;
            }
            else{
                profit=max(profit,a[s]-a[b]);
            }  
            s++;
        }
        return profit;
    }
    int main(){
        int n;cin>>n;
        vector<int>v;
        for(int i=0;i<n;i++){int x;cin>>x;v.push_back(x);}
        cout<<maxProfit(v);
    }