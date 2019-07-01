struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

#include "894.c"

int main() {
    int retsz;
    tn_t **ans = allPossibleFBT(7, &retsz);
    free(ans);
}
