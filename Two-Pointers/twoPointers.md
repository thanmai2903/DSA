# Pattern 2: Two Pointers

In problems where we deal with sorted arrays (or <b>LinkedList</b>s) and need to find a set of elements that fulfill certain constraints, the <b>two pointers</b> approach becomes quite useful. The set of elements could be a pair, a triplet or even a subarray. For example, take a look at the following problem:

> Given an array of sorted numbers and a target sum, find a pair in the array whose sum is equal to the given target.

To solve this problem, we can consider each element one by one (pointed out by the first pointer) and iterate through the remaining elements (pointed out by the second pointer) to find a pair with the given sum. The <b>time complexity</b> of this algorithm will be `O(N^2)` where `N` is the number of elements in the input array.

Given that the input array is sorted, an efficient way would be to start with one pointer in the beginning and another pointer at the end. At every step, we will see if the numbers pointed by the <b>two pointers</b> add up to the target sum. If they do not, we will do one of two things:

1. If the sum of the two numbers pointed by the <b>two pointers</b> is greater than the target sum, this means that we need a pair with a smaller sum. So, to try more pairs, we can decrement the end-pointer.
2. If the sum of the two numbers pointed by the <b>two pointers</b> is smaller than the target sum, this means that we need a pair with a larger sum. So, to try more pairs, we can increment the start-pointer.

## 🌴 Pair with Target Sum aka "Two Sum" (easy)

https://leetcode.com/problems/two-sum/

> Given an array of sorted numbers and a `target` sum, find a pair in the array whose sum is equal to the given `target`.

Write a function to return the indices of the two numbers (i.e. the pair) such that they add up to the given `target`.

Since the given array is sorted, a brute-force solution could be to iterate through the array, taking one number at a time and searching for the second number through <b>Binary Search</b>. The <b>time complexity</b> of this algorithm will be `O(N*logN)`. Can we do better than this?

We can follow the <b>Two Pointers</b> approach. We will start with one pointer pointing to the beginning of the array and another pointing at the end. At every step, we will see if the numbers pointed by the <b>two pointers</b> add up to the `target` sum. If they do, we have found our pair; otherwise, we will do one of two things:

1. If the sum of the two numbers pointed by the <b>two pointers</b> is greater than the `target` sum, this means that we need a pair with a smaller sum. So, to try more pairs, we can decrement the end-pointer.
2. If the sum of the two numbers pointed by the <b>two pointers</b> is smaller than the `target` sum, this means that we need a pair with a larger sum. So, to try more pairs, we can increment the start-pointer.

### Brute Force Solution

```cpp
#include <vector>

vector<int> pairWithTargetSum(vector<int>& nums, int target) {
    // Iterate through all pairs of indices
    for (int i = 0; i < nums.size(); i++) {
        for (int j = 0; j < nums.size(); j++) {
            // Check if the sum of nums[i] and nums[j] is equal to the target
            if (i != j && (nums[i] + nums[j]) == target) {
                // Return the indices as a vector
                return {i, j};
            }
        }
    }
    // If no pair is found, return an empty vector (you may modify the return value based on your requirements)
    return {};
}

```

### Two pointer Solution

Assume the input is sorted

```cpp
vector<int> pairWithTargetSum(const vector<int>& arr, int target) {
    int start = 0;
    int end = arr.size() - 1;

    // Use the two-pointer approach
    while (start < end) {
        int currentSum = arr[start] + arr[end];

        // Check if the current sum matches the target
        if (currentSum == target) {
            // Return the indices as a vector
            return {start, end};
        }

        // Move the pointers based on the comparison with the target
        if (currentSum < target) {
            start++;
        } else {
            end--;
        }
    }

    // If no pair is found, return an empty vector
    return {};
}
```

-   The <b>time complexity</b> of the above algorithm will be `O(N)`, where `N` is the total number of elements in the given array.
-   The algorithm runs in constant space `O(1)`.

### ❗ Hash Table Solution

Instead of using a two-pointer or a binary search approach, we can utilize a <b>HashTable</b> to search for the required pair. We can iterate through the array one number at a time. Let’s say during our iteration we are at number `X`, so we need to find `Y` such that `“X + Y == Target”`. We will do two things here:

