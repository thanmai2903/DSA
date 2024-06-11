# Lazy Propagation in Segment Trees

Lazy propagation is an optimization technique used with Segment Trees to handle range updates efficiently. Let's dive into it step by step, with examples and visualizations.

## Segment Tree Recap

A Segment Tree is a binary tree used for storing intervals or segments. It allows for efficient range queries and updates.

### Normal Segment Tree Operations:
1. **Build Tree:** Construct the tree from the initial array.
2. **Query:** Find the sum/min/max of elements in a subarray.
3. **Update:** Change the value of an element or a range of elements.

## Problem with Normal Segment Trees

For range updates (updating a subarray), normal Segment Trees can be inefficient because they might need to update multiple nodes, leading to higher time complexity.

## Lazy Propagation Concept

Lazy propagation helps to defer updates to segments and only apply them when necessary, making range updates more efficient.

## Steps to Implement Lazy Propagation

1. **Initialize an extra `lazy` array:**
   - This array helps keep track of pending updates for each segment.

2. **Modify Update and Query Functions:**
   - Ensure that pending updates are applied before accessing a node.
   - Propagate pending updates to child nodes.

## Structure

- **Tree Array (`tree`):** Stores segment values.
- **Lazy Array (`lazy`):** Stores pending updates.



