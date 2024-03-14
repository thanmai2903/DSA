# Queue

-   empty, size, front, back, push, emplace, pop, swap

```cpp
#include <iostream>
#include <queue>

int main() {
    std::queue<int> myQueue;

    // Checking if queue is empty
    std::cout << "Is queue empty? " << (myQueue.empty() ? "Yes" : "No") << std::endl;

    // Pushing elements into the queue
    myQueue.push(1);
    myQueue.push(2);
    myQueue.push(3);

    // Getting the size of the queue
    std::cout << "Size of queue: " << myQueue.size() << std::endl;

    // Accessing the front and back elements of the queue
    std::cout << "Front element of queue: " << myQueue.front() << std::endl;
    std::cout << "Back element of queue: " << myQueue.back() << std::endl;

    // Popping the front element from the queue
    myQueue.pop();

    // Emplacing an element into the queue
    myQueue.emplace(4);

    // Swapping contents of queues
    std::queue<int> anotherQueue;
    anotherQueue.push(5);
    anotherQueue.push(6);
    myQueue.swap(anotherQueue);

    // Outputting elements of the queue after swap
    std::cout << "Queue after swapping:" << std::endl;
    while (!myQueue.empty()) {
        std::cout << myQueue.front() << " ";
        myQueue.pop();
    }
    std::cout << std::endl;

    return 0;
}
```

## Deque

-   deck or doubly ended queues
-   dynamic size => expanded/contracted on both sides
-   provide similar functionality to vectors but with efficient insertion and deletion of elements also at the beginning of the sequence, and not only at its end.

1. begin, end, rbegin, rend, size, max_size, resize, empty, at, front, back, assign, push_back, push_front, pop_back, pop_front, insert, erase, swap, clear, emplace, emplace_back , emplace_frontoutput?

```cpp
#include <iostream>
#include <deque>

int main() {
    // Creating a deque
    std::deque<int> myDeque;

    // Adding elements to the deque
    myDeque.push_back(1);
    myDeque.push_back(2);
    myDeque.push_front(0);
    myDeque.emplace_back(3);
    myDeque.emplace_front(-1);

    // Iterating through the deque using iterators
    std::cout << "Deque elements: ";
    for (auto it = myDeque.begin(); it != myDeque.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl; // -1 0 1 2 3

    // Reversing the deque using reverse iterators
    std::cout << "Reversed Deque elements: ";
    for (auto rit = myDeque.rbegin(); rit != myDeque.rend(); ++rit) {
        std::cout << *rit << " ";
    }
    std::cout << std::endl;//  3 2 1 0 -1

    // Accessing elements by index
    std::cout << "Element at index 2: " << myDeque.at(2) << std::endl; // 1

    // Front and back elements
    std::cout << "Front element: " << myDeque.front() << std::endl; // -1
    std::cout << "Back element: " << myDeque.back() << std::endl; // 3

    // Size and maximum size
    std::cout << "Size of deque: " << myDeque.size() << std::endl; // 5
    std::cout << "Maximum size of deque: " << myDeque.max_size() << std::endl; //4611686018427387903

    // Resizing the deque
    myDeque.resize(5, 10);

    // Checking if the deque is empty
    std::cout << "Is deque empty? " << (myDeque.empty() ? "Yes" : "No") << std::endl; // No

    // Popping elements from the back and front
    myDeque.pop_back(); // -1 0 1 2
    myDeque.pop_front();// 0 1 2

    // Inserting elements at a specific position
    myDeque.insert(myDeque.begin() + 2, 7);// 0 1 7 2
    myDeque.insert(myDeque.begin() + 3, 2, 8); // 0 1 7 8 8 2

    // Erasing elements from a specific position
    myDeque.erase(myDeque.begin() + 1);// 0 7 8 8 2

    // Swapping the contents of two deques
    std::deque<int> anotherDeque = {100, 200, 300};
    myDeque.swap(anotherDeque);

    // Clearing the deque
    myDeque.clear();

    return 0;
}
```

-   myDeque.resize(5, 10)
    -   if no of ele < 5 -> push val 10 untill size is 5
    -   if no of ele > 5 -> pop such that size will be 5

# Priority-Queue

-   specifically designed such that its first element is always the greatest of the elements it contains
-   heap -> only max_heap ele can be retrieved.

**Heap**

```cpp
#include <iostream>
#include <queue>

int main() {
    // Creating a priority queue (max heap) of integers
    std::priority_queue<int> maxHeap;

    // Inserting elements into the max heap
    maxHeap.push(3);
    maxHeap.push(7);
    maxHeap.push(1);
    maxHeap.push(9);
    maxHeap.push(5);

    // Printing elements of the max heap
    std::cout << "Max Heap elements: ";
    while (!maxHeap.empty()) {
        std::cout << maxHeap.top() << " ";
        maxHeap.pop();
    }
    std::cout << std::endl;

    // Creating a priority queue (min heap) of integers
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;

    // Inserting elements into the min heap
    minHeap.push(3);
    minHeap.push(7);
    minHeap.push(1);
    minHeap.push(9);
    minHeap.push(5);

    // Printing elements of the min heap
    std::cout << "Min Heap elements: ";
    while (!minHeap.empty()) {
        std::cout << minHeap.top() << " ";
        minHeap.pop();
    }
    std::cout << std::endl;

    return 0;
}
```

**Output**

```
Max Heap elements: 9 7 5 3 1
Min Heap elements: 1 3 5 7 9
```
