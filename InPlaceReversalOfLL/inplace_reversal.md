# In-place Reversal of a LinkedList

In a lot of problems, we are asked to reverse the links between a set of nodes of a <b>LinkedList</b>. Often, the constraint is that we need to do this </i>in-place</i>, i.e., using the existing node objects and without using extra memory.

<b></i>in-place</i> Reversal of a LinkedList pattern</b> describes an efficient way to solve the above problem.

## Reverse a LinkedList (easy)

https://leetcode.com/problems/reverse-linked-list/

> Given the head of a Singly <b>LinkedList</b>, reverse the <b>LinkedList</b>. Write a function to return the new head of the reversed <b>LinkedList</b>.

To reverse a <b>LinkedList</b>, we need to reverse one node at a time. We will start with a variable `current` which will initially point to the head of the <b>LinkedList</b> and a variable `previous` which will point to the previous node that we have processed; initially `previous` will point to `null`.

In a stepwise manner, we will reverse the `current` node by pointing it to the `previous` before moving on to the next node. Also, we will update the `previous` to always point to the previous node that we have processed.

#### Way-1

```cpp
#include <iostream>

class ListNode {
public:
    int value;
    ListNode* next;
    ListNode(int val) : value(val), next(nullptr) {}
};

void printList(ListNode* head) {
    ListNode* temp = head;
    while (temp != nullptr) {
        std::cout << temp->value << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

ListNode* reverse(ListNode* head) {
    ListNode* current = head;
    ListNode* previous = nullptr;
    ListNode* next = nullptr;

    while (current != nullptr) {
        // Temporarily store the next node
        next = current->next;

        // Reverse the current node
        current->next = previous;

        // Before we move to the next node,
        // point previous to the current node
        previous = current;

        // Move on to the next node
        current = next;
    }

    return previous;
}

int main() {
    ListNode* head = new ListNode(2);
    head->next = new ListNode(4);
    head->next->next = new ListNode(6);
    head->next->next->next = new ListNode(8);
    head->next->next->next->next = new ListNode(10);

    std::cout << "Nodes of original LinkedList are: ";
    printList(head);

    ListNode* reversedHead = reverse(head);

    std::cout << "Nodes of reversed LinkedList are: ";
    printList(reversedHead);

    return 0;
}

```

#### Way-2

```cpp
#include <iostream>

class ListNode {
public:
    int value;
    ListNode* next;
    ListNode(int val) : value(val), next(nullptr) {}
    void printList() {
        ListNode* temp = this;
        while (temp != nullptr) {
            std::cout << temp->value << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
};

ListNode* reverse(ListNode* head) {
    ListNode* current = head;
    ListNode* previous = nullptr;
    ListNode* next = nullptr;

    while (current != nullptr) {
        // Temporarily store the next node
        next = current->next;

        // Reverse the current node
        current->next = previous;

        // Before we move to the next node,
        // point previous to the current node
        previous = current;

        // Move on to the next node
        current = next;
    }

    return previous;
}

int main() {
    ListNode* head = new ListNode(2);
    head->next = new ListNode(4);
    head->next->next = new ListNode(6);
    head->next->next->next = new ListNode(8);
    head->next->next->next->next = new ListNode(10);

    std::cout << "Nodes of original LinkedList are: ";
    head->printList();

    ListNode* reversedHead = reverse(head);

    std::cout << "Nodes of reversed LinkedList are: ";
    reversedHead->printList();

    return 0;
}
```

-   The time complexity of our algorithm will be `O(N)` where `N’` is the total number of nodes in the <b>LinkedList</b>.
-   We only used constant space, therefore, the space complexity of our algorithm is `O(1)`.

## Reverse a Sub-list (medium)

https://leetcode.com/problems/reverse-linked-list-ii/

> Given the head of a <b>LinkedList</b> and two positions `p` and `q`, reverse the <b>LinkedList</b> from position `p` to `q`.

The problem follows the <b></i>in-place</i> Reversal</b> of a <b>LinkedList</b> pattern. We can use a similar approach as discussed in <b>Reverse a LinkedList</b>. Here are the steps we need to follow:

1. Skip the first `p-1` nodes, to reach the node at position `p`.
2. Remember the node at position `p-1` to be used later to connect with the reversed sub-list.
3. Next, reverse the nodes from `p` to `q` using the same approach discussed in <b>Reverse a LinkedList</b>.
4. Connect the `p-1` and `q+1` nodes to the reversed sub-list.

