# Rabin Karp

-   The Rabin-Karp algorithm is a string searching algorithm that uses hashing to efficiently find occurrences of a pattern within a text.
-   It's particularly useful when you have to search for multiple patterns within the same text.
-   The algorithm relies on the rolling hash technique to compute hash values of substrings in constant time.

1. **Choose a Hash Function:** The first step is to choose a hash function. The hash function should be efficient to compute and should produce a unique hash value for each string. In Rabin-Karp, we typically use polynomial hashing. For simplicity, we'll use a basic hash function that calculates the hash value of a string based on its characters' ASCII values.

2. **Compute Hash Values:** Compute the hash values of the pattern and all substrings of the same length in the text. We'll compute the hash values using the chosen hash function.

3. **Search for Matches:** Compare the hash value of the pattern with the hash values of all substrings of the same length in the text. If the hash values match, compare the substrings character by character to confirm the match.

4. **Handle Collisions:** Since we're using hashing, collisions may occur. If two different substrings have the same hash value, perform a character-by-character comparison to confirm the match.

```cpp
#include <iostream>
#include <string>

using namespace std;

// Hash function for ASCII characters
int hashFunction(const string& str) {
    int hashValue = 0;
    for (char c : str) {
        hashValue += c; // Simple sum of ASCII values
    }
    return hashValue;
}

void search(const string& text, const string& pattern) {
    int patternHash = hashFunction(pattern);
    int patternLength = pattern.length();
    int textLength = text.length();

    for (int i = 0; i <= textLength - patternLength; ++i) {
        string substring = text.substr(i, patternLength);
        int substringHash = hashFunction(substring);

        if (substringHash == patternHash && substring == pattern) {
            cout << "Pattern found at index " << i << endl;
        }
    }
}

int main() {
    string text = "ABABCABABCDABABCABAB";
    string pattern = "ABABCABAB";

    search(text, pattern);

    return 0;
}
```

**very Similar To sliding window**

```cpp
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class KarpRabin {
private:
    const int PRIME = 101;

    double calculateHash(const string& str) {
        double hash = 0;
        for(int i = 0; i < str.length(); i++) {
            hash += str[i] * pow(PRIME, i);
        }
        return hash;
    }

    double updateHash(double prevHash, char oldChar, char newChar, int patternLength) {
        double newHash = (prevHash - oldChar) / PRIME;
        newHash += newChar * pow(PRIME, patternLength - 1);
        return newHash;
    }

public:
    void search(const string& text, const string& pattern) {
        int patternLength = pattern.length();
        double patternHash = calculateHash(pattern);
        double textHash = calculateHash(text.substr(0, patternLength));

        for(int i = 0; i <= text.length() - patternLength; i++) {
            if(textHash == patternHash) {
                if(text.substr(i, patternLength) == pattern) {
                    cout << "Pattern found at index " << i << endl;
                }
            }

            if (i < text.length() - patternLength) {
                textHash = updateHash(textHash, text[i], text[i + patternLength], patternLength);
            }
        }
    }
};

int main() {
    KarpRabin karpRabin;
    string text = "ABABCABABCDABABCABAB";
    string pattern = "ABABCABAB";

    karpRabin.search(text, pattern);

    return 0;
}
```
