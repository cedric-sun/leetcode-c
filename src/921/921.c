char stack[1010];
int top;

int minAddToMakeValid(char * S){
	top=-1;
	for (int i=0;S[i];i++) {
		if (top<0 || stack[top] == ')' || S[i] == '(')
			stack[++top]=S[i];
		else
			top--;
	}
	return top+1;
}
