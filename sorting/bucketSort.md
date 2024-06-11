# Bucket Sort Algorithm

-   The data items in the bucket sort are distributed in the form of buckets.
-   Bucket sort is a sorting algorithm that separate the elements into multiple groups said to be buckets.
-   Elements in bucket sort are first uniformly divided into groups called buckets, and then they are sorted by any other sorting algorithm.
-   After that, elements are gathered in a sorted manner.

```
1. First, partition the range into a fixed number of buckets.
2. Then, toss every element into its appropriate bucket.(bucketIdx = value*bucketSize)
3. After that, sort each bucket individually by applying a sorting algorithm.
4. And at last, concatenate all the sorted buckets.
```

### Advantages

1. reduces no of comparisons
2. Asymptotically fast because of uniform distribution of elements.

### Drawbacks

1. It may or may not be a stable sorting algorithm.

```
- An algorithm is considered stable if it preserves the relative order of equal elements from the input in the sorted output.
- Bucket Sort can be stable, but this depends on the sorting algorithm used to sort the elements within each bucket.
- If a stable sorting algorithm (like insertion sort) is used for the buckets, then the entire bucket sort will be stable.
```

2. It is not useful if we have a large array because it increases the cost.
3. It is not an in-place sorting algorithm, because some extra space is required to sort the buckets.

-   Bucket sort is commonly used-
    1. With float-point values.
    2. WHen i/p is distributed over a range.
-   It is also known a **scatter-gather approach.**

```
scatter-> sort->gather
```

### Code

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

// Function to perform insertion sort on a bucket
void insertionSort(std::vector<float> &bucket) {
    for (size_t i = 1; i < bucket.size(); ++i) {
        float key = bucket[i];
        int j = i - 1;
        while (j >= 0 && bucket[j] > key) {
            bucket[j + 1] = bucket[j];
            j--;
        }
        bucket[j + 1] = key;
    }
}

// Function to perform bucket sort
void bucketSort(std::vector<float> &arr) {
    // Step 1: Create empty buckets
    int n = arr.size();
    std::vector<std::vector<float>> buckets(n);

    // Step 2: Distribute elements into buckets
    for (int i = 0; i < n; ++i) {
        int bucketIndex = static_cast<int>(arr[i] * n); // Index in the range [0, n-1]
        buckets[bucketIndex].push_back(arr[i]);
    }

    // Step 3: Sort individual buckets using insertion sort
    for (int i = 0; i < n; ++i) {
        insertionSort(buckets[i]);
    }

    // Step 4: Concatenate all buckets into the original array
    int index = 0;
    for (int i = 0; i < n; ++i) {
        for (size_t j = 0; j < buckets[i].size(); ++j) {
            arr[index++] = buckets[i][j];
        }
    }
}

int main() {
    // Example input array
    std::vector<float> arr = {0.42, 0.32, 0.23, 0.52, 0.25, 0.47, 0.51};

    std::cout << "Original array: ";
    for (float num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Perform bucket sort
    bucketSort(arr);

    std::cout << "Sorted array: ";
    for (float num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
```
