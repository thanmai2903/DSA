# Dynamic Programming

## Example 1: Fibonacci Sequence

### Problem

Given an integer `n`, find the nth Fibonacci number.

### State

`F(n)` represents the nth Fibonacci number.

### Transition

$$
 F(n) = F(n-1) + F(n-2)
$$

### Base Case

$$ F(0) = 0, F(1) = 1 $$

### Final Subproblem

Calculate \(F(n)\).

---

## Example 2: Coin Change Problem

### Problem

Given coins of different denominations and a total amount, find the minimum number of coins needed to make up that amount.

### State

`dp[i]` represents the minimum number of coins needed to make amount `i`.

### Transition

$$
dp[i] = min(dp[i], dp[i - c] + 1)
$$

### Base Case

$$
dp[0] = 0 ({0 coins are needed to make up amount 0})
$$

### Final Subproblem

`dp[amount]` gives the minimum number of coins needed for the given amount.

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int coinChange(vector<int>& coins, int amount) {
    // Initialize dp array with a large value (amount + 1)
    vector<int> dp(amount + 1, amount + 1);
    dp[0] = 0; // Base case

    // Iterate through each amount from 1 to the target amount
    for (int i = 1; i <= amount; ++i) {
        // Check each coin
        for (int coin : coins) {
            if (i - coin >= 0) {
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
    }

    // If dp[amount] is still amount + 1, it means the amount cannot be formed with given coins
    return dp[amount] > amount ? -1 : dp[amount];
}

int main() {
    vector<int> coins = {1, 2, 5};
    int amount = 11;
    int result = coinChange(coins, amount);
    if (result != -1) {
        cout << "Minimum number of coins needed: " << result << endl;
    } else {
        cout << "It's not possible to make up the amount with the given coins." << endl;
    }
    return 0;
}

```

---

## Example 3: Longest Increasing Subsequence

### Problem

Find the length of the longest subsequence such that all elements of the subsequence are sorted in increasing order.

### State

`dp[i]` represents the length of the longest increasing subsequence ending at index `i`.

### Transition

$$
dp[i] = \max(dp[i], dp[j] + 1) \quad \text{if } arr[i] > arr[j]
$$

### Base Case

dp[i] = 1 {each element is a subsequence of length 1 by itself}

### Final Subproblem

The length of the longest increasing subsequence is the maximum value in `dp`.

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int lengthOfLIS(vector<int>& nums) {
    if (nums.empty()) return 0;

    int n = nums.size();
    vector<int> dp(n, 1); // Initialize dp array with 1

    // Fill dp array based on the state transition
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (nums[i] > nums[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    // The length of the longest increasing subsequence is the maximum value in dp array
    return *max_element(dp.begin(), dp.end());
}

int main() {
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    int result = lengthOfLIS(nums);
    cout << "Length of the longest increasing subsequence: " << result << endl;
    return 0;
}

```

---

## Example 4: 0/1 Knapsack Problem

### Problem

Given a set of items, each with a weight and a value, determine the maximum value that can be obtained by selecting items such that the total weight does not exceed the given capacity.

### State

`dp[i][w]` represents the maximum value that can be obtained using the first `i` items with a total weight `w`.

### Transition

$$
dp[i][w] = max(dp[i-1][w], dp[i-1]w - weight[i-1]] + value[i-1])
$$

### Base Case

dp[0][w] = 0
dp[i][0] = 0

### Final Subproblem

`dp[n][W]` gives the maximum value for `n` items and capacity `W`.

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int knapsack(int W, vector<int>& weights, vector<int>& values, int n) {
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    // Fill the dp array according to the state transition
    for (int i = 1; i <= n; ++i) {
        for (int w = 1; w <= W; ++w) {
            if (weights[i-1] <= w) {
                dp[i][w] = max(dp[i-1][w], dp[i-1][w - weights[i-1]] + values[i-1]);
            } else {
                dp[i][w] = dp[i-1][w];
            }
        }
    }

    // The maximum value is in dp[n][W]
    return dp[n][W];
}

int main() {
    int W = 50; // Capacity of the knapsack
    vector<int> weights = {10, 20, 30}; // Weights of the items
    vector<int> values = {60, 100, 120}; // Values of the items
    int n = weights.size(); // Number of items

    int max_value = knapsack(W, weights, values, n);
    cout << "Maximum value in the knapsack: " << max_value << endl;
    return 0;
}

```

---

## Example 5: Edit Distance (Levenshtein Distance)

### Problem

Given two strings, find the minimum number of operations (insertions, deletions, substitutions) required to convert one string into the other.

### State

`dp[i][j]` represents the minimum number of operations required to convert the first `i` characters of string `s1` to the first `j` characters of string `s2`.

### Transition

$$
dp[i][j] = min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + 1 \quad \text{if } s1[i-1] != s2[j-1]
$$

$$
dp[i][j] = dp[i-1][j-1] \quad \text{if } s1[i-1] == s2[j-1]
$$

### Base Case

$$
dp[i][0] = i
$$

$$
dp[0][j] = j
$$

### Final Subproblem

`dp[m][n]` gives the edit distance between strings `s1` of length `m` and `s2` of length `n`.

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minDistance(string s1, string s2) {
    int m = s1.size();
    int n = s2.size();

    // Create a dp table to store results of subproblems
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));

    // Initialize base cases
    for (int i = 0; i <= m; ++i) {
        dp[i][0] = i; // Deleting all characters from s1 to match empty s2
    }
    for (int j = 0; j <= n; ++j) {
        dp[0][j] = j; // Inserting all characters into empty s1 to match s2
    }

    // Fill dp table according to state transition
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (s1[i-1] == s2[j-1]) {
                dp[i][j] = dp[i-1][j-1]; // Characters match, no new operation
            } else {
                dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1; // Minimum of insert, delete, substitute
            }
        }
    }

    // The answer is in dp[m][n]
    return dp[m][n];
}

int main() {
    string s1 = "intention";
    string s2 = "execution";
    int result = minDistance(s1, s2);
    cout << "Minimum edit distance: " << result << endl;
    return 0;
}
```

---

## Example 6: Maximum Subarray Sum (Kadane's Algorithm)

### Problem

Find the maximum sum of a contiguous subarray within a given one-dimensional array of numbers.

### State

`dp[i]` represents the maximum subarray sum ending at index `i`.

### Transition

$$
dp[i] = \max(arr[i], dp[i-1] + arr[i])
$$

### Base Case

$$
dp[0] = arr[0]
$$

### Final Subproblem

The maximum subarray sum is the maximum value in the `dp` array.

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxSubArray(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;

    vector<int> dp(n);
    dp[0] = nums[0];
    int max_sum = dp[0];

    for (int i = 1; i < n; ++i) {
        dp[i] = max(nums[i], dp[i-1] + nums[i]);
        max_sum = max(max_sum, dp[i]);
    }

    return max_sum;
}

int main() {
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int result = maxSubArray(nums);
    cout << "Maximum subarray sum: " << result << endl;
    return 0;
}
```

---

## Example 7: Longest Common Subsequence (LCS)

### Problem

Given two sequences, find the length of their longest common subsequence.

### State

`dp[i][j]` represents the length of the longest common subsequence of the first `i` characters of `s1` and the first `j` characters of `s2`.

### Transition

## Transition

$$
dp[i][j] = dp[i-1][j-1] + 1 \quad \text{if } s1[i-1] == s2[j-1]
$$

$$
dp[i][j] = \max(dp[i-1][j], dp[i][j-1]) \quad \text{if } s1[i-1] \neq s2[j-1]
$$

### Base Case

$$
dp[0][j] = 0 ;
dp[i][0] = 0
$$

### Final Subproblem

`dp[m][n]` gives the length of the LCS of `s1` of length `m` and `s2` of length `n`.

```cpp
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int longestCommonSubsequence(string s1, string s2) {
    int m = s1.size();
    int n = s2.size();

    // Create a dp table with dimensions (m+1) x (n+1) initialized to 0
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    // Fill the dp table according to the state transition
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (s1[i-1] == s2[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    // The answer is in dp[m][n]
    return dp[m][n];
}

int main() {
    string s1 = "abcde";
    string s2 = "ace";
    int result = longestCommonSubsequence(s1, s2);
    cout << "Length of the longest common subsequence: " << result << endl;
    return 0;
}
```

---

## Example 8: Minimum Path Sum in a Grid

### Problem

Given a `m x n` grid filled with non-negative numbers, find a path from the top left to the bottom right which minimizes the sum of all numbers along its path.

### State

`dp[i][j]` represents the minimum path sum to reach cell `(i, j)`.

### Transition

$$
 dp[i][j] = grid[i][j] + \min(dp[i-1][j], dp[i][j-1])
$$

### Base Case

$$
 dp[0][0] = grid[0][0]
$$

$$
dp[i][0] = dp[i-1][0] + grid[i][0]
$$

$$
dp[0][j] = dp[0][j-1] + grid[0][j]
$$

### Final Subproblem

`dp[m-1][n-1]` gives the minimum path sum to reach the bottom right corner.

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minPathSum(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();

    // Create a dp table with the same dimensions as grid
    vector<vector<int>> dp(m, vector<int>(n, 0));

    // Base case
    dp[0][0] = grid[0][0];

    // Initialize the first column
    for (int i = 1; i < m; ++i) {
        dp[i][0] = dp[i-1][0] + grid[i][0];
    }

    // Initialize the first row
    for (int j = 1; j < n; ++j) {
        dp[0][j] = dp[0][j-1] + grid[0][j];
    }

    // Fill the dp table
    for (int i = 1; i < m; ++i) {
        for (int j = 1; j < n; ++j) {
            dp[i][j] = grid[i][j] + min(dp[i-1][j], dp[i][j-1]);
        }
    }

    // The answer is in the bottom-right cell of the dp table
    return dp[m-1][n-1];
}

int main() {
    vector<vector<int>> grid = {
        {1, 3, 1},
        {1, 5, 1},
        {4, 2, 1}
    };
    int result = minPathSum(grid);
    cout << "Minimum path sum: " << result << endl;
    return 0;
}

```

---

## Example 9: House Robber Problem

### Problem

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police (i.e., you cannot rob two adjacent houses).

### State

`dp[i]` represents the maximum amount of money that can be robbed from the first `i` houses.

### Transition

$$
 dp[i] = \max(dp[i-1], dp[i-2] + nums[i])
$$

### Base Case

$$
dp[0] = nums[0]
$$

$$
dp[1] = \max(nums[0], nums[1])
$$

### Final Subproblem

The maximum amount of money that can be robbed from all houses is `dp[n-1]`.

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int rob(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;
    if (n == 1) return nums[0];

    vector<int> dp(n);
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);

    for (int i = 2; i < n; ++i) {
        dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
    }

    return dp[n-1];
}

int main() {
    vector<int> nums = {2, 7, 9, 3, 1};
    int result = rob(nums);
    cout << "Maximum amount of money that can be robbed: " << result << endl;
    return 0;
}

```

---

## Example 10: Climbing Stairs

### Problem

You are climbing a staircase. It takes `n` steps to reach the top. Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

### State

`dp[i]` represents the number of distinct ways to reach the \(i\)-th step.

### Transition

$$
dp[i] = dp[i-1] + dp[i-2]
$$

### Base Case

$$ dp[0] = 1 $$
$$ dp[1] = 1 $$

### Final Subproblem

`dp[n]` gives the number of distinct ways to reach the top.

```cpp
#include <iostream>
#include <vector>
using namespace std;

int climbStairs(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;

    vector<int> dp(n + 1);
    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i <= n; ++i) {
        dp[i] = dp[i-1] + dp[i-2];
    }

    return dp[n];
}

int main() {
    int n = 5; // Example input
    int result = climbStairs(n);
    cout << "Number of distinct ways to climb to the top: " << result << endl;
    return 0;
}

```

---

## Example 11: Longest Palindromic Subsequence

### Problem

Given a string, find the length of the longest subsequence which is a palindrome.

### State

`dp[i][j]` represents the length of the longest palindromic subsequence in the substring `s[i...j]`.

### Transition

$$ dp[i][j] = dp[i+1][j-1] + 2 \quad \text{if } s[i] == s[j] $$
$$ dp[i][j] = \max(dp[i+1][j], dp[i][j-1]) \quad \text{if } s[i] \neq s[j] $$

### Base Case

$$ dp[i][i] = 1 $$

### Final Subproblem

`dp[0][n-1]` gives the length of the longest palindromic subsequence in the string `s`.

```cpp
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int longestPalindromeSubseq(string s) {
    int n = s.size();
    if (n == 0) return 0;

    // Create a dp table with dimensions (n) x (n)
    vector<vector<int>> dp(n, vector<int>(n, 0));

    // Base case: single letters are palindromes of length 1
    for (int i = 0; i < n; ++i) {
        dp[i][i] = 1;
    }

    // Fill the dp table
    for (int len = 2; len <= n; ++len) { // len is the length of the substring
        for (int i = 0; i <= n - len; ++i) {
            int j = i + len - 1; // endpoint of the substring
            if (s[i] == s[j]) {
                dp[i][j] = dp[i+1][j-1] + 2;
            } else {
                dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
            }
        }
    }

    // The result is in dp[0][n-1]
    return dp[0][n-1];
}

int main() {
    string s = "bbbab";
    int result = longestPalindromeSubseq(s);
    cout << "Length of the longest palindromic subsequence: " << result << endl;
    return 0;
}

```

---

## Example 12: Matrix Chain Multiplication

### Problem

Given a sequence of matrices, find the most efficient way to multiply these matrices together. The problem is not actually to perform the multiplications but merely to decide in which order to perform the multiplications.

### State

`dp[i][j]` represents the minimum number of scalar multiplications needed to compute the matrix `M[i...j]`.

### Transition

$$ dp[i][j] = \min\_{i \leq k < j} (dp[i][k] + dp[k+1][j] + cost_of_multiplication(M[i...k], M[k+1...j])) $$

### Base Case

$$ dp[i][i] = 0 $$

### Final Subproblem

`dp[1][n-1]` gives the minimum number of multiplications needed to multiply matrices from 1 to `n`.

```cpp
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int matrixChainOrder(vector<int>& p) {
    int n = p.size() - 1;
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    // dp[i][i] is 0 for all i
    for (int i = 1; i <= n; ++i) {
        dp[i][i] = 0;
    }

    // L is the chain length.
    for (int L = 2; L <= n; ++L) {
        for (int i = 1; i <= n - L + 1; ++i) {
            int j = i + L - 1;
            dp[i][j] = INT_MAX;
            for (int k = i; k < j; ++k) {
                int q = dp[i][k] + dp[k+1][j] + p[i-1] * p[k] * p[j];
                if (q < dp[i][j]) {
                    dp[i][j] = q;
                }
            }
        }
    }

    return dp[1][n];
}

int main() {
    vector<int> p = {1, 2, 3, 4};
    int result = matrixChainOrder(p);
    cout << "Minimum number of multiplications is: " << result << endl;
    return 0;
}

```

---

## Example 13: Partition Equal Subset Sum

### Problem

Given a set of positive integers, determine if it can be partitioned into two subsets with equal sum.

### State

`dp[i][j]` represents whether a sum `j` can be achieved using the first `i` numbers.

### Transition

$$ dp[i][j] = dp[i-1][j] \quad \text{or} \quad dp[i-1]j - nums[i-1]] $$

### Base Case

$$ dp[i][0] = true $$
$$ dp[0][j] = false \quad \text{for } j > 0 $$

### Final Subproblem

Determine if `dp[n][target]` is `true`, where `target` is half the sum of the set (only if the sum is even).

```cpp
#include <iostream>
#include <vector>
using namespace std;

bool canPartition(vector<int>& nums) {
    int sum = 0;
    for (int num : nums) {
        sum += num;
    }

    // If the total sum is odd, we cannot partition it into two equal subsets
    if (sum % 2 != 0) {
        return false;
    }

    int target = sum / 2;
    int n = nums.size();

    // Create a dp array with dimensions (n+1) x (target+1)
    vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));

    // Initialize base cases
    for (int i = 0; i <= n; ++i) {
        dp[i][0] = true;
    }

    // Fill the dp table
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= target; ++j) {
            if (j >= nums[i-1]) {
                dp[i][j] = dp[i-1][j] || dp[i-1][j - nums[i-1]];
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    // The answer is whether we can partition into subsets with sum equal to target
    return dp[n][target];
}

int main() {
    vector<int> nums = {1, 5, 11, 5};
    bool result = canPartition(nums);
    if (result) {
        cout << "The set can be partitioned into two subsets with equal sum." << endl;
    } else {
        cout << "The set cannot be partitioned into two subsets with equal sum." << endl;
    }
    return 0;
}

```

---

## Example 14: Wildcard Matching

### Problem

Given an input string `s` and a pattern `p`, implement wildcard pattern matching with support for '?' and '_'. The '?' matches any single character, and '_' matches any sequence of characters (including the empty sequence).

### State

`dp[i][j]` represents whether the first `i` characters in the string `s` match the first `j` characters of the pattern `p`.

### transition

$$
dp[i][j] = dp[i-1][j-1] \quad \text{if } s[i-1] == p[j-1] \text{ or } p[j-1] == '?'
$$

$$
dp[i][j] = dp[i][j-1] \quad \text{or} \quad dp[i-1][j] \quad \text{if } p[j-1] == '*'
$$

## Base Case

$$
dp[0][0] = true
$$

$$
dp[i][0] = false \quad \text{for } i > 0
$$

$$
dp[0][j] = dp[0][j-1] \quad \text{if } p[j-1] == '*'
$$

## Final Subproblem

`dp[m][n]` gives whether the entire string `s` matches the pattern `p`.

```cpp
#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool isMatch(string s, string p) {
    int m = s.size(), n = p.size();
    vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
    dp[0][0] = true;

    for (int j = 1; j <= n; ++j) {
        if (p[j-1] == '*') {
            dp[0][j] = dp[0][j-1];
        }
    }

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (p[j-1] == '*') {
                dp[i][j] = dp[i][j-1] || dp[i-1][j];
            } else if (p[j-1] == '?' || s[i-1] == p[j-1]) {
                dp[i][j] = dp[i-1][j-1];
            }
        }
    }

    return dp[m][n];
}

