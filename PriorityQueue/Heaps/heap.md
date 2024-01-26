# Heaps/ Priority Queue

-   Heaps, particularly Priority Queues, are data structures that maintain a set of elements with associated priorities.
-   A specialized tree-based data structure that satisfies the heap property.
-   A Heap, often implemented as a Priority Queue, is a data structure that maintains a partially ordered tree structure. The key feature of a heap is that at any node, the key of that node is less than or equal to the keys of its children. This makes it suitable for efficiently maintaining the maximum or minimum element in a collection.
-   Heaps can be implemented as a binary heap or a more generalized structure like a Fibonacci heap. The most common use case is implementing priority queues, where elements with higher priority (or lower priority depending on the use case) are dequeued before those with lower priority.
-   If the problem deals with the top/min/max/closest K elements among given n elements, use a heap to simplify it.

-   A heap can be classified further as either a “max-heap” or a “min-heap”.
-   In a max-heap, the keys of parent nodes are always greater than or equal to those of the children and the highest key is in the root node.
-   In a min-heap, the keys of parent nodes are less than or equal to those of the children and the lowest key is in the root node.
-   The heap is one maximally efficient implementation of an abstract data type called a priority queue, and in fact, priority queues are often referred to as “heaps”, regardless of how they may be implemented. A common implementation of a heap is the **binary heap**, in which the tree is a **complete binary tree.**

**Applications of Heap**

-   Data Compression: Huffmann Encoding Algorithm
-   Shortest Path Algo: Dijksta
-   Minimum Spanning Tree: Prim’s Algorithm
-   Order Statistics: Kth Largest/Smallest Element
-   Priority Queue: Heap Sort

1. **Understand the Problem:**

-   Clearly understand the problem statement and the operations you need to perform using a heap. Identify whether it involves finding the maximum, minimum, or k-th element.

2. **Common Situations Where Heaps Are Useful and How to Identify Them:**
   i. Finding Kth Smallest/Largest Element:

    If the problem involves finding the Kth smallest or largest element in a collection, consider using a min-heap for Kth smallest and max-heap for Kth largest.

ii. Merge K Sorted Lists:

    If you need to merge K sorted lists, a min-heap can help efficiently get the smallest element among the current elements from all lists.

iii. Top K Elements:

    When you are asked to find the top K elements based on some criteria, a heap can be useful. For example, finding the K most frequent elements or K largest elements.

-   The heap data structure, specifically the binary heap, was introduced as a data structure for the heapsort sorting algorithm. Heaps are also crucial in several efficient graph algorithms such as Dijkstra’s algorithm.
-   In a heap, the highest (or lowest) priority element is always stored at the root.
-   There is no particular relationship among nodes on any given level, even among the siblings.
-   When a heap is a complete binary tree, it has the smallest possible height — a heap with `N` nodes always has `log N` height.
-   A heap is a useful data structure when you need to remove the object with the highest (or lowest) priority.

#### Key Points

