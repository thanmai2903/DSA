[Largest Area in Histogram](https://leetcode.com/problems/largest-rectangle-in-histogram/)
**Question**
Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.

**Solution**
The solution for this question uses template 6 above. We merge the solution for previous smaller and next smaller both.
In the example below, nextSmaller is strictly smaller while previousSmaller also considers equal elements (in addition to smaller elements).
This actually works in our favour because this is making sure we don't count the same element twice.

```cpp
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> nextSmaller(n, n);
        vector<int> previousSmaller(n, -1);
        stack<int> st;

        // Calculate previousSmaller and nextSmaller
        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[st.top()] > heights[i]) {
                int stackTop = st.top();
                st.pop();
                nextSmaller[stackTop] = i;
            }
            if (!st.empty()) {
                previousSmaller[i] = st.top();
            }
            st.push(i);
        }

        int maxArea = 0;
        for (int i = 0; i < n; i++) {
            int currentHeight = heights[i];
            int width = nextSmaller[i] - previousSmaller[i] - 1;
            maxArea = max(maxArea, currentHeight * width);
        }

        return maxArea;
    }
};
```
