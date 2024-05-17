# Modified Binary Search

As we know, whenever we are given a sorted <b>Array</b> or <b>LinkedList</b> or <b>Matrix</b>, and we are asked to find a certain element, the best algorithm we can use is the <b>Binary Search</b>.

## Order-agnostic Binary Search (easy)

https://leetcode.com/problems/binary-search/

> Given a sorted array of numbers, find if a given number `key` is present in the array. Though we know that the array is sorted, we don’t know if it’s sorted in ascending or descending order. You should assume that the array can have duplicates.
>
> Write a function to return the index of the `key` if it is present in the array, otherwise return `-1`.

To make things simple, let’s first solve this problem assuming that the input array is sorted in ascending order. Here are the set of steps for <b>Binary Search</b>:

1. Let’s assume `start` is pointing to the first index and `end` is pointing to the last index of the input array (let’s call it `arr`). This means:

```
    int start = 0;
    int end = arr.length - 1;
```

2. First, we will find the `middle` of `start` and `end`. An easy way to find the middle would be: <i>middle=(start+end)/2</i>. The safest way to find the middle of two numbers without getting an overflow is as follows:

```
     middle  = start + (end-start)/2
```

3. Next, we will see if the `key` is equal to the number at index `middle`. If it is equal we return `middle` as the required index.
4. If `key` is not equal to number at index middle, we have to check two things:

-   If `key < arr[middle]`, then we can conclude that the `key` will be smaller than all the numbers after index `middle` as the array is sorted in the ascending order. Hence, we can reduce our search to `end = mid - 1`.
-   If `key > arr[middle]`, then we can conclude that the `key` will be greater than all numbers before index `middle` as the array is sorted in the ascending order. Hence, we can reduce our search to `start = mid + 1`.
-   We will repeat steps 2-4 with new ranges of `start` to `end`. If at any time `start` becomes greater than `end`, this means that we can’t find the `key` in the input array and we must return `-1`.

If the array is sorted in the descending order, we have to update the step 4 above as:

-   If `key > arr[middle]`, then we can conclude that the `key` will be greater than all numbers after index `middle` as the array is sorted in the descending order. Hence, we can reduce our search to `end = mid - 1`.
-   If `key < arr[middle]`, then we can conclude that the `key` will be smaller than all the numbers before index `middle` as the array is sorted in the descending order. Hence, we can reduce our search to `start = mid + 1`.
    Finally, how can we figure out the sort order of the input array? We can compare the numbers pointed out by `start` and `end` index to find the sort order. If `arr[start] < arr[end]`, it means that the numbers are sorted in ascending order otherwise they are sorted in the descending order.

```cpp
#include <iostream>
#include <vector>

int binarySearch(const std::vector<int>& arr, int key) {
    int start = 0;
    int end = arr.size() - 1;

    // Check to see if arr is sorted ascending or descending
    bool isAscending = arr[start] < arr[end];

    while (start <= end) {
        // Calculate the middle of the current range
        int middle = start + (end - start) / 2;

        if (key == arr[middle]) {
            return middle;
        }

        if (isAscending) {
            // Ascending order
            if (key < arr[middle]) {
                // The key can be in the first half
                end = middle - 1;
            } else {
                // Key > arr[middle], so the key can be in the second half
                start = middle + 1;
            }
        } else {
            // Descending order
            if (key > arr[middle]) {
                // The key can be in the first half
                end = middle - 1;
            } else {
                // Key < arr[middle], the key can be in the second half
                start = middle + 1;
            }
        }
    }

    // Key not found
    return -1;
}

int main() {
    std::vector<int> arr1 = {4, 6, 10};
    std::vector<int> arr2 = {1, 2, 3, 4, 5, 6, 7};
    std::vector<int> arr3 = {10, 6, 4};

    std::cout << "Index of key 10 in arr1: " << binarySearch(arr1, 10) << std::endl; // Output should be 2
    std::cout << "Index of key 5 in arr2: " << binarySearch(arr2, 5) << std::endl; // Output should be 4
    std::cout << "Index of key 10 in arr3: " << binarySearch(arr3, 10) << std::endl; // Output should be 0
    std::cout << "Index of key 4 in arr3: " << binarySearch(arr3, 4) << std::endl; // Output should be 2

    return 0;
}
```

-   Since, we are reducing the search range by half at every step, this means that the time complexity of our algorithm will be `O(log N)` where `N` is the total elements in the given array.
-   The algorithm runs in constant space `O(1)`.

## Ceiling of a Number (medium)

> Given an array of numbers sorted in an ascending order, find the ceiling of a given number `key`. The ceiling of the `key` will be the smallest element in the given array greater than or equal to the `key`.
>
> Write a function to return the index of the ceiling of the `key`. If there isn’t any ceiling return `-1`.

