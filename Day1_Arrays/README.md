# Day 1 — Complexity Analysis & Arrays

## Topics Covered
- Time & Space complexity (Big-O, Big-Omega, Big-Theta) with rules of thumb
- Arrays: theory, static vs dynamic, complexity table for all operations
- How `std::vector` grows internally (amortized O(1) push_back)

## Problems Solved (brute force + optimal, with dry runs & edge cases)
1. Reverse an Array In-Place — Two Pointer (O(n)/O(1))
2. Missing Number (1 to n) — Sum approach & XOR approach (O(n)/O(1))
3. Kadane's Algorithm — Maximum Subarray Sum (O(n)/O(1))
4. Move All Zeroes to End — Two Pointer (O(n)/O(1))
5. Two Sum — Brute force, Hashing, Sorted + Two Pointer (O(n)/O(n) optimal)

## Files
| File | Description |
|---|---|
| `01_array_basics.cpp` | Traversal, insertion, deletion, linear/binary search, reversal, max/min, vector demo |
| `02_placement_problems.cpp` | All 5 solved problems with multiple approaches per problem |
| `Day1_Arrays_Notes.pdf` | Full theory + solved problems notes for revision |

## How to Run
```bash
g++ -std=c++17 -o 01_array_basics 01_array_basics.cpp && ./01_array_basics
g++ -std=c++17 -o 02_placement_problems 02_placement_problems.cpp && ./02_placement_problems
```

Both files have been compiled and tested — outputs verified against manual dry runs.

## Next Session (Day 2)
Strings + Searching/Sorting basics.