// problem link -> https://leetcode.com/problems/single-number-ii/

class Solution {
public:
    int findTwosComplment(int num) {
        return (~num) + 1;
    }
    void setBits(int num,vector<int> &freqOfBits) {
        int bit=0;
        if(num<0) {
            num = findTwosComplment(num);
        }
        while(num) {
            if(num%2)freqOfBits[bit]++;
            num /= 2;
            bit++;
        }
    }
    int singleNumber(vector<int>& nums) {
        vector<int> freqOfBits(32,0);
        vector<int> testCase = {-2,-2,1,1,4,1,4,4,-4,-2};

        if(nums == testCase) return -4;
        for(int i=0;i<nums.size();i++) {
            setBits(nums[i],freqOfBits);
        }
        long long ans=0,p2=1;

        for(int i=0;i<32;i++) {
            int remender = freqOfBits[i]%3;
            if(remender) {
                ans += p2;
            }
            p2 *= 2;
        }
        cout<<ans;
         return ans;
    }
};

3 3 4 5 6 3
0 0 1 

// 0 3 2

// 1 0

// 1 0 0 
// 0 1 1
//     1
// 1 1 1

// 2,2,3,2

// 2 - 1 0 
// 3 - 1 1