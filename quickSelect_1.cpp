#include<bits/stdc++.h>
using namespace std;
    void swap(int &a,int &b){
        int temp=a;a=b;b=temp;
    }
    int partition(int arr[],int l,int r){
        int i=l-1,j;
        int pivot=arr[r];
        for(j=l;j<r;j++){
            if(arr[j]<pivot){
                i++;
                swap(arr[i],arr[j]);
            }
        }
        i++;
        swap(arr[i],arr[j]);
        return i;
    }
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    int kthSmallest(int arr[], int l, int r, int k) {
        //code here
        int pivotIdx=partition(arr,l,r);
        if(pivotIdx==k-1){
            return arr[pivotIdx];
        }
        else if(pivotIdx<k-1){
            return kthSmallest(arr,pivotIdx+1,r,k);
        }
        else return kthSmallest(arr,l,pivotIdx-1,k);
    }
        int kthSmallest2(int arr[], int l, int r, int k) {
        if(l==r)return arr[l];
        int pivotIdx=partition(arr,l,r);
        int x=pivotIdx-l+1;
        if(k==x){
            return arr[pivotIdx];
        }
        else if(k<x){
            return kthSmallest(arr,l,pivotIdx-1,k);
        }
        else return kthSmallest(arr,pivotIdx+1,r,k-x);
    }
    int main(){
    int n;cin>>n;
    int k;cin>>k;
    int a[n];
    for(int i=0;i<n;i++)cin>>a[i];
    kthSmallest(a,0,n-1,k);
    for(int i=0;i<n;i++)cout<<a[i]<<" ";
}
