#### Introduction

The Sliding Window Technique is a problem-solving technique that is used to

1.**Running Average**: Use a sliding window to efficiently calculate the average of a fixed-size window as new elements arrive in a stream of data.

2.**Formulating Adjacent Pairs**: Sliding windows are useful when you need to process adjacent pairs of elements in an ordered data structure, allowing you to easily access and operate on neighboring elements.

3.**Target Value Identification**: When you want to find a specific target value or combination of values in an array, a sliding window can help by adjusting the window size and efficiently searching for the desired value or subarrays that meet specific criteria.

4.**Longest/Shortest/Most Optimal Sequence**: Sliding windows are handy when you need to find the longest, shortest, or most optimal sequence that satisfies a given condition in a collection. By sliding a window through the collection and tracking relevant information within it, you can identify the desired sequence more efficiently than scanning the entire collection.

The main idea behind the sliding window technique is to convert two nested loops into a single loop. Usually, the technique helps us to reduce the time complexity from O(n²) or O(n³) to O(n).
This is done by maintaining a sliding window, which is a subarray of the original array that is of a fixed size. The algorithm then iterates over the original array, updating the sliding window as it goes. This allows the algorithm to keep track of a contiguous sequence of elements in the original array, without having to iterate over the entire array multiple times.

Both fixed and variable window sliding window problems can use the techniques of **hashing, two pointers, and sliding window optimization**.

-   a.Hashing is a common technique for tracking the elements in a sliding window. This is because a hash table can quickly and efficiently look up the presence of an element in the window.
-   b.Two pointers is another common technique for tracking the elements in a sliding window. This is because two pointers can easily track the start and end of the window.
-   c.Sliding window optimization is a technique that combines hashing and two pointers to improve the performance of the sliding window algorithm. This is done by using hashing to quickly look up the presence of an element in the window, and using two pointers to track the start and end of the window.
-   The choice of technique for solving a sliding window problem depends on the specific problem and the constraints of the problem. For example, if the sliding window is small, then hashing may be a good choice. However, if the sliding window is large, then two pointers may be a better choice.

-   **Fixed** -> windowSize = const, findout condition
-   **variable** -> condition = const, findout windowSize
-   means after finding out windowSize it can increase or decrease in **variable size sliding window**
-   means after finding out condition window size is const in **fixed size sliding window**

### Identification

-   **Fixed** -> arr/string + subarr/substring + window size -> maximize/minimize the condition that fits windowSize
-   **Variable** -> arr/string + subarr/substring + condition -> maximize/minimize the windowSize that fits the condition

### Template for fixed sized window

-   In a fixed window problem, we have a **predefined window size that remains constant** throughout the problem-solving process.
    The template for solving a fixed window problem involves maintaining two pointers, **low and high, that represent the indices of the current window**.
    The process involves iterating over the array or sequence, adjusting the window as necessary, and performing computations or operations on the elements within the window.
    Here's the template

```
fixed_window()
{
    int low = 0, high = 0, windowsize = k;
    while (i < sizeofarray)
    {
        // Step 1: Create a window that is one element smaller than the desired window size
        if (high - low + 1 < windowsize)
        {
            // Generate the window by increasing the high index
            high++;
        }
        // Step 2: Process the window
        else
        {
            // Window size is now equal to the desired window size
            // Step 2a: Calculate the answer based on the elements in the window
            // Step 2b: Remove the oldest element (at low index) from the window for the next window

            // Proceed to the next window by incrementing the low and high indices
        }
    }
}
```

### Template for variable sized window

-   In a variable window problem,**the window size is not fixed and can change dynamically based on certain conditions or criteria**. The template for solving a variable window problem involves maintaining two pointers, start and end, which represent the indices of the current window.

-   Initialize the window indices: Start by initializing the start and end pointers to the first element of the sequence or array.

-   **Expand the window**: Check a condition to determine whether to expand the window. If the condition is satisfied, increment the end pointer to expand the window size.

-   **Process the window**: Once the window size meets the desired criteria or condition, perform the required computations or operations on the elements within the window.

-   **Adjust the window size**: If the window size exceeds the desired criteria, adjust the window by moving the start pointer. Iterate or loop until the window size matches the desired criteria, and update the window accordingly.

```
variable_window()
{
    int start = 0, end = 0;
    while (end < n)
    {
        // Perform calculations or operations within the window

        /* Case 1: Expand the window
           If the window size is less than the desired value (k), increase the end index
        */
        if (end - start + 1 < k)
        {
            end++;
        }

        /* Case 2: Window of desired size
           If the window size is equal to the desired value (k), process the window and calculate the answer
        */
        else if (end - start + 1 == k)
        {
            // Perform the required calculations or operations to obtain the answer
            // Store the answer in a variable (ans)

            end++;
        }

        /* Case 3: Reduce the window size
           If the window size is greater than the desired value (k), adjust the window by moving the start index
        */
        else if (end - start + 1 > k)
        {
            while (end - start + 1 > k)
            {
                // Remove calculations or operations involving the element at the start index

                start++;
            }

            // Check if the window size becomes equal to the desired value (k) after adjustment
            if (end - start + 1 == k)
            {
                // Perform calculations or operations and store the answer if necessary
            }

            end++;
        }
    }

    // Return the final answer (ans)
}
```
