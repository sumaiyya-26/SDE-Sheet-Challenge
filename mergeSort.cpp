   #include<bits/stdc++.h>
   using namespace std;
   //some error dont know what
//    1.TLE
//    2.wrong ans(in some Tcs)
//    3.wrong ans(in some TCs)
    void swap(int &a,int &b){int temp=a;a=b;b=temp;}
 void merge(int arr[], int l, int mid, int r)
    {

        // Extra _SPACE

        // Your code here
        //  int s1=mid-l+1;
        //  int s2=r-mid;
        //  int a1[s1];
        //  int a2[s2];
        //  for(int i=0;i<s1;i++)a1[i]=arr[i+l];
        //  for(int i=0;i<s2;i++)a2[i]=arr[mid+1+i];
        // int i=0,j=0,k=l;
        // while(i<s1 && j<s2){
        //      if(a1[i]<a2[j]){arr[k++]=a1[i];i++;}
        //      else if(a1[i]>a2[j]){arr[k++]=a2[j];j++;}
        //  }
        // while(i<s1){
        //      arr[k++]=a1[i];i++;
        //  }
        //  while(j<s2){
        //      arr[k++]=a2[j];j++;
        //  }

        
        // In_Place
        // TC:(O(n1*n2))
        // SC:O(1)

        // int i=l,j=mid;
        // while(i<mid && j<=r){
        //     if(arr[i]>arr[j]){
        //         swap(arr[i],arr[j]);
        //         int k=j+1;
        //         int key=arr[j];
        //         while(k<=r && arr[k]<key){
        //             arr[k-1]=arr[k];
        //             k++;
        //         }
        //         arr[k-1]=key;
        //     }
        //     i++;
        // }   





        // gap method 
        // TC:(O(nlog(n)))
        // SC:O(1)    

         int gap;
        int s1=mid-l+1;
        int s2=r-mid;
        if((s1+s2)%2==0){
            gap=(s1+s2)/2;
        }
        else gap=((s1+s2)/2)+1;
        while(gap!=0){
            int i=l,j=l+gap;
            while(i<=r && j<=r){
               if(arr[i]>arr[j])
               swap(arr[i],arr[j]);
               i+=gap;
               j+=gap;
            }
            gap=gap/2;
        }   
    }
    void mergeSort(int arr[], int l, int r)
    {
        //code here
        if(l<r){
            int mid=(l+r)/2;
            mergeSort(arr,l,mid);
            mergeSort(arr,mid+1,r);
            merge(arr,l,mid,r);
        }
    }
    int main(){
        int n;cin>>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        mergeSort(a,0,n-1);
    }