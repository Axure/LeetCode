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
    int maxDepth(TreeNode* root) {
        if (root == NULL) {
        	return 0;
        } else {
        	return max(maxDepth(root->left), maxDepth(root->right)) + 1;
        }
    }
};

int main(int argc, char const *argv[])
{
	TreeNode a = TreeNode(5);
	TreeNode b = TreeNode(6);
	a.left = &b;

	Solution mySolution;

	cout << mySolution.maxDepth(&a) << endl;
    cout << mySolution.maxDepth(&b);
	return 0;
}