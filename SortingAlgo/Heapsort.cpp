#include <iostream>
using namespace std;

void MaxHeapify(int* arr, int heapSize, int i){
     auto largest = i;
     auto left = 2*i+1;
     auto right = 2*i+2;
     if(left<heapSize && arr[left]>arr[i]){
          largest = left; 
     }
     if(right<heapSize && arr[right]>arr[largest]){
          largest = right; 
     }
     if (largest != i) {
        auto temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        MaxHeapify(arr, heapSize, largest);

}
}

void BuildMaxHeap(int* arr, int size){
    for(int i=size/2-1;i>=0;i--){
         MaxHeapify(arr, size, i);
     }
}
void Heapsort(int* arr, int size){
     BuildMaxHeap(arr, size);
     for (int i=size-1; i>=2;i--) {
        auto temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        MaxHeapify(arr, i, 0);
    }      
}

int  main(){
    int size;
    cin>>size;
    int* arr = new int[size];
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    Heapsort(arr, size);
    if(arr[0]>arr[1]){
        auto temp = arr[0];
        arr[0] = arr[1];
        arr[1] = temp;
    }
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
}