This problem follows the <b>Binary Search</b> pattern. Since <b>Binary Search</b> helps us find a number in a sorted array efficiently, we can use a modified version of the <b>Binary Search</b> to find the ceiling of a number.

We can use a similar approach as discussed in <b>Order-agnostic Binary Search</b>. We will try to search for the `key` in the given array. If we find the `key`, we return its `index` as the ceiling. If we can’t find the `key`, the next big number will be pointed out by the index `start`.

Since we are always adjusting our range to find the `key`, when we exit the loop, the start of our range will point to the smallest number greater than the `key` as shown in the above picture.

We can add a check in the beginning to see if the `key` is bigger than the biggest number in the input array. If so, we can return `-1`.

```cpp
#include <iostream>
#include <vector>

int searchCeilingOfNumber(const std::vector<int>& arr, int key) {
    int n = arr.size();
    int start = 0;
    int end = n - 1;

    if (key > arr[end]) {
        return -1;
    }

    while (start <= end) {
        int mid = start + (end - start) / 2;

        if (arr[mid] > key) {
            // Key is in the first half
            end = mid - 1;
        } else if (arr[mid] < key) {
            // Key is in the second half
            start = mid + 1;
        } else {
            // Found the key
            return mid;
        }
    }

    // Since the loop is running until 'start <= end', so at the end of the while loop, 'start == end + 1'
    // We are not able to find the element in the given array, so the next big number will be arr[start]
    return start;
}

int main() {
    std::vector<int> arr1 = {4, 6, 10};
    std::vector<int> arr2 = {1, 3, 8, 10, 15};
    std::vector<int> arr3 = {4, 6, 10};

    std::cout << "Index of ceiling of 6 in arr1: " << searchCeilingOfNumber(arr1, 6) << std::endl; // Output should be 1
    std::cout << "Index of ceiling of 12 in arr2: " << searchCeilingOfNumber(arr2, 12) << std::endl; // Output should be 4
    std::cout << "Index of ceiling of 17 in arr3: " << searchCeilingOfNumber(arr3, 17) << std::endl; // Output should be -1
    std::cout << "Index of ceiling of -1 in arr3: " << searchCeilingOfNumber(arr3, -1) << std::endl; // Output should be 0

    return 0;
}
```

## Floor Of a Number (medium)

```cpp
int searchFloorOfNumber(const std::vector<int>& arr, int key) {
    int start = 0;
    int end = arr.size() - 1;

    if (key < arr[start]) {
        return -1;
    }

    while (start <= end) {
        int mid = start + (end - start) / 2;

        if (key < arr[mid]) {
            // Key is in the first half
            end = mid - 1;
        } else if (key > arr[mid]) {
            // Key is in the second half
            start = mid + 1;
        } else {
            // Found the key
            return mid;
        }
    }

    // Since the loop is running until 'start <= end', so at the end of the while loop, 'start == end + 1'
    // We are not able to find the element in the given array, so the next smaller number will be arr[end]
    return end;
}
```

-   Since, we are reducing the search range by half at every step, this means that the time complexity of our algorithm will be `O(log N)` where `N` is the total elements in the given array.
-   The algorithm runs in constant space `O(1)`.

### Similar Problem

https://leetcode.com/problems/search-insert-position/

> Given an array of numbers sorted in ascending order, find the floor of a given number ‘key’. The floor of the ‘key’ will be the biggest element in the given array smaller than or equal to the ‘key’
>
> Write a function to return the index of the floor of the ‘key’. If there isn’t a floor, return -1.

```cpp
int searchInsert(vector<int>& nums, int target) {
        int l = 0, h = size(nums)-1;
        while(l <= h){
            int mid = l + (h-l)/2;
            if(nums[mid] == target){
                return mid;
            }else if(nums[mid] < target){
                l = mid+1;
            }else{
                h = mid-1;
            }
        }
        return l;
    }
```

-   Since, we are reducing the search range by half at every step, this means that the time complexity of our algorithm will be `O(log N)` where `N` is the total elements in the given array.
-   The algorithm runs in constant space `O(1)`.

## Next Letter (medium)

https://leetcode.com/problems/find-smallest-letter-greater-than-target/

> Given an array of lowercase letters sorted in ascending order, find the <b>smallest letter</b> in the given array <b>greater than a given `key`</b>.
>
> Assume the given array is a <b>circular list</b>, which means that the last letter is assumed to be connected with the first letter. This also means that the smallest letter in the given array is greater than the last letter of the array and is also the first letter of the array.
>
> Write a function to return the next letter of the given `key`.

The problem follows the <b>Binary Search</b> pattern. Since <b>Binary Search</b> helps us find an element in a sorted array efficiently, we can use a modified version of it to find the next letter.

We can use a similar approach as discussed in <b>Ceiling of a Number</b>. There are a couple of differences though:

