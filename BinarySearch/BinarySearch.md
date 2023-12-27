# Introduction

Binary search divides the search space into half until we reach the result. As a result the time performance of binary search (log n) is considerably better than linear search (n). This means where linear search will take 10^6 steps, binary search will do it in only 17 steps.

Binary search usually works for sorted arrays. But don't make the mistake of assuming it works only on sorted arrays. A bigger question to ask is if the search space can be perceived as or converted into a monotonically increasing / decreasing function. Typically, you'll be asked to return a minimum value that satisfies a given condition or the maximum value that satisfies a given condition. We'll learn it as we go through the examples below.

**lower bound** -> the smallest index(i) such that the number arr[i] >= x
**upper bound** -> the smallest index(i) such that the number arr[i] > x

```
#include <bits/stdc++.h>
int main()
{
    std::vector<int> v{ 10, 20, 30, 30, 50 };

    // Print vector
    std::cout << "Vector contains :";
    for (unsigned int i = 0; i < v.size(); i++)
        std::cout << " " << v[i];
    std::cout << "\n";

    std::vector<int>::iterator low, upp;

    std::cout<<"******* lower_bound *********"<<std::endl;
    low = std::lower_bound(v.begin(), v.end(), 20);
    std::cout << "\nlower_bound for element 20 at position : " << (low - v.begin());
    low = std::lower_bound(v.begin(), v.end(), 25);
    std::cout << "\nlower_bound for element 25 at position : " << (low - v.begin())<<std::endl;


    std::cout<<"****** upper_bound ************"<<std::endl;
    upp = std::upper_bound(v.begin(), v.end(), 30);
    std::cout << "\nupper_bound for element 30 at position : " << (upp - v.begin());
     upp = std::upper_bound(v.begin(), v.end(), 25);
    std::cout << "\nupper_bound for element 25 at position : " << (upp - v.begin());

    return 0;
}
```

Output:
Vector contains : 10 20 30 30 50
**\*\*\***lower_bound\***\*\*\*\***
lower_bound for element 20 at position : 1
lower_bound for element 25 at position : 2
**\*\***upper_bound\***\*\*\*\*\*\*\***
upper_bound for element 30 at position : 4
upper_bound for element 25 at position : 2

---

1. upper bound return first element which is > value. If not, return end().
2. lower bound return first element which is ≥ value. If not, return end().

### Examples for set

```
#include <bits/stdc++.h>
using namespace std;
int main(){
   set<int> Set;
   Set.insert(9);
   Set.insert(7);
   Set.insert(5);
   Set.insert(3);
   Set.insert(1);
   cout<<"Elements are : ";
   for (auto i = Set.begin(); i!= Set.end(); i++)
      cout << *i << " ";
   cout<<"******* lower_bound *********"<<endl;
   auto i = Set.lower_bound(5);
   cout <<"\nlower bound of 5 in the set is: ";
   cout << (*i) << endl;
   i = Set.lower_bound(1);
   cout<<"lower bound of 1 in the set is: ";
   cout << (*i) << endl;
     i = Set.lower_bound(4);
   cout<<"lower bound of 4 in the set is: ";
   cout << (*i) << endl;

   cout<<"****** upper_bound ************"<<endl;
   i = Set.upper_bound(5);
   cout <<"\nupper bound of 5 in the set is: ";
   cout << (*i) << endl;
   i = Set.upper_bound(1);
   cout<<"upper bound of 1 in the set is: ";
   cout << (*i) << endl;
   i = Set.upper_bound(4);
   cout<<"upper bound of 4 in the set is: ";
   cout << (*i) << endl;

   return 0;
}
```

Output:
Elements are : 1 3 5 7 9
**\*\*\*** lower_bound \***\*\*\*\***
lower bound of 5 in the set is: 5
lower bound of 1 in the set is: 1
lower bound of 4 in the set is: 5
**\*\*** upper_bound \***\*\*\*\*\*\*\***
upper bound of 5 in the set is: 7
upper bound of 1 in the set is: 3
upper bound of 4 in the set is: 5

```
int lowerBound(const std::vector<int>& arr, int target) {
    int low = 0, high = arr.size() - 1, result = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] >= target) {
            result = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return result;
}

// Binary search implementation for upper bound
int upperBound(const std::vector<int>& arr, int target) {
    int low = 0, high = arr.size() - 1, result = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] > target) {
            result = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return result;
}
```

#### Template

I try to convert each binary search related problem in either of the two formats - minimization problem (minimize x such that condition(x) is true) or maximization problem (maximize x such that condition(x) is true). In both the cases we construct the condition(x) such that it is true for our answer.

