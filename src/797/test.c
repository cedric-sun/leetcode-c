#include <stdlib.h>
#include <stdio.h>

#include "797.c"

/* [[1,4,3],[3,2],[4,3],[4],[]] */
void test0() {
	int graphSize = 5;
	int **graph = malloc(graphSize*sizeof *graph);
	int *graphColSize = malloc(graphSize * sizeof *graphColSize);
	graph[0] = (int[]){1,4,3};	graphColSize[0] = 3;
	graph[1] = (int[]){3,2};	graphColSize[1] = 2;
	graph[2] = (int[]){4,3};	graphColSize[2] = 2;
	graph[3] = (int[]){4};		graphColSize[3] = 1;
	graph[4] = (int[]){0xdeadbeef};		graphColSize[4] = 0;

	int retsz;
	int *retColSizes;
	int **wefans=allPathsSourceTarget(graph,graphSize,graphColSize,&retsz,&retColSizes);

	for (int i=0;i<retsz;i++) {
		free(wefans[i]);
	}
	free(wefans);
	free(retColSizes);
	free(graphColSize);
	free(graph);
}

/* [[4,3,11,5,7,8,10,2,1,6],[2,9,3,11,10,6,7,4,5],[10,7,9,4,3,6,11,5],[9,4,11,6,8,10,7,5],[5,7,6,9,8,11,10],[8,7,11,9,10,6],[10,7,11,9,8],[9,10,11,8],[10,9],[11,10],[11],[]] */
void test1() {
	int graphSize = 12;
	int **graph = malloc(graphSize*sizeof *graph);
	int *graphColSize = malloc(graphSize * sizeof *graphColSize);
	graph[0] = (int[]){4,3,11,5,7,8,10,2,1,6};	graphColSize[0]=10;
	graph[1] = (int[]){2,9,3,11,10,6,7,4,5};	graphColSize[1]=9;
	graph[2] = (int[]){10,7,9,4,3,6,11,5};		graphColSize[2]=8;
	graph[3] = (int[]){9,4,11,6,8,10,7,5};		graphColSize[3]=8;
	graph[4] = (int[]){5,7,6,9,8,11,10};		graphColSize[4]=7;
	graph[5] = (int[]){8,7,11,9,10,6};		graphColSize[5]=6;
	graph[6] = (int[]){10,7,11,9,8};		graphColSize[6]=5;
	graph[7] = (int[]){9,10,11,8};			graphColSize[7]=4;
	graph[8] = (int[]){10,9};			graphColSize[8]=2;
	graph[9] = (int[]){11,10};			graphColSize[9]=2;
	graph[10] = (int[]){11};			graphColSize[10]=1;
	graph[11] = (int[]){0xdeadbeef};		graphColSize[11]=0;

	int retsz;
	int *retColSizes;
	int **wefans=allPathsSourceTarget(graph,graphSize,graphColSize,&retsz,&retColSizes);

	for (int i=0;i<retsz;i++) {
		free(wefans[i]);
	}
	free(wefans);
	free(retColSizes);
	free(graphColSize);
	free(graph);
}

int main() {
	test1();
}
