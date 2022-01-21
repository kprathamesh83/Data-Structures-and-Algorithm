#include<iostream>
using namespace std;

auto partion(int arr[],int low,int high){
    auto pivot = arr[low];
    int i=low,j=high;
    auto temp = 0;
    while(i<j){
        while(arr[i]<=pivot) i++;
        while(arr[j]>pivot) j--;
        if(i<j){
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;
    return j;
}

void quicksort(int arr[],int low, int high){
     if(low<high){
         auto part = partion(arr,low,high);
         quicksort(arr,low,part-1);
         quicksort(arr,part+1,high);
     }
}

int main(){
    int arr[] = {34,3423,13,5,345,65,3,2,34,5,643,4,4};
    auto len = sizeof(arr)/sizeof(arr[0]);
    quicksort(arr,0,len-1);
    for(auto i : arr){
        cout<<i<<" ";
    }
}