int main() {
    string s = "adceb";
    string p = "*a*b";
    bool result = isMatch(s, p);
    if (result) {
        cout << "The string matches the pattern." << endl;
    } else {
        cout << "The string does not match the pattern." << endl;
    }
    return 0;
}
```

---

## Example 15: Word Break Problem

### Problem

Given a string `s` and a dictionary of words `dict`, determine if `s` can be segmented into a space-separated sequence of one or more dictionary words.

### State

`dp[i]` represents whether the substring `s[0...i-1]` can be segmented into dictionary words.

### Transition

$$ dp[i] = dp[j] \quad \text{if } s[j...i-1] \in dict $$

### Base Case

$$ dp[0] = true $$

### Final Subproblem

`dp[n]` gives whether the entire string `s` can be segmented using dictionary words.

```cpp
#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

bool wordBreak(string s, vector<string>& wordDict) {
    unordered_set<string> dict(wordDict.begin(), wordDict.end());
    int n = s.size();
    vector<bool> dp(n + 1, false);
    dp[0] = true;

    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (dp[j] && dict.find(s.substr(j, i - j)) != dict.end()) {
                dp[i] = true;
                break;
            }
        }
    }

    return dp[n];
}

int main() {
    string s = "leetcode";
    vector<string> wordDict = {"leet", "code"};
    bool result = wordBreak(s, wordDict);
    if (result) {
        cout << "The string can be segmented into dictionary words." << endl;
    } else {
        cout << "The string cannot be segmented into dictionary words." << endl;
    }
    return 0;
}

