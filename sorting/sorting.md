# Sorting Algorithms Comparison

| **Algorithm**      | **Time Complexity (Average)** | **Time Complexity (Worst)** | **Space Complexity** | **Stable** | **In-place** |
| ------------------ | ----------------------------- | --------------------------- | -------------------- | ---------- | ------------ |
| **Bubble Sort**    | O(n^2)                        | O(n^2)                      | O(1)                 | Yes        | Yes          |
| **Insertion Sort** | O(n^2)                        | O(n^2)                      | O(1)                 | Yes        | Yes          |
| **Selection Sort** | O(n^2)                        | O(n^2)                      | O(1)                 | No         | Yes          |
| **Merge Sort**     | O(n log n)                    | O(n log n)                  | O(n)                 | Yes        | No           |
| **Quick Sort**     | O(n log n)                    | O(n^2)                      | O(log n)             | No         | Yes          |
| **Heap Sort**      | O(n log n)                    | O(n log n)                  | O(1)                 | No         | Yes          |
| **Counting Sort**  | O(n + k)                      | O(n + k)                    | O(k)                 | Yes        | No           |
| **Radix Sort**     | O(nk)                         | O(nk)                       | O(n + k)             | Yes        | No           |
| **Bucket Sort**    | O(n + k)                      | O(n^2)                      | O(n + k)             | Yes\*      | No           |
| **Tim Sort**       | O(n log n)                    | O(n log n)                  | O(n)                 | Yes        | No           |
| **Shell Sort**     | O(n log n) - O(n^3/2)         | O(n^2)                      | O(1)                 | No         | Yes          |

### Explanation of Terms:

-   **Time Complexity (Average)**: The expected time it takes to sort the array on average.
-   **Time Complexity (Worst)**: The maximum time it could take to sort the array.
-   **Space Complexity**: The amount of extra memory space required by the algorithm.
-   **Stable**: A sorting algorithm is stable if it maintains the relative order of equal elements.
-   **In-place**: A sorting algorithm is in-place if it requires only a constant amount of extra space, excluding the input and output.

### Notes:

-   **Bubble Sort**: Simple but inefficient for large lists.
-   **Insertion Sort**: Efficient for small or nearly sorted lists.
-   **Selection Sort**: Simple but inefficient, doesn't maintain the relative order of equal elements.
-   **Merge Sort**: Very efficient and stable, but requires extra space.
-   **Quick Sort**: Very efficient on average, but not stable and worst-case is O(n^2). Often optimized with techniques like choosing a random pivot.
-   **Heap Sort**: Efficient and in-place, but not stable.
-   **Counting Sort**: Efficient for small ranges of integers, requires extra space proportional to the range.
-   **Radix Sort**: Efficient for fixed-length integer keys, requires extra space.
-   **Bucket Sort**: Efficient for uniformly distributed data, stability depends on the sorting algorithm used for the buckets.
-   **Tim Sort**: Hybrid sorting algorithm (used in Python's sort and Java's Arrays.sort), very efficient and stable.
-   **Shell Sort**: An in-place comparison sort, better performance than Insertion Sort but not stable.
