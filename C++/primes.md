# Check for prime

```cpp
// Checks all numbers from 2 to n-1.
bool isPrimeBruteForce(int n) {
    if (n <= 1) return false; // 0 and 1 are not prime numbers
    for (int i = 2; i < n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}


// Checks all numbers from 2 to root(n).
bool isPrimeImproved(int n) {
    if (n <= 1) return false;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return false;
    }
    return true;
}

/*The optimal method involves checking for divisibility by 2 and 3 first,
 then using the 6k ± 1 optimization. Any prime number greater than 3 can be written
 in the form of 6k±1.*/

// Checks divisibility by 2 and 3, then checks numbers in the form of 6k±1 up to root(n)
bool isPrimeOptimal(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i += 6) {
        // Check if n is divisible by i (6k - 1)
        if (n % i == 0) return false;
        // Check if n is divisible by i + 2 (6k + 1)
        if (n % (i + 2) == 0) return false;

    }
    return true;
}
```

# Sieve of Erathosenes

The Sieve of Eratosthenes is an efficient algorithm to find all prime numbers up to a given limit n. It works by iteratively marking the multiples of each prime number starting from 2.

```cpp
#include <iostream>
#include <vector>
using namespace std;

void sieveOfEratosthenes(int n) {
    // Initialize a boolean array with true values
    vector<bool> prime(n + 1, true);

    // Set 0 and 1 to false as they are not prime numbers
    prime[0] = prime[1] = false;

    // Start from the first prime number, which is 2
    for (int p = 2; p * p <= n; p++) {//log(log(n))
        // If prime[p] is not changed, then it is a prime
        if (prime[p]) {
            // Update all multiples of p to false
            //start from  i = p+p or i=p*p
            for (int i = p * p; i <= n; i += p) {//log(n)
                prime[i] = false;
            }
        }
    }

    // Print all prime numbers
    for (int p = 2; p <= n; p++) {//n*log(log(n))
        if (prime[p]) {//log(log(n))
            cout << p << " ";
        }
    }
    cout << endl;
}

int main() {
    int n = 50;
    cout << "Prime numbers up to " << n << " are: ";
    sieveOfEratosthenes(n);
    return 0;
}
```

## Get all Prime Factors of anumber

```cpp
unordered_map<int, int> getPrimeFactorsWithCounts(int n) {
    unordered_map<int, int> primeFactors;

    // Check for number of 2s that divide n
    while (n % 2 == 0) {
        primeFactors[2]++;
        n /= 2;
    }

    // n must be odd at this point so we can skip even numbers
    for (int i = 3; i <= sqrt(n); i += 2) {
        // While i divides n, add i and divide n
        while (n % i == 0) {
            primeFactors[i]++;
            n /= i;
        }
    }

    // This condition is to check if n is a prime number greater than 2
    if (n > 2) {
        primeFactors[n]++;
    }

    return primeFactors;
}
```

# Primes in range [L,R] (Segment Sieve)

```cpp
vector<bool>  sieve(int n) {
    vector<bool> prime(n + 1, true);
    prime[0] = prime[1] = false;
    for (int p = 2; p * p <= n; p++) {
        if (prime[p]) {
            for (int i = p * p; i <= n; i += p) {
                prime[i] = false;
            }
        }
    }
    return prime;
}

vector<bool> getPrimesInRange(long long L, long long R){
    long long limit = sqrt(R);
    vector<bool> isPrime = sieve(limit);
    vector<bool> primes(R - L + 1, true);
    for (long long i = 2; i*i <= R; i++) {
        if (isPrime[i]) {
            //start from first number >= L and is divisble by i*i
            for (long long j = max(i * i, (L + i - 1) / i * i); j <= R; j += i) {
                primes[j - L] = false;
            }
        }
    }
    if (L == 1) {
        primes[0] = false;
    }
    return primes;
}
int main(){
    vector<bool> ans =  getPrimesInRange(40, 50);
    for(int i=0; i<size(ans); ++i){
        if(ans[i] == true){
            cout << i+40 << " ";//41 43 47
        }
    }
}

```

