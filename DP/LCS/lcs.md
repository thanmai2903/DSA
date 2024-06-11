# Longest Common Subsequence (LCS) and Its Variants

## 1. Introduction to Longest Common Subsequence (LCS)

The LCS problem is defined as follows:
Given two sequences, find the length of the longest subsequence present in both of them. A subsequence is a sequence that appears in the same relative order, but not necessarily consecutively.

### Example:

-   Sequence 1: `ABCBDAB`
-   Sequence 2: `BDCAB`

The LCS is `BDAB` with length 4.

## 2. Basic Dynamic Programming Approach

The dynamic programming (DP) approach involves creating a 2D table where `dp[i][j]` represents the length of the LCS of the first `i` characters of `text1` and the first `j` characters of `text2`.

### Algorithm:

1. Initialize a 2D DP array with dimensions `(m+1) x (n+1)` where `m` and `n` are lengths of the two sequences.
2. Iterate through each character of both strings.
3. If characters match, add 1 to the result from the previous indices.
4. If characters don't match, take the maximum value from the previous indices (either `i-1` or `j-1`).

### C++ Code:

```cpp
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int longestCommonSubsequence(string text1, string text2) {
    int m = text1.length();
    int n = text2.length();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (text1[i - 1] == text2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[m][n];
}

int main() {
    string text1 = "ABCBDAB";
    string text2 = "BDCAB";
    cout << "Length of LCS: " << longestCommonSubsequence(text1, text2) << endl;
    return 0;
}
```

## 3. Space Optimization

The above approach uses O(m \* n) space. We can reduce this to O(min(m, n)) by using two 1D arrays instead of a 2D array.

```cpp
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int longestCommonSubsequence(string text1, string text2) {
    if (text1.length() < text2.length()) {
        swap(text1, text2);
    }

    int m = text1.length();
    int n = text2.length();
    vector<int> previous(n + 1, 0);
    vector<int> current(n + 1, 0);

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (text1[i - 1] == text2[j - 1]) {
                current[j] = previous[j - 1] + 1;
            } else {
                current[j] = max(previous[j], current[j - 1]);
            }
        }
        swap(previous, current);
    }

    return previous[n];
}

int main() {
    string text1 = "ABCBDAB";
    string text2 = "BDCAB";
    cout << "Length of LCS: " << longestCommonSubsequence(text1, text2) << endl;
    return 0;
}
```

## 4. Variants of LCS

### a. Printing the LCS

To print the LCS, we need to keep track of the choices made while filling the DP table.

### C++ Code:

```cpp
#include <iostream>
#include <vector>
#include <string>
using namespace std;

string getLCS(string text1, string text2) {
    int m = text1.length();
    int n = text2.length();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (text1[i - 1] == text2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    // Backtrack to find the LCS
    int i = m, j = n;
    string lcs = "";

    while (i > 0 && j > 0) {
        if (text1[i - 1] == text2[j - 1]) {
            lcs += text1[i - 1];
            --i; --j;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            --i;
        } else {
            --j;
        }
    }

    reverse(lcs.begin(), lcs.end());
    return lcs;
}

int main() {
    string text1 = "ABCBDAB";
    string text2 = "BDCAB";
    cout << "LCS: " << getLCS(text1, text2) << endl;
    return 0;
}
```

## 5. LCS Variants Problems

### a. Longest Palindromic Subsequence

This can be solved by finding the LCS of the string and its reverse.

### C++ Code:

```cpp
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int longestCommonSubsequence(string text1, string text2) {
    int m = text1.length();
    int n = text2.length();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (text1[i - 1] == text2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[m][n];
}

int longestPalindromicSubsequence(string s) {
    string rev = s;
    reverse(rev.begin(), rev.end());
    return longestCommonSubsequence(s, rev);
}

int main() {
    string s = "BBABCBCAB";
    cout << "Length of Longest Palindromic Subsequence: " << longestPalindromicSubsequence(s) << endl;
    return 0;
}
```

### b. Shortest Common Supersequence

The shortest common supersequence (SCS) of two strings is the shortest string that has both strings as subsequences.

### C++ code:

```cpp
  #include <iostream>
#include <vector>
#include <string>
using namespace std;

int longestCommonSubsequence(string text1, string text2) {
    int m = text1.length();
    int n = text2.length();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (text1[i - 1] == text2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[m][n];
}

string shortestCommonSupersequence(string text1, string text2) {
    int m = text1.length();
    int n = text2.length();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (text1[i - 1] == text2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    int i = m, j = n;
    string scs = "";

    while (i > 0 && j > 0) {
        if (text1[i - 1] == text2[j - 1]) {
            scs += text1[i - 1];
            --i; --j;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            scs += text1[i - 1];
            --i;
        } else {
            scs += text2[j - 1];
            --j;
        }
    }

    while (i > 0) {
        scs += text1[i - 1];
        --i;
    }

    while (j > 0) {
        scs += text2[j - 1];
        --j;
    }

    reverse(scs.begin(), scs.end());
    return scs;
}

int main() {
    string text1 = "ABCBDAB";
    string text2 = "BDCAB";
    cout << "Shortest Common Supersequence: " << shortestCommonSupersequence(text1, text2) << endl;
    return 0;
}
```

## 6. Conclusion

The LCS problem is a fundamental problem in computer science with many applications and variants. By understanding the basic dynamic programming approach, you can tackle various related problems such as the Longest Palindromic Subsequence and Shortest Common Supersequence. Optimizations can be applied to improve space complexity, and by modifying the basic approach slightly, you can solve different LCS-related problems.