```
// Minimize x such that condition(x) is true
int binarySearchMinimize(const std::vector<int>& arr) {
    int lo = -1, hi = arr.size();
    while (lo + 1 < hi) {
        int mid = lo + (hi - lo) / 2;
        if (condition(arr, mid)) {
            hi = mid;
        } else {
            lo = mid;
        }
    }
    return hi;
}

// Maximize x such that condition(x) is true
int binarySearchMaximize(const std::vector<int>& arr) {
    int lo = -1, hi = arr.size();
    while (lo + 1 < hi) {
        int mid = lo + (hi - lo) / 2;
        if (condition(arr, mid)) {
            lo = mid;
        } else {
            hi = mid;
        }
    }
    return lo;
}

bool condition(const std::vector<int>& arr, int idx) {
    // Some condition on arr[idx]
    // Return true or false
    return true;
}
```

#### Example

**Minimization** - Find first occurrance of an element in a sorted array with duplicates.
**Maximization** - Find last occurrance of an element in a sorted array with duplicates.

#### Notes

If you look at both the templates carefully. We can make the following observations:

In minimization template, hi contains the final answer.
In maximization template, lo contains the final answer.

In each of the template, the variable that contains the final answer (hi for minimization / lo for maximization), should be able to take all possible values in the search space. In other words, one variable always holds the answer (or the valid value) and the other variable holds the invalid value.

When we exit from while loop, lo and hi are adjacent to each other. (lo + 1 < hi) will not be true when lo + 1 === hi.

The while loop condition guarantees that you always will have at least three values in the search space (lo, mid, hi). Although, the way we initialize the values for lo and hi, only one of them holds a valid value at any point in time.

Q-1) [First Bad Version](https://leetcode.com/problems/first-bad-version/)

You are a product manager and currently leading a team to develop a new product. Unfortunately, the latest version of your product fails the quality check. Since each version is developed based on the previous version, all the versions after a bad version are also bad.

Suppose you have n versions [1, 2, ..., n] and you want to find out which one is the first bad one, which causes all the following versions to be bad. You are given an API bool isBadVersion(version) which will return whether version is bad. Implement a function to find the first bad version. You should minimize the number of calls to the API.

#### Solution

Let's decide a few things / make some observations before jumpting into the solution:

Our search space is monotonically increasing. If a version fails, then all versions after it also fail.
Any version starting from 1 to n could be bad. This means our search space is [1, n] (inclusive).
We want to find the first bad version. If the condition inside the while loop is going to be isBadVersion(version), then we can see that we want to find the minimum version, such that isBadVersion(version) is true. This is the minimization template.
In minimization template, hi gives the final answer. So we initialize lo to a value that is going to be invalid. We initialize hi to a value that is going to be maximum in the search space.

lo = 0, hi = n;
type: minimization problem
range: lo -> invalid (0), hi -> valid (1 to n)
initialize: lo to 0, hi to n.
condition: f(x) = isBadVersion(x)

```
 int firstBadVersion(int n) {
        int lo = 0, hi = n;
        while(lo+1 < hi){
            int mid = lo + (hi-lo)/2;
            if(isBadVersion(mid)){
                hi = mid;
            }else{
                lo = mid;
            }
        }
        return hi;
    }
```

Q-2) [Search Insert Position](https://leetcode.com/problems/search-insert-position/)

Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

#### Solution

It is a minimization problem. The target can be placed anywhere between 0 index and arr.length (after the last element).
We want to find first such position where the condition the number is greater or equal to target is true.

type: minimization problem
range: lo -> invalid (-1), hi -> valid (0 to nums.length)
initialize: lo to -1, hi to nums.length
condition: f(x) = x >= target

```
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int lo = -1, hi = nums.size();
        while(lo + 1 < hi){
            int mid = lo + (hi-lo)/2;
            if(nums[mid] == target) return mid;
            else if (nums[mid] > target) hi = mid;
            else lo = mid;
        }
        return hi;
    }
};
```

Q-3) [Find First and Last Position of Element in Sorted Array](https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/)

Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.

The array can contain duplicates, or it is possible that the element is not present in the array.

#### Solution

Find **first occurrance** of the element.
type: minimization problem
range: lo -> invalid (-1), hi -> valid (0 - nums.length)
initialize: lo to -1, hi to nums.length. If the hi remains unchanged till the end, we know that the element doesn't exist and we can return -1, otherwise we return hi.
condition: f(x) = x >= target

