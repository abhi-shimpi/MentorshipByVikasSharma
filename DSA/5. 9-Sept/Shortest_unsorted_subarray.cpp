class Solution {
public:
    int findUnsortedSubarray(vector<int>& arr) {
        // TC -> O(N)
        // SC -> O(1)
       int startIndex = -1,endIndex = -1;
       int n = arr.size();

        // 2 6 1 8 10 9 10 11 9 15 
        // start = 1
        // end = 4
        // (start , end) => max= 10 , min = 1
        // min = 1 => element < 6 => left of 6 , start = 0 
        // max = 10 => elements right og endIndex => end = 6
        // len =  end - start + 1 = 6 
       for(int i=0;i<n-1;i++) {
            if(arr[i] > arr[i+1] && startIndex ==-1) {
                startIndex = i;
                endIndex = i+1;
            } else if(arr[i] > arr[i+1] &&  startIndex != -1) {
                endIndex = i+1;
            }
       }
       if(startIndex == -1 && endIndex == -1) { return 0;}
       int max = INT_MIN,min=INT_MAX;

       for(int i=startIndex;i<=endIndex;i++) {
            if(arr[i] > max) max = arr[i];
            if(arr[i] < min) min = arr[i];
       }
        int start = -1;
       for(int i = startIndex-1;i>=0;i--) {
            if(arr[i] <= min) {
                 start = i+1;
                 break;
            }
       }
       if(start == -1) start = 0;

       int end = -1;
       for(int i=endIndex+1;i<n;i++) {
        if(arr[i] >= max) {
            end = i-1;
            break;
        }
       }
       if(end == -1) end = n-1;

       return end - start + 1;
       return 0;
    }
};