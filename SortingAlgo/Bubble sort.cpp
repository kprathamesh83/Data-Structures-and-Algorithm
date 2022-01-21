#include<iostream>
using namespace std;
int main(){
    int a[] = {34,3423,13,5,345,65,3,2,34,5,643,4,4};
    int n = sizeof(a)/sizeof(a[0]);
    for(int i=0;i<n-1;i++){
         for(int j=0;j<n-i-1;j++){
             if(a[j]>a[j+1]){
                 auto temp = a[j+1];
                 a[j+1] = a[j];
                 a[j] = temp;
             } 
         }
    }
    for (int i : a){
        cout<<i<<" ";
    }
    
}
