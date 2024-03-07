[K Inverse Pairs](https://leetcode.com/problems/k-inverse-pairs-array/)

## M-1 Recursion -> TLE

```cpp
class Solution {
    int MOD = 1e9 + 7;
private:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current_permutation;
        vector<bool> used(nums.size(), false);
        generatePermutations(nums, used, current_permutation, result);
        return result;
    }
    void generatePermutations(const vector<int>& nums, vector<bool>& used, vector<int>& current_permutation, vector<vector<int>>& result) {
        if (current_permutation.size() == nums.size()) {
            result.push_back(current_permutation);
            return;
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (!used[i]) {
                used[i] = true;
                current_permutation.push_back(nums[i]);
                generatePermutations(nums, used, current_permutation, result);
                current_permutation.pop_back();
                used[i] = false;
            }
        }
    }
public:
    int kInversePairs(int n, int k) {
        vector<int>a;
        for(int i=1; i<=n; ++i){
            a.push_back(i);
        }
        vector<vector<int>> ans = permute(a);

        int cnt = 0;
        for(auto& v: ans){
            int inv_pairs = 0;
            for(int i=0; i<v.size()-1; ++i){
                for(int j=i+1; j<v.size(); ++j){
                    if(v[i] > v[j]){
                       inv_pairs++;
                    }
                }
            }
            if(inv_pairs == k) cnt++;
        }
        return cnt%MOD;

    }
};
```

**Intuition**
Let's say we have n elements in our permutation then Depending on where we put the element (n+1) in our permutation, we may add 0, 1, 2, ..., n new inverse pairs. For example, if we have some permutation of 1...4, then:

5 x x x x creates 4 new inverse pairs
x 5 x x x creates 3 new inverse pairs
...
x x x x 5 creates 0 new inverse pairs
**Approach**
dp[n][k] = dp[n - 1][k - 0] + dp[n - 1][k - 1] + ... + dp[n - 1][k - (n - 1)]

Complexity
Time complexity: O(n∗k∗k) to O(n∗k)O(n\*k)O(n∗k)

Space complexity:O(n∗k) to O(k)O(k)O(k)

## Memoization - TLE 80/81 passed

```cpp
class Solution {
public:
    int MOD = 1e9 + 7;
    int dp[1001][1001];
    int kInversePairs(int n, int k) {
        memset(dp, -1, sizeof(dp));
        return helper(n, k);
    }

    int helper(int n, int k){
        if(k == 0) return 1;
        if(k < 0) return 0;

        if(dp[n][k]!=-1) return dp[n][k];

        int ans = 0;

        for(int i=0; i<n; ++i){
            ans += helper(n-1, k-i);
            ans%=MOD;
        }
        return dp[n][k] = ans;
    }
};
```

## Tabulation - Accepted

```cpp
class Solution {
private:
    int mod = 1e9+7;
    int dp[1001][1001];
public:
    int kInversePairs(int n, int k) {
        memset(dp, 0, sizeof(dp));
        //base case
        for(int N=0;N<=n;++N) dp[N][0]=1;

        for(int N=1;N<=n;++N) {
            for(int K=0;K<=k;++K) {
                int ans=0;
                for(int i=0;i<min(N,K+1);++i) {
                    ans+=dp[N-1][K-i];
                    ans%=mod;
                }
                dp[N][K]=ans;
            }
        }
        return dp[n][k];
    }
};
```

**Optimization Idea**
f(n, k) = f(n-1, k) + f(n-1, k-1) + f(n-1, k-2) + ... + f(n-1, k-n+1) --->(1)

f(n, k-1) = f(n-1, k-1) + f(n-1, k-2) + f(n-1, k-3) + ... + f(n-1, k-n+1)+ f(n-1, k-n) --->(2)

subtract eqn 2 from eqn 1,we get

f(n, k) = f(n, k-1) + f(n-1, k) - f(n-1, k-n)

**Time-Optimized Tabulation**

```cpp
class Solution {
private:
    int MOD = 1e9+7;
    int dp[1001][1001];
public:
    int kInversePairs(int n, int k) {
        memset(dp, 0, sizeof(dp));
        //base case
        for(int N=0;N<=n;++N) dp[N][0]=1;

        for(int N=1;N<=n;++N) {
            for(int K=0;K<=k;++K) {
                dp[N][K] = (dp[N-1][K] + (K > 0 ? dp[N][K-1] : 0))%MOD;

                dp[N][K] = (dp[N][K] + MOD - (K >= N ? dp[N-1][K-N] : 0))%MOD;
            }
        }
        return dp[n][k];
    }
};
```

**Time & Space Optimized Tabulation**

```cpp
class Solution {
private:
    const int mod=int(1e9+7);
public:
    int kInversePairs(int n, int k) {
        vector<int> prev(k+1,0),curr(k+1,0);
        prev[0]=curr[0]=1;
        for(int N=1;N<=n;++N) {
            for(int K=0;K<=k;++K) {
                curr[K] = (prev[K] + (K > 0 ? curr[K - 1] : 0)) % mod;
                curr[K] = (curr[K] + mod - (K >= N ? prev[K-N] : 0)) % mod;
            }
            prev = curr;
        }
        return curr[k];
    }
};
```
