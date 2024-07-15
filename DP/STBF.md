# Dynamic Programming

## Example 1: Fibonacci Sequence

### Problem

Given an integer `n`, find the nth Fibonacci number.

### State

`F(n)` represents the nth Fibonacci number.

### Transition

\[ F(n) = F(n-1) + F(n-2) \]

### Base Case

\[ F(0) = 0, \quad F(1) = 1 \]

### Final Subproblem

Calculate \(F(n)\).

---

## Example 2: Coin Change Problem

### Problem

Given coins of different denominations and a total amount, find the minimum number of coins needed to make up that amount.

### State

`dp[i]` represents the minimum number of coins needed to make amount `i`.

### Transition

\[ dp[i] = \min(dp[i], dp[i - c] + 1) \]

### Base Case

\[ dp[0] = 1 \quad (\text{0 coins are needed to make up amount 0}) \]

### Final Subproblem

`dp[amount]` gives the minimum number of coins needed for the given amount.

---

## Example 3: Longest Increasing Subsequence

### Problem

Find the length of the longest subsequence such that all elements of the subsequence are sorted in increasing order.

### State

`dp[i]` represents the length of the longest increasing subsequence ending at index `i`.

### Transition

\[ dp[i] = \max(dp[i], dp[j] + 1) \quad \text{if } arr[i] > arr[j] \]

### Base Case

\[ dp[i] = 1 \quad (\text{each element is a subsequence of length 1 by itself}) \]

### Final Subproblem

The length of the longest increasing subsequence is the maximum value in `dp`.

---

## Example 4: 0/1 Knapsack Problem

### Problem

Given a set of items, each with a weight and a value, determine the maximum value that can be obtained by selecting items such that the total weight does not exceed the given capacity.

### State

`dp[i][w]` represents the maximum value that can be obtained using the first `i` items with a total weight `w`.

### Transition

\[ dp[i][w] = \max(dp[i-1][w], dp[i-1]w - weight[i-1]] + value[i-1]) \]

### Base Case

\[ dp[0][w] = 0 \]
\[ dp[i][0] = 0 \]

### Final Subproblem

`dp[n][W]` gives the maximum value for `n` items and capacity `W`.

---

## Example 5: Edit Distance (Levenshtein Distance)

### Problem

Given two strings, find the minimum number of operations (insertions, deletions, substitutions) required to convert one string into the other.

### State

`dp[i][j]` represents the minimum number of operations required to convert the first `i` characters of string `s1` to the first `j` characters of string `s2`.

### Transition

\[ dp[i][j] = \min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + 1 \quad \text{if } s1[i-1] \neq s2[j-1] \]
\[ dp[i][j] = dp[i-1][j-1] \quad \text{if } s1[i-1] == s2[j-1] \]

### Base Case

\[ dp[i][0] = i \]
\[ dp[0][j] = j \]

### Final Subproblem

`dp[m][n]` gives the edit distance between strings `s1` of length `m` and `s2` of length `n`.

---

## Example 6: Maximum Subarray Sum (Kadane's Algorithm)

### Problem

Find the maximum sum of a contiguous subarray within a given one-dimensional array of numbers.

### State

`dp[i]` represents the maximum subarray sum ending at index `i`.

### Transition

\[ dp[i] = \max(arr[i], dp[i-1] + arr[i]) \]

### Base Case

\[ dp[0] = arr[0] \]

### Final Subproblem

The maximum subarray sum is the maximum value in the `dp` array.

---

## Example 7: Longest Common Subsequence (LCS)

### Problem

Given two sequences, find the length of their longest common subsequence.

### State

`dp[i][j]` represents the length of the longest common subsequence of the first `i` characters of `s1` and the first `j` characters of `s2`.

### Transition

\[ dp[i][j] = dp[i-1][j-1] + 1 \quad \text{if } s1[i-1] == s2[j-1] \]
\[ dp[i][j] = \max(dp[i-1][j], dp[i][j-1]) \quad \text{if } s1[i-1] \neq s2[j-1] \]

