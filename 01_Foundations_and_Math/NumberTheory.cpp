/**
 * ============================================================================
 * PHASE 1: NUMBER THEORY MASTERY (C++)
 * ============================================================================
 * Concepts Covered:
 *  1. Euclidean Algorithm for Greatest Common Divisor (GCD) & LCM
 *  2. Binary Exponentiation (Fast Power - O(log N))
 *  3. Sieve of Eratosthenes (O(N log log N))
 *  4. Segmented Sieve for Range [L, R]
 *  5. Modular Arithmetic & Modular Inverse via Fermat's Little Theorem
 * ============================================================================
 */

#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>

using namespace std;

// ============================================================================
// SECTION 1: EUCLIDEAN GCD & LCM
// ============================================================================

/**
 * Intuition & Proof (Euclid's Lemma):
 *  gcd(a, b) = gcd(b, a % b).
 *  If d divides both a and b (a = k1*d, b = k2*d), then a % b = a - q*b = (k1 - q*k2)*d.
 *  Thus d also divides (a % b).
 * 
 * Time Complexity: O(log(min(a, b)))
 * Space Complexity: O(log(min(a, b))) for recursion stack frame depth.
 */
long long gcdEuclid(long long a, long long b) {
    if (b == 0) return a;
    return gcdEuclid(b, a % b);
}

long long lcmEuclid(long long a, long long b) {
    if (a == 0 || b == 0) return 0;
    // Divide first to prevent integer overflow before multiplication!
    return (a / gcdEuclid(a, b)) * b;
}

// ============================================================================
// SECTION 2: BINARY EXPONENTIATION (FAST POWER: a^b % MOD)
// ============================================================================

/**
 * Redundancy in Linear Power: Multiplying 'a', 'b' times takes O(b) steps.
 * 
 * Binary Exponentiation Insight:
 *  If b is EVEN:  a^b = (a^(b/2))^2
 *  If b is ODD:   a^b = a * (a^((b-1)/2))^2
 * 
 * Halving exponent at every step -> Logarithmic breakdown!
 * Time Complexity: O(log b)
 * Space Complexity: O(1) iterative implementation
 */
long long powerMod(long long base, long long exp, long long mod) {
    long long result = 1;
    base %= mod;
    while (exp > 0) {
        if (exp & 1) { // If exp is odd (bit 0 is 1)
            result = (__int128)result * base % mod;
        }
        base = (__int128)base * base % mod;
        exp >>= 1; // Divide exponent by 2
    }
    return result;
}

// ============================================================================
// SECTION 3: SIEVE OF ERATOSTHENES (Generate primes up to N)
// ============================================================================

/**
 * Problem: Find all prime numbers up to N.
 * Plain Trial Division for 1..N: O(N * sqrt(N)) time.
 * 
 * Sieve Insight:
 *  Mark true for all numbers 2..N.
 *  For every prime p, mark all multiples of p starting from p*p as false.
 *  Why start from p*p? Multiples like 2*p, 3*p, ... (p-1)*p were already marked by smaller primes!
 * 
 * Time Complexity: O(N log(log N)) - Sum of reciprocals of primes is O(log log N).
 * Space Complexity: O(N) boolean array.
 */
vector<int> sieveOfEratosthenes(int n) {
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;

    for (int p = 2; p * p <= n; ++p) {
        if (isPrime[p]) {
            for (int i = p * p; i <= n; i += p) {
                isPrime[i] = false;
            }
        }
    }

    vector<int> primes;
    for (int i = 2; i <= n; ++i) {
        if (isPrime[i]) primes.push_back(i);
    }
    return primes;
}

// ============================================================================
// SECTION 4: SEGMENTED SIEVE (Primes in Range [L, R])
// ============================================================================

/**
 * Problem: Find primes in range [L, R] where R can be large (e.g. 10^12), but R - L <= 10^6.
 * 
 * Strategy:
 *  1. Generate primes up to sqrt(R) using Standard Sieve.
 *  2. Create dummy boolean array of size (R - L + 1).
 *  3. For each prime p in sqrt(R), find first multiple of p >= L:
 *     firstMultiple = max(p * p, ((L + p - 1) / p) * p).
 *  4. Mark all multiples of p in range [L, R] as composite.
 * 
 * Time Complexity: O((R - L + 1) log log R + sqrt(R) log log sqrt(R))
 * Space Complexity: O(R - L + 1 + sqrt(R))
 */