## [Count Primes](https://leetcode.com/problems/count-primes/)

```cpp
class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) return 0;
        int cnt = 0;
        vector<int>prime (n+1, 1);
        prime[0] = prime[1] = 0;
        for(int i=2; i<n; ++i){
            if(prime[i]){
                cnt++;
                //mark all multiples of i as false, since they would neer be prime
                for(int j=2*i; j<n; j+=i){
                    prime[j] = 0;
                }
            }
        }
        return cnt;
    }
};
```

## [Four Divisors](https://leetcode.com/problems/four-divisors/)

### Brute

```cpp
class Solution {
public:
    pair<int, int> divisors(int n) {
        int sum = 0;
        int cnt = 0;
        for (int i = 1; i * i <= n; ++i) {
            if (n % i == 0) {
                if (i != n / i) {//dup divisior
                    sum += i + n / i;
                    cnt += 2;
                } else {
                    sum += i;
                    cnt++;
                }
                if (cnt > 4) break;
            }
        }
        return {cnt, sum};
    }
    int sumFourDivisors(vector<int>& nums) {
        int ans = 0;
        for(int i=0; i<size(nums); ++i){
            auto [f,l] = divisors(nums[i]);
            if(f == 4){
                ans += l;
            }
        }
        return ans;
    }
};
```

### Optimal using sieve

```cpp
class Solution {
public:
    pair<int, int> divisors(int n,  vector<int>& divisorCount,  vector<int>& divisorSum) {
        return {divisorCount[n], divisorSum[n]};
    }

    int sumFourDivisors(vector<int>& nums) {
        int maxNum = *max_element(nums.begin(), nums.end());
        vector<int> divisorCount(maxNum + 1, 0);
        vector<int> divisorSum(maxNum + 1, 0);

        // Sieve
        for (int i = 1; i <= maxNum; ++i) {
            for (int j = i; j <= maxNum; j += i) {
                divisorCount[j]++;
                divisorSum[j] += i;
            }
        }

        int ans = 0;
        for (int i = 0; i < nums.size(); ++i) {
            auto [count, sum] = divisors(nums[i], divisorCount, divisorSum);
            if (count == 4) {
                ans += sum;
            }
        }
        return ans;
    }
};
```

## [Most Frequent Prime](https://leetcode.com/problems/most-frequent-prime/description/)

```cpp
typedef pair<int, int> pii;

class Solution {
public:
    vector<pii> dirs = {{0, 1}, {1, 0}, {-1, 0}, {0, -1},
                        {1, 1}, {-1, -1}, {1, -1}, {-1, 1}};
    bool isPrime(int n) {
        if (n <= 1) return false;
        if (n <= 3) return true;
        if (n % 2 == 0 || n % 3 == 0) return false;
        for (int i = 5; i * i <= n; i += 6) {
            // Check if n is divisible by i (6k - 1)
            if (n % i == 0)
                return false;
            // Check if n is divisible by i + 2 (6k + 1)
            if (n % (i + 2) == 0)
                return false;
        }
        return true;
    }

    int mostFrequentPrime(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        unordered_map<int, int> mp;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                for (auto [f, l] : dirs) {
                    int digit = mat[i][j];
                    int newX = i + f, newY = j + l;
                    while (newX >= 0 && newX < m && newY >= 0 && newY < n) {
                        digit = digit * 10 + mat[newX][newY];
                        if (digit > 10 && isPrime(digit)) {
                            mp[digit]++;
                        }
                        newX += f;
                        newY += l;
                    }
                }
            }
        }

        if (mp.empty()) return -1;
        int freq = 0;
        int ans;
        for (auto it : mp) {
            if (it.second >= freq) {
                if (freq == it.second) ans = max(ans, it.first);
                else {
                    freq = it.second;
                    ans = it.first;
                }
            }
        }
        return ans;
    }
};

```