1. The array is considered circular, which means if the `key` is bigger than the last letter of the array or if it is smaller than the first letter of the array, the `key`’s next letter will be the first letter of the array.
2. The other difference is that we have to find the next biggest letter which can’t be equal to the `key`. This means that we will ignore the case where `key == arr[middle]`. To handle this case, we can update our start range to `start = middle +1`.

In the end, instead of returning the element pointed out by start, we have to return the letter pointed out by `start % array.length`. This is needed because of point 2 discussed above. Imagine that the last letter of the array is equal to the `key`. In that case, we have to return the first letter of the input array.

```cpp
#include <iostream>
#include <vector>

char searchNextLetter(const std::vector<char>& letters, char key) {
    int n = letters.size();
    int start = 0;
    int end = n - 1;

    while (start <= end) {
        int mid = start + (end - start) / 2;

        // In the first half
        if (key < letters[mid]) {
            end = mid - 1;
        } else {
            // Key > letters[mid]
            // In the second half
            start = mid + 1;
        }
    }

    // Since the loop is running until 'start <= end', so at the end of the while loop, 'start == end + 1'
    return letters[start % n];
}

int main() {
    std::vector<char> letters1 = {'a', 'c', 'f', 'h'};
    std::vector<char> letters2 = {'a', 'c', 'f', 'h'};
    std::vector<char> letters3 = {'a', 'c', 'f', 'h'};
    std::vector<char> letters4 = {'a', 'c', 'f', 'h'};

    std::cout << "Next letter after 'f' in letters1: " << searchNextLetter(letters1, 'f') << std::endl; // Output should be 'h'
    std::cout << "Next letter after 'b' in letters2: " << searchNextLetter(letters2, 'b') << std::endl; // Output should be 'c'
    std::cout << "Next letter after 'm' in letters3: " << searchNextLetter(letters3, 'm') << std::endl; // Output should be 'a'
    std::cout << "Next letter after 'h' in letters4: " << searchNextLetter(letters4, 'h') << std::endl; // Output should be 'a'

    return 0;
}
```

-   Since, we are reducing the search range by half at every step, this means that the time complexity of our algorithm will be `O(log N)` where `N` is the total elements in the given array.
-   The algorithm runs in constant space `O(1)`.

## Number Range (medium)

https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

> Given an array of numbers sorted in ascending order, find the range of a given number `key`. The range of the `key` will be the first and last position of the `key` in the array.
>
> Write a function to return the range of the `key`. If the `key` is not present return `[-1, -1]`.
> The problem follows the <b>Binary Search</b> pattern. Since <b>Binary Search</b> helps us find a number in a sorted array efficiently, we can use a modified version of the <b>Binary Search</b> to find the first and the last position of a number.

We can use a similar approach as discussed in <b>Order-agnostic Binary Search</b>. We will try to search for the `key` in the given array; if the `key` is found (i.e. `key == arr[middle`) we have two options:

1. When trying to find the first position of the `key`, we can update `end = middle - 1` to see if the `key` is present before `middle`.
2. When trying to find the last position of the `key`, we can update `start = middle + 1` to see if the `key` is present after `middle`.
   In both cases, we will keep track of the last position where we found the `key`. These positions will be the required range.

```cpp
#include <iostream>
#include <vector>

int binarySearch(const std::vector<int>& arr, int key, bool findMaxIndex) {
    int keyIndex = -1;
    int start = 0;
    int end = arr.size() - 1;

    while (start <= end) {
        int mid = start + (end - start) / 2;

        if (key < arr[mid]) {
            end = mid - 1;
        } else if (key > arr[mid]) {
            start = mid + 1;
        } else {
            // key == arr[mid]
            keyIndex = mid;
            if (findMaxIndex) {
                // search ahead to find the last index of key
                start = mid + 1;
            } else {
                // search behind to find the first index of key
                end = mid - 1;
            }
        }
    }

    return keyIndex;
}

std::vector<int> findRange(const std::vector<int>& arr, int key) {
    std::vector<int> result(2, -1);
    result[0] = binarySearch(arr, key, false);

    if (result[0] != -1) {
        // no need to search if key is not present in the input array
        result[1] = binarySearch(arr, key, true);
    }
    return result;
}

int main() {
    std::vector<int> arr1 = {4, 6, 6, 6, 9};
    std::vector<int> arr2 = {1, 3, 8, 10, 15};
    std::vector<int> arr3 = {1, 3, 8, 10, 15};

    std::vector<int> result1 = findRange(arr1, 6);
    std::vector<int> result2 = findRange(arr2, 10);
    std::vector<int> result3 = findRange(arr3, 12);

    std::cout << "Range for 6 in arr1: [" << result1[0] << ", " << result1[1] << "]" << std::endl; // Output should be [1, 3]
    std::cout << "Range for 10 in arr2: [" << result2[0] << ", " << result2[1] << "]" << std::endl; // Output should be [3, 3]
    std::cout << "Range for 12 in arr3: [" << result3[0] << ", " << result3[1] << "]" << std::endl; // Output should be [-1, -1]

    return 0;
}
```

