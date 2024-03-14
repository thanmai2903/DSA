# Map

-   key:value pair
-   unique keys
-   Maps are typically implemented as binary search trees.

```cpp
#include <iostream>
#include <map>

int main() {
    // Define a map
    std::map<int, std::string> myMap;

    // Insert elements into the map
    myMap.insert({1, "One"});
    myMap.insert({2, "Two"});
    myMap.insert({3, "Three"});

    // Check if map is empty
    if (!myMap.empty()) {
        std::cout << "Map is not empty." << std::endl;
    }

    // Get the size of the map
    std::cout << "Size of map: " << myMap.size() << std::endl;

    // Iterate through the map using iterators
    for (auto it = myMap.begin(); it != myMap.end(); ++it) {
        std::cout << it->first << ": " << it->second << std::endl;
    }

    // Access an element using at()
    std::cout << "Value at key 2: " << myMap.at(2) << std::endl;

    // Erase an element from the map
    myMap.erase(2);

    // Find an element in the map
    auto findIt = myMap.find(3);
    if (findIt != myMap.end()) {
        std::cout << "Element found: " << findIt->second << std::endl;
    }

    // Count occurrences of an element
    int count = myMap.count(1);
    std::cout << "Count of element with key 1: " << count << std::endl;

    // Upper bound example
    auto upperBoundIt = myMap.upper_bound(1);
    if (upperBoundIt != myMap.end()) {
        std::cout << "Upper bound of key 1: " << upperBoundIt->first << std::endl;
    }

    // Lower bound example
    auto lowerBoundIt = myMap.lower_bound(1);
    if (lowerBoundIt != myMap.end()) {
        std::cout << "Lower bound of key 1: " << lowerBoundIt->first << std::endl;
    }

    // Clear the map
    myMap.clear();

    return 0;
}
```

## Multi-map

```cpp
#include <iostream>
#include <map>

int main() {
    // Define a multimap
    std::multimap<int, std::string> myMultiMap;

    // Insert elements into the multimap
    myMultiMap.insert({1, "One"});
    myMultiMap.insert({2, "Two"});
    myMultiMap.insert({2, "Two again"}); // Inserting a duplicate key

    // Check if multimap is empty
    if (!myMultiMap.empty()) {
        std::cout << "Multimap is not empty." << std::endl;
    }

    // Get the size of the multimap
    std::cout << "Size of multimap: " << myMultiMap.size() << std::endl;

    // Iterate through the multimap using iterators
    for (auto it = myMultiMap.begin(); it != myMultiMap.end(); ++it) {
        std::cout << it->first << ": " << it->second << std::endl;
    }

    // Access elements using at() (not available in multimap)
    // Erase an element from the multimap
    myMultiMap.erase(2);

    // Find elements in the multimap
    auto range = myMultiMap.equal_range(1);
    std::cout << "Elements with key 1:" << std::endl;
    for (auto it = range.first; it != range.second; ++it) {
        std::cout << it->first << ": " << it->second << std::endl;
    }

    // Count occurrences of an element
    int count = myMultiMap.count(1);
    std::cout << "Count of element with key 1: " << count << std::endl;

    // Upper bound example
    auto upperBoundIt = myMultiMap.upper_bound(1);
    if (upperBoundIt != myMultiMap.end()) {
        std::cout << "Upper bound of key 1: " << upperBoundIt->first << std::endl;
    }

    // Lower bound example
    auto lowerBoundIt = myMultiMap.lower_bound(1);
    if (lowerBoundIt != myMultiMap.end()) {
        std::cout << "Lower bound of key 1: " << lowerBoundIt->first << std::endl;
    }

    // Clear the multimap
    myMultiMap.clear();

    return 0;
}
```
