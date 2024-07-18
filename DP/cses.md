# Dynamic Programming Problems

## Problem 1: Dice Combinations

**Problem**: Given a value `n`, find the number of ways to get the sum `n` using any number of dice rolls (each die roll can be from 1 to 6).

-   **State**: `dp[i]` represents the number of ways to get the sum `i`.
-   **Transition**: For each roll value from 1 to 6:
    $$
    dp[i] = dp[i-1] + dp[i-2] + dp[i-3] + dp[i-4] + dp[i-5] + dp[i-6]
    $$
    $$
-   **Base Case**:
    $$
    dp[0] = 1 \quad \text{(one way to get sum 0 - by not rolling)}
    $$
    $$
-   **Final Subproblem**: `dp[n]` gives the number of ways to get the sum `n`.

## Problem 2: Minimizing Coins

**Problem**: Given a list of coin denominations and a target sum `x`, find the minimum number of coins required to make the sum `x`.

-   **State**: `dp[i]` represents the minimum number of coins needed to make sum `i`.
-   **Transition**: For each coin `c`:
    $$
    dp[i] = \min(dp[i], dp[i-c] + 1)
    $$
    $$
-   **Base Case**:
    $$
    dp[0] = 0 \quad \text{(zero coins are needed to make sum 0)}
    $$
    $$
-   **Final Subproblem**: `dp[x]` gives the minimum number of coins to make sum `x`.

## Problem 3: Coin Combinations I

**Problem**: Given a list of coin denominations and a target sum `x`, find the number of ways to make the sum `x` using the coins.

-   **State**: `dp[i]` represents the number of ways to make the sum `i`.
-   **Transition**: For each coin `c`:
    $$
    dp[i] += dp[i-c]
    $$
    $$
-   **Base Case**:
    $$
    dp[0] = 1 \quad \text{(one way to make sum 0 - by not using any coins)}
    $$
    $$
-   **Final Subproblem**: `dp[x]` gives the number of ways to make the sum `x`.

## Problem 4: Coin Combinations II

**Problem**: Given a list of coin denominations and a target sum `x`, find the number of ways to make the sum `x` using each coin at most once.

-   **State**: `dp[i]` represents the number of ways to make the sum `i`.
-   **Transition**: For each coin `c` (iterate through coins first to ensure each coin is used at most once):
    $$
    dp[i] += dp[i-c]
    $$
    $$
-   **Base Case**:
    $$
    dp[0] = 1 \quad \text{(one way to make sum 0 - by not using any coins)}
    $$
    $$
-   **Final Subproblem**: `dp[x]` gives the number of ways to make the sum `x`.

## Problem 5: Removing Digits

**Problem**: Given an integer `n`, find the minimum number of steps to reduce it to zero. In each step, you can subtract any one of the digits of `n` from `n`.

-   **State**: `dp[i]` represents the minimum number of steps to reduce `i` to zero.
-   **Transition**: For each digit `d` of `i`:
    $$
    dp[i] = \min(dp[i], dp[i-d] + 1)
    $$
    $$
-   **Base Case**:
    $$
    dp[0] = 0 \quad \text{(zero steps needed to reduce 0 to zero)}
    $$
    $$
-   **Final Subproblem**: `dp[n]` gives the minimum number of steps to reduce `n` to zero.

## Problem 6: Grid Paths

**Problem**: Given an `n x n` grid, find the number of ways to move from the top-left corner to the bottom-right corner. You can only move right or down and some cells may be blocked.

-   **State**: `dp[i][j]` represents the number of ways to reach cell `(i, j)`.
-   **Transition**: If the cell `(i, j)` is not blocked:
    $$
    dp[i][j] = dp[i-1][j] + dp[i][j-1]
    $$
    $$
-   **Base Case**:
    $$
    dp[0][0] = 1 \quad \text{(one way to start at the top-left corner)}
    $$
    $$
-   **Final Subproblem**: `dp[n-1][n-1]` gives the number of ways to reach the bottom-right corner.

## Problem 7: Book Shop

**Problem**: You have `n` books and a budget of `x`. Each book has a price and a value. Maximize the total value of books you can buy without exceeding the budget.

-   **State**: `dp[i][j]` represents the maximum value of books you can buy from the first `i` books with a budget of `j`.
-   **Transition**: For each book `i`:
    $$
    dp[i][j] = \max(dp[i-1][j], dp[i-1]j-price[i]] + value[i]) \quad \text{if } j \geq price[i]
    $$
    $$
-   **Base Case**:
    $$
    dp[0][j] = 0 \quad \text{(zero books have zero value)}
    $$
    $$
-   **Final Subproblem**: `dp[n][x]` gives the maximum value of books you can buy with the budget `x`.

## Problem 8: Array Description

