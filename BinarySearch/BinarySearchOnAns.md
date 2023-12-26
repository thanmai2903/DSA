# Binary Search on Answers

## Introduction

When dealing with sorted arrays, binary search is a common approach. However, binary search can also be applied in cases where the input array is not sorted. These types of problems are often referred to as "binary search on answers." The key conditions for identifying such problems are:

1. Constraint of `n <= 10 ^ 5`.
2. The question involves finding the minimum of maximums, maximum of minimums, or some minimum/maximum/at least condition.
3. The problem exhibits a monotonic nature.

## Template for Binary Search on Answers
`bool isValid(vector<int>& nums, int mid, int k){
    // Return either true or false based on the criteria 'k'
}

int function(vector<int>& nums, int k) {
    int l = minimum_possible_answer, r = maximum_possible_answer;
    int ans = -1;
    
    while(l <= r){
        int mid = (l + r) / 2;
        if(isValid(nums, mid, k) == true){
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return ans;
} `

**Time Complexity**: O(N * log(Range of Binary Search))

Where N is the size of the array, and Range of Binary Search is high - low.
Note
Calculating mid:
Calculating mid can result in overflow when the numbers are extremely big. There are a few ways of calculating mid:

 1. mid = (l + h) / 2 - worst, very easy to overflow.
 2. mid = l + (r - l) / 2 - much better, but still possible.
 3. mid = (l + h) >> 1 - the best, but hard to understand.

### Why Integer Overflows?
If we take (low + high) / 2, and if both low and high are nearly 10 ^ 9, in that case, the sum of both (low + high) exceeds the integer range, causing integer overflow. For simplicity, the first condition is used.

## Example Problems

Q-1) [Find the Smallest Divisor Given a Threshold](https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/)

### Identification:

#### Constraint: 1 <= nums.length <= 5 * 10 ^ 4
Find the smallest divisor such that the result mentioned above is less than or equal to threshold.
Identifying values of low and high

low = 1;
high = Max of array
#### Intuition:
Binary search the result.
1) If the sum > threshold, the divisor is too small.
2) If the sum <= threshold, the divisor is big enough.

`class Solution {
    bool isValid(vector<int>& nums, int threshold, int mid){
        int sum = 0;
        for(auto it: nums){
            sum += ceil(float(it)/float(mid)) ;
        }
        return sum <= threshold ;
    }
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int l = 1, r = *max_element(nums.begin(), nums.end()) ;
        int res = -1;
        while(l <= r){
            int mid = (l + r)/2 ;
            if(isValid(nums, threshold, mid) == true){
                res = mid ;
                r = mid - 1 ;
            }else{
                l = mid + 1 ;
            }
            
        }
        return res ;
    }
};`
---

Q-2) [Split Array Largest Sum](https://leetcode.com/problems/split-array-largest-sum/)

### Identification:

1 <= nums.length <= 1000
Return the minimized largest sum of the split
Identifying values of low and high

1) If k = n (size of array), In this case all the students will get only one book, then the minimum possible answer would be max of the array
2) If k = 1, then the maximum possible answer could be when there is only one student and he should read all books so high = sum of the array.

`class Solution {
public: 
    bool canSplit(vector<int>& nums, int k, int mid){
        int stud = 1 ;
        int sum = 0;
        for(auto &i : nums){
            sum += i ;
            if(sum > mid){
                stud++ ;
                sum = i ;
            }
        }
        return stud <= k;
    }
    
    
    int splitArray(vector<int>& nums, int k) {
        int l = *max_element(nums.begin(), nums.end()), r = accumulate(nums.begin(), nums.end(), 0) ;
        int res = -1 ;

        while(l <= r){
            int mid = l + (r-l)/2 ;
            if(canSplit(nums, k, mid) == true){
                r = mid - 1;
                res = mid ;
            }else{
                l = mid + 1 ;
            }
        }
        return res ;
    }
};`
---

Q-3) [Capacity To Ship Packages Within D Days](https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/)
(same code as split largest subarray sum)

### Identification:

1 <= days <= weights.length <= 5 * 104
Return the least weight capacity of the ship that will result in all the packages on the conveyor belt being shipped within days days.
Identifying values of low and high

