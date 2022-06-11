   #include<bits/stdc++.h>
   using namespace std;
   
    int lengthOfLongestSubstring(string s) {
       unordered_map<char,int>mp; 
       int low=0,high=0,len=0;
       while(high<s.length()){
           if(mp.find(s[high])!=mp.end()){
               if(mp[s[high]]>=low && mp[s[high]]<=high){
                   low=mp[s[high]]+1;
                   len=max(len,high-low+1);
                   mp[s[high]]=high;
               }
               else{
                   len=max(len,high-low+1);
                   mp[s[high]]=high;
               }
           }
           else{
               mp.insert({s[high],high});
               len=max(len,high-low+1);
           }
           high++;
       }
        return len;
    }

    int main(){
        string s;cin>>s;
        cout<<lengthOfLongestSubstring(s);
    }