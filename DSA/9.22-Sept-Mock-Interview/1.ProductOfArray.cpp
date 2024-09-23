// https://leetcode.com/problems/product-of-array-except-self/
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // TC ->O(N)
        // SC -> O(1)
        // This approach uses Prefix product and Suffix Product 
        int n = nums.size();
        vector<int> ans(n,0);
        long long prefixProd = 1;

        for(int i=0;i<n;i++) {
            prefixProd *= nums[i];
            ans[i] = prefixProd;
        }

        long long suffixProd = 1;

        for(int i=n-1;i>=0;i--) {
            int prefixProd = i==0 ? 1 : ans[i-1];
            int prod = prefixProd * suffixProd;
            ans[i]= prod;
            suffixProd *= nums[i];
        }

        return ans;
    }
};