1. Search for `Y` (which is equivalent to `“Target - X”`) in the HashTable. If it is there, we have found the required pair.
2. Otherwise, insert `“X”` in the HashTable, so that we can search it for the later numbers.

```cpp
vector<int> pairWithTargetSum(const vector<int>& nums, int target) {
    // Create a hash table (unordered_map) to store element values and their indices
    unordered_map<int, int> numIndices;

    // Iterate through the array
    for (int i = 0; i < nums.size(); i++) {
        int item = nums[i];

        // Calculate the complement (Y = target - X)
        int complement = target - item;

        // Check if the complement exists in the hash table
        if (numIndices.find(complement) != numIndices.end()) {
            // If found, return the indices as a vector
            return {numIndices[complement], i};
        }

        // Add the current element and its index to the hash table
        numIndices[item] = i;
    }

    // If no pair is found, return [-1, -1]
    return {-1, -1};
}
```

-   The <b>time complexity</b> of the above algorithm will be `O(N)`, where `N` is the total number of elements in the given array.
-   The <b>space complexity</b> will also be `O(N)`, as, in the worst case, we will be pushing `N` numbers in the HashTable.

## Remove Duplicates (easy)

https://leetcode.com/problems/remove-duplicates-from-sorted-array/

> Given an array of sorted numbers, <b>remove all duplicates</b> from it. You should <b>not use any extra space</b>; after removing the duplicates </i>in-place</i> return the length of the subarray that has no duplicate in it.

In this problem, we need to remove the duplicates </i>in-place</i> such that the resultant length of the array remains sorted. As the input array is sorted, therefore, one way to do this is to shift the elements left whenever we encounter duplicates. In other words, we will keep one pointer for iterating the array and one pointer for placing the next non-duplicate number. So our algorithm will be to iterate the array and whenever we see a non-duplicate number we move it next to the last non-duplicate number we’ve seen.

<b>Assume the input is sorted</b>

```cpp

int removeDuplicates(vector<int>& arr) {
    // Initialize two pointers
    int i = 1;
    int nextNonDupe = 1;

    // Iterate through the array
    while (i < arr.size()) {
        // If the current element is different from the last unique element
        if (arr[nextNonDupe - 1] != arr[i]) {
            // Place the current element at the position of nextNonDupe
            arr[nextNonDupe] = arr[i];
            nextNonDupe++;
        }
        i++;
    }

    // Return the length of the array after removing duplicates
    return nextNonDupe;
}
```

-   The <b>time complexity</b> of the above algorithm will be `O(N)`, where `N` is the total number of elements in the given array.
-   The algorithm runs in constant space `O(1)`.

### Remove Element

https://leetcode.com/problems/remove-element/

> Given an unsorted array of numbers and a target `key`, remove all instances of `key` </i>in-place</i> and return the new length of the array.

```cpp
int removeElement(vector<int>& arr, int key) {
    // Pointer for the next element which is not the key
    int nextElement = 0;

    // Iterate through the array
    for (int i = 0; i < arr.size(); i++) {
        // If the current element is not equal to the key, keep it
        if (arr[i] != key) {
            arr[nextElement] = arr[i];
            nextElement++;
        }
    }
    // Return the length of the array after removing every 'key'
    return nextElement;
}
```

-   The <b>time complexity</b> of the above algorithm will be `O(N)`, where `N` is the total number of elements in the given array.
-   The algorithm runs in constant space `O(1)`.

## Squaring a Sorted Array (easy)

https://leetcode.com/problems/squares-of-a-sorted-array/

This is a straightforward question. The only trick is that we can have negative numbers in the input array, which will make it a bit difficult to generate the output array with squares in sorted order.

An easier approach could be to first find the index of the first non-negative number in the array. After that, we can use <b>Two Pointers</b> to iterate the array. One pointer will move forward to iterate the non-negative numbers, and the other pointer will move backward to iterate the negative numbers. At any step, whichever number gives us a bigger square will be added to the output array.

Since the numbers at both ends can give us the largest square, an alternate approach could be to use <b>two pointers</b> starting at both ends of the input array. At any step, whichever pointer gives us the bigger square, we add it to the result array and move to the next/previous number according to the pointer.

