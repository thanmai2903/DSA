# Vectors

1.  begin, end, rbegin, rend

```cpp
#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};

    // Iterate over the elements using begin() and end()
    std::cout << "Iterating forward:" << std::endl;
    for (auto it = vec.begin(); it != vec.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Iterate over the elements using rbegin() and rend()
    std::cout << "Iterating backward:" << std::endl;
    for (auto rit = vec.rbegin(); rit != vec.rend(); ++rit) {
        std::cout << *rit << " ";
    }
    std::cout << std::endl;

    return 0;
}
```

```
Iterating forward:
1 2 3 4 5
Iterating backward:
5 4 3 2 1
```

2.  size, max_size, resize, capacity

```cpp
#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec;

    // Initial size and capacity
    std::cout << "Initial size of vector: " << vec.size() << std::endl;
    std::cout << "Initial capacity of vector: " << vec.capacity() << std::endl;
    std::cout << "Max size of vector: " << vec.max_size() << std::endl;

    // Add some elements
    for (int i = 0; i < 10; ++i) {
        vec.push_back(i);
    }

    // After adding elements
    std::cout << "\nAfter adding elements:" << std::endl;
    std::cout << "Size of vector: " << vec.size() << std::endl;
    std::cout << "Capacity of vector: " << vec.capacity() << std::endl;

    // Resize the vector
    vec.resize(15); // Resize to size 15, appending default-initialized elements
    std::cout << "\nAfter resizing to 15:" << std::endl;
    std::cout << "Size of vector: " << vec.size() << std::endl;
    std::cout << "Capacity of vector: " << vec.capacity() << std::endl;

    for(auto& e: vec){
        std::cout<<e<<" ";
    }


    return 0;
}
```

**Output**

```
Initial size of vector: 0
Initial capacity of vector: 0
Max size of vector: 4611686018427387903

After adding elements:
Size of vector: 10
Capacity of vector: 16

After resizing to 15:
Size of vector: 15
Capacity of vector: 16

0 1 2 3 4 5 6 7 8 9 0 0 0 0 0
```

3. at, front, back, empty

```cpp
vector<int>v = {1,2,3,4,5};
cout<<v.at(2)<<endl; // 3
cout<<v.front()<<endl; // 1
cout<<v.back()<<endl; // 5
cout<<v.empty()<<endl; // 0
```

4. assign, push_back, pop_back, insert, erase, emplace, emplace_back

```cpp
#include <iostream>
#include <vector>

int main() {
    // Initialize an empty vector
    std::vector<int> vec;

    // Assign values to the vector
    vec.assign({1, 2, 3, 4, 5});

    // Push elements to the back of the vector
    vec.push_back(6);// {1, 2, 3, 4, 5,6}
    vec.push_back(7); // {1, 2, 3, 4, 5,6,7}

    // Pop element from the back of the vector
    vec.pop_back(); //{1, 2, 3, 4, 5, 6}

    // Insert element at a specific position
    vec.insert(vec.begin() + 2, 8); //{1, 2, 8, 3, 4, 5,6}

    // Erase element at a specific position
    vec.erase(vec.begin() + 3); //{1, 2, 8, 4, 5,6}

    // Emplace an element at a specific position
    vec.emplace(vec.begin() + 1, 9);//{1,9, 2, 8, 4, 5,6}

    // Emplace an element at the back of the vector
    vec.emplace_back(10);//{1,9, 2, 8, 4, 5, 6, 10}

    // Output the vector
    std::cout << "Vector: ";
    for (int num : vec) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
```

5. emplace vs insert
   `emplace()` constructs elements in place using their constructors, passing constructor arguments directly.
   `insert()` inserts elements into the vector by copying or moving them into the container.
6. emplace_back vs push_back
   `emplace_back()` constructs the new element in place within the vector, using its constructor with the provided arguments.
   `push_back()` inserts a copy or moves the provided element into the vector.

### Deletion in Vector

#### 1

```cpp
std::vector<int> vec = {1, 2, 3, 4, 5};
vec.erase(vec.begin() + 2); // Removes element at index 2
vec.erase(vec.begin() + 1, vec.begin() + 3); // Removes elements in the range [1, 3)
```

#### 2

```cpp
std::vector<int> vec = {1, 2, 3, 4, 5};
vec.pop_back(); // Removes the last element (5) from the vector
```

#### 3

```cpp
std::vector<int> vec = {1, 2, 3, 4, 5};
vec.erase(std::remove(vec.begin(), vec.end(), 3), vec.end()); // Removes all occurrences of value 3
```

#### 4

```cpp
std::vector<int> vec = {1, 2, 3, 4, 5};
vec.clear(); // Removes all elements from the vector
```
