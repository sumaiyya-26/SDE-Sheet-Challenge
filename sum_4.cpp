    #include<bits/stdc++.h>
    using namespace std;
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            
            for(int j=i+1;j<n;j++)
            {
                int sum=nums[i]+nums[j];
                int low=j+1;
                int high=n-1;
                int t=target-sum;
                while(low<high)
                {
                    if(nums[low]+nums[high]<t)
                    {
                        low++;
                    }
                    else if (nums[low]+nums[high]>t)
                    {
                       high--;
                    }
                    else {
                        vector<int>temp;
                        temp.push_back(nums[i]);
                        temp.push_back(nums[j]);
                        temp.push_back(nums[low]);
                        temp.push_back(nums[high]);
                        ans.push_back(temp);
                        while(low<high && nums[low]==temp[2])low++;
                        while(low<high && nums[high]==temp[3])high--;
                }
            }
                while(j+1<n && nums[j+1]==nums[j])j++;
        }while(i+1<n && nums[i+1]==nums[i])i++;
    }
        return ans;
    }
    int main(){
        int n;cin>>n;
        int target;cin>>target;
        vector<int>v;for(int i=0;i<n;i++){int x;cin>>x;v.push_back(x);}
        fourSum(v,target);
    }