```cpp
#include <iostream>

class Node {
public:
    int value;
    Node* next;

    Node(int val, Node* nextNode = nullptr) : value(val), next(nextNode) {}

    std::string getList() {
        std::string result = "";
        Node* temp = this;
        while (temp != nullptr) {
            result += std::to_string(temp->value) + " ";
            temp = temp->next;
        }
        return result;
    }
};

Node* reverseSubList(Node* head, int p, int q) {
    if (p == q) {
        return head;
    }

    Node* current = head;
    Node* previous = nullptr;

    int i = 0;

    while (current != nullptr && i < p - 1) {
        previous = current;
        current = current->next;
        i++;
    }

    const Node* lastNodeOfFirstPart = previous;
    const Node* lastNodeOfSubList = current;

    Node* next = nullptr;

    i = 0;

    while (current != nullptr && i < q - p + 1) {
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
        i++;
    }

    if (lastNodeOfFirstPart != nullptr) {
        lastNodeOfFirstPart->next = previous;
    } else {
        head = previous;
    }

    lastNodeOfSubList->next = current;

    return head;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    std::cout << "Nodes of original LinkedList are: " << head->getList() << std::endl;
    head = reverseSubList(head, 2, 4);
    std::cout << "Nodes of reversed LinkedList are: " << head->getList() << std::endl;

    // Free memory
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}

```

-   The time complexity of our algorithm will be `O(N)` where `N` is the total number of nodes in the <b>LinkedList</b>.
-   We only used constant space, therefore, the space complexity of our algorithm is `O(1)`.

> 🌟 Reverse the first `k` elements of a given <b>LinkedList</b>.

This problem can be easily converted to our parent problem; to reverse the first `k` nodes of the list, we need to pass `p=1` and `q=k`.

> 🌟 Given a <b>LinkedList</b> with `n` nodes, reverse it based on its size in the following way:
>
> 1. If `n` is even, reverse the list in a group of `n/2` nodes.
> 2. If `n` is odd, keep the middle node as it is, reverse the first `n/2` nodes and reverse the last `n/2` nodes.

When `n` is even we can perform the following steps:

1. Reverse first `n/2` nodes: `head = reverse(head, 1, n/2)`
2. Reverse last `n/2` nodes: `head = reverse(head, n/2 + 1, n)`

When `n` is odd, our algorithm will look like:

1. `head = reverse(head, 1, n/2)`
2. `head = reverse(head, n/2 + 2, n)`
   Please note the function call in the second step. We’re skipping two elements as we will be skipping the middle element.

## Reverse every K-element Sub-list (medium)

https://leetcode.com/problems/reverse-nodes-in-k-group/

> Given the head of a <b>LinkedList</b> and a number ‘k’, <b>reverse every ‘k’ sized sub-list</b> starting from the head.
> If, in the end, you are left with a sub-list with less than ‘k’ elements, reverse it too.

The problem follows the <b></i>in-place</i> Reversal of a LinkedList</b> pattern and is quite similar to <b>Reverse a Sub-list</b>. The only difference is that we have to reverse all the sub-lists. We can use the same approach, starting with the first sub-list (i.e. `p=1, q=k`) and keep reversing all the sublists of size ‘k’.

```cpp
#include <iostream>

class Node {
public:
    int value;
    Node* next;
    Node(int val, Node* nextNode = nullptr) : value(val), next(nextNode) {}

    std::string getList() {
        std::string result = "";
        Node* temp = this;
        while (temp != nullptr) {
            result += std::to_string(temp->value) + " ";
            temp = temp->next;
        }
        return result;
    }
};

Node* reverseEveryKElements(Node* head, int k) {
    // Edge cases
    if (k <= 1 || head == nullptr) {
        return head;
    }

    Node* current = head;
    Node* previous = nullptr;

    while (true) {
        Node* lastNodeOfPreviousPart = previous;

        // After reversing the LL current will become the last node of the sublist
        Node* lastNodeOfSubList = current;

        // Will be used to temporarily store the next node
        Node* next = nullptr;

        int i = 0;

        // Reverse k nodes
        while (current != nullptr && i < k) {
            next = current->next;
            current->next = previous;
            previous = current;
            current = next;
            i++;
        }

        // Connect with the previous part
        if (lastNodeOfPreviousPart != nullptr) {
            lastNodeOfPreviousPart->next = previous;
        } else {
            head = previous;
        }

        // Connect with the next part
        lastNodeOfSubList->next = current;

        if (current == nullptr) {
            break;
        }
        previous = lastNodeOfSubList;
    }
    return head;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);
    head->next->next->next->next->next->next = new Node(7);
    head->next->next->next->next->next->next->next = new Node(8);

    std::cout << "Nodes of original LinkedList are: " << head->getList() << std::endl;
    std::cout << "Nodes of reversed LinkedList are: " << reverseEveryKElements(head, 3)->getList() << std::endl;

    return 0;
}
```

-   The time complexity of our algorithm will be `O(N)` where `N` is the total number of nodes in the <b>LinkedList</b>.
-   We only used constant space, therefore, the space complexity of our algorithm is `O(1)`.

