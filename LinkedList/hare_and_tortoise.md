1. Check loop exists in a single linked list return true or false(Cycle Detection Algorithm)(Floyd's algo)

```
#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

bool hasCycle(ListNode* head) {
    if (head == nullptr || head->next == nullptr) {
        return false;  // No cycle in an empty list or a list with a single node
    }

    ListNode* slow = head;
    ListNode* fast = head;

    // Detect cycle using the fast and slow pointer approach
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            return true;  // Cycle detected
        }
    }

    return false;  // No cycle detected
}

int main() {
    // Example usage
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = head->next;  // Creating a cycle

    bool hasCycleResult = hasCycle(head);

    if (hasCycleResult) {
        cout << "The linked list has a cycle." << endl;
    } else {
        cout << "No cycle in the linked list." << endl;
    }

    // Don't forget to free the memory
    // ... (your code to delete the linked list)

    return 0;
}
```

2. If Cycle exists find he start node of the loop
   Floyd's Tortoise and Hare algorithm (fast and slow pointers)

```
#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

pair<bool, ListNode*> detectCycle(ListNode* head) {
    if (head == nullptr || head->next == nullptr) {
        return {false, nullptr};  // No cycle in an empty list or a list with a single node
    }

    ListNode* slow = head;
    ListNode* fast = head;

    // Detect cycle using the fast and slow pointer approach
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            // Cycle detected, now find the starting point of the cycle
            slow = head;
            while (slow != fast) {
                slow = slow->next;
                fast = fast->next;
            }

            return {true, slow};  // Return true and the starting point of the cycle
        }
    }

    return {false, nullptr};  // No cycle detected
}

int main() {
    // Example usage
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = head->next;  // Creating a cycle

    auto [hasCycle, startNode] = detectCycle(head);

    if (hasCycle) {
        cout << "The linked list has a cycle." << endl;
        cout << "Starting point of the cycle: " << startNode->val << endl;
    } else {
        cout << "No cycle in the linked list." << endl;
    }

    // Don't forget to free the memory
    // ... (your code to delete the linked list)

    return 0;
}
```

3. Find length of loop if in a linked list cycle exist.

```
#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

int detectCycleLength(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;
    bool hasCycle = false;

    // Detect cycle using the fast and slow pointer approach
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            hasCycle = true;
            break;
        }
    }

    if (!hasCycle) {
        return 0;  // No cycle, return null
    }

    // Find the length of the cycle
    int length = 1;
    fast = fast->next;  // Move fast pointer one step ahead

    while (slow != fast) {
        fast = fast->next;
        length++;
    }

    return length;
}

int main() {
    // Example usage
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = head->next;  // Creating a cycle

    int cycleLength = detectCycleLength(head);

    if (cycleLength > 0) {
        cout << "Length of the cycle: " << cycleLength << endl;
    } else {
        cout << "No cycle in the linked list." << endl;
    }

    // Don't forget to free the memory
    // ... (your code to delete the linked list)

    return 0;
}

```
