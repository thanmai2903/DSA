**“Number of Subarrays” Questions**

**"Prefixed" Sliding Window**

-   the **claim** is that if you have a subarray with exactly K 1s, and the first p numbers are 0, then extending the subarray by including the next p + 1 elements (with the same suffix) results in valid subarrays.

-   If the subarray [i,j] contains K 1s, and the first p numbers of the subarray are 0, then that means all the subarrays from [i,j] to [i+p, j] inclusive are valid, which is p+1 subarrays.

-   In the first loop, we move the left pointer to the right while the sum is too high, just like in a standard sliding window question.
    -   We set p to 0 because i is changing.
-   In the 2nd loop, after finding some [i,j], we find how many leading 0s are in this subarray.
    Finally, we need to check if the current sum equals the target again - because the first loop didn’t check if the sum is too low.

```
int numSubarraysWithSum(vector<int>& A, int S) {
    int p = 0, i = 0, r = 0, c = 0;

    for (int j = 0; j < A.size(); j++) {
        c += A[j];  // Increment the current sum by the value at index j

        // Check if the current sum exceeds the target S
        while (c > S && i < j) {
            p = 0;  // Reset the prefix count
            c -= A[i];  // Decrement the current sum by the value at index i
            i++;  // Move the left pointer to the next position
        }

        // Handle consecutive zeros in the subarray
        while (A[i] == 0 && i < j) {
            p++;  // Increment the prefix count for each zero encountered
            c -= A[i];  // Decrement the current sum by the zero value
            i++;  // Move the left pointer to the next position
        }

        // If the current sum is equal to the target S, update the result count
        if (c == S) r += p + 1;
    }

    return r;
}

```
