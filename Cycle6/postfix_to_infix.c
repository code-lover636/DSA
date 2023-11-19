#include <stdio.h>
#include <string.h>

int isOperand(char operand){
	if( ('a'<=operand && operand<='z') || (operand>='A' && operand<='Z') )
		return 1;
	else
		return 0;
}

void push(char stack[100][100], char operand, int *top){
    stack[++(*top)][0]=operand;
}

void pop(char stack[][100], int *top){
    (*top)--;
}

void convert(char postexp[100], char stack[100][100], int *top){
	for(int i=0; i<strlen(postexp); i++){
		if(isOperand(postexp[i])){
			push(stack, postexp[i], &(*top));
		}
		else{
      pop(stack, &(*top));
			pop(stack, &(*top));
			char temp[100] = "(";
			strcat(temp,stack[++(*top)]);
			int len = strlen(stack[(*top)])+1;
			temp[len] = postexp[i];
			strcat(temp,stack[(*top)+1]);
			temp[strlen(temp)] = ')';
			strcpy(stack[*top], temp);
		}
	}
}

int main(void) {
	char postexp[100], stack[100][100];
	int top = -1;
	printf("Enter postfix expression: ");
	scanf("%s", postexp);
	convert(postexp, stack, &top);
	printf("%s\n", stack[top]);
}
