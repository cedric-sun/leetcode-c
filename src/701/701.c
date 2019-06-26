/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#include <stdlib.h>

typedef struct TreeNode tn_t;

static tn_t *_root;
static int v;

static inline tn_t *new_node() {
	tn_t *ret = malloc(sizeof *ret);
	ret->val = v;
	ret-> left = ret->right = NULL;
	return ret;
}

static void dfs(tn_t *root) {
	if (v > root->val)
		if (root->right)	dfs(root->right);
		else 			root->right = new_node();
	else
		if (root->left)		dfs(root->left);
		else 			root->left = new_node();
}

struct TreeNode* insertIntoBST(struct TreeNode* root, int val){
	_root = root;
	v = val;
	dfs(root);
	return _root;
}
