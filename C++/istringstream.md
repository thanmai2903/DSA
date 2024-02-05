## What is std::istringstream?

std::istringstream is a class in the C++ Standard Library that is part of the <sstream> header. It is derived from std::basic_istringstream, which is a template class that represents an input stream that reads from a string. The istringstream class is particularly useful when you want to treat a string as an input stream, allowing you to use stream extraction operators (>>) to parse formatted data from the string

**Notes:**

-   std::istringstream is commonly used for parsing strings, especially when dealing with formatted data.
-   It works similarly to std::cin (standard input stream) but reads from a string instead of user input.
-   Be cautious about the format of the string; incorrect formats may lead to extraction failures.

#### Ex-1.

```cpp
#include <iostream>
#include <sstream>
#include <string>

int main() {
    std::string myString = "123 45.67 hello";
    std::istringstream iss(myString);

    int intValue;
    float floatValue;
    std::string stringValue;

    iss >> intValue >> floatValue >> stringValue;

    if (iss.fail()) {
        std::cerr << "Extraction failed!" << std::endl;
    } else {
        std::cout << "Int: " << intValue << ", Float: " << floatValue << ", String: " << stringValue << std::endl;
    }

    return 0;
}
```

**Output**
Int: 123, Float: 45.67, String: hello

#### Ex-2

```cpp
#include <iostream>
#include <sstream>
#include <string>

int main() {
    std::string myString = "namaste tata see oho hello";
    std::istringstream iss(myString);
    std::string word;

    while (iss >> word) {
        std::cout << word << std::endl;
    }

    return 0;
}
```

**Output**
namaste
tata
see
oho
hello
