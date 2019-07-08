/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#include <stdlib.h>

typedef struct ListNode ln_t;

static inline ln_t *new_node() {
	ln_t *ret = malloc(sizeof *ret);
	ret->next = NULL;
	return ret;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
	ln_t *res = NULL;
	ln_t *cur = NULL;
	int carry=0;
	while (l1||l2||carry) {
		ln_t *tmp = new_node();
		int op1=l1?l1->val:0;
		int op2=l2?l2->val:0;
		int sum = op1+op2+carry;
		tmp->val = sum%10;
		carry=sum/10;
		l1=l1?l1->next:NULL;
		l2=l2?l2->next:NULL;
		if (!res)
			res = cur = tmp;
		else
			cur=cur->next = tmp;
	}
	return res;
}
