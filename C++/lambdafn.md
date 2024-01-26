```cpp
[capture](parameters) -> return_type {
    // function body
}
```

-   **capture:** Specifies what external variables are accessible inside the lambda function. It can be an empty capture ([]) if you don't need any external variables, or it can capture variables by value ([a, b]) or by reference ([&a, &b]).
-   **parameters** The input parameters of the lambda function, similar to a regular function.
-   **return_type:** The return type of the lambda function. If the lambda function does not return anything (i.e., it's a void function), you can omit this part.
-   **function body:** The actual code of the lambda function.

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
   // Example 1: Lambda function without parameters
   auto greet = []() {
       std::cout << "Hello, Lambda!" << std::endl;
   };
   greet();  // Call the lambda function

   // Example 2: Lambda function with parameters
   auto add = [](int a, int b) -> int {
       return a + b;
   };
   std::cout << "Sum: " << add(5, 3) << std::endl;

   // Example 3: Lambda function as a comparator for sorting
   std::vector<int> numbers = {5, 2, 8, 1, 7};
   std::sort(numbers.begin(), numbers.end(), [](int a, int b) {
       return a > b;  // Sort in descending order
   });

   for (int num : numbers) {
       std::cout << num << " ";
   }
   std::cout << std::endl;

   return 0;
}
```
