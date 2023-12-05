#include <stdio.h>
#include <string.h>
#include <math.h>

int isOperand(char operand){
	if( ('0'<=operand && operand<='9'))
		return 1;
	else
		return 0;
}

void push(int stack[], int operand, int *top){
    stack[++(*top)]=operand;
}

void pop(int stack[], int *top){
    (*top)--;
}

int compute(int num1, int num2, char operator){
    switch(operator){
        case '+':
            return num1+num2;
        case '-':
            return num1-num2;
        case '/':
            return num1/num2;
        case '*':
            return num1*num2;
        case '^':
            return pow(num1,num2);
    }
}

void convert(char postexp[], int stack[], int *top){
	for(int i=0; i<strlen(postexp); i++){
		if(isOperand(postexp[i])){
			int n = postexp[i]-48;
			push(stack, n, &(*top));
		}
		else{
            		pop(stack, &(*top));
			pop(stack, &(*top));
            		int ans = compute(stack[(*top)+1], stack[(*top)+2],postexp[i]);
            		push(stack, ans, &(*top));
		}
	}
}

int main(void) {
	char postexp[100];
	int top = -1, stack[100];
	printf("Enter postfix expression: ");
	scanf("%s", postexp);
	convert(postexp, stack, &top);
	printf("%d\n", stack[top]);
}
