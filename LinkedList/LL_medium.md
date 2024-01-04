1. [Swap Nodes in Pairs](https://leetcode.com/problems/swap-nodes-in-pairs/)

Given a linked list, swap every two adjacent nodes and return its head. You must solve the problem without modifying the values in the list's nodes (i.e., only nodes themselves may be changed.)

```

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* temp = new ListNode(0);
        temp->next = head;
        ListNode* first = head;

        if (head != nullptr && head->next != nullptr) {
            first = head->next;
        }

        while (temp->next != nullptr && temp->next->next != nullptr) {
            ListNode* node1 = temp->next;
            ListNode* node2 = temp->next->next;
            temp->next = node2;
            node1->next = node2->next;
            node2->next = node1;
            temp = node1;
        }

        return first;

    }
};
```

2. [Split Linked List in parts](https://leetcode.com/problems/split-linked-list-in-parts/description/)
   Given the head of a singly linked list and an integer k, split the linked list into k consecutive linked list parts.

The length of each part should be as equal as possible: no two parts should have a size differing by more than one. This may lead to some parts being null.

The parts should be in the order of occurrence in the input list, and parts occurring earlier should always have a size greater than or equal to parts occurring later.

Return an array of the k parts.

**Approach**

-   We start by creating an array parts of size k to store the resulting linked list parts. Initially, all elements are set to nullptr.

-   We calculate the length of the input linked list by traversing it using a for loop. This helps us determine the size of each part.

-   We calculate two important values:

    -   n: The minimum guaranteed size of each part, obtained by dividing the total length by k.
    -   r: The number of extra nodes that need to be distributed among the first r parts, where r is the remainder of the division.

-   We initialize two pointers, node and prev, to traverse the linked list. node starts at the head of the linked list (root), and prev keeps track of the previous node.

-   We loop through each part of the result:

-   Store the current node as the start of the current part in the parts array.
-   Traverse n + 1 nodes if there are remaining extra nodes (when r > 0). Otherwise, traverse only n nodes.
-   After traversing, we disconnect the current part from the rest of the list by setting prev->next to nullptr. This ensures that each part is isolated.
-   Finally, we return the parts array containing the k parts of the linked list.

**Solution**

```
class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> ans(k,NULL);
        int sz = 0;
        ListNode* curr = head, *prev=nullptr;

        while (curr) {
            sz++;
            curr = curr->next;
        }

        int q = sz / k;
        int r = sz % k;
        curr = head;

        for (int i = 0; curr && i < k; i++,r--) {
            // Store the current node as the start of the current part.
            ans[i] = curr;
            // Traverse n + 1 nodes if there are remaining extra nodes (r > 0).
            // Otherwise, traverse only n nodes.
            for (int j = 0; j < q + (r > 0); j++) {
                prev = curr;
                curr = curr->next;
            }
            // Disconnect the current part from the rest of the list by setting prev->next to nullptr.
            prev->next = nullptr;
        }

        return ans;
    }
};
```

3. [Insertion Sort](https://leetcode.com/problems/insertion-sort-list/)

**Method 1**

```
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        for(auto cur = head; cur; cur = cur -> next)
            for(auto j = head; j != cur; j = j -> next)
                if(j -> val > cur -> val)
                    swap(j -> val, cur -> val);
        return head;
    }
};
```

**Method 2**

```
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy -> next = head;
        ListNode *pre = dummy, *cur = head;
        while (cur) {
            if ((cur -> next) && (cur -> next -> val < cur -> val)) {
                while ((pre -> next) && (pre -> next -> val < cur -> next -> val)) {
                    pre = pre -> next;
                }
                ListNode* temp = pre -> next;
                pre -> next = cur -> next;
                cur -> next = cur -> next -> next;
                pre -> next -> next = temp;
                pre = dummy;
            }
            else {
                cur = cur -> next;
            }
        }
        return dummy -> next;
    }
};
```

4. [Merge Sort](https://leetcode.com/problems/sort-list/)

```
class Solution:
    def sortList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head or not head.next:
            return head

        left = head
        right = self.get_mid(head)

        tmp = right.next
        right.next = None
        right = tmp

        left = self.sortList(left)
        right = self.sortList(right)

        return self.merge(left, right)

    def get_mid(self, head: ListNode) -> ListNode:
        fast = head
        slow = head

        while fast and fast.next and fast.next.next:
            slow = slow.next
            fast = fast.next.next

        return slow

    def merge(self, left: ListNode, right: ListNode) -> ListNode:
        merged = ListNode()
        ans = merged

        while left and right:
            if left.val < right.val:
                merged.next = left
                left = left.next
            else:
                merged.next = right
                right = right.next
            merged = merged.next

        if left:
            merged.next = left
        if right:
            merged.next = right

        return ans.next

```

5. [ Copy List with Random Pointer](https://leetcode.com/problems/copy-list-with-random-pointer/description/)

```
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*>mp;
        mp[NULL] = NULL;

        Node* curr = head;
        //cloning the linkedlist and conneccting to hash-map
        while(curr){
            Node* copy = new Node(curr->val);
            mp[curr] = copy;
            curr = curr->next;
        }

        //link all nodes
        curr = head;
        while(curr){
            Node* copy = mp[curr];
            copy->next = mp[curr->next];
            copy->random = mp[curr->random];
            curr = curr->next;
        }
        return mp[head];
    }
};
```
