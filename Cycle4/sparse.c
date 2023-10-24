
/*
3. Consider a sparse matrix(A sparse matrix is a matrix in which most of the elements are zero).Print the index of all non zero elements and also count them.
*/

#include <stdio.h>

int main(){

	//Read matrix
	int m, n, count=0;
	printf("Enter row, column: ");
	scanf("%d %d", &m, &n);
	int mat[m][n];
	
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			printf("Enter element matrix[%d][%d]: ", i+1, j+1);
			scanf("%d", &mat[i][j]);
		}
	}
	
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			if(mat[i][j]!=0){
				printf("Element: %d, index: %d, %d\n", mat[i][j], i, j);
				count++;
			}
		}
	}
	printf("Total number of non-zero elements: %d\n", count);
}

/*
Output:
Enter row, column: 3 3
Enter element matrix[1][1]: 1
Enter element matrix[1][2]: 2
Enter element matrix[1][3]: 0
Enter element matrix[2][1]: 0
Enter element matrix[2][2]: 0
Enter element matrix[2][3]: 1
Enter element matrix[3][1]: 0
Enter element matrix[3][2]: 0
Enter element matrix[3][3]: 2
Element: 1, index: 0, 0
Element: 2, index: 0, 1
Element: 1, index: 1, 2
Element: 2, index: 2, 2
Total number of non-zero elements: 4
*/
