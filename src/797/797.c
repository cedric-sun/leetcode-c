/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

#include <stdlib.h>
#include <string.h>

#define NMAX 15

int path[NMAX];
int plen;

int **_graph;
int _graphSize;
int *_graphColSize;

int **ans;
int ans_sz;
int *ans_plen;

int ans_buf_sz;

void new_ans() {
	if (ans_sz>=ans_buf_sz) {
		ans_buf_sz<<=1;
		ans = realloc(ans, ans_buf_sz * sizeof *ans);
		ans_plen = realloc(ans_plen, ans_buf_sz * sizeof *ans_plen);
	}
	ans[ans_sz] = malloc(plen * sizeof(int));
	memcpy(ans[ans_sz],path,plen*sizeof(int));
	ans_plen[ans_sz] = plen;
	ans_sz++;
}

void dfs(int root) {
	if (root == _graphSize-1) {
		new_ans();
		return;
	}
	for (int i=0;i<_graphColSize[root];i++) {
		path[plen++] = _graph[root][i];
		dfs(_graph[root][i]);
		plen--;
	}
}


int** allPathsSourceTarget(int** graph, int graphSize, int* graphColSize, int* returnSize, int** returnColumnSizes){
	_graph = graph;
	_graphSize = graphSize;
	_graphColSize = graphColSize;
	ans_buf_sz = 100;
	ans_sz=0;
	ans = malloc(ans_buf_sz * sizeof *ans);
	ans_plen = malloc(ans_buf_sz * sizeof *ans_plen);
	plen=0;

	path[plen++]=0;
	dfs(0);

	*returnSize=ans_sz;
	*returnColumnSizes = ans_plen;
	return ans;
}
