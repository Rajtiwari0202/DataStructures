# Day 3 — Linked Lists (Singly, Doubly, Circular)

## Topics Covered
- Linked List theory: node structure, memory layout, and the array-vs-linked-list tradeoff table
- Singly Linked List (SLL): insert head/tail, delete, search, traverse, reverse (iterative + recursive)
- Doubly Linked List (DLL): insert head/tail, O(1) deletion given a node pointer
- Circular Linked List (CLL): insert at head, traversal with cycle-aware stopping condition

## Problems Solved (brute force + optimal, with dry runs & edge cases)
1. Detect Cycle in a Linked List — Floyd's Tortoise & Hare (O(n)/O(1))
2. Find Middle of Linked List — Slow/Fast Pointer (O(n)/O(1))
3. Merge Two Sorted Linked Lists — Dummy Node technique (O(n+m)/O(1))
4. Remove Nth Node From End — Two Pointer with Gap (O(n)/O(1))

## Files
| File | Description |
|---|---|
| `01_linked_list_basics.cpp` | SLL, DLL, CLL classes with all core operations |
| `02_linked_list_problems.cpp` | All 4 solved problems with dry-run-verified output |
| `Day3_LinkedLists_Notes.pdf` | Full theory + solved problems notes for revision |

## How to Run
```bash
g++ -std=c++17 -o 01_linked_list_basics 01_linked_list_basics.cpp && ./01_linked_list_basics
g++ -std=c++17 -o 02_linked_list_problems 02_linked_list_problems.cpp && ./02_linked_list_problems
```

Both files have been compiled and tested — outputs verified against manual dry runs.

## Next Session (Day 4)
Stacks.