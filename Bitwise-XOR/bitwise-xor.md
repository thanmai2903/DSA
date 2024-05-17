# Bitwise XOR

<b>XOR</b> is a logical bitwise operator that returns `0` (false) if both bits are the same and returns `1` (true) otherwise. In other words, it only returns `1` if exactly one bit is set to `1` out of the two bits in comparison.

|  A  |  B  | A xor B |
| :-: | :-: | :-----: |
|  0  |  0  |    0    |
|  0  |  1  |    1    |
|  1  |  0  |    1    |
|  1  |  1  |    0    |

It is surprising to know the approaches that the XOR operator enables us to solve certain problems. For example, let’s take a look at the following problem:

> Given an array of `n-1` integers in the range from `1` to `n`, find the one number that is missing from the array.

A straight forward approach to solve this problem can be:

1. Find the sum of all integers from `1` to `n`; let’s call it `s1`.
2. Subtract all the numbers in the input array from `s1`; this will give us the missing number.

```cpp
#include <vector>
#include <iostream>

int findMissingNumber(const std::vector<int>& arr) {
    int n = arr.size() + 1;

    // Find sum of all numbers from 1 to n
    int s1 = 0;
    for(int i = 1; i <= n; ++i) {
        s1 += i;
    }

    // Subtract all numbers in input from sum
    for(int num : arr) {
        s1 -= num;
    }

    // s1 is now the missing number
    return s1;
}

int main() {
    std::vector<int> arr = {1, 5, 2, 6, 4};
    std::cout << findMissingNumber(arr) << std::endl; // Output should be 3
    return 0;
}

```

-   The time complexity of the above algorithm is `O(n)` and the space complexity is `O(1)`.

### What could go wrong with the above algorithm?

> While finding the sum of numbers from `1` to `n`, we can get integer overflow when `n` is large.

How can we avoid this? Can XOR help us here?

Remember the important property of XOR that it returns 0 if both the bits in comparison are the same. In other words, XOR of a number with itself will always result in 0. This means that if we XOR all the numbers in the input array with all numbers from the range `1` to `n` then each number in the input is going to get zeroed out except the missing number. Following are the set of steps to find the missing number using XOR:

1. XOR all the numbers from `1` to `n`, let’s call it `x1`.
2. XOR all the numbers in the input array, let’s call it `x2`.
3. The missing number can be found by `x1` XOR `x2`.

```cpp
#include <vector>
#include <iostream>

int findMissingNumber(const std::vector<int>& arr) {
    int n = arr.size() + 1;

    // x1 represents XOR of all values from 1 to n
    int x1 = 1;
    for (int i = 2; i <= n; ++i) {
        x1 = x1 ^ i;
    }

    // x2 represents XOR of all values in arr
    int x2 = arr[0];
    for (int i = 1; i < arr.size(); ++i) {
        x2 = x2 ^ arr[i];
    }

    // Missing number is the XOR of x1 and x2
    return x1 ^ x2;
}

int main() {
    std::vector<int> arr = {1, 5, 2, 6, 4};
    std::cout << findMissingNumber(arr) << std::endl; // Output should be 3
    return 0;
}
```

-   The time complexity of the above algorithm is `O(n)` and the space complexity is `O(1)`. The time and space complexities are the same as that of the previous solution but, in this algorithm, we will not have any integer overflow problem.

### Important properties of XOR to remember

Following are some important properties of XOR to remember:

-   Taking XOR of a number with itself returns 0, e.g.,
    -   1 ^ 1 = 0
    -   29 ^ 29 = 0
-   Taking XOR of a number with 0 returns the same number, e.g.,
    -   1 ^ 0 = 1
    -   31 ^ 0 = 31
-   XOR is Associative & Commutative, which means:
    -   (a ^ b) ^ c = a ^ (b ^ c)
    -   a ^ b = b ^ a

## Single Number (easy)

https://leetcode.com/problems/single-number/

> In a non-empty array of integers, every number appears twice except for one, find that single number.

One straight forward solution can be to use a <b>HashMap</b> kind of data structure and iterate through the input:

-   If number is already present in <b>HashMap</b>, remove it.
-   If number is not present in <b>HashMap</b>, add it.
-   In the end, only number left in the <b>HashMap</b> is our required single number.

### using Map class

```cpp
int findSingleNumber(const std::vector<int>& arr) {
    std::unordered_map<int, int> numberMap;

    // Iterate through the array, incrementing the count for each element
    for (int num : arr) {
        numberMap[num]++;
    }

    // Find the element with a count of 1 (the single number)
    for (const auto& [key, value] : numberMap) {
        if (value == 1) {
            return key;
        }
    }

    // If no single number is found, throw an exception (optional)
    throw std::runtime_error("No single number found in the array");
}

```

### using Map object

