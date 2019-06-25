#include <stddef.h>
#include <string.h>
#define N 26

static size_t ans,newlen;
static unsigned char freq[N];

static void dfs() {
	for (int i=0;i<newlen;i++) {
		if (freq[i]) {
			freq[i]--;
			ans++;
			dfs();
			freq[i]++;
		}
	}
}

static void stupid_leetcode_init() {
	ans = newlen = 0;
	memset(freq,0,N);
}

int numTilePossibilities(char * tiles){
	stupid_leetcode_init();
	for (int i=0;tiles[i];i++) {
		freq[tiles[i]-'A']++;
	}

	for (int i=0;i<N;i++)
		if (freq[i]) freq[newlen++] = freq[i];
	dfs();
	return ans;
}