-   Since, we are reducing the search range by half at every step, this means that the time complexity of our algorithm will be `O(log N)` where `N` is the total elements in the given array.
-   The algorithm runs in constant space `O(1)`.

## Search in a Sorted Infinite Array (medium)

https://leetcode.com/problems/search-in-a-sorted-array-of-unknown-size/

> Given an infinite sorted array (or an array with unknown size), find if a given number `key` is present in the array. Write a function to return the index of the `key` if it is present in the array, otherwise return `-1`.
>
> Since it is not possible to define an array with infinite (unknown) size, you will be provided with an interface `ArrayReader` to read elements of the array. `ArrayReader.get(index)` will return the number at `index`; if the array’s size is smaller than the `index`, it will return `Integer.MAX_VALUE`.

The problem follows the <b>Binary Search</b> pattern. Since <b>Binary Search</b> helps us find a number in a sorted array efficiently, we can use a modified version of the <b>Binary Search</b> to find the `key` in an infinite sorted array.

The only issue with applying binary search in this problem is that we don’t know the bounds of the array. To handle this situation, we will first find the proper bounds of the array where we can perform a binary search.

An efficient way to find the proper bounds is to start at the beginning of the array with the bound’s size as `1` and exponentially increase the bound’s size (i.e., double it) until we find the bounds that can have the key.

```cpp
#include <iostream>
#include <vector>
#include <climits>

class ArrayReader {
public:
    ArrayReader(const std::vector<int>& arr) : arr(arr) {}

    int get(int index) const {
        if (index >= arr.size()) return INT_MAX;
        return arr[index];
    }

private:
    std::vector<int> arr;
};

int binarySearch(const ArrayReader& reader, int key, int start, int end) {
    while (start <= end) {
        int mid = start + (end - start) / 2;

        if (key < reader.get(mid)) {
            end = mid - 1;
        } else if (key > reader.get(mid)) {
            start = mid + 1;
        } else {
            // Found the key
            return mid;
        }
    }
    return -1;
}

int searchInInfiniteArray(const ArrayReader& reader, int key) {
    // 1. Find the proper bounds
    int start = 0;
    int end = 1;
    while (reader.get(end) < key) {
        int newStart = end + 1;
        end += (end - start + 1) * 2;

        // 2. Increase to double the bounds size
        start = newStart;
    }
    return binarySearch(reader, key, start, end);
}

int main() {
    ArrayReader reader1({4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30});
    std::cout << "Index of 11: " << searchInInfiniteArray(reader1, 11) << std::endl; // Output should be -1
    std::cout << "Index of 16: " << searchInInfiniteArray(reader1, 16) << std::endl; // Output should be 6

    ArrayReader reader2({1, 3, 8, 10, 15});
    std::cout << "Index of 15: " << searchInInfiniteArray(reader2, 15) << std::endl; // Output should be 4
    std::cout << "Index of 200: " << searchInInfiniteArray(reader2, 200) << std::endl; // Output should be -1

    return 0;
}
```

-   There are two parts of the algorithm. In the first part, we keep increasing the bound’s size exponentially (double it every time) while searching for the proper bounds. Therefore, this step will take `O(log N)` assuming that the array will have maximum `N` numbers. In the second step, we perform the binary search which will take `O(log N)`, so the overall time complexity of our algorithm will be` O(log N + log N)` which is asymptotically equivalent to `O(log N)`.

-   The algorithm runs in constant space `O(1)`.

## Minimum Difference Element (medium)

https://leetcode.com/problems/minimum-absolute-difference/

> Given an array of numbers sorted in ascending order, find the element in the array that has the minimum difference with the given `key`.

The problem follows the <b>Binary Search</b> pattern. Since <b>Binary Search</b> helps us find a number in a sorted array efficiently, we can use a modified version of the <b>Binary Search</b> to find the number that has the minimum difference with the given `key`.

We can use a similar approach as discussed in <b>Order-agnostic Binary Search</b>. We will try to search for the `key` in the given array. If we find the `key` we will return it as the minimum difference number. If we can’t find the `key`, (at the end of the loop) we can find the differences between the `key` and the numbers pointed out by indices `start` and `end`, as these two numbers will be closest to the `key`. The number that gives minimum difference will be our required number.