Find the **last occurrance** of the element.
type: maximization problem
range: lo -> valid (-1 to nums.length - 1), hi -> invalid (nums.length)
initialize lo to -1, hi to nums.length
if the lo remains unchanged till the end, we know that the element doesn't exist
we can return lo (because when it is unchanged, it is already -1)
condition: f(x) = x <= target

```
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = firstOcc(nums, target);
        int last = lastOcc(nums,target);
        return {first, last};
    }
    int firstOcc(vector<int> nums, int x){
        int lo = -1, hi = nums.size();
        while(lo +1 < hi){
            int mid = lo + (hi-lo)/2;
            if(nums[mid] >= x) hi = mid;
            else lo = mid;
        }
        return (hi < nums.size() && nums[hi] == x) ? hi : -1;;
    }
    int lastOcc(vector<int> nums, int x){
        int lo = -1, hi = nums.size();
        while(lo +1 < hi){
            int mid = lo + (hi-lo)/2;
            if(nums[mid] <= x) lo = mid;
            else hi = mid;
        }
        return (lo >= 0 && nums[lo] == x) ? lo : -1;;
    }
};
```

Q-4) [Check If a Number Is Majority Element in a Sorted Array]()
Given an array nums sorted in non-decreasing order, there is a special number in the array nums, which is unique in the array and occurs at least twice. Find the number if it exists in the array.

Solution
Because the array is sorted, a majority element will occur multiple times at adjacent locations to each other. If we can find the index of the first occurrance of the target, and the last occurrance of the target. We can say that the element is a majority element if the distance between the first and last occurrance is greater than n / 2.

In another words, we can use findRange function above on the target element. If the return range is greater than n / 2, then the element is a majority element.

```
std::vector<int> findRange(const std::vector<int>& nums, int target) {
    int lo = -1, hi = nums.size();
    while (lo + 1 < hi) {
        int mid = lo + (hi - lo) / 2;
        if (nums[mid] < target) {
            lo = mid;
        } else {
            hi = mid;
        }
    }
    int firstOccurrence = hi;

    lo = -1, hi = nums.size();
    while (lo + 1 < hi) {
        int mid = lo + (hi - lo) / 2;
        if (nums[mid] <= target) {
            lo = mid;
        } else {
            hi = mid;
        }
    }
    int lastOccurrence = lo;

    if (firstOccurrence <= lastOccurrence) {
        return {firstOccurrence, lastOccurrence};
    } else {
        return {-1, -1}; // Not found
    }
}

bool findMajorityElement(const std::vector<int>& nums, int target) {
    std::vector<int> range = findRange(nums, target);
    if (range[0] == -1) {
        return false;
    }

    int rangeLength = range[1] - range[0] + 1;
    return (rangeLength > nums.size() / 2);
}
```

Q-5) [Find Smallest Letter Greater Than Target](https://leetcode.com/problems/find-smallest-letter-greater-than-target/description/)
Given a list of sorted characters letters containing only lowercase letters, and given a target letter target, find the smallest element in the list that is larger than the given target.

#### Solution

type: minimization problem
range: lo -> invalid (-1), hi -> valid (0 - letters.length)
initialize: lo to -1, hi to letters.length
if the hi remains unchanged till the end, we wrap it around and answer 0.
condition: f(x) = x > target

```
class Solution {
public:
    char nextGreatestLetter(std::vector<char>& letters, char target) {
        int lo = -1, hi = letters.size();
        while (lo + 1 < hi) {
            int mid = lo + (hi - lo) / 2;
            if (letters[mid] > target) {
                hi = mid;
            } else {
                lo = mid;
            }
        }
        return (hi == letters.size()) ? letters[0] : letters[hi];
    }
};
```

Q-6) [Arranging Coins](https://leetcode.com/problems/arranging-coins/description/)
You have n coins that you want to form in a staircase shape. The staircase consists of n levels, and the i-th level has i coins. The last row of the staircase may be incomplete.

Given the integer n, return the number of full staircase rows that can be formed.

Solution
Every level has one more than the previous level. If there are 5 full rows, it'll look something like this
[1, 2, 3, 4, 5] - first row has 1 coin, second row has 2 coins, third row has 3 coins, fourth row has 4 coins, and fifth row has 5 coins.

Let's say there are k complete, and 0 incomplete rows. Then the total number of coins would be k \* (k + 1) / 2.

According to the problem, there could be at most 1 incomplete row at the end. We already know that the toal number of coins is n.

So, the condition that should hold true is:

f(k) = k \* (k + 1) / 2 <= n and we want to maximize k. It is clear that it is a maximization problem. So, lo will hold the valid value and hi will hold the invalid value.

Let's summarize our understanding here.

type: maximization
range: lo -> valid (1), hi -> invalid (n + 1). the number of rows will always be smaller than the number of coins + 1.
initialize: lo to 1, hi to n + 1
condition: f(k) = k \* (k + 1) / 2 <= n

```
class Solution {
public:
long long coinCountInRows(long long rowCount) {
    return rowCount * (rowCount + 1) / 2;
}

long long arrangeCoins(long long n) {
    long long lo = 1, hi = n + 1;
    while (lo + 1 < hi) {
        long long mid = lo + (hi - lo) / 2;
        if (coinCountInRows(mid) <= n) {
            lo = mid;
        } else {
            hi = mid;
        }
    }
    return lo;
}
};
```

Q-7) [Find Minimum in Rotated Sorted Array](https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/)
Suppose an array of unique integers sorted in ascending order is rotated at some pivot unknown to you beforehand. (i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).

