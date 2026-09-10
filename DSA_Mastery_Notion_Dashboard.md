# 🚀 Complete DSA Mastery Tracker & Study System (Top MNC / FAANG Target)

> **"Mastery is not about solving 1000 random problems. It is about deeply internalizing ~200 canonical problem patterns, deconstructing redundancies, and proving optimal solutions effortlessly."**

---

## 📥 How to Import this Tracker into Notion (1-Click Setup)

You have a ready-to-import database file: `DSA_LeetCode_Tracker.csv` in this repository!

### ⚡ 3-Step Setup in Notion:
1. **Open Notion** $\to$ Click **`+ New Page`** in your sidebar.
2. In the new blank page, click the **`...`** (top right) $\to$ Select **`Import`** $\to$ Choose **`CSV`**.
3. Select the file:
   `c:\Users\Dell\OneDrive\Documents\Data Structures and Algorithms\DSA_LeetCode_Tracker.csv`

🎉 **Notion will instantly generate a full, interactive database with all 194 problems pre-categorized with Phase, Sub-Topic, Difficulty, URLs, and Key Intuition!**

---

## 🎨 Recommended Notion Views to Create in Your Database

Once imported, click the **`+`** button next to the view tab to add these 4 high-productivity views:

```
+-----------------------------------------------------------------------------------+
| [📋 Kanban Board] | [📊 Phase Roadmap] | [🔥 Revision Queue] | [⭐ High Confidence] |
+-----------------------------------------------------------------------------------+
```

1. **📋 Kanban Board View (Progress Tracking)**:
   - Layout: **Board**
   - Group by: **`Status`** (`Not Started` $\to$ `In Progress` $\to$ `Solved` $\to$ `Needs Revisit`).
   - Card preview: **None** | Properties shown: `Difficulty`, `Phase`, `LeetCode URL`, `Confidence`.

2. **📊 Phase Roadmap View (Structured Progression)**:
   - Layout: **Table**
   - Group by: **`Phase`**
   - Sort by: **`Order` (Ascending)**
   - Shows problems in the exact pedagogical order you should solve them!

3. **🔥 Revision Queue View (Spaced Repetition)**:
   - Layout: **Table** / **List**
   - Filter: `Status is Needs Revisit` OR `Confidence is ⭐ or ⭐⭐`.
   - Use this before every mock interview or company OA.

4. **🎯 Difficulty Breakdown View**:
   - Filter by: `Difficulty` (`Easy` for warmup $\to$ `Medium` for core $\to$ `Hard` for edge mastery).

---

## 📝 7-Step Analytical Template (Paste this inside every Notion problem card)

Whenever you open a problem in Notion, write your notes using this exact interview structure:

```markdown
### 1. Problem Constraints & Clues
- Input constraints: (e.g. N <= 10^5 => O(N log N) or O(N) required)
- Edge cases: (empty, single element, negatives, duplicates, INT_MIN/INT_MAX)

### 2. Brute Force Approach
- Intuition:
- Bottleneck (What is redundant?):
- Time: O(...) | Space: O(...)

### 3. Better Approach
- Optimization technique:
- What redundant work is eliminated?
- Time: O(...) | Space: O(...)

### 4. Optimal Approach & Proof
- Core pattern:
- Invariant / Mathematical proof:
- Time: O(...) | Space: O(...)

### 5. Dry Run / Visual Diagram
- Pointer states / Memory stack trace:

### 6. C++ Code Snippet & Edge Case Handling
- Pointers, STL container mechanics, edge branches

### 7. Core Takeaway / "Aha!" Moment
- If I see [Signal X], I should immediately think of [Pattern Y]!
```

---

## 🗺️ Master Curriculum Phase-by-Phase Checklist

Below is your master curriculum with direct LeetCode links and links to your local C++ notes.

---

