#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// As we can see that the time complexity of the std::find() is O(n) 
// and it also works on unsorted sequences, we can conclude that it uses the linear search algorithm in its implementation.
// TC-> O(n* n) -> keep order of original elements
// vector<int> removeDuplicate(vector<int> &vec) {
//     vector<int> ans;

//     for(int i=0;i<vec.size();i++) {
//         auto it = find(ans.begin(),ans.end(),vec[i]);
//         if(it == ans.end()) {
//             ans.push_back(vec[i])
//         }
//     }
// }

// Using set
// TC -> O(n * logn) -> keep order of original elements
// vector<int> removeDuplicate(vector<int> &vec) {
//     set<int> uniqueEle;
//     vector<int> ans;

//     for(int i=0;i<vec.size();i++) {
//         if(uniqueEle.find(vec[i]) == uniqueEle.end()) { // O(logn)
//             uniqueEle.insert(vec[i]); // O(logn)
//             ans.push_back(vec[i]);
//         }
//     }
//     return ans;
// }
// TC -> O(n * logn) ->  Not keep order of original elements
// vector<int> removeDuplicate(vector<int> &vec) {
//     set<int> uniqueEle;

//     for(int i=0;i<vec.size();i++) {
//       uniqueEle.insert(vec[i]);
//     }
//     vector<int> ans;
//     for(auto it:uniqueEle) {
//         ans.push_back(it);
//     }
//     return ans;
// }

// Using hashmap -> Not keep order of original elements
// vector<int> removeDuplicate(vector<int> &vec) {
//     unordered_map<int> ump;

//     for(int i=0;i<vec.size();i++) {
//       ump[vec[i]]++;
//     }
//     vector<int> ans;
//     for(auto it:ump) {
//         ans.push_back(it.first);
//     }
//     return ans;
// }

// Using stack
// vector<int> removeDuplicate(vector<int> &vec) {
//     stack<int> st;
//     sort(vec.begin(),vec.end());

//     for(int i=vec.size()-1;i>=0;i--) {
//         if(st.empty()) {
//             st.push(vec[i]);
//         } else {
//             if(st.top() != vec[i]) {
//                 st.push(vec[i]);
//             }
//         }
//     }
//     vector<int> ans;
//     while(!st.empty()) {
//         ans.push_back(st.top());
//         st.pop();
//     }
//     return ans;
// }

// Using queue
vector<int> removeDuplicate(vector<int> &vec) {
    if(vec.size()<=1) return vec;
    queue<int> que;
    sort(vec.begin(),vec.end());
    vector<int> ans;
    
    for(int i=1;i<vec.size();i++) {
        if(que.empty()) {
            que.push(vec[i]);
        } else if( que.front() != vec[i]) {
            ans.push_back(que.front());
            que.pop();
            que.push(vec[i]);
        }
    }
    if(!que.empty())ans.push_back(que.front());
    return ans;
}

void printArray(vector<int> &ans) {
    for(int i=0;i<ans.size();i++) {
        cout<<ans[i]<<endl;
    }
}

int main() {
    vector<int> vec = {10,7,8,9,2,4,7,2,8,9};
    vector<int> ans = removeDuplicate(vec);
    printArray(ans);
}