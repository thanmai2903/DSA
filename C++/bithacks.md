i%2 == 0 -> check even -> !(i & 1)
i%2 != 0 -> check odd -> i & 1

1 >> m -> pow(2,m)
1 << m -> 1/pow(2,m)

x & (x-1) => removes the right most bit in binary of x => x-1 is ans
x & (-x) => removes the right most bit in binary of x => x is ans

x & (x-1) == 0 => x is power of 2

-   iota(nums.begin(), nums.end(), 1); // Initialize vector with numbers 1 to n

# Bit Manipulation: From Beginner to Pro

## Level 1: Understanding the Basics

-   Number Representation: Computers store data in binary form, where each unit is called a bit (0 or 1). An 8-bit integer can represent 256 (2 raised to 8) unique values.
-   Bitwise Operators: These operators perform operations on individual bits of the operands. Key operators include:
-   & (AND): Sets a bit to 1 only if both corresponding bits are 1.
-   | (OR): Sets a bit to 1 if either or both corresponding bits are 1.
-   ^ (XOR): Sets a bit to 1 if the corresponding bits are different.
-   ~ (NOT): Flips all bits (0 becomes 1 and vice versa).
-   Shifting Operations: These operators shift the bits of a number by a specified number of positions:
-   << (Left Shift): Moves bits to the left, padding with zeros on the right.
-   > > (Right Shift): Moves bits to the right, filling with zeros (unsigned) or replicating the sign bit (signed).

## Level 2: Core Techniques

#### Setting, Clearing, and Toggling Bits:

1. **Setting a bit:** Use x | (1 << position) where x is the number and position is the bit index (0-based, starting from the rightmost bit).
2. **Clearing a bit:** Use x & ~(1 << position).
3. **Toggling a bit:** Use x ^ (1 << position).
4. **Checking if a Bit is Set:** Use x & (1 << position) and check if the result is non-zero.
5. **Extracting a Specific Bit:** Use (x >> position) & 1.

## Level 3: Advanced Concepts

1. **Bit Masks:**

-   A bit mask is a custom-designed number used to manipulate specific bits in another number.
-   It's created by setting the desired bits to 1 and the remaining bits to 0.
-   Example: Mask 0b00001111 (decimal 15) has its lower 4 bits set to 1.
    Performing a bitwise AND ( & ) between this mask and any number effectively clears the lower 4 bits of that number.

2. **Counting Set Bits:**

**Brian Kernighan's Algorithm:**

This efficient algorithm counts the number of set bits (1s) in a non-negative integer. Here's how it works:

1. Initialize a counter variable count to 0.
2. While the number x is not zero:
    - Increment the count: count += x & 1
    - Remove the rightmost set bit: x = x >> 1 (right shift by 1)
3. Return the final count.

```cpp
int countSetBits(int x){
    int count = 0;
    while (x){
        count += x & 1;
        x = x >> 1;
    }
    return count;
}
```

**Explanation**

-   The bitwise AND (&) with 1 (x & 1) isolates the rightmost bit of x. If it's 1, the result is 1, and the count is incremented.
-   The right shift (>>) effectively removes the counted bit from x for the next iteration.
-   The loop continues until all bits in x are processed, and the final count reflects the total number of set bits.

3. **Finding the Most Significant Set Bit (MSB):**

The MSB is the leftmost bit (highest position) set to 1 in a binary representation. Here's a method to find it:

1. Initialize a variable position to 0.
2. While x is not zero:
    - Shift x right by 1: x >>= 1
    - Increment position: position += 1
3. Return position - 1 (since indexing starts from 0).

```cpp
int MSB(int x){
  int pos = 0;
  while(x){
    x = x>>1;
    pos++;
  }
  return pos-1;
}
```

**Explanation:**
The loop iterates until x becomes zero, signifying all bits have been processed.
In each iteration, x is shifted right by 1. If the MSB was set, it will be shifted out, and the loop will continue.
position keeps track of the number of shifts performed, indicating the position of the MSB (remember 0-based indexing, hence - 1).

4. **Parity Check:**

The parity of a number refers to whether it has an even or odd number of set bits. Here's how to check using XOR (^):

1. Initialize a result variable res to x.
2. While res is not zero:
    - Perform XOR between res and res >> 1: res ^= res >> 1
3. Check the least significant bit of res:
    - If the last bit is 0, the number has even parity (even number of set bits).
    - If the last bit is 1, the number has odd parity (odd number of set bits).

```cpp
#include <iostream>

using namespace std;

bool checkParity(int x) {
  int res = x;
  while (res != 0) {
    res ^= res >> 1; // XOR with right shifted version
  }
  return (res & 1) == 0; // Check least significant bit
}

int main() {
  int num;
  cout << "Enter a number: ";
  cin >> num;

  if (checkParity(num)) {
    cout << num << " has even parity (even number of set bits)." << endl;
  } else {
    cout << num << " has odd parity (odd number of set bits)." << endl;
  }

  return 0;
}
```

**Explanation:**

-   The XOR operation between a number and its right-shifted version effectively isolates and removes the common bits, leaving only the bits that differ between the two.
-   Repeating this process eliminates all paired bits, leaving only the single rightmost set bit in res.
-   The parity of the original number is reflected in the least significant bit of the final res.