### Phase 1: Complexity Analysis & Math Foundations
*Workspace Reference*: [TimeComplexity_and_Recurrence.md](file:///c:/Users/Dell/OneDrive/Documents/Data%20Structures%20and%20Algorithms/01_Foundations_and_Math/TimeComplexity_and_Recurrence.md) | [BitManipulation.cpp](file:///c:/Users/Dell/OneDrive/Documents/Data%20Structures%20and%20Algorithms/01_Foundations_and_Math/BitManipulation.cpp) | [NumberTheory.cpp](file:///c:/Users/Dell/OneDrive/Documents/Data%20Structures%20and%20Algorithms/01_Foundations_and_Math/NumberTheory.cpp)

- [ ] [LC 136. Single Number](https://leetcode.com/problems/single-number/) `Easy` — XOR reduction
- [ ] [LC 191. Number of 1 Bits](https://leetcode.com/problems/number-of-1-bits/) `Easy` — Brian Kernighan
- [ ] [LC 338. Counting Bits](https://leetcode.com/problems/counting-bits/) `Easy` — Bitwise DP
- [ ] [LC 231. Power of Two](https://leetcode.com/problems/power-of-two/) `Easy` — `n & (n - 1) == 0`
- [ ] [LC 190. Reverse Bits](https://leetcode.com/problems/reverse-bits/) `Easy` — Bit shifts
- [ ] [LC 260. Single Number III](https://leetcode.com/problems/single-number-iii/) `Medium` — LSB mask partitioning
- [ ] [LC 137. Single Number II](https://leetcode.com/problems/single-number-ii/) `Medium` — Modulo 3 bit states
- [ ] [LC 201. Bitwise AND of Numbers Range](https://leetcode.com/problems/bitwise-and-of-numbers-range/) `Medium` — Common prefix shift
- [ ] [LC 371. Sum of Two Integers](https://leetcode.com/problems/sum-of-two-integers/) `Medium` — XOR + Carry
- [ ] [LC 78. Subsets (Bitmask)](https://leetcode.com/problems/subsets/) `Medium` — $2^N$ bitmasks
- [ ] [LC 204. Count Primes](https://leetcode.com/problems/count-primes/) `Medium` — Sieve of Eratosthenes
- [ ] [LC 50. Pow(x, n)](https://leetcode.com/problems/powx-n/) `Medium` — Binary Exponentiation
- [ ] [LC 172. Factorial Trailing Zeroes](https://leetcode.com/problems/factorial-trailing-zeroes/) `Medium` — Legendre formula
- [ ] [LC 149. Max Points on a Line](https://leetcode.com/problems/max-points-on-a-line/) `Hard` — GCD slope normalization
- [ ] [LC 60. Permutation Sequence](https://leetcode.com/problems/permutation-sequence/) `Hard` — Factorial math indexing

---

### Phase 2: Arrays, Two Pointers & Sliding Window
*Workspace Reference*: [TwoPointers.cpp](file:///c:/Users/Dell/OneDrive/Documents/Data%20Structures%20and%20Algorithms/02_Arrays_and_Pointers/TwoPointers.cpp) | [SlidingWindow.cpp](file:///c:/Users/Dell/OneDrive/Documents/Data%20Structures%20and%20Algorithms/02_Arrays_and_Pointers/SlidingWindow.cpp) | [PrefixSum.cpp](file:///c:/Users/Dell/OneDrive/Documents/Data%20Structures%20and%20Algorithms/02_Arrays_and_Pointers/PrefixSum.cpp)

#### Array Mechanics & Kadane
- [ ] [LC 53. Maximum Subarray](https://leetcode.com/problems/maximum-subarray/) `Medium` — Kadane's algorithm
- [ ] [LC 121. Best Time to Buy and Sell Stock](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/) `Easy` — Running minimum
- [ ] [LC 152. Maximum Product Subarray](https://leetcode.com/problems/maximum-product-subarray/) `Medium` — Dual min/max state
- [ ] [LC 75. Sort Colors](https://leetcode.com/problems/sort-colors/) `Medium` — Dutch National Flag 3-pointer
- [ ] [LC 31. Next Permutation](https://leetcode.com/problems/next-permutation/) `Medium` — Pivot & suffix reverse
- [ ] [LC 56. Merge Intervals](https://leetcode.com/problems/merge-intervals/) `Medium` — Interval sorting
- [ ] [LC 57. Insert Interval](https://leetcode.com/problems/insert-interval/) `Medium` — 3-stage sweep
- [ ] [LC 48. Rotate Image](https://leetcode.com/problems/rotate-image/) `Medium` — Transpose + Reverse
- [ ] [LC 73. Set Matrix Zeroes](https://leetcode.com/problems/set-matrix-zeroes/) `Medium` — First row/col markers
- [ ] [LC 54. Spiral Matrix](https://leetcode.com/problems/spiral-matrix/) `Medium` — 4-boundary contraction

#### Two Pointers
- [ ] [LC 167. Two Sum II - Input Array Is Sorted](https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/) `Medium` — Opposite pointers
- [ ] [LC 15. 3Sum](https://leetcode.com/problems/3sum/) `Medium` — Sorting + 2-pointer scan
- [ ] [LC 18. 4Sum](https://leetcode.com/problems/4sum/) `Medium` — Quadruplets with long long check
- [ ] [LC 11. Container With Most Water](https://leetcode.com/problems/container-with-most-water/) `Medium` — Squeeze shorter wall
- [ ] [LC 42. Trapping Rain Water](https://leetcode.com/problems/trapping-rain-water/) `Hard` — Two pointers $O(1)$ space
- [ ] [LC 26. Remove Duplicates from Sorted Array](https://leetcode.com/problems/remove-duplicates-from-sorted-array/) `Easy` — Fast & Slow pointers
- [ ] [LC 283. Move Zeroes](https://leetcode.com/problems/move-zeroes/) `Easy` — In-place swap

#### Sliding Window
- [ ] [LC 643. Maximum Average Subarray I](https://leetcode.com/problems/maximum-average-subarray-i/) `Easy` — Fixed window
- [ ] [LC 438. Find All Anagrams in a String](https://leetcode.com/problems/find-all-anagrams-in-a-string/) `Medium` — Frequency match window
- [ ] [LC 3. Longest Substring Without Repeating Characters](https://leetcode.com/problems/longest-substring-without-repeating-characters/) `Medium` — Variable window map
- [ ] [LC 424. Longest Repeating Character Replacement](https://leetcode.com/problems/longest-repeating-character-replacement/) `Medium` — Max freq window
- [ ] [LC 1004. Max Consecutive Ones III](https://leetcode.com/problems/max-consecutive-ones-iii/) `Medium` — At most K zeroes
- [ ] [LC 76. Minimum Window Substring](https://leetcode.com/problems/minimum-window-substring/) `Hard` — Dynamic shrink window
- [ ] [LC 992. Subarrays with K Different Integers](https://leetcode.com/problems/subarrays-with-k-different-integers/) `Hard` — `Exactly(K) = AtMost(K) - AtMost(K-1)`
- [ ] [LC 1248. Count Number of Nice Subarrays](https://leetcode.com/problems/count-number-of-nice-subarrays/) `Medium` — At Most K trick

#### Prefix Sum & Difference Array
- [ ] [LC 560. Subarray Sum Equals K](https://leetcode.com/problems/subarray-sum-equals-k/) `Medium` — Hash Map prefix sum
- [ ] [LC 974. Subarray Sums Divisible by K](https://leetcode.com/problems/subarray-sums-divisible-by-k/) `Medium` — Modulo prefix map
- [ ] [LC 525. Contiguous Array](https://leetcode.com/problems/contiguous-array/) `Medium` — 0 as -1 and 1 as +1
- [ ] [LC 238. Product of Array Except Self](https://leetcode.com/problems/product-of-array-except-self/) `Medium` — Prefix & suffix products
- [ ] [LC 1109. Corporate Flight Bookings](https://leetcode.com/problems/corporate-flight-bookings/) `Medium` — Difference array
- [ ] [LC 1094. Car Pooling](https://leetcode.com/problems/car-pooling/) `Medium` — Difference array

---

### Phase 3: Binary Search Mastery
*Workspace Reference*: [BinarySearch_Guide.md](file:///c:/Users/Dell/OneDrive/Documents/Data%20Structures%20and%20Algorithms/03_Binary_Search/BinarySearch_Guide.md) | [BinarySearch_1D_2D.cpp](file:///c:/Users/Dell/OneDrive/Documents/Data%20Structures%20and%20Algorithms/03_Binary_Search/BinarySearch_1D_2D.cpp) | [BinarySearch_SearchSpace.cpp](file:///c:/Users/Dell/OneDrive/Documents/Data%20Structures%20and%20Algorithms/03_Binary_Search/BinarySearch_SearchSpace.cpp)

#### 1D & 2D Binary Search
- [ ] [LC 704. Binary Search](https://leetcode.com/problems/binary-search/) `Easy` — Standard template
- [ ] [LC 35. Search Insert Position](https://leetcode.com/problems/search-insert-position/) `Easy` — Lower bound
- [ ] [LC 34. Find First and Last Position of Element](https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/) `Medium` — Lower + Upper bound
- [ ] [LC 33. Search in Rotated Sorted Array](https://leetcode.com/problems/search-in-rotated-sorted-array/) `Medium` — Sorted half determination
- [ ] [LC 81. Search in Rotated Sorted Array II](https://leetcode.com/problems/search-in-rotated-sorted-array-ii/) `Medium` — Duplicate handling
- [ ] [LC 153. Find Minimum in Rotated Sorted Array](https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/) `Medium` — Inflection point
- [ ] [LC 162. Find Peak Element](https://leetcode.com/problems/find-peak-element/) `Medium` — Slope climbing
- [ ] [LC 540. Single Element in a Sorted Array](https://leetcode.com/problems/single-element-in-a-sorted-array/) `Medium` — Even/odd index pairing
- [ ] [LC 74. Search a 2D Matrix](https://leetcode.com/problems/search-a-2d-matrix/) `Medium` — Virtual 1D index
- [ ] [LC 240. Search a 2D Matrix II](https://leetcode.com/problems/search-a-2d-matrix-ii/) `Medium` — Staircase search

#### Binary Search on Search Space
- [ ] [LC 875. Koko Eating Bananas](https://leetcode.com/problems/koko-eating-bananas/) `Medium` — Speed search space
- [ ] [LC 1011. Capacity To Ship Packages Within D Days](https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/) `Medium` — Capacity search space
- [ ] [LC 410. Split Array Largest Sum](https://leetcode.com/problems/split-array-largest-sum/) `Hard` — Book allocation
- [ ] [LC 1552. Magnetic Force Between Two Balls](https://leetcode.com/problems/magnetic-force-between-two-balls/) `Medium` — Aggressive cows
- [ ] [LC 4. Median of Two Sorted Arrays](https://leetcode.com/problems/median-of-two-sorted-arrays/) `Hard` — Dual partition cut
- [ ] [LC 378. Kth Smallest Element in a Sorted Matrix](https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/) `Medium` — Value search space + staircase count
- [ ] [LC 719. Find K-th Smallest Pair Distance](https://leetcode.com/problems/find-k-th-smallest-pair-distance/) `Hard` — Two pointers inside binary search

---

### Phase 4: Strings & Advanced Pattern Matching
*Workspace Reference*: [PatternMatching_Guide.md](file:///c:/Users/Dell/OneDrive/Documents/Data%20Structures%20and%20Algorithms/04_Strings/PatternMatching_Guide.md) | [PatternMatching.cpp](file:///c:/Users/Dell/OneDrive/Documents/Data%20Structures%20and%20Algorithms/04_Strings/PatternMatching.cpp)

- [ ] [LC 125. Valid Palindrome](https://leetcode.com/problems/valid-palindrome/) `Easy` — Two pointers
- [ ] [LC 14. Longest Common Prefix](https://leetcode.com/problems/longest-common-prefix/) `Easy` — Vertical scanning
- [ ] [LC 151. Reverse Words in a String](https://leetcode.com/problems/reverse-words-in-a-string/) `Medium` — In-place two-pass reverse
- [ ] [LC 8. String to Integer (atoi)](https://leetcode.com/problems/string-to-integer-atoi/) `Medium` — Finite automata / Clamp
- [ ] [LC 28. Find the Index of the First Occurrence](https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/) `Easy` — KMP algorithm with LPS
- [ ] [LC 459. Repeated Substring Pattern](https://leetcode.com/problems/repeated-substring-pattern/) `Easy` — KMP LPS prefix periodicity
- [ ] [LC 214. Shortest Palindrome](https://leetcode.com/problems/shortest-palindrome/) `Hard` — KMP LPS on `S + '#' + rev(S)`
- [ ] [LC 187. Repeated DNA Sequences](https://leetcode.com/problems/repeated-dna-sequences/) `Medium` — Rolling Hash / 2-bit mask
- [ ] [LC 5. Longest Palindromic Substring](https://leetcode.com/problems/longest-palindromic-substring/) `Medium` — Manacher's $O(N)$
- [ ] [LC 647. Palindromic Substrings](https://leetcode.com/problems/palindromic-substrings/) `Medium` — Expand around center / Manacher

---

### Phase 5: Linear Data Structures & Cache Design
*Workspace Reference*: [LinkedLists.cpp](file:///c:/Users/Dell/OneDrive/Documents/Data%20Structures%20and%20Algorithms/05_Linear_Data_Structures/LinkedLists.cpp) | [MonotonicStructures.cpp](file:///c:/Users/Dell/OneDrive/Documents/Data%20Structures%20and%20Algorithms/05_Linear_Data_Structures/MonotonicStructures.cpp)

#### Linked Lists
- [ ] [LC 206. Reverse Linked List](https://leetcode.com/problems/reverse-linked-list/) `Easy` — 3-pointer iteration
- [ ] [LC 92. Reverse Linked List II](https://leetcode.com/problems/reverse-linked-list-ii/) `Medium` — Sublist reversal
- [ ] [LC 25. Reverse Nodes in k-Group](https://leetcode.com/problems/reverse-nodes-in-k-group/) `Hard` — $K$-group recursive reverse
- [ ] [LC 141. Linked List Cycle](https://leetcode.com/problems/linked-list-cycle/) `Easy` — Floyd's tortoise & hare
- [ ] [LC 142. Linked List Cycle II](https://leetcode.com/problems/linked-list-cycle-ii/) `Medium` — Cycle start point
- [ ] [LC 21. Merge Two Sorted Lists](https://leetcode.com/problems/merge-two-sorted-lists/) `Easy` — Dummy head
- [ ] [LC 23. Merge k Sorted Lists](https://leetcode.com/problems/merge-k-sorted-lists/) `Hard` — Min-Heap priority queue
- [ ] [LC 19. Remove Nth Node From End of List](https://leetcode.com/problems/remove-nth-node-from-end-of-list/) `Medium` — $N$-gap two pointers
- [ ] [LC 160. Intersection of Two Linked Lists](https://leetcode.com/problems/intersection-of-two-linked-lists/) `Easy` — Switch heads
- [ ] [LC 234. Palindrome Linked List](https://leetcode.com/problems/palindrome-linked-list/) `Easy` — Middle + Reverse half
- [ ] [LC 138. Copy List with Random Pointer](https://leetcode.com/problems/copy-list-with-random-pointer/) `Medium` — Node weaving
- [ ] [LC 146. LRU Cache](https://leetcode.com/problems/lru-cache/) `Medium` — Doubly Linked List + Hash Map
- [ ] [LC 460. LFU Cache](https://leetcode.com/problems/lfu-cache/) `Hard` — Multi-frequency lists

#### Stacks, Queues & Monotonic Structures
- [ ] [LC 20. Valid Parentheses](https://leetcode.com/problems/valid-parentheses/) `Easy` — Stack matching
- [ ] [LC 155. Min Stack](https://leetcode.com/problems/min-stack/) `Medium` — Running minimum pair / math
- [ ] [LC 150. Evaluate Reverse Polish Notation](https://leetcode.com/problems/evaluate-reverse-polish-notation/) `Medium` — Stack evaluation
- [ ] [LC 394. Decode String](https://leetcode.com/problems/decode-string/) `Medium` — Count & String stacks
- [ ] [LC 227. Basic Calculator II](https://leetcode.com/problems/basic-calculator-ii/) `Medium` — Operator precedence stack
- [ ] [LC 496. Next Greater Element I](https://leetcode.com/problems/next-greater-element-i/) `Easy` — Monotonic stack
- [ ] [LC 503. Next Greater Element II](https://leetcode.com/problems/next-greater-element-ii/) `Medium` — Circular monotonic stack
- [ ] [LC 739. Daily Temperatures](https://leetcode.com/problems/daily-temperatures/) `Medium` — Index monotonic stack
- [ ] [LC 901. Online Stock Span](https://leetcode.com/problems/online-stock-span/) `Medium` — Span accumulation stack
- [ ] [LC 84. Largest Rectangle in Histogram](https://leetcode.com/problems/largest-rectangle-in-histogram/) `Hard` — Monotonic increasing stack
- [ ] [LC 85. Maximal Rectangle](https://leetcode.com/problems/maximal-rectangle/) `Hard` — 2D to histogram conversion
- [ ] [LC 239. Sliding Window Maximum](https://leetcode.com/problems/sliding-window-maximum/) `Hard` — Monotonic decreasing deque
- [ ] [LC 402. Remove K Digits](https://leetcode.com/problems/remove-k-digits/) `Medium` — Greedy monotonic stack

---

### Phase 6: Recursion & Backtracking Mastery
*Workspace Reference*: [BacktrackingMastery.cpp](file:///c:/Users/Dell/OneDrive/Documents/Data%20Structures%20and%20Algorithms/06_Recursion_and_Backtracking/BacktrackingMastery.cpp)

- [ ] [LC 78. Subsets](https://leetcode.com/problems/subsets/) `Medium` — State-space branching
- [ ] [LC 90. Subsets II](https://leetcode.com/problems/subsets-ii/) `Medium` — Duplicate skip logic
- [ ] [LC 46. Permutations](https://leetcode.com/problems/permutations/) `Medium` — In-place swap backtracking
- [ ] [LC 47. Permutations II](https://leetcode.com/problems/permutations-ii/) `Medium` — Visited duplicate check
- [ ] [LC 39. Combination Sum](https://leetcode.com/problems/combination-sum/) `Medium` — Unbounded item choice
- [ ] [LC 40. Combination Sum II](https://leetcode.com/problems/combination-sum-ii/) `Medium` — Single-use duplicate skip
- [ ] [LC 17. Letter Combinations of a Phone Number](https://leetcode.com/problems/letter-combinations-of-a-phone-number/) `Medium` — Digit map exploration
- [ ] [LC 22. Generate Parentheses](https://leetcode.com/problems/generate-parentheses/) `Medium` — Balanced Catalan branching
- [ ] [LC 79. Word Search](https://leetcode.com/problems/word-search/) `Medium` — 2D grid DFS backtracking
- [ ] [LC 212. Word Search II](https://leetcode.com/problems/word-search-ii/) `Hard` — Trie + 2D Backtracking
- [ ] [LC 51. N-Queens](https://leetcode.com/problems/n-queens/) `Hard` — $O(1)$ diagonal checks
- [ ] [LC 37. Sudoku Solver](https://leetcode.com/problems/sudoku-solver/) `Hard` — 9x9 constraint pruning
- [ ] [LC 131. Palindrome Partitioning](https://leetcode.com/problems/palindrome-partitioning/) `Medium` — Palindrome prefix recursion

---

### Phase 7: Trees, BSTs & Advanced Data Structures
*Workspace Reference*: [BinaryTrees_BST.cpp](file:///c:/Users/Dell/OneDrive/Documents/Data%20Structures%20and%20Algorithms/07_Trees_and_Advanced_Trees/BinaryTrees_BST.cpp) | [AdvancedTrees.cpp](file:///c:/Users/Dell/OneDrive/Documents/Data%20Structures%20and%20Algorithms/07_Trees_and_Advanced_Trees/AdvancedTrees.cpp)

#### Binary Trees & BST
- [ ] [LC 102. Binary Tree Level Order Traversal](https://leetcode.com/problems/binary-tree-level-order-traversal/) `Medium` — BFS queue
- [ ] [LC 104. Maximum Depth of Binary Tree](https://leetcode.com/problems/maximum-depth-of-binary-tree/) `Easy` — Post-order height
- [ ] [LC 543. Diameter of Binary Tree](https://leetcode.com/problems/diameter-of-binary-tree/) `Easy` — Bottom-up diameter
- [ ] [LC 110. Balanced Binary Tree](https://leetcode.com/problems/balanced-binary-tree/) `Easy` — Early stopping height
- [ ] [LC 236. Lowest Common Ancestor of a Binary Tree](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/) `Medium` — Dual subtree return
- [ ] [LC 199. Binary Tree Right Side View](https://leetcode.com/problems/binary-tree-right-side-view/) `Medium` — Reverse preorder
- [ ] [LC 105. Construct Binary Tree from Preorder & Inorder](https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/) `Medium` — Subtree boundary split
- [ ] [LC 297. Serialize and Deserialize Binary Tree](https://leetcode.com/problems/serialize-and-deserialize-binary-tree/) `Hard` — Stringstream reconstruction
- [ ] [LC 124. Binary Tree Maximum Path Sum](https://leetcode.com/problems/binary-tree-maximum-path-sum/) `Hard` — Negative branch pruning
- [ ] [LC 98. Validate Binary Search Tree](https://leetcode.com/problems/validate-binary-search-tree/) `Medium` — Boundary propagation
- [ ] [LC 230. Kth Smallest Element in a BST](https://leetcode.com/problems/kth-smallest-element-in-a-bst/) `Medium` — Inorder stopping
- [ ] [LC 235. Lowest Common Ancestor of a BST](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/) `Medium` — Value branch split
- [ ] [LC 173. Binary Search Tree Iterator](https://leetcode.com/problems/binary-search-tree-iterator/) `Medium` — Controlled stack pushAllLeft
- [ ] [LC 99. Recover Binary Search Tree](https://leetcode.com/problems/recover-binary-search-tree/) `Medium` — Morris Traversal $O(1)$ space
- [ ] [LC 1373. Maximum Sum BST in Binary Tree](https://leetcode.com/problems/maximum-sum-bst-in-binary-tree/) `Hard` — Subtree metadata verification

#### Tries & Advanced Trees
- [ ] [LC 208. Implement Trie (Prefix Tree)](https://leetcode.com/problems/implement-trie-prefix-tree/) `Medium` — Standard Trie
- [ ] [LC 211. Design Add and Search Words Data Structure](https://leetcode.com/problems/design-add-and-search-words-data-structure/) `Medium` — Wildcard Trie search
- [ ] [LC 421. Maximum XOR of Two Numbers in an Array](https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/) `Medium` — Bitwise Trie greedy
- [ ] [LC 1707. Maximum XOR With an Element From Array](https://leetcode.com/problems/maximum-xor-with-an-element-from-array/) `Hard` — Offline sorted queries + Bitwise Trie
- [ ] [LC 307. Range Sum Query - Mutable](https://leetcode.com/problems/range-sum-query-mutable/) `Medium` — Fenwick / Segment Tree
- [ ] [LC 315. Count of Smaller Numbers After Self](https://leetcode.com/problems/count-of-smaller-numbers-after-self/) `Hard` — Fenwick Tree / Merge Sort
- [ ] [LC 493. Reverse Pairs](https://leetcode.com/problems/reverse-pairs/) `Hard` — Merge sort two-pointer counting

---

### Phase 8: Heaps & Priority Queues
*Workspace Reference*: [HeapsMastery.cpp](file:///c:/Users/Dell/OneDrive/Documents/Data%20Structures%20and%20Algorithms/08_Heaps/HeapsMastery.cpp)

- [ ] [LC 215. Kth Largest Element in an Array](https://leetcode.com/problems/kth-largest-element-in-an-array/) `Medium` — QuickSelect $O(N)$ / Min-Heap
- [ ] [LC 347. Top K Frequent Elements](https://leetcode.com/problems/top-k-frequent-elements/) `Medium` — Min-Heap of size K / Bucket sort
- [ ] [LC 692. Top K Frequent Words](https://leetcode.com/problems/top-k-frequent-words/) `Medium` — Custom comparator heap
- [ ] [LC 295. Find Median from Data Stream](https://leetcode.com/problems/find-median-from-data-stream/) `Hard` — Two Heaps (Max-Heap + Min-Heap)
- [ ] [LC 480. Sliding Window Median](https://leetcode.com/problems/sliding-window-median/) `Hard` — Two multisets with lazy delete
- [ ] [LC 621. Task Scheduler](https://leetcode.com/problems/task-scheduler/) `Medium` — Frequency math formula
- [ ] [LC 767. Reorganize String](https://leetcode.com/problems/reorganize-string/) `Medium` — Top-2 element heap pop
- [ ] [LC 373. Find K Pairs with Smallest Sums](https://leetcode.com/problems/find-k-pairs-with-smallest-sums/) `Medium` — K-way heap merge
- [ ] [LC 502. IPO](https://leetcode.com/problems/ipo/) `Hard` — Dual Heaps (Capital min-heap, Profit max-heap)

---

### Phase 9: Graphs & Network Analysis
*Workspace Reference*: [GraphTraversals_ShortestPath.cpp](file:///c:/Users/Dell/OneDrive/Documents/Data%20Structures%20and%20Algorithms/09_Graphs/GraphTraversals_ShortestPath.cpp) | [AdvancedGraphAlgorithms.cpp](file:///c:/Users/Dell/OneDrive/Documents/Data%20Structures%20and%20Algorithms/09_Graphs/AdvancedGraphAlgorithms.cpp)

#### Traversals & BFS Shortest Path
- [ ] [LC 200. Number of Islands](https://leetcode.com/problems/number-of-islands/) `Medium` — Connected components
- [ ] [LC 133. Clone Graph](https://leetcode.com/problems/clone-graph/) `Medium` — Node clone mapping
- [ ] [LC 994. Rotting Oranges](https://leetcode.com/problems/rotting-oranges/) `Medium` — Multi-source BFS
- [ ] [LC 785. Is Graph Bipartite?](https://leetcode.com/problems/is-graph-bipartite/) `Medium` — 2-coloring DFS/BFS
- [ ] [LC 417. Pacific Atlantic Water Flow](https://leetcode.com/problems/pacific-atlantic-water-flow/) `Medium` — Border reverse BFS/DFS
- [ ] [LC 130. Surrounded Regions](https://leetcode.com/problems/surrounded-regions/) `Medium` — Border safe marking
- [ ] [LC 127. Word Ladder](https://leetcode.com/problems/word-ladder/) `Hard` — BFS shortest transformation

#### Topological Sort & Directed Cycles
- [ ] [LC 207. Course Schedule](https://leetcode.com/problems/course-schedule/) `Medium` — Kahn's BFS in-degree cycle detection
- [ ] [LC 210. Course Schedule II](https://leetcode.com/problems/course-schedule-ii/) `Medium` — Topological order return
- [ ] [LC 269. Alien Dictionary](https://leetcode.com/problems/alien-dictionary/) `Hard` — Word comparison + TopoSort
- [ ] [LC 310. Minimum Height Trees](https://leetcode.com/problems/minimum-height-trees/) `Medium` — Inward leaf trimming

#### Shortest Path Algorithms
- [ ] [LC 743. Network Delay Time](https://leetcode.com/problems/network-delay-time/) `Medium` — Dijkstra min-heap
- [ ] [LC 787. Cheapest Flights Within K Stops](https://leetcode.com/problems/cheapest-flights-within-k-stops/) `Medium` — Bellman-Ford $K+1$ iterations
- [ ] [LC 1631. Path With Minimum Effort](https://leetcode.com/problems/path-with-minimum-effort/) `Medium` — Dijkstra on effort metric
- [ ] [LC 778. Swim in Rising Water](https://leetcode.com/problems/swim-in-rising-water/) `Hard` — Dijkstra min-heap / Binary Search

#### Disjoint Set Union (DSU) & MST
- [ ] [LC 684. Redundant Connection](https://leetcode.com/problems/redundant-connection/) `Medium` — DSU cycle detection
- [ ] [LC 547. Number of Provinces](https://leetcode.com/problems/number-of-provinces/) `Medium` — DSU root count
- [ ] [LC 721. Accounts Merge](https://leetcode.com/problems/accounts-merge/) `Medium` — Email DSU grouping
- [ ] [LC 1584. Min Cost to Connect All Points](https://leetcode.com/problems/min-cost-to-connect-all-points/) `Medium` — Kruskal's MST / Prim
- [ ] [LC 1192. Critical Connections in a Network](https://leetcode.com/problems/critical-connections-in-a-network/) `Hard` — Tarjan's bridges ($low[v] > tin[u]$)

---

### Phase 10: Dynamic Programming (DP) Mastery
*Workspace Reference*: [DP_Framework_and_Patterns.md](file:///c:/Users/Dell/OneDrive/Documents/Data%20Structures%20and%20Algorithms/10_Dynamic_Programming/DP_Framework_and_Patterns.md) | [DP_Core_Patterns.cpp](file:///c:/Users/Dell/OneDrive/Documents/Data%20Structures%20and%20Algorithms/10_Dynamic_Programming/DP_Core_Patterns.cpp) | [DP_Advanced_Patterns.cpp](file:///c:/Users/Dell/OneDrive/Documents/Data%20Structures%20and%20Algorithms/10_Dynamic_Programming/DP_Advanced_Patterns.cpp)

#### 1D & Knapsack Patterns
- [ ] [LC 70. Climbing Stairs](https://leetcode.com/problems/climbing-stairs/) `Easy` — Fibonacci recurrence
- [ ] [LC 746. Min Cost Climbing Stairs](https://leetcode.com/problems/min-cost-climbing-stairs/) `Easy` — Cost step DP
- [ ] [LC 198. House Robber](https://leetcode.com/problems/house-robber/) `Medium` — $O(1)$ space optimization
- [ ] [LC 213. House Robber II](https://leetcode.com/problems/house-robber-ii/) `Medium` — Circular array split
- [ ] [LC 91. Decode Ways](https://leetcode.com/problems/decode-ways/) `Medium` — 1-digit vs 2-digit branching
- [ ] [LC 139. Word Break](https://leetcode.com/problems/word-break/) `Medium` — Substring DP
- [ ] [LC 322. Coin Change](https://leetcode.com/problems/coin-change/) `Medium` — Unbounded knapsack (Min coins)
- [ ] [LC 518. Coin Change II](https://leetcode.com/problems/coin-change-ii/) `Medium` — Combinations unbounded knapsack
- [ ] [LC 416. Partition Equal Subset Sum](https://leetcode.com/problems/partition-equal-subset-sum/) `Medium` — 0/1 Knapsack backwards loop
- [ ] [LC 494. Target Sum](https://leetcode.com/problems/target-sum/) `Medium` — Subset sum reduction

#### 2D, Grid & String DP
- [ ] [LC 62. Unique Paths](https://leetcode.com/problems/unique-paths/) `Medium` — Grid combination DP
- [ ] [LC 63. Unique Paths II](https://leetcode.com/problems/unique-paths-ii/) `Medium` — Obstacle handling
- [ ] [LC 64. Minimum Path Sum](https://leetcode.com/problems/minimum-path-sum/) `Medium` — Min adjacent path
- [ ] [LC 221. Maximal Square](https://leetcode.com/problems/maximal-square/) `Medium` — Subsquare min dimension
- [ ] [LC 1143. Longest Common Subsequence](https://leetcode.com/problems/longest-common-subsequence/) `Medium` — LCS matrix
- [ ] [LC 72. Edit Distance](https://leetcode.com/problems/edit-distance/) `Medium` — Insert/Delete/Replace transitions
- [ ] [LC 115. Distinct Subsequences](https://leetcode.com/problems/distinct-subsequences/) `Hard` — Backwards space optimization
- [ ] [LC 10. Regular Expression Matching](https://leetcode.com/problems/regular-expression-matching/) `Hard` — Star `*` transitions
- [ ] [LC 44. Wildcard Matching](https://leetcode.com/problems/wildcard-matching/) `Hard` — Dynamic wildcard `*` matching

#### LIS, Interval & Bitmask DP
- [ ] [LC 300. Longest Increasing Subsequence](https://leetcode.com/problems/longest-increasing-subsequence/) `Medium` — Patience sorting $O(N \log N)$
- [ ] [LC 354. Russian Doll Envelopes](https://leetcode.com/problems/russian-doll-envelopes/) `Hard` — 2D sort + LIS
- [ ] [LC 1671. Minimum Number of Removals to Make Mountain Array](https://leetcode.com/problems/minimum-number-of-removals-to-make-mountain-array/) `Hard` — Bitonic LIS
- [ ] [LC 312. Burst Balloons](https://leetcode.com/problems/burst-balloons/) `Hard` — Reverse interval MCM DP
- [ ] [LC 1547. Minimum Cost to Cut a Stick](https://leetcode.com/problems/minimum-cost-to-cut-a-stick/) `Hard` — Range cut DP
- [ ] [LC 847. Shortest Path Visiting All Nodes](https://leetcode.com/problems/shortest-path-visiting-all-nodes/) `Hard` — TSP style Bitmask BFS

---

### Phase 11: System Design Data Structures & Hard Problems
*Workspace Reference*: [SystemDataStructures.cpp](file:///c:/Users/Dell/OneDrive/Documents/Data%20Structures%20and%20Algorithms/11_System_Design_Structures/SystemDataStructures.cpp)

- [ ] [LC 146. LRU Cache](https://leetcode.com/problems/lru-cache/) `Medium` — Doubly Linked List + Hash Map
- [ ] [LC 460. LFU Cache](https://leetcode.com/problems/lfu-cache/) `Hard` — Frequency buckets + Doubly Linked Lists
- [ ] [LC 432. All O`one Data Structure](https://leetcode.com/problems/all-oone-data-structure/) `Hard` — Count buckets with key set
- [ ] [LC 981. Time Based Key-Value Store](https://leetcode.com/problems/time-based-key-value-store/) `Medium` — Map + Binary Search
- [ ] [LC 1146. Snapshot Array](https://leetcode.com/problems/snapshot-array/) `Medium` — Version history + `upper_bound`
- [ ] [LC 380. Insert Delete GetRandom O(1)](https://leetcode.com/problems/insert-delete-getrandom-o1/) `Medium` — Vector + Map swap-with-back
- [ ] [LC 355. Design Twitter](https://leetcode.com/problems/design-twitter/) `Medium` — User graph + K-way tweet heap merge
- [ ] [LC 895. Maximum Frequency Stack](https://leetcode.com/problems/maximum-frequency-stack/) `Hard` — Multi-level frequency stacks
