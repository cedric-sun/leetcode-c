#include "890.c"
#include <stdio.h>

int main() {
	char *test[] = {
		"qxrwtncxyoqwmsxoavos",
		"eqvzjrnqgkezxmqkhdkm",
		"pjxmgdujohpmtsjhazhs",
		"yqhlipeqwnylkrqnsbnr",
		"plktdyslmoptqflowaof"};
	char pattern[] = "ghtxpauhingxekhnoqnk";
	int retsz;
	char **res = findAndReplacePattern(test,5,pattern,&retsz);
	for (int i=0;i<retsz;i++) {
		printf("%s\n",res[i]);
	}
}
