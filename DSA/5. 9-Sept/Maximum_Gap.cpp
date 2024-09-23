class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int max = INT_MIN, min = INT_MAX;
        int n = nums.size();

        if(n < 2) {
            return 0;
        }
        // Calculating min and max
        for(int i=0;i<n;i++) {
            if(nums[i] > max) max = nums[i];
            if(nums[i] < min) min = nums[i];
        }
        // If all elements are same
        if(min == max) return 0;
        // bucketSize = ceil((max-min)/(double)(n-1.0));
        int bucketSize = ceil((max - min) / (double)(n - 1));

        vector<int> minOfBuckets(n+1,INT_MAX);
        vector<int> maxOfBuckets(n+1,INT_MIN);
        // filling buckets with corresponding values
        for(int i=0;i<n;i++) {
            int bucketIndex = (nums[i] - min)/bucketSize;
            cout<<bucketIndex;
           if(bucketIndex < n) {
             minOfBuckets[bucketIndex] = std::min(nums[i],minOfBuckets[bucketIndex]);

            maxOfBuckets[bucketIndex] = std::max(nums[i],maxOfBuckets[bucketIndex]);
           }
        }

        // Calculating max gap
        int maxGap = INT_MIN;
        int previousMax = min;
        for(int i = 0;i<n-1;i++) {
            if(maxOfBuckets[i] == INT_MIN) continue;

            int gap = minOfBuckets[i] - previousMax;
            if(gap > maxGap) maxGap = gap;
            previousMax = maxOfBuckets[i];
        }
        maxGap = std::max(maxGap,max - previousMax); // Handling edge case where last max and max element can have max gap
        return maxGap;
    }
};