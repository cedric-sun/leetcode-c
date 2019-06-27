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

static int *preo;

static tn_t *dfs(int l, int r) {
	if (r-l<=0)
		return NULL;
	tn_t *root = malloc(sizeof *root);
	root->val = preo[l];
	int i;
	for (i=l+1;i<r;i++)
		if (preo[i]>preo[l])
			break;
	root->left = dfs(l+1,i);
	root->right = dfs(i,r);
	return root;
}

struct TreeNode* bstFromPreorder(int* preorder, int preorderSize){
	preo = preorder;
	return dfs(0,preorderSize);
}
