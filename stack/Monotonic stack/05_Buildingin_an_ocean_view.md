**Question** There are n buildings in a line. You are given an integer array heights of size n that represents the heights of the buildings in the line.

The ocean is to the right of the buildings. A building has an ocean view if the building can see the ocean without obstructions. Formally, a building has an ocean view if all the buildings to its right have a smaller height.

Return a list of indices (0-indexed) of buildings that have an ocean view, sorted in increasing order.

### Solution

A building has ocean view if all buildings on its right are smaller than this building.

Problem type - next greater
Stack type - monotonic strictly decreasing
Operator - <=
No assignment or processing step required

#### Code

```cpp
vector<int> findBuildings(const std::vector<int>& heights) {
    // in other words, we want to find which of the buildings
    // have a next greater element
    // at the end, the elements left in the stack will be the ones
    // which wouldn't have any greater elements after them
    std::stack<int> stack;
    for (int i = 0; i < heights.size(); i++) {
        // note the operator used is <=
        // because we want to pop out the buildings which have another
        // building with equal or greater height in view
        // this means the monotonic stack is going to be strictly decreasing
        while (!stack.empty() && heights[stack.top()] <= heights[i]) {
            stack.pop();
        }
        stack.push(i);
    }

    // Convert stack to vector and return
    std::vector<int> result;
    while (!stack.empty()) {
        result.insert(result.begin(), stack.top());
        stack.pop();
    }

    return result;
}
```
