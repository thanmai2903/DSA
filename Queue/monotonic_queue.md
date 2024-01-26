## Monotonic Queue

-   A monotonic Queue is a data structure the elements from the front to the end is strictly either increasing or decreasing.

-   Monotonic increasing queue: to push an element e, starts from the rear element, we pop out element s≥e(violation);
-   Monotonic decreasing queue: we pop out element s<=e (violation).
-   Sometimes, we can relax the strict monotonic condition, and can allow the stack or queue have repeat value.

```
index   v   Increasing queue        Decreasing queue
1       5   [5]                     [5]
2       3   [3] 3 kick out 5        [5, 3] #3->5
3       1   [1] 1 kick out 3        [5, 3, 1] #1->3
4       2   [1, 2] #2->1            [5, 3, 2] 2 kick out 1 #2->3
5       4   [1, 2, 4] #4->2         [5,4] 4 kick out 2, 3 #4->2
```

-   **increasing queue:** find the first element smaller than current either in the left (from pushing in) or in the right (from popping out);
-   **decreasing queue:** find the first element larger than current either in the left (from pushing in) or in the right (from popping out);

-   This monotonic queue is actually a data structure that needed to add/remove element from the end. In some application we might further need to remove element from the front. Thus Deque from collections fits well to implement this data structure.

## Monotonic Increasing Queue

```cpp
pair<std::vector<int>, std::vector<int>> increasingQueue(const std::vector<int>& A) {
    std::deque<int> q;
    std::vector<int> firstSmallerToLeft(A.size(), -1);
    std::vector<int> firstSmallerToRight(A.size(), -1);

    for (int i = 0; i < A.size(); ++i) {
        while (!q.empty() && A[q.back()] >= A[i]) {
            firstSmallerToRight[q.back()] = A[i];
            q.pop_back();
        }

        if (!q.empty()) {
            firstSmallerToLeft[i] = A[q.back()];
        }

        q.push_back(i);
    }

    return {firstSmallerToLeft, firstSmallerToRight};
}
```

## Monotonic Decreasing Queue

```cpp
pair<std::vector<int>, std::vector<int>> decreasingQueue(const std::vector<int>& A) {
    std::deque<int> q;
    std::vector<int> firstLargerToLeft(A.size(), -1);
    std::vector<int> firstLargerToRight(A.size(), -1);

    for (int i = 0; i < A.size(); ++i) {
        while (!q.empty() && A[q.back()] <= A[i]) {
            firstLargerToRight[q.back()] = A[i];
            q.pop_back();
        }

        if (!q.empty()) {
            firstLargerToLeft[i] = A[q.back()];
        }

        q.push_back(i);
    }

    return {firstLargerToLeft, firstLargerToRight};
}
```

[Sliding Window Maximum](https://leetcode.com/problems/sliding-window-maximum/)
M-1.

```cpp
class Solution {
public:
vector<int> maxSlidingWindow(vector<int>& nums, int k) {

    int j = 0 , i = 0 ;
    deque<int> q ;
    vector<int> ans ;

    while(j < nums.size()){
        if(!q.empty() && nums[j] > q.back()){
            while(!q.empty() && nums[j] > q.back()){
                q.pop_back() ;
            }
        }
        q.push_back(nums[j]) ;

        if(j - i + 1 < k){
            j++ ;
        }else if(j - i + 1 == k){
            ans.push_back(q.front()) ;
            if(q.front() == nums[i]){
                q.pop_front() ;
            }
            i++ ;
            j++ ;
        }
    }

    return ans ;
   }
};
```

M-2.

````cpp
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;
        deque<int> dq;
        int i = 0, j = 0;

        while (j < n) {
            // Remove elements outside the current window
            while (!dq.empty() && dq.front() < i) {
                dq.pop_front();
            }

            // Remove elements smaller than the current element from the back
            while (!dq.empty() && nums[dq.back()] < nums[j]) {
                dq.pop_back();
            }

            dq.push_back(j);

            // If the window is fully formed, add the maximum to the result
            if (j-i+1 >= k ) {
                ans.push_back(nums[dq.front()]);
                i++;
            }

            j++;
        }

        return ans;
    }
    ```
````
