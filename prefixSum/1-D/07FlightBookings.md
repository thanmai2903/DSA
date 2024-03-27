[Corporate Flight Bookings](https://leetcode.com/problems/corporate-flight-bookings/)

There are n flights that are labeled from 1 to n.

You are given an array of flight bookings bookings, where bookings[i] = [firsti, lasti, seatsi] represents a booking for flights firsti through lasti (inclusive) with seatsi seats reserved for each flight in the range.

Return an array answer of length n, where answer[i] is the total number of seats reserved for flight i.

```cpp
class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int>ans(n,0);
        for(auto& b: bookings){
            int f = b[0]-1;// 0-based indexing
            int l = b[1];
            int s = b[2];

            ans[f] += s;
            if (l < n) {
                ans[l] -= s;
            }
        }
        for(int i=1; i<n; ++i){
            ans[i] += ans[i-1];
        }
        return ans;
    }
};
```
