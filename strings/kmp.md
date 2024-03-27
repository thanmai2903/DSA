# Knuth-Morris-Pratt KMP String Matching Algorithm

-   KMP algorithm is for pattern matching
-   The Knuth-Morris-Pratt (KMP) algorithm involves shifting patterns to the right by one step when there is a mismatch.
-   KMP String Matching Algorithm uses pattern comparison.
-   KMP algorithm reduces time complexity of string matching
-   KMP algorithm improves pattern matching efficiency
-   KMP algorithm Time complexity will be O(m+n) where naive way is O(mn)
-   Longest prefix suffix table -> lps table

### IN LPS Table, How do the iterators move?

1. If there is a match, increment both i and j.
2. If there is a mismatch after a match, place j at LPS[pattern[j - 1]] and compare again.
3. If j = 0, and there is a mismatch, increment i.

### Pseudo Code for LPS

```cpp
LPS ← array [size = pattern length]
LPS[0] ← 0  {LPS value of the first element is always 0}
len ← 0  {length of previous longest proper prefix that is also a suffix}
i ← 1
m ← length of pattern
while i < m do
    if pattern[i] is equal to pattern[len] then
        len ← len + 1
        LPS[i] ← len
        i ← i + 1
    else  {pattern[i] is not equal to pattern[len]}
        if len is not equal to 0 then
            len ← LPS[len - 1]
        else  {if len is 0}
            LPS[i] ← 0
            i ← i + 1
return LPS
```

### Pseudo Code for KMP

```cpp
Explain
LPS ← ComputeLPS(Pattern) {build LPS table function}
i ← 0
j ← 0
n ← string length
m ← pattern length
while i < n do
    if pattern[j] = string[i] then  {if the characters are a match}
        i ← i + 1
        j ← j + 1
      if j = m then  {j pointer has reached end of pattern}
        return i - j {index of the match}
            j ← LPS[j - 1]

    else if i<n && pattern[j] != string[i] then {no match}
            if j > 0
            j ← LPS[j - 1]
          else
            i ← i + 1
return -1 {no match}
```

## Code for KMP

```cpp
#include <bits/stdc++.h>

void computeLPSArray(char* pat, int M, int* lps);

// Prints occurrences of pat[] in txt[]
void KMPSearch(char* pat, char* txt)
{
    int M = strlen(pat);
    int N = strlen(txt);

    // create lps[] that will hold the longest prefix suffix
    // values for pattern
    int lps[M];

    // Preprocess the pattern (calculate lps[] array)
    computeLPSArray(pat, M, lps);

    int i = 0; // index for txt[]
    int j = 0; // index for pat[]
    while ((N - i) >= (M - j)) {
        if (pat[j] == txt[i]) {
            j++;
            i++;
        }

        if (j == M) {
            printf("Found pattern at index %d ", i - j);
            j = lps[j - 1];
        }

        // mismatch after j matches
        else if (i < N && pat[j] != txt[i]) {
            // Do not match lps[0..lps[j-1]] characters,
            // they will match anyway
            if (j != 0)
                j = lps[j - 1];
            else
                i = i + 1;
        }
    }
}

// Fills lps[] for given pattern pat[0..M-1]
void computeLPSArray(char* pat, int M, int* lps)
{
    // length of the previous longest prefix suffix
    int len = 0;

    lps[0] = 0; // lps[0] is always 0

    // the loop calculates lps[i] for i = 1 to M-1
    int i = 1;
    while (i < M) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        }
        else // (pat[i] != pat[len])
        {
            // This is tricky. Consider the example.
            // AAACAAAA and i = 7. The idea is similar
            // to search step.
            if (len != 0) {
                len = lps[len - 1];

                // Also, note that we do not increment
                // i here
            }
            else // if (len == 0)
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}

// Driver code
int main()
{
    char txt[] = "ABABDABACDABABCABAB";
    char pat[] = "ABABCABAB";
    KMPSearch(pat, txt);
    return 0;
}
```

[Roy's video](https://www.youtube.com/watch?v=GTJr8OvyEVQ&t=606s)

## [Longest Happy prefix](https://leetcode.com/problems/longest-happy-prefix/)

```cpp
class Solution {
public:
    vector<int> lps(string& word){
        vector<int> lp(word.length(), 0);

        int j = 0;
        for(int i = 1; i < word.length();){
            if(word[i] == word[j]){
                lp[i] = j+1;
                i++;
                j++;
            }
            else{
                if(j != 0)
                    j = lp[j-1];//j will have the value of prev character and gives the next highest substring which have same prefix and same suffix.
                else
                    i++;
            }
        }

        return lp;
    }

    string longestPrefix(string s) {
        vector<int> lp = lps(s);

        return s.substr(0, lp.back());
    }
};
```

## M-2. KMP

```cpp
class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = haystack.size(), n = needle.size();
        if (!n) {
            return 0;
        }
        vector<int> lps = kmpProcess(needle);
        for (int i = 0, j = 0; i < m;) {
            if (haystack[i] == needle[j]) {
                i++, j++;
            }
            if (j == n) {
                return i - j;
            }
            if (haystack[i] != needle[j]) {
                j ? j = lps[j - 1] : i++;
            }
        }
        return -1;
    }
private:
    vector<int> kmpProcess(string& word){
        vector<int> lp(word.length(), 0);

        int j = 0;
        for(int i = 1; i < word.length();){
            if(word[i] == word[j]){
                lp[i] = j+1;
                i++;
                j++;
            }
            else{
                if(j != 0)
                    j = lp[j-1];//j will have the value of prev character and gives the next highest substring which have same prefix and same suffix.
                else
                    i++;
            }
        }

        return lp;
    }
};
```
