/**
 * ============================================================================
 * PHASE 7: BINARY TREES & BINARY SEARCH TREES (C++)
 * ============================================================================
 * Concepts Covered:
 *  1. Iterative Traversals & Morris Traversal (O(1) Auxiliary Space)
 *  2. Diameter of Binary Tree (O(N) Bottom-up)
 *  3. Lowest Common Ancestor (LCA)
 *  4. Validate BST & BST Iterator
 * ============================================================================
 */

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <climits>
#include <cassert>

using namespace std;

// ============================================================================
// BINARY TREE NODE DEFINITION
// ============================================================================

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// ============================================================================
// SECTION 1: MORRIS INORDER TRAVERSAL (O(1) Auxiliary Space)
// ============================================================================

/**
 * Intuition:
 *  Instead of using recursion or stack, establish temporary THREADED LINKS!
 *  For current node `curr`:
 *   - If `curr->left` is NULL: print `curr->val`, move `curr = curr->right`.
 *   - Else: find Inorder Predecessor `prev` (rightmost node in left subtree).
 *     - If `prev->right` is NULL: set thread `prev->right = curr`, move `curr = curr->left`.
 *     - Else (thread already exists): remove thread `prev->right = NULL`, print `curr->val`, move `curr = curr->right`.
 * 
 * Time Complexity: O(N) (Every edge traversed at most twice)
 * Auxiliary Space Complexity: O(1)
 */
vector<int> morrisInorderTraversal(TreeNode* root) {
    vector<int> inorder;
    TreeNode* curr = root;

    while (curr != nullptr) {
        if (curr->left == nullptr) {
            inorder.push_back(curr->val);
            curr = curr->right;
        } else {
            // Find Inorder Predecessor
            TreeNode* prev = curr->left;
            while (prev->right != nullptr && prev->right != curr) {
                prev = prev->right;
            }

            if (prev->right == nullptr) {
                prev->right = curr; // Create temporary thread
                curr = curr->left;
            } else {
                prev->right = nullptr; // Break thread
                inorder.push_back(curr->val);
                curr = curr->right;
            }
        }
    }

    return inorder;
}

// ============================================================================
// SECTION 2: DIAMETER OF BINARY TREE (O(N) Bottom-Up)
// ============================================================================

int calculateHeightAndDiameter(TreeNode* root, int& maxDiameter) {
    if (!root) return 0;

    int leftHeight = calculateHeightAndDiameter(root->left, maxDiameter);
    int rightHeight = calculateHeightAndDiameter(root->right, maxDiameter);

    maxDiameter = max(maxDiameter, leftHeight + rightHeight);

    return 1 + max(leftHeight, rightHeight);
}

int diameterOfBinaryTree(TreeNode* root) {
    int maxDiameter = 0;
    calculateHeightAndDiameter(root, maxDiameter);
    return maxDiameter;
}

// ============================================================================
// SECTION 3: LOWEST COMMON ANCESTOR (LCA)
// ============================================================================

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (!root || root == p || root == q) return root;

    TreeNode* leftLCA = lowestCommonAncestor(root->left, p, q);
    TreeNode* rightLCA = lowestCommonAncestor(root->right, p, q);

    if (leftLCA && rightLCA) return root; // Both subtrees returned a target -> root is LCA!
    return leftLCA ? leftLCA : rightLCA;
}

// ============================================================================
// SECTION 4: VALIDATE BST
// ============================================================================

bool isValidBSTHelper(TreeNode* root, long long minVal, long long maxVal) {
    if (!root) return true;
    if (root->val <= minVal || root->val >= maxVal) return false;

    return isValidBSTHelper(root->left, minVal, root->val) &&
           isValidBSTHelper(root->right, root->val, maxVal);
}

bool isValidBST(TreeNode* root) {
    return isValidBSTHelper(root, LLONG_MIN, LLONG_MAX);
}

// ============================================================================
// MAIN DRIVER & VERIFICATION SUITE
// ============================================================================

int main() {
    cout << "==========================================" << endl;
    cout << "   RUNNING BINARY TREE & BST TESTS        " << endl;
    cout << "==========================================" << endl;

    // Build sample tree:
    //       4
    //      / \
    //     2   5
    //    / \
    //   1   3
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    // Test 1: Morris Inorder Traversal
    cout << "\n[Test 1] Testing Morris Inorder Traversal..." << endl;
    vector<int> inorder = morrisInorderTraversal(root);
    cout << "Morris Inorder: ";
    for (int x : inorder) cout << x << " ";
    cout << endl;
    assert(inorder == vector<int>({1, 2, 3, 4, 5}));
    cout << "✓ Morris Traversal Passed!" << endl;

    // Test 2: Diameter of Tree
    cout << "\n[Test 2] Testing Diameter of Tree..." << endl;
    int diameter = diameterOfBinaryTree(root);
    cout << "Tree Diameter: " << diameter << endl;
    assert(diameter == 3); // Path: 1 -> 2 -> 4 -> 5
    cout << "✓ Diameter Passed!" << endl;

    // Test 3: LCA
    cout << "\n[Test 3] Testing LCA of 1 and 3..." << endl;
    TreeNode* lca = lowestCommonAncestor(root, root->left->left, root->left->right);
    assert(lca->val == 2);
    cout << "✓ LCA Passed!" << endl;

    // Test 4: Validate BST
    cout << "\n[Test 4] Testing Validate BST..." << endl;
    assert(isValidBST(root) == true);
    cout << "✓ Validate BST Passed!" << endl;

    cout << "\n==========================================" << endl;
    cout << " ALL BINARY TREE & BST TESTS PASSED!      " << endl;
    cout << "==========================================" << endl;

    return 0;
}