### Base Case

\[ dp[0][j] = 0 \]
\[ dp[i][0] = 0 \]

### Final Subproblem

`dp[m][n]` gives the length of the LCS of `s1` of length `m` and `s2` of length `n`.

---

## Example 8: Minimum Path Sum in a Grid

### Problem

Given a `m x n` grid filled with non-negative numbers, find a path from the top left to the bottom right which minimizes the sum of all numbers along its path.

### State

`dp[i][j]` represents the minimum path sum to reach cell `(i, j)`.

### Transition

\[ dp[i][j] = grid[i][j] + \min(dp[i-1][j], dp[i][j-1]) \]

### Base Case

\[ dp[0][0] = grid[0][0] \]
\[ dp[i][0] = dp[i-1][0] + grid[i][0] \]
\[ dp[0][j] = dp[0][j-1] + grid[0][j] \]

### Final Subproblem

`dp[m-1][n-1]` gives the minimum path sum to reach the bottom right corner.

---

## Example 9: House Robber Problem

### Problem

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police (i.e., you cannot rob two adjacent houses).

### State

`dp[i]` represents the maximum amount of money that can be robbed from the first `i` houses.

### Transition

\[ dp[i] = \max(dp[i-1], dp[i-2] + nums[i]) \]

### Base Case

\[ dp[0] = nums[0] \]
\[ dp[1] = \max(nums[0], nums[1]) \]

### Final Subproblem

The maximum amount of money that can be robbed from all houses is `dp[n-1]`.

---

## Example 10: Climbing Stairs

### Problem

You are climbing a staircase. It takes `n` steps to reach the top. Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

### State

`dp[i]` represents the number of distinct ways to reach the \(i\)-th step.

### Transition

\[ dp[i] = dp[i-1] + dp[i-2] \]

### Base Case

\[ dp[0] = 1 \]
\[ dp[1] = 1 \]

### Final Subproblem

`dp[n]` gives the number of distinct ways to reach the top.

---

## Example 11: Longest Palindromic Subsequence

### Problem

Given a string, find the length of the longest subsequence which is a palindrome.

### State

`dp[i][j]` represents the length of the longest palindromic subsequence in the substring `s[i...j]`.

### Transition

\[ dp[i][j] = dp[i+1][j-1] + 2 \quad \text{if } s[i] == s[j] \]
\[ dp[i][j] = \max(dp[i+1][j], dp[i][j-1]) \quad \text{if } s[i] \neq s[j] \]

### Base Case

\[ dp[i][i] = 1 \]

### Final Subproblem

`dp[0][n-1]` gives the length of the longest palindromic subsequence in the string `s`.

---

## Example 12: Matrix Chain Multiplication

### Problem

Given a sequence of matrices, find the most efficient way to multiply these matrices together. The problem is not actually to perform the multiplications but merely to decide in which order to perform the multiplications.

### State

`dp[i][j]` represents the minimum number of scalar multiplications needed to compute the matrix `M[i...j]`.

### Transition

\[ dp[i][j] = \min\_{i \leq k < j} (dp[i][k] + dp[k+1][j] + cost_of_multiplication(M[i...k], M[k+1...j])) \]

### Base Case

\[ dp[i][i] = 0 \]

### Final Subproblem

`dp[1][n-1]` gives the minimum number of multiplications needed to multiply matrices from 1 to `n`.

---

## Example 13: Partition Equal Subset Sum

### Problem

Given a set of positive integers, determine if it can be partitioned into two subsets with equal sum.

### State

`dp[i][j]` represents whether a sum `j` can be achieved using the first `i` numbers.

### Transition

\[ dp[i][j] = dp[i-1][j] \quad \text{or} \quad dp[i-1]j - nums[i-1]] \]

### Base Case

\[ dp[i][0] = true \]
\[ dp[0][j] = false \quad \text{for } j > 0 \]

### Final Subproblem

Determine if `dp[n][target]` is `true`, where `target` is half the sum of the set (only if the sum is even).

---

## Example 14: Wildcard Matching