```

---

## Example 16: Minimum Cost to Paint Houses

### Problem

There are `n` houses in a row. Each house can be painted with one of three colors. You have to paint all the houses such that no two adjacent houses have the same color. The cost of painting each house with a certain color is different. Find the minimum cost to paint all houses.

### State

`dp[i][c]` represents the minimum cost to paint house `i` with color `c`.

### Transition

$$ dp[i][0] = cost[i][0] + \min(dp[i-1][1], dp[i-1][2]) $$
$$ dp[i][1] = cost[i][1] + \min(dp[i-1][0], dp[i-1][2]) $$
$$ dp[i][2] = cost[i][2] + \min(dp[i-1][0], dp[i-1][1]) $$

### Base Case

$$ dp[0][0] = cost[0][0] $$
$$ dp[0][1] = cost[0][1] $$
$$ dp[0][2] = cost[0][2] $$

### Final Subproblem

The minimum cost to paint all houses is:
$$ \min(dp[n-1][0], dp[n-1][1], dp[n-1][2]) $$

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minCost(vector<vector<int>>& costs) {
    if (costs.empty()) return 0;
    int n = costs.size();
    vector<vector<int>> dp(n, vector<int>(3, 0));

    dp[0][0] = costs[0][0];
    dp[0][1] = costs[0][1];
    dp[0][2] = costs[0][2];

    for (int i = 1; i < n; ++i) {
        dp[i][0] = costs[i][0] + min(dp[i-1][1], dp[i-1][2]);
        dp[i][1] = costs[i][1] + min(dp[i-1][0], dp[i-1][2]);
        dp[i][2] = costs[i][2] + min(dp[i-1][0], dp[i-1][1]);
    }

    return min({dp[n-1][0], dp[n-1][1], dp[n-1][2]});
}

int main() {
    vector<vector<int>> costs = {{17, 2, 17}, {16, 16, 5}, {14, 3, 19}};
    int result = minCost(costs);
    cout << "The minimum cost to paint all houses is: " << result << endl;
    return 0;
}

```

