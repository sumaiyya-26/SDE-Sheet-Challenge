    #include<bits/stdc++.h>
    using namespace std;
       int longestConsecutive(vector<int>& nums) {
        set<int>s;
        int mx=0;
        for(int i=0;i<nums.size();i++)s.insert(nums[i]);
        for(int i=0;i<nums.size();i++){
            int c;
            if(!s.count(nums[i]-1)){
                int x=nums[i];
                c=1;
                while(s.count(x+1)){
                    c++;
                    x++;
                }
                mx=max(mx,c);
            }
        }
        return mx;
    }
    int main(){
        int n;cin>>n;
        int target;cin>>target;
        vector<int>v;for(int i=0;i<n;i++){int x;cin>>x;v.push_back(x);}
        longestConsecutive(v);
    }