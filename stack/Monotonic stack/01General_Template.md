# Monotonic Stack Algorithm

## Introduction

This template demonstrates the implementation of the monotonic stack algorithm in C++. The monotonic stack is used to efficiently solve problems related to finding the next greater or previous greater element in an array.

## Key Points

-   We initialize an empty stack at the beginning.
-   The stack contains the index of items in the array, not the items themselves.
-   There is an outer for loop and an inner while loop.
-   At the beginning of the program, the stack is empty, so we don't enter the while loop initially.
-   The earliest we can enter the while loop body is during the second iteration of the for loop, when there is at least one item in the stack.
-   At the end of the while loop, the index of the current element is pushed into the stack.
-   The `OPERATOR` inside the while loop condition decides what type of monotonic stack we are creating. The `OPERATOR` could be any of the four: `>`, `>=`, `<`, `<=`.
-   **Time Complexity**: It can be argued that no element is accessed more than four times (a constant) - one when comparing its value with the item in the stack (while conditional), two when pushing the item into the stack, three when comparing this item in the stack with the current item being iterated (while conditional again), and four when popping the item out of the stack. As a result, the time complexity of this algorithm is linear - O(n), where n is the number of elements in the array.
-   **Space Complexity**: Because we are using an external data structure - stack, in the worst case, it can be filled with all the elements in the array. The space complexity is also linear - O(n), where n is the number of elements in the array.

## Implementation

```cpp
#include <iostream>
#include <vector>
#include <stack>

void buildMonoStack(const std::vector<int>& arr) {
    // Initialize an empty stack
    std::stack<int> stack;

    // Iterate through all the elements in the array
    for (int i = 0; i < arr.size(); ++i) {
        while (!stack.empty() && arr[stack.top()] < arr[i]) {
            // If the previous condition is satisfied, pop the top element
            int stackTop = stack.top();
            stack.pop();

            // Do something with stackTop here e.g.
            // nextGreater[stackTop] = i
            std::cout << "Next Greater of " << arr[stackTop] << " is " << arr[i] << std::endl;
        }

        if (!stack.empty()) {
            // If stack has some elements left
            // Do something with stack top here e.g.
            // previousGreater[i] = stack.top()
            std::cout << "Previous Greater of " << arr[i] << " is " << arr[stack.top()] << std::endl;
        }

        // At the end, push the current index into the stack
        stack.push(i);
    }

    // At all points in time, the stack maintains its monotonic property
}

int main() {
    std::vector<int> arr = {3, 1, 4, 6, 2, 0, 5};

    buildMonoStack(arr);

    return 0;
}
```
