   #include<bits/stdc++.h>
   using namespace std;
   void swap(int &a,int &b){int temp=a;a=b;b=temp;}
    void Reverse(vector<int>&v,int idx,int n){
        int s=n-idx;
        for(int i=idx,j=n-1;i<(idx+s/2);i++,j--){
            swap(v[i],v[j]);
        }
    }
    void nextPermutation(vector<int>& nums) {
        // next_permutation(nums.begin(),nums.end());
        // for(int i=0;i<nums.size();i++)cout<<nums[i]<<" ";
        int n=nums.size();
        int idx1=0,idx2=0,f=0;
        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1])
            {idx1=i;f=1;break;}
        }
        if(f){
        for(int i=n-1;i>=0;i--){
            if(nums[i]>nums[idx1]){
                idx2=i;
                break;
            }
        }
        swap(nums[idx1],nums[idx2]);
        Reverse(nums,idx1+1,n);
        }
        else Reverse(nums,0,n);
    }
    int main(){
        int n;cin>>n;
        vector<int>v;
        for(int i=0;i<n;i++){int x;cin>>x;v.push_back(x);}
    }