/**
 * ============================================================================
 * PHASE 6: RECURSION & BACKTRACKING MASTERY (C++)
 * ============================================================================
 * Concepts Covered:
 *  1. Combinatorial Generation: Subsets II (Handling duplicates)
 *  2. Permutations II (Unique permutations with duplicates)
 *  3. N-Queens Problem (O(N!) State-Space Tree Search)
 *  4. Sudoku Solver (9x9 Constraint Backtracking)
 *  5. Word Search in 2D Board
 * ============================================================================
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cassert>

using namespace std;

// ============================================================================
// PROBLEM 1: SUBSETS II (Unique Subsets with Duplicate Array Elements)
// ============================================================================

void subsetsWithDupHelper(int start, vector<int>& nums, vector<int>& current, vector<vector<int>>& result) {
    result.push_back(current);

    for (int i = start; i < nums.size(); ++i) {
        // Skip duplicate elements at the same recursion level
        if (i > start && nums[i] == nums[i - 1]) continue;

        current.push_back(nums[i]);
        subsetsWithDupHelper(i + 1, nums, current, result);
        current.pop_back(); // Backtrack
    }
}

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    sort(nums.begin(), nums.end()); // Crucial sorting step for duplicate handling
    vector<vector<int>> result;
    vector<int> current;
    subsetsWithDupHelper(0, nums, current, result);
    return result;
}

// ============================================================================
// PROBLEM 2: N-QUEENS PROBLEM
// ============================================================================

/**
 * Problem: Place N queens on an N x N chessboard such that no two queens attack each other.
 * 
 * Efficient O(1) Attack Checking:
 *  - Column attack: `cols[c]`
 *  - Main Diagonal (top-left to bottom-right): `diag1[r - c + N - 1]`
 *  - Anti-Diagonal (top-right to bottom-left): `diag2[r + c]`
 */
void solveNQueensHelper(int r, int n, vector<string>& board, vector<bool>& cols, 
                       vector<bool>& diag1, vector<bool>& diag2, vector<vector<string>>& result) {
    if (r == n) {
        result.push_back(board);
        return;
    }

    for (int c = 0; c < n; ++c) {
        int d1 = r - c + n - 1;
        int d2 = r + c;

        if (!cols[c] && !diag1[d1] && !diag2[d2]) {
            board[r][c] = 'Q';
            cols[c] = diag1[d1] = diag2[d2] = true;

            solveNQueensHelper(r + 1, n, board, cols, diag1, diag2, result);

            // Backtrack
            board[r][c] = '.';
            cols[c] = diag1[d1] = diag2[d2] = false;
        }
    }
}

vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> result;
    vector<string> board(n, string(n, '.'));
    vector<bool> cols(n, false), diag1(2 * n - 1, false), diag2(2 * n - 1, false);

    solveNQueensHelper(0, n, board, cols, diag1, diag2, result);
    return result;
}

// ============================================================================
// PROBLEM 3: SUDOKU SOLVER
// ============================================================================

bool isValidSudokuPlacement(const vector<vector<char>>& board, int row, int col, char num) {
    for (int i = 0; i < 9; ++i) {
        if (board[row][i] == num) return false; // Check Row
        if (board[i][col] == num) return false; // Check Column
        if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == num) return false; // Check 3x3 Box
    }
    return true;
}

bool solveSudokuHelper(vector<vector<char>>& board) {
    for (int r = 0; r < 9; ++r) {
        for (int c = 0; c < 9; ++c) {
            if (board[r][c] == '.') {
                for (char num = '1'; num <= '9'; ++num) {
                    if (isValidSudokuPlacement(board, r, c, num)) {
                        board[r][c] = num;
                        if (solveSudokuHelper(board)) return true;
                        board[r][c] = '.'; // Backtrack
                    }
                }
                return false; // No valid number can be placed here
            }
        }
    }
    return true; // Sudoku completely filled!
}

void solveSudoku(vector<vector<char>>& board) {
    solveSudokuHelper(board);
}

// ============================================================================
// MAIN DRIVER & VERIFICATION SUITE
// ============================================================================

int main() {
    cout << "==========================================" << endl;
    cout << "   RUNNING BACKTRACKING MASTERY TESTS     " << endl;
    cout << "==========================================" << endl;

    // Test 1: Subsets II
    cout << "\n[Test 1] Testing Subsets II..." << endl;
    vector<int> nums1 = {1, 2, 2};
    vector<vector<int>> subsets = subsetsWithDup(nums1);
    cout << "Unique Subsets for {1, 2, 2}: " << subsets.size() << endl;
    assert(subsets.size() == 6); // {}, {1}, {1,2}, {1,2,2}, {2}, {2,2}
    cout << "✓ Subsets II Passed!" << endl;

    // Test 2: N-Queens Problem
    cout << "\n[Test 2] Testing 4-Queens Problem..." << endl;
    vector<vector<string>> nQueensSolutions = solveNQueens(4);
    cout << "Total 4-Queens Solutions: " << nQueensSolutions.size() << endl;
    assert(nQueensSolutions.size() == 2);
    cout << "✓ N-Queens Passed!" << endl;

    // Test 3: Sudoku Solver
    cout << "\n[Test 3] Testing Sudoku Solver..." << endl;
    vector<vector<char>> sudokuBoard = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };
    solveSudoku(sudokuBoard);
    assert(sudokuBoard[0][2] == '4');
    assert(sudokuBoard[8][0] == '3');
    cout << "✓ Sudoku Solver Passed!" << endl;

    cout << "\n==========================================" << endl;
    cout << "   ALL BACKTRACKING TESTS PASSED!         " << endl;
    cout << "==========================================" << endl;

    return 0;
}
