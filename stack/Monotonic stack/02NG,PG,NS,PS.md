# Monotonic Stack Examples

## 1. Next Greater

### Notes

-   For finding next greater elements (not equal), use a monotonic non-increasing stack (type 4).
-   If the question was to find next greater or equal elements, use a monotonic strictly decreasing stack (type 3).
-   Use the `operator <` in the while loop condition to create a monotonic non-increasing stack (type 4).
-   Time and space complexity: O(n)

### Code

```cpp
#include <iostream>
#include <vector>
#include <stack>

std::vector<int> findNextGreaterIndexes(const std::vector<int>& arr) {
    // initialize an empty stack
    std::stack<int> stack;

    // initialize nextGreater array, this array holds the output
    // initialize all the elements to -1 (invalid value)
    std::vector<int> nextGreater(arr.size(), -1);

    // iterate through all the elements of the array
    for (int i = 0; i < arr.size(); i++) {
        // while loop runs until the stack is not empty AND
        // the element represented by stack top is STRICTLY SMALLER than the current element
        // This means, the stack will always be monotonic non-increasing (type 4)
        while (!stack.empty() && arr[stack.top()] < arr[i]) {
            // pop out the top of the stack, it represents the index of the item
            int stackTop = stack.top();
            stack.pop();

            // as given in the condition of the while loop above,
            // nextGreater element of stackTop is the element at index i
            nextGreater[stackTop] = i;
        }

        // push the current element
        stack.push(i);
    }

    return nextGreater;
}

int main() {
    std::vector<int> arr = {3, 1, 4, 6, 2, 0, 5};

    std::vector<int> result = findNextGreaterIndexes(arr);

    // Output the result
    for (int i = 0; i < result.size(); i++) {
        std::cout << "Next Greater of " << arr[i] << " is " << (result[i] != -1 ? arr[result[i]] : -1) << std::endl;
    }

    return 0;
}
```

## 2. Previous Greater

### Notes

-   For finding previous greater elements (not equal) we use a monotonic strictly decreasing stack (type 3)
-   If the question was to find previous greater or equal elements, then we would have used a monotonic non increasing stack (type 4)
-   We use the operator <= in while loop condition above - this results in a monotonic strictly decreasing stack (type 3). If we use `< operator`, then this becomes a monotonic non increasing stack (type 4).
-   Time and space complexity - O(n)

### Code

```cpp
#include <iostream>
#include <vector>
#include <stack>

std::vector<int> findPreviousGreaterIndexes(const std::vector<int>& arr) {
// initialize an empty stack
std::stack<int> stack;

    // initialize previousGreater array, this array holds the output
    // initialize all the elements to -1 (invalid value)
    std::vector<int> previousGreater(arr.size(), -1);

    // iterate through all the elements of the array
    for (int i = 0; i < arr.size(); i++) {
        // while loop runs until the stack is not empty AND
        // the element represented by stack top is SMALLER OR EQUAL to the current element
        // This means, the stack will always be strictly decreasing (type 3) - because elements are popped when they are equal
        // so equal elements will never stay in the stack (definition of strictly decreasing stack)
        while (!stack.empty() && arr[stack.top()] <= arr[i]) {
            // pop out the top of the stack, it represents the index of the item
            stack.pop();
        }

        // after the while loop, only the elements which are greater than the current element are left in the stack
        // this means we can confidently decide the previous greater element of the current element i, that's stack top
        if (!stack.empty()) {
            previousGreater[i] = stack.top();
        }

        // push the current element
        stack.push(i);
    }

    return previousGreater;

}

int main() {
std::vector<int> arr = {3, 1, 4, 6, 2, 0, 5};

    std::vector<int> result = findPreviousGreaterIndexes(arr);

    // Output the result
    for (int i = 0; i < result.size(); i++) {
        std::cout << "Previous Greater of " << arr[i] << " is " << (result[i] != -1 ? arr[result[i]] : -1) << std::endl;
    }

    return 0;

}

```

## 3. Both NG,PG

```cpp
vector<std::vector<int>> findNextAndPreviousGreaterIndexes(const std::vector<int>& arr) {
// initialize an empty stack
std::stack<int> stack;

    // initialize previousGreater and nextGreater arrays
    std::vector<int> previousGreater(arr.size(), -1);
    std::vector<int> nextGreater(arr.size(), -1);

    // iterate through all the elements of the array
    for (int i = 0; i < arr.size(); i++) {
        // while loop runs until the stack is not empty AND
        // the element represented by stack top is SMALLER OR EQUAL to the current element
        // This means, the stack will always be strictly decreasing (type 3) - because elements are popped when they are equal
        // so equal elements will never stay in the stack (definition of strictly decreasing stack)
        while (!stack.empty() && arr[stack.top()] <= arr[i]) {
            // pop out the top of the stack, it represents the index of the item
            int stackTop = stack.top();
            stack.pop();

            // decides the next greater element for the index popped out from the stack
            nextGreater[stackTop] = i;
        }

        // after the while loop, only the elements which are greater than the current element are left in the stack
        // this means we can confidently decide the previous greater element of the current element i, that's stack top
        if (!stack.empty()) {
            previousGreater[i] = stack.top();
        }

        // push the current element
        stack.push(i);
    }

    return {previousGreater, nextGreater};

}

```

