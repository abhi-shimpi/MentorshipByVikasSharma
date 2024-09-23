class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        // TC -> O(N * log(N))
        // SC -> O(n)
        vector<vector<int>> ans;
        unordered_map<int,int> ump; // Can we remove this?
        sort(arr.begin(),arr.end());
        // 1 2 3 4 
        // minDifference
        // minDiffrence  = arr[i] + x;
        int minDiffrence = INT_MAX;
        int n = arr.size();

        for(int i=0;i<n-1;i++) {
            int diffrence = abs(arr[i+1] - arr[i]);
            if(diffrence < minDiffrence) {
                minDiffrence = diffrence;
            }
            ump[arr[i]]++;
        }
        ump[arr[n-1]]++;
        for(int i = 0;i<n;i++) {
            // x  = arr[i] - minDifference;
           int element = arr[i] - minDiffrence;
           if(ump[element]) {
                if(element > arr[i]) {
                    ans.push_back({arr[i],element});
                } else {
                    ans.push_back({element,arr[i]});
                }
           }
        }
        return ans;
    }
};