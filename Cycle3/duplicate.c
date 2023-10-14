/*
2. Find the duplicate element from a list.
Hint: Sort the list and count the occurrence of each element.
*/

#include <stdio.h>

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

int partition(int arr[], int low, int high){
	int pivot = arr[high], i = low-1;
	
	for(int j=low; j<high; j++){
		if(arr[j]<=pivot){
			swap(&arr[j], &arr[++i]);
		}
	}
	swap(&arr[high], &arr[i+1]);
	return i+1;
}


int quickSort(int arr[], int low, int high){
	if(low<high){
		int pivot_index = partition(arr, low, high);
		
		quickSort(arr, pivot_index+1, high);
		quickSort(arr, low, pivot_index-1);
	}
}

void main(){
	int size, k, count=1;
	
	//Read array
	printf("Enter size of array: ");
	scanf("%d", &size);
	int arr[size];
	for(int i=0; i<size; i++){
		printf("Enter element %d: ", i+1);
		scanf("%d", &arr[i]);
	}	
	
	quickSort(arr, 0, size-1);
	
	printf("Sorted array: ");
	for(int i=0; i<size; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
	for(int i=0; i<size-1; i++){
		if(arr[i]==arr[i+1]){
			count++;
		}
		else if(count>1){
			printf("%d occurs %d time(s)\n", arr[i], count);
			count = 1;
		}
	}
	if(count>1){
		printf("%d occurs %d time(s)\n", arr[size-1], count);
	}
}

/*
Output:
Enter size of array: 5
Enter element 1: 1
Enter element 2: 2
Enter element 3: 1
Enter element 4: 0
Enter element 5: 9
Sorted array: 0 1 1 2 9 
1 occurs 2 time(s)
*/