## 🌟 Reverse alternating K-element Sub-list (medium)

> Given the head of a <b>LinkedList</b> and a number `K`, <b>reverse every alternating `K` sized sub-list</b> starting from the head.
>
> If, in the end, you are left with a sub-list with less than `K` elements, reverse it too.

The problem follows the <b></i>in-place</i> Reversal of a LinkedList</b> pattern and is quite similar to <b>Reverse every K-element Sub-list</b>. The only difference is that we have to skip `K` alternating elements. We can follow a similar approach, and in each iteration after reversing `K` elements, we will skip the next `K` elements.

```cpp
#include <iostream>

class Node {
public:
    int value;
    Node* next;

    Node(int val, Node* nextNode = nullptr) : value(val), next(nextNode) {}

    void printList() {
        Node* temp = this;
        while (temp != nullptr) {
            std::cout << temp->value << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
};

Node* reverseAlternateKElements(Node* head, int k) {
    if (head == nullptr || k <= 1) return head;

    Node* current = head;
    Node* previous = nullptr;

    while (current != nullptr) {
        const Node* lastNodeOfPreviousPart = previous;
        const Node* lastNodeOfSubList = current;

        Node* next = nullptr;

        int i = 0;
        while (current != nullptr && i < k) {
            next = current->next;
            current->next = previous;
            previous = current;
            current = next;
            i++;
        }

        if (lastNodeOfPreviousPart != nullptr) {
            lastNodeOfPreviousPart->next = previous;
        } else {
            head = previous;
        }

        lastNodeOfSubList->next = current;

        i = 0;
        while (current != nullptr && i < k) {
            previous = current;
            current = current->next;
            i++;
        }
    }

    return head;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);
    head->next->next->next->next->next->next = new Node(7);
    head->next->next->next->next->next->next->next = new Node(8);

    std::cout << "Nodes of original LinkedList are: ";
    head->printList();
    Node* result = reverseAlternateKElements(head, 2);
    std::cout << "Nodes of reversed LinkedList are: ";
    result->printList();

    // Free memory
    while (result != nullptr) {
        Node* temp = result;
        result = result->next;
        delete temp;
    }

    return 0;
}
```

-   The time complexity of our algorithm will be `O(N)`where `N’` is the total number of nodes in the <b>LinkedList</b>.
-   We only used constant space, therefore, the space complexity of our algorithm is `O(1)`.

## 🌟 Rotate a LinkedList (medium)

https://leetcode.com/problems/rotate-list/

> Given the head of a Singly <b>LinkedList</b> and a number `K`, rotate the <b>LinkedList</b> to the right by `K` nodes.

Another way of defining the rotation is to take the sub-list of `K` ending nodes of the <b>LinkedList</b> and connect them to the beginning. Other than that we have to do three more things:

1. Connect the last node of the <b>LinkedList</b> to the head, because the list will have a different tail after the rotation.
2. The new head of the <b>LinkedList</b> will be the node at the beginning of the sublist.
3. The node right before the start of sub-list will be the new tail of the rotated <b>LinkedList</b>.

```cpp
#include <iostream>

class Node {
public:
    int value;
    Node* next;

    Node(int val, Node* nextNode = nullptr) : value(val), next(nextNode) {}

    std::string getList() {
        std::string result = "";
        Node* temp = this;
        while (temp != nullptr) {
            result += std::to_string(temp->value) + " ";
            temp = temp->next;
        }
        return result;
    }
};

Node* rotate(Node* head, int rotations) {
    if (head == nullptr || head->next == nullptr || rotations <= 0) return head;

    // Find the length and the last node of the list
    Node* lastNode = head;
    int listLength = 1;

    while (lastNode->next != nullptr) {
        lastNode = lastNode->next;
        listLength++;
    }

    // Connect the last node with the head to make it a circular list
    lastNode->next = head;

    // No need to do rotations more than the length of the list
    rotations %= listLength;
    int skipLength = listLength - rotations;
    Node* lastNodeOfRotatedList = head;

    for (int i = 0; i < skipLength - 1; i++) {
        lastNodeOfRotatedList = lastNodeOfRotatedList->next;
    }

    // lastNodeOfRotatedList->next is pointing to the sub-list of k ending nodes
    head = lastNodeOfRotatedList->next;
    lastNodeOfRotatedList->next = nullptr;

    return head;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);

    std::cout << "Nodes of original LinkedList are: " << head->getList() << std::endl;
    head = rotate(head, 3);
    std::cout << "Nodes of rotated LinkedList are: " << head->getList() << std::endl;

    // Free memory
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
```

-   The time complexity of our algorithm will be `O(N)` where `N’` is the total number of nodes in the <b>LinkedList</b>.
-   We only used constant space, therefore, the space complexity of our algorithm is `O(1)`.
