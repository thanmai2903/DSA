## 1. Introduction to Trie:

A Trie (pronounced "try") is a tree-like data structure that is used to store a dynamic set of strings where the keys are usually sequences, such as words in a dictionary.

## 2. Trie Structure:

-   Each node in the Trie represents a character of the key.
-   The path from the root to a particular node spells out the key associated with that node.
-   Each node may have multiple children, each corresponding to a different character.

## 3. Basic Trie Operations:

-   Efficient on operations on words in a dictionary.

#### Insertion:

      - Start from the root and follow the path corresponding to each character in the key.
      - If a node does not exist for a character, create a new node.
      - Continue this process until the entire key is inserted.

#### Search:

      - Start from the root and traverse the Trie based on the characters of the key.
      - If at any point, the path is not present, the key is not in the Trie.
      - Otherwise, check if the last node is marked as the end of a key.

#### Deletion:

      - Similar to search, find the node corresponding to the last character of the key.
      - Mark that node as not the end of the key.
      - If the node has no children and is not the end of another key, recursively delete the node.

#### Prefix Search

-   Similar to search but doesn't require the last node to be marked as an end node. It checks if the path exists in the Trie.

#### Lexicographical ordering of words

      - smallest word first
      - King > Apple
      - Kings < Apple

## 5. Advanced Trie Concepts:

#### Compressed Tries (Radix Tree):

      - Combine nodes with only one child into a single node.
      - Reduces space complexity and improves performance.

#### Trie with Map (Associative Trie):

      -Instead of having an array of children, use a map or hash table to store children.
      -Allows for a more flexible set of characters and reduces space.

#### Suffix Trie:

      - Specialized Trie for handling all suffixes of a given string.
      - Useful for string matching and pattern matching.

## 6. Tricks and Techniques:

#### Prefix Matching:

      - Given a prefix, traverse the Trie until the last node of the prefix.
      - All descendants of this node represent words with the given prefix.

#### Counting Words with a Prefix:

      - Traverse the Trie using the given prefix.
      - Perform a depth-first search to count all the words under that node.

#### Wildcard Matching:

      - Use a wildcard character (e.g., '*') to represent any character.
      - Modify search to handle wildcards by exploring all possible paths.

## 7. Applications:

-   Spell-checking, autocomplete features
-   IP routing and networking
-   Symbol table construction in compilers

## 8. Challenges and Optimizations:

-   Balancing between space and time complexity.
-   Handling large datasets efficiently.

## 9. Tips

**Understanding Edge Cases:** Consider edge cases like empty strings, duplicates, and special characters in your implementation
**Time Complexity:** Trie operations generally have a time complexity proportional to the length of the key.

# BAsic Trie Structure in C++

```cpp
#include <iostream>
#include <unordered_map>
using namespace std;

class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool isEnd;

    TrieNode() : isEnd(false) {}
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

    void insert(string word) {
        TrieNode* node = root;
        for (char ch : word) {
            if (node->children.find(ch) == node->children.end()) {
                node->children[ch] = new TrieNode();
            }
            node = node->children[ch];
        }
        node->isEnd = true;
    }

    bool search(string word) {
        TrieNode* node = root;
        for (char ch : word) {
            if (node->children.find(ch) == node->children.end()) {
                return false;
            }
            node = node->children[ch];
        }
        return node->isEnd;
    }

    bool startsWith(string prefix) {
        TrieNode* node = root;
        for (char ch : prefix) {
            if (node->children.find(ch) == node->children.end()) {
                return false;
            }
            node = node->children[ch];
        }
        return true;
    }
    // Helper function to check if a node has no children
    bool hasNoChildren(TrieNode* node) {
        return node->children.empty();
    }

    // Recursive function to delete a word from the trie
    bool deleteWordHelper(TrieNode* node, string word, int depth) {
        if (depth == word.length()) {
            if (!node->isEnd) {
                // Word not found
                return false;
            }
            node->isEnd = false; // Mark as not end of word
            return hasNoChildren(node); // Check if the current node has no children
        }

        char ch = word[depth];
        if (node->children.find(ch) == node->children.end()) {
            // Word not found
            return false;
        }

        bool shouldDeleteNode = deleteWordHelper(node->children[ch], word, depth + 1);

        if (shouldDeleteNode) {
            // Remove the child node from the map and delete it
            node->children.erase(ch);
            delete node->children[ch];
            // Check if the current node is not the end of another word and has no children
            return !node->isEnd && hasNoChildren(node);
        }

        return false;
    }

    // Public function to delete a word from the trie
    void deleteWord(string word) {
        deleteWordHelper(root, word, 0);
    }
};

int main() {
    Trie trie;

    trie.insert("apple");
    cout << trie.search("apple") << endl;   // Output: 1 (true)
    cout << trie.search("app") << endl;     // Output: 0 (false)
    cout << trie.startsWith("app") << endl; // Output: 1 (true)

    return 0;
}
```
