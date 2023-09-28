/*
5. Merge two sorted Arrays.
Given two sorted arrays A:n and B:m. the program should create a sorted array C:m+n by merging them.
*/

#include <stdio.h>

int merge(int L[], int n, int R[], int m){
	
	int i=0,j=0,k=0, c[n+m];
	while(i<n && j<m){
		if(L[i]<=R[j]){
			c[k]=L[i];
			i++;		
		}	
		else{
			c[k]=R[j];
			j++;		
		}
		k++;
	}
	while(i<n){
		c[k]=L[i];
		i++;
		k++;	
	}
	while(j<m){
		c[k]=R[j];
		j++;
		k++;	
	}
	
	for(int i=0; i<n+m; i++){
		printf("%d\t", c[i]);	
	}

}

void main()
{
	int n, m, key; 
	printf("Enter total element of array1: ");
	scanf("%d", &n);
	int arr1[n];
	
	for(int i=0; i<n; i++){
		printf("Enter number: ");
		scanf("%d", &arr1[i]);
	}
	
	printf("Enter total element of array2: ");
	scanf("%d", &m);
	int arr2[m];
	
	for(int i=0; i<m; i++){
		printf("Enter number: ");
		scanf("%d", &arr2[i]);
	}

	merge(arr1, n, arr2, m);
}	

/*
Output:
Enter total element of array1: 3
Enter number: 1
Enter number: 3
Enter number: 5
Enter total element of array2: 4
Enter number: 2
Enter number: 4
Enter number: 8
Enter number: 9
1	2	3	4	5	8	9	
*/
