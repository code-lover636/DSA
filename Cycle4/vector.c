/*
1.Read a matrix A and a vector v. Write a function which will compute A.v
*/

#include <stdio.h>

int main(){

	//Read matrix
	int m, n;
	printf("Enter row, column: ");
	scanf("%d %d", &m, &n);
	int mat[m][n], vector[n];
	
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			printf("Enter element matrix[%d][%d]: ", i+1, j+1);
			scanf("%d", &mat[i][j]);
		}
	}
	
	// Read vector
	for(int i=0; i<n; i++){
		printf("Enter component of vector (%d): ", i+1);
		scanf("%d", &vector[i]);
	}
	
	// Dot product	
	int result[m];
	for(int i=0; i<m; i++){
		result[i] = 0;
		for(int j=0; j<n; j++){
			result[i] += mat[i][j]*vector[j];
		}
	}
	
	printf("\nResult:\n");
	for(int i=0; i<m; i++){
		printf("%d\n", result[i]);
	}
}

/*
Output:
Enter row, column: 3 2
Enter element matrix[1][1]: 1 
Enter element matrix[1][2]: 2
Enter element matrix[2][1]: 3
Enter element matrix[2][2]: 4
Enter element matrix[3][1]: 5
Enter element matrix[3][2]: 6
Enter component of vector (1): 1
Enter component of vector (2): 1

Result:
3
7
11
*/
