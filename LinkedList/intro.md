#### Linked List

1. LnkedLists are used for storing the collections of data.(same as array for this point)

2. LL -> has data and a reference to the next node.

3. entry point of LL is head, Note that head is not a seperate node but a refrence to first node.

4. successive lements are connected by pointers.

5. can be made just as long as required(untill systems memory exhausts).

6. LL is an ADT because of insert, delete operations of main LL and deletelist, count, nthnodefromlast of auxillary LL.

#### why constant time for accessing array elements

```
memory_location = base_address + i * element_size
```

Here, base_address is the starting address of the array, i is the index, and element_size is the size of each element in the array. Since this calculation involves basic arithmetic operations and doesn't depend on the size of the array, the time complexity for accessing or modifying an element is considered constant.

7. Each node is allocated in a heap with a call to malloc(), so a node memory continues to exist untill its explicitly deallocated with a call to free().

#### LinkedList

| Advantages                                    | Disadvantages                                 |
| --------------------------------------------- | --------------------------------------------- |
| 1. Dynamic Nature                             | 1. More memory usage due to address pointer   |
| 2. Optimal insertion & deletion               | 2. Slow traversal compared to arrays          |
| 3. Stack's & queues can be easily implemented | 3. No reverse traversal in singly linked list |
| 4. No memory wastage                          | 4. No random access                           |

---

#### Real-life Application's :-

-   Previous - n - next page in browser
-   Image Viewer
-   Music Player

#### Types of LinkedList

**Singly-linked list**: linked list in which each node points to the next node and the last node points to null
**Doubly-linked list**: linked list in which each node has two pointers, p and n, such that p points to the previous node and n points to the next node; the last node's n pointer points to null
**Circular-linked list**: linked list in which each node points to the next node and the last node points back to the first node

#### Time Complexity:

-   Access: O(n)
-   Search: O(n)
-   Insert: O(1)
-   Remove: O(1)

#### Creation of linkedlist

![Creation of linkedlist](https://assets.leetcode.com/users/images/e8a78cc1-a75b-4f0d-ba57-92ef068afa32_1645841744.9345918.png)

**Output**:-

---

| 10 | --> | 20 | --> | 30 |

---

#### Traversal of linkedlist

![Traversing](https://assets.leetcode.com/users/images/40c57982-0dbb-4c9e-a420-033b64c5a0b0_1645842309.6500573.png)

#### Insertion of linkedlist

![Insertion](https://assets.leetcode.com/users/images/0298dacd-790b-4c55-b272-ba060cf3d702_1645842902.3864892.png)

```
void insertAtBeginning(Node*& head, int val) {
    Node* newNode = new Node(val);
    newNode->next = head;
    head = newNode;
}

// Function to insert a node at the end of a linked list
void insertAtEnd(Node*& head, int val) {
    Node* newNode = new Node(val);

    if (head == nullptr) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }

    temp->next = newNode;
}

// Function to insert a node at a given position in a linked list
void insertAtPosition(Node*& head, int val, int position) {
    Node* newNode = new Node(val);

    if (position == 0 || head == nullptr) {
        newNode->next = head;
        head = newNode;
        return;
    }

    Node* temp = head;
    for (int i = 0; i < position - 1 && temp != nullptr; ++i) {
        temp = temp->next;
    }

    if (temp == nullptr) {
        std::cerr << "Invalid position.\n";
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

```

#### Deletion of linkedlist

![Deletion](https://assets.leetcode.com/users/images/aa07476e-8016-4eb2-bb60-2e293cb57268_1645843792.401583.png)

```
 // Function to delete a node at the beginning of the linked list
    void deleteAtBeginning() {
        if (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    // Function to delete a node at the end of the linked list
    void deleteAtEnd() {
        if (!head)
            return;

        if (!head->next) {
            // If there is only one node, delete it
            delete head;
            head = nullptr;
            return;
        }

        Node* temp = head;
        while (temp->next->next)
            temp = temp->next;

        delete temp->next;
        temp->next = nullptr;
    }

    // Function to delete a node at a given position in the linked list
    void deleteAtPosition(int position) {
        if (!head || position <= 0)
            return;

        if (position == 1) {
            // If position is 1, delete the node at the beginning
            deleteAtBeginning();
            return;
        }

        Node* temp = head;
        for (int i = 1; i < position - 1 && temp; ++i)
            temp = temp->next;

        if (!temp || !temp->next)
            return; // Invalid position

        Node* toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
    }
```

**Deletion of entire linked list**

```
 // Function to delete the entire linked list
    void deleteList() {
        Node* current = head;
        Node* nextNode;

        while (current != nullptr) {
            nextNode = current->next;
            delete current;
            current = nextNode;
        }

        head = nullptr; // Set the head to null after deleting all nodes
    }
```

**Advantages of Doubly LinkedList**

1. for a given node in a list, we can navigate in both directions.
2. deletion of a node is easier(compared to singly linkedlist, here without traversing to get prev node, we drectly have prev pointer).

**DisAdvantages of Doubly LinkedList**

1. Each node requires extra pointer, requiring more space.
2. Insertion and deletion requires more operations than singly linkedlist.

3. circular linkedlist do not have ends.
4. In SCLL, each node has a successor not predecessor.
5. CLL can be singly or doubly linked.

#### A Memory-Efficient Doubly Linked List

```

 typedef struct listNode{
	int data;
	struct listNode * ptrdiff;
};
```

ptrdiff = exclusive or operation of "pointer to prev node" and "pointer to the next node"

#### Unrolled linkedlist

-   An unrolled linked list is a variation of a traditional linked list data structure where multiple elements are stored in each node.
-   In an unrolled linked list, however, a node contains multiple elements (not just one) and may also include a fixed-size array to hold these elements. This arrangement reduces the number of pointers needed, as each node stores more than one data element.

1. Display linkedlist from the end
   **Algo:** Traverse recursively till the end of the linkedlist. While coming back, start printing the elements.

```
void displayReverseLinkedList(Node* head) {
    // Base case: an empty list
    if (head == nullptr) {
        return;
    }

    // Recursive case: display the rest of the list in reverse order
    displayReverseLinkedList(head->next);

    // Print the current node's data
    std::cout << head->data << " ";
}

```

---

2. Check whether linkedlist length is even or odd
   **Algo:** Take a pointer that moves at 2x[two nodes at a time]. At the end, if the length is even, the pointer will be NULL; otherwse it will point to last node.

```
int f(ListNode* head){
    while(head && head->next){
        head = head->next->next;
    }
    if(head) return 0;//even
    return 1; //odd
}
```

3. If the head of the ll is pointing to kth node, how will u get the elements before kth element
