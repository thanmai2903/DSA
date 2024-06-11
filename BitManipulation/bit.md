# Convert to Binary from Decimal

```cpp
vector<bool> decimalToBitVector(int n) {
    vector<bool> bitVector;

    // Edge case for 0
    if (n == 0) {
        bitVector.push_back(0);
        return bitVector;
    }

    while (n > 0) {
        bitVector.push_back(n % 2);
        n = n / 2;
    }

    // The bits are in reverse order, we need to reverse the vector
    reverse(bitVector.begin(), bitVector.end());
    return bitVector;
}
vector<bool> decimalToBitVector(int n) {
    vector<bool> bitVector;

    // Edge case for 0
    if (n == 0) {
        bitVector.push_back(0);
        return bitVector;
    }
    int i=0;
    while (n > 0) {
        bitVector[i] = (n % 2);
        n = n / 2;
        i++;
    }
    return bitVector;
}
```

# Convert Binary TO Decimal

```cpp
int bitVectorToDecimal(const vector<bool>& bitVector) {
    int decimalNumber = 0;
    int size = bitVector.size();

    for (int i = 0; i < size; ++i) {
        if (bitVector[size - 1 - i]) {
            decimalNumber += pow(2, i);
        }
    }

    return decimalNumber;
}
```

## NOTE

-   32 bit number -> Min Value: -2e9, Max Value: +2e9 -> INT
-   64 bit number -> LONG LONG INT
-   5 -> 00000...101(32 bit)
-   (-5) -> ? =>
    -   1's COmpliment = flip bits of 000...101 -> 111...010
    -   2's compliment = add 1 to end of 010 -> 111...011
-   **Trick** -> For a 32 bit Number, if left most bit is 1 => it's negative number.
-   **AND** -> Both bits are 1 then only 1 else 0
-   **OR** -> Both bits are 0 then only 0 else 1
-   **XOR** -> Both bits are same then 0 else 1
-   a^a = 0, a^0 = 0
-   **AND** always **shrink or same** the value
-   a&b -> res = either min(a,b) or even lesser.
-   **OR** always **increases or same** the value
-   a|b -> res = either max(a,b) or even greater.

```
-   **XOR** helps to flip a specific bits
-   5 -> 0101 -> TO flip 1st bit, do masking like below
-   make a MASK of ith bit -> 0010 then xor of both -> res = 0111
```

# Set and Unset the ith bit

-   set -> make 1 of ith bit even if ith bit is 0/1 => use **or** operation -> left shift => n | (1 << i)
-   unset -> make 0 of ith bit even if ith bit is 0/1 => use **and** operation -> left shift => n & ~(1 << i)

# Check ith bit is set or not?

-   check -> if ith bit is 1 or 0 => use **and** operation -> left shift => n & (1 << i)

```cpp
if((n&(1<<i)) == 0){
    //ith bit is not set
}else{
    //it is set
}
```

# Remove Right Most set bit

```cpp
int removeRightmostSetBit(int n) {
    return n & (n - 1);
}
```