```cpp
#include <iostream>
#include <vector>
#include <cmath>

int searchMinDiffElement(const std::vector<int>& arr, int key) {
    int start = 0;
    int end = arr.size() - 1;

    if (key <= arr[start]) {
        return arr[start];
    } else if (key >= arr[end]) {
        return arr[end];
    }

    while (start <= end) {
        int mid = start + (end - start) / 2;

        if (key < arr[mid]) {
            end = mid - 1;
        } else if (key > arr[mid]) {
            start = mid + 1;
        } else {
            return arr[mid];
        }
    }

    // At the end of the while loop, 'start == end + 1'
    // We are not able to find the element in the given array
    // Return the element which is closest to the 'key'
    if (std::abs(arr[start] - key) < std::abs(key - arr[end])) {
        return arr[start];
    }
    return arr[end];
}

int main() {
    std::vector<int> arr1 = {4, 6, 10};
    std::vector<int> arr2 = {1, 3, 8, 10, 15};

    std::cout << "Closest element to 7: " << searchMinDiffElement(arr1, 7) << std::endl; // Output should be 6
    std::cout << "Closest element to 4: " << searchMinDiffElement(arr1, 4) << std::endl; // Output should be 4
    std::cout << "Closest element to 12: " << searchMinDiffElement(arr2, 12) << std::endl; // Output should be 10
    std::cout << "Closest element to 17: " << searchMinDiffElement(arr1, 17) << std::endl; // Output should be 10

    return 0;
}
```

-   Since, we are reducing the search range by half at every step, this means the time complexity of our algorithm will be `O(logN)` where `N` is the total elements in the given array.
-   The algorithm runs in constant space `O(1)`.

## Bitonic Array Maximum (easy)

> Find the maximum value in a given Bitonic array. An array is considered bitonic if it is monotonically increasing and then monotonically decreasing. Monotonically increasing or decreasing means that for any index `i` in the `array arr[i] != arr[i+1]`.

A <b>bitonic array</b> is a sorted array; the only difference is that its first part is sorted in <i>ascending order</i> and the second part is sorted in <i>descending order</i>. We can use a similar approach as discussed in <b>Order-agnostic Binary Search</b>. Since no two consecutive numbers are same (as the array is monotonically increasing or decreasing), whenever we calculate the `middle`, we can compare the numbers pointed out by the index `middle` and `middle+1` to find if we are in the ascending or the descending part. So:

1.  If `arr[middle] > arr[middle + 1]`, we are in the second (descending) part of the bitonic array. Therefore, our required number could either be pointed out by `middle` or will be before `middle`. This means we will be doing: `end = middle`.
2.  If `arr[middle] < arr[middle + 1]`, we are in the first (ascending) part of the bitonic array. Therefore, the required number will be after `middle`. This means we will be doing: `start = middle + 1`.

We can break when `start == end`. Due to the two points mentioned above, both `start` and `end` will be pointing at the maximum number of the bitonic array.

```cpp
function searchBitonicArray(arr, key) {
  const maxIndex = findMax(arr);
  const keyIndex = binarySearch(arr, key, 0, maxIndex);
  if (keyIndex !== -1) {
    return keyIndex;
  }

  return binarySearch(arr, key, maxIndex + 1, arr.length - 1);
}

//find index of the max value in bitonic array
function findMax(arr) {
  let start = 0;
  let end = arr.length - 1;

  while (start < end) {
    const mid = Math.floor(start + (end - start) / 2);

    if (arr[mid] > arr[mid + 1]) {
      end = mid;
    } else {
      //arr[mid] < arr[mid+1]
      start = mid + 1;
    }
  }
  //at the end of the while loop start === end
  return start;
}

//order-agnostic binary search
function binarySearch(arr, key, start, end) {
  //check to see if arr is sorted ascending or descending
  const isAscending = arr[start] < arr[end];

  while (start <= end) {
    //calculate the middle of the current range
    const middle = Math.floor(start + (end - start) / 2);

    if (key === arr[middle]) {
      return middle;
    }

    if (isAscending) {
      //ascending order
      if (key < arr[middle]) {
        //the key can be in the first half
        end = middle - 1;
      } else {
        //key > arr[middle], so the key can be in the
        //second half
        start = middle + 1;
      }
    } else {
      //descending order
      if (key > arr[middle]) {
        //the key can be in the first half
        end = middle - 1;
      } else {
        //key < arr[middle], the key can be in the
        //second half
        start = middle + 1;
      }
    }
  }

  // key not found
  return -1;
}

searchBitonicArray([1, 3, 8, 4, 3], 4);
//3
searchBitonicArray([3, 8, 3, 1], 8);
//1
searchBitonicArray([1, 3, 8, 12], 12);
//3
searchBitonicArray([10, 9, 8], 10);
//0
```

-   Since, we are reducing the search range by half at every step, this means the time complexity of our algorithm will be `O(logN)` where `N` is the total elements in the given array.
-   The algorithm runs in constant space `O(1)`.

## 🌟 Search Bitonic Array (medium)

> Given a Bitonic array, find if a given `key` is present in it. An array is considered bitonic if it is monotonically increasing and then monotonically decreasing. Monotonically increasing or decreasing means that for any index `i` in the array `arr[i] != arr[i+1]`.
>
> Write a function to return the index of the `key`. If the `key` is not present, return `-1`.

