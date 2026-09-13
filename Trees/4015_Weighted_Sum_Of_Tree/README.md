# Weighted Sum of a Tree

- You are given an integer array parent of length n representing a rooted tree with nodes labeled from 0 to n - 1.

- The tree is rooted at node 0, so parent[0] = -1. For each node i where 1 <= i <= n - 1, parent[i] denotes the parent of node i.

- You are also given an integer array nums of length n, where nums[i] denotes the value of node i.

- The weight of a node i at depth d is nums[i] * (h - d + 1), where h is the height of the tree.

Return the sum of the weights of all nodes in the tree.

The depth of a node is the number of nodes on the path from the root to that node, inclusive, with the root having depth 1.

The height of the tree is the maximum depth among all nodes in the tree.