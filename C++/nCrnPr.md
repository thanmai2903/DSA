### With using Factorial

```cpp
#include <iostream>
using namespace std;

// Function to calculate factorial
int factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

// Function to calculate nCr (Combinations)
int nCr(int n, int r) {
    if (r < 0 || r > n) {
        return 0;  // Invalid input
    }

    return factorial(n) / (factorial(r) * factorial(n - r));
}

// Function to calculate nPr (Permutations)
int nPr(int n, int r) {
    if (r < 0 || r > n) {
        return 0;  // Invalid input
    }

    return factorial(n) / factorial(n - r);
}

int main() {
    int n, r;
    cout << "Enter the value of n: ";
    cin >> n;
    cout << "Enter the value of r: ";
    cin >> r;

    cout << "nCr is: " << nCr(n, r) << endl;
    cout << "nPr is: " << nPr(n, r) << endl;

    return 0;
}
```

### Without using Factorial

```cpp
#include <iostream>
using namespace std;

// Function to calculate nCr (Combinations)
int nCr(int n, int r) {
    if (r < 0 || r > n) {
        return 0;  // Invalid input
    }

    int result = 1;
    for (int i = 1; i <= r; ++i) {
        result *= (n - i + 1);
        result /= i;
    }

    return result;
}

// Function to calculate nPr (Permutations)
int nPr(int n, int r) {
    if (r < 0 || r > n) {
        return 0;  // Invalid input
    }

    int result = 1;
    for (int i = 1; i <= r; ++i) {
        result *= (n - i + 1);
    }

    return result;
}

int main() {
    int n, r;
    cout << "Enter the value of n: ";
    cin >> n;
    cout << "Enter the value of r: ";
    cin >> r;

    cout << "nCr is: " << nCr(n, r) << endl;
    cout << "nPr is: " << nPr(n, r) << endl;

    return 0;
}
```
