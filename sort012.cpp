#include <bits/stdc++.h> 
using namespace std;
void bruteforce(int *arr, int n)
{
   //   Write your code here
   //    TC:O(n^2)
   //    SC:O(n)
    int ans[n];
    int j=1;
    int x=j;

        ans[0]=arr[0];
    for(int i=1;i<n;i++){
        x=j;
        while(ans[j-1]>arr[i]){
            ans[j]=ans[j-1];
            j--;
        }
        ans[j]=arr[i];
        j=x+1;
    }
    for(int i=0;i<n;i++)arr[i]=ans[i];
}

void swap(int &a,int &b){int temp=a;a=b;b=temp;}
void sort012(int a[],int n){
    int low=0;int mid=0;
    int high=n-1;
    while(mid<=high){
        switch(a[mid]){
            case 0: {swap(a[mid],a[low]);
                    mid++;
                    low++;
                    break;}
            case 1:{mid++;
                   break;}
            case 2:{swap(a[mid],a[high]);
                high--;  
                break; }   
        }
    }
}
int main(){
    int n;cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)cin>>arr[i];
    sort012(arr,n);
    for(int i=0;i<n;i++)cout<<arr[i]<<" ";
}