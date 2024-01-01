1.[Maximum Sum of Distinct Subarrays With Length K](https://leetcode.com/problems/maximum-sum-of-distinct-subarrays-with-length-k/)

```
class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int w) {
        long long res = 0, sum = 0;
        int n = nums.size();
        unordered_map<int,int>mp;
        int i = 0, j = 0;
        while (j < n) {
            mp[nums[j]]++;
            sum += nums[j];
            if (j - i + 1 < w) {
                j++;
            } else {
                if(mp.size() == w) res = max(res,sum);
                mp[nums[i]]--;
                sum -= nums[i];
                if(!mp[nums[i]]) mp.erase(nums[i]);
                i++;
                j++;
            }
        }
        return res;
    }
};
```

2. [First negative integer in every window of size k](https://practice.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1)

```
vector<long long> printFirstNegativeInteger(long long int arr[],
                                             long long int N, long long int K) {
    int i=0,j=0;
    vector<long long> ans,temp;
    while(j < N){
        if(arr[j] < 0) temp.push_back(arr[j]);
        if(j-i+1 < K) {
            j++;
        }
        else{
            if(temp.empty()) ans.push_back(0);
            else{
                ans.push_back(temp.front());
                if(arr[i] == temp.front()){
                    temp.erase(temp.begin());
                }
            }

            i++;
            j++;
        }
    }
    return ans;
 }
```

3. [Find All Anagrams in a String](https://leetcode.com/problems/find-all-anagrams-in-a-string/)

```
vector<int> findAnagrams(string s, string p) {
        vector<int>ans;
        int k = p.size();
        unordered_map<char,int>mp1;
        for(auto &c: p){
            mp1[c]++;
        }

        unordered_map<char,int>mp2;
        int i=0,j=0;
        while(j < s.size()){

            mp2[s[j]]++;
            if(j-i+1 < k){
                j++;
            }else{
                bool flag = true;
                for (auto& pair : mp1) {
                    // Check if the key exists in the second map
                    if (mp2.find(pair.first) == mp2.end()) {
                        flag = false;
                        break;
                    }

                    // Check if the corresponding values are equal
                    if (mp2[pair.first] != pair.second) {
                        flag = false;
                        break;
                    }
                }
                if(flag == true) ans.push_back(i);
                mp2[s[i]]--;
                if (mp2[s[i]] == 0) {
                    mp2.erase(s[i]);
                }
                i++;
                j++;
            }
        }
        return ans;
    }
```

4. [Maximum of all subarrays of size k](https://practice.geeksforgeeks.org/problems/maximum-of-all-subarrays-of-size-k3101/1)

```
vector <int> max_of_subarrays(int *arr, int n, int k)
    {
        // your code here
        vector<int>ans,dummy;
        int i=0,j=0;
        while(j < n){
            while(dummy.size() > 0 && dummy.back() < arr[j]){
                dummy.pop_back();
            }
            dummy.push_back(arr[j]);
            if(j-i+1 < k){
                j++;
            }else{
                ans.push_back(dummy.front());
                if(dummy.front() == arr[i]){
                    dummy.erase(dummy.begin());
                }

                i++;
                j++;
            }
        }
        return ans;
    }
```

5. [Substrings of Size Three with Distinct Characters](https://leetcode.com/problems/substrings-of-size-three-with-distinct-characters/description/)

### Approach - 1

```
int countGoodSubstrings(string s) {
        int cnt = 0;
        int i=0,j=0;
        string temp="";
        while(j < s.size()){
            if(j-i+1 < 3){
                temp.push_back(s[j]);
                j++;
            }else{
                temp.push_back(s[j]);
                if(set<char>(temp.begin(),temp.end()).size() == temp.size()) cnt++;
                temp.erase(0,1);
                i++;j++;
            }
        }
        return cnt;
    }
```

#### Approach - 2

```
 int countGoodSubstrings(string s) {
        int cnt = 0;
        for(int i=1;i<s.size()-1;i++)
            if(s[i]!=s[i-1] && s[i]!=s[i+1] && s[i-1]!=s[i+1]) cnt++;
        return cnt;
    }
```

6. [Maximum Number of Vowels in a Substring of Given Length](https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/description/)

```
class Solution {
public:
    int maxVowels(string s, int k) {
        int mx = INT_MIN;
        int i=0,j=0;
        int temp = 0;

        while(j < s.size()){
            if(s[j] == 'a' || s[j] =='e' || s[j] == 'i' || s[j] == 'o' || s[j] == 'u'){
                temp++;
            }

            if(j-i+1 < k){
                j++;
            }else{
                mx = max(mx,temp);
                if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
                    temp--;
                }
                i++;
                j++;
            }
        }
        return mx;
    }
};
```

-   same method but in a different way

```
class Solution {
public:
    int maxVowels(string s, int k) {
        int mx = INT_MIN;
        int i=0,j=0;
        string temp;
        while(j < s.size()){
            temp += s[j];
            if(j-i+1 < k){
                j++;
            }else{
                int cnt = 0;
                for(auto& e: temp){
                    if(e == 'a' || e =='e' || e == 'i' || e == 'o' || e == 'u'){
                        cnt++;
                    }
                }
                mx = max(mx,cnt);
                //remove first char in temp;
                temp.erase(temp.begin());
                i++;
                j++;
            }
        }
        return mx;
    }
};
```

7. [Maximum Number of Occurrences of a Substring](https://leetcode.com/problems/maximum-number-of-occurrences-of-a-substring/description/)

Given a string s, return the maximum number of occurrences of any substring under the following rules:

The number of unique characters in the substring must be less than or equal to maxLetters.
The substring size must be between minSize and maxSize inclusive.

```
class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        int res = 0;
        int i = 0, j = 0;
        unordered_map<string, int> freqMap;
        unordered_map<char, int> charCount;

        while (j < s.size()) {
            charCount[s[j]]++;

            if (j - i + 1 < minSize) {
                j++;
            } else if (j - i + 1 >= minSize && j - i + 1 <= maxSize) {
                if (charCount.size() <= maxLetters) {
                    string substring = s.substr(i, j - i + 1);
                    freqMap[substring]++;
                    res = max(res, freqMap[substring]);
                }

                charCount[s[i]]--;
                if (charCount[s[i]] == 0) {
                    charCount.erase(s[i]);
                }

                i++;
                j++;
            } else {
                charCount[s[i]]--;
                if (charCount[s[i]] == 0) {
                    charCount.erase(s[i]);
                }

                i++;
            }
        }

        return res;
    }
};

```

8. [Maximum Average Subarray I](https://leetcode.com/problems/maximum-average-subarray-i/description/)

You are given an integer array nums consisting of n elements, and an integer k.

Find a contiguous subarray whose length is equal to k that has the maximum average value and return this value. Any answer with a calculation error less than 10-5 will be accepted.

```
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double res = INT_MIN;
        int i=0,j=0;
        int temp=0;
        while(j < nums.size()){
            temp += nums[j];
            if(j-i+1 < k){
                j++;
            }else{
                double avg = (double)temp/k;
                res = max(res,avg);
                temp -= nums[i];
                i++;
                j++;
            }
        }
        return res;
    }
};
```

9. [sliding Window Maximum](https://leetcode.com/problems/sliding-window-maximum/)

**Approach**: We use doubly ended queue(deque) so that we can push and pop from both ends. We first check if the current element is greater than q.back and while it is true we pop from back. We also push the current element.

Once sliding window is of length k we push_back q.front to the output vector and check whether the ith element is q.front() and if so we pop that.

```
vector<int> maxSlidingWindow(vector<int>& nums, int k) {

    int j = 0 , i = 0 ;
    deque<int> q ;
    vector<int> ans ;

    while(j < nums.size()){
        if(!q.empty() && nums[j] > q.back()){
            while(!q.empty() && nums[j] > q.back()){
                q.pop_back() ;
            }
        }
        q.push_back(nums[j]) ;

        if(j - i + 1 < k){
            j++ ;
        }else if(j - i + 1 == k){
            ans.push_back(q.front()) ;
            if(q.front() == nums[i]){
                q.pop_front() ;
            }
            i++ ;
            j++ ;
        }
    }

    return ans ;
   }
```

10. [Number of Sub-arrays of Size K and Average Greater than or Equal to Threshold](https://leetcode.com/problems/number-of-sub-arrays-of-size-k-and-average-greater-than-or-equal-to-threshold/)

```
class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int j = 0, i = 0 , sum = 0;
        int n = arr.size() , cnt = 0;

        while(j < n){
            sum += arr[j] ;
            if(j - i + 1 < k){
                j++ ;
            }else if(j - i + 1 == k){
                if(sum >= threshold*k ){
                    cnt++ ;
                }
                sum -= arr[i] ;
                i++ ;
                j++;
            }
        }
        return cnt ;
}
};
```
