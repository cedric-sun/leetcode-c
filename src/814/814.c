/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#include <stddef.h>

typedef struct TreeNode tn_t;

int dfs(tn_t *root) {
	if (root == NULL) return 0;
	int lc_1 = dfs(root->left);
	int rc_1 = dfs(root->right);
	if (!lc_1) root->left = NULL;
	if (!rc_1) root->right = NULL;
	return lc_1 || rc_1 || root->val;
}

struct TreeNode* pruneTree(struct TreeNode* root){
	if (!dfs(root))
		root=NULL;
	return root;
}
