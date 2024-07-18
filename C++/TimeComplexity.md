# Time Complexity Analysis for Various Loop Structures

We'll start with single loops, then move to nested loops (both dependent and independent), and finally consider loops with more complex dependencies.

## Single Loop

**Example 1: Simple Single Loop**

```cpp
for (int i = 1; i <= n; i++) {
    // some O(1) operation
}
```

-   **Outer Loop:** Runs `n` times.
-   **Inner Operation:** Runs in \( O(1) \) time.

**Time Complexity:** \( O(n) \)

## Two Nested Loops

### Independent Nested Loops

**Example 2: Two Independent Loops with the Same Range**

```cpp
for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
        // some O(1) operation
    }
}
```

-   **Outer Loop:** Runs `n` times.
-   **Inner Loop:** Runs `n` times for each iteration of the outer loop.

**Time Complexity:** \( O(n) times O(n) = O(n^2) \)

**Example 3: Two Independent Loops with Different Ranges**

```cpp
for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
        // some O(1) operation
    }
}
```

-   **Outer Loop:** Runs `m` times.
-   **Inner Loop:** Runs `n` times for each iteration of the outer loop.

**Time Complexity:** \( O(m) times O(n) = O(m \cdot n) \)

### Dependent Nested Loops

**Example 4: Two Dependent Loops**

```cpp
for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= i; j++) {
        // some O(1) operation
    }
}
```

-   **Outer Loop:** Runs `n` times.
-   **Inner Loop:** Runs `i` times for each iteration of the outer loop.

To find the total number of operations, we sum the number of inner loop executions:

-   For i=1 => inner loop runs 1 time
-   For i=2 => inner loop runs 2 time
-   For i=3 => inner loop runs 3 time
    ....
-   For i=n => inner loop runs n time

=> 1+2+3+4+...+n = n\*(n+1)/2 == n^2

**Time Complexity:** \( O(n^2) \)

## Three Nested Loops

**Example 5: Triangular Pattern**

```cpp
for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= i; j++) {
        for (int k = 1; k <= j; k++) {
            // some O(1) operation
        }
    }
}
```

-   **Outer Loop:** Runs `n` times.
-   **Middle Loop:** Runs `i` times for each iteration of the outer loop.
-   **Inner Loop:** Runs `j` times for each iteration of the middle loop.

To find the total number of operations, we sum the number of inner loop executions:

$$
\sum*{i=1}^{n} \sum*{j=1}^{i} \sum*{k=1}^{j} 1 = \sum*{i=1}^{n} \sum*{j=1}^{i} j = \sum*{i=1}^{n} \frac{i(i+1)}{2} = \frac{n(n+1)(n+2)}{6}
$$

**Time Complexity:** \( O(n^3) \)

## Complex Dependent Loops

**Example 6: Inverted Triangular Pattern**

```cpp
for (int i = 1; i <= n; i++) {
    for (int j = i; j <= n; j++) {
        // some O(1) operation
    }
}
```

-   **Outer Loop:** Runs `n` times.
-   **Inner Loop:** Runs `n - i + 1` times for each iteration of the outer loop.

To find the total number of operations, we sum the number of inner loop executions:

$$ \sum*{i=1}^{n} (n - i + 1) = \sum*{i=1}^{n} i = \frac{n(n+1)}{2} $$

**Time Complexity:** \( O(n^2) \)

**Example 7: Multiplicative Dependent Loops**

```cpp
for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n / i; j++) {
        // some O(1) operation
    }
}
```

-   **Outer Loop:** Runs `n` times.
-   **Inner Loop:** Runs `n / i` times for each iteration of the outer loop.

To find the total number of operations, we sum the number of inner loop executions:

=> n/1 + n/2 +n/3 +...+n/n => n*(1+1/2+1/3+....1/n)
=> n*log(n)

This sum approximates to \( O(n \log n) \).

**Time Complexity:** \( O(n \log n) \)

**Example 8: Increment by Outer Loop Variable**

```cpp
for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n ; j+=i) {
        // some O(1) operation
    }
}
```

-   **Outer Loop:** Runs `n` times.
-   **Inner Loop:** Runs `n / i` times for each iteration of the outer loop.

To find the total number of operations, we sum the number of inner loop executions:

$$ \sum*{i=1}^{n} \frac{n}{i} = n \sum*{i=1}^{n} \frac{1}{i} $$

This sum approximates to \( O(n \log n) \).

**Time Complexity:** \( O(n \log n) \)

## Logarithmic and Other Patterns

**Example 9: Logarithmic Loop**

```cpp
for (int i = 1; i <= n; i *= 2) {
    // some O(1) operation
}
```

-   **Outer Loop:** Runs \( \log_2 n \) times as `i` doubles each time.

**Time Complexity:** \( O(\log n) \)

**Example 10: Logarithmic Nested Loops**

```cpp
for (int i = 1; i <= n; i *= 2) {
    for (int j = 1; j <= i; j++) {
        // some O(1) operation
    }
}
```

-   **Outer Loop:** Runs \( \log_2 n \) times as `i` doubles each time.
-   **Inner Loop:** Runs `i` times for each iteration of the outer loop.

To find the total number of operations, we sum the number of inner loop executions:

$$ \sum\_{k=0}^{\log_2 n} 2^k $$

This sum evaluates to \( 2^{\log_2 n + 1} - 1 = 2n - 1 \).

**Time Complexity:** \( O(n) \)

## Summary of Examples and Their Time Complexities

1. **Single Loop:**

    - Simple Single Loop: \( O(n) \)

2. **Two Independent Loops:**

    - Same Range: \( O(n^2) \)
    - Different Ranges: \( O(m \cdot n) \)

3. **Two Dependent Loops:**

    - Sum of Iterations: \( O(n^2) \)

4. **Three Nested Loops:**

    - Triangular Pattern: \( O(n^3) \)

5. **Complex Dependent Loops:**

    - Inverted Triangular Pattern: \( O(n^2) \)
    - Multiplicative Dependent Loops: \( O(n \log n) \)
    - Increment by Outer Loop Variable: \( O(n \log n) \)

6. **Logarithmic and Other Patterns:** - Logarithmic Loop: \( O(\log n) \) - Logarithmic Nested Loops: \( O(n) \)
   $$