vector<long long> segmentedSieve(long long L, long long R) {
    long long limit = sqrt(R);
    vector<int> basePrimes = sieveOfEratosthenes(limit);

    vector<bool> isPrimeRange(R - L + 1, true);

    for (int p : basePrimes) {
        long long firstMultiple = max((long long)p * p, ((L + p - 1) / p) * p);
        for (long long j = firstMultiple; j <= R; j += p) {
            isPrimeRange[j - L] = false;
        }
    }

    if (L == 1) isPrimeRange[0] = false; // 1 is not prime

    vector<long long> rangePrimes;
    for (long long i = L; i <= R; ++i) {
        if (isPrimeRange[i - L]) {
            rangePrimes.push_back(i);
        }
    }
    return rangePrimes;
}

// ============================================================================
// SECTION 5: MODULAR MULTIPLICATIVE INVERSE (Fermat's Little Theorem)
// ============================================================================

/**
 * Fermat's Little Theorem:
 *  If P is prime and a is not divisible by P:
 *  a^(P - 1) ≡ 1 (mod P)
 * 
 * Multiply both sides by a^(-1):
 *  a^(P - 2) ≡ a^(-1) (mod P)
 * 
 * Thus, Modular Inverse of 'a' modulo prime 'P' is (a^(P-2)) % P.
 * Used for Modular Division: (a / b) % P = (a * modInverse(b, P)) % P.
 * 
 * Time Complexity: O(log P) using Binary Exponentiation.
 */
long long modInverse(long long a, long long p) {
    return powerMod(a, p - 2, p);
}

// ============================================================================
// MAIN DRIVER & VERIFICATION SUITE
// ============================================================================

int main() {
    cout << "==========================================" << endl;
    cout << "   RUNNING NUMBER THEORY TEST SUITE       " << endl;
    cout << "==========================================" << endl;

    // Test 1: GCD and LCM
    cout << "\n[Test 1] Testing GCD and LCM..." << endl;
    assert(gcdEuclid(48, 18) == 6);
    assert(lcmEuclid(12, 18) == 36);
    cout << "✓ GCD(48, 18) = " << gcdEuclid(48, 18) << endl;
    cout << "✓ LCM(12, 18) = " << lcmEuclid(12, 18) << endl;

    // Test 2: Binary Exponentiation
    cout << "\n[Test 2] Testing Binary Exponentiation (2^10 % 1000)..." << endl;
    long long powRes = powerMod(2, 10, 1000);
    assert(powRes == 24); // 1024 % 1000 = 24
    cout << "✓ 2^10 % 1000 = " << powRes << endl;

    // Test 3: Sieve of Eratosthenes
    cout << "\n[Test 3] Testing Sieve of Eratosthenes up to 30..." << endl;
    vector<int> primesUpTo30 = sieveOfEratosthenes(30);
    cout << "Primes <= 30: ";
    for (int p : primesUpTo30) cout << p << " ";
    cout << endl;
    assert(primesUpTo30.size() == 10); // {2, 3, 5, 7, 11, 13, 17, 19, 23, 29}

    // Test 4: Segmented Sieve
    cout << "\n[Test 4] Testing Segmented Sieve in range [10, 30]..." << endl;
    vector<long long> segmentedPrimes = segmentedSieve(10, 30);
    cout << "Primes in [10, 30]: ";
    for (long long p : segmentedPrimes) cout << p << " ";
    cout << endl;
    assert(segmentedPrimes.size() == 6); // {11, 13, 17, 19, 23, 29}

    // Test 5: Modular Inverse
    cout << "\n[Test 5] Testing Modular Inverse (3^(-1) mod 11)..." << endl;
    long long MOD = 11;
    long long inv3 = modInverse(3, MOD);
    cout << "3^(-1) mod 11 = " << inv3 << endl;
    assert((3 * inv3) % MOD == 1); // 3 * 4 = 12 ≡ 1 mod 11

    cout << "\n==========================================" << endl;
    cout << "    ALL NUMBER THEORY TESTS PASSED!       " << endl;
    cout << "==========================================" << endl;

    return 0;
}