## 4. Next Smaller (strictly smaller)

-   If you have were able to understand the logic until this point, finding next smaller and previous smaller shouldn't be difficult at all. To get previous greater elements we simply flip the operator from < to >. By doing this we end up creating a strictly increasing (type 1) or a non-decreasing (type 2) array. Given that I've already explained the corresponding cases for next greater and previous greater elements, let me directly show you code examples below.

### Code

```cpp
vector<int> findNextSmallerIndexes(const std::vector<int>& arr) {
// initialize an empty stack
std::stack<int> stack;

    // initialize nextSmaller array, this array holds the output
    // initialize all the elements to -1 (invalid value)
    std::vector<int> nextSmaller(arr.size(), -1);

    // iterate through all the elements of the array
    for (int i = 0; i < arr.size(); i++) {
        // while loop runs until the stack is not empty AND
        // the element represented by stack top is STRICTLY LARGER than the current element
        // This means, the stack will always be monotonic non-decreasing (type 2)
        while (!stack.empty() && arr[stack.top()] > arr[i]) {
            // pop out the top of the stack, it represents the index of the item
            int stackTop = stack.top();
            stack.pop();

            // as given in the condition of the while loop above,
            // nextSmaller element of stackTop is the element at index i
            nextSmaller[stackTop] = i;
        }

        // push the current element
        stack.push(i);
    }

    return nextSmaller;

}

```

## 5. PrevSmaller

```cpp
vector<int> findPreviousSmallerIndexes(const std::vector<int>& arr) {
// initialize an empty stack
std::stack<int> stack;

    // initialize previousSmaller array, this array holds the output
    // initialize all the elements to -1 (invalid value)
    std::vector<int> previousSmaller(arr.size(), -1);

    // iterate through all the elements of the array
    for (int i = 0; i < arr.size(); i++) {
        // while loop runs until the stack is not empty AND
        // the element represented by stack top is LARGER OR EQUAL to the current element
        // This means, the stack will always be monotonic strictly increasing (type 1)
        while (!stack.empty() && arr[stack.top()] >= arr[i]) {
            // pop out the top of the stack, it represents the index of the item
            stack.pop();
        }

        // this is the additional bit here
        if (!stack.empty()) {
            // the index at the stack top refers to the previous smaller element for `i`th index
            previousSmaller[i] = stack.top();
        }

        // push the current element
        stack.push(i);
    }

    return previousSmaller;

}

```

## 6. Both NS and PS

### Code

```cpp
vector<std::vector<int>> findNextAndPreviousSmallerIndexes(const std::vector<int>& arr) {
// initialize an empty stack
std::stack<int> stack;

    // initialize nextSmaller and previousSmaller arrays
    std::vector<int> nextSmaller(arr.size(), -1);
    std::vector<int> previousSmaller(arr.size(), -1);

    // iterate through all the elements of the array
    for (int i = 0; i < arr.size(); i++) {
        // while loop runs until the stack is not empty AND
        // the element represented by stack top is LARGER OR EQUAL to the current element
        // This means, the stack will always be monotonic strictly increasing (type 1)
        while (!stack.empty() && arr[stack.top()] >= arr[i]) {
            // pop out the top of the stack, it represents the index of the item
            int stackTop = stack.top();
            stack.pop();

            // as given in the condition of the while loop above,
            // nextSmaller element of stackTop is the element at index i
            nextSmaller[stackTop] = i;
        }

        // this is the additional bit here
        if (!stack.empty()) {
            // the index at the stack top refers to the previous smaller element for `i`th index
            previousSmaller[i] = stack.top();
        }

        // push the current element
        stack.push(i);
    }

    return {nextSmaller, previousSmaller};

}
```

**Summary**
Let's summarize all the approaches here, to cement our learning.

| Problem          | Stack Type                 | Operator in While Loop | Assignment Position |
| ---------------- | -------------------------- | ---------------------- | ------------------- |
| Next Greater     | Decreasing (equal allowed) | `stackTop < current`   | Inside while loop   |
| Previous Greater | Decreasing (strict)        | `stackTop <= current`  | Outside while loop  |
| Next Smaller     | Increasing (equal allowed) | `stackTop > current`   | Inside while loop   |
| Previous Smaller | Increasing (strict)        | `stackTop >= current`  | Outside while loop  |
