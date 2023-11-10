/*
5.Input the representation of a sparse matrix. Find the representation of its transpose.
*/


#include <stdio.h>

int main(){
	int n;
	printf("Enter total number of non-zero elements: ");
	scanf("%d",&n);
	int rep[3][n], temp[n];
	
	for(int i=0; i<n; i++){
		printf("Enter row: ");
		scanf("%d",&rep[0][i]);
		printf("Enter column: ");
		scanf("%d",&rep[1][i]);
		printf("Enter value: ");
		scanf("%d",&rep[2][i]);
	}
	
	printf("\nSparse representation:\n");
	for(int i=0; i<n; i++){
		printf("%d %d %d\n", rep[0][i], rep[1][i], rep[2][i]);
	}	
	
	for(int i=0; i<n; i++){
		temp[i] = rep[0][i];
	}
	for(int i=0; i<n; i++){
		rep[0][i] = rep[1][i];
	}
	for(int i=0; i<n; i++){
		rep[1][i] = temp[i];
	}
	
	
	printf("\ntranspose:\n");
	for(int i=0; i<n; i++){
		printf("%d %d %d\n", rep[0][i], rep[1][i], rep[2][i]);
	}	
}
