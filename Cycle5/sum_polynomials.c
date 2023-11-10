/*
1. Write a program to read two polynomials and store them in an array. Calculate the sum of the two polynomials and display the first polynomial, second polynomial and the resultant polynomial.
*/

#include <stdio.h>

void display(int mat[], int n){

	for(int i=0; i<n; i++){
		printf("%dx^%d + ", mat[i], i);
	}
	printf("\b \b \n");
}

int main(){
	int n1, n2;
	printf("Enter the degree of polynomial 1: ");
	scanf("%d",&n1);
	printf("Enter the degree of polynomial 2: ");
	scanf("%d",&n2);
	
	int poly1[n1], poly2[n2], max;
	if(n1>n2)
		max=n1;
	else
		max=n2;
	
	int res[max];
	
	for(int i=0; i<n1; i++){
		printf("Polynomial 1, enter cofficient of x^%d: ", i);
		scanf("%d",&poly1[i]);
	}
	
	for(int i=0; i<n2; i++){
		printf("Polynomial 2, enter cofficient of x^%d: ", i);
		scanf("%d",&poly2[i]);
	}
	
	for(int i=0; i<max; i++){
		if(n1==max && i>=n2){
			res[i] = poly1[i];
		}
		else if(n2==max && i>=n1){
			res[i] = poly2[i];
		}
		else{
			res[i] = poly1[i]+poly2[i];
		}
	}
	
	display(poly1, n1);
	display(poly2, n2);
	display(res, max);
	
}