The problem follows the <b>Binary Search</b> pattern. Since <b>Binary Search</b> helps us efficiently find a number in a sorted array we can use a modified version of the <b>Binary Search</b> to find the `key` in the bitonic array.

Here is how we can search in a <b>bitonic array</b>:

1. First, we can find the index of the maximum value of the <b>bitonic array</b>, similar to <b>Bitonic Array Maximum</b>. Let’s call the index of the maximum number `maxIndex`.
2. Now, we can break the array into two sub-arrays:
    - Array from index `0` to `maxIndex`, sorted in ascending order.
    - Array from index `maxIndex+1` to `array_length-1`, sorted in descending order.
3. We can then call <b>Binary Search</b> separately in these two arrays to search the `key`. We can use the same <b>Order-agnostic Binary Search</b> for searching.

```cpp
#include <iostream>
#include <vector>

// Function to find the maximum element in a bitonic array
int findMax(const std::vector<int>& arr) {
    int start = 0;
    int end = arr.size() - 1;

    while (start < end) {
        int mid = start + (end - start) / 2;

        if (arr[mid] > arr[mid + 1]) {
            end = mid;
        } else {
            // arr[mid] < arr[mid + 1]
            start = mid + 1;
        }
    }
    // At the end of the while loop, start == end
    return start;
}

// Order-agnostic binary search
int binarySearch(const std::vector<int>& arr, int key, int start, int end) {
    bool isAscending = arr[start] < arr[end];

    while (start <= end) {
        int mid = start + (end - start) / 2;

        if (arr[mid] == key) {
            return mid;
        }

        if (isAscending) {
            // Ascending order
            if (key < arr[mid]) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        } else {
            // Descending order
            if (key > arr[mid]) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
    }

    // Key not found
    return -1;
}

// Function to search for a key in a bitonic array
int searchBitonicArray(const std::vector<int>& arr, int key) {
    int maxIndex = findMax(arr);
    int keyIndex = binarySearch(arr, key, 0, maxIndex);
    if (keyIndex != -1) {
        return keyIndex;
    }

    return binarySearch(arr, key, maxIndex + 1, arr.size() - 1);
}

int main() {
    std::vector<int> arr1 = {1, 3, 8, 4, 3};
    std::vector<int> arr2 = {3, 8, 3, 1};
    std::vector<int> arr3 = {1, 3, 8, 12};
    std::vector<int> arr4 = {10, 9, 8};

    std::cout << "Index of 4 in [1, 3, 8, 4, 3]: " << searchBitonicArray(arr1, 4) << std::endl; // Output should be 3
    std::cout << "Index of 8 in [3, 8, 3, 1]: " << searchBitonicArray(arr2, 8) << std::endl; // Output should be 1
    std::cout << "Index of 12 in [1, 3, 8, 12]: " << searchBitonicArray(arr3, 12) << std::endl; // Output should be 3
    std::cout << "Index of 10 in [10, 9, 8]: " << searchBitonicArray(arr4, 10) << std::endl; // Output should be 0

    return 0;
}
```

-   Since, we are reducing the search range by half at every step, this means the time complexity of our algorithm will be `O(logN)` where `N` is the total elements in the given array.
-   The algorithm runs in constant space `O(1)`.

## 🌟 Search in Rotated Array (medium)

https://leetcode.com/problems/search-in-rotated-sorted-array/

> Given an array of numbers which is sorted in ascending order and also rotated by some arbitrary number, find if a given ‘key’ is present in it.
>
> Write a function to return the index of the ‘key’ in the rotated array. If the ‘key’ is not present, return -1. You can assume that the given array does not have any duplicates.

The problem follows the <b>Binary Search</b> pattern. We can use a similar approach as discussed in <b>Order-agnostic Binary Search</b> and modify it similar to <b>Search Bitonic Array</b> to search for the `key` in the rotated array.

After calculating the middle, we can compare the numbers at indices `start` and `middle`. This will give us two options:

1. If `arr[start] <= arr[middle]`, the numbers from `start` to `middle` are sorted in ascending order.
2. Else, the numbers from `middle+1` to `end` are sorted in ascending order.

Once we know which part of the array is sorted, it is easy to adjust our ranges. For example, if option 1 is `true`, we have two choices:

1. By comparing the `key` with the numbers at index `start` and `middle` we can easily find out if the `key` lies between indices `start` and `middle`; if it does, we can skip the second part => `end = middle -1`.
2. Else, we can skip the first part => `start = middle + 1`.

Since there are no duplicates in the given array, it is always easy to skip one part of the array in each iteration. However, if there are duplicates, it is not always possible to know which part is sorted. We will look into this case in the <b>Similar Problems</b> section.

