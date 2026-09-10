# Phase 4: String Matching & Advanced String Algorithms

String pattern matching is a cornerstone of tech interview problems at top MNCs. Naive string matching takes $O(N \cdot M)$ time. Advanced algorithms achieve $O(N + M)$ linear time by avoiding redundant character comparisons.

---

## 1. KMP (Knuth-Morris-Pratt) Algorithm

The KMP algorithm uses the **$\pi$-array** (or **LPS** - Longest Proper Prefix which is also a Suffix) to skip unnecessary comparisons when a mismatch occurs.

### Definition of LPS / $\pi$-Array:
`LPS[i]` is the length of the longest proper prefix of `pattern[0...i]` that is also a suffix of `pattern[0...i]`.

Example: Pattern = `"ababa"`
- `"a"` $\implies$ LPS[0] = 0
- `"ab"` $\implies$ LPS[1] = 0
- `"aba"` $\implies$ Prefix `"a"`, Suffix `"a"` $\implies$ LPS[2] = 1
- `"abab"` $\implies$ Prefix `"ab"`, Suffix `"ab"` $\implies$ LPS[3] = 2
- `"ababa"` $\implies$ Prefix `"aba"`, Suffix `"aba"` $\implies$ LPS[4] = 3

### KMP Time Complexity:
- **LPS Construction**: $O(M)$
- **Text Search**: $O(N)$
- **Total Time**: $O(N + M)$
- **Auxiliary Space**: $O(M)$

---

## 2. Rabin-Karp Algorithm (Rolling Hash)

Rabin-Karp uses **Polynomial Rolling Hash** to map string substrings to integer hash values.

### Hash Function:
$$H(S[0 \dots k-1]) = \left( \sum_{i=0}^{k-1} S[i] \cdot p^{k-1-i} \right) \pmod M$$
where $p$ is a prime base (e.g. 31 or 53) and $M$ is a large prime modulo (e.g. $10^9 + 7$).

### Sliding Window Rolling Hash Update:
When shifting from window $S[i \dots i+k-1]$ to $S[i+1 \dots i+k]$:
$$H_{\text{new}} = \left( (H_{\text{old}} - S[i] \cdot p^{k-1}) \cdot p + S[i+k] \right) \pmod M$$

- **Time Complexity**: $O(N + M)$ expected average time.
- **Space Complexity**: $O(1)$ auxiliary space.

---

## 3. Z-Algorithm

The Z-algorithm builds a **Z-array** where `Z[i]` is the length of the longest substring starting from `S[i]` that is also a prefix of `S`.

### String Construction for Pattern Search:
Concatenate $P + \text{'\$'} + T$. Search for indices where $Z[i] == |P|$.
- **Time Complexity**: $O(N + M)$ linear time.
- **Space Complexity**: $O(N + M)$.

---

## 4. Manacher's Algorithm (Palindromes in $O(N)$)

Finding the longest palindromic substring naively takes $O(N^2)$ time.
Manacher's algorithm uses previously computed palindrome radii to compute the longest palindrome in $O(N)$ time!

### Odd & Even Handling:
Transform string `S` by inserting boundary characters `'#'`:
`"aba"` $\implies$ `"#a#b#a#"`.

Maintain `center` and `rightBoundary` of the furthest reaching palindrome.
- **Time Complexity**: $O(N)$ linear time.
- **Space Complexity**: $O(N)$.
