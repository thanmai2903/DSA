# Set

-   stores unique elements
-   values of elemenets can't be modified but can be inserted/removed.

-   begin, end, rbegin, rend, empty, size, max_size, insert, erase, swap, clear, emplace

```cpp
#include <iostream>
#include <set>

int main() {
    // Creating a set
    std::set<int> mySet;

    // Inserting elements into the set
    mySet.insert(10);
    mySet.insert(20);
    mySet.insert(30);
    mySet.insert(40);

    // Checking if the set is empty
    std::cout << "Is set empty? " << (mySet.empty() ? "Yes" : "No") << std::endl; // No

    // Getting the size of the set
    std::cout << "Size of set: " << mySet.size() << std::endl; // 4

    // Maximum size of the set
    std::cout << "Maximum size of set: " << mySet.max_size() << std::endl; // 230584300921369395

    // Iterating through the set using iterators
    std::cout << "Set elements: ";
    for (auto it = mySet.begin(); it != mySet.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;// 10 20 30 40

    // Reversing the iteration using reverse iterators
    std::cout << "Reversed Set elements: ";
    for (auto rit = mySet.rbegin(); rit != mySet.rend(); ++rit) {
        std::cout << *rit << " ";
    }
    std::cout << std::endl;// 40 30 20 10

    // Erasing an element from the set
    mySet.erase(20); // 10 30 40

    // Inserting an element using emplace
    mySet.emplace(50);// 10 30 40 50

    // Swapping the contents of two sets
    std::set<int> anotherSet = {100, 200, 300};
    mySet.swap(anotherSet);

    // Clearing the set
    mySet.clear();

    return 0;
}
```

-   find, count, upper_bound(stricly greater), lower_bound(greater or equal)

```cpp
#include <iostream>
#include <set>

int main() {
    // Creating a set
    std::set<int> mySet = {10, 20, 30, 40, 50};

    // Finding an element in the set
    auto it = mySet.find(30);
    if (it != mySet.end()) {
        std::cout << "Element found: " << *it << std::endl;
    } else {
        std::cout << "Element not found" << std::endl;
    }

    // Counting occurrences of an element in the set
    int count = mySet.count(20);
    std::cout << "Count of element 20: " << count << std::endl;

    // Finding the lower bound of an element in the set
    auto lower = mySet.lower_bound(50);
    if (lower != mySet.end()) {
        std::cout << "Lower bound of 50: " << *lower << std::endl;
    } else {
        std::cout << "No lower bound found for 50" << std::endl;
    }
    auto lower1 = mySet.lower_bound(30);
    if (lower1 != mySet.end()) {
        std::cout << "Lower bound of 30: " << *lower1 << std::endl;
    } else {
        std::cout << "No lower bound found for 30" << std::endl;
    }

    // Finding the upper bound of an element in the set
    auto upper = mySet.upper_bound(35);
    if (upper != mySet.end()) {
        std::cout << "Upper bound of 35: " << *upper << std::endl;
    } else {
        std::cout << "No upper bound found for 35" << std::endl;
    }
    auto upper1 = mySet.upper_bound(50);
    if (upper1 != mySet.end()) {
        std::cout << "Upper bound of 50: " << *upper1 << std::endl;
    } else {
        std::cout << "No upper bound found for 50" << std::endl;
    }

    return 0;
}
```

**Output**

```
Element found: 30
Count of element 20: 1
Lower bound of 50: 50
Lower bound of 30: 30
Upper bound of 35: 40
No upper bound found for 50
```

# multiset

-   multiple-key set
-   multiple elements can have equivalent values.
-   The value of the elements in a multiset cannot be modified once in the container (the elements are always const), but they can be inserted or removed.
-   Multisets are typically implemented as binary search trees.

```cpp
#include <iostream>
#include <set>

int main() {
    // Creating a multiset
    std::multiset<int> myMultiSet;

    // Inserting elements into the multiset
    myMultiSet.insert(10);
    myMultiSet.insert(20);
    myMultiSet.insert(30);
    myMultiSet.insert(30); // Duplicate element
    myMultiSet.insert(40);

    // Checking if the multiset is empty
    std::cout << "Is multiset empty? " << (myMultiSet.empty() ? "Yes" : "No") << std::endl;

    // Getting the size of the multiset
    std::cout << "Size of multiset: " << myMultiSet.size() << std::endl;

    // Maximum size of the multiset
    std::cout << "Maximum size of multiset: " << myMultiSet.max_size() << std::endl;

    // Iterating through the multiset using iterators
    std::cout << "Multiset elements: ";
    for (auto it = myMultiSet.begin(); it != myMultiSet.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Reversing the iteration using reverse iterators
    std::cout << "Reversed Multiset elements: ";
    for (auto rit = myMultiSet.rbegin(); rit != myMultiSet.rend(); ++rit) {
        std::cout << *rit << " ";
    }
    std::cout << std::endl;

    // Finding an element in the multiset
    auto findIt = myMultiSet.find(30);
    if (findIt != myMultiSet.end()) {
        std::cout << "Element 30 found" << std::endl;
    } else {
        std::cout << "Element 30 not found" << std::endl;
    }

    // Counting occurrences of an element in the multiset
    int count = myMultiSet.count(30);
    std::cout << "Count of element 30: " << count << std::endl;

    // Finding the lower bound of an element in the multiset
    auto lowerBound = myMultiSet.lower_bound(25);
    if (lowerBound != myMultiSet.end()) {
        std::cout << "Lower bound of 25: " << *lowerBound << std::endl;
    } else {
        std::cout << "No lower bound found for 25" << std::endl;
    }

    // Finding the upper bound of an element in the multiset
    auto upperBound = myMultiSet.upper_bound(35);
    if (upperBound != myMultiSet.end()) {
        std::cout << "Upper bound of 35: " << *upperBound << std::endl;
    } else {
        std::cout << "No upper bound found for 35" << std::endl;
    }

    // Erasing an element from the multiset
    myMultiSet.erase(30);

    // Clearing the multiset
    myMultiSet.clear();

    return 0;
}
```

**Output**

```
Is multiset empty? No
Size of multiset: 5
Maximum size of multiset: 230584300921369395
Multiset elements: 10 20 30 30 40
Reversed Multiset elements: 40 30 30 20 10
Element 30 found
Count of element 30: 2
Lower bound of 25: 30
Upper bound of 35: 40

```
