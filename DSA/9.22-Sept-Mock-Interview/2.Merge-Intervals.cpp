// https://leetcode.com/problems/merge-intervals/
class Solution {
public:
    bool isIntervalsOverlaping(vector<int> interval1 ,vector<int> interval2,int &minStart,int & maxEnd) {
        int firstEnd = interval1[1];
        int secondStart = interval2[0];
        int firstStart = interval1[0];
        int secondEnd = interval2[1];

        // cout<<firstStart<<" "<<firstEnd<<" "<<secondStart<<" "<<secondEnd<<endl;
        if(firstEnd >= secondStart && firstStart <= secondEnd) {
            minStart = min(min(firstStart,secondStart),minStart);
            maxEnd = max(max(firstEnd,secondEnd),maxEnd);
            return true;
        }
        return false;
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans= {};
        int n = intervals.size();

        for(int i=0;i<n;i++) {
            if(ans.size()) {
                int minStart = intervals[i][0];
                int maxEnd = intervals[i][1];
                bool isOverlapped = false;

                vector<vector<int>> tempAns;
                int j =ans.size()-1;
                while(j>=0) {
                    if(isIntervalsOverlaping(ans[j],{minStart,maxEnd},minStart,maxEnd)) {
                        while(j>=0 && isIntervalsOverlaping(ans[j],{minStart,maxEnd},minStart,maxEnd)) {        
                            isOverlapped = true;
                            j--;
                        }
                        // cout<<minStart<<" "<<maxEnd<<endl;
                        tempAns.push_back({minStart,maxEnd});
                    } else {    
                        tempAns.push_back(ans[j]);
                        j--;
                    }
                }
                // cout<<isOverlapped;
                if(!isOverlapped){
                    ans.push_back({intervals[i][0],intervals[i][1]});
                } else {
                    reverse(tempAns.begin(),tempAns.end());
                    ans = tempAns;
                }
            } else {
                ans.push_back(intervals[i]);
            }
        }

        return ans;
    }
};

// [[1,3],[2,3],[2,4],[2,6],[8,10],[15,18]]

// p1 = 0;
// end = 3;
// p2 = p1 + 1; = 2 

// [1 , 6]
