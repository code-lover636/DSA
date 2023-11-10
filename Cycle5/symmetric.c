/*
6.Check whether the given matrix is sparse symmetric using the representation given
*/



#include <stdio.h>

int check(int n, int rep[3][n]){
	int rep2[3][n], flag=1;
	
	for(int i=0; i<n; i++){
		rep2[0][i] = rep[1][i];
		rep2[1][i] = rep[0][i];
		rep2[2][i] = rep[2][i];
	}
	
	for(int i=0; i<n; i++){
		for(int j=0; j<n; i++){
			if(rep[0][i]==rep2[0][j] && rep[1][i]==rep2[1][j]){
				if(rep[2][i]!=rep2[2][i]){
					return 0;
				}
				else{
					flag=0;
				}
			}
		}
		if(flag){
			return 0;
		}
	}
	return 1;
	
}

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
		

	if(check(n, rep)){
		printf("Symmetric\n");
	}
	else{
		printf("Not Symmetric\n");
	}

		
}
