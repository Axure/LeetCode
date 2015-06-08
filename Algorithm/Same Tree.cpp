/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == NULL || q == NULL) {
            if (q == NULL&& p == NULL) {
                return true;
            } else {
                return false;
            }
        } else {
            if (p->val != q->val) {
                return false;
            } else {
                return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
            }
        }
    }
};

int main(int argc, char const *argv[])
{
	TreeNode a = TreeNode(5);
	TreeNode b = TreeNode(6);
	a.left = &b;

	Solution mySolution;

	cout << mySolution.isSameTree(&a, &b);
	return 0;
}