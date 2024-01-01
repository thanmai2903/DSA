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

3. #### Print Longest substring with no repeating characters (variable ans)

**Approach**: Firstly, increment the frequency of jth element. If the frequency of jth element is 1 then it could be the potential answer else while (frequency > 1) decrement frequency of i (If frequency is 0 remove it from the map)

```
int printLongestUnique(string s){

    int i = 0, j = 0, ans = -1;
    unordered_map<char, int> mpp;
	string res = "" ;
    while (j < s.size()) {
        mpp[s[j]]++;

        if (j - i + 1 < mpp.size()) {
            j++;
        }else if (j - i + 1 ==  mpp.size()) {
            if(j - i + 1 > ans){
            	ans = j - i + 1 ;
                res = s.substr(i, j) ;
            }
            j++;
        }else if (j - i + 1 >  mpp.size()) {
            while (j - i + 1 >  mpp.size()) {
                if (mpp[s[i]] == 1) {
                    mpp.erase(s[i]);
                }else {
                    mpp[s[i]]--;
                }
                i++;
            }
            j++;
        }
    }
    return ans;
}
```

4. #### Count of all substring with no repeating characters
    **Approach**: Same as Q1 , just increment the count wth j-i+1

```
int countOfSubstringNoRepeat(string s) {
    int len =0, i = 0, j = 0,count=0;
    unordered_map<char, int> mpp;
    string ans = "" ;

    while(j < s.size()){
        mpp[s[j]]++ ;

        if(mpp[s[j]] == 1){
            count += (j-i+1) ;
        }else if(mpp[s[j]] == 2){
            while(mpp[s[j]] == 2){

                mpp[s[i]]-- ;
                if(mpp[s[i]] == 0){
                    mpp.erase(s[i]) ;
                }
                 i++;
            }
            count += (j-i+1) ;
        }

        j++ ;

    }
    return count ;
}
```

5. #### Longest Substring With K Unique Characters

**Approach**: Firstly, increment the frequency of jth element then, If mpp.size() < k increment j , if mpp.size() == k then it is potential answer else while mpp.size() > k decrement the frequency of ith element (If zero then remove it)

```
int longestKSubstr(string s, int k) {
    int i = 0 , j = 0 , ans = -1 ;
    unordered_map<char, int> mpp ;

    while(j < s.size()){
        mpp[s[j]]++ ;

        if(mpp.size() < k){
            j++ ;
        }else if(mpp.size() == k ){
            ans = max(ans, j-i+1) ;
            j++ ;
        }else if(mpp.size() > k ){
            while(mpp.size() > k){
                if(mpp[s[i]] == 1){
                    mpp.erase(s[i]) ;
                }else{
                    mpp[s[i]]-- ;
                }
                i++ ;
            }
            j++ ;
        }
    }
    return ans ;
}
```

6. #### Longest Substring With at most K Unique Characters

**Approach**: Same as above question because of almost we can include size less than k as well.

```
int longestAtMostKSubstr(string s, int k) {
    // your code here
        int n = s.size(), i = 0, j = 0, ans = -1;
        unordered_map<char, int> mp;

        while( j < s.size()){
            mp[s[j]]++;
            if(mp.size() < k){
                ans = max(ans, j-i+1);
                j++;
            }else if(mp.size() == k){
                ans = max(ans, j-i+1);
                j++;
            }else if(mp.size() > k){
                while(mp.size() > k){
                    if(mp[s[i]] == 1){
                      mp.erase(s[i]);
                    }else{
                       mp[s[i]]--;
                    }
                    i++;
                }
                j++;
            }
        }
        return ans;
  }
```

