**Map**

-   implemented as a BST(red black tree)
-   always sorted on keys
-   Operations like insertion, deletion, and search have a time complexity of O(log n)
-   Suitable when you need to maintain a sorted collection of unique elements and require ordered traversal of elements. It's commonly used in scenarios where elements need to be accessed in sorted order.

**Unordered_map**

-   implemented as a hash table
-   no particular order
-   The time complexity of operations like insertion, deletion, and search is O(1) on average. However, in the worst case (when all keys hash to the same value), the time complexity is O(n).
-   Suitable when you need to maintain a collection of unique elements and do not require any ordering when traversing elements. and fast lookup, insertion, deletion.

-   std::map: Generally has a higher memory overhead compared to std::unordered_map due to the additional storage required for the tree structure.

```cpp
#include <iostream>
#include <unordered_map>

int main() {
    // Define an unordered_map
    std::unordered_map<int, std::string> myUnorderedMap;

    // Check if unordered_map is empty
    if (myUnorderedMap.empty()) {
        std::cout << "Unordered_map is empty." << std::endl;
    }

    // Get the size of the unordered_map
    std::cout << "Size of unordered_map: " << myUnorderedMap.size() << std::endl;

    // Get the maximum size of the unordered_map
    std::cout << "Maximum size of unordered_map: " << myUnorderedMap.max_size() << std::endl;

    // Insert elements into the unordered_map
    myUnorderedMap.emplace(1, "One");
    myUnorderedMap.emplace(2, "Two");
    myUnorderedMap.insert({3, "Three"});

    // Iterate through the unordered_map using iterators
    for (auto it = myUnorderedMap.begin(); it != myUnorderedMap.end(); ++it) {
        std::cout << it->first << ": " << it->second << std::endl;
    }

    // Find an element in the unordered_map
    auto findIt = myUnorderedMap.find(2);
    if (findIt != myUnorderedMap.end()) {
        std::cout << "Element found: " << findIt->second << std::endl;
    }

    // Count occurrences of an element
    int count = myUnorderedMap.count(1);
    std::cout << "Count of element with key 1: " << count << std::endl;

    // Inserting elements into the unordered_map
    myUnorderedMap.emplace(4, "Four");
    myUnorderedMap.insert({5, "Five"});

    myUnorderedMap.at(5);

    // Erase an element from the unordered_map
    myUnorderedMap.erase(5);

    // Swap two unordered_maps
    std::unordered_map<int, std::string> anotherUnorderedMap;
    anotherUnorderedMap.insert({10, "Ten"});
    myUnorderedMap.swap(anotherUnorderedMap);

    // Check if unordered_map is empty after swap
    if (myUnorderedMap.empty()) {
        std::cout << "Unordered_map is empty after swap." << std::endl;
    }

    return 0;
}
```