---

## Example 17: Palindrome Partitioning II

### Problem

Given a string `s`, partition `s` such that every substring of the partition is a palindrome. Return the minimum cuts needed for a palindrome partitioning of `s`.

### State

`dp[i]` represents the minimum number of cuts needed for a palindrome partitioning of the substring `s[0...i]`.

### Transition

$$ dp[i] = 0 \quad \text{if } s[0...i] \text{ is a palindrome} $$

$$
 dp[i] = \min(dp[i], dp[j-1] + 1) \quad \text{if } s[j...i] \text{ is a palindrome}
$$

### Base Case

$$ dp[i] = 0 \quad \text{if } s[0...i] \text{ is a palindrome} $$

### Final Subproblem

`dp[n-1]` gives the minimum number of cuts needed for the entire string `s`.

```cpp
class Solution {
public:
    int minCut(string s) {
        //dp[i] -> Min cuts of s in [0..i] such that it is a palindrome.
        int n = size(s);
        vector<vector<bool>> isPalin(n, vector<bool> (n,false));
        vector<int>dp(n, 0);

        //pre-compute isPalin
        for(int i=0; i<n; ++i){
            dp[i] = i;//max cuts is it's length
            for(int j=0; j<=i; ++j){
                //j...i is palindrome if s[i] == s[j] and (len == 1/2 or [j+1...i-1] inner substring is palindrome)
                if(s[i] == s[j] && (i-j<=1 || isPalin[j+1][i-1])){
                    isPalin[j][i] = true;
                    dp[i] = (j == 0) ? 0 : min(dp[i], dp[j-1]+1);
                }
            }
        }

        return dp[n-1];
    }
};
```

---

## Example 18: Maximum Profit in Job Scheduling

### Problem

Given `n` jobs, each represented by start time, end time, and profit, find the maximum profit you can achieve by scheduling non-overlapping jobs.

### State

`dp[i]` represents the maximum profit that can be obtained by considering the first `i` jobs.

### Transition

$$ dp[i] = \max(dp[i-1], profit[i] + dp[last\_non\_conflicting\_job]) $$

### Base Case

$$ dp[0] = profit[0] $$

### Final Subproblem

`dp[n-1]` gives the maximum profit for all jobs.

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Job {
    int start, end, profit;
};

bool jobComparator(Job s1, Job s2) {
    return s1.end < s2.end;
}

int latestNonConflict(vector<Job>& jobs, int i) {
    for (int j = i - 1; j >= 0; j--) {
        if (jobs[j].end <= jobs[i].start) {
            return j;
        }
    }
    return -1;
}

int maxProfit(vector<Job>& jobs) {
    sort(jobs.begin(), jobs.end(), jobComparator);
    int n = jobs.size();
    vector<int> dp(n);
    dp[0] = jobs[0].profit;

    for (int i = 1; i < n; i++) {
        int inclProfit = jobs[i].profit;
        int l = latestNonConflict(jobs, i);
        if (l != -1) {
            inclProfit += dp[l];
        }
        dp[i] = max(inclProfit, dp[i-1]);
    }

    return *max_element(dp.begin(), dp.end());
}

int main() {
    vector<Job> jobs = {{1, 2, 50}, {3, 5, 20}, {6, 19, 100}, {2, 100, 200}};
    int result = maxProfit(jobs);
    cout << "The maximum profit that can be achieved is: " << result << endl;
    return 0;
}

```

---

## Example 19: Russian Doll Envelopes

### Problem

You have a number of envelopes with width and height given as a pair of integers `(w, h)`. One envelope can fit into another if both the width and height of one envelope are greater than the width and height of the other envelope. Find the maximum number of envelopes you can put one inside the other.

### State

`dp[i]` represents the maximum number of envelopes ending with envelope `i`.

### Transition

$$ dp[i] = \max(dp[i], dp[j] + 1) \quad \text{if } width[i] > width[j] \text{ and } height[i] > height[j] $$

### Base Case

$$ dp[i] = 1 $$

### Final Subproblem

The maximum number of envelopes is the maximum value in `dp`.

```cpp
//TLE
class Solution {
public:
    static bool comp(const vector<int>& a, const vector<int>& b) {
        if(a[0] == b[0]) {
            return a[1] > b[1];
        }
        return a[0] < b[0];
    }

