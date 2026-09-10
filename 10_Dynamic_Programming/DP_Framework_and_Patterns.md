# Phase 10: Dynamic Programming (DP) Framework & Master Patterns

Dynamic Programming optimizes recursive problems by solving each overlapping subproblem **exactly once** and storing the result in a table (Memoization / Tabulation).

---

## 🎯 The 6-Step Systematic DP Framework

For every DP problem in FAANG interviews, follow these exact 6 steps:

```
[1. Identify Overlapping Subproblems & Optimal Substructure]
       ↓
[2. Define DP State: What does dp[i][j] represent?]
       ↓
[3. Formulate Mathematical Recurrence Relation]
       ↓
[4. State Base Cases & Constraints]
       ↓
[5. Top-Down (Memoization) → Bottom-Up (Tabulation)]
       ↓
[6. Space Optimization (Reduce Space by 1 Dimension)]
```

---

## 🗺️ The 8 Essential Interview DP Patterns

| Pattern | Description | Key Recurrence / Technique | Time | Space |
| :--- | :--- | :--- | :--- | :--- |
| **1D Linear DP** | Choice at index $i$ depends on previous $k$ states | $dp[i] = \text{op}(dp[i-1], dp[i-2])$ | $O(N)$ | $O(1)$ |
| **0/1 Knapsack** | Include or exclude item $i$ (weight limit $W$) | $dp[i][w] = \max(dp[i-1][w], v[i] + dp[i-1][w-wt[i]])$ | $O(N \cdot W)$ | $O(W)$ |
| **Unbounded Knapsack**| Unlimited supply of items | Loop weights $w = wt[i] \dots W$ | $O(N \cdot W)$ | $O(W)$ |
| **String Matching / LCS**| Operations on 2 strings | $dp[i][j] = dp[i-1][j-1] + 1$ (if match) | $O(N \cdot M)$ | $O(\min(N,M))$|
| **LIS Pattern** | Subsequence with increasing order | Binary Search + DP vector | $O(N \log N)$ | $O(N)$ |
| **Interval / MCM DP** | Splitting range $[i \dots j]$ at cut $k$ | $dp[i][j] = \min_{k} (dp[i][k] + dp[k+1][j] + \text{cost})$ | $O(N^3)$ | $O(N^2)$ |
| **DP on Trees** | Choice at node $u$ depends on subtrees | Post-order DFS traversal | $O(N)$ | $O(H)$ |
| **DP with Bitmasking**| Subset state represented as integer bitmask | $dp[\text{mask}][u]$ | $O(2^N \cdot N^2)$| $O(2^N \cdot N)$|

---

## 💡 Space Optimization Rule of Thumb
If `dp[i][j]` only depends on the previous row `dp[i-1]`, you can eliminate the 2D matrix and use **two 1D vectors** (`prev` and `curr`), reducing space from $O(N \cdot M)$ to $O(M)$!
