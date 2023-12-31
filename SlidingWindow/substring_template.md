1. Use two pointers: i and j to represent a window.
2. Move j to find a valid window.
3. When a valid window is found, move i to find a smaller window.

```
int findSubstring(string s){
        vector<int> map(128,0); // or unordered_map<char,int>mp
        int counter; // check whether the substring is valid
        int i=0, j=0; //two pointers, one point to tail and one  head
        int d; //the length of substring

        for() { /* initialize the hash map here */ }

        while(j<s.size()){

            if(map[s[j++]]-- ?){  /* modify counter here */ }

            while(/* counter condition */){

                 /* update d here if finding minimum*/

                //increase i to make it invalid/valid again

                if(map[s[i++]]++ ?){ /*modify counter here*/ }
            }

            /* update d here if finding maximum*/
        }
        return d;
  }
```

1. [Minimum Window Substring](https://leetcode.com/problems/minimum-window-substring/)

```
class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.size(), i=0, j=0, minStart = 0, minLen = INT_MAX;
        int counter = t.size();
        // counter represents the number of chars of t to be found in s.
        vector<int>mp(128,0);// unordered_map<int,int> mp;
        for(auto c: t){// Statistic for count of char in t
            mp[c]++;
        }
        while(j < n){
            // If char in s exists in t, decrease counter
            if(mp[s[j]] > 0){
                counter--;
            }
            // Decrease m[s[end]]. If char does not exist in t, m[s[end]] will be negative.
            mp[s[j]]--;
            j++;
            // When we found a valid window, move start to find smaller window.
            while(counter == 0){
                if(j-i < minLen){
                    minLen = j-i;
                    minStart = i;
                }
                mp[s[i]]++;
                // When char exists in t, increase counter.
                if(mp[s[i]] > 0){
                    counter++;
                }
                i++;
            }
        }
        return minLen == INT_MAX? "" : s.substr(minStart,minLen);

    }
};
```

2.[ Longest Substring with At Most Two Distinct Characters](https://leetcode.com/problems/longest-substring-with-at-most-two-distinct-characters/description/)

```
int lengthOfLongestSubstringTwoDistinct(string s) {
        vector<int> mp(128, 0);
        int counter=0, i=0, j=0, d=0;
        while(j<s.size()){
            if(mp[s[j]] == 0){
                counter++;
            }
            mp[s[j]]++;
            j++;
            while(counter>2) {
              if(map[s[i]]==1)
                counter--;
              mp[s[i]]--;
              i++;
            }
            d=max(d, j-i);
        }
        return d;
    }
```

3. [Longest Substring Without Repeating Characters](https://leetcode.com/problems/longest-substring-without-repeating-characters/)

```
int lengthOfLongestSubstring(string s) {
        vector<int> map(128,0);
        int counter=0, i=0, j=0, d=0;
        while(end<s.size()){
            if(map[s[j]]>0) counter++;
            map[s[j]]++;
            j++;
            while(counter>0) {
              if(map[s[i]] > 1)
                counter--;
              map[s[i]]--;
              i++;
            }
            d=max(d, j-i); //while valid, update d
        }
        return d;
    }
```
