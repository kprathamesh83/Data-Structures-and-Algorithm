#include<iostream>
using namespace std;

void merge(int arr[], int mid, int low, int high){
     auto n = mid - low + 1;
     auto m = high - mid;
     auto *left = new int[n];
     auto *right = new int[m];
     int i = 0, j = 0, k = low;
     for(int a=0;a<n;a++){
         left[a] = arr[low+a];
     }  
    for(int a=0;a<m;a++){
         right[a] = arr[mid+a+1];
     }  
     while(i<n && j<m){
         if(left[i]<=right[j]){
             arr[k] = left[i];
             i++;
         }
         else {
             arr[k] = right[j];
             j++;
         }
         k++;
     }
     while(i<n){
         arr[k] = left[i];
         i++;
         k++;
     }
     while(j<m){
         arr[k] = right[j];
         j++;
         k++;
     }

}

void mergesort(int arr[], int low, int high){
    if(low < high){ 
       auto mid = (low + high)/2;
       mergesort(arr,low,mid);
       mergesort(arr,mid+1,high);
       merge(arr,mid,low,high);
    }
}

int main(){
    int arr[] = {34,3423,13,5,345,65,3,2,34,5,643,4,4};
    auto len = sizeof(arr)/sizeof(arr[0]);
    mergesort(arr,0,len-1);
    for(int i=0;i<len;i++){
        cout<<arr[i]<<" ";
    }    
    return 0;
}