    int maxEnvelopes(vector<vector<int>>& e) {
        sort(e.begin(), e.end(), comp);
        int n = e.size();
        vector<int> dp(n, 1);

        for(int i = 1; i < n; ++i) {
            for(int j = 0; j < i; ++j) {
                if(e[i][0] > e[j][0] && e[i][1] > e[j][1]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};
```

```cpp
class Solution {
public:
    static bool comp(const vector<int>& a, const vector<int>& b) {
        if(a[0] == b[0]) {
            return a[1] > b[1];
        }
        return a[0] < b[0];
    }

    int maxEnvelopes(vector<vector<int>>& e) {
        sort(e.begin(), e.end(), comp);
        int n = e.size();
        vector<int> lis;

        for(int i = 0; i < n; ++i) {
            auto it = lower_bound(lis.begin(), lis.end(), e[i][1]);
            if(it == lis.end()) {
                lis.push_back(e[i][1]);
            }else{
                *it = e[i][1];
            }
        }
        return lis.size();
    }
};
```

---

## Example 20: Super Egg Drop

### Problem

You are given `K` eggs and you have access to a building with `N` floors. Your goal is to find the minimum number of attempts you need to determine the highest floor from which an egg can be dropped without breaking.

### State

`dp[K][N]` represents the minimum number of attempts needed with `K` eggs and `N` floors.

### Transition

$$ dp[K][N] = 1 + \min\_{1 \leq i \leq N} \max(dp[K-1][i-1], dp[K][N-i]) $$

### Base Case

$$ dp[1][N] = N $$
$$ dp[K][0] = 0 $$

### Final Subproblem

`dp[K][N]` gives the minimum number of attempts needed with `K` eggs and `N` floors.

```cpp
//TLE
class Solution {
public:
    int superEggDrop(int K, int N) {
        vector<vector<int>> dp(K + 1, vector<int>(N + 1, 0));

        // Base case
        //if one egg => we have to try all floors
        for(int i = 1; i <= N; ++i) {
            dp[1][i] = i;
        }
        //if only one floor=> ans is 1
        //if no floors => ans is 0
        for(int i=1; i<=K; ++i){
            dp[i][1] = 1;
            dp[i][0] = 0;
        }

        // Fill the dp table
        for(int k = 2; k <= K; ++k) {
            for(int n = 2; n <= N; ++n) {
                dp[k][n] = INT_MAX;
                for(int x = 1; x <= n; ++x) {
                    int worst = 1 + max(dp[k-1][x-1], dp[k][n-x]);
                    dp[k][n] = min(dp[k][n], worst);
                }
            }
        }

        return dp[K][N];
    }
};
```

```cpp
class Solution {
public:
    int superEggDrop(int K, int N) {
        vector<vector<int>> dp(K + 1, vector<int>(N + 1, 0));

        // Base case: one egg
        for(int i = 1; i <= N; ++i) {
            dp[1][i] = i;
        }

        // Base case: zero floors
        for(int k = 1; k <= K; ++k) {
            dp[k][0] = 0;
            dp[k][1] = 1;  // one floor
        }

        // Fill the dp table
        for(int k = 2; k <= K; ++k) {
            for(int n = 2; n <= N; ++n) {
                dp[k][n] = INT_MAX;
                int low = 1, high = n;
                while(low <= high) {
                    int mid = (low + high) / 2;
                    int break_case = dp[k - 1][mid - 1];
                    int not_break_case = dp[k][n - mid];
                    int worst = 1 + max(break_case, not_break_case);
                    if(break_case > not_break_case) {
                        high = mid - 1;
                    }else{
                        low = mid + 1;
                    }
                    dp[k][n] = min(dp[k][n], worst);
                }
            }
        }

        return dp[K][N];
    }
};
```

---

## Example 21: Burst Balloons

### Problem

You are given `n` balloons, each with a number on it. You burst the balloons to maximize the total coins you get. The number of coins you get when you burst balloon `i` is `nums[i-1] * nums[i] * nums[i+1]`. If `i-1` or `i+1` goes out of bounds, assume the value is 1.

### State

`dp[i][j]` represents the maximum coins that can be obtained by bursting balloons between `i` and `j` (excluding `i` and `j`).

### Transition

$$ dp[i][j] = \max(dp[i][j], dp[i][k] + dp[k][j] + nums[i-1] _ nums[k] _ nums[j+1]) $$

### Base Case

$$ dp[i][i+1] = 0 $$

### Final Subproblem

`dp[0][n-1]` gives the maximum coins for bursting all balloons.

```cpp
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        //dp[i][j] -> Max coins u can collect by bursting b/w ith and jth balloon
        //traverse from i+1...j-1 becauz in b/w i and j pos is the state
        //dp[i][j] = max(dp[i][j],  dp[i][k] + dp[k][j] + nums[i]*nums[k]*nums[j] )
        //B.C -> dp[i][i+1] = 0;
        int n = size(nums);
        //add 1 at begin and end to avoid underflow
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        vector<vector<int>> dp(n+2, vector<int>(n+2, 0));

        for(int len=2; len<n+2; ++len){
            for(int i=0; i<n+2-len; ++i){
                int j = i+len;
                for(int k=i+1; k<j; ++k){
                    int temp = dp[i][k] + dp[k][j] + nums[i]*nums[k]*nums[j];
                    dp[i][j] = max(dp[i][j], temp);
                }
            }
        }
        return dp[0][n+1];
    }
};
```

---

## Example 22: Unique Paths

### Problem

You are given a grid with `m` rows and `n` columns. You start at the top-left corner and need to reach the bottom-right corner. You can only move down or right. How many unique paths are there?

### State

`dp[i][j]` represents the number of unique paths to reach cell `(i, j)`.

### Transition

$$ dp[i][j] = dp[i-1][j] + dp[i][j-1] $$

### Base Case

$$ dp[0][0] = 1 $$
$$ dp[i][0] = 1 $$
$$ dp[0][j] = 1 $$

### Final Subproblem

`dp[m-1][n-1]` gives the number of unique paths to the bottom-right corner.

```cpp
#include <iostream>
#include <vector>
using namespace std;

int uniquePaths(int m, int n) {
    // Create a dp table initialized to 1
    vector<vector<int>> dp(m, vector<int>(n, 1));

    // Fill the dp table based on the transition formula
    for (int i = 1; i < m; ++i) {
        for (int j = 1; j < n; ++j) {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }

    // The answer is in dp[m-1][n-1] (number of unique paths to bottom-right corner)
    return dp[m - 1][n - 1];
}

int main() {
    int m = 3, n = 7;
    cout << "Number of unique paths: " << uniquePaths(m, n) << endl;
    return 0;
}
```

---

## Example 23: Longest Palindromic Substring

### Problem

Given a string `s`, find the longest substring that is a palindrome.

### State

`dp[i][j]` represents whether the substring `s[i...j]` is a palindrome.

### Transition

$$ dp[i][j] = (s[i] == s[j]) \text{ and } (j - i < 3 \text{ or } dp[i+1][j-1]) $$

### Base Case

$$ dp[i][i] = true $$

### Final Subproblem

Find the maximum length substring for which `dp[i][j]` is `true`.

```cpp
#include <iostream>
#include <vector>
#include <string>
using namespace std;

string longestPalindrome(string s) {
    int n = s.length();
    if (n == 0) return "";

    // Create a dp table initialized to false
    vector<vector<bool>> dp(n, vector<bool>(n, false));

    int maxLength = 1; // The maximum length of palindrome found
    int start = 0; // The starting index of the longest palindromic substring

    // Base case: single letter substrings are palindromes
    for (int i = 0; i < n; ++i) {
        dp[i][i] = true;
    }

    // Base case: two consecutive identical letters are palindromes
    for (int i = 0; i < n - 1; ++i) {
        if (s[i] == s[i + 1]) {
            dp[i][i + 1] = true;
            start = i;
            maxLength = 2;
        }
    }

    // Fill the dp table for substrings longer than 2 characters
    for (int len = 3; len <= n; ++len) {
        for (int i = 0; i <= n - len; ++i) {
            int j = i + len - 1;
            if (s[i] == s[j] && dp[i + 1][j - 1]) {
                dp[i][j] = true;
                start = i;
                maxLength = len;
            }
        }
    }

    // The longest palindromic substring is from start to start + maxLength - 1
    return s.substr(start, maxLength);
}

int main() {
    string s = "babad";
    cout << "Longest palindromic substring: " << longestPalindrome(s) << endl;
    return 0;
}
```

---

## Example 24: Coin Change 2

### Problem

You are given coins of different denominations and a total amount of money. Find the number of ways to make up that amount using the coins. You can use each coin as many times as you want.

### State

`dp[i]` represents the number of ways to make up amount `i`.

### Transition

$$ dp[i] = dp[i] + dp[i - c] $$

### Base Case

$$ dp[0] = 1 $$

### Final Subproblem

`dp[amount]` gives the number of ways to make up the given amount.

```cpp
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        //dp[i][j] -< no of ways to get amount j till index i
        //dp[i][j] = dp[i-1][j] + dp[i][j-coin]

        //B.C
        //amount = 0 => one way
        int n = size(coins);
        vector<vector<int>> dp(n+1, vector<int>(amount+1, 0));
        for(int i=0; i<=n; ++i){
            dp[i][0] = 1;
        }
        for(int i=1; i<=n; ++i){
            for(int j=0; j<=amount; ++j){
                if(coins[i-1]>j){
                    dp[i][j] = dp[i-1][j];
                }
                else dp[i][j] = dp[i-1][j] + dp[i][j-coins[i-1]];
            }
        }
        return dp[n][amount];
    }
};
```

---

## Example 25: Minimum Path Sum

### Problem

Given a `m x n` grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

### State

`dp[i][j]` represents the minimum path sum to reach cell `(i, j)`.

### Transition

$$ dp[i][j] = grid[i][j] + \min(dp[i-1][j], dp[i][j-1]) $$

### Base Case

$$ dp[0][0] = grid[0][0] $$
$$ dp[i][0] = dp[i-1][0] + grid[i][0] $$
$$ dp[0][j] = dp[0][j-1] + grid[0][j] $$

### Final Subproblem

`dp[m-1][n-1]` gives the minimum path sum to the bottom-right corner.

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minPathSum(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();

    // Create a dp table
    vector<vector<int>> dp(m, vector<int>(n, 0));

    // Base Case
    dp[0][0] = grid[0][0];

    // Initialize first column of the dp table
    for (int i = 1; i < m; ++i) {
        dp[i][0] = dp[i - 1][0] + grid[i][0];
    }

    // Initialize first row of the dp table
    for (int j = 1; j < n; ++j) {
        dp[0][j] = dp[0][j - 1] + grid[0][j];
    }

    // Fill the dp table
    for (int i = 1; i < m; ++i) {
        for (int j = 1; j < n; ++j) {
            dp[i][j] = grid[i][j] + min(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    // The answer is in dp[m-1][n-1] (minimum path sum to bottom-right corner)
    return dp[m - 1][n - 1];
}

int main() {
    vector<vector<int>> grid = {
        {1, 3, 1},
        {1, 5, 1},
        {4, 2, 1}
    };
    cout << "Minimum path sum: " << minPathSum(grid) << endl;
    return 0;
}

```

---

## Example 26: Subset Sum

### Problem

Given a set of positive integers and a value `sum`, determine if there is a subset of the given set with sum equal to `sum`.

### State

`dp[i][j]` represents whether a subset of the first `i` elements has a sum equal to `j`.

### Transition

$$ dp[i][j] = dp[i-1][j] \quad \text{or} \quad dp[i-1]j - nums[i-1]] $$

