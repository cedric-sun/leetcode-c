/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#include <stdlib.h>

static int v;
static struct TreeNode *_root;

inline struct TreeNode *new_node(int v) {
	struct TreeNode *ret = malloc(sizeof *ret);
	ret->val = v;
	ret -> left = ret->right = NULL;
	return ret;
}

void dfs(struct TreeNode *root, struct TreeNode *prev) {
	if (root == NULL) {
		prev -> right = new_node(v);
		return;
	}
	if (v > root->val) {
		struct TreeNode *node = new_node(v);
		node->left = root;
		if (prev)
			prev -> right = node;
		else
			_root = node;
		return;
	}
	dfs(root->right,root);
}

struct TreeNode* insertIntoMaxTree(struct TreeNode* root, int val){
	v = val;
	_root = root;
	dfs(root,NULL);
	return _root;
}
