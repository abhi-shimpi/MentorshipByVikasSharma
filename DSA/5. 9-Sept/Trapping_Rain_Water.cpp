class Solution {
public:
    int trap(vector<int>& height) {
        // TC -> O(N)
        // SC -> O(N) Can we remove extra storage?
        // Focus on thoughtprocess of how you approch the problem
        int maxFromLeft = INT_MIN;
        int maxFromRight = INT_MIN;
        int n = height.size();
        vector<int> arrOfMaxLeft;
        vector<int> arrOfMaxRight(n,0);

        // array -> 0 1 0 2 1  0 1 3 2 1 2 1
        // maxLeft> 0 0 1 1 2  2 2 2 3 3 3 3 
        // maxRight>                     2 1 

        for(int i=0;i<n;i++) {
            if(maxFromLeft == INT_MIN) {
                maxFromLeft = 0;
            }
            arrOfMaxLeft.push_back(maxFromLeft);
            if(height[i] > maxFromLeft) {
                maxFromLeft = height[i];
            }
        }
        for(int i=n-1;i>=0;i--) {
            if(maxFromRight == INT_MIN) {
                maxFromRight = 0;
            }
            arrOfMaxRight[i] = maxFromRight;
            if(height[i] > maxFromRight) {
                maxFromRight = height[i];
            }
        }

        int ans=0;
        for(int i=0;i<n;i++) {
            int spaceOfWater = min(arrOfMaxLeft[i],arrOfMaxRight[i]);
            cout<<arrOfMaxLeft[i]<<"  "<<arrOfMaxRight[i]<<endl;
            ans += (spaceOfWater-height[i] > 0 ? (spaceOfWater-height[i]) : 0);
        }
        return ans;
    }
};  


// 0 1 0 2 1 0 1 3 2 1 2 1 ---

// 0 1 1 2 2 2 2 3 3 3 3 3 

// 3 3 3 3 3 3 3 3 2 2 2 1

// 0 1 1 2 2 2 2 3 2 2 2 1 -----

// 0 0 1 0 1 2 1 0 0 1 0 0
