1. [Reversal of Linkedlist](https://leetcode.com/problems/reverse-linked-list/)

### Itervative Method

```
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* curr=head;
        ListNode* prev=NULL,*next=NULL;
        while(curr != NULL){
            //store next
            next = curr->next;
            //reverse the node
            curr->next=prev;
            //MOve ptrs ahead
            prev=curr;
            curr=next;
        }
        head=prev;
        return head;
    }

};

```

### Recursive Method

**Explanation**:-
We will create 2 pointer's fast & slow

Fast pointer will move at the speed of 2X

Slow pointer will move at the speed of 1X

If fast pointer reaches null or fast.next is null we will return our slow pointer which mean's our slow pointer is pointing at mid of linked list

```
class Solution {
public:
    ListNode* reverseList(ListNode *head, ListNode *prev = NULL) {
        if(!head) return prev;
        ListNode* nxt = head->next;
        head->next = prev;
        return  reverseList(nxt, head);
    }
};
```

2. [Middle of Linked List](https://leetcode.com/problems/middle-of-the-linked-list/)

### Brute force

```
#include <iostream>

class ListNode {
public:
    int val;
    ListNode* next;
    ListNode(int x)  {
        this->val = x;
        this->next = nullptr;
    }
};

class Solution {
public:
    ListNode* findMiddle(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head; // Return the only node or nullptr for an empty list
        }

        int count = 0;
        ListNode* current = head;

        // First pass: Count the number of nodes
        while (current != nullptr) {
            count++;
            current = current->next;
        }

        // Second pass: Move to the middle node
        current = head;
        for (int i = 0; i < count / 2; i++) {
            current = current->next;
        }

        return current;
    }
};

int main() {
    // Example usage
    Solution solution;

    // Creating a linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    ListNode* middleNode = solution.findMiddle(head);

    std::cout << "Middle Node Value: " << middleNode->val << std::endl;

    // Clean up memory (not shown in original code for brevity)
    return 0;
}
```

### fast and slow pointer method

```
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};
```

3. [Cycle in Linkedlist](https://leetcode.com/problems/linked-list-cycle/)

**Explanation**:-

-   We will create 2 pointer's fast & slow
-   Fast pointer will move at the speed of 2X
-   Slow pointer will move at the speed of 1X
-   If fast pointer & slow pointer meet each other we will return true otherwise they there is no cycle we will return false!!

```
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) return true;
        }
        return false;
    }
};
```

4. [Palindrome Linked List](https://leetcode.com/problems/palindrome-linked-list/)

**Explanation**:-

-   First we will get the mid so, that we can divide a linked list into two.
-   After that, we will reverse the half of the linked list
-   Then we have our slow pointer on new head & we will compare the value with old head i.e. head
-   We will check these value & move both the pointer's slow & head until slow reaches null.
-   If slow reaches null we will return true, otherwise false.

```
class Solution {
public:
    ListNode* reverse(ListNode* head) {
        if(head == NULL) return head;
        ListNode* curr = head;
        ListNode* prev = NULL;
        //ListNode* nxt = NULL;

        while(curr != NULL){
            ListNode* nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        head = prev;
        return head;
    }
    bool isPalindrome(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;

        while(fast != NULL && fast->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
        }
        slow = reverse(slow);
        while(slow != NULL && (slow->val == head->val)){
            head = head->next;
            slow = slow->next;
        }
        return slow == NULL;
    }
};
```
