Q-1) [Median of Two Sorted arrays](https://leetcode.com/problems/median-of-two-sorted-arrays/)

Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).

### Solution

### Approach 1: Merge and Sort

Create a new array with a size equal to the total number of elements in both input arrays.
Insert elements from both input arrays into the new array.
Sort the new array.
Find and return the median of the sorted array.
**Time Complexity**
In the worst case TC is O((n + m) \* log(n + m)).

**Space Complexity**
O(n + m), where ‘n’ and ‘m’ are the sizes of the arrays.

```
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // Get the sizes of both input arrays.
        int n = nums1.size();
        int m = nums2.size();

        // Merge the arrays into a single sorted array.
        vector<int> merged;
        for (int i = 0; i < n; i++) {
            merged.push_back(nums1[i]);
        }
        for (int i = 0; i < m; i++) {
            merged.push_back(nums2[i]);
        }

        // Sort the merged array.
        sort(merged.begin(), merged.end());

        // Calculate the total number of elements in the merged array.
        int total = merged.size();

        if (total % 2 == 1) {
            // If the total number of elements is odd, return the middle element as the median.
            return static_cast<double>(merged[total / 2]);
        } else {
            // If the total number of elements is even, calculate the average of the two middle elements as the median.
            int middle1 = merged[total / 2 - 1];
            int middle2 = merged[total / 2];
            return (static_cast<double>(middle1) + static_cast<double>(middle2)) / 2.0;
        }
    }
```

### Approach 2: Two Pointer

Initialize two pointers, i and j, both initially set to 0.
Move the pointer that corresponds to the smaller value forward at each step.
Continue moving the pointers until you have processed half of the total number of elements.
Calculate and return the median based on the values pointed to by i and j.
Time Complexity

O(n + m), where ‘n’ & ‘m’ are the sizes of the two arrays.
Space Complexity

O(1).

```
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        int i = 0, j = 0, m1 = 0, m2 = 0;

        // Find median.
        for (int count = 0; count <= (n + m) / 2; count++) {
            m2 = m1;
            if (i != n && j != m) {
                if (nums1[i] > nums2[j]) {
                    m1 = nums2[j++];
                } else {
                    m1 = nums1[i++];
                }
            } else if (i < n) {
                m1 = nums1[i++];
            } else {
                m1 = nums2[j++];
            }
        }

        // Check if the sum of n and m is odd.
        if ((n + m) % 2 == 1) {
            return static_cast<double>(m1);
        } else {
            double ans = static_cast<double>(m1) + static_cast<double>(m2);
            return ans / 2.0;
        }
    }
```

### Approach 3: Binary Search

    Use binary search to partition the smaller of the two input arrays into two parts.

Find the partition of the larger array such that the sum of elements on the left side of the partition in both arrays is half of the total elements.
Check if this partition is valid by verifying if the largest number on the left side is smaller than the smallest number on the right side.
If the partition is valid, calculate and return the median.
**Time Complexity** :O(logm/logn)
**Space Complexity** : O(1)

```
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        if(n1 > n2) return findMedianSortedArrays(nums2, nums1);
        int half = (n1 + n2 + 1)/2;
        int l = 0,h = n1;
        while(l <= h){
            int mid1 = l + (h-l)/2;
            int mid2 = half - mid1;
            int l1 = INT_MIN, l2 = INT_MIN, r1 = INT_MAX, r2 = INT_MAX;
            if(mid1 -1  >= 0) l1 = nums1[mid1 - 1];
            if(mid1 < n1) r1 = nums1[mid1];
            if(mid2 -1 >= 0) l2 = nums2[ mid2-1];
            if(mid2 < n2)  r2 = nums2[mid2];

            if(l1 <= r2 && l2 <= r1){
                if((n1+n2) % 2 == 0){
                    return (max(l1,l2) + min(r1,r2))/2.0;
                }else{
                    return max(l1,l2);
                }
            }
            else if(l1 > r2){ h = mid1 - 1;}
            else if(l2 > r1){ l = mid1 + 1;}
        }
        return 0.0;
    }
};
```

Q-2) [K-th Element of two sorted arrays](https://takeuforward.org/data-structure/k-th-element-of-two-sorted-arrays/)
Problem Statement: Given two sorted arrays of size m and n respectively, you are tasked with finding the element that would be at the kth position of the final sorted array.

### Intuition :

It is mentioned that given arrays are sorted. This gives us some hints to use binary search in them.

If we look into the final merged sorted array.

We can part it in such a way that our kth element will be at the end of the left half array. Let’s make some observations. The left portion of the array is made of some elements of both array1 and array2. We can see that all elements of the right half of the array are always larger than the left ones. So, with help of binary search, we will divide arrays into partitions with keeping k elements in the left half. We have to keep in mind that l1 <= r2 and l2 <= r1. Why so? This ensures that left-half elements are always lesser than right elements.

#### Approach :

Apply binary search in an array with a small size. Start iterating with two pointers, say left and right. Find the middle of the range. Take elements from low to middle of array1 and the remaining elements from the second array. Then using the condition mentioned above, check if the left half is valid. If valid, print the maximum of both array’s last element. If not, move the range towards the right if l2 > r1, else move the range towards the left if l1 > r2.

```
class Solution {
public:
    double kThElement(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        if(n1 > n2) return kThElement(nums2, nums1);
        int half = (n1 + n2 + 1)/2;
        int l = 0,h = n1;
        while(l <= h){
            int mid1 = l + (h-l)/2;
            int mid2 = half - mid1;
            int l1 = INT_MIN, l2 = INT_MIN, r1 = INT_MAX, r2 = INT_MAX;
            if(mid1 -1  >= 0) l1 = nums1[mid1 - 1];
            if(mid1 < n1) r1 = nums1[mid1];
            if(mid2 -1 >= 0) l2 = nums2[ mid2-1];
            if(mid2 < n2)  r2 = nums2[mid2];

            if(l1 <= r2 && l2 <= r1){
                return max(l1,l2);
            }
            else if(l1 > r2){ h = mid1 - 1;}
            else if(l2 > r1){ l = mid1 + 1;}
        }
        return 1;
    }
};

```
