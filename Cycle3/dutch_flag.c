/*
5.Solve the Dutch National Flag Problem:
Problem: Given an array containing only 0s, 1s, and 2s, sort the array in O(n) time.
Challenge: solve this problem with a single pass through the array, without using standard sorting algorithms.
*/


#include <stdio.h>

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}


int main(){
	int low=0, size, high, mid=0;
	
	printf("Enter size of array: ");
	scanf("%d", &size);
	int arr[size];
	for(int i=0; i<size; i++){
		printf("Enter element %d: ", i+1);
		scanf("%d", &arr[i]);
	}
	high = size-1;
	while(mid<=high){
		if(arr[mid]==0){
			swap(&arr[mid++],&arr[low++]);
		}
		else if(arr[mid]==1){
			mid++;
		}
		else{
			swap(&arr[mid],&arr[high--]);
		}
	}
	
	printf("Sorted array: ");
	for(int i=0; i<size; i++){
		printf("%d ", arr[i]);
	}
}
/*
Output:
Enter size of array: 5
Enter element 1: 0
Enter element 2: 0
Enter element 3: 1
Enter element 4: 2
Enter element 5: 1
Sorted array: 0 0 1 1 2 
*/
