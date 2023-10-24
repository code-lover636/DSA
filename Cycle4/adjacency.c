/*
5.Consider adjacency matrix of  an undirected graph(with out self loops)  which is always symmetric and diagonal elements are zero.Input an adjacency matrix and check these properties.Also find the number of edges and degree of all vertices.( Note: The degree of a vertex is the number of edges that are attached to it. The degree sum formula says that if you add up the degree of all the vertices in a (finite) graph, the result is twice the number of the edges in the graph)
*/


#include <stdio.h>

void adjacency(int row, int col, int mat[row][col]){
	int is0=1, issymmetry=1, degree[row];
	for(int i=0; i<row; i++){
		degree[i] = 0;
		for(int j=0; j<col; j++){
			if(i==j && mat[i][j]!=0)
				is0 = 0;
			if(mat[i][j] != mat[j][i])
				issymmetry = 0;
			degree[i] += mat[i][j];
		}
	}
	
	if(issymmetry && is0){
		printf("Given matrix is a adjacency matrix of an undirected graph\n");
		int sum=0;
		for(int l=0; l<row; l++){
			printf("Degree of vertex%d: %d\n", l+1, degree[l]);
			sum+=degree[l];
		}
		printf("Edge: %d\n", sum/2);
	}
	else{
		printf("Given matrix is not a adjacency matrix of an undirected graph\n");
	}
}


int main(){

	//Read matrix
	int m, n;
	printf("Enter row, column: ");
	scanf("%d %d", &m, &n);
	
	if(m!=n){
		printf("Given matrix is not a adjacency matrix of an undirected graph\n");
		return 0;
	}
	
	int mat[m][n];
	
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			printf("Enter element matrix[%d][%d]: ", i+1, j+1);
			scanf("%d", &mat[i][j]);
		}
	}
	

	
	adjacency(m, n, mat);
	
}

/*
Enter row, column: 4 4
Enter element matrix[1][1]: 0
Enter element matrix[1][2]: 1
Enter element matrix[1][3]: 0 
Enter element matrix[1][4]: 1
Enter element matrix[2][1]: 1
Enter element matrix[2][2]: 0
Enter element matrix[2][3]: 1
Enter element matrix[2][4]: 0
Enter element matrix[3][1]: 0
Enter element matrix[3][2]: 1
Enter element matrix[3][3]: 0
Enter element matrix[3][4]: 1
Enter element matrix[4][1]: 1
Enter element matrix[4][2]: 0
Enter element matrix[4][3]: 1
Enter element matrix[4][4]: 0
Given matrix is a adjacency matrix of an undirected graph
Degree of vertex1: 2
Degree of vertex2: 2
Degree of vertex3: 2
Degree of vertex4: 2
Edge: 4
*/
