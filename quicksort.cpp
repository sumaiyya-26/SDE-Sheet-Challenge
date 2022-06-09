#include<bits/stdc++.h>
using namespace std;
void swap(int &a,int &b){int temp=a;a=b;b=temp;}
int partition (int arr[], int low, int high)
{
    int i=low-1,j;
    int pivotElement=arr[high];
    for(j=low;j<high;j++){
        if(arr[j]<=pivotElement){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    i++;
    swap(arr[i],arr[j]);
    return i;
}
void quickSort(int arr[], int low, int high)
{
    if(low<high){
        int pivotIndex=partition(arr,low,high);
        quickSort(arr,low,pivotIndex-1);
        quickSort(arr,pivotIndex+1,high);
    }
}
int main(){
    int n;cin>>n;
    int a[n];
    for(int i=0;i<n;i++)cin>>a[i];
    quickSort(a,0,n-1);
    for(int i=0;i<n;i++)cout<<a[i]<<" ";
}