```cpp
#include <iostream>
#include <vector>

int searchRotatedArray(const std::vector<int>& arr, int key) {
    int start = 0;
    int end = arr.size() - 1;

    while (start <= end) {
        int mid = start + (end - start) / 2;

        if (arr[mid] == key) {
            return mid;
        }

        if (arr[start] <= arr[mid]) {
            // First half is sorted in ascending order
            if (key >= arr[start] && key < arr[mid]) {
                // The key can be in the first half
                end = mid - 1;
            } else {
                // Key > arr[mid], so the key can be in the second half
                start = mid + 1;
            }
        } else {
            // Second half is sorted in ascending order
            if (key > arr[mid] && key <= arr[end]) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
    }

    // Key not found
    return -1;
}

int main() {
    std::vector<int> arr1 = {10, 15, 1, 3, 8};
    std::vector<int> arr2 = {4, 5, 7, 9, 10, -1, 2};

    std::cout << "Index of 15 in [10, 15, 1, 3, 8]: " << searchRotatedArray(arr1, 15) << std::endl; // Output should be 1
    std::cout << "Index of 10 in [4, 5, 7, 9, 10, -1, 2]: " << searchRotatedArray(arr2, 10) << std::endl; // Output should be 4

    return 0;
}
```

-   Since, we are reducing the search range by half at every step, this means the time complexity of our algorithm will be `O(logN)` where `N` is the total elements in the given array.
-   The algorithm runs in constant space `O(1)`.

### Similar Problem

https://leetcode.com/problems/search-in-rotated-sorted-array-ii/

> How do we search in a sorted and rotated array that also has duplicates?
>
> The code above will fail in the following example!

The only problematic scenario is when the numbers at indices `start`, `middle`, and `end` are the same, as in this case, we can’t decide which part of the array is sorted. In such a case, the best we can do is to skip one number from both ends: `start = start + 1` & `end = end - 1`.

```cpp
#include <iostream>
#include <vector>

int searchRotatedArrayWithDuplicates(const std::vector<int>& arr, int key) {
    int start = 0;
    int end = arr.size() - 1;

    while (start <= end) {
        int mid = start + (end - start) / 2;

        if (arr[mid] == key) {
            return mid;
        }

        // The only difference from the previous solution,
        // if numbers at indexes start, mid, and end are same, we can't choose a side
        // the best we can do, is to skip one number from both ends as key != arr[mid]
        if (arr[start] == arr[mid] && arr[end] == arr[mid]) {
            ++start;
            --end;
        } else if (arr[start] <= arr[mid]) {
            // First half is sorted in ascending order
            if (key >= arr[start] && key < arr[mid]) {
                // The key can be in the first half
                end = mid - 1;
            } else {
                // Key > arr[mid], so the key can be in the second half
                start = mid + 1;
            }
        } else {
            // Second half is sorted in ascending order
            if (key > arr[mid] && key <= arr[end]) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
    }

    // Key not found
    return -1;
}

int main() {
    std::vector<int> arr1 = {3, 7, 3, 3, 3};
    std::cout << "Index of 7 in [3, 7, 3, 3, 3]: " << searchRotatedArrayWithDuplicates(arr1, 7) << std::endl; // Output should be 1

    std::vector<int> arr2 = {10, 15, 1, 3, 8};
    std::cout << "Index of 15 in [10, 15, 1, 3, 8]: " << searchRotatedArrayWithDuplicates(arr2, 15) << std::endl; // Output should be 1

    std::vector<int> arr3 = {4, 5, 7, 9, 10, -1, 2};
    std::cout << "Index of 10 in [4, 5, 7, 9, 10, -1, 2]: " << searchRotatedArrayWithDuplicates(arr3, 10) << std::endl; // Output should be 4

    std::vector<int> arr4 = {2, 5, 6, 0, 0, 1, 2};
    std::cout << "Index of 0 in [2, 5, 6, 0, 0, 1, 2]: " << searchRotatedArrayWithDuplicates(arr4, 0) << std::endl; // Output should be 3 or 4

    return 0;
}
```

-   This algorithm will run most of the times in `O(logN)`. However, since we only skip two numbers in case of duplicates instead of half of the numbers, the worst case time complexity will become `O(N)`.
-   The algorithm runs in constant space `O(1)`.

## 🌟 Rotation Count (medium)

https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/

> Given an array of numbers which is sorted in ascending order and is rotated ‘k’ times around a pivot, find ‘k’.
>
> You can assume that the array does not have any duplicates.

This problem follows the <b>Binary Search</b> pattern. We can use a similar strategy as discussed in <b>Search in Rotated Array</b>.

In this problem, actually, we are asked to find the index of the minimum element. The number of times the minimum element is moved to the right will be equal to the number of rotations. An interesting fact about the minimum element is that it is the only element in the given array which is smaller than its previous element. Since the array is sorted in ascending order, all other elements are bigger than their previous element.

After calculating the `middle`, we can compare the number at index `middle` with its `previous` and `next` number. This will give us two options:

