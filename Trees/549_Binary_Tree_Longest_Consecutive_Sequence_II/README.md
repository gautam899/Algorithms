# Binary Tree Longest Consecutive Sequence II

## Description (This is leetcode Premium problem!)

- You are given the root of a binary tree and need to find the length of the longest consecutive path in the tree.

- A consecutive path consists of nodes where each consecutive pair of nodes has values that differ by exactly 1. The path can be either increasing (like [1,2,3,4]) or decreasing (like [4,3,2,1]). Mixed patterns like [1,2,4,3] are not valid consecutive paths.

- The key aspect of this problem is that the path doesn't have to follow the traditional parent-to-child direction. Instead, it can go through any connected nodes in the tree, including paths that go child-parent-child. This means a valid path could start from a node in the left subtree, go up through the parent, and continue down into the right subtree, as long as the values remain consecutive.

- For example, if you have a tree structure where a parent node has value 2, its left child has value 1, and its right child has value 3, then the path [1,2,3] going from left child through parent to right child would be a valid consecutive path of length 3.

## Intution

- The key insight is that any consecutive path passing through a node can be broken down into two parts: an increasing sequence and a decreasing sequence that meet at that node.

- Hence for every node, we return a pair [incr, decr]. incr is the maximum length of increasing consecutive sequence ending at the current node. Similarly decr is the maximum length of decreasing consecutive sequence ending at the current node.

- Base Case: For null node, return {0,0}, no path passing through null node.

- For every node intialize incr, decr to 1 each.

- Important thing to understand here is the difference between, increasing and decreasing sequence. We do not mean increasing from the node but rather a increasing consecutive sequence ending at the node. Same for the decreasing sequence.