7. [Longest Repeating Character Replacement](https://leetcode.com/problems/longest-repeating-character-replacement/)

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

8. [ Sliding Window maximum](https://leetcode.com/problems/sliding-window-maximum/)

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

9. [Minimum Window Substring](https://leetcode.com/problems/minimum-window-substring/)

#### Method-1

-   Maintain one HashMap to store frequency of every character of string t.
-   Initialize a counter variable with size of that hashmap. (If this variable is zero then
-   we have sufficient characters)
-   Iterate over the other string with variable -> j
-   If that character is present in the hashmap then decrement it (even if it becomes zero)
-   and check whether its freqeuncy is zero or not. If zero then decrement counter by one.
-   If counter is greater than zero just increment j
-   If counter is zero then we have just enough characters to fulfill our condition. Here, we need to optimize our substring.
-   Iterate from i (initiazed to 0) to j and if the character is present in hashmap increment it
    -   If frequency of that character is greater than zero increment counter.
    -   If not then again optimize the substring.

```
string smallestWindow(string s, string t){
   string ans = "";
   if (s.size() < t.size())
       return "-1";

   unordered_map<char, int> mp;
   for (int i = 0; i < t.size(); i++){
       mp[t[i]]++;
   }

   int length = INT_MAX;
   int i = 0, j = 0;
   int count = mp.size();

   while (j < s.size()){

       if (mp.find(s[j]) != mp.end()){
           mp[s[j]]--;
           if (mp[s[j]] == 0)
               count--;
       }

       if (count > 0){
           j++;
       }else if (count == 0){
           while (count == 0){

               if (mp.find(s[i]) != mp.end()){

                   if (j - i + 1 < length){
                       length = j - i + 1;
                       ans = s.substr(i, j - i + 1);
                   }
                   mp[s[i]]++;
                   if (mp[s[i]] > 0)
                       count++;
               }

               i++;
           }
           j++;
       }


   }
   return (ans.size() == 0 ?  "-1" : ans);
```

#### Method-2

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

10. [Minimum Size Subarray sum](https://leetcode.com/problems/minimum-size-subarray-sum/)

**Approach**: All values are positive, so once a contiguous sum exceeds or equals the sum, we don't need to add to the current subarray. Adding would increase the length of a subarray which already satisfies the problem constraint so we reduce the window size till sum >= k.

```
int minSubArrayLen(int k, vector<int>& nums) {
        int j = 0 , i = 0 ;
        int sum = 0 , len = INT_MAX;

        while(j < nums.size()){
            sum += nums[j] ;

            if(sum < k){
                j++ ;
            }else if(sum == k){
                len = min(len, j-i+1) ;
                j++ ;
            }else if(sum > k){

                while(sum >= k){
                     len = min(len, j-i+1) ;
                     sum -= nums[i] ;
                     i++ ;
                 }

                j++ ;
            }

        }

        return len == INT_MAX ? 0 : len  ;
    }
```

11. #### Max Consecutive Ones in Binary Array where you can transform k zeros to ones

**Approach**: If the number is zero then increment the count. If count <= k calculate the answer else if count is greater than k while it is greater decrement the count.

```
int longestOnes(vector<int>& nums, int k){

    int i = 0, j = 0;
    int count = 0;
    int len = 0;

    while (j < nums.size()) {
        if (nums[j] == 0) {
            count++;
        }

        if (count <= k) {
            len = max(len, j-i+1) ;
            j++;
        }else if (count > k) {
            while (count > k) {
                if (nums[i] == 0) {
                    count--;
                }
                i++;
            }
            j++;
        }
    }
    return len;
}
```

12. #### Minimum size subarray sum where the sum is greater than or equal to the target (Only Positive Numbers)
    **Approach**: Add element to the sum. If sum is less than k increment j else if sum is grater than k try to minimize the window till the window size again becomes invalid.

```
int lenOfLongSubarr(int A[], int N, int K){

    int i = 0, j = 0, sum = 0;
    int max = INT_MIN;

    while (j < N) {
        sum += A[right];

        if (sum < K) {
            j++;
        }else if (sum == K) {
            max = max > sum ? max : (right - left + 1);
            j++;
        }else if (sum > K) {
            while (sum > K) {
                sum -= A[left];
                i++;
            }
            j++;
        }
    }
    return max;
}
```

13. [Minimum Consecutive Cards to Pick Up](https://leetcode.com/problems/minimum-consecutive-cards-to-pick-up/s)

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

14. [Fruits into Baskets](https://leetcode.com/problems/fruit-into-baskets/)

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

15. [Permutation in String](https://leetcode.com/problems/permutation-in-string/description/)

```
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int i=0,j=0, n = s2.size(), k = s1.size();
        unordered_map<char, int> mp2;
        for(auto c: s1){
            mp2[c]++;
        }
        int cnt = mp2.size();
        while(j < n){
            if(mp2.find(s2[j]) != mp2.end()){
                mp2[s2[j]]--;
                if(mp2[s2[j]] == 0)cnt--;
            }

            if(j-i+1 < k){
                j++;
            }else if(j-i+1 == k){
                if(cnt == 0) return true;
                if(mp2.find(s2[i])!=mp2.end()){
                    mp2[s2[i]]++;
                    if(mp2[s2[i]]==1){
                       cnt++;
                    }
                }
                i++;
                j++;
            }
        }
        return false;
    }
};
```