```cpp
#include <iostream>
#include <unordered_map>
#include <vector>

int singleNumber(const std::vector<int>& arr) {
    std::unordered_map<int, int> numberMap;

    // Populate the map with counts of each number
    for (int num : arr) {
        numberMap[num]++;
    }

    // Find the number with a count of 1
    for (const auto& pair : numberMap) {
        if (pair.second == 1) {
            return pair.first;
        }
    }

    // If no single number is found, return an indication (e.g., -1)
    return -1; // Adjust this based on the expected behavior for no single number
}

int main() {
    std::vector<int> arr1 = {1, 4, 2, 1, 3, 2, 3};
    std::vector<int> arr2 = {7, 9, 7};

    std::cout << "Single number in arr1: " << singleNumber(arr1) << std::endl; // Output should be 4
    std::cout << "Single number in arr2: " << singleNumber(arr2) << std::endl; // Output should be 9

    return 0;
}
```

Time and space complexity Time Complexity of the above solution will be `O(n)`and space complexity will also be `O(n)`.

Can we do better than this using the <b>XOR</b> Pattern?

Recall the following two properties of XOR:

-   It returns zero if we take XOR of two same numbers.
-   It returns the same number if we XOR with zero.
    So we can XOR all the numbers in the input; duplicate numbers will zero out each other and we will be left with the single number.

```cpp
#include <iostream>
#include <vector>

int singleNumber(const std::vector<int>& arr) {
    int num = 0;

    // XOR all numbers in the input array
    for (int i = 0; i < arr.size(); ++i) {
        num ^= arr[i];
    }

    return num;
}

int main() {
    std::vector<int> arr1 = {1, 4, 2, 1, 3, 2, 3};
    std::vector<int> arr2 = {7, 9, 7};

    std::cout << "Single number in arr1: " << singleNumber(arr1) << std::endl; // Output should be 4
    std::cout << "Single number in arr2: " << singleNumber(arr2) << std::endl; // Output should be 9

    return 0;
}
```

-   Time complexity of this solution is `O(n)` as we iterate through all numbers of the input once.
-   The algorithm runs in constant space `O(1)`.

## 😕 Two Single Numbers (medium)

https://leetcode.com/problems/single-number-iii/

> In a non-empty array of numbers, every number appears exactly twice except two numbers that appear only once. Find the two numbers that appear only once.

This problem is quite similar to <b>Single Number</b>, the only difference is that, in this problem, we have two single numbers instead of one. Can we still use XOR to solve this problem?

Let’s assume `num1` and `num2` are the two single numbers. If we do XOR of all elements of the given array, we will be left with XOR of `num1` and `num2` as all other numbers will cancel each other because all of them appeared twice. Let’s call this XOR `n1xn2`. Now that we have XOR of `num1` and `num2`, how can we find these two single numbers?

As we know that `num1` and `num2` are two different numbers, therefore, they should have at least one bit different between them. If a bit in `n1xn2` is ‘1’, this means that `num1` and `num2` have different bits in that place, as we know that we can get ‘1’ only when we do XOR of two different bits, i.e.,

`1 XOR 0 = 0 XOR 1 = 1`

We can take any bit which is ‘1’ in `n1xn2` and partition all numbers in the given array into two groups based on that bit. One group will have all those numbers with that bit set to ‘0’ and the other with the bit set to ‘1’. This will ensure that `num1` will be in one group and `num2` will be in the other. We can take XOR of all numbers in each group separately to get `num1` and `num2`, as all other numbers in each group will cancel each other. Here are the steps of our algorithm:

1. Taking XOR of all numbers in the given array will give us XOR of `num1` and `num2`, calling this XOR as `n1xn2`.
2. Find any bit which is set in `n1xn2`. We can take the rightmost bit which is ‘1’. Let’s call this `rightmostSetBit`.
3. Iterate through all numbers of the input array to partition them into two groups based on `rightmostSetBit`. Take XOR of all numbers in both the groups separately. Both these XORs are our required numbers.

```cpp
#include <iostream>
#include <vector>

std::vector<int> findSingleNumbers(const std::vector<int>& nums) {
    int n1xn2 = 0;

    // Get the XOR of all the numbers
    for (int n : nums) {
        n1xn2 ^= n;
    }

    // Get the rightmost bit that is 1
    int right = 1;
    while ((right & n1xn2) == 0) {
        // Left shift operator (<<) shifts the first operand the specified number of bits to the left
        // Excess bits shifted off to the left are discarded
        // Zero bits are shifted in from the right
        right = right << 1;
    }

    int num1 = 0, num2 = 0;

    // Partition the numbers into two groups based on the rightmost bit
    for (int n : nums) {
        if ((n & right) != 0) {
            // The bit is set
            num1 ^= n;
        } else {
            // The bit is not set
            num2 ^= n;
        }
    }

    return {num1, num2};
}

int main() {
    std::vector<int> nums1 = {1, 4, 2, 1, 3, 5, 6, 2, 3, 5};
    std::vector<int> nums2 = {2, 1, 3, 2};

    std::vector<int> result1 = findSingleNumbers(nums1);
    std::vector<int> result2 = findSingleNumbers(nums2);

    std::cout << "Single numbers in nums1: " << result1[0] << " and " << result1[1] << std::endl; // Output should be 4 and 6
    std::cout << "Single numbers in nums2: " << result2[0] << " and " << result2[1] << std::endl; // Output should be 1 and 3

    return 0;
}
```