### Base Case

$$ dp[i][0] = true $$
$$ dp[0][j] = false \quad \text{for } j > 0 $$

### Final Subproblem

Determine if `dp[n][sum]` is `true`.

```cpp
#include <iostream>
#include <vector>
using namespace std;

bool isSubsetSum(vector<int>& nums, int sum) {
    int n = nums.size();

    // Create a dp table initialized to false
    vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, false));

    // Base Case: There is always a subset with sum 0 (the empty subset)
    for (int i = 0; i <= n; ++i) {
        dp[i][0] = true;
    }

    // Fill the dp table
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= sum; ++j) {
            if (nums[i - 1] > j) {
                dp[i][j] = dp[i - 1][j];
            } else {
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i - 1]];
            }
        }
    }

    // The answer is in dp[n][sum] (whether there is a subset with sum equal to `sum`)
    return dp[n][sum];
}

int main() {
    vector<int> nums = {3, 34, 4, 12, 5, 2};
    int sum = 9;
    if (isSubsetSum(nums, sum)) {
        cout << "Found a subset with given sum" << endl;
    } else {
        cout << "No subset with given sum" << endl;
    }
    return 0;
}
```

---

## Example 27: Maximum Product Subarray

### Problem

Given an integer array `nums`, find the contiguous subarray within an array (containing at least one number) which has the largest product.

### State

`dp_max[i]` and `dp_min[i]` represent the maximum and minimum product subarray ending at index `i`.

### Transition

$$ dp*max[i] = \max(nums[i], nums[i] * dp*max[i-1], nums[i] * dp*min[i-1]) $$
$$ dp_min[i] = \min(nums[i], nums[i] * dp*max[i-1], nums[i] * dp_min[i-1]) $$

### Base Case

$$ dp_max[0] = dp_min[0] = nums[0] $$

### Final Subproblem

The maximum product subarray is the maximum value in `dp_max`.

```cpp
int maxProduct(vector<int>& nums) {
    if (nums.empty()) return 0;

    int n = nums.size();
    vector<int> dp_max(n), dp_min(n);
    dp_max[0] = dp_min[0] = nums[0];
    int result = nums[0];

    for (int i = 1; i < n; ++i) {
        if (nums[i] >= 0) {
            dp_max[i] = max(nums[i], nums[i] * dp_max[i - 1]);
            dp_min[i] = min(nums[i], nums[i] * dp_min[i - 1]);
        } else {
            dp_max[i] = max(nums[i], nums[i] * dp_min[i - 1]);
            dp_min[i] = min(nums[i], nums[i] * dp_max[i - 1]);
        }
        result = max(result, dp_max[i]);
    }

    return result;
}
```

---

## Example 28: Regular Expression Matching

### Problem

Given an input string `s` and a pattern `p`, implement regular expression matching with support for `.` and `*`. `.` matches any single character, and `*` matches zero or more of the preceding element.

### State

`dp[i][j]` represents whether the first `i` characters in the string `s` match the first `j` characters of the pattern `p`.

### Transition

$$ dp[i][j] = dp[i-1][j-1] \quad \text{if } s[i-1] == p[j-1] \text{ or } p[j-1] == '.' $$
$$ dp[i][j] = dp[i][j-2] \quad \text{or} \quad dp[i-1][j] \quad \text{if } p[j-2] \text{ matches } s[i-1] \text{ or } p[j-2] == '.' $$

### Base Case

$$ dp[0][0] = true $$

### Final Subproblem

`dp[m][n]` gives whether the entire string `s` matches the pattern `p`.

```cpp
class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.length();
        int n = p.length();

        // Create a dp table initialized to false
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));

        // Base Case: empty string matches empty pattern
        dp[0][0] = true;

        // Handle patterns like a*, a*b*, a*b*c* that can match an empty string
        for (int j = 2; j <= n; ++j) {
            if (p[j - 1] == '*') {
                dp[0][j] = dp[0][j - 2];
            }
        }

        // Fill the dp table
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (p[j - 1] == '*') {
                    // Zero occurrence of the character before '*'
                    dp[i][j] = dp[i][j - 2];

                    // One or more occurrence of the character before '*'
                    if (p[j - 2] == s[i - 1] || p[j - 2] == '.') {
                        dp[i][j] = dp[i][j] || dp[i - 1][j];
                    }
                } else {
                    // Match if current characters are the same or pattern has '.'
                    if (s[i - 1] == p[j - 1] || p[j - 1] == '.') {
                        dp[i][j] = dp[i - 1][j - 1];
                    }
                }
            }
        }

        // The answer is whether the entire string matches the entire pattern
        return dp[m][n];
    }
};
```

---

## Example 29: Interleaving String

### Problem

Given strings `s1`, `s2`, and `s3`, find whether `s3` is formed by an interleaving of `s1` and `s2`.

### State

`dp[i][j]` represents whether `s3[0...i+j-1]` is an interleaving of `s1[0...i-1]` and `s2[0...j-1]`.

### Transition

$$ dp[i][j] = dp[i-1][j] \quad \text{if } s1[i-1] == s3[i+j-1] $$
$$ dp[i][j] = dp[i][j-1] \quad \text{if } s2[j-1] == s3[i+j-1] $$

### Base Case

$$ dp[0][0] = true $$

### Final Subproblem

`dp[m][n]` gives whether `s3` is an interleaving of `s1` and `s2`.

```cpp
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.length();
        int n = s2.length();

        // If the total length of s1 and s2 is not equal to the length of s3, return false
        if (m + n != s3.length()) return false;

        // Create a dp table initialized to false
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));

        // Base Case: empty strings interleave to form an empty string
        dp[0][0] = true;

        // Fill dp table for s1 being empty
        for (int j = 1; j <= n; ++j) {
            dp[0][j] = dp[0][j - 1] && (s2[j - 1] == s3[j - 1]);
        }

        // Fill dp table for s2 being empty
        for (int i = 1; i <= m; ++i) {
            dp[i][0] = dp[i - 1][0] && (s1[i - 1] == s3[i - 1]);
        }

        // Fill the rest of the dp table
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                dp[i][j] = (dp[i - 1][j] && s1[i - 1] == s3[i + j - 1]) ||
                           (dp[i][j - 1] && s2[j - 1] == s3[i + j - 1]);
            }
        }

        // The answer is in dp[m][n], whether s3 can be formed by interleaving s1 and s2
        return dp[m][n];
    }
};
```