```cpp
  //The only trick is that we can have negative numbers in the input array, which will make it a bit difficult to generate the output array with squares in sorted order.
  //An easier approach could be to first find the index of the first non-negative number in the array.
  //After that, we can use Two Pointers to iterate the array.
  //One pointer will move forward to iterate the non-negative numbers
  //the other pointer will move backward to iterate the negative numbers. At any step, whichever number gives us a bigger square will be added to the output array.
  //Since the numbers at both ends can give us the largest square, an alternate approach could be to use two pointers starting at both ends of the input array. At any step, whichever pointer gives us the bigger square, we add it to the result array and move to the next/previous number according to the pointer.




vector<int> makeSquares(const vector<int>& arr) {
    int n = arr.size();
    vector<int> squares(n, 0);
    int highestSquareIndex = n - 1;
    int start = 0;
    int end = n - 1;

    // Use two pointers: one at the start and one at the end of the array
    while (start <= end) {
        // Calculate squares of the numbers at the start and end pointers
        int startSquare = arr[start] * arr[start];
        int endSquare = arr[end] * arr[end];

        // Compare the squares and place the larger one in the result array
        if (startSquare > endSquare) {
            squares[highestSquareIndex] = startSquare;
            start++; // Move the start pointer forward
        } else {
            squares[highestSquareIndex] = endSquare;
            end--; // Move the end pointer backward
        }
        // Decrement the highest square index to fill the result array from the end
        highestSquareIndex--;
    }

    return squares;
}

```

-   The above algorithm’s <b>time complexity</b> will be `O(N)` as we are iterating the input array only once.
-   The above algorithm’s <b>space complexity</b> will also be `O(N)`; this space will be used for the output array.

## 🌟 Triplet Sum to Zero (medium)

https://leetcode.com/problems/3sum/

> Given an array of unsorted numbers, find all unique triplets in it that add up to zero.

