[Trapping rain Water](https://leetcode.com/problems/trapping-rain-water/)

### M-1. space and time 0(n)

```cpp
class Solution {
public:
    int trap(vector<int>& h) {
        int n = h.size();
        int area = 0;
        vector<int> maxLeft(n, 0);
        vector<int> maxRight(n, 0);
        //prefix Left max sum
        maxLeft[0] = h[0];
        for(int i=1; i<n; ++i){
            maxLeft[i] = max(maxLeft[i-1],h[i]);
        }
        // Right max sum
        maxRight[n-1] = h[n-1];
        for(int i=n-2; i>=0; --i){
            maxRight[i] = max(maxRight[i+1],h[i]);
        }
        for (int i = 1; i < n - 1; ++i) {
            int mini = min(maxLeft[i-1], maxRight[i+1]);
            if (mini >= h[i]) area += (mini - h[i]);
        }

        return area;
    }
};
```

### M-2 time->0(n) space -> 0(1) 2 ptrs

```cpp
class Solution {
public:
    int trap(vector<int>& h) {
        //2-ptrs
        int n = h.size(), area = 0;
        int maxL = h[0], maxR = h[n-1];
        int l =0, r = n-1;
        while(l<r){
            if(maxL < maxR) {
                l++;
                maxL = max(maxL, h[l]);
                area += maxL - h[l];
            }
            else {
                r--;
                maxR = max(maxR, h[r]);
                area += maxR - h[r];
            }
        }
        return area;
    }
};
```

### M-3 monotonic stack space and time ->0(n)

```cpp
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        stack<int>st;
        int area = 0;
        for(int i=0; i<n; ++i){
            while(!st.empty() && height[st.top()] <= height[i]){
                int stackTop = st.top();
                st.pop();
                if(!st.empty()){
                    //h(height) -> min of prevGreater or nextGreater
                    int h = min(height[st.top()],height[i]) - height[stackTop];
                    //w(width) -> space b/w prevGreater and nextGreater
                    int w = i - (st.top()+1);

                    //area is h*w
                    area += h*w;
                }
            }
            st.push(i);
        }
        return area;
    }
};
```
