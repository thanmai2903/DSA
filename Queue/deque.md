## Deque

A deque is a data structure that allows insertion and deletion of elements from both ends, front and back.

deque<int> myDeque;

## Insertion and Deletion:

### Insert at the Front (push_front):

myDeque.push_front(1);

### Insert at the Back (push_back):

myDeque.push_back(2);

### Delete from the Front (pop_front):

myDeque.pop_front();

### Delete from the Back (pop_back):

myDeque.pop_back();

## Accessing Elements:

### Front Element (front):

int frontElement = myDeque.front();

### Back Element (back):

int backElement = myDeque.back();

## Extra Functions

1. myDeque.size()
2. myDeque.empty() -> return boolean

### 1. Iterating through a Deque:

```cpp
for (auto it = myDeque.begin(); it != myDeque.end(); ++it) {
    std::cout << *it << " ";
}

```

### 2. Erasing Elements:

```cpp
// Erase element at position 2
myDeque.erase(myDeque.begin() + 2);

```

### 3. Clearing the Deque:

```cpp
myDeque.clear();

```

### 4. Using Deque as a Queue or Stack:

```cpp
// Push
myDeque.push_back(1);
myDeque.push_back(2);

// Pop
myDeque.pop_back();
```
