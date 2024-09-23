#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> findUnsortedSubarray(int arr[],int n) {
    int isSIInitiated = false;
    int startIndex = -1,endIndex = -1;
    bool isSubarrayUnsorted = false;

    for(int i=0;i<n-1;i++) {
        if(arr[i] > arr[i+1]) {
            if(!isSIInitiated){
                isSIInitiated = true;
                startIndex = i;
            }
            isSubarrayUnsorted = true;
        } else {
            if(isSubarrayUnsorted) {
                endIndex = i;
            }
            isSubarrayUnsorted = false;
        }
    }
    if(isSubarrayUnsorted) endIndex = n-1;

    vector<int> ans;
    if(startIndex != -1 && endIndex != -1) {
        ans.push_back(startIndex);
        ans.push_back(endIndex);
    }
    return ans.size() ? ans : {};
} 

int main() {
    int arr[] = {1,4,3,5,2,6,7,8,9,10};
    int n = 10;
    vector<int> ans =  findUnsortedSubarray(arr,n);
    for(int i=ans[0];i<ans[ans.size()-1];i++) {
        cout<<arr[i];
    }
}