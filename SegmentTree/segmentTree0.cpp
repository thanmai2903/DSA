

#include <bits/stdc++.h>
using namespace std;

int merge(int x, int y){
  // return x + y;
  // return x^y;
  // return min(x,y);
}

void buildTree(vector<int>& tree, vector<int>& arr, int index, int low, int high) {
    if (low == high) {
        tree[index] = arr[low];
    } else {
        int mid = (low + high) >> 1;
        int left = index * 2, right = index * 2 + 1;
        buildTree(tree, arr, left, low, mid);
        buildTree(tree, arr, right, mid + 1, high);
        tree[index] = merge(tree[left], tree[right]);
    }
}

int rangeQuery(const vector<int>& tree, int index, int low, int high, int l, int r) {
    if (low > high || low > r || high < l) // disjoint -> not overlap
        return 0;
    if (l <= low && high <= r) // complete overlap -> node indices in b/w query indices
        return tree[index];
    int mid = (low + high) >> 1;
    int left = rangeQuery(tree, index * 2, low, mid, l, r);
    int right = rangeQuery(tree, index * 2 + 1, mid + 1, high, l, r);
    return merge(left, right);
}

void updateQuery(vector<int>& arr, vector<int>& tree, int index, int low, int high, int pos, int delta) {
    if (low == high) {
			arr[pos] = delta;
      tree[index] = arr[pos];
    } else {
        int mid = (low + high) >> 1;
        int left = index * 2, right = index * 2 + 1;
        if (mid >= pos) // goto left
            updateQuery(arr, tree, index * 2, low, mid, pos, delta);
        else // goto right
            updateQuery(arr, tree, index * 2 + 1, mid + 1, high, pos, delta);
        tree[index] = merge(tree[left], tree[right]);
    }
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8};
    vector<int> tree(4 * arr.size());
    buildTree(tree, arr, 1, 0, arr.size() - 1);
		cout<<"Original Tree: ";
    for (auto& e : tree) {
        cout << e << " ";
    }
    cout << endl;
    updateQuery(arr, tree, 1, 0, 7, 2, 5);
		cout<<"Updated Tree: ";
    for (auto& e : tree) {
        cout << e << " ";
    }
    cout << endl;
    cout << rangeQuery(tree, 1, 0, 7, 1, 3) << endl;
    return 0;
}