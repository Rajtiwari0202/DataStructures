# Phase 1: Asymptotic Analysis & Recurrence Relations

Welcome to Phase 1! Here we build the mathematical backbone of algorithm analysis required by top MNC interviewers.

---

## 1. Asymptotic Notations: Big-O, Big-$\Omega$, Big-$\Theta$

When analyzing algorithms, we evaluate how running time or space grows as input size $N \to \infty$.

### Mathematical Definitions

Let $f(n)$ be the running time of an algorithm for input size $n$, and $g(n)$ be a reference function.

1. **Big-O ($O$) - Upper Bound (Worst Case)**
   $$f(n) = O(g(n)) \iff \exists \; c > 0, n_0 > 0 \text{ such that } 0 \le f(n) \le c \cdot g(n) \quad \forall n \ge n_0$$
   *Meaning*: $f(n)$ grows **at most as fast as** $g(n)$.

2. **Big-Omega ($\Omega$) - Lower Bound (Best Case)**
   $$f(n) = \Omega(g(n)) \iff \exists \; c > 0, n_0 > 0 \text{ such that } 0 \le c \cdot g(n) \le f(n) \quad \forall n \ge n_0$$
   *Meaning*: $f(n)$ grows **at least as fast as** $g(n)$.

3. **Big-Theta ($\Theta$) - Tight Bound (Exact Growth Rate)**
   $$f(n) = \Theta(g(n)) \iff \exists \; c_1, c_2 > 0, n_0 > 0 \text{ such that } c_1 \cdot g(n) \le f(n) \le c_2 \cdot g(n) \quad \forall n \ge n_0$$
   *Note*: $f(n) = \Theta(g(n)) \iff f(n) = O(g(n)) \text{ and } f(n) = \Omega(g(n))$.

---

## 2. Growth Rate Hierarchy

Ordering from slowest growth (fastest execution) to fastest growth (slowest execution):

$$O(1) < O(\log \log n) < O(\log n) < O(\sqrt{n}) < O(n) < O(n \log n) < O(n^2) < O(n^3) < O(2^n) < O(n!) < O(n^n)$$

### Interviewer Constraint Rule of Thumb ($10^8$ operations per second limit):

| Constraint ($N$) | Maximum Allowed Complexity | Typical Algorithmic Approaches |
| :--- | :--- | :--- |
| $N \le 10$ to $12$ | $O(N!)$ or $O(N^2 \cdot 2^N)$ | Backtracking, Permutations, TSP (DP + Bitmasking) |
| $N \le 15$ to $20$ | $O(2^N \cdot N)$ | Meet in the Middle, Subset generation, Bitmask DP |
| $N \le 100$ | $O(N^4)$ or $O(N^3)$ | Floyd-Warshall, Matrix Chain Multiplication DP |
| $N \le 500$ | $O(N^3)$ | 3D DP, Grid DP, Cubic Matrix Ops |
| $N \le 2000$ to $5000$ | $O(N^2)$ | Dynamic Programming, Nested Loops, All pairs |
| $N \le 10^5$ to $2 \cdot 10^5$ | $O(N \log N)$ or $O(N)$ | Sorting, Binary Search, Segment Trees, Priority Queue, Two Pointers |
| $N \le 10^6$ to $10^7$ | $O(N)$ | Linear scan, Hash Maps, Prefix Sums, Monotonic Stack, Sieve |
| $N \le 10^9$ to $10^{18}$ | $O(\log N)$ or $O(1)$ | Binary Search on Answer, Binary Exponentiation, Math/Euclid GCD |

---

## 3. Recurrence Relations & Solving Techniques

Recurrence relations model recursive algorithms $T(n) = \text{work at current level} + \text{work in subproblems}$.

### Method 1: The Master Theorem (Divide and Conquer)

For recurrences of the form:
$$T(n) = a T\left(\frac{n}{b}\right) + f(n) \quad \text{where } a \ge 1, b > 1$$

