# Phase 3: Binary Search & Search Space Optimization Mastery

Binary Search is one of the most fundamental yet tricky topics in technical interviews. Interviewers test your ability to avoid off-by-one errors (`low <= high` vs `low < high`), handle integer overflow (`mid = low + (high - low) / 2`), and formulate **Monotonic Decision Functions** for search space optimization.

---

## 1. Core Mechanics & The Monotonic Principle

Binary Search works on any search space that satisfies a **Monotonic Property**:

$$\text{Predicate}(x) = \begin{cases} 
\text{false} & \text{for } x < \text{target} \\ 
\text{true} & \text{for } x \ge \text{target} 
\end{cases}$$

Visually, the predicate space looks like:
$$\underbrace{[\text{false}, \text{false}, \text{false}, \dots, \text{false}]}_{\text{Invalid Region}} \quad \underbrace{[\text{true}, \text{true}, \dots, \text{true}]}_{\text{Valid Region}}$$

Binary Search eliminates **half of the remaining search space** at each iteration!

### Time & Recurrence Analysis:
$$T(n) = T(n/2) + O(1)$$
By Master's Theorem Case 2 ($a=1, b=2, k=0 \implies n^{\log_2 1} = n^0 = 1$):
$$T(n) = \Theta(\log_2 n)$$

---

## 2. Standard Templates & Edge-Case Rules

### Template 1: Basic Search (Find exact target)
```cpp
int low = 0, high = n - 1;
while (low <= high) {
    int mid = low + (high - low) / 2;
    if (nums[mid] == target) return mid;
    else if (nums[mid] < target) low = mid + 1;
    else high = mid - 1;
}
return -1;
```

### Template 2: Lower Bound (`std::lower_bound`)
*Finds the FIRST element $\ge \text{target}$ (First `true` index).*
```cpp
int low = 0, high = n - 1, ans = n;
while (low <= high) {
    int mid = low + (high - low) / 2;
    if (nums[mid] >= target) {
        ans = mid;    // Potential candidate found
        high = mid - 1; // Search left for an earlier valid index
    } else {
        low = mid + 1;  // Search right
    }
}
return ans;
```

### Template 3: Upper Bound (`std::upper_bound`)
*Finds the FIRST element $> \text{target}$.*
```cpp
int low = 0, high = n - 1, ans = n;
while (low <= high) {
    int mid = low + (high - low) / 2;
    if (nums[mid] > target) {
        ans = mid;
        high = mid - 1;
    } else {
        low = mid + 1;
    }
}
return ans;
```

---

## 3. Binary Search on Answer Space (Minimax / Maximin)

When a problem asks to **"Minimize the Maximum..."** or **"Maximize the Minimum..."**, it is almost ALWAYS a Binary Search on Answer Space problem!

### The Framework:
1. **Define Range**:
   - `low` = minimum possible valid answer (e.g. `max(arr)` or `1`).
   - `high` = maximum possible valid answer (e.g. `sum(arr)` or `10^9`).
2. **Define Feasibility Function `isPossible(mid)`**:
   - Returns `true` if condition can be satisfied with max/min capacity `mid`.
   - Function MUST be monotonic!
3. **Binary Search**:
   - If `isPossible(mid)` is true: candidate found $\implies$ try smaller `high = mid - 1` (for minimization) or larger `low = mid + 1` (for maximization).

### Classic Search Space Problems:
- **Book Allocation Problem**: Allocate $N$ books to $M$ students such that maximum pages allocated to a student is minimized.
- **Aggressive Cows**: Place $C$ cows in $N$ stalls such that minimum distance between any two cows is maximized.
- **K-th Element of Two Sorted Arrays**: Search space over values/partition cuts.
