/*
4.Input the representation of two sparse matrices. Obtain the representation of their sum.
*/

#include <stdio.h>

int main(){
	int n, m, max, flag=1;
	printf("Enter total number of non-zero elements (matrix1 ");
	scanf("%d",&n);
	int rep1[3][n];
	
	for(int i=0; i<n; i++){
		printf("Enter row: ");
		scanf("%d",&rep1[0][i]);
		printf("Enter column: ");
		scanf("%d",&rep1[1][i]);
		printf("Enter value: ");
		scanf("%d",&rep1[2][i]);
	}
	
	printf("\nEnter total number of non-zero elements (matrix2): ");
	scanf("%d",&m);
	int rep2[3][m];
	
	for(int i=0; i<m; i++){
		printf("Enter row: ");
		scanf("%d",&rep2[0][i]);
		printf("Enter column: ");
		scanf("%d",&rep2[1][i]);
		printf("Enter value: ");
		scanf("%d",&rep2[2][i]);
	}
	
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(rep1[0][i]==rep2[0][i] && rep1[1][i]==rep2[1][i]){
				rep1[2][i] += rep2[2][i];
				rep2[2][i]=0;
			}
				
		}
	}
	
	for(int i=0; i<n; i++){
		printf("%d %d %d\n", rep1[0][i], rep1[1][i], rep1[2][i]);
	}
	for(int i=0; i<n; i++){
		if(rep2[2][i]!=0){
			printf("%d %d %d\n", rep2[0][i], rep2[1][i], rep2[2][i]);
		}
	}
	
				
		
}