### Problem

Given an input string `s` and a pattern `p`, implement wildcard pattern matching with support for '?' and '_'. The '?' matches any single character, and '_' matches any sequence of characters (including the empty sequence).

### State

`dp[i][j]` represents whether the first `i` characters in the string `s` match the first `j` characters of the pattern `p`.

### Transition

\[ dp[i][j] = dp[i-1][j-1] \quad \text{if } s[i-1] == p[j-1] \text{ or } p[j-1] == '?' \]
\[ dp[i][j] = dp[i][j-1] \quad \text{or} \quad dp[i-1][j] \quad \text{if } p[j-1] == 'star' \]

### Base Case

\[ dp[0][0] = true \]
\[ dp[i][0] = false \quad \text{for } i > 0 \]
\[ dp[0][j] = dp[0][j-1] \quad \text{if } p[j-1] == 'star' \]

### Final Subproblem

`dp[m][n]` gives whether the entire string `s` matches the pattern `p`.

---

## Example 15: Word Break Problem

### Problem

Given a string `s` and a dictionary of words `dict`, determine if `s` can be segmented into a space-separated sequence of one or more dictionary words.

### State

`dp[i]` represents whether the substring `s[0...i-1]` can be segmented into dictionary words.

### Transition

\[ dp[i] = dp[j] \quad \text{if } s[j...i-1] \in dict \]

### Base Case

\[ dp[0] = true \]

### Final Subproblem

`dp[n]` gives whether the entire string `s` can be segmented using dictionary words.

---

## Example 16: Minimum Cost to Paint Houses

### Problem

There are `n` houses in a row. Each house can be painted with one of three colors. You have to paint all the houses such that no two adjacent houses have the same color. The cost of painting each house with a certain color is different. Find the minimum cost to paint all houses.

### State

`dp[i][c]` represents the minimum cost to paint house `i` with color `c`.

### Transition

\[ dp[i][0] = cost[i][0] + \min(dp[i-1][1], dp[i-1][2]) \]
\[ dp[i][1] = cost[i][1] + \min(dp[i-1][0], dp[i-1][2]) \]
\[ dp[i][2] = cost[i][2] + \min(dp[i-1][0], dp[i-1][1]) \]

### Base Case

\[ dp[0][0] = cost[0][0] \]
\[ dp[0][1] = cost[0][1] \]
\[ dp[0][2] = cost[0][2] \]

### Final Subproblem

The minimum cost to paint all houses is:
\[ \min(dp[n-1][0], dp[n-1][1], dp[n-1][2]) \]

---

## Example 17: Palindrome Partitioning II

### Problem

Given a string `s`, partition `s` such that every substring of the partition is a palindrome. Return the minimum cuts needed for a palindrome partitioning of `s`.

### State

`dp[i]` represents the minimum number of cuts needed for a palindrome partitioning of the substring `s[0...i]`.

### Transition

\[ dp[i] = 0 \quad \text{if } s[0...i] \text{ is a palindrome} \]
\[ dp[i] = \min(dp[i], dp[j-1] + 1) \quad \text{if } s[j...i] \text{ is a palindrome} \]

### Base Case

\[ dp[i] = 0 \quad \text{if } s[0...i] \text{ is a palindrome} \]

### Final Subproblem

`dp[n-1]` gives the minimum number of cuts needed for the entire string `s`.

---

## Example 18: Maximum Profit in Job Scheduling

### Problem

Given `n` jobs, each represented by start time, end time, and profit, find the maximum profit you can achieve by scheduling non-overlapping jobs.

### State

`dp[i]` represents the maximum profit that can be obtained by considering the first `i` jobs.

### Transition

\[ dp[i] = \max(dp[i-1], profit[i] + dp[last\_non\_conflicting\_job]) \]

### Base Case

\[ dp[0] = profit[0] \]

### Final Subproblem

`dp[n-1]` gives the maximum profit for all jobs.

---

## Example 19: Russian Doll Envelopes

### Problem

