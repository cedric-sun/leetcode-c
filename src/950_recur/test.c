#include "950.c"

#include <stdio.h>
#include <stdlib.h>

int main() {
	int test[] = {17,13,11,2,3,5,7,15,22};
	const int sz = sizeof(test)/sizeof(int);
	int retsz;
	int *ret = deckRevealedIncreasing(test,sz,&retsz);
	for (int i=0;i<sz;i++)
		printf("%d ",ret[i]);
	putchar('\n');
}
