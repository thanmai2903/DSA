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
