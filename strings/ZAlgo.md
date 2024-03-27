# Z Algorithm Pattern Matching

-   Z(k) = Longest substring starting at k which is also prefix of the string.

index: 0 1 2 3 4 5 6 7 8 9
**Ex** : a a b x a a y a a b
Z : 0 1 0 0 2 1 0 3 1 0

`Given pattern and a text`
text = "xabcabzabc" pat = "abc"

1. combine pattern and text with a special character like $ which doesn't contain in both the strings.
   => "abc$xabcabzabc"

2. calculate Z values ; Z[0] = 0
   I: 0 1 2 3 4 5 6 7 8 9 10 11 12
   S: a b c $ x a b c a b z a b c
   Z: 0 0 0 0 0 3 0 0 2 0 0 3 0 0

3. Then look for the postioons in Z which is = length of the pattern.
   I: 0 1 2 3 4 5 6 7 8 9 10 11 12
   S: a b c $ x a b c a b z a b c
   Z: 0 0 0 0 0 3 0 0 2 0 0 3 0 0

4. indices are after $ -> 5-4 = 1, 11-4 = 7
   => in the original string my pattern exists at index 1 and 7

```cpp
#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> calculateZ(const string& concat) {
    int n = concat.length();
    vector<int> Z(n, 0);

    int left = 0, right = 0;
    for (int i = 1; i < n; ++i) {
        if (i > right) {
            left = right = i;
            //checking right ptr not going out of bounds
            //here ofcourse right-left = 0 comparing conact[r] with concat[0] at first loop
            while (right < n && concat[right - left] == concat[right]) {
                right++;
            }
            Z[i] = right - left;
            right--;
        } else {
          //it decreases the no of comparisons, without recalcualting z values we are copying the alredy computed z values.
            int k = i - left;
            if (Z[k] < right - i + 1) {
                Z[i] = Z[k];
            } else {
                left = i;
                while (right < n && concat[right - left] == concat[right]) {
                    right++;
                }
                Z[i] = right - left;
                right--;
            }
        }
    }

    return Z;
}

vector<int> zAlgorithm(const string& text, const string& pattern) {
    string concat = pattern + "$" + text;
    int patternLength = pattern.length();
    vector<int> Z = calculateZ(concat);

    vector<int> matches;
    for (int i = 0; i < Z.size(); ++i) {
        if (Z[i] == patternLength) {
            matches.push_back(i - patternLength - 1); // Adjust for extra character '$'
        }
    }

    return matches;
}

int main() {
    string text = "abacaba";
    string pattern = "aba";
    vector<int> matches = zAlgorithm(text, pattern);

    if (matches.empty()) {
        cout << "Pattern not found in the text." << endl;
    } else {
        cout << "Pattern found at indices: ";
        for (int index : matches) {
            cout << index << " ";
        }
        cout << endl;
    }

    return 0;
}
```

**TC** O(m+n)
**SC** O(m+n)