1. If `arr[middle] > arr[middle + 1]`, then the element at `middle + 1` is the smallest.
2. If `arr[middle - 1] > arr[middle]`, then the element at `middle` is the smallest.

To adjust the ranges we can follow the same approach as discussed in <b>Search in Rotated Array</b>. Comparing the numbers at indices `start` and `middle` will give us two options:

1. If `arr[start] < arr[middle]`, the numbers from `start` to `middle` are sorted.
2. Else, the numbers from `middle + 1` to `end` are sorted.

```cpp
#include <iostream>
#include <vector>

int countRotations(const std::vector<int>& arr) {
    int start = 0;
    int end = arr.size() - 1;

    while (start < end) {
        int mid = start + (end - start) / 2;

        // if mid is greater than the next element
        if (mid < end && arr[mid] > arr[mid + 1]) {
            return mid + 1;
        }

        // if mid is smaller than the previous element
        if (mid > start && arr[mid - 1] > arr[mid]) {
            return mid;
        }

        // determine which half to search in
        if (arr[start] < arr[mid]) {
            // first half is sorted, so pivot is in the second half
            start = mid + 1;
        } else {
            // second half is sorted, so pivot is in the first half
            end = mid - 1;
        }
    }

    // if no rotation found
    return 0;
}

int main() {
    std::vector<int> arr1 = {10, 15, 1, 3, 8};
    std::cout << "Rotation count of [10, 15, 1, 3, 8]: " << countRotations(arr1) << std::endl; // Output should be 2

    std::vector<int> arr2 = {4, 5, 7, 9, 10, -1, 2};
    std::cout << "Rotation count of [4, 5, 7, 9, 10, -1, 2]: " << countRotations(arr2) << std::endl; // Output should be 5

    std::vector<int> arr3 = {1, 3, 8, 10};
    std::cout << "Rotation count of [1, 3, 8, 10]: " << countRotations(arr3) << std::endl; // Output should be 0

    return 0;
}
```

-   Since, we are reducing the search range by half at every step, this means the time complexity of our algorithm will be `O(logN)` where `N` is the total elements in the given array.
-   The algorithm runs in constant space `O(1)`.

### Similar Problem

https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/

> How do we find the rotation count of a sorted and rotated array that has duplicates too?
>
> The above code will fail on the following example!

We can follow the same approach as discussed in <b>Search in Rotated Array</b>. The only difference is that before incrementing `start` or decrementing `end`, we will check if either of them is the smallest number.

```cpp
#include <iostream>
#include <vector>

int countRotationsWithDuplicates(const std::vector<int>& arr) {
    int start = 0;
    int end = arr.size() - 1;

    while (start < end) {
        int mid = start + (end - start) / 2;

        // If mid is greater than the next element
        if (mid < end && arr[mid] > arr[mid + 1]) {
            return mid + 1;
        }

        // If mid is smaller than the previous element
        if (mid > start && arr[mid - 1] > arr[mid]) {
            return mid;
        }

        // If elements at start, mid, and end are equal, we cannot choose a side
        if (arr[start] == arr[mid] && arr[end] == arr[mid]) {
            // Skip one number from both ends
            if (arr[start] > arr[start + 1]) {
                return start + 1;
            }
            start++;
            if (arr[end - 1] > arr[end]) {
                return end;
            }
            end--;
        } else if (arr[start] < arr[mid] || (arr[start] == arr[mid] && arr[mid] > arr[end])) {
            // Left side is sorted, so the pivot is on the right side
            start = mid + 1;
        } else {
            // Right side is sorted, so the pivot is on the left side
            end = mid - 1;
        }
    }

    // If the array has not been rotated
    return 0;
}

int main() {
    std::vector<int> arr1 = {3, 3, 7, 3};
    std::cout << "Rotation count of [3, 3, 7, 3]: " << countRotationsWithDuplicates(arr1) << std::endl; // Output should be 3

    std::vector<int> arr2 = {10, 15, 1, 3, 8};
    std::cout << "Rotation count of [10, 15, 1, 3, 8]: " << countRotationsWithDuplicates(arr2) << std::endl; // Output should be 2

    std::vector<int> arr3 = {4, 5, 7, 9, 10, -1, 2};
    std::cout << "Rotation count of [4, 5, 7, 9, 10, -1, 2]: " << countRotationsWithDuplicates(arr3) << std::endl; // Output should be 5

    std::vector<int> arr4 = {1, 3, 8, 10};
    std::cout << "Rotation count of [1, 3, 8, 10]: " << countRotationsWithDuplicates(arr4) << std::endl; // Output should be 0

    return 0;
}
```

-   This algorithm will run in `O(logN)` most of the times, but since we only skip two numbers in case of duplicates instead of the half of the numbers, therefore the worst case time complexity will become `O(N)`.
-   The algorithm runs in constant space `O(1)`.
