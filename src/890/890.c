/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#include <stdlib.h>
#include <string.h>

void formalize(char *str, char *res) {
	int map[128] = {0};
	char cur;
	int cnt=1;
	int i;
	for (i=0;cur=str[i];i++) {
		if (!map[cur])
			map[cur] = cnt++;
		res[i] = map[cur];
	}
}

#define NSTR 100
#define STRSZ 100
char ** findAndReplacePattern(char ** words, int wordsSize, char * pattern, int* returnSize){
	char fmlzd_words[NSTR][STRSZ];
	char fmlzd_pattern[STRSZ];
	for (int i=0;i<wordsSize;i++) {
		formalize(words[i], fmlzd_words[i]);
	}
	formalize(pattern,fmlzd_pattern);

	char **res = malloc(NSTR * sizeof *res);
	int cnt=0;
	int len = strlen(pattern);
	for (int i=0;i<wordsSize;i++) {
		if (!memcmp(fmlzd_words[i],fmlzd_pattern,len)) {
			res[cnt] = malloc(STRSZ * sizeof(**res));
			strcpy(res[cnt++],words[i]);
		}
	}
	*returnSize = cnt;
	return res;
}
