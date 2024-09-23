
// BFA -> O(N*N) -> Gives TLE
// SC -> O(N)
class Solution {
public:
    bool canJumpTillLast = false;
    void checkCanJump(vector<int> &nums,int n,int curr,vector<int> &dp) {
        if(dp[curr]) return;
        if(curr >= n-1) {
            canJumpTillLast = true;
            return;
        }
        for(int i=1;i<=nums[curr];i++) {
            checkCanJump(nums,n,i+curr,dp);
            if(canJumpTillLast) {
                dp[curr] = true;
                return;
            } ;
        }
    }
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1,0);
        checkCanJump(nums,n,0,dp);
        return canJumpTillLast;
    }
};

// Optimal -> O(N)
// SC -> O(1)
// Intuition -> Just focus on how far you go in terms of indexing like what can maximum reach and find reach on every index and 
// update maxReach if current is greter than maxReach
// If current index is greater than maxReach then it directly suggest that i cannot reach till current index so there is way to go further
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxReach = 0;

        for(int i=0;i<nums.size();i++) {
            if(i > maxReach) return false;

            int reach = i + nums[i];
            if(reach > maxReach)maxReach = reach;
        }
        return true;
    }
};
### Optimization Hint

- Instead of exploring all possible jumps recursively, you can try to **keep track of the farthest index** you can reach as you iterate through the array.
- If at any point, the current index is beyond the farthest reachable index, you can conclude that it's not possible to reach the end.
- If you reach the end or surpass it while updating the farthest index, you can return `true`.

### Key Insights:
1. Keep updating the farthest index you can reach (`maxReach`).
2. If the current index exceeds `maxReach`, you cannot proceed further.
3. If you reach the end while updating `maxReach`, return `true`.

This approach reduces the time complexity to \( O(n) \) since you are only iterating through the array once.

Would you like to see the optimized greedy solution based on this approach?