**Problem**: Given an array of length `n` where some elements are fixed and others can be any value from 1 to `m`, count the number of ways to fill the array such that the absolute difference between adjacent elements is at most 1.

-   **State**: `dp[i][j]` represents the number of ways to fill the first `i` elements with the `i`-th element being `j`.
-   **Transition**: For each possible value `j` of the `i`-th element:
    $$
    dp[i][j] = dp[i-1][j-1] + dp[i-1][j] + dp[i-1][j+1]
    $$
    $$
-   **Base Case**:
    $$
    dp[0][j] = 1 \quad \text{if the first element is } j
    $$
    $$
-   **Final Subproblem**: Sum `dp[n-1][j]` for all possible `j`.

## Problem 9: Counting Towers

**Problem**: Count the number of ways to build a tower of height `n` using 1x2 and 2x1 tiles.

-   **State**: `dp[n]` represents the number of ways to build a tower of height `n`.
-   **Transition**: For each height `i`:
    $$
    dp[i] = dp[i-1] + dp[i-2]
    $$
    $$
-   **Base Case**:
    $$
    dp[0] = 1, \quad dp[1] = 1
    $$
    $$
-   **Final Subproblem**: `dp[n]` gives the number of ways to build a tower of height `n`.

## Problem 10: Edit Distance

**Problem**: Given two strings, find the minimum number of operations (insertions, deletions, substitutions) required to convert one string into the other.

-   **State**: `dp[i][j]` represents the minimum number of operations required to convert the first `i` characters of `s1` to the first `j` characters of `s2`.
-   **Transition**:
    -   If `s1[i-1] == s2[j-1]`, then no new operation is needed: `dp[i][j] = dp[i-1][j-1]`.
    -   If `s1[i-1] != s2[j-1]`, consider the minimum operations among insertion, deletion, and substitution:
        $$
        dp[i][j] = 1 + \min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1])
        $$
        $$
-   **Base Case**:
    $$
    dp[i][0] = i \quad \text{(i deletions)}, \quad dp[0][j] = j \quad \text{(j insertions)}
    $$
    $$
-   **Final Subproblem**: `dp[m][n]` gives the minimum edit distance between `s1` and `s2`.

## Problem 11: Rectangle Cutting

**Problem**: Given a rectangle of dimensions `a x b`, find the minimum number of cuts needed to cut it into squares.

-   **State**: `dp[a][b]` represents the minimum number of cuts needed to cut a rectangle of dimensions `a x b` into squares.
-   **Transition**: For each possible horizontal and vertical cut, calculate the minimum cuts:
    $$
    dp[a][b] = \min(dp[a][b], dp[i][b] + dp[a-i][b] + 1 \quad \text{for } 1 \leq i < a)
    $$
    $$
    dp[a][b] = \min(dp[a][b], dp[a][j] + dp[a][b-j] + 1 \quad \text{for } 1 \leq j < b)
    $$
-   **Base Case**:
    $$
    dp[i][i] = 0 \quad \text{(a square needs no cuts)}
    $$
    $$
-   **Final Subproblem**: `dp[a][b]` gives the minimum cuts for a rectangle of dimensions `a x b`.

## Problem 12: Two Sets II

**Problem**: Given an integer `n`, find the number of ways to partition the set `{1, 2, ..., n}` into two subsets of equal sum.

-   **State**: `dp[i][j]` represents the number of ways to form sum `j` using the first `i` natural numbers.
-   **Transition**: For each number `i`, either include it in the subset or exclude it:
    $$
    dp[i][j] = dp[i-1][j] + dp[i-1][j-i] \quad \text{if } j \geq i
    $$
    $$
-   **Base Case**:
    $$
    dp[0][0] = 1 \quad \text{(one way to partition an empty set)}
    $$
    $$
-   **Final Subproblem**: `dp[n][\text{sum/2}]` gives the number of ways to partition the set if `sum` is even.

## Problem 13: Increasing Subsequence

**Problem**: Given an array, find the length of the longest increasing subsequence.

-   **State**: `dp[i]` represents the length of the longest increasing subsequence ending at index `i`.
-   **Transition**: For each `j < i`, if `arr[j] < arr[i]`, then update:
    $$
    dp[i] = \max(dp[i], dp[j] + 1)
    $$
    $$
-   **Base Case**:
    $$
    dp[i] = 1 \quad \text{(each element is a subsequence of length 1 by itself)}
    $$
    $$
-   **Final Subproblem**: The length of the longest increasing subsequence is the maximum value in `dp`.

## Problem 14: Array Partition

**Problem**: Given an array, partition it into two subsets such that the difference of their sums is minimized.

-   **State**: `dp[i]` represents whether a sum `i` can be achieved using the elements.
-   **Transition**: For each element `num`:
    $$
    dp[i] = dp[i] \text{ or } dp[i-num] \quad \text{if } i \geq num
    $$
    $$
