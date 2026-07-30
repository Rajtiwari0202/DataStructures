# Day 2 — Strings + Sorting & Searching Basics

## Topics Covered
- Strings in C++: mutability, memory layout, complexity of all common operations
- Concatenation-in-loop gotcha (amortized O(n^2) risk)
- All 5 core sorting algorithms with best/avg/worst time, space, stability, in-place comparison table
- Why Quick Sort degrades to O(n^2) and why Merge Sort needs O(n) space

## Problems Solved (brute force + optimal, with dry runs & edge cases)
1. Palindrome Check — Two Pointer (O(n)/O(1))
2. Anagram Check — Sort & Compare vs Frequency Count (O(n)/O(1) optimal)
3. First Non-Repeating Character — Frequency Map (O(n)/O(1))
4. Search in Rotated Sorted Array — Modified Binary Search (O(log n)/O(1))

## Files
| File | Description |
|---|---|
| `01_sorting_algorithms.cpp` | Bubble, Selection, Insertion, Merge, Quick Sort — all implemented and tested |
| `02_strings_searching_problems.cpp` | All 4 solved problems with multiple approaches per problem |
| `Day2_Strings_Sorting_Notes.pdf` | Full theory + solved problems notes for revision |

## How to Run
```bash
g++ -std=c++17 -o 01_sorting_algorithms 01_sorting_algorithms.cpp && ./01_sorting_algorithms
g++ -std=c++17 -o 02_strings_searching_problems 02_strings_searching_problems.cpp && ./02_strings_searching_problems
```

Both files have been compiled and tested — outputs verified against manual dry runs.

## Next Session (Day 3)
Linked Lists — Singly, Doubly, Circular.