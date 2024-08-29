#include <vector>
#include <iostream>
using namespace std;

void swap(int i,int j,vector<int> &arr) {
    int i1 = arr[i];
    int j1 = arr[j];

    i1 = i1 + j1;
    j1 = i1 - j1;
    i1 = i1 - j1;

    arr[i] = i1;
    arr[j] = j1;
}

int getPartitionIndex(vector<int>&arr,int low,int high) {
    int i=low;
    int j=high;
    int pivot = arr[low];

    while(i<j) {
        while(arr[i] <= pivot && i<=high) i++;

        while(arr[j] > pivot && j>=low) j--;

        if(i<j) swap(i,j,arr);
    }
    swap(j,low,arr);
    return j;
}

void quickSort(vector<int>&arr,int low,int high) {
    if(low<high) {
        int partitionIndex = getPartitionIndex(arr,low ,high);
        quickSort(arr,low,partitionIndex-1);
        quickSort(arr,partitionIndex+1,high);
    }
}

void printArray(vector<int> &arr) {
    cout<<"Sorted array is"<<endl;
    for(int i=0;i<arr.size();i++) {
        cout<<arr[i]<<endl;
    }
}

int main() {
    int n;
    cout<<"Enter number of elements in array"<<endl;
    cin>>n;
    cout<<"Enter array elements"<<endl;
    vector<int> arr;
    for(int i=0;i<n;i++) {
        int input;
        cin>>input;
        arr.push_back(input);
    }
    quickSort(arr,0,n-1);
    printArray(arr);
}