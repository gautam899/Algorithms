# Rod Cutting Problem

### Input

- A vector 'price' of length n where price[i] denotes the selling price of length i

### Output

- The problem requires us to find the maximum possible selling price after cutting the rod.

### Approach

- We can think of solving this problem using top down recursive solution and bottom up tabulation method.

- For a rod of length n, we have an option of cutting the rod in length ranging from 1->n. n is when the rod is sold without any cuts.

- Simply using rescursion results in exponential time complexity as total number of ways to cut a rod is O(2^n-1). Observing carefully we can point out that in this case we are doing more work than necessary i.e solving multiple subproblems repeatedly which can be memoized using dynamic programming.

- 