-   **Base Case**:
    $$
    dp[0] = true \quad \text{(a sum of 0 is always possible)}
    $$
    $$
-   **Final Subproblem**: Find the minimum difference between the two subsets.

## Problem 15: Counting Bits

**Problem**: Given an integer `n`, return the number of bits that are equal to `1` in the binary representation of numbers from `0` to `n`.

-   **State**: `dp[i]` represents the number of `1`s in the binary representation of `i`.
-   **Transition**: Use the relationship between `i` and `i//2`:
    $$
    dp[i] = dp[i // 2] + (i \% 2)
    $$
    $$
-   **Base Case**:
    $$
    dp[0] = 0
    $$
    $$
-   **Final Subproblem**: `dp[n]` gives the number of bits equal to `1`.

## Problem 16: Range Sum Queries

**Problem**: Given an array and multiple queries, each query asks for the sum of a subarray.

-   **State**: `dp[i]` represents the sum of the first `i` elements.
-   **Transition**: Precompute prefix sums:
    $$
    dp[i] = dp[i-1] + arr[i-1]
    $$
    $$
-   **Base Case**:
    $$
    dp[0] = 0
    $$
    $$
-   **Final Subproblem**: The sum of subarray `[l, r]` is `dp[r+1] - dp[l]`.

## Problem 17: Range Minimum Queries

**Problem**: Given an array and multiple queries, each query asks for the minimum value in a subarray.

-   **State**: `dp[i][j]` represents the minimum value in the subarray from index `i` to `j`.
-   **Transition**: For each possible range, update the minimum:
    $$
    dp[i][j] = \min(dp[i][j-1], arr[j])
    $$
    $$
-   **Base Case**:
    $$
    dp[i][i] = arr[i]
    $$
    $$
-   **Final Subproblem**: `dp[l][r]` gives the minimum value in the subarray `[l, r]`.

## Problem 18: Longest Palindromic Subsequence

**Problem**: Given a string, find the length of the longest subsequence which is a palindrome.

-   **State**: `dp[i][j]` represents the length of the longest palindromic subsequence in the substring `s[i...j]`.
-   **Transition**:
    -   If `s[i] == s[j]`, then `dp[i][j] = dp[i+1][j-1] + 2`.
    -   Otherwise, `dp[i][j] = \max(dp[i+1][j], dp[i][j-1])`.
-   **Base Case**:
    $$
    dp[i][i] = 1
    $$
    $$
-   **Final Subproblem**: `dp[0][n-1]` gives the length of the longest palindromic subsequence in `s`.

## Problem 19: Longest Palindromic Substring

**Problem**: Given a string `s`, find the longest palindromic substring in `s`.

-   **State**: `dp[i][j]` represents whether the substring `s[i...j]` is a palindrome.
-   **Transition**:
    -   If `s[i] == s[j]`, then `dp[i][j] = (j - i < 3) || dp[i+1][j-1]`.
-   **Base Case**:
    $$
    dp[i][i] = true
    $$
    $$
-   **Final Subproblem**: Find the longest substring for which `dp[i][j]` is true.

## Problem 20: Knapsack Problem

**Problem**: Given weights and values of `n` items, put these items in a knapsack of capacity `W` to get the maximum total value in the knapsack.

-   **State**: `dp[i][j]` represents the maximum value that can be obtained with the first `i` items and capacity `j`.
-   **Transition**: For each item `i` and weight `w`:
    $$
    dp[i][j] = \max(dp[i-1][j], dp[i-1][j-w] + v) \quad \text{if } j \geq w
    $$
    $$
-   **Base Case**:
    $$
    dp[0][j] = 0 \quad \text{for all } j
    $$
    $$
-   **Final Subproblem**: `dp[n][W]` gives the maximum value for capacity `W`.

## Problem 21: Subarray Divisibility

**Problem**: Given an array of integers, count the number of subarrays whose sum is divisible by `k`.

-   **State**: `dp[i][r]` represents the number of subarrays ending at index `i` with a remainder `r` when divided by `k`.
-   **Transition**: For each element, update the remainders based on the current sum:
    $$
    dp[i](r + arr[i]) \% k] += dp[i-1][r]
    $$
    $$
-   **Base Case**:
    $$
    dp[0][0] = 1 \quad \text{(one way to get sum 0)}
    $$
    $$
-   **Final Subproblem**: Sum `dp[i][0]` for all `i`.

## Problem 22: Longest Arithmetic Subsequence

**Problem**: Given an array of integers, find the length of the longest arithmetic subsequence.

-   **State**: `dp[i][d]` represents the length of the longest arithmetic subsequence ending at index `i` with common difference `d`.
-   **Transition**: For each `j < i`:
    $$
    dp[i][d] = \max(dp[i][d], dp[j][d] + 1) \quad \text{where } d = arr[i] - arr[j]
    $$
    $$
