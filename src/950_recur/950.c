/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#include <stdlib.h>
#include <string.h>

static int *_deck;

/*	non-flip	****---	*-*-*-*
 *	flip		***----	-*-*-*-
 */
static void reorder(int l, int r,int flip) {
	if (r-l<=1) {
		return;
	}
	int len = r-l;
	int naster = (len+1)>>1;
	if (len&1 && flip)
		naster--;
	int ndash = len -naster;
	int t = l + naster;
	reorder(t,r,flip ^ len&1);
	static int bf_aster[500];
	static int bf_dash[500];
	memcpy(bf_aster, _deck+l,sizeof(int)*naster);
	memcpy(bf_dash, _deck+t,sizeof(int)*ndash);
	for (int i=0,j=0,k=0;i<len;i++)
		if (i&1 ^ flip) _deck[l+i] = bf_dash[k++];
		else _deck[l+i] = bf_aster[j++];
}

static int comp(const void *a, const void *b) {
	return *(const int*)a<*(const int*)b?-1:*(const int*)a>*(const int*)b?1:0;
}

int* deckRevealedIncreasing(int* deck, int deckSize, int* returnSize){
	_deck = deck;
	*returnSize = deckSize;
	qsort(deck, deckSize, sizeof *deck, comp);
#define NOFLIP 0
	reorder(0,deckSize,NOFLIP);
	int *ret = malloc(sizeof(int)*deckSize);
	memcpy(ret,deck,sizeof(int)*deckSize);
	return ret;
}