---

## Example 30: Scramble String

### Problem

Given a string `s1`, we may represent it as a binary tree by partitioning it into two non-empty substrings recursively. A string `s2` is a scramble of `s1` if we can swap the children of some nodes in the tree of `s1` to get `s2`. Given two strings `s1` and `s2`, determine if `s2` is a scramble of `s1`.

### State

`dp[i][j][k]` represents whether the substring `s1[i...i+k-1]` is a scramble of `s2[j...j+k-1]`.

### Transition

$$ dp[i][j][k] = (dp[i][j][l] \text{ and } dp[i+l][j+l][k-l]) \quad \text{or} \quad (dp[i][j+k-l][l] \text{ and } dp[i+l][j][k-l]) $$

### Base Case

$$ dp[i][j][1] = (s1[i] == s2[j]) $$

### Final Subproblem

`dp[0][0][n]` gives whether `s1` is a scramble of `s2`.

## Example 31: Word Break II

**Problem**: Given a string `s` and a dictionary of words `dict`, add spaces in `s` to construct a sentence where each word is a valid dictionary word. Return all such possible sentences.

1. **State**: `dp[i]` represents all sentences that can be formed using the first `i` characters of `s`.
2. **Transition**: For each word in `dict`, if it matches `s[j:i]`, add the sentence formed by `dp[j]` + `word`.
3. **Base Case**: `dp[0] = [""]` (empty string).
4. **Final Subproblem**: `dp[n]` gives all possible sentences for the entire string.

## Example 32: Distinct Subsequences

**Problem**: Given two strings `s` and `t`, return the number of distinct subsequences of `s` which equals `t`.

1. **State**: `dp[i][j]` represents the number of distinct subsequences of `s[0...i-1]` which equals `t[0...j-1]`.
2. **Transition**: If `s[i-1] == t[j-1]`, `dp[i][j] = dp[i-1][j-1] + dp[i-1][j]`. Otherwise, `dp[i][j] = dp[i-1][j]`.
3. **Base Case**: `dp[i][0] = 1` for all `i` (an empty `t` is a subsequence of any `s`).
4. **Final Subproblem**: `dp[m][n]` gives the number of distinct subsequences of `s` that equal `t`.

## Example 33: Minimum Cost to Merge Stones

**Problem**: Given an array of stones where the `i`-th stone has weight `stones[i]`, merge adjacent stones into one. The cost of merging stones is the sum of their weights. Return the minimum cost to merge all stones into one stone.

1. **State**: `dp[i][j]` represents the minimum cost to merge stones from index `i` to `j`.
2. **Transition**: For each possible split point `k`, `dp[i][j] = min(dp[i][k] + dp[k+1][j] + sum(i...j))`.
3. **Base Case**: `dp[i][i] = 0` (a single stone has no merge cost).
4. **Final Subproblem**: `dp[0][n-1]` gives the minimum cost to merge all stones.

## Example 34: Maximum Length of Pair Chain

**Problem**: Given a set of pairs of integers, find the longest chain that can be formed. A chain is a sequence of pairs where the second element of each pair is less than the first element of the next pair.

1. **State**: `dp[i]` represents the length of the longest chain ending at pair `i`.
2. **Transition**: For each pair `j` where `j < i` and `pairs[j][1] < pairs[i][0]`, `dp[i] = max(dp[i], dp[j] + 1)`.
3. **Base Case**: `dp[i] = 1` for all `i` (each pair can be a chain of length 1).
4. **Final Subproblem**: The length of the longest chain is the maximum value in `dp`.

## Example 35: Largest Divisible Subset

**Problem**: Given a set of distinct positive integers, find the largest subset where every pair `(Si, Sj)` satisfies `Si % Sj == 0` or `Sj % Si == 0`.

1. **State**: `dp[i]` represents the largest divisible subset ending at index `i`.
2. **Transition**: For each `j < i` where `nums[i] % nums[j] == 0`, `dp[i] = max(dp[i], dp[j] + 1)`.
3. **Base Case**: `dp[i] = 1` for all `i` (each number can be a subset of size 1).
4. **Final Subproblem**: The size of the largest divisible subset is the maximum value in `dp`.

## Example 36: Shortest Palindrome

**Problem**: Given a string `s`, find the shortest palindrome that can be formed by adding characters in front of `s`.

1. **State**: `dp[i]` represents the length of the longest palindromic suffix ending at index `i`.
2. **Transition**: For each `j < i` where `s[j] == s[i]`, check if `s[j:i]` is a palindrome.
3. **Base Case**: `dp[i] = 1` (each character is a palindrome of length 1).
4. **Final Subproblem**: The shortest palindrome is formed by adding the non-palindromic prefix in reverse to the beginning of `s`.

## Example 37: Maximum Sum of 3 Non-Overlapping Subarrays

**Problem**: Given an array of integers, find three non-overlapping subarrays with maximum sum.

1. **State**: `dp[i][j]` represents the maximum sum of `i` subarrays ending before index `j`.
2. **Transition**: For each possible subarray, update the maximum sum by including the current subarray or excluding it.
3. **Base Case**: `dp[0][j] = 0` (no subarrays to consider).
4. **Final Subproblem**: The maximum sum of 3 non-overlapping subarrays is `dp[3][n]`.

## Example 38: Number of Ways to Paint `n` x `3` Grid

**Problem**: You are given an `n x 3` grid, and you need to paint it such that no two adjacent cells have the same color. Return the number of ways to paint the grid.

1. **State**: `dp[i][j]` represents the number of ways to paint the first `i` rows with the last row in color configuration `j`.
2. **Transition**: For each possible color configuration of the previous row, update the number of ways for the current row.
3. **Base Case**: Initialize `dp[0][j]` for all valid color configurations of the first row.
4. **Final Subproblem**: The total number of ways to paint the grid is the sum of `dp[n][j]` for all valid color configurations of the last row.

## Example 39: Domino and Tromino Tiling

**Problem**: Given a `2 x n` board, find the number of ways to tile the board using `2 x 1` dominoes and `2 x 2` and `1 x 2` trominoes.

1. **State**: `dp[i]` represents the number of ways to tile a `2 x i` board.
2. **Transition**: Consider placing dominoes and trominoes to update the number of ways for the current board size.
3. **Base Case**: Initialize `dp[0] = 1` and `dp[1] = 1` (base cases for the board of size `2 x 0` and `2 x 1`).
4. **Final Subproblem**: The total number of ways to tile the board is `dp[n]`.

## Example 40: Longest Arithmetic Subsequence

**Problem**: Given an array of integers, find the length of the longest arithmetic subsequence.

1. **State**: `dp[i][d]` represents the length of the longest arithmetic subsequence ending at index `i` with a common difference `d`.
2. **Transition**: For each `j < i`, update the length of the subsequence by extending the subsequence ending at `j` with the current element.
3. **Base Case**: Initialize `dp[i][d] = 1` for all `i` and possible differences `d`.
4. **Final Subproblem**: The length of the longest arithmetic subsequence is the maximum value in `dp`.