-   **Base Case**:
    $$
    dp[i][d] = 1 \quad \text{(each element can be a subsequence of length 1)}
    $$
    $$
-   **Final Subproblem**: The maximum value in `dp` array.

## Problem 23: Longest Zigzag Subsequence

**Problem**: Given an array of integers, find the length of the longest zigzag subsequence.

-   **State**: `dp[i][0]` represents the length of the longest zigzag subsequence ending at index `i` and decreasing, `dp[i][1]` represents it increasing.
-   **Transition**: For each `j < i`:
    $$
    dp[i][0] = \max(dp[i][0], dp[j][1] + 1) \quad \text{if } arr[i] < arr[j]
    $$
    $$
    dp[i][1] = \max(dp[i][1], dp[j][0] + 1) \quad \text{if } arr[i] > arr[j]
    $$
-   **Base Case**:
    $$
    dp[i][0] = dp[i][1] = 1 \quad \text{(each element can be a subsequence of length 1)}
    $$
    $$
-   **Final Subproblem**: The maximum value in `dp` array.

## Problem 24: Maximum Sum Increasing Subsequence

**Problem**: Given an array of integers, find the sum of the maximum sum increasing subsequence.

-   **State**: `dp[i]` represents the maximum sum of an increasing subsequence ending at index `i`.
-   **Transition**: For each `j < i`:
    $$
    dp[i] = \max(dp[i], dp[j] + arr[i]) \quad \text{if } arr[j] < arr[i]
    $$
    $$
-   **Base Case**:
    $$
    dp[i] = arr[i]
    $$
    $$
-   **Final Subproblem**: The maximum value in `dp` array.

## Problem 25: Matrix Chain Multiplication

**Problem**: Given a sequence of matrices, find the minimum number of scalar multiplications needed to compute the matrix product.

-   **State**: `dp[i][j]` represents the minimum number of multiplications needed to compute the product of matrices from `i` to `j`.
-   **Transition**: For each split point `k`:
    $$
    dp[i][j] = \min(dp[i][j], dp[i][k] + dp[k+1][j] + cost_of_multiplication(M[i...k], M[k+1...j]))
    $$
    $$
-   **Base Case**:
    $$
    dp[i][i] = 0
    $$
    $$
-   **Final Subproblem**: `dp[1][n]` gives the minimum number of multiplications for matrices from 1 to `n`.

## Problem 26: Painting Fence

**Problem**: Given `n` fences and `k` colors, find the number of ways to paint the fences such that no more than two adjacent fences have the same color.

-   **State**: `dp[i][0]` represents the number of ways to paint the first `i` fences with the `i`-th fence having a different color than the `(i-1)`-th, `dp[i][1]` represents it having the same color.
-   **Transition**:
    $$
    dp[i][0] = (dp[i-1][0] + dp[i-1][1]) \* (k-1)
    $$
    $$
    dp[i][1] = dp[i-1][0]
    $$
-   **Base Case**:
    $$
    dp[1][0] = k, \quad dp[1][1] = 0
    $$
    $$
-   **Final Subproblem**: The sum of `dp[n][0]` and `dp[n][1]`.

## Example 27: Boolean Parenthesization Problem

**Problem**: Given a boolean expression and a list of operators (`AND`, `OR`, `XOR`), find the number of ways to parenthesize the expression such that it evaluates to `True`.

1. **State**: `dp[i][j][isTrue]` represents the number of ways to parenthesize the subexpression from `i` to `j` such that it evaluates to `isTrue`.
2. **Transition**: For each operator `op` between `i` and `j`:
    $$
    dp[i][j][isTrue] = \sum \text{ (count of ways considering the operator and its effect on True/False evaluation)}
    $$
    $$
3. **Base Case**:
    $$
    dp[i][i][isTrue] = 1 \quad \text{if the single operand evaluates to isTrue}
    $$
    $$
4. **Final Subproblem**: `dp[0][n-1][True]` gives the number of ways to parenthesize the entire expression to evaluate to `True`.

## Example 28: Optimal Binary Search Tree

**Problem**: Given `n` keys and probabilities of searching for each key, construct a binary search tree with the minimum expected search cost.

1. **State**: `dp[i][j]` represents the minimum cost of a binary search tree containing keys from `i` to `j`.
2. **Transition**: For each key `k` as root:
    $$
    dp[i][j] = \min(dp[i][j], dp[i][k-1] + dp[k+1][j] + \text{sum of probabilities from } i \text{ to } j)
    $$
    $$
3. **Base Case**:
    $$
    dp[i][i] = \text{probability of } i
    $$
    $$
4. **Final Subproblem**: `dp[1][n]` gives the minimum cost of the optimal binary search tree for keys from 1 to `n`.
