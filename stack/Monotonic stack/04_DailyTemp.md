[Daily Temperatures](https://leetcode.com/problems/daily-temperatures/description/)
Given an array of integers temperatures represents the daily temperatures, return an array answer such that answer[i] is the number of days you have to wait after the ith day to get a warmer temperature. If there is no future day for which this is possible, keep answer[i] == 0 instead.

```cpp
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n = temp.size();
        vector<int> ans(n,0);
        stack<int>st;
        for(int i=0; i<n; ++i){
            while(!st.empty() && temp[st.top()] < temp[i]){
                int stackTop = st.top();
                st.pop();
                ans[stackTop] = i-stackTop;
            }
            st.push(i);
        }
        return ans;
    }
};
```