-   Heaps -> **Partial Ordered Tree** and **Complete Binary Tree**
-   A simple array can be used to represent a Heap where array indices refer to the node position in the tree.
-   Parent and child nodes can be accessed with indices:

    -   A root node ｜ i = 0, the first item of the array
    -   A parent node ｜ parent(i) = i
    -   A left child node ｜ left(i) = 2i+1
    -   A right child node ｜ right(i)=2i+2
        ![h](https://miro.medium.com/v2/resize:fit:720/format:webp/1*cN_AR3fwVNRIf-pYIAYqYw.jpeg)
        ![ji](https://miro.medium.com/v2/resize:fit:720/format:webp/1*5mhwGo-y-Zw3X2a2l446Qw.jpeg)

    **Summary**
    ![su](https://miro.medium.com/v2/resize:fit:720/format:webp/1*PIY7aOhvUeDV5PJNboPv0A.jpeg)

-   Two type of Heaps — Min Heap, Max Heap
-   Min Heap — the parent node always has a smaller value than the child nodes.
-   Max Heap — the parent node is always larger than the child node value.
    ![imgg](https://miro.medium.com/v2/resize:fit:720/format:webp/1*YsG9jcE4XiDMj-E_VhX03A.jpeg)
    ![imggg](https://miro.medium.com/v2/resize:fit:720/format:webp/1*0hd7XsIV3D092XKKTZg6Pg.jpeg)

-   If we use MIN HEAP then the array will be sorted in ascending order
-   If we use MAX HEAP then the array will be sorted in descending order
    **Adding an element**
    ![i](https://miro.medium.com/v2/resize:fit:1400/format:webp/1*BP0o8V34jxYE4Dn8byJqow.jpeg)

**Deleting an element**
![d](https://miro.medium.com/v2/resize:fit:720/format:webp/1*tq8hBeMDKPTvhfp9R_J45g.jpeg)
![s](https://miro.medium.com/v2/resize:fit:720/format:webp/1*6bCR-NtCtEh9IfRHTzDn_Q.jpeg)

#### Heap Operations

**heapify**
The heapify operation converts the iterable array heap into a tree structure w.r.t heap order.
The priority_queue constructor can be used to initialize a priority queue with elements from a range (in this case, a vector).

**heappush**
It inserts an element into the heap. Post insertion the heap order is adjusted to maintain the heap properties.
The `push` member function is used to insert an element into the priority queue.

**Heappop Operation:**
The top member function retrieves the top (minimum) element without removing it.
The pop member function removes the top element and adjusts the priority queue to maintain the heap order.

-   By default, priority_queue in C++ is a max heap. The std::greater<int> comparator ensures that the smallest element is at the top of the priority queue.

```cpp
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main() {
    // heapify operation
    vector<int> minHeap = {5, 6, 2};
    priority_queue<int, vector<int>, greater<int>> minHeapQueue(minHeap.begin(), minHeap.end());

    // heappush operation
    minHeapQueue.push(7);

    // heappop operation
    int minValue = minHeapQueue.top(); // this retrieves the minimum value
    minHeapQueue.pop(); // removes the minimum value and adjusts the heap order

    cout << "Top element after heappush: " << minHeapQueue.top() << "\n";
    cout << "Removed element: " << minValue << "\n";

    return 0;
}
```

### Binary Heaps

-   Binary heaps are super efficient for implementing priority queues because it’s very easy to know and retrieve/remove the element with the highest priority: it will always be the root node!
    ![h](https://miro.medium.com/v2/resize:fit:720/format:webp/1*4rG1Dxt18Y5p0FefQDf-1A.jpeg)

### Min Heap Implementation

```cpp
#include <iostream>
#include <vector>

class PriorityQueue {
private:
    std::vector<int> pq;

    // Helper function to calculate parent index
    int parent(int index) {
        return (index - 1) / 2;
    }

    // Helper function to calculate left child index
    int leftChild(int index) {
        return 2 * index + 1;
    }

    // Helper function to calculate right child index
    int rightChild(int index) {
        return 2 * index + 2;
    }

    // Helper function to swap elements at two indices
    void swap(int& a, int& b) {
        int temp = a;
        a = b;
        b = temp;
    }

    // Helper function to perform heapify operation
    void heapify(int index) {
        int minIndex = index;
        int left = leftChild(index);
        int right = rightChild(index);

        if (left < pq.size() && pq[left] < pq[minIndex]) {
            minIndex = left;
        }

        if (right < pq.size() && pq[right] < pq[minIndex]) {
            minIndex = right;
        }

        if (minIndex != index) {
            swap(pq[index], pq[minIndex]);
            heapify(minIndex);
        }
    }

public:
    PriorityQueue() {}

    bool isEmpty() {
        return pq.empty();
    }

    int getSize() {
        return pq.size();
    }

    void insert(int elem) {
        pq.push_back(elem);

        int childIndex = pq.size() - 1;

        while (childIndex > 0) {
            int parentIndex = parent(childIndex);
            if (pq[parentIndex] > pq[childIndex]) {
                swap(pq[parentIndex], pq[childIndex]);
            } else {
                break;
            }

            childIndex = parentIndex;
        }
    }

    int removeMin() {
        if (pq.empty()) {
            return -1;
        }

        int minVal = pq[0];
        int size = pq.size();
        swap(pq[0], pq[size - 1]);
        pq.pop_back();

        heapify(0);

        return minVal;
    }
};

int main() {
    PriorityQueue pq;
    pq.insert(12);
    pq.insert(11);
    pq.insert(13);
    pq.insert(5);
    pq.insert(6);
    pq.insert(7);

    while (!pq.isEmpty()) {
        std::cout << pq.removeMin() << " ";
    }

    return 0;
}

```

### Max Heap Implementation

```cpp

#include <iostream>
#include <vector>

class PriorityQueue {
private:
    std::vector<int> pq;

    // Helper function to calculate parent index
    int parent(int index) {
        return (index - 1) / 2;
    }

    // Helper function to calculate left child index
    int leftChild(int index) {
        return 2 * index + 1;
    }

    // Helper function to calculate right child index
    int rightChild(int index) {
        return 2 * index + 2;
    }

    // Helper function to swap elements at two indices
    void swap(int& a, int& b) {
        int temp = a;
        a = b;
        b = temp;
    }

    // Helper function to perform heapify operation (max heap)
    void heapify(int index) {
        int maxIndex = index;
        int left = leftChild(index);
        int right = rightChild(index);

        if (left < pq.size() && pq[left] > pq[maxIndex]) {
            maxIndex = left;
        }

        if (right < pq.size() && pq[right] > pq[maxIndex]) {
            maxIndex = right;
        }

        if (maxIndex != index) {
            swap(pq[index], pq[maxIndex]);
            heapify(maxIndex);
        }
    }

public:
    PriorityQueue() {}

    bool isEmpty() {
        return pq.empty();
    }

    int getSize() {
        return pq.size();
    }

    // Function to insert into max heap
    void insert(int elem) {
        pq.push_back(elem);

        int childIndex = pq.size() - 1;

        while (childIndex > 0) {
            int parentIndex = parent(childIndex);
            if (pq[parentIndex] < pq[childIndex]) {
                swap(pq[parentIndex], pq[childIndex]);
            } else {
                break;
            }

            childIndex = parentIndex;
        }
    }

    // Function to remove the maximum element (root) from max heap
    int removeMax() {
        if (pq.empty()) {
            return -1;
        }

        int maxVal = pq[0];
        int size = pq.size();
        swap(pq[0], pq[size - 1]);
        pq.pop_back();

        heapify(0);

        return maxVal;
    }
};

int main() {
    PriorityQueue pq;
    pq.insert(12);
    pq.insert(11);
    pq.insert(13);
    pq.insert(5);
    pq.insert(6);
    pq.insert(7);

    while (!pq.isEmpty()) {
        std::cout << pq.removeMax() << " ";
    }

    return 0;
}
```

### Kth Smallest -> max heap

```cpp
int kthSmallestElement(int *arr,int n,int k) {

    // Here we want smallest so we have to use MAX HEAP, default priority queue is max heap

    priority_queue<int> pq;

    for(int i = 0; i < n; i++) {
        pq.push(arr[i]);
        if(i >= k) {
            pq.pop(); // we only want k elements in the priority queue at any time
        }
    }

    return pq.top();

}
```

### Kth Largest -> min heap

```cpp
int kthLargestElement(int *arr,int n,int k) {

    // Here we want largest so we have to use MIN HEAP.

    priority_queue<int, vector<int>, greater<int>> pq;

    for(int i = 0; i < n; i++) {
        pq.push(arr[i]);

        if(i >= k) {
            pq.pop(); // we only want k elements in the priority queue at any time
        }
    }

    return pq.top();

}
```

### K Smallest Elements

```cpp
vector<int> ksmallestElements(int *arr,int n,int k) {

    priority_queue<int> pq;

    for(int i = 0; i < n; i++) {
        pq.push(arr[i]);

        if(i >= k) {
            pq.pop();
        }
    }

    vector<int> ans;

    while(!pq.empty()) {
        ans.push_back(pq.top());
        pq.pop();
    }
    return ans;
}
```

### K Sorted Array

```cpp
vector<int> sortTheKSortedArray(int *arr,int n,int k) {

    vector<int> ans;
    priority_queue<int, vector<int>, greater<int>> pq;

    for(int i = 0; i < n; i++) {
        pq.push(arr[i]);

        if(i >= k) {
            ans.push_back(pq.top());
            pq.pop();
        }
    }

    while(!pq.empty()) {
        ans.push_back(pq.top());
        pq.pop();
    }
    return ans;

}
```
