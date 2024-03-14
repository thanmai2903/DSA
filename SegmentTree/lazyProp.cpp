#include <bits/stdc++.h>
using namespace std;

void buildTree(vector<int>& tree, vector<int>& arr, int index, int low, int high) {
    if (low == high) {
        tree[index] = arr[low];
    } else {
        int mid = (low + high) >> 1;
        int left = index * 2, right = index * 2 + 1;
        buildTree(tree, arr, left, low, mid);
        buildTree(tree, arr, right, mid + 1, high);
        tree[index] = max(tree[left], tree[right]);
    }
}

void propagateLazy(vector<int>& tree, vector<int>& lazy, int index, int low, int high) {
    if (lazy[index] != 0) {
        tree[index] += lazy[index];
        if (low != high) {
            lazy[index * 2] += lazy[index];
            lazy[index * 2 + 1] += lazy[index];
        }
        lazy[index] = 0;
    }
}

void updateRange(vector<int>& tree, vector<int>& lazy, int index, int low, int high, int l, int r, int delta) {
    propagateLazy(tree, lazy, index, low, high);
    if (low > high || low > r || high < l) // disjoint
        return;
    if (l <= low && high <= r) { // complete overlap
        tree[index] += delta;
        if (low != high) {
            lazy[index * 2] += delta;
            lazy[index * 2 + 1] += delta;
        }
        return;
    }
    int mid = (low + high) >> 1;
    updateRange(tree, lazy, index * 2, low, mid, l, r, delta);
    updateRange(tree, lazy, index * 2 + 1, mid + 1, high, l, r, delta);
    tree[index] = max(tree[index * 2], tree[index * 2 + 1]); // merge function (max in this case)
}

int queryRange(vector<int>& tree, vector<int>& lazy, int index, int low, int high, int l, int r) {
    propagateLazy(tree, lazy, index, low, high);
    if (low > high || low > r || high < l) // disjoint
        return INT_MIN; // or a suitable neutral value
    if (l <= low && high <= r) // complete overlap
        return tree[index];
    int mid = (low + high) >> 1;
    int left = queryRange(tree, lazy, index * 2, low, mid, l, r);
    int right = queryRange(tree, lazy, index * 2 + 1, mid + 1, high, l, r);
    return max(left, right); // merge function (max in this case)
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8};
    vector<int> tree(4 * arr.size());
    vector<int> lazy(4 * arr.size());

    // Building initial segment tree
    buildTree(tree, arr, 1, 0, arr.size() - 1);

    // Example of lazy update
    updateRange(tree, lazy, 1, 0, 7, 2, 4, 2); // Add 2 to elements in range [2, 4]
    cout << queryRange(tree, lazy, 1, 0, 7, 1, 6) << endl; // Query in range [1, 6]

    return 0;
}
