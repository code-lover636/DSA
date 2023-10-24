/*
4.Saddle Point in a Matrix: Find and print all saddle points (elements that are both the smallest in their row and the largest in their column) in a given matrix.
*/


#include <stdio.h>

void findSaddle(int row, int col, int mat[row][col]){
	
	for(int i=0; i<row; i++){
		int min = mat[i][0], j_index=0, flag=1;
		for(int j=0; j<col; j++){
			if(mat[i][j]<min){
				min = mat[i][j];
				j_index = j;
			}
		}
		for(int k=0; k<row; k++){
			if(min<mat[k][j_index]){
				flag=0;
				break;
			}
		}
		if(flag){
			printf("Saddle point: %d\n", mat[i][j_index]);
		}
	}
}


int main(){

	//Read matrix
	int m, n;
	printf("Enter row, column: ");
	scanf("%d %d", &m, &n);
	int mat[m][n];
	
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			printf("Enter element matrix[%d][%d]: ", i+1, j+1);
			scanf("%d", &mat[i][j]);
		}
	}
	

	
	findSaddle(m, n, mat);
	
}

/*
Enter row, column: 3 3
Enter element matrix[1][1]: 1
Enter element matrix[1][2]: 2
Enter element matrix[1][3]: 3
Enter element matrix[2][1]: 4
Enter element matrix[2][2]: 5
Enter element matrix[2][3]: 6
Enter element matrix[3][1]: 7
Enter element matrix[3][2]: 8
Enter element matrix[3][3]: 9
Saddle point: 7
*/