You have a number of envelopes with width and height given as a pair of integers `(w, h)`. One envelope can fit into another if both the width and height of one envelope are greater than the width and height of the other envelope. Find the maximum number of envelopes you can put one inside the other.

### State

`dp[i]` represents the maximum number of envelopes ending with envelope `i`.

### Transition

\[ dp[i] = \max(dp[i], dp[j] + 1) \quad \text{if } width[i] > width[j] \text{ and } height[i] > height[j] \]

### Base Case

\[ dp[i] = 1 \]

### Final Subproblem

The maximum number of envelopes is the maximum value in `dp`.

---

## Example 20: Super Egg Drop

### Problem

You are given `K` eggs and you have access to a building with `N` floors. Your goal is to find the minimum number of attempts you need to determine the highest floor from which an egg can be dropped without breaking.

### State

`dp[K][N]` represents the minimum number of attempts needed with `K` eggs and `N` floors.

### Transition

\[ dp[K][N] = 1 + \min\_{1 \leq i \leq N} \max(dp[K-1][i-1], dp[K][N-i]) \]

### Base Case

\[ dp[1][N] = N \]
\[ dp[K][0] = 0 \]

### Final Subproblem

`dp[K][N]` gives the minimum number of attempts needed with `K` eggs and `N` floors.

---

## Example 21: Burst Balloons

### Problem

You are given `n` balloons, each with a number on it. You burst the balloons to maximize the total coins you get. The number of coins you get when you burst balloon `i` is `nums[i-1] * nums[i] * nums[i+1]`. If `i-1` or `i+1` goes out of bounds, assume the value is 1.

### State

`dp[i][j]` represents the maximum coins that can be obtained by bursting balloons between `i` and `j` (excluding `i` and `j`).

### Transition

\[ dp[i][j] = \max(dp[i][j], dp[i][k] + dp[k][j] + nums[i-1] _ nums[k] _ nums[j+1]) \]

### Base Case

\[ dp[i][i+1] = 0 \]

### Final Subproblem

`dp[0][n-1]` gives the maximum coins for bursting all balloons.

---

## Example 22: Unique Paths

### Problem

You are given a grid with `m` rows and `n` columns. You start at the top-left corner and need to reach the bottom-right corner. You can only move down or right. How many unique paths are there?

### State

`dp[i][j]` represents the number of unique paths to reach cell `(i, j)`.

### Transition

\[ dp[i][j] = dp[i-1][j] + dp[i][j-1] \]

### Base Case

\[ dp[0][0] = 1 \]
\[ dp[i][0] = 1 \]
\[ dp[0][j] = 1 \]

### Final Subproblem

`dp[m-1][n-1]` gives the number of unique paths to the bottom-right corner.

---

## Example 23: Longest Palindromic Substring

### Problem

Given a string `s`, find the longest substring that is a palindrome.

### State

`dp[i][j]` represents whether the substring `s[i...j]` is a palindrome.

### Transition

\[ dp[i][j] = (s[i] == s[j]) \text{ and } (j - i < 3 \text{ or } dp[i+1][j-1]) \]

### Base Case

\[ dp[i][i] = true \]

### Final Subproblem

Find the maximum length substring for which `dp[i][j]` is `true`.

---

## Example 24: Coin Change 2

### Problem

You are given coins of different denominations and a total amount of money. Find the number of ways to make up that amount using the coins. You can use each coin as many times as you want.

### State

`dp[i]` represents the number of ways to make up amount `i`.

### Transition

\[ dp[i] = dp[i] + dp[i - c] \]

### Base Case

\[ dp[0] = 1 \]

### Final Subproblem

`dp[amount]` gives the number of ways to make up the given amount.

---

## Example 25: Minimum Path Sum

### Problem

Given a `m x n` grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

### State

`dp[i][j]` represents the minimum path sum to reach cell `(i, j)`.

### Transition

\[ dp[i][j] = grid[i][j] + \min(dp[i-1][j], dp[i][j-1]) \]

### Base Case

