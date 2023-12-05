#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100

int stack[MAX];
int top = -1;
char postfix[MAX];
char infix[MAX];

int isFull(){
    return top==MAX-1;
}

int isEmpty(){
    return top==-1;
}

int pop(){
    if(isEmpty()){
        printf("Stack underflow.%s\n", postfix);
        return -1;
    }
    return stack[top--];
}

void push(char item){
    if(isFull()){
        printf("Stack overflow.\n");
        exit(0);
    }
    stack[++top] = item;
}

void add(char item){
    int len = strlen(postfix);
    if(len==MAX-1){
        printf("Array is full.\n");
        exit(0);
    }
    postfix[len] = item;
    postfix[len+1] = '\0';
}

int precedence(char op){
    if(op=='^')
        return 3;
    else if(op=='*' || op=='/')
        return 2;
    else if(op=='+' || op=='-')
        return 1;
    else
        return 0;
}

void convert(){
    for(int i=0; i<strlen(infix); i++){
        if(isalnum(infix[i])){
            add(infix[i]);
        }
        else if(infix[i] == '('){
            push(infix[i]);
        }
        else if(infix[i] == ')'){
            while(top>-1 && stack[top] != '(')
                add(pop());
            pop();
        }
        else{
            while(top>-1 && precedence(stack[top])>=precedence(infix[i]))
                add(pop());
            push(infix[i]);
        }
    }
    
    for(int i=top; i>=0; i--){
        add(pop());
    }
}

int main() {
    printf("Enter infix expression: ");
    scanf("%s", &infix);
    postfix[0] = '\0';
    convert();
    printf("Postfix expression: %s\n", postfix);
}
