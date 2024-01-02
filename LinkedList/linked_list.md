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

**Method 1**

```
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        vector<int> arr;
        while(head){
            int x = head->val;
            arr.push_back(x);
            head = head->next;
        }
        int i=0,j=arr.size()-1;
        while(i <= j){
            if(arr[i] != arr[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};
```

**Method 2 Explanation**:-

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
        ListNode* i = head;
        ListNode* j = slow;
        while(j){
            if(i->val != j->val) return false;
            i = i->next;
            j = j->next;
        }
        return true;
    }
};
```

5. [Delete Node](https://leetcode.com/problems/delete-node-in-a-linked-list/)

```

class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* nextNode = node->next;
        node->val = nextNode->val;
        node->next = nextNode->next;
    }
};
```

6. [Merge 2 sorted Linked lists](https://leetcode.com/problems/merge-two-sorted-lists/)

```
class Solution {
public:
    // Iteratively
    ListNode* mergeTwoLists1(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* cur = dummy;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                cur->next = l1;
                l1 = l1->next;
            } else {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        cur->next = l1 ? l1 : l2;
        return dummy->next;
    }

    // Recursively
    ListNode* mergeTwoLists2(ListNode* l1, ListNode* l2) {
        if (!l1 || !l2) {
            return l1 ? l1 : l2;
        }
        if (l1->val < l2->val) {
            l1->next = mergeTwoLists2(l1->next, l2);
            return l1;
        } else {
            l2->next = mergeTwoLists2(l1, l2->next);
            return l2;
        }
    }

    // In-place, iteratively
    ListNode* mergeTwoLists3(ListNode* l1, ListNode* l2) {
        if (!l1 || !l2) {
            return l1 ? l1 : l2;
        }
        ListNode* dummy = new ListNode(0);
        dummy->next = l1;
        ListNode* cur = dummy;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                l1 = l1->next;
            } else {
                ListNode* nxt = cur->next;
                cur->next = l2;
                ListNode* tmp = l2->next;
                l2->next = nxt;
                l2 = tmp;
            }
            cur = cur->next;
        }
        cur->next = l1 ? l1 : l2;
        return dummy->next;
    }
};

```

7. [Intersection of Two Linked Lists](https://leetcode.com/problems/intersection-of-two-linked-lists/description/)

**Explanation**:-

-   Take 2 pointer's: pointer A walks through List A and List B (since once it hits null, it goes to List B's head).

-   Pointer B also walks through List B and List A.

-   Regardless of the length of the two lists, the sum of the lengths are the same (i.e. a+b = b+a), which means that the pointers sync up at the point of intersection.

-   If the lists never intersected, it's fine too, because they'll sync up at the end of each list, both of which are null.

```
 class Solution {
     ListNode getIntersectionNode(ListNode* headA, ListNode* headB) {
        ListNode* a = headA;
        ListNode* b = headB;

        while(a != b){
            a = a == nullptr ? headB : a.next;
            b = b == nullptr ? headA : b.next;
        }
        return b;
    }
}

```

8. [Odd Even Linked List](https://leetcode.com/problems/odd-even-linked-list/)

**APPROACH** :

-   The idea is to split the linked list into 2 : one containing all odd nodes and other containing all even nodes. And finally, attach the even node linked list at the end of the odd node linked list.
-   To split the linked list into even nodes & odd nodes, we traverse the linked list and keep connecting the consecutive odd nodes and even nodes (to maintain the order of nodes) and save the pointer to the first even node.
-   Finally, we insert all the even nodes at the end of the odd node list.

```
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {

        if (!head || !head->next) {
            return head;
        }

        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* evenHead = even;

        while (even && even->next) {
            odd->next = even->next; //Connect all odds
            even->next = odd->next->next;  //Connect all evens
            odd = odd->next;
            even = even->next;
        }

        odd->next = evenHead;

        return head;
    }
};

```

9. [Swapping Nodes in a Linked List](https://leetcode.com/problems/swapping-nodes-in-a-linked-list)

```
    ListNode* curr = head;
        for(int i=0; i<k-1; ++i){
            curr = curr->next;
        }
        ListNode* left = curr;
        ListNode* right = head;
        while(curr->next){
            curr = curr->next;
            right = right->next;
        }
        swap(left->val, right->val);
        return head;
```

```
ListNode* swapNodes(ListNode* head, int k) {
        ListNode* curr = head;
        ListNode* left = head;
        ListNode* right = head;
        int counter = 1;
        while(curr!=NULL){
            if (counter<k){
                left = left->next;
            }
            if (counter>k){
                right = right->next;
            }
            curr = curr->next;
            counter++;
        }
        swap(left->val, right->val);
        return head;
    }
```