-   The time complexity of this solution is `O(n)` where `n` is the number of elements in the input array.
-   The algorithm runs in constant space `O(1)`.

## 😕 Complement of Base 10 Number (medium)

https://leetcode.com/problems/complement-of-base-10-integer/

Every non-negative integer N has a binary representation, for example, 8 can be represented as “1000” in binary and 7 as “0111” in binary.

The complement of a binary representation is the number in binary that we get when we change every 1 to a 0 and every 0 to a 1. For example, the binary complement of “1010” is “0101”.

For a given positive number N in base-10, return the complement of its binary representation as a base-10 integer.

Recall the following properties of XOR:

1. It will return 1 if we take XOR of two different bits i.e. `1^0 = 0^1 = 1`.
2. It will return 0 if we take XOR of two same bits i.e. `0^0 = 1^1 = 0`. In other words, XOR of two same numbers is 0.
3. It returns the same number if we XOR with 0.

From the above-mentioned first property, we can conclude that XOR of a number with its complement will result in a number that has all of its bits set to 1. For example, the binary complement of “101” is “010”; and if we take XOR of these two numbers, we will get a number with all bits set to 1, i.e., `101 ^ 010 = 111`

We can write this fact in the following equation:

`number ^ complement = all_bits_set`

Let’s add ‘number’ on both sides:

`number ^ number ^ complement = number ^ all_bits_set`

From the above-mentioned second property:

`0 ^ complement = number ^ all_bits_set`

From the above-mentioned third property:

`complement = number ^ all_bits_set`

We can use the above fact to find the complement of any number.

<b>How do we calculate `all_bits_set`?</b> One way to calculate `all_bits_set` will be to first count the bits required to store the given number. We can then use the fact that for a number which is a complete power of ‘2’ i.e., it can be written as pow(2, n), if we subtract ‘1’ from such a number, we get a number which has ‘n’ least significant bits set to ‘1’. For example, ‘4’ which is a complete power of ‘2’, and ‘3’ (which is one less than 4) has a binary representation of ‘11’ i.e., it has ‘2’ least significant bits set to ‘1’.

```cpp
#include <iostream>
#include <cmath>

int calculateBitwiseComplement(int n) {
    int bitCount = 0;
    int num = n;

    // Count number of total bits in 'num'
    while (num > 0) {
        bitCount++;
        num = num >> 1;
    }

    // For a number which is a complete power of '2' i.e., it can be written as pow(2, n),
    // if we subtract '1' from such a number, we get a number which has 'n' least significant
    // bits set to '1'. For example, '4' which is a complete power of '2', and '3' (which is
    // one less than 4) has a binary representation of '11' i.e., it has '2' least significant
    // bits set to '1'.
    int allBitsSet = pow(2, bitCount) - 1;

    // From the solution description: complement = number ^ allBitsSet
    return n ^ allBitsSet;
}

int main() {
    std::cout << "Bitwise complement of 8: " << calculateBitwiseComplement(8) << std::endl; // Output should be 7
    std::cout << "Bitwise complement of 10: " << calculateBitwiseComplement(10) << std::endl; // Output should be 5

    return 0;
}
```

-   Time complexity of this solution is `O(b)`where `b` is the number of bits required to store the given number.
-   Space complexity of this solution is `O(1)`.

## 🌟 Flip Binary Matrix(hard)

https://leetcode.com/problems/flipping-an-image/

> Given a binary matrix representing an image, we want to flip the image horizontally, then invert it.
>
> To flip an image horizontally means that each row of the image is reversed. For example, flipping `[0, 1, 1]` horizontally results in `[1, 1, 0]`.
>
> To invert an image means that each 0 is replaced by 1, and each 1 is replaced by 0. For example, inverting `[1, 1, 0]` results in `[0, 0, 1]`.

-   <b>Flip:</b> We can flip the image in place by replacing <i>ith</i> element from left with the <i>ith</i> element from the right.
-   <b>Invert:</b> We can take XOR of each element with `1`. If it is `1` then it will become `0` and if it is `0` then it will become `1`.

```cpp
vector<std::vector<int>> flipAndInvertImage(std::vector<std::vector<int>>& matrix) {
    int c = matrix.size();

    for (int row = 0; row < c; ++row) {
        for (int col = 0; col < (c + 1) / 2; ++col) {
            int temp = matrix[row][col] ^ 1;
            matrix[row][col] = matrix[row][c - 1 - col] ^ 1;
            matrix[row][c - 1 - col] = temp;
        }
    }

    return matrix;
}
```

-   The time complexity of this solution is `O(n)` as we iterate through all elements of the input.
-   The space complexity of this solution is `O(1)`.
