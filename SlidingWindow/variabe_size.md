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
