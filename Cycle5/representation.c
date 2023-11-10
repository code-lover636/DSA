/*
3.Given a sparse matrix . Represent and store it using an efficient method. Also find the sparsity (The sparsity of a matrix can be quantified with a score, which is the number of zero values in the matrix divided by the total number of elements in the matrix.)
*/

#include <stdio.h>

int main(){
	int n, m, sp=0, count=0;
	printf("Enter total row, column of matrix: ");
	scanf("%d",&m);
	scanf("%d",&n);
	
	int mat[m][n];
	
	
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			printf("Enter element matrix[%d][%d]: ", i+1, j+1);
			scanf("%d",&mat[i][j]);
		}
	}
	
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			if(mat[i][j] !=0){
				sp++;
			}
		}
	}
	
	int rep[3][sp];
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			if(mat[i][j] !=0){
				rep[0][count] = i;
				rep[1][count] = j;
				rep[2][count++] = mat[i][j];
			}
		}
	}
	
	for(int i=0; i<sp; i++){
		printf("%d %d %d\n", rep[0][i], rep[1][i], rep[2][i]);
	}
	float tot = n*m;
	printf("Sparsity = %f\n", 1-(sp/tot) );
		
}
