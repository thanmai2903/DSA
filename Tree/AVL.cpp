#include <iostream>
using namespace std;

// Define the structure for an AVL Tree node
struct Node {
    int data;         // Data stored in the node
    Node* left;       // Pointer to the left child
    Node* right;      // Pointer to the right child
    int height;       // Height of the node

    // Constructor to initialize a new node with given value
    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
        height = 1;  // New node is initially added at leaf, so height is 1
    }
};

// Function to get the height of a node
int height(Node* node) {
    if (node == nullptr) {
        return 0;
    }
    return node->height;
}

// Function to get the balance factor of a node
int getBalanceFactor(Node* node) {
    if (node == nullptr) {
        return 0;
    }
    return height(node->left) - height(node->right);
}

// Function to perform a right rotation on a subtree rooted with y
Node* rightRotate(Node* y) {
    Node* x = y->left;      // x is the left child of y
    Node* T2 = x->right;    // T2 is the right child of x

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    // Return new root
    return x;
}

// Function to perform a left rotation on a subtree rooted with x
Node* leftRotate(Node* x) {
    Node* y = x->right;     // y is the right child of x
    Node* T2 = y->left;     // T2 is the left child of y

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    // Return new root
    return y;
}

// Function to insert a node into the AVL tree
Node* insert(Node* node, int key) {
    // 1. Perform the normal BST insertion
    if (node == nullptr) {
        return new Node(key);
    }

    if (key < node->data) {
        node->left = insert(node->left, key);   // Insert in the left subtree
    } else if (key > node->data) {
        node->right = insert(node->right, key); // Insert in the right subtree
    } else {
        // Equal keys are not allowed in BST
        return node;
    }

    // 2. Update the height of this ancestor node
    node->height = 1 + max(height(node->left), height(node->right));

    // 3. Get the balance factor of this ancestor node to check whether this node became unbalanced
    int balance = getBalanceFactor(node);

    // 4. If the node becomes unbalanced, then there are 4 cases:

    // Left Left Case
    if (balance > 1 && key < node->left->data) {
        return rightRotate(node);
    }

    // Right Right Case
    if (balance < -1 && key > node->right->data) {
        return leftRotate(node);
    }

    // Left Right Case
    if (balance > 1 && key > node->left->data) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left Case
    if (balance < -1 && key < node->right->data) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    // return the (unchanged) node pointer
    return node;
}

// Function to find the node with the minimum value in a tree
Node* minValueNode(Node* node) {
    Node* current = node;

    // Loop down to find the leftmost leaf
    while (current->left != nullptr) {
        current = current->left;
    }

    return current;
}

// Function to delete a node from the AVL tree
Node* deleteNode(Node* root, int key) {
    // 1. Perform standard BST delete
    if (root == nullptr) {
        return root;
    }

    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    } else {
        // Node with only one child or no child
        if ((root->left == nullptr) || (root->right == nullptr)) {
            Node* temp = root->left ? root->left : root->right;

            // No child case
            if (temp == nullptr) {
                temp = root;
                root = nullptr;
            } else {
                *root = *temp;  // One child case
            }

            delete temp;
        } else {
            // Node with two children: Get the inorder successor (smallest in the right subtree)
            Node* temp = minValueNode(root->right);

            // Copy the inorder successor's data to this node
            root->data = temp->data;

            // Delete the inorder successor
            root->right = deleteNode(root->right, temp->data);
        }
    }

    // If the tree had only one node, then return
    if (root == nullptr) {
        return root;
    }

    // 2. Update height of the current node
    root->height = 1 + max(height(root->left), height(root->right));

    // 3. Get the balance factor of this node to check whether this node became unbalanced
    int balance = getBalanceFactor(root);

    // 4. If this node becomes unbalanced, then there are 4 cases:

    // Left Left Case
    if (balance > 1 && getBalanceFactor(root->left) >= 0) {
        return rightRotate(root);
    }

    // Left Right Case
    if (balance > 1 && getBalanceFactor(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Right Case
    if (balance < -1 && getBalanceFactor(root->right) <= 0) {
        return leftRotate(root);
    }

    // Right Left Case
    if (balance < -1 && getBalanceFactor(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

// Function to perform in-order traversal of the AVL tree
void inOrder(Node* root) {
    if (root != nullptr) {
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }
}

// Main function to test the AVL tree implementation
int main() {
    Node* root = nullptr;  // Initialize the root of the AVL tree as nullptr

    // Insert nodes into the AVL tree
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

    // Print in-order traversal of the AVL tree
    cout << "In-order traversal of the constructed AVL tree is:" << endl;
    inOrder(root);
    cout << endl;

    // Delete a node from the AVL tree
    root = deleteNode(root, 30);

    // Print in-order traversal of the AVL tree after deletion
    cout << "In-order traversal after deletion of 30:" << endl;
    inOrder(root);
    cout << endl;

    return 0;
}