1) If days == n (size of array), then every day 1 element can be shipped, so max of array would be minimum possible answer
2) If days = 1, then high has to be sum of all elements
#### Intuition:
Given the number of bags,
return the minimum capacity of each bag,
so that we can put items one by one into all bags.

`class Solution {
public:
    bool isValid(vector<int>& weights, int days, int mid){
        int totDays = 1;
        int sum = 0 ;
        
        for(auto &i : weights){
            sum += i ;
            if(sum > mid){
                totDays++ ;
                sum = i ;
            }
        }
        
        return totDays <= days;
    }
    
    int shipWithinDays(vector<int>& weights, int days) {
        int l = *max_element(weights.begin(), weights.end()) ;
        int r = accumulate(weights.begin(), weights.end(), 0)  ;
        int res = -1;
        
        while(l <= r){
            int mid = (l + r) >> 1;
            if(isValid(weights, days, mid) == true){
                res = mid ;
                r = mid-1;
            }else{
               l = mid+1 ;
            }
        }
        return res;
    }
};`
---

Q-4) [Koko Eating Bananas](https://leetcode.com/problems/koko-eating-bananas/)

### Identication:
1 <= piles.length <= 10^4
Return the minimum integer k such that she can eat all the bananas within h hours.
Identifying low and high:

1) low = 1;
2) high = Maximum in array

`class Solution {
public:
    bool isValid(vector<int>& piles, int h, int mid){
        long long int hrs = 0 ;
       
        for(auto &it: piles){
            hrs += (it / mid);
            if((it % mid) > 0 ){
                hrs++ ;
            }
        }
        
        return hrs <= h ;
    }
    
    int minEatingSpeed(vector<int>& piles, int r) {
        int l = 1 , h= *max_element(piles.begin(), piles.end()) ;
        int ans = -1;
        
        while(l <= h){
            int mid = l + (h-l)/2 ;
            
            if(isValid(piles, r, mid) == true){
                ans = mid ;
                 h = mid - 1 ;
                
            }else{
               l = mid + 1 ;
            }
        }
        return ans ;
    }
    
};`
---

Q-5) [Minimized Maximum of Products Distributed to Any Store ](https://leetcode.com/problems/minimized-maximum-of-products-distributed-to-any-store/)

### Identication:
1 <= m <= n <= 105
Minimize the maximum number of products that are given to any store.

`class Solution {
    bool isValid(int mid, vector<int>& quantities, int n){
        int cnt = 0 ;
        for(auto &it: quantities){
            cnt += (it / mid) ;
            if(it % mid != 0){
                cnt++ ;
            }
        }
        return cnt <= n ;
    }
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int low = 1, high = *max_element(quantities.begin(), quantities.end()) ;
        int res = -1 ;
        
        while(low <= high){
            int mid = (low + high)/2 ;
            if(isValid(mid, quantities, n) == true){
                res = mid ;
                high = mid - 1 ;
            }else{
                low = mid + 1 ;
            }
        }
        
        return res ;
    }
};`
---

Q-6) [ Minimum Time to Complete Trips](https://leetcode.com/problems/minimum-time-to-complete-trips/description/)

### Identifying low and high:

1) low = 0;
2) high = 10 ^ 14
We need to find worst case in order to get upper bound.
According to the ranges in the problem, 1 <= time.length <= 10^5; 1 <= time[i], totalTrips <= 10^7.

The less the number of buses, the greater value of time and totalTrips are, the more time are needed. We can use the extreme of each, 1, 10 ^ 7 and 10 ^ 7 to locate the worst case.

Therefore, the longest time, the upper bound of the binary search space, 10 ^ 7 * 10 ^ 7, which corresponds to the worst case that only 1 bus is available and it need to finish 10 ^ 7 trips.
`class Solution {
public:
    long long totalTripComp(vector<int>& time, long long secs){
        long long cnt = 0 ;
        for(auto it : time){
            cnt += (secs/it) ;
        }
        return cnt ;
    }
    
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long low = 0, high = 1e14 ;
        long long ans = high ;
        while(low <= high){
            long long mid = low + (high-low)/2 ;
            if(totalTripComp(time, mid) >= totalTrips ){
                ans = mid ;
                high = mid-1 ;             
            }else{
                low = mid+1 ;
            }
        }
        return ans ;
    }
};`
---