\[ dp[0][0] = grid[0][0] \]
\[ dp[i][0] = dp[i-1][0] + grid[i][0] \]
\[ dp[0][j] = dp[0][j-1] + grid[0][j] \]

### Final Subproblem

`dp[m-1][n-1]` gives the minimum path sum to the bottom-right corner.

---

## Example 26: Subset Sum

### Problem

Given a set of positive integers and a value `sum`, determine if there is a subset of the given set with sum equal to `sum`.

### State

`dp[i][j]` represents whether a subset of the first `i` elements has a sum equal to `j`.

### Transition

\[ dp[i][j] = dp[i-1][j] \quad \text{or} \quad dp[i-1]j - nums[i-1]] \]

### Base Case

\[ dp[i][0] = true \]
\[ dp[0][j] = false \quad \text{for } j > 0 \]

### Final Subproblem

Determine if `dp[n][sum]` is `true`.

---

## Example 27: Maximum Product Subarray

### Problem

Given an integer array `nums`, find the contiguous subarray within an array (containing at least one number) which has the largest product.

### State

`dp_max[i]` and `dp_min[i]` represent the maximum and minimum product subarray ending at index `i`.

### Transition

\[ dp*max[i] = \max(nums[i], nums[i] * dp*max[i-1], nums[i] * dp*min[i-1]) \]
\[ dp_min[i] = \min(nums[i], nums[i] * dp*max[i-1], nums[i] * dp_min[i-1]) \]

### Base Case

\[ dp_max[0] = dp_min[0] = nums[0] \]

### Final Subproblem

The maximum product subarray is the maximum value in `dp_max`.

---

## Example 28: Regular Expression Matching

### Problem

Given an input string `s` and a pattern `p`, implement regular expression matching with support for `.` and `*`. `.` matches any single character, and `*` matches zero or more of the preceding element.

### State

`dp[i][j]` represents whether the first `i` characters in the string `s` match the first `j` characters of the pattern `p`.

### Transition

\[ dp[i][j] = dp[i-1][j-1] \quad \text{if } s[i-1] == p[j-1] \text{ or } p[j-1] == '.' \]
\[ dp[i][j] = dp[i][j-2] \quad \text{or} \quad dp[i-1][j] \quad \text{if } p[j-2] \text{ matches } s[i-1] \text{ or } p[j-2] == '.' \]

### Base Case

\[ dp[0][0] = true \]

### Final Subproblem

`dp[m][n]` gives whether the entire string `s` matches the pattern `p`.

---

## Example 29: Interleaving String

### Problem

Given strings `s1`, `s2`, and `s3`, find whether `s3` is formed by an interleaving of `s1` and `s2`.

### State

`dp[i][j]` represents whether `s3[0...i+j-1]` is an interleaving of `s1[0...i-1]` and `s2[0...j-1]`.

### Transition

\[ dp[i][j] = dp[i-1][j] \quad \text{if } s1[i-1] == s3[i+j-1] \]
\[ dp[i][j] = dp[i][j-1] \quad \text{if } s2[j-1] == s3[i+j-1] \]

### Base Case

\[ dp[0][0] = true \]

### Final Subproblem

`dp[m][n]` gives whether `s3` is an interleaving of `s1` and `s2`.

---

## Example 30: Scramble String

### Problem

Given a string `s1`, we may represent it as a binary tree by partitioning it into two non-empty substrings recursively. A string `s2` is a scramble of `s1` if we can swap the children of some nodes in the tree of `s1` to get `s2`. Given two strings `s1` and `s2`, determine if `s2` is a scramble of `s1`.

### State

`dp[i][j][k]` represents whether the substring `s1[i...i+k-1]` is a scramble of `s2[j...j+k-1]`.

### Transition

\[ dp[i][j][k] = (dp[i][j][l] \text{ and } dp[i+l][j+l][k-l]) \quad \text{or} \quad (dp[i][j+k-l][l] \text{ and } dp[i+l][j][k-l]) \]

### Base Case

\[ dp[i][j][1] = (s1[i] == s2[j]) \]

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
