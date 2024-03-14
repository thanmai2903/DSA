## STACK

1. empty, size, back, top, push, emplace, pop, swap push_back, pop_back

-   st.top() == st.back()
-   st.push(5) == st.emplace(5) == st.push_back(5)
-   st.pop() == st.pop_back()

```cpp
#include <iostream>
#include <stack>

int main() {
    std::stack<int> myStack;

    // Checking if stack is empty
    std::cout << "Is stack empty? " << (myStack.empty() ? "Yes" : "No") << std::endl;

    // Pushing elements into the stack
    myStack.push(1);
    myStack.push(2);
    myStack.push(3);

    // Getting the size of the stack
    std::cout << "Size of stack: " << myStack.size() << std::endl;

    // Accessing the top element of the stack
    std::cout << "Top element of stack: " << myStack.top() << std::endl;

    // Popping the top element from the stack
    myStack.pop();

    // Emplacing an element into the stack
    myStack.emplace(4);

    // Swapping contents of stacks
    std::stack<int> anotherStack;
    anotherStack.push(5);
    anotherStack.push(6);
    myStack.swap(anotherStack);

    // Outputting elements of the stack after swap
    std::cout << "Stack after swapping:" << std::endl;
    while (!myStack.empty()) {
        std::cout << myStack.top() << " ";
        myStack.pop();
    }
    std::cout << std::endl;

    // Pushing and popping using push_back() and pop_back()
    std::stack<int> vecStack;
    vecStack.push_back(7);
    vecStack.push_back(8);
    vecStack.push_back(9);
    std::cout << "Top element of vecStack: " << vecStack.back() << std::endl;
    vecStack.pop_back();

    return 0;
}
```
