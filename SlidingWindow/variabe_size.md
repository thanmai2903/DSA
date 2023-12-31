1. Longest Sub-Array with Sum K

Given an array containing N integers(positives only) and an integer K., Your task is to find the length of the longest Sub-Array with the sum of the elements equal to the given value K.

```
int lenOfLongSubarr(int A[], int N, int K) {
    int i = 0, j = 0, sum = 0, res = INT_MIN;

    while (j < N) {
        sum += A[j];

        if (sum < K) {
            j++;
        } else if (sum == K) {
            res = max(res, j - i + 1);
            j++;
        } else {
            while (sum > K) {
                sum -= A[i];
                i++;
            }

            if (sum == K) {
                res = max(res, j - i + 1);
            }

            j++;
        }
    }

    return (res == INT_MIN) ? 0 : res;
}
```

2. [Longest Substring Without Repeating Characters](https://leetcode.com/problems/longest-substring-without-repeating-characters/)

```
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i=0,j=0,ans=0;
        unordered_map<char,int>mp;
        while(j < s.size()){
            mp[s[j]]++;
            if(j - i + 1 < mp.size()) {
                j++;
            }
            else if(j - i + 1 == mp.size()) {
                ans = max(ans, j-i+1);
                j++;
            }else{
                while(j-i+1 > mp.size()){
                    mp[s[i]]--;
                    if (mp[s[i]] == 0)
                        mp.erase(s[i]);
                    i++;
                }
                if(j-i+1 == mp.size()){
                    ans = max(ans,j-i+1);
                }
                j++;
            }
        }
        return ans;
    }
};
```

3. [Longest Repeating Character Replacement](https://leetcode.com/problems/longest-repeating-character-replacement/)

```
class Solution {
public:
    int characterReplacement(string s, int k) {
        int i=0,j=0, res=0, maxCount=0, n = s.size();
        unordered_map<char,int>mp;
        while(j < n){
            mp[s[j]]++;
            maxCount = max(maxCount, mp[s[j]]);
            if(j-i+1-maxCount <= k){
                res = max(res,j-i+1);
                j++;
            }else{ // if length of the window - maxCount > no of replacements, no result, so simply increment i after removing calculations of initial i in map
                mp[s[i]]--;
                i++;
                j++;
            }
        }
        return res;
    }
};
```

4. [ Sliding Window maximum](https://leetcode.com/problems/sliding-window-maximum/)

#### Approach 1 - Brute force

```
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int i=0, j=0,mx=INT_MIN, n = nums.size();
        vector<int>res;
        while(j < n){
            mx = max(mx, nums[j]);
            if(j-i+1 < k){
                j++;
            }else{
                int x = *max_element(nums.begin()+i, nums.begin()+j+1);
                res.push_back(x);
                i++;
                j++;
            }
        }
        return res;
    }
};
```

#### Approach 2 - Optimal(using deque)

-   for a deque, inserting and deleting takes cost od O(1) time
-   our deque stores elements in decreasing order(monotonically decreasing)

```
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;
        deque<int> dq;
        int i = 0, j = 0;

        while (j < n) {
            // Remove elements outside the current window
            while (!dq.empty() && dq.front() < i) {
                dq.pop_front();
            }

            // Remove elements smaller than the current element from the back
            while (!dq.empty() && nums[dq.back()] < nums[j]) {
                dq.pop_back();
            }

            dq.push_back(j);

            // If the window is fully formed, add the maximum to the result
            if (j-i+1 >= k ) {
                ans.push_back(nums[dq.front()]);
                i++;
            }

            j++;
        }

        return ans;
    }
};
```

5. [Minimum Window Substring](https://leetcode.com/problems/minimum-window-substring/)

```
class Solution {
public:
    string minWindow(string s, string t) {
        if (t == "") return "";

        unordered_map<char, int> countT, window;

        for (char c : t) {
            countT[c]++;
        }

        int have = 0, need = countT.size();
        int i = 0;
        vector<int> res = {-1, -1};
        int resLen = INT_MAX;

        int j = 0;
        while (j < s.length()) {
            char c = s[j];
            window[c]++;

            if (countT.find(c) != countT.end() && window[c] == countT[c]) {
                have++;
            }

            while (have == need) {
                if (j - i + 1 < resLen) {
                    res = {i, j};
                    resLen = j - i + 1;
                }

                window[s[i]] -= 1;
                if (countT.find(s[i]) != countT.end() && window[s[i]] < countT[s[i]]) {
                    have--;
                }

                i++;
            }

            j++;
        }

        int left = res[0], right = res[1];
        return (resLen != INT_MAX) ? s.substr(left, right - left + 1) : "";
    }
};

```

6. [Minimum Size Subarray sum](https://leetcode.com/problems/minimum-size-subarray-sum/)

The O(n) solution is to use two pointers: l and r. First we move r until we get a sum >= s, then we move l to the right until sum < s. In this process, store the minimum length between l and r. Since each element in nums will be visited by l and r for at most once. This algorithm is of O(n) time.

```
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int minLen = INT_MAX, i=0, j=0, n =nums.size();
        long long sum = 0;
        while(j < n){
            sum += nums[j];
            while(target <= sum){
                minLen = min(minLen, j-i+1);
                sum -= nums[i];
                i++;
            }
            j++;
        }
        return minLen == INT_MAX ? 0: minLen;
    }
};
```

7. [Minimum Consecutive Cards to Pick Up](https://leetcode.com/problems/minimum-consecutive-cards-to-pick-up/s)

```
class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        int minLen = INT_MAX, j=0, n = cards.size();
        unordered_map<int, int> mp;
        while(j < n){
            if(mp.find(cards[j]) != mp.end()){
                minLen = min(minLen, j - mp[cards[j]] + 1);
            }
            mp[cards[j]] = j;
            j++;
        }
        return minLen == INT_MAX? -1 : minLen;
    }
};
```

8. [Fruits into Baskets](https://leetcode.com/problems/fruit-into-baskets/)

Basically it's just: "Find the longest continuous sub array that has exactly 2 distinct elements."

```
class Solution {
public:
    int totalFruit(vector<int>& s) {
        int maxLen = INT_MIN, i = 0, j = 0, n = s.size(), cnt = 0;
        unordered_map<int, int> mp;

        while (j < n) {
            mp[s[j]]++;
            cnt++;

            while (mp.size() > 2) {
                mp[s[i]]--;
                if (mp[s[i]] == 0) {
                    mp.erase(s[i]);
                }
                cnt--;
                i++;
            }

            maxLen = max(maxLen, cnt);
            j++;
        }

        return maxLen;
    }
};

```
