# 1. ceil of (k/y)

How many times to add y to get sum >= k === ceil[k/y]
ceil(k/y) === (k+y-1)/y
or ceil(k/y) === k % y == 0 ? k/y : k/y-1;

-   similarly floor (k/y) = ceil(k/y) - 1

# 2. Mod m

```
(a+b)%m = (a%m + b%m)%m
(a*b)%m = (a%m * b%m)%m
(a-b)%m = (a%m - b%m + m)%m (Add of m is to make sure that if a%m - b%m becomes negative, make positive)
```

# 3. a power b

1. One methos is to multiply a , b times => O(b) time
2. Recursion -> O(log(b))

\[
\text{power}(a, b) =
\begin{cases}
1 & \text{if } b = 0 \\
\text{power}(a, \frac{b}{2}) \cdot \text{power}(a, \frac{b}{2}) & \text{if } b \text{ is even} \\
a \cdot \text{power}(a, \frac{b}{2}) \cdot \text{power}(a, \frac{b}{2}) & \text{if } b \text{ is odd}
\end{cases}
\]

-   **Even Case:**

    -   \( b \) is even
    -   \( a^b = (a^{b/2})^2 \)

-   **Odd Case:**
    -   \( b \) is odd
    -   \( a^b = a \cdot (a^{b/2})^2 \) or
    -   \( a^b = a \cdot (a^{(b-1)/2})^2 \)
    -   since if n is odd => n/2 and (n-1)/2 are same

```cpp
int power(int a, int b){
    if(b == 0) return 1;
    int temp = power(a, b/2);
    if(b%2 == 0) return temp*temp;
    else return a*temp*temp;
}
```

This is called `Binary Exponentiation` or `bin pow`

# 4. GCD

```cpp
// Euclidean Algorithm (Iterative)
int gcdIterative(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Euclidean Algorithm (Recursive)
int gcdRecursive(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcdRecursive(b, a % b);
}
```

# 5. LCM

```cpp
// LCM(x,y)*GCD(x,y) = x*y
// Helper function to calculate GCD using the Euclidean algorithm (iterative)
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// LCM using the relationship between GCD and LCM
int lcmUsingGcd(int a, int b) {
    return (a / gcd(a, b)) * b;
}

// LCM using prime factorization (naive approach)
int lcmUsingPrimeFactorization(int a, int b) {
    int lcm = 1;
    int factor = 2;

    while (a > 1 || b > 1) {
        bool divided = false;
        if (a % factor == 0) {
            a /= factor;
            divided = true;
        }
        if (b % factor == 0) {
            b /= factor;
            divided = true;
        }
        if (divided) {
            lcm *= factor;
        } else {
            factor++;
        }
    }
    return lcm;
}

// LCM using repeated addition
int lcmUsingRepeatedAddition(int a, int b) {
    int larger = max(a, b);
    int lcm = larger;

    while (lcm % a != 0 || lcm % b != 0) {
        lcm += larger;
    }
    return lcm;
}
```

