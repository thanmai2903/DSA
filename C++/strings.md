# 1. number to string

-   The `to_string` function from the <string> header is the most straightforward way to convert a number to a string.

```cpp
#include <iostream>
#include <string>

int main() {
    int num = 12345;

    // Convert int to string
    std::string str = std::to_string(num);
    std::cout << "String: " << str << std::endl;

    double dnum = 123.45;

    // Convert double to string
    std::string dstr = std::to_string(dnum);
    std::cout << "String: " << dstr << std::endl;

    return 0;
}
```

# 2. string to number

-   The `stoi` and `stol` functions from the <string> header are used to convert strings to integers.

```cpp
#include <iostream>
#include <string>

int main() {
    std::string str = "12345";

    // Convert string to int
    int num = std::stoi(str);
    std::cout << "Integer: " << num << std::endl;

    // Convert string to long
    long longNum = std::stol(str);
    std::cout << "Long: " << longNum << std::endl;

     std::string str1 = "123.45";

    // Convert string to float
    float fnum = std::stof(str1);
    std::cout << "Float: " << fnum << std::endl;

    // Convert string to double
    double dnum = std::stod(str1);
    std::cout << "Double: " << dnum << std::endl;

    // Convert string to long double
    long double ldnum = std::stold(str1);
    std::cout << "Long Double: " << ldnum << std::endl;

    return 0;
}
```

# 3. Character Handling Functions

In C++, the <cctype> header provides a variety of functions to classify and transform characters. Here is a list of common character handling functions along with descriptions and examples for each:

1. `isdigit`: Checks if the character is a digit (0-9).
2. `isalpha`: Checks if the character is an alphabetic letter (A-Z or a-z).
3. `isalnum`: Checks if the character is alphanumeric (A-Z, a-z, or 0-9).
4. `isupper`: Checks if the character is an uppercase letter (A-Z).
5. `islower`: Checks if the character is a lowercase letter (a-z).

```cpp
#include <iostream>
#include <cctype> // For character handling functions
#include <string>

int main() {
    // Sample characters
    char digit = '5';
    char alpha = 'G';
    char alnum = 'A';
    char upper = 'H';
    char lower = 'h';

    // 1. isdigit
    // Checks if the character is a digit (0-9)
    std::cout << digit << " is a digit: " << std::isdigit(digit) << std::endl;

    // 2. isalpha
    // Checks if the character is an alphabetic letter (A-Z or a-z)
    std::cout << alpha << " is an alphabetic character: " << std::isalpha(alpha) << std::endl;

    // 3. isalnum
    // Checks if the character is alphanumeric (A-Z, a-z, or 0-9)
    std::cout << alnum << " is an alphanumeric character: " << std::isalnum(alnum) << std::endl;

    // 4. isupper
    // Checks if the character is an uppercase letter (A-Z)
    std::cout << upper << " is an uppercase letter: " << std::isupper(upper) << std::endl;

    // 5. islower
    // Checks if the character is a lowercase letter (a-z)
    std::cout << lower << " is a lowercase letter: " << std::islower(lower) << std::endl;


    return 0;
}
```

# 5. Modifying strings

```cpp
#include <iostream>
#include <string>

int main() {
    std::string s = "Hello";

    // Append
    s += ", World!";
    std::cout << s << std::endl;

    // Insert
    s.insert(5, " C++");
    std::cout << s << std::endl;

    // Erase
    s.erase(5, 4);
    std::cout << s << std::endl;

    // Replace
    s.replace(7, 5, "C++ Programmers");
    std::cout << s << std::endl;

    return 0;
}
/*
Hello, World!
Hello C++, World!
Hello, World!
Hello, C++ Programmers!
*/
```

# 6. Substrings

```cpp
#include <iostream>
#include <string>

int main() {
    std::string s = "Hello, World!";
    std::string sub = s.substr(7, 5);

    std::cout << "Substring: " << sub << std::endl; // Output: "World"

    return 0;
}
```

# 7. Comparison

```cpp
#include <iostream>
#include <string>

int main() {
    std::string s1 = "Hello";
    std::string s2 = "World";

    if (s1 == s2) {
        std::cout << "s1 and s2 are equal" << std::endl;
    } else {
        std::cout << "s1 and s2 are not equal" << std::endl;
    }

    if (s1 < s2) {
        std::cout << "s1 is less than s2" << std::endl;
    }

    return 0;
}
```

# 8. Transform

```cpp
#include <iostream>
#include <string>
#include <algorithm>

int main() {
    std::string s = "Hello, World!";

    // Convert to uppercase
    std::transform(s.begin(), s.end(), s.begin(), ::toupper);
    std::cout << "Uppercase: " << s << std::endl;

    // Convert to lowercase
    std::transform(s.begin(), s.end(), s.begin(), ::tolower);
    std::cout << "Lowercase: " << s << std::endl;

    return 0;
}
/*
Uppercase: HELLO, WORLD!
Lowercase: hello, world!
*/
```

# 9. Iteration

```cpp
#include <iostream>
#include <string>

int main() {
    std::string s = "Hello, World!";

    // Using a range-based for loop
    for (char c : s) {
        std::cout << c << " ";
    }
    std::cout << std::endl;

    // Using an iterator
    for (std::string::iterator it = s.begin(); it != s.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    return 0;
}
```