Compare $f(n)$ with $n^{\log_b a}$:

1. **Case 1 (Subproblems dominate)**:
   If $f(n) = O(n^{\log_b a - \epsilon})$ for some $\epsilon > 0$, then:
   $$T(n) = \Theta(n^{\log_b a})$$

2. **Case 2 (Balanced)**:
   If $f(n) = \Theta(n^{\log_b a} \log^k n)$ for some $k \ge 0$, then:
   $$T(n) = \Theta(n^{\log_b a} \log^{k+1} n)$$

3. **Case 3 (Root/Combine step dominates)**:
   If $f(n) = \Omega(n^{\log_b a + \epsilon})$ for some $\epsilon > 0$, AND regularity condition holds ($a f(n/b) \le c f(n)$ for $c < 1$), then:
   $$T(n) = \Theta(f(n))$$

#### Master Theorem Examples:

- **Binary Search**: $T(n) = T(n/2) + \Theta(1)$
  - $a=1, b=2 \implies n^{\log_2 1} = n^0 = 1$.
  - $f(n) = \Theta(1) = \Theta(n^0)$. Case 2 ($k=0$) applies!
  - $T(n) = \Theta(\log n)$.

- **Merge Sort**: $T(n) = 2T(n/2) + \Theta(n)$
  - $a=2, b=2 \implies n^{\log_2 2} = n^1 = n$.
  - $f(n) = \Theta(n)$. Case 2 ($k=0$) applies!
  - $T(n) = \Theta(n \log n)$.

- **Strassen's Matrix Multiplication**: $T(n) = 7T(n/2) + \Theta(n^2)$
  - $a=7, b=2 \implies n^{\log_2 7} \approx n^{2.807}$.
  - $f(n) = O(n^2) = O(n^{2.807 - \epsilon})$. Case 1 applies!
  - $T(n) = \Theta(n^{\log_2 7}) \approx \Theta(n^{2.807})$.

---

### Method 2: Recursion Tree Method

Visualizing level-by-level work.

Example: $T(n) = 2 T(n/2) + c n$

```
Level 0:                 cn                    = cn
                       /    \
Level 1:           c(n/2)   c(n/2)             = cn
                   /   \     /   \
Level 2:        c(n/4) c(n/4) c(n/4) c(n/4)    = cn
                ...
Level log₂ n:   T(1) T(1) ... T(1)             = cn
```

Total Height = $\log_2 n + 1$.
Total Work = $\sum_{i=0}^{\log_2 n} cn = c n \cdot (\log_2 n + 1) = \Theta(n \log n)$.

---

### Method 3: Substitution Method (Mathematical Induction)

1. Guess the form of the solution.
2. Verify using induction.
3. Solve for constants.

Example: Prove $T(n) = T(n-1) + n \implies T(n) = O(n^2)$.
- Induction Hypothesis: Assume $T(k) \le c k^2$ for $k < n$.
- Induction Step: $T(n) = T(n-1) + n \le c(n-1)^2 + n = c(n^2 - 2n + 1) + n = c n^2 - (2c - 1)n + c$.
- We need $c n^2 - (2c - 1)n + c \le c n^2$.
- Holds if $2c - 1 \ge c \implies c \ge 1$. Proven!

---

## 4. Space Complexity Analysis

Total Space = **Auxiliary Space** (extra memory allocated) + **Input Space**.

### Memory Layout & Call Stack:
When recursion happens, stack frames are pushed onto the Call Stack:

```
+--------------------------+
|  Recurse(n=1) StackFrame | -> Parameters, local variables, return address
+--------------------------+
|  Recurse(n=2) StackFrame |
+--------------------------+
|  ...                     |
+--------------------------+
|  Recurse(n=N) StackFrame |
+--------------------------+
```

Max Stack Depth = Height of Recursion Tree $\implies$ Auxiliary Space Complexity!
