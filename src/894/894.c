/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#include <stdlib.h>

typedef struct TreeNode tn_t;

static tn_t **ans[20];
static int sz[20];

tn_t *deep_copy(tn_t *root) {
	if (root == NULL)
		return NULL;
	tn_t *ret = malloc(sizeof *ret);
	ret->val = root->val;
	ret->left = deep_copy(root->left);
	ret->right = deep_copy(root->right);
	return ret;
}

tn_t *new_node(tn_t *lc, tn_t *rc) {
	tn_t *ret = malloc(sizeof *ret);
	ret->val = 0;
	ret->left =lc;
	ret->right=rc;
	return ret;
}

#define MTPN 5000

void preproc() {
	ans[1] = malloc(MTPN * sizeof(tn_t*));
	ans[1][0] = new_node(NULL,NULL);
	sz[1] = 1;
	for (int i=3;i<20;i+=2) {
		int cnt = 0;
		ans[i] = malloc(MTPN * sizeof(tn_t*));
		for (int x=1;x<i;x+=2) {
			for (int j=0;j<sz[x];j++) {
				for (int k=0;k<sz[i-x-1];k++) {
					ans[i][cnt++] = new_node(deep_copy(ans[x][j]),deep_copy(ans[i-x-1][k]));
				}
			}
		}
		sz[i]=cnt;
	}
}

struct TreeNode** allPossibleFBT(int N, int* returnSize){
	if (!( N&1 )) {
		*returnSize = 0;
		return NULL;
	}
	if (!ans[1]) {
		preproc();
	}
	tn_t **tns_copy = malloc(sz[N] * sizeof *tns_copy);
	for (int i=0;i<sz[N];i++)
		tns_copy[i]=deep_copy(ans[N][i]);
	*returnSize = sz[N];
	return tns_copy;
}
