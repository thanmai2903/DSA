# Segment Trees: Powerful Data Structures for Range Queries and Updates

-   A segment tree is a special type of **binary tree** that efficiently supports range queries and updates on an underlying array. It excels at solving problems where you need to find information about a specific subrange of elements in the array, such as
    -   Finding the sum of elements in a range
    -   Finding the minimum or maximum element in a range
    -   Counting the number of occurrences of a particular value within a range

##### When do u apply segment tee?

1. perform query on a range in O(logN) time - query means sum/prod/avg/max/min

-   updating the data should be in O(logN)time

##### NOTE

-   Segment tree is a Binary Tree which have interval info and operation.
-   Segment tree is Full Binary Tree(every node except leaf has 2 children)
-   A segment tree is a binary tree where each node represents an interval. Generally a node would store one or more properties of an interval which can be queried later.
-   A segment tree let's us process such queries efficiently in logarithmic order of time.

-   A segment tree for an n element range can be comfortably represented using an array of size ≈ 4∗n.
-   A node at index i can have two children at indexes (2∗i+1) and (2∗i+2) and parent at (i-1)/2.
    ![iokpo](https://leetcode.com/articles/Figures/segtree_intro_2.png)

-   Segment trees are very intuitive and easy to use when built recursively.

## 1. Build Tre from original data

```cpp
void buildSegTree(vector<int>& arr, int treeIndex, int lo, int hi)
{
    if (lo == hi) {                 // leaf node. store value in node.
        tree[treeIndex] = arr[lo];
        return;
    }

    int mid = lo + (hi - lo) / 2;   // recurse deeper for children.
    buildSegTree(arr, 2 * treeIndex + 1, lo, mid);
    buildSegTree(arr, 2 * treeIndex + 2, mid + 1, hi);

    // merge build results
    tree[treeIndex] = merge(tree[2 * treeIndex + 1], tree[2 * treeIndex + 2]);
}

// call this method as buildSegTree(arr, 0, 0, n-1);
// Here arr[] is input array and n is its size.
arr[] = { 18, 17, 13, 19, 15, 11, 20, 12, 33, 25 };
tree[] = { 183, 82, 101, 48, 34, 43, 58, 35, 13, 19, 15, 31, 12, 33, 25, 18, 17, 0, 0, 0, 0, 0, 0, 11, 20, 0, 0, 0, 0, 0, 0 };
```

## 2. Read/Query on an interval or segment of the data.

```cpp
int querySegTree(int treeIndex, int lo, int hi, int i, int j)
{
    // query for arr[i..j]
/*
....l0...hi....
..j..........i....
*/

    if (lo > j || hi < i)               // segment completely outside range
        return 0;                       // represents a null node

/*
....l0...hi....
..i..........j....
*/

    if (i <= lo && j >= hi)             // segment completely inside range
        return tree[treeIndex];

    int mid = lo + (hi - lo) / 2;       // partial overlap of current segment and queried range. Recurse deeper.

    if (i > mid)
        return querySegTree(2 * treeIndex + 2, mid + 1, hi, i, j);
    else if (j <= mid)
        return querySegTree(2 * treeIndex + 1, lo, mid, i, j);

    int leftQuery = querySegTree(2 * treeIndex + 1, lo, mid, i, mid);
    int rightQuery = querySegTree(2 * treeIndex + 2, mid + 1, hi, mid + 1, j);

    // merge query results
    return merge(leftQuery, rightQuery);
}

// call this method as querySegTree(0, 0, n-1, i, j);
// Here [i,j] is the range/interval you are querying.
// This method relies on "null" nodes being equivalent to storing zero.
```

## 3. Update the value of an element.

```cpp
void updateValSegTree(int treeIndex, int lo, int hi, int arrIndex, int val)
{
    if (lo == hi) {                 // leaf node. update element.
        tree[treeIndex] = val;
        return;
    }

    int mid = lo + (hi - lo) / 2;   // recurse deeper for appropriate child

    if (arrIndex > mid)
        updateValSegTree(2 * treeIndex + 2, mid + 1, hi, arrIndex, val);
    else if (arrIndex <= mid)
        updateValSegTree(2 * treeIndex + 1, lo, mid, arrIndex, val);

    // merge updates
    tree[treeIndex] = merge(tree[2 * treeIndex + 1], tree[2 * treeIndex + 2]);
}

// call this method as updateValSegTree(0, 0, n-1, i, val);
// Here you want to update the value at index i with value val.
```

-   3 cases
    overlap of find query b/w [i,j] and intervals

1. partial overlap -> look on left and right sides
2. total overlap (interval is in b/w [i,j]) -> stop and return val at that node
3. no overlap -> stop return max (if min query is asked)

-   if size of arr -> power of 2 let say 4 -> size of tree = 2*n-1 => 2*4-1 => 7
-   if size of arr -> not power of 2 let say 5 -> find next power of 2 > 5 => size of tree = 2*n-1 => 2*8-1 => 15
