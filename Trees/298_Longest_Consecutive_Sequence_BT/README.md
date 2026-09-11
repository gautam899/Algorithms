# Longest Consecutiv Sequence in BT

- You are given the root of a binary tree. Your task is to find the length of the longest consecutive sequence path in the tree.

- A consecutive sequence path is defined as a path where each node's value is exactly one more than its parent node's value in the path. For example, a path with values 1 → 2 → 3 is a consecutive sequence.

### Key constraints to note:

1. The path can start at any node in the tree (not necessarily the root)
2. The path must follow parent-to-child connections only (you cannot traverse from a child back to its parent)
3. The values must increase by exactly 1 at each step along the path