Find index of the minimum element.

#### Solution

If the array was not rotated, we could simply return the first element of the array. In this case the array has been rotated, which means it is sorted until the pivot. And then it is sorted after the pivot. It is not sorted at the pivot.

We want to find a monotonic function here. This function will map the array elements to a series of boolean values. These values will be a series of false values followed by true values for each of the indices.

Turns out, we can. For a rotated sorted array, we can compare each element with the last element of the array. If the current value is less than or equal to the last value, then we know that we are on the right side of the pivot. If the current value is greater than the last value, then we know that we are on the left side of the pivot.

Example:
arr = [4,5,6,7,0,1,2]
isOnRight = [false, false, false, false, true, true, true]

Here, the pivot is between 7 and 0. This means, 0, 1, 2 are on the right side of the pivot, and 4, 5, 6, 7 are on the left side of the pivot. So, isOnRight function will return true for 0, 1, 2. The first element is 0, which is also our answer.

The minimum value is the first value on the right side of the pivot.

type: minimization problem
range: lo -> invalid (-1), hi -> valid (0 - nums.length - 1)
initialize: lo to -1, hi to nums.length - 1
condition: f(x) = x <= nums[nums.length - 1]

```
class Solution {
public:
    int findMin(vector<int>& nums) {
        int lo=-1,hi = nums.size()-1;
        while(lo+1<hi){
            int mid = lo + (hi-lo)/2;
            if(nums[mid] <= nums[nums.size()-1]){
                hi = mid;
            }else{
                lo = mid;
            }
        }
        return nums[hi];
    }
};
```

Q-8) [Search in Rotated Sorted Array](https://leetcode.com/problems/search-in-rotated-sorted-array/)
In the previous question, you found the minimum number in a rotated sorted array. In this one, you need to find a target value in this array.

#### Solution

For solving this question, let's find the index of the minimum element first. Once we know the index, we can either search for the element on the left side of the pivot or the right side of the pivot. This would be decided based on whether the target is smaller than the right most element or not.

```
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int k = findPivot(nums,target);
        int lo=0,hi=nums.size()-1;
        int x = binarySearch(lo,k-1,target,nums);
        int y = binarySearch(k,hi,target,nums);
        return x != -1 ? x : y;
    }
private:
    int findPivot(vector<int>& nums, int target){
        int lo = -1, hi = nums.size()-1;
        while(lo+1<hi){
            int mid = lo + (hi-lo)/2;
            if(nums[mid] <= nums[hi]) hi = mid;
            else lo = mid;
        }
        return hi;
    }
    int binarySearch(int lo, int hi, int target, vector<int>& nums){
        while(lo<=hi){
            int mid = lo+(hi-lo)/2;
            if(nums[mid] == target) return mid;
            else if(nums[mid] < target) lo=mid+1;
            else hi = mid-1;

        }return -1;
    }
};
```

Q-9) [Find Peak Element](https://leetcode.com/problems/find-peak-element/description/)
A peak element is an element that is greater than its neighbors.

Given a 0-indexed array where A[i] ≠ A[i+1], find a peak element and return its index. If the array contains multiple peaks, return the index to any one of the peaks.

Solution
The peak element could be any from 0 to n - 1. The monotonic function will be whether the current value is greater than the next value or not. We are interested in finding the first such index which returns true for this function.

type: minimization problem
range: lo -> invalid (-1), hi -> valid (0 - nums.length - 1)
initialize: lo to -1, hi to nums.length - 1
condition: f(x) = nums[x] > nums[x + 1]

```
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int lo = -1,hi = nums.size()-1;
        while(lo+1<hi){
            int mid = lo + (hi-lo)/2;
            if((nums[mid] > nums[mid+1]) || (mid == hi)) hi = mid;
            else lo = mid;
        }
        return hi;
    }
};
```
