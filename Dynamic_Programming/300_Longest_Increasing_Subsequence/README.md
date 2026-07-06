# Longest Increasing Subsequence

### Approach 1: Brute Force DFS

- Ex: [1,2,,4,3] For every elements we have two choice either we can choose it to be a part of the subsequence. For n elements, in total we have total 2^n choice, hence the time complexity ends up O(2^N).

### Approach 2: Memoization

- Upon doing a dry run we realize that that we are doing a lot of re-work. We can memoize what we 
  have already evaluated using a 1-D array.