Q-7) [Minimum Number of Days to Make m Bouquets](https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/)

### Identication:

1 <= m <= n <= 105
Minimum number of days you need to wait to be able to make m bouquets from the garden

#### Identifying low and high:
low = minimum element in array;
for high = maximum element in array
We need to find worst case in order to get upper bound.

`bool isValid(int mid, vector<int>& bloomDay, int m, int k){
    int cnt = 0 , temp = 0 ;
    
    for(auto &it: bloomDay){
        if(it <= mid){
            temp++ ;
            if(temp == k){
                temp = 0;
                cnt++ ;
            }
        }else{
            temp = 0;
        }
    }
    return cnt >= m ;
}

int minDays(vector<int>& bloomDay, int m, int k) {
    int low = *min_element(bloomDay.begin(), bloomDay.end()) , high = *max_element(bloomDay.begin(), bloomDay.end() ) ;
    int res = -1;

    while(low <= high){
        int mid = (low + high)/2 ;

        if(isValid(mid, bloomDay, m, k) == true){
            res = mid ;
            high = mid - 1;
        }else{
            low = mid + 1 ;
        }
    }

    return res ;
}`
---

Q-8) [Magnetic Force Between Two Balls](https://leetcode.com/problems/magnetic-force-between-two-balls/)

### Identication:
2 <= n <= 10^5
Minimum magnetic force between any two balls is maximum.

#### Identifying low and high:
low = 1;
for high = 1e9
We need to find worst case in order to get upper bound.

`bool isPossible(int mid, int n, int k, vector<int> &stalls){
    int coord = stalls[0] ;
    int cnt =  1;
    for(int i = 1; i < n; i++){
        if(stalls[i] - coord >= mid){
            coord = stalls[i] ;
            cnt++ ;
        }
    }
    return cnt >= k ;
}

int maxDistance(vector<int>& stalls, int k) {
    int n = stalls.size() ;
    sort(stalls.begin(), stalls.end()) ;
    int low = 1, high = 1e9 ;
    int res = -1;
    while(low <= high){
        int mid = (low + high) >> 1;
        if(isPossible(mid, n, k, stalls)){
            res = mid ;
            low = mid + 1 ;
        }else{
            high = mid - 1;
        }
    }
    return res;
}`
---

Q-9) [Maximum Tastiness of Candy Basket ](https://leetcode.com/contest/weekly-contest-325/problems/maximum-tastiness-of-candy-basket/)
(Exact same as Q 1552. Magnetic Force Between Two Balls)
### Identication:
2 <= k <= price.length <= 10^5
Return the maximum tastiness of a candy basket.
​
#### Identifying low and high:
low = 1;
for high = stalls[n-1] - stalls[0]

`bool isPossible(int mid, int n, int k, vector<int> &stalls){
    int coord = stalls[0] ;
    int cnt =  1;
    for(int i = 1; i < n; i++){
        if(stalls[i] - coord >= mid){
            coord = stalls[i] ;
            cnt++ ;
        }
    }
    return cnt>=k ;
}
public:
int maximumTastiness(vector<int>& stalls, int k) {
    int n = stalls.size() ;
    sort(stalls.begin(), stalls.end()) ;
    int low = 1, high = stalls[n-1] - stalls[0] ;
    int res = 0 ;
    while(low <= high){
        int mid = (low + high) >> 1;
        if(isPossible(mid, n, k, stalls)){
            res = mid ;
            low = mid + 1 ;
        }else{
            high = mid - 1;
        }
    }
    return res;
}`

Q-10) [Maximum Running Time of N Computers ](https://leetcode.com/problems/maximum-running-time-of-n-computers/)

`bool isValid(vector<int>& nums, long long int n, long long int mid){
    long long int cnt = 0 ;
    for(auto &it: nums){
        cnt += min(mid, 1ll * it) ;
    }
    return cnt >= (1ll * mid * n) ;
}

long long maxRunTime(int n, vector<int>& batteries) {
    long long int low = 0, high = accumulate(batteries.begin(), batteries.end(), 0ll) ;
    long long int res = -1 ;

    while(low <= high){
        long long int mid = (low + high)>>1;
        if(isValid(batteries, n, mid) == true){
            res = mid ;
            low = mid + 1 ;
        }else{
            high = mid - 1;
        }
    }

    return res ;
}`
---

Q-11) [Minimum Limit of Balls in a Bag ](https://leetcode.com/problems/minimum-limit-of-balls-in-a-bag/)

`bool isValid(vector<int>& nums, int maxOperations, int mid){
    int cnt = 0 ;
    for(auto &it: nums){
        if(it > mid){
            cnt += (it - 1) / mid ;
        }
    }
    return cnt <= maxOperations ;
}

int minimumSize(vector<int>& nums, int maxOperations) {
    int low = 1, high = *max_element(nums.begin(), nums.end()) ;
    int res = -1 ;

    while(low <= high){
        int mid = low + (high - low)/2 ;
        if(isValid(nums, maxOperations, mid) == true){
            res = mid ;
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }

    return res ;
}`

Q-12) [The Painter's Partition Problem-II
](https://practice.geeksforgeeks.org/problems/the-painters-partition-problem1535/0)

`class Solution{
     static long f(int arr[],long mid,int m){
        long pages =0;
        long student=1;
        
        for(int i=0;i<arr.length;i++){
            if(pages+arr[i]<=mid){
                pages+=arr[i];
            }
            else{
                student++;
                pages = arr[i];
            }
        }
        return student;
    }
    static long minTime(int[] arr,int n,int M){
        //code here
       
        long sum = 0;
        long max =0;
        for(int i=0;i<n;i++){
            sum+= arr[i]; 
            max = Math.max(arr[i],max);
        }
        
        long low = max;
        long high =sum;
     
        while(low<=high){
            long mid = low + (high-low)/2;
            long noOfStudent = f(arr,mid,M);
            
            if((int)noOfStudent>M){
                low =mid+1;
            }
            else{
               
                high =mid-1;
            }
        }
        return low;
    }
}`
---

Q-13) [Allocate minimum number of pages
](https://practice.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1)

`class Solution 
{
private:
   int isValid(int nums[], int N, int mid){
       int sum = 0,student = 1;
       for(int i=0; i<N; ++i){
           sum += nums[i];
           if(sum > mid){
               student++;
               sum = nums[i];
           }
       }
       return student;
   }
public:
    //Function to find minimum number of pages.
    int findPages(int nums[], int N, int k) 
    {
        //code here
        if(k > N) return -1;
        int lo=INT_MIN, hi=0;
        for(int i=0; i<N; ++i){
            lo = max(lo,nums[i]);
            hi += nums[i];
            
        }
        int ans=-1;
        while(lo <= hi){
            int mid = lo + (hi - lo)/2;
            if(isValid(nums,N,mid) <= k){
                ans = mid;
                hi = mid-1;
            }else{
                lo = mid+1;
            }
        }
        return ans;
    }
};`
---

Q-14) [Aggressive Cows](https://practice.geeksforgeeks.org/problems/aggressive-cows/0)

`class Solution {
private:
    bool isValid(int n, int k, vector<int> &stalls, int mid){
        
        int cow = 1, prev = stalls[0];
        for(int i=1; i<n; ++i){
            if(stalls[i] - prev >= mid){
                cow++;
                prev = stalls[i];
            }
        }
        return cow  >= k;
    }
public:
    int solve(int n, int k, vector<int> &stalls) {
        sort(stalls.begin(),stalls.end());
        // Write your code here
        int mn = INT_MAX, mx = INT_MIN;
        for(auto e: stalls){
            mn = min(mn,e);
            mx = max(mx,e);
        }
        int l = 1, h = mx - mn, ans = -1;
        while(l <= h){
            int mid = l + (h-l)/2;
            if(isValid(n,k,stalls,mid)){
                ans = mid;
                l = mid+1;
            }else{
                h = mid-1;
            }
        }
        return ans;
    }
};`