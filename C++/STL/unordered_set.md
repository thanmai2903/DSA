## set

-   sorted order always
-   implemented as BST(Red black tree)
-   Operations like insertion, deletion, and search have a time complexity of O(log n), where n is the number of elements in the set.
-   Suitable when you need to maintain a sorted collection of unique elements and require ordered traversal of elements.

## unordered_set

-   no particular order
-   implemented as a hash table
-   The time complexity of operations like insertion, deletion, and search is O(1) on average. However, in the worst case (when all keys hash to the same value), the time complexity is O(n).
-   Suitable when you need to maintain a collection of unique elements and do not require any ordering when traversing elements. and fast lookup, insertion, deletion.

-   empty, size, max_size, begin, end, find, count, emplace, insert, erase, slar, swap

```cpp
#include <iostream>
#include <unordered_set>

int main() {
    // Define an unordered_set
    std::unordered_set<int> myUnorderedSet;

    // Insert elements into the unordered_set
    myUnorderedSet.insert(3);
    myUnorderedSet.insert(1);
    myUnorderedSet.insert(4);
    myUnorderedSet.insert(1); // Duplicate insertion

    // Check if unordered_set is empty
    if (!myUnorderedSet.empty()) {
        std::cout << "Unordered_set is not empty." << std::endl;
    }

    // Get the size of the unordered_set
    std::cout << "Size of unordered_set: " << myUnorderedSet.size() << std::endl;

    // Iterate through the unordered_set using iterators
    for (auto it = myUnorderedSet.begin(); it != myUnorderedSet.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Search for an element in the unordered_set
    auto findIt = myUnorderedSet.find(4);
    if (findIt != myUnorderedSet.end()) {
        std::cout << "Element found: " << *findIt << std::endl;
    }

    // Count occurrences of an element
    int count = myUnorderedSet.count(1);
    std::cout << "Count of element with value 1: " << count << std::endl;

    // Emplace elements into the unordered_set
    myUnorderedSet.emplace(2);

    // Erase an element from the unordered_set
    myUnorderedSet.erase(3);

    // Swap contents with another unordered_set
    std::unordered_set<int> anotherUnorderedSet = {5, 6, 7};
    myUnorderedSet.swap(anotherUnorderedSet);

    // Iterate through the swapped unordered_set
    for (int num : myUnorderedSet) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
```

**Output**

```
Unordered_set is not empty.
Size of unordered_set: 3
4 1 3
Element found: 4
Count of element with value 1: 1
7 6 5
```
