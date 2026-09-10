# 🚀 Complete DSA Mastery Curriculum & Notion Tracker (C++)

[![C++20](https://img.shields.io/badge/Language-C%2B%2B20-blue.svg)](https://isocpp.org/)
[![LeetCode](https://img.shields.io/badge/LeetCode-194%20Problems-orange.svg)](https://leetcode.com/)
[![Target](https://img.shields.io/badge/Target-MAANG%20%2F%20FAANG%20%2F%20HFTs-red.svg)](#)
[![Notion](https://img.shields.io/badge/Notion-Ready%20Tracker-black.svg)](DSA_LeetCode_Tracker.csv)

A structured, battle-tested Data Structures & Algorithms curriculum designed for cracking technical interviews at top MNCs (Google, Meta, Amazon, Microsoft, Apple, Uber, Netflix) and High-Frequency Trading (HFT) firms.

---

## 🎯 The 7-Step Problem Solving Framework

Every topic and algorithm in this repository is built using a rigorous 7-Step Analytical Framework:
1. **Constraints & Clue Analysis**: Identifying pattern indicators from input sizes ($N \le 10^5 \implies O(N \log N)$ or $O(N)$).
2. **Brute Force Formulation**: Establishing baseline complexity and pinpointing algorithmic bottlenecks.
3. **Redundancy Elimination**: Identifying *what unnecessary work* the brute force performs and how optimal structures eliminate it.
4. **Optimal Invariant & Proof**: Mathematical induction, Master's theorem, and loop invariants.
5. **Recurrence & Complexity Analysis**: Exact Big-$O$, Big-$\Omega$, Big-$\Theta$, and call stack memory bounds.
6. **Dry Run & Visual State Diagrams**: Step-by-step tracing of pointers, windows, trees, and stack frames.
7. **Production-Grade Modern C++ (C++20)**: Clean STL usage, pointer/reference semantics, and edge-case handling.

---

## 📁 Repository Structure

```
├── 01_Foundations_and_Math/
│   ├── TimeComplexity_and_Recurrence.md   <- Master Theorem, Big-O/Omega/Theta proofs
│   ├── BitManipulation.cpp               <- Kernighan, Single Number I/III, Power Set
│   └── NumberTheory.cpp                  <- Fast Power, Sieve, Segmented Sieve, Mod Inverse
├── 02_Arrays_and_Pointers/
│   ├── TwoPointers.cpp                   <- 3-Sum, Trapping Rain Water O(1) space, Most Water
│   ├── SlidingWindow.cpp                 <- Fixed/Variable Windows, Min Window Substring, AtMost(K)
│   └── PrefixSum.cpp                     <- Subarray Sum = K, Difference Array O(1), 2D Matrix Sum
├── 03_Binary_Search/
│   ├── BinarySearch_Guide.md             <- Monotonic Predicate Framework & Templates
│   ├── BinarySearch_1D_2D.cpp            <- Rotated Search, Peak Element, 2D Matrix
│   └── BinarySearch_SearchSpace.cpp      <- Book Allocation, Aggressive Cows, K-th Element 2 Sorted Arrays
├── 04_Strings/
│   ├── PatternMatching_Guide.md          <- KMP, Rabin-Karp, Z-Algo, Manacher Theory
│   └── PatternMatching.cpp               <- KMP (LPS), Rabin-Karp Hash, Z-Array, Manacher O(N)
├── 05_Linear_Data_Structures/
│   ├── LinkedLists.cpp                   <- Reversal, Fast/Slow, O(1) LRU & LFU Cache Design
│   └── MonotonicStructures.cpp           <- NGE II, Histogram Largest Rectangle, Sliding Window Max
├── 06_Recursion_and_Backtracking/
│   └── BacktrackingMastery.cpp           <- Subsets II, N-Queens, Sudoku Solver
├── 07_Trees_and_Advanced_Trees/
│   ├── BinaryTrees_BST.cpp               <- Morris Traversal O(1) space, Diameter, LCA, BST Validation
│   └── AdvancedTrees.cpp                 <- Bitwise Trie Max XOR, Segment Tree + Lazy, Fenwick Tree
├── 08_Heaps/
│   └── HeapsMastery.cpp                  <- Custom Min-Heap O(N) Heapify, Top K Frequent, Two Heaps Median
├── 09_Graphs/
│   ├── GraphTraversals_ShortestPath.cpp  <- TopoSort (Kahn's), Dijkstra, Bellman-Ford, Floyd-Warshall
│   └── AdvancedGraphAlgorithms.cpp       <- DSU (Path Compression & Rank), Kruskal, Tarjan, Kosaraju
├── 10_Dynamic_Programming/
│   ├── DP_Framework_and_Patterns.md     <- 6-Step DP Framework & 8 Core Patterns Guide
│   ├── DP_Core_Patterns.cpp              <- House Robber, Coin Change, LCS, Edit Distance, LIS O(N log N)
│   └── DP_Advanced_Patterns.cpp          <- MCM Interval DP, Burst Balloons, TSP DP + Bitmasking
├── 11_System_Design_Structures/
│   └── SystemDataStructures.cpp          <- All O(1) Data Structure, Snapshot Array
├── DSA_LeetCode_Tracker.csv               <- 1-Click Notion Database Import (194 curated problems)
├── DSA_Mastery_Notion_Dashboard.md        <- Notion Markdown Dashboard & Study Checklists
└── .gitignore                            <- Ignores compiled binaries (*.exe, *.class)
```

---

## 📊 Notion LeetCode Tracker (194 Problems)

This repository includes a pre-configured database file: **[`DSA_LeetCode_Tracker.csv`](DSA_LeetCode_Tracker.csv)** containing **194 highest-yield LeetCode problems** arranged in the exact pedagogical order you should solve them.

### How to Import to Notion:
1. Open **Notion** and click **`+ New Page`**.
2. Click **`...`** (top right) $\to$ **`Import`** $\to$ **`CSV`**.
3. Select `DSA_LeetCode_Tracker.csv`.
4. Notion creates a live database with columns for:
   - **Order** (1 to 194)
   - **Problem Name & LeetCode #**
   - **Direct LeetCode URL**
   - **Phase & Sub-Topic**
   - **Difficulty** (Easy, Medium, Hard)
   - **Status** (Not Started, In Progress, Solved, Needs Revisit)
   - **Target Time & Space Complexity**
   - **Key Intuition / Trap**

---

## 🛠️ How to Compile & Run the Implementations

All files are written in modern C++ (C++20) and contain self-contained `main()` driver test suites with assertions.

```bash
# Example: Compile & Run Phase 2 Two Pointers
g++ -std=c++20 -O2 02_Arrays_and_Pointers/TwoPointers.cpp -o TwoPointers.exe
./TwoPointers.exe

# Example: Compile & Run Phase 7 Advanced Trees
g++ -std=c++20 -O2 07_Trees_and_Advanced_Trees/AdvancedTrees.cpp -o AdvancedTrees.exe
./AdvancedTrees.exe

# Example: Compile & Run Phase 10 Core DP Patterns
g++ -std=c++20 -O2 10_Dynamic_Programming/DP_Core_Patterns.cpp -o DP_Core.exe
./DP_Core.exe
```

---

## 🗺️ Master Curriculum Overview

| Phase | Core Patterns & Algorithms | Key Files |
| :--- | :--- | :--- |
| **01: Foundations & Math** | Asymptotic Analysis, Master Theorem, Bitwise Tricks, Kernighan, Sieve, Fast Power, Fermat's Inverse | [`TimeComplexity.md`](01_Foundations_and_Math/TimeComplexity_and_Recurrence.md), [`BitManipulation.cpp`](01_Foundations_and_Math/BitManipulation.cpp) |
| **02: Arrays & Pointers** | Two Pointers, Trapping Rain Water, Variable Sliding Window, `AtMost(K)`, Difference Array | [`TwoPointers.cpp`](02_Arrays_and_Pointers/TwoPointers.cpp), [`SlidingWindow.cpp`](02_Arrays_and_Pointers/SlidingWindow.cpp) |
| **03: Binary Search** | Lower/Upper Bound, Rotated Array, Search Space (Book Allocation, Aggressive Cows) | [`BinarySearch_Guide.md`](03_Binary_Search/BinarySearch_Guide.md), [`BinarySearch_SearchSpace.cpp`](03_Binary_Search/BinarySearch_SearchSpace.cpp) |
| **04: Strings** | KMP Algorithm ($\pi$-array), Rabin-Karp Hash, Z-Algorithm, Manacher's $O(N)$ Palindromes | [`PatternMatching_Guide.md`](04_Strings/PatternMatching_Guide.md), [`PatternMatching.cpp`](04_Strings/PatternMatching.cpp) |
| **05: Linear Structures** | Linked Lists, **LRU & LFU Cache Design**, Monotonic Stack (Histogram), Monotonic Deque | [`LinkedLists.cpp`](05_Linear_Data_Structures/LinkedLists.cpp), [`MonotonicStructures.cpp`](05_Linear_Data_Structures/MonotonicStructures.cpp) |
| **06: Backtracking** | State-Space Tree Pruning, Subsets II, Permutations II, N-Queens $O(1)$ Checks, Sudoku Solver | [`BacktrackingMastery.cpp`](06_Recursion_and_Backtracking/BacktrackingMastery.cpp) |
| **07: Trees & Advanced** | Morris Inorder $O(1)$ Space, Diameter, LCA, Bitwise Trie, Segment Tree + Lazy, Fenwick Tree | [`BinaryTrees_BST.cpp`](07_Trees_and_Advanced_Trees/BinaryTrees_BST.cpp), [`AdvancedTrees.cpp`](07_Trees_and_Advanced_Trees/AdvancedTrees.cpp) |
| **08: Heaps** | Binary Heap $O(N)$ Heapify, Top K Frequent, Two Heaps Streaming Median | [`HeapsMastery.cpp`](08_Heaps/HeapsMastery.cpp) |
| **09: Graphs** | Kahn's TopoSort, Dijkstra, Bellman-Ford, DSU (Path Compression & Rank), Kruskal, Tarjan, Kosaraju | [`GraphTraversals_ShortestPath.cpp`](09_Graphs/GraphTraversals_ShortestPath.cpp), [`AdvancedGraphAlgorithms.cpp`](09_Graphs/AdvancedGraphAlgorithms.cpp) |
| **10: Dynamic Programming**| 1D DP, 0/1 & Unbounded Knapsack, String DP (LCS/Edit Distance), LIS $O(N \log N)$, MCM, TSP Bitmask | [`DP_Framework.md`](10_Dynamic_Programming/DP_Framework_and_Patterns.md), [`DP_Core_Patterns.cpp`](10_Dynamic_Programming/DP_Core_Patterns.cpp) |
| **11: System Design** | All O(1) Data Structure, Snapshot Array (Binary Search History), Twitter Feed | [`SystemDataStructures.cpp`](11_System_Design_Structures/SystemDataStructures.cpp) |
