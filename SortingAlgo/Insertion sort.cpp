#include<iostream>
using namespace std;
int main()
{ 
    int arr[] = {34,3423,13,5,345,65,3,2,34,5,643,4,4};
    int n = sizeof(arr)/sizeof(arr[0]);
    for(int i=1;i<n;i++){
        int k = arr[i];
        int j = i-1;
        while(j>=0 && k<arr[j]){
            arr[j+1] = arr[j];
            arr[j] = k;
            j--;
        }
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";  
    }
    return 0;
}
