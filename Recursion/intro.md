# Recursion

-   When a fn call itself when a specified condition is met is known as Recursion.
-   Recursion is a method of solving a problem where the solution depends on solutions to smaller instances of the same problem.
-   For an infinite loop, stackoverflow => **SEGMENTATION FAULT**
-   Decision + choices
-   Recursive Tree
-   Make Input Smaller
-   IP-OP Method
    ![o](https://assets.leetcode.com/users/images/3da869bb-17e8-4479-9629-23431ffb157f_1643541268.3172822.png)

**Ex:** Subset of "ab"
![t](https://assets.leetcode.com/users/images/11e8bbd2-0d4d-4a8c-8187-7a855d43bf80_1643541967.9300315.png)

-   When smaller"IP" becomes empty return the tree & get's the answer

### 2 steps to solve Recursion Problem

-   Design a recursive tree
-   F8ck the problem a.k.a Write the code

-   Recursion is used in
    -   Array/String
    -   Heap
    -   Stack
    -   Tree
    -   Graph [DFS]
    -   Linked List
-   Recursion is backbone of :- DP / BackTracking / Divide n Conquer

### 2 ways to solve a problem.

-   **Recursive Tree** -> IP/OP method [work's only if you know Decision]
-   **Base Condition-Induction-Hypothesis** -> [IBH] [only work when you don't have given choices & make IP smaller]

-   Hypothesis :- Work's like recursion tree
-   Induction :- let's say you have to print 1 to n all numbers, so the magic happen's called induction
-   Base Condition :- Work's only if you have "smallest valid Input" OR "smallest invalid iput"

## Que. Print 1 to n

So, we are only worried about making our input 1 step smaller, for the rest input it will work magically. And that magic is recursion
![i](https://assets.leetcode.com/users/images/27febad5-1405-4bcb-9140-6a6e718cd124_1643554221.7310085.png)

```cpp
void solve(int n){
    // Base condition
    if(n == 0) return;
    solve(n - 1); // Hypothesis
    cout << n; // Induction
  }
```

## Que. Print n to 1

![i](https://assets.leetcode.com/users/images/0bbb9755-deff-4112-b409-94c7e396dd5e_1643557294.5193331.png)

```cpp
void solve(int n){
    // Base condition
    if(n == 0) return;
    cout << n; // Induction
    solve(n - 1); // Hypothesis
  }
```

## Que. reverse an array

#### M-1.

```cpp
void reverse(int arr[], int start, int end){
    if(start >= end) return;
    swap(arr[start], arr[end]);
    reverse(arr, start + 1, end - 1);
}
```

#### M-2.

```cpp
void reverse(int arr[], int i=0, int n){
    if(i >= n/2) return;
    swpa(arr[i], arr[n-i-1]);
    reverse(arr, i+1, n);
}
```

## Que. Check if a string is a palindrome or not.

#### M-1.

```cpp
bool isPalindrome(string s, int start, int end){
    if(start >= end) return true;
    return s[start] == s[end] && isPalindrome(s, start + 1, end - 1);
}
```

#### m-2.

```cpp
bool isPalindrome(string s, int i=0, int n){
    if(i >= n/2) return true;
    if(s[i] != s[n-i-1]){
        return false;
    }
    return isPalindrome(s, i+1, n);
}
```

## Que. Fibonacii Number

```cpp
int fib(int n){
    if(n <= 1) return n;
    return fib(n-1) + fib(n-2);
}
```
