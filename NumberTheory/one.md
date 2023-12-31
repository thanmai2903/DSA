1. #### Find factors of a number

**Approach 1**
This function has a time complexity of O(n), since it has to iterate through all n numbers.

```
void finding_factor_of_number(int n) {
  for (int i = 1; i <= n; i++) {
    if (n % i == 0) {
      cout << i << " is a factor" << endl;
    }
  }
}
```

**Approach 2**
This function has a time complexity of O(sqrt(n)), since it has to iterate through all n numbers.

If a number n is not a prime, it can be factored into two factors a and b. n = a _ b
Now a and b can't be both greater than the square root of n, since then the product a _ b would be greater than sqrt(n) \* sqrt(n) = n **So in any factorization of n, at least one of the factors must be less than or equal to the square root of n**

```
void find_factors(int number) {
  for (int factor = 1; factor * factor <= number; factor++) {
    if (number % factor == 0) {
      // Print the factor
      cout << factor << endl;

      // Check if factor and quotient are different (to avoid duplicates)
      if (number / factor != factor) {
        // Print the quotient (another factor)
        cout << number / factor << endl;
      }
    }
  }
}
```

-   and if we can't find any factors less than or equal to the square root,
    n must be a prime.
-   This means that if we loop from 2 to sqrt(x) and don't find any factors, then x must be a prime number

```
bool is_prime(int number) {
  // A prime number is a number that has only two factors: 1 and itself.

  // We can check if a number is prime by looping from 2 to the square root of the number.
  // If we find any factor in this range, then the number is not prime.

  for (int factor = 2; factor * factor <= number; factor++) {
    if (number % factor == 0) {
      // The number is not prime because it has a factor greater than 1.
      return false;
    }
  }

  // If we reach the end of the loop without finding any factors, then the number is prime.

  return true;
}
```

#### Sieve of Eratosthenes (used to mark all prime)

used to:

-   find all prime factor
-   all factor of number
-   Mark lowest prime
-   Mark highest Prime
-   Printing all Prime factor

say every number is prime then except 0 and 1, then we can say if 2 is prime all multiple of 2 is not prime then mark all multiple of 2 as false as its is not prime
eg ->

| Prime Numbers         | Multiples        |
| --------------------- | ---------------- |
| 2 4, 6, 8, 10, 12, 14 | , ... mark false |
| 3 6, 9, 12, 15, 18,   | ... mark false   |
| 4 8 ,12 ,16           | ... mark false   |
| 5 10, 15, 20, 25, 30, | ... mark false   |

```
const int N = 1e6+ 10;
vector<bool> Prime(N, 1);
void Seive()
{
    Prime[0] = Prime[1] = false;
    for (int i = 2; i < N; i++)
    {
        if (Prime[i])
        for (int j = 2 * i; j < N; j += i)
        Prime[j] = 0;
    }
   // Time Complexity: O(n*log(log(n)))
}
```

```
const int N = 1e6 + 10;
vector<bool> Prime(N, 1);
vector<int> lprime(N, 0), hprime(N, 0);

void Seive()
{
    Prime[0] = Prime[1] = false;
    for (int i = 2; i < N; i++)
    {
        if (Prime[i])
        {
            // Update smallest and highest prime factor as this is the first prime
            lprime[i] = hprime[i] = i;
            for (int j = 2 * i; j < N; j += i)
            {
                Prime[j] = 0; // Mark multiples as non-prime
                hprime[j] = i; // Update highest prime factor to the current prime

                // If smallest prime factor is not assigned yet, assign it
                if (lprime[j] == 0)
                {
                    lprime[j] = i;
                }
            }
        }
    }
}
```

#### Now we simple use these lowest prime and highest prime do more coolthings

1. Printing all prime factor of numbers ->Reason for this : All factors of a number are products of prime factors.

```
void Allprimefact(int num)
{
    map<int, int> primefac; // Here we have store prime factor and there frequencies
    // we will use these frequencies to solve many questions
    while (num > 1)
    {
        int lowprime = lprime[num]; // you can use high prime also
        while (num % lowprime == 0)
        {
            primefac[lowprime]++;
            num /= lowprime;
        }
    }
    for (auto [num, count] : primefac)
        cout << num << " " << count << endl;
}

2. Another use of sieves:-> Find all factor of a number
Actually here we have coded like seives but actually its not sieves() You can name it anything method according to your convenience

```

int const N=1e6+10;
vector<int>factor[N];

void allfactor()
{
for(int i=2;i<N;i++)
for (int j = i; j < N; j += i)
factor[j].push_back(i);
// you can also add 1 as factor
Time comp: O(nlog(n))
}

```


```