This problem follows the <b>Two Pointers</b> pattern and shares similarities with [Pair with Target Sum](#🌴-pair-with-target-sum-aka-"two-sum"-easy). A couple of differences are that the input array is not sorted and instead of a pair we need to find triplets with a target sum of zero.

To follow a similar approach, first, we will sort the array and then iterate through it taking one number at a time. Let’s say during our iteration we are at number `X`, so we need to find `Y` and `Z` such that `X + Y + Z == 0`. At this stage, our problem translates into finding a pair whose sum is equal to `-X` (as from the above equation `Y + Z == -X`).

Another difference from <b>[Pair with Target Sum](#🌴-pair-with-target-sum-aka-"two-sum"-easy)</b> is that we need to find all the unique triplets. To handle this, we have to skip any duplicate number. Since we will be sorting the array, so all the duplicate numbers will be next to each other and are easier to skip.

```cpp
void searchPair(const vector<int>& arr, int targetSum, int start, vector<vector<int>>& triplets) {
    int end = arr.size() - 1;

    // Two-pointer approach to find pairs that add up to targetSum
    while (start < end) {
        int currentSum = arr[start] + arr[end];

        if (currentSum == targetSum) {
            // Found a triplet that adds up to zero
            triplets.push_back({-targetSum, arr[start], arr[end]});
            start++;
            end--;

            // Skip duplicate elements to avoid duplicates in triplets
            while (start < end && arr[start] == arr[start - 1]) {
                start++;
            }
            while (start < end && arr[end] == arr[end + 1]) {
                end--;
            }
        } else if (currentSum < targetSum) {
            // Need a pair with a larger sum
            start++;
        } else {
            // Need a pair with a smaller sum
            end--;
        }
    }
}

vector<vector<int>> searchTriplets(vector<int>& arr) {
    // Sort the array
    sort(arr.begin(), arr.end());
    vector<vector<int>> triplets;

    // Iterate through the array
    for (int i = 0; i < arr.size(); i++) {
        // Skip duplicate elements
        if (i > 0 && arr[i] == arr[i - 1]) {
            continue;
        }
        // Search for pairs that add up to the negative of the current element
        searchPair(arr, -arr[i], i + 1, triplets);
    }

    return triplets;
}
```

-   Sorting the array will take `O(N * logN)`. The `searchPair()` function will take `O(N)`. As we are calling `searchPair()` for every number in the input array, this means that overall `searchTriplets()` will take `O(N * logN + N^2)`, which is asymptotically equivalent to `O(N^2)`.
-   Ignoring the space required for the output array, the <b>space complexity</b> of the above algorithm will be `O(N)` which is required for sorting.

## Triplet Sum Close to Target (medium)

https://leetcode.com/problems/3sum-closest/

> Given an array of unsorted numbers and a `targetSum`, find a <b>triplet in the array whose sum is as close to the `targetSum` as possible</b>, return the sum of the triplet. If there are more than one such triplet, return the sum of the triplet with the smallest sum.

This problem follows the <b>Two Pointers</b> pattern and is quite similar to <b>[Triplet Sum to Zero](#🌟-triplet-sum-to-zero-medium)</b>.

We can follow a similar approach to iterate through the array, taking one number at a time. At every step, we will save the difference between the triplet and the `targetSum`, so that in the end, we can return the triplet with the closest sum.

```cpp
class Solution {
public:
    int threeSumClosest(std::vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        // Initialize the closest sum and the minimum difference
        int closestSum = nums[0] + nums[1] + nums[2];
        int minDifference = abs(closestSum - target);

        // Iterate through the array
        for (int i = 0; i < n - 2; ++i) {
            // Initialize two pointers
            int left = i + 1;
            int right = n - 1;

            // Perform a two-pointer search
            while (left < right) {
                int currentSum = nums[i] + nums[left] + nums[right];
                int currentDifference = abs(currentSum - target);

                // Update closest sum if necessary
                if (currentDifference < minDifference) {
                    closestSum = currentSum;
                    minDifference = currentDifference;
                }

                // Move pointers based on the current sum relative to the target
                if (currentSum < target) {
                    left++;
                } else if (currentSum > target) {
                    right--;
                } else {
                    // If the current sum is equal to the target, return it immediately
                    return currentSum;
                }
            }
        }

        return closestSum;
    }
};

```

-   Sorting the array will take `O(N* logN)`. Overall, the function will take `O(N * logN + N^2)`, which is asymptotically equivalent to `O(N^2)`
-   The above algorithm’s <b>space complexity</b> will be `O(N)`, which is required for sorting.

## Triplets with Smaller Sum (medium)

https://leetcode.com/problems/3sum-smaller/

> Given an array `arr` of unsorted numbers and a `target` sum, count all triplets in it such that `arr[i] + arr[j] + arr[k] < target` where `i`, `j`, and `k` are three different indices. Write a function to return the count of such triplets.

This problem follows the <b>Two Pointers pattern</b> and shares similarities with <b>Triplet Sum to Zero</b>. The only difference is that, in this problem, we need to find the triplets whose sum is less than the given target. To meet the condition `i != j != k` we need to make sure that each number is not used more than once.

Following a similar approach, first, we can sort the array and then iterate through it, taking one number at a time. Let’s say during our iteration we are at number `X`, so we need to find `Y` and `Z` such that `X + Y + Z < target`. At this stage, our problem translates into finding a pair whose sum is less than `“target - X”` (as from the above equation `Y + Z == target - X`). We can use a similar approach as discussed in <b>Triplet Sum to Zero</b>.

```cpp
int searchPair(const vector<int>& arr, int targetSum, int first) {
    int count = 0;
    int start = first + 1;
    int end = arr.size() - 1;

    while (start < end) {
        if (arr[start] + arr[end] < targetSum) {
            // We found a triplet
            // Since arr[end] >= arr[start], we can replace arr[end]
            // by any number between start and end to get a sum less than the targetSum
            count += end - start;
            start++;
        } else {
            // We need a pair with a smaller sum
            end--;
        }
    }

    return count;
}

int tripletWithSmallerSum(vector<int>& arr, int target) {
    // Sort the array
    sort(arr.begin(), arr.end());
    int count = 0;

    // Iterate through the array
    for (int i = 0; i < arr.size() - 2; i++) {
        count += searchPair(arr, target - arr[i], i);
    }

    return count;
}
```

-   Sorting the array will take `O(N * logN)`. The `searchPair()` will take `O(N)`. So, overall `searchTriplets()` will take `O(N * logN + N^2)`, which is asymptotically equivalent to `O(N^2)`.
-   The <b>space complexity</b> of the above algorithm will be `O(N)` which is required for sorting if we are not using an </i>in-place</i> sorting algorithm.

> Write a function to return the list of all such triplets instead of the count. How will the <b>time complexity</b> change in this case?

```cpp
void searchPair(const vector<int>& arr, int targetSum, int first, vector<vector<int>>& triplets) {
    int start = first + 1;
    int end = arr.size() - 1;

    while (start < end) {
        if (arr[start] + arr[end] < targetSum) {
            // We found a triplet
            // Since arr[end] >= arr[start], we can replace arr[end]
            // by any number between start and end to get a sum less than the targetSum
            for (int i = end; i > start; i--) {
                triplets.push_back({arr[first], arr[start], arr[i]});
            }
            start++;
        } else {
            // We need a pair with a smaller sum
            end--;
        }
    }
}

vector<vector<int>> tripletWithSmallerSum(vector<int>& arr, int target) {
    // Sort the array
    sort(arr.begin(), arr.end());
    vector<vector<int>> triplets;

    // Iterate through the array
    for (int i = 0; i < arr.size() - 2; i++) {
        searchPair(arr, target - arr[i], i, triplets);
    }

    return triplets;
}
```

-   Sorting the array will take `O(N * logN)`. The `searchPair()`, in this case, will take `O(N^2)`; the main while loop will run in `O(N)` but the nested for loop can also take `O(N)` - this will happen when the target sum is bigger than every triplet in the array. So, overall `searchTriplets()` will take `O(N * logN + N^3)`, which is asymptotically equivalent to `O(N^3)`.
-   Ignoring the space required for the output array, the <b>space complexity</b> of the above algorithm will be `O(N)` which is required for sorting.

## 🌟 Subarrays with Product Less than a Target (medium)

https://leetcode.com/problems/subarray-product-less-than-k/

> Given an array with positive numbers and a `targetSum`, find all of its contiguous subarrays whose <b>product is less than the `targetSum`</b>.

This problem follows the <b>Sliding Window</b> and the <b>Two Pointers</b> pattern and shares similarities with <b>[Triplets with Smaller Sum](#triplets-with-smaller-sum-medium)</b> with two differences:

1. In this problem, the input array is not sorted.
2. Instead of finding triplets with sum less than a target, we need to find all subarrays having a product less than the target.
   The implementation will be quite similar to <b>[Triplets with Smaller Sum](#triplets-with-smaller-sum-medium)</b>.

```cpp
int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = size(nums), cnt=0;
        if (k <= 1) {
            return 0; // If k is less than or equal to 1, return 0 since no product can be less than k.
        }
        int i=0, j=0, prod=1;
        while(j < n){
            prod *= nums[j];
            while(prod >= k){
                prod /= nums[i];
                i++;
            }
            cnt += j - i + 1;
            j++;
        }


        return cnt;
    }
```

-   The main for-loop managing the sliding window takes `O(N)` but creating subarrays can take up to `O(N^2)` in the worst case. Therefore overall, our algorithm will take `O(N^3)`.
-   Ignoring the space required for the output list, the algorithm runs in `O(N)` space which is used for the temp list.

## Dutch National Flag Problem (medium)

https://leetcode.com/problems/sort-colors/

> Given an array containing `0`s, `1`s and `2`s, sort the array </i>in-place</i>. You should treat numbers of the array as objects, hence, we can’t count `0`s, `1`s, and `2`s to recreate the array.

The flag of the Netherlands consists of three colors: red, white and blue; and since our input array also consists of three different numbers that is why it is called <b>Dutch National Flag problem</b>.

The brute force solution will be to use an <i>in-place</i> sorting algorithm like <i>Heapsort</i> which will take `O(N*logN)`. Can we do better than this? Is it possible to sort the array in one iteration?

We can use a <b>Two Pointers</b> approach while iterating through the array. Let’s say the <b>two pointers</b> are called `low` and `high` which are pointing to the first and the last element of the array respectively. So while iterating, we will move all `0`s before `low` and all `2`s after `high` so that in the end, all `1`s will be between `low` and `high`.

```cpp
void sortColors(vector<int>& arr) {
        // //Dutch National Flag Algorithm
         int n = arr.size();
        // int l=0,m=0,h=n-1;
        // //do untill u not get unsorted section
        // while(m<=h){
        //     if(nums[m]==0) {swap(nums[l],nums[m]);l++;m++;}
        //     else if(nums[m]==1) {m++;}
        //     else{swap(nums[m],nums[h]);h--;}
        // }
        int low = 0, mid = 0, high = n - 1; // 3 pointers

        while (mid <= high) {
            if (arr[mid] == 0) {
                swap(arr[low], arr[mid]);
                low++;
                mid++;
            }
            else if (arr[mid] == 1) {
                mid++;
             }
            else {
                swap(arr[mid], arr[high]);
                high--;
             }
        }
    }
```

-   The <b>time complexity</b> of the above algorithm will be `O(N)` as we are iterating the input array only once.
-   The algorithm runs in constant space `O(1)`.

## 🌟 Quadruple Sum to Target (medium)

https://leetcode.com/problems/4sum/

> Given an array of unsorted numbers and a `targetSum`, find all <b>unique quadruplets</b> in it, whose <b>sum is equal to the `targetSum`</b>.

This problem follows the <b>Two Pointers</b> pattern and shares similarities with <b>[Triplet Sum to Zero](#🌟-triplet-sum-to-zero-medium)</b>.

We can follow a similar approach to iterate through the array, taking one number at a time. At every step during the iteration, we will search for the quadruplets similar to <b>Triplet Sum to Zero</b> whose sum is equal to the given `target`.

### Way-1

```cpp
void searchPairs(const vector<int>& arr, int targetSum, int first, int second, vector<vector<int>>& quads) {
    int start = second + 1;
    int end = arr.size() - 1;

    while (start < end) {
        int sum = arr[first] + arr[second] + arr[start] + arr[end];
        if (sum == targetSum) {
            // Found the quadruplet
            quads.push_back({arr[first], arr[second], arr[start], arr[end]});
            start++;
            end--;

            // Skip the same element to avoid duplicate quadruplets
            while (start < end && arr[start] == arr[start - 1]) {
                start++;
            }
            while (start < end && arr[end] == arr[end + 1]) {
                end--;
            }
        } else if (sum < targetSum) {
            // We need a pair with a bigger sum
            start++;
        } else {
            // We need a pair with a smaller sum
            end--;
        }
    }
}

// Function to search for quadruplets that sum up to the target sum
vector<vector<int>> searchQuads(vector<int>& arr, int target) {
    // Sort the array
    sort(arr.begin(), arr.end());
    vector<vector<int>> quads;

    // Iterate through the array
    for (int i = 0; i < arr.size() - 3; i++) {
        // Skip the same element to avoid duplicate quadruplets
        if (i > 0 && arr[i] == arr[i - 1]) {
            continue;
        }
        for (int j = i + 1; j < arr.size() - 2; j++) {
            // Skip the same element to avoid duplicate quadruplets
            if (j > i + 1 && arr[j] == arr[j - 1]) {
                continue;
            }
            // Search for pairs to form quadruplets
            searchPairs(arr, target, i, j, quads);
        }
    }
    return quads;
}
```

### Way-2

```cpp
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(begin(nums), end(nums));
        vector<vector<int>> res;
        set<vector<int>> s;
        int n = size(nums);
        for(int i=0; i<n-3; ++i){
            for(int j=i+1; j<n-2; ++j){
                long long newT = (long long)target - (long long)nums[i] - (long long)nums[j];
                int l = j+1, h = n-1;
                while(l < h){
                    if(nums[l] + nums[h] > newT){
                        h--;
                    }else if(nums[l] + nums[h] < newT){
                        l++;
                    }else{
                        s.insert({nums[i], nums[j], nums[l], nums[h]});
                        l++;
                        h--;
                    }
                }
            }
        }

        for(auto i: s){
            res.push_back(i);
        }
        return res;
    }
};
```

-   Sorting the array will take `O(N*logN)`. Overall `searchQuads()` will take `O(N * logN + N³)`, which is asymptotically equivalent to `O(N³)`.
-   The <b>space complexity</b> of the above algorithm will be `O(N)` which is required for sorting.

## 🌟 Comparing Strings containing Backspaces (medium)

https://leetcode.com/problems/backspace-string-compare/

> Given two strings containing backspaces (identified by the character `#`), check if the two strings are equal.

To compare the given strings, first, we need to apply the backspaces. An efficient way to do this would be from the end of both the strings. We can have separate pointers, pointing to the last element of the given strings. We can start comparing the characters pointed out by both the pointers to see if the strings are equal. If, at any stage, the character pointed out by any of the pointers is a backspace (`#`), we will skip and apply the backspace until we have a valid character available for comparison.

```cpp
bool backspaceCompare(string s, string t) {
        int i = s.size() - 1;
        int j = t.size() - 1;

        while (i >= 0 || j >= 0) {
            // Process backspaces in s
            int backspaceCount = 0;
            while (i >= 0) {
                if (s[i] == '#') {
                    backspaceCount++;
                    i--;
                } else if (backspaceCount > 0) {
                    backspaceCount--;
                    i--;
                } else {
                    break;
                }
            }

            // Process backspaces in t
            backspaceCount = 0;
            while (j >= 0) {
                if (t[j] == '#') {
                    backspaceCount++;
                    j--;
                } else if (backspaceCount > 0) {
                    backspaceCount--;
                    j--;
                } else {
                    break;
                }
            }

            // Compare characters
            if (i >= 0 && j >= 0 && s[i] != t[j]) {
                return false;
            }

            // If one string is exhausted and the other is not
            if ((i >= 0) != (j >= 0)) {
                return false;
            }

            // Move to the next character
            i--;
            j--;
        }

        // If both pointers reach the beginning and the loop ends, the strings match
        return true;
    }
```

-   The <b>time complexity</b> of the above algorithm will be `O(M+N)` where `M` and `N` are the lengths of the two input strings respectively.
-   The algorithm runs in constant space `O(1)`.

## 🌟 Minimum Window Sort (medium)

https://leetcode.com/problems/shortest-subarray-to-be-removed-to-make-array-sorted/

> Given an array, find the length of the smallest subarray in it which when sorted will sort the whole array.

As we know, once an array is sorted (in ascending order), the smallest number is at the beginning and the largest number is at the end of the array. So if we start from the beginning of the array to find the first element which is out of sorting order i.e., which is smaller than its previous element, and similarly from the end of array to find the first element which is bigger than its previous element, will sorting the subarray between these two numbers result in the whole array being sorted?

Let’s try to understand this with the Example mentioned above. In the following array, what are the first numbers out of sorting order from the beginning and the end of the array:

```
[1, 3, 2, 0, -1, 7, 10]
```

Starting from the beginning of the array the first number out of the sorting order is `2` as it is smaller than its previous element which is `3`.
Starting from the end of the array the first number out of the sorting order is `0` as it is bigger than its previous element which is `-1`

As you can see, sorting the numbers between `3` and `-1` will not sort the whole array. To see this, the following will be our original array after the sorted subarray:

```
[1, -1, 0, 2, 3, 7, 10]
```

The problem here is that the smallest number of our subarray is `-1` which dictates that we need to include more numbers from the beginning of the array to make the whole array sorted. We will have a similar problem if the maximum of the subarray is bigger than some elements at the end of the array. To sort the whole array we need to include all such elements that are smaller than the biggest element of the subarray. So our final algorithm will look like:

1. From the beginning and end of the array, find the first elements that are out of the sorting order. The two elements will be our candidate subarray.
2. Find the maximum and minimum of this subarray.
3. Extend the subarray from beginning to include any number which is bigger than the minimum of the subarray.
4. Similarly, extend the subarray from the end to include any number which is smaller than the maximum of the subarray.

```cpp
class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& a) {
        int n = a.size();
        int low = 0, high = n-1;

        while( low+1 < n and a[low] <= a[low+1])
            low++;

        if(low == n-1) return 0;

        while(high > low and  a[high] >= a[high-1])
            high--;

        int ans = min(n-low-1, high);

        int i = 0, j = high;

        while(i<=low and j<n){
            if(a[i] <= a[j]){
                ans=min(ans, j-i-1);
                i++;
            }
            else
                j++;
        }

        return ans;
    }
};
```

-   The <b>time complexity</b> of the above algorithm will be `O(N)`.
-   The algorithm runs in constant space `O(1)`.
