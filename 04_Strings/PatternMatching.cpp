/**
 * ============================================================================
 * PHASE 4: STRING PATTERN MATCHING ALGORITHMS (C++)
 * ============================================================================
 * Concepts Covered:
 *  1. KMP (Knuth-Morris-Pratt) Algorithm (LPS Array)
 *  2. Rabin-Karp Algorithm (Rolling Hash)
 *  3. Z-Algorithm (Z-Array Computation)
 *  4. Manacher's Algorithm (Longest Palindromic Substring in O(N))
 * ============================================================================
 */

#include <iostream>
#include <vector>
#include <string>
#include <cassert>
#include <algorithm>

using namespace std;

// ============================================================================
// SECTION 1: KMP ALGORITHM
// ============================================================================

// Compute Longest Proper Prefix which is also a Suffix (LPS array)
vector<int> computeLPSArray(const string& pat) {
    int m = pat.length();
    vector<int> lps(m, 0);
    int len = 0; // Length of previous longest prefix suffix
    int i = 1;

    while (i < m) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1]; // Fall back to previous matching prefix
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

// Find all 0-indexed start positions of pattern in text
vector<int> KMPMatch(const string& text, const string& pat) {
    vector<int> matches;
    if (pat.empty() || text.length() < pat.length()) return matches;

    vector<int> lps = computeLPSArray(pat);
    int n = text.length();
    int m = pat.length();

    int i = 0; // Index for text
    int j = 0; // Index for pattern

    while (i < n) {
        if (pat[j] == text[i]) {
            i++;
            j++;
        }

        if (j == m) {
            matches.push_back(i - j); // Match found!
            j = lps[j - 1];
        } else if (i < n && pat[j] != text[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }

    return matches;
}

// ============================================================================
// SECTION 2: RABIN-KARP ROLLING HASH
// ============================================================================

vector<int> rabinKarpMatch(const string& text, const string& pat) {
    vector<int> matches;
    int n = text.length();
    int m = pat.length();
    if (m > n) return matches;

    long long p = 31; // Base prime
    long long MOD = 1e9 + 7;

    // Precompute p^(m-1) % MOD
    long long pPow = 1;
    for (int i = 0; i < m - 1; ++i) {
        pPow = (pPow * p) % MOD;
    }

    long long patHash = 0;
    long long textHash = 0;

    for (int i = 0; i < m; ++i) {
        patHash = (patHash * p + pat[i]) % MOD;
        textHash = (textHash * p + text[i]) % MOD;
    }

    for (int i = 0; i <= n - m; ++i) {
        if (patHash == textHash) {
            // Verify substring to prevent hash collision false positives
            if (text.substr(i, m) == pat) {
                matches.push_back(i);
            }
        }

        if (i < n - m) {
            // Slide window: remove leading char, add trailing char
            textHash = (textHash - text[i] * pPow) % MOD;
            if (textHash < 0) textHash += MOD;
            textHash = (textHash * p + text[i + m]) % MOD;
        }
    }

    return matches;
}

// ============================================================================
// SECTION 3: Z-ALGORITHM
// ============================================================================

vector<int> computeZArray(const string& s) {
    int n = s.length();
    vector<int> Z(n, 0);
    int L = 0, R = 0;

    for (int i = 1; i < n; ++i) {
        if (i > R) {
            L = R = i;
            while (R < n && s[R - L] == s[R]) R++;
            Z[i] = R - L;
            R--;
        } else {
            int k = i - L;
            if (Z[k] < R - i + 1) {
                Z[i] = Z[k];
            } else {
                L = i;
                while (R < n && s[R - L] == s[R]) R++;
                Z[i] = R - L;
                R--;
            }
        }
    }
    return Z;
}

vector<int> ZMatch(const string& text, const string& pat) {
    string concat = pat + "$" + text;
    vector<int> Z = computeZArray(concat);
    vector<int> matches;
    int m = pat.length();

    for (int i = m + 1; i < concat.length(); ++i) {
        if (Z[i] == m) {
            matches.push_back(i - m - 1);
        }
    }
    return matches;
}

// ============================================================================
// SECTION 4: MANACHER'S ALGORITHM (Longest Palindromic Substring in O(N))
// ============================================================================

string manacherLongestPalindrome(const string& s) {
    if (s.empty()) return "";

    // Step 1: Transform string by inserting '#' between characters
    string T = "^";
    for (char c : s) {
        T += "#";
        T += c;
    }
    T += "#$";

    int n = T.length();
    vector<int> P(n, 0);
    int C = 0, R = 0;

    for (int i = 1; i < n - 1; ++i) {
        int iMirror = 2 * C - i;

        if (R > i) {
            P[i] = min(R - i, P[iMirror]);
        } else {
            P[i] = 0;
        }

        // Expand palindrome centered at i
        while (T[i + 1 + P[i]] == T[i - 1 - P[i]]) {
            P[i]++;
        }

        // Update center and right boundary if palindrome centered at i expands past R
        if (i + P[i] > R) {
            C = i;
            R = i + P[i];
        }
    }

    // Find maximum palindrome radius
    int maxLen = 0;
    int centerIndex = 0;
    for (int i = 1; i < n - 1; ++i) {
        if (P[i] > maxLen) {
            maxLen = P[i];
            centerIndex = i;
        }
    }

    int start = (centerIndex - 1 - maxLen) / 2;
    return s.substr(start, maxLen);
}

// ============================================================================
// MAIN DRIVER & VERIFICATION SUITE
// ============================================================================

int main() {
    cout << "==========================================" << endl;
    cout << "   RUNNING STRING ALGORITHMS TEST SUITE   " << endl;
    cout << "==========================================" << endl;

    string text = "AABAACAADAABAABA";
    string pattern = "AABA";

    // Test 1: KMP Algorithm
    cout << "\n[Test 1] Testing KMP Algorithm..." << endl;
    vector<int> kmpMatches = KMPMatch(text, pattern);
    cout << "KMP Match indices: ";
    for (int idx : kmpMatches) cout << idx << " ";
    cout << endl;
    assert(kmpMatches == vector<int>({0, 9, 12}));
    cout << "✓ KMP Algorithm Passed!" << endl;

    // Test 2: Rabin-Karp Algorithm
    cout << "\n[Test 2] Testing Rabin-Karp Algorithm..." << endl;
    vector<int> rkMatches = rabinKarpMatch(text, pattern);
    assert(rkMatches == vector<int>({0, 9, 12}));
    cout << "✓ Rabin-Karp Algorithm Passed!" << endl;

    // Test 3: Z-Algorithm
    cout << "\n[Test 3] Testing Z-Algorithm..." << endl;
    vector<int> zMatches = ZMatch(text, pattern);
    assert(zMatches == vector<int>({0, 9, 12}));
    cout << "✓ Z-Algorithm Passed!" << endl;

    // Test 4: Manacher's Algorithm
    cout << "\n[Test 4] Testing Manacher's Algorithm..." << endl;
    string palString = "babad";
    string maxPal = manacherLongestPalindrome(palString);
    cout << "Longest Palindromic Substring of 'babad': " << maxPal << endl;
    assert(maxPal == "bab" || maxPal == "aba");
    cout << "✓ Manacher's Algorithm Passed!" << endl;

    cout << "\n==========================================" << endl;
    cout << "    ALL STRING ALGORITHMS TESTS PASSED!   " << endl;
    cout << "==========================================" << endl;

    return 0;
}