## Example 41: Minimum Window Substring

**Problem**: Given two strings `s` and `t`, find the minimum window in `s` which will contain all the characters in `t`.

1. **State**: `dp[i][j]` represents the minimum window in `s[0...i-1]` containing all characters in `t[0...j-1]`.
2. **Transition**: Update the minimum window length by including the current character in `s` or excluding it.
3. **Base Case**: `dp[0][j] = ""` for all `j` (empty string has no window).
4. **Final Subproblem**: Find the minimum window in `dp[n][m]`.

## Example 42: Minimum Difficulty of a Job Schedule

**Problem**: Given a list of job difficulties and an integer `d`, split the job list into `d` days such that the maximum difficulty of any job in a day is minimized.

1. **State**: `dp[i][k]` represents the minimum difficulty to schedule the first `i` jobs in `k` days.
2. **Transition**: For each job split point `j`, `dp[i][k] = min(dp[j][k-1] + max(jobs[j:i]))`.
3. **Base Case**: `dp[0][0] = 0` (no jobs, no difficulty).
4. **Final Subproblem**: `dp[n][d]` gives the minimum difficulty to schedule all jobs in `d` days.

## Example 43: Strange Printer

**Problem**: You have a strange printer with the following capabilities: it can print a sequence of the same character with each turn, and it can change the character it prints. Given a string, determine the minimum number of turns the printer needs to print it.

1. **State**: `dp[i][j]` represents the minimum number of turns needed to print the substring `s[i...j]`.
2. **Transition**: If `s[i] == s[j]`, `dp[i][j] = dp[i][j-1]`. Otherwise, `dp[i][j] = min(dp[i][k] + dp[k+1][j])` for all `i <= k < j`.
3. **Base Case**: `dp[i][i] = 1` (single character needs one turn).
4. **Final Subproblem**: `dp[0][n-1]` gives the minimum number of turns to print the entire string.

## Example 44: Maximum Vacation Days

**Problem**: Given `n` cities and a `k` weeks travel schedule, where traveling from one city to another has certain costs and each city has specific vacation days. Find the maximum vacation days you can spend.

1. **State**: `dp[i][j]` represents the maximum vacation days after `i` weeks ending in city `j`.
2. **Transition**: For each city `j`, update the maximum vacation days by considering traveling from any city `k` in the previous week.
3. **Base Case**: `dp[0][j]` is the vacation days in each city `j` for the first week.
4. **Final Subproblem**: The maximum vacation days is the maximum value in `dp[k][j]`.

## Example 45: Split Array Largest Sum

**Problem**: Given an array and an integer `m`, split the array into `m` non-empty subarrays such that the largest sum of any subarray is minimized.

1. **State**: `dp[i][j]` represents the minimum largest sum of splitting the first `i` elements into `j` subarrays.
2. **Transition**: For each possible split point `k`, `dp[i][j] = min(dp[i][j], max(dp[k][j-1], sum(k+1, i)))`.
3. **Base Case**: `dp[i][1] = sum(1, i)` (only one subarray).
4. **Final Subproblem**: `dp[n][m]` gives the minimum largest sum for splitting the array into `m` subarrays.

## Example 46: Non-negative Integers without Consecutive Ones

**Problem**: Given a positive integer `n`, count the number of non-negative integers less than or equal to `n` that do not contain consecutive ones in their binary representation.

1. **State**: `dp[i]` represents the number of valid integers of length `i`.
2. **Transition**: For each bit position, consider the number of valid integers ending in `0` or `1` without consecutive ones.
3. **Base Case**: Initialize `dp[0]` and `dp[1]` for the base cases.
4. **Final Subproblem**: Count valid integers for all bit lengths up to `n`.

## Example 47: Paint House II

**Problem**: There are a row of `n` houses, each house can be painted with one of the `k` colors. The cost of painting each house with a certain color is different. Find the minimum cost to paint all houses such that no two adjacent houses have the same color.

1. **State**: `dp[i][j]` represents the minimum cost to paint house `i` with color `j`.
2. **Transition**: For each house `i` and color `j`, update the cost considering the minimum cost of painting the previous house with any color except `j`.
3. **Base Case**: `dp[0][j] = cost[0][j]` for all `j`.
4. **Final Subproblem**: The minimum cost is the minimum value in `dp[n-1][j]`.

## Example 48: Domino and Tromino Tiling II

**Problem**: Given a `n x m` board, find the number of ways to tile the board using `2 x 1` dominoes and `2 x 2` and `1 x 2` trominoes.

1. **State**: `dp[i][j]` represents the number of ways to tile a `i x j` board.
2. **Transition**: Consider placing dominoes and trominoes in all possible ways to update the number of ways for the current board size.
3. **Base Case**: Initialize `dp[0][0]` and `dp[1][1]` for the base cases.
4. **Final Subproblem**: The total number of ways to tile the board is `dp[n][m]`.

## Example 49: K Inverse Pairs Array

**Problem**: Given two integers `n` and `k`, find the number of different arrays consisting of numbers from `1` to `n` such that there are exactly `k` inverse pairs.

1. **State**: `dp[i][j]` represents the number of arrays consisting of `1` to `i` with exactly `j` inverse pairs.
2. **Transition**: Update the number of inverse pairs by considering each position `k` and adjusting the number of pairs accordingly.
3. **Base Case**: `dp[i][0] = 1` for all `i` (no inverse pairs).
4. **Final Subproblem**: `dp[n][k]` gives the number of arrays with exactly `k` inverse pairs.

## Example 50: Minimum Number of Refueling Stops

**Problem**: A car travels from a starting point to a destination which is `target` miles away. The car has an initial `fuel` tank capacity, and there are gas stations along the way. Find the minimum number of refueling stops to reach the destination.

1. **State**: `dp[i]` represents the maximum distance that can be reached with `i` refueling stops.
2. **Transition**: For each gas station, update the maximum distance by considering refueling at the station or skipping it.
3. **Base Case**: `dp[0] = startFuel` (initial fuel).
4. **Final Subproblem**: Find the minimum `i` such that `dp[i] >= target`.

## Example 51: Number of Longest Increasing Subsequence

**Problem**: Given an unsorted array of integers, find the number of longest increasing subsequences.

1. **State**: `dp[i]` represents the length of the longest increasing subsequence ending at index `i`.
2. **Transition**: For each `j < i`, if `nums[j] < nums[i]`, update `dp[i] = max(dp[i], dp[j] + 1)`.
3. **Base Case**: `dp[i] = 1` for all `i` (each element can be a subsequence of length 1).
4. **Final Subproblem**: Count the number of subsequences that have the maximum length.

## Example 52: Profitable Schemes

**Problem**: Given a list of crimes, each with a profit and a group size, find the number of ways to commit at least a certain profit with a given number of people.

1. **State**: `dp[i][j]` represents the number of ways to achieve `j` profit with `i` people.
2. **Transition**: For each crime, update the number of ways by considering committing or not committing the crime.
3. **Base Case**: `dp[0][0] = 1` (one way to achieve zero profit with zero people).
4. **Final Subproblem**: Count the number of ways to achieve at least the given profit.
