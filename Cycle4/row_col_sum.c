/*
2.Read a matrix A. Write functions rowsum and colsum which will print the sum of elements in all rows and columns respectively.
*/

#include <stdio.h>

void rowsum(int row, int col, int mat[row][col]){
	int sum;
	for(int i=0; i<row; i++){
		sum = 0;
		for(int j=0; j<col; j++){
			sum += mat[i][j];
			printf("sum: %d", sum);
		}
		printf("Sum of row %d: %d\n", i+1, sum);
	}
}

void colsum(int row, int col, int mat[row][col]){
	int sum;
	for(int i=0; i<col; i++){
		sum = 0;
		for(int j=0; j<row; j++){
			sum += mat[j][i];
		}
		printf("Sum of column %d: %d\n", i+1, sum);
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
	

	
	rowsum(m, n, mat);
	colsum(m, n, mat);
	
}

/*
Enter row, column: 2 2
Enter element matrix[1][1]: 1
Enter element matrix[1][2]: 2
Enter element matrix[2][1]: 1
Enter element matrix[2][2]: 2
	
Sum of row 1: 3
Sum of row 2: 3
Sum of column 1: 2
Sum of column 2: 4
*/
