/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#include <stdlib.h>
#include <stddef.h>
#include <limits.h>

static int *arr;

/* [l,r) */
static int find_max_idx(size_t l, size_t r) {
	int maxI = l;
	for (int i=l;i<r;i++) {
		if (arr[i]>arr[maxI]) {
			maxI = i;
		}
	}
	return maxI;
}

static struct TreeNode *dfs(size_t l, size_t r) {
	if (r-l<=0)
		return NULL;
	int maxI = find_max_idx(l,r);
	struct TreeNode *root = malloc(sizeof *root);
	root->val = arr[maxI];
	root->left = dfs(l,maxI);
	root->right = dfs(maxI+1,r);
	return root;
}

struct TreeNode* constructMaximumBinaryTree(int* nums, int numsSize){
	arr = nums;
	return dfs(0,